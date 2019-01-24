import ROOT
import tables
import numpy as np
from scipy import stats
import pandas as pd

import json
import os


def sumCurrents(curr, bcidList):

    sumCurr = 0.0
    if curr:
        for bcid in bcidList:
            sumCurr = sumCurr + curr[str(bcid)]
    else: 
        print "Attention: No beam currents for time period of scan found in input files"
    
    return sumCurr


def checkFBCTcalib(table, CalibrateFBCTtoDCCT):

    h_ratioB1 = ROOT.TGraph()
    h_ratioB1.SetMarkerStyle(8)
    h_ratioB1.SetMarkerSize(0.4)
    h_ratioB1.SetTitle("SumFBCT/DCCT for B1, for scan "+str(table[0][1]))
    h_ratioB1.GetXaxis().SetTitle("Scan point number")
    h_ratioB1.GetYaxis().SetTitle("SumFBCT(active bunches)/DCCT")

    h_ratioB2 = ROOT.TGraph()
    h_ratioB2.SetMarkerStyle(8)
    h_ratioB2.SetMarkerSize(0.4)
    h_ratioB2.SetTitle("SumFBCT/DCCT for B2, for scan "+str(table[0][1]))
    h_ratioB2.GetXaxis().SetTitle("Scan point number")
    h_ratioB2.GetYaxis().SetTitle("SumFBCT(active bunches)/DCCT")


    for idx, entry in enumerate(table):
        h_ratioB1.SetPoint(idx, entry[2], entry[5]/entry[3])
        h_ratioB2.SetPoint(idx, entry[2], entry[6]/entry[4])


    h_ratioB1.Fit("pol0")
    h_ratioB2.Fit("pol0")

    fB1 = ROOT.TF1()
    fB2 = ROOT.TF1()
    fB1 = h_ratioB1.GetFunction("pol0")
    fB2 = h_ratioB2.GetFunction("pol0")

    corrB1 = fB1.GetParameter(0)
    corrB2 = fB2.GetParameter(0)

    if CalibrateFBCTtoDCCT == True:
        print "Applying FBCT to DCCT calibration"

        for idx, entry in enumerate(table):
            #K1=entry[5]/entry[3]
            #K2=entry[6]/entry[4]
            for key in entry[7].keys():
                old1 = entry[7][key]
                #entry[7][key] = old1/K1
                entry[7][key] = old1/corrB1
            for key in entry[8].keys():
                old2 =  entry[8][key]
                #entry[8][key] = old2/K2
                entry[8][key] = old2/corrB2

            old1=entry[5]
            #entry[5]=old1/K1
            entry[5]=old1/corrB1
            old2=entry[6]
            #entry[6]=old2/K2
            entry[6]=old2/corrB2

    return [h_ratioB1, h_ratioB2, table]

def getCurrents(datapath, scanpt, fill):

#    print "beginning of getCurrents", scanpt
    filelist = os.listdir(datapath)

    beamts = []
    bx1data = []
    bx2data = []
    bx1df = pd.DataFrame()
    bx2df = pd.DataFrame()

    beam1data = []
    beam2data = [] 
    beam1df = pd.DataFrame()
    beam2df = pd.DataFrame()

    fbct1 = {}
    fbct2 = {}

    dcct1 = 0.0
    dcct2 = 0.0

    filledBunches1 = []
    filledBunches2 = []
    collBunches=[]

# omit very first nibble because it may not be fully contained in VdM scan
    tw = '(timestampsec >' + str(scanpt[0]) + ') & (timestampsec <=' +  str(scanpt[1]) + ')'
    print "tw", tw

    for file in filelist:
        h5file = tables.open_file(datapath + "/" + file, 'r')
        beamtable = h5file.root.beam
        bunchlist1 = [r['bxconfig1'] for r in beamtable.where(tw)] 
        bunchlist2 = [r['bxconfig2'] for r in beamtable.where(tw)]        
        beamtslist = [r['timestampsec'] for r in beamtable.where(tw)]
        beamts = beamts + beamtslist

        if bunchlist1 and bunchlist2:
            collBunches  = np.nonzero(bunchlist1[0]*bunchlist2[0])[0].tolist()
            filledBunches1 = np.nonzero(bunchlist1[0])[0].tolist()
            filledBunches2 = np.nonzero(bunchlist2[0])[0].tolist()

