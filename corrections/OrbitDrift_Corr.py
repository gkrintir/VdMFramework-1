import CorrectionManager
import ROOT as r
import sys
import pickle
from vdmUtilities import *
import math
from math import sqrt


class OrbitDrift_Corr(CorrectionManager.CorrectionProvider):

    Names = []
    TimeWindows = []
    OrbitDrifts_X = []
    OrbitDrifts_Y = []

    def GetCorr(self, fileName):

        table = {}
        with open(fileName, 'rb') as f:
            table = pickle.load(f)

        self.Names = table["Names"]
        self.TimeWindows = table["TimeWindows"]
        self.OrbitDrifts_X = table["OrbitDrifts_X"]
        self.OrbitDrifts_Y = table["OrbitDrifts_Y"]

        return


    def PrintCorr(self):

        print ""
        print "===="
        print "PrintODCorrPars"
        
        for idx, val in enumerate(self.Names):
            print val
            for idx2, valTw in enumerate(self.TimeWindows[idx]):
                print "   ", valTw, " ", self.OrbitDrifts_X[idx][idx2], " ", self.OrbitDrifts_Y[idx][idx2]
        print "===="
        print ""


    def doCorr(self,inData,configFile):

        print "Applying orbit drifts to the coordinates"

        print "   configFile = ", configFile
        self.GetCorr(configFile)
        self.PrintCorr()

    # evaluate displacements with orbit drifts
        
        for entry in inData:
            dispWithOD = [{} for value in entry.displacement]
            for idx, snm in enumerate(self.Names):
                if snm == entry.scanName:
                    for idxsp, disp in enumerate(entry.displacement):
                        disp2 = entry.displX[idxsp]**2 + entry.displY[idxsp]**2
                        prevCorrScale = 1
                        if disp2 != 0:
                            prevCorrScale = sqrt(disp**2 / disp2)
                        
                        tAve = (entry.tStart[idxsp] + entry.tStop[idxsp]) / 2
                        ODvalX = -1000
                        ODvalY = -1000
                        
                        for idxOD in range(0, 2):
                            if self.TimeWindows[idx][idxOD] <= tAve <= self.TimeWindows[idx][idxOD+1]:
#                                print "Scan ", entry.scanName, " Tave in range: ", self.TimeWindows[idx][idxOD], " <= ", tAve, " <= ", self.TimeWindows[idx][idxOD+1]
                                ODvalX = self.OrbitDrifts_X[idx][idxOD] + ((self.OrbitDrifts_X[idx][idxOD+1] - self.OrbitDrifts_X[idx][idxOD]) / (self.TimeWindows[idx][idxOD+1] - self.TimeWindows[idx][idxOD])) * (tAve - self.TimeWindows[idx][idxOD])
                                ODvalY = self.OrbitDrifts_Y[idx][idxOD] + ((self.OrbitDrifts_Y[idx][idxOD+1] - self.OrbitDrifts_Y[idx][idxOD]) / (self.TimeWindows[idx][idxOD+1] - self.TimeWindows[idx][idxOD])) * (tAve - self.TimeWindows[idx][idxOD])
                                break
                        else:
                            print "ERROR: In scan", entry.scanName, " point average time ", tAve, " not in the range of [", self.TimeWindows[idx][0], ", ", self.TimeWindows[idx][2], "]."
                            
                        newValX = entry.displX[idxsp]*prevCorrScale + (ODvalX / 1000)
                        newValY = entry.displY[idxsp]*prevCorrScale + (ODvalY / 1000)
                            
                        dispWithOD[idxsp] = sqrt((newValX)**2 + (newValY)**2)
                            
                        if ("X" in entry.scanName):
                            relDisSign = math.copysign(1, newValX)
                        elif ("Y" in entry.scanName):
                            relDisSign = math.copysign(1, newValY)
                        dispWithOD[idxsp] = relDisSign * dispWithOD[idxsp]
                            
#                            print "Scan ", entry.scanName, " point ", idxsp, " new displacement = ", dispWithOD[idxsp]
                        
                    break
            else:
                print "ERROR: Scan name ", entry.scanName, " not found in orbit drifts file."
            
            for bx in entry.collidingBunches:
                coordinates_corrected = [a*(b/c) if c != 0 else b for  a, b, c in zip(entry.spPerBX[bx], dispWithOD, entry.displacement) if not math.isnan(a+b+c)]
                entry.spPerBX[bx] = coordinates_corrected
                
            entry.displacement = dispWithOD
            