# dcct, i.e. current per beam
            beam1list = [r['intensity1'] for r in beamtable.where(tw)]
            beam2list = [r['intensity2'] for r in beamtable.where(tw)]
            beam1data = beam1data + beam1list
            beam2data = beam2data + beam2list
# fbct, ie. current per bx 
            bx1list = [r['bxintensity1'] for r in beamtable.where(tw)]
            bx2list = [r['bxintensity2'] for r in beamtable.where(tw)]
# only consider nominally filled bunches
            bx1data = bx1data + (bx1list* bunchlist1[0]).tolist()
            bx2data = bx2data + (bx2list* bunchlist2[0]).tolist()

        h5file.close()

    beam1df = pd.DataFrame(beam1data)
    beam2df = pd.DataFrame(beam2data)
    
    bx1df = pd.DataFrame(bx1data)
    bx2df = pd.DataFrame(bx2data)

    if beam1df.empty or beam2df.empty or bx1df.empty or bx2df.empty:
        print "Attention, beam current df empty because timestamp window not contained in file"
    else:
        dcct1 = float(beam1df.mean())
        dcct2 = float(beam2df.mean())

# attention: LHC bcid's start at 1, not at 0

        ## In 4266 BCID 2674 is 3% too low in FBCT
        if fill == 4266:

            for idx, bcid in enumerate(filledBunches1):
                if bcid+1==2674:
                    fbct1[str(bcid+1)] = 1.03*bx1df[bcid].mean()
                else:
                    fbct1[str(bcid+1)] = bx1df[bcid].mean()

            for idx, bcid in enumerate(filledBunches2):
                if bcid+1==2674:
                    fbct2[str(bcid+1)] = 1.03*bx2df[bcid].mean()
                else:
                    fbct2[str(bcid+1)] = bx2df[bcid].mean()

        ## In 4634 even BCIDs are 4% too high in FBCT
        elif fill == 4634:

            for idx, bcid in enumerate(filledBunches1):
                if (bcid+1)%2 == 0:
                    fbct1[str(bcid+1)] = 1.04*bx1df[bcid].mean()
                else:
                    fbct1[str(bcid+1)] = bx1df[bcid].mean()

            for idx, bcid in enumerate(filledBunches2):
                fbct2[str(bcid+1)] = bx2df[bcid].mean()

        else:

            for idx, bcid in enumerate(filledBunches1):
                fbct1[str(bcid+1)] = bx1df[bcid].mean()

            for idx, bcid in enumerate(filledBunches2):
                fbct2[str(bcid+1)] = bx2df[bcid].mean()

        for idx, bcid in enumerate(filledBunches1):
            old=filledBunches1[idx]
            filledBunches1[idx]=old+1

        for idx, bcid in enumerate(filledBunches2):
            old=filledBunches2[idx]
            filledBunches2[idx]=old+1

        for idx, bcid in enumerate(collBunches):
            old=collBunches[idx]
            collBunches[idx]=old+1


    return dcct1, dcct2, fbct1, fbct2, filledBunches1, filledBunches2, collBunches


def getCurrentsFromTimber( scanpt, fill, db, pytimber):


#    print "beginning of getCurrents", scanpt

    bx1data = []
    bx2data = []

    beam1data = []
    beam2data = [] 

# omit very first nibble because it may not be fully contained in VdM scan
    tw = '(timestampsec >' + str(scanpt[0]) + ') & (timestampsec <=' +  str(scanpt[1]) + ')'
    print "tw", tw

    import time
    import os,sys
    import subprocess
    import datetime
    import pytz

    utc_dt0 = datetime.datetime.utcfromtimestamp(scanpt[0])
    aware_utc_dt0 = utc_dt0.replace(tzinfo=pytz.utc)
    tz = pytz.timezone('Europe/Brussels')
    dt0 = aware_utc_dt0.astimezone(tz)
    dt0 = datetime.datetime.fromtimestamp(scanpt[0], tz)
    
    utc_dt1 = datetime.datetime.utcfromtimestamp(scanpt[1])
    aware_utc_dt1 = utc_dt1.replace(tzinfo=pytz.utc)
    dt1 = aware_utc_dt1.astimezone(tz)
    dt1 = datetime.datetime.fromtimestamp(scanpt[1], tz)

    t0=pytimber.parsedate(str(dt0).split('+')[0])
    t1=pytimber.parsedate(str(dt1).split('+')[0])
    
    
# dcct, i.e. current per beam
    if fill>=4725: # first fill in 2016
        ib1="LHC.BCTDC.A6R4.B1:BEAM_INTENSITY_ADC24BIT"
        ib2="LHC.BCTDC.A6R4.B2:BEAM_INTENSITY_ADC24BIT"
    else:
        ib1="LHC.BCTDC.A6R4.B1:BEAM_INTENSITY"
        ib2="LHC.BCTDC.A6R4.B2:BEAM_INTENSITY"

    data=db.get([ib1,ib2],t0,t1)
    timestamps,beam1data=data[ib1]
    timestamps,beam2data=data[ib2]
        
    dcct1=beam1data.mean()
    dcct2=beam2data.mean()

# fbct, ie. current per bx (on timber by default only nominally filled bunches)

    ib1="LHC.BCTFR.A6R4.B1:BUNCH_INTENSITY"
    ib2="LHC.BCTFR.A6R4.B2:BUNCH_INTENSITY"

    data1=db.get([ib1,ib2],t0,t0+62)

    timestamps,bx1data=data1[ib1]
    timestamps,bx2data=data1[ib2]
    fbct1=bx1data.mean(axis=0)
    fbct2=bx2data.mean(axis=0)



# attention: LHC bcid's start at 1, not at 0
    ## In 4266 BCID 2674 is 3% too low in FBCT
    if fill == 4266:
        #numpy magic ;D
        #x[:,1::2] #all even
        #x[:,::2] #all odd
        #x[:,[0,2]] # first and third column
        #x[:,[0]] # first column
        fbct1[[2673]]=1.03*fbct1[[2673]]
        fbct2[[2673]]=1.03*fbct1[[2673]]

    ## In 4634 even BCIDs are 4% too high in FBCT
    elif fill == 4634:
        fbct1[1::2]=1.04*fbct1[1::2]

    fbct1_dict = dict(enumerate(fbct1.flatten(), 1))
    fbct2_dict = dict(enumerate(fbct2.flatten(), 1))
    fbct1_dict  = {str(k):float(v) for k,v in fbct1_dict.items()}
    fbct2_dict  = {str(k):float(v) for k,v in fbct2_dict.items()}

    return dcct1, dcct2, fbct1_dict, fbct2_dict


############################
def doMakeBeamCurrentFile(ConfigInfo):

    import csv, pickle

    AnalysisDir = str(ConfigInfo['AnalysisDir'])
    InputCentralPath = str(ConfigInfo['InputCentralPath'])
    InputScanFile = './' + AnalysisDir + '/' + str(ConfigInfo['InputScanFile'])
    OutputSubDir = str(ConfigInfo['OutputSubDir'])

    outpath = './' + AnalysisDir + '/' + OutputSubDir 

    ReadFromTimber = False
    try:
        if 'ReadFromTimber' in ConfigInfo:
            ReadFromTimber = ConfigInfo['ReadFromTimber']
            import pytimber as pytimber                                                                                                                                                                 
            db = pytimber.LoggingDB()
    except:
        print "makeBeamCurrentFileII: add ReadFromTimber argument in makeBeamCurrentFileConfig"

    CalibrateFBCTtoDCCT = False
    CalibrateFBCTtoDCCT = ConfigInfo['CalibrateFBCTtoDCCT']

    
    with open(InputScanFile, 'rb') as f:
        scanInfo = pickle.load(f)

    Fill = scanInfo["Fill"]     
    ScanNames = scanInfo["ScanNames"]     
    
#    CollidingBunches = scanInfo["CollidingBunches"]
#    FilledBunchesB1 = scanInfo["FilledBunchesB1"]
#    FilledBunchesB2 = scanInfo["FilledBunchesB2"]

    table = {}
    csvtable = []
#    csvtable.append(["ScanNumber, ScanNames, ScanPointNumber, avrgdcct1, avrgdcct2, sum(avrgfbctB1), sum(avrgfbctB2), sumColl(avrgfbct1), sumColl(avrgfbct2), fbct1 per Bx, fbct2 per BX"])
    csvtable.append(["ScanNumber, ScanNames, ScanPointNumber, avrgdcct1, avrgdcct2, sum(avrgfbctB1), sum(avrgfbctB2), fbct1 per Bx, fbct2 per BX"])

    for i in range(len(ScanNames)):
        key = "Scan_" + str(i+1)
        scanpoints = scanInfo[key]
        table["Scan_" + str(i+1)]=[]
        for j, sp in enumerate(scanpoints):
            if (ReadFromTimber):
                avrgdcct1, avrgdcct2, avrgfbct1, avrgfbct2 = getCurrentsFromTimber( sp[3:], int(Fill), db, pytimber)
            else:
                avrgdcct1, avrgdcct2, avrgfbct1, avrgfbct2, FilledBunchesB1, FilledBunchesB2, CollidingBunches = getCurrents(InputCentralPath, sp[3:], int(Fill))


#Sums over all filled bunches
            sumavrgfbct1 = sumCurrents(avrgfbct1, FilledBunchesB1) 
            sumavrgfbct2 = sumCurrents(avrgfbct2, FilledBunchesB2)
#Sums over all colliding bunches
            sumCollavrgfbct1 = sumCurrents(avrgfbct1, CollidingBunches) 
            sumCollavrgfbct2 = sumCurrents(avrgfbct2, CollidingBunches) 
            avrgfbct1['sum'] = sumCollavrgfbct1
            avrgfbct2['sum'] = sumCollavrgfbct2

            print "Scan point", j, sp
            row = [i+1, str(ScanNames[i]), j+1, avrgdcct1, avrgdcct2, sumavrgfbct1, sumavrgfbct2, avrgfbct1, avrgfbct2]
            table["Scan_" + str(i+1)].append(row)

    canvas = ROOT.TCanvas()

    ROOT.gStyle.SetOptFit(111)
    ROOT.gStyle.SetOptStat(0)

    h_ratioB1 = ROOT.TGraph()
    h_ratioB2 = ROOT.TGraph()

    outpdf = outpath+'/checkFBCTcalib_'+str(Fill)+'.pdf'
    for i in range(len(ScanNames)):
        key = "Scan_" + str(i+1)
        [h_ratioB1, h_ratioB2, table[key]] = checkFBCTcalib(table[key], CalibrateFBCTtoDCCT)
        h_ratioB1.Draw("AP")
        canvas.SaveAs(outpdf + '(')
        h_ratioB2.Draw("AP")
        canvas.SaveAs(outpdf + '(')

    canvas.SaveAs(outpdf + ']')

    for i in range(len(ScanNames)):
        key="Scan_"+str(i+1)
        csvtable.append([str(key)])
        for idx, entry in enumerate(table[key]):
            row=[entry[0],entry[1],entry[2],entry[3],entry[4],entry[5],entry[6],entry[7],entry[8]]
            csvtable.append(row)

    return table, csvtable

##############
if __name__ == '__main__':

    import pickle, csv, sys, json

    ConfigFile = sys.argv[1]

    Config=open(ConfigFile)
    ConfigInfo = json.load(Config)
    Config.close()

    AnalysisDir = str(ConfigInfo["AnalysisDir"])
    OutputSubDir = str(ConfigInfo["OutputSubDir"])


    InputScanFile = './' + AnalysisDir + '/' + str(ConfigInfo['InputScanFile'])
    with open(InputScanFile, 'rb') as f:
        scanInfo = pickle.load(f)

    Fill = scanInfo["Fill"]     

    table = {}
    csvtable = []

    table, csvtable = doMakeBeamCurrentFile(ConfigInfo)
    
    outpath = AnalysisDir + '/' + OutputSubDir

    csvfile = open(outpath+'/BeamCurrents_'+str(Fill)+'.csv', 'wb')
    writer = csv.writer(csvfile)
    writer.writerows(csvtable)
    csvfile.close()

    with open(outpath+'/BeamCurrents_'+str(Fill)+'.pkl', 'wb') as f:
        pickle.dump(table, f)
            
