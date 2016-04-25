import FitManager
import ROOT as r
import math
import sys
from array import array
from vdmUtilities import *
r.gROOT.ProcessLine(".L myfcn.C+g")


class Sim_PCCAndVtx_Fit(FitManager.FitProvider):

    fitDescription = ''' 
    Double Gaussian(Luminometer1).                                                                                                                                            
    ff = r.TF1("ff","[2]*([3]*exp(-(x-[4])**2/(2*([0]*[1]/([3]*[1]+1-[3]))**2)) + (1-[3])*exp(-(x-[4])**2/(2*([0]/([3]*[1]+1-[3]))**2)) )")
    ff1.SetParNames("#Sigma","#sigma_{1}/#sigma_{2}","Amp","Frac","Mean")
    Double gaussian formula with substition to effective width and widths ratio
                                     
    CapSigma = h*sigma1 + (1-h)*sigma2
    sigRatio = sigma1/sigma2                                   
    [0] -> [0]*[1]/([3]*[1]+1-[3])                      
    [1] -> [0]/([3]*[1]+1-[3])

    Double Gaussian(Luminometer2).
    ff1 = r.TF1("ff","[2]*([3]*exp(-(x-[4])**2/(2*([0]*[1]/([3]*[1]+1-[3]))**2)) + (1-[3])*exp(-(x-[4])**2/(2*([0]/([3]*[1]+1-[3]))**2)) )")
    ff1.SetParNames("#Sigma","#sigma_{1}/#sigma_{2}","Amp","Frac","Mean")

    Double gaussian formula with substition to effective width and widths ratio
    CapSigma = h*sigma1 + (1-h)*sigma2
    sigRatio = sigma1/sigma2
    [0] -> [0]*[1]/([3]*[1]+1-[3])
    [1] -> [0]/([3]*[1]+1-[3])
    '''

    table_Luminometer1 = []
    table_Luminometer2 = []

    table_Luminometer1.append(["Scan", "Type", "BCID", "sigma","sigmaErr", "sigmaRatio","sigmaRatio_Err","Amp","AmpErr", \
                                   "Frac","FracErr","Mean","MeanErr", "CapSigma", "CapSigmaErr", "peak", "peakErr", \
                                   "area", "areaErr","fitStatus", "chi2", "ndof"])
    
    table_Luminometer2.append(["Scan", "Type", "BCID", "sigma","sigmaErr", "sigmaRatio","sigmaRatio_Err","Amp","AmpErr", \
                                   "Frac","FracErr","Mean","MeanErr", "CapSigma", "CapSigmaErr", "peak", "peakErr", \
                                   "area", "areaErr","fitStatus", "chi2", "ndof"])


   
    def doFit( self,graph,config):

        nDG = 5
        nPars = 2*nDG-1
        #initial values on parameters
        ExpSigma = []
        ExpPeak = []
        StartSigma = []
        StartRatio = []
        StartFrac = []
        StartPeak = []
        #StartConst = [] #placeholder

        #limits on parameters
        LimitSigma_lower = [] 
        LimitSigma_upper = [] 
        LimitRatio_lower = [] 
        LimitRatio_upper = [] 
        LimitFrac_lower = [] 
        LimitFrac_upper = [] 
        LimitPeak_lower = [] 
        LimitPeak_upper = [] 
        #LimitConst_lower = [] #placeholder
        #LimitConst_upper = [] #placeholder

        for i in range(0,2):
            ExpSigma.append( graph[i].GetRMS()*0.5 )
            print  i, graph[i].GetHistogram().GetRMS()*0.5
            ExpPeak.append( graph[i].GetHistogram().GetMaximum() )

            #Currenly parameters initial values and ranges are treated the same
            StartSigma.append( ExpSigma[i] * config['StartSigma'] )
            LimitSigma_lower.append( config['LimitsSigma'][0] )
            LimitSigma_upper.append( config['LimitsSigma'][1] )

            StartRatio.append( config['StartRatio'] )
            LimitRatio_lower.append( config['LimitsRatio'][0] )
            LimitRatio_upper.append( config['LimitsRatio'][1] )

            StartFrac.append( config['StartFrac'] )
            LimitFrac_lower.append( config['LimitsFrac'][0] )
            LimitFrac_upper.append( config['LimitsFrac'][1] )
            
            StartPeak.append( ExpPeak[i]*config['StartPeak'] )
            LimitPeak_lower.append( ExpPeak[i]*config['LimitsPeak'][0] )
            LimitPeak_upper.append( ExpPeak[i]*config['LimitsPeak'][1] )
            
            #StartConst.append( config['StartConst'] )#placeholder
            #LimitConst_lower.append( config['LimitsConst'][0] )#placeholder
            #LimitConst_upper.append( config['LimitsConst'][1] )#placeholder
        
        fittedFunctions = [] 

        ff = r.TF1("ff","[2]*([3]*exp(-(x-[4])**2/(2*([0]*[1]/([3]*[1]+1-[3]))**2)) + (1-[3])*exp(-(x-[4])**2/(2*([0]/([3]*[1]+1-[3]))**2)) )")
	ff.SetParNames("#Sigma","#sigma_{1}/#sigma_{2}","Amp","Frac","Mean")
        fittedFunctions.append(ff)
        ff1 = r.TF1("ff1","[2]*([3]*exp(-(x-[4])**2/(2*([0]*[1]/([3]*[1]+1-[3]))**2)) + (1-[3])*exp(-(x-[4])**2/(2*([0]/([3]*[1]+1-[3]))**2)) )")
        ff1.SetParNames("#Sigma","#sigma_{1}/#sigma_{2}","Amp","Frac","Mean")
        fittedFunctions.append(ff1)

# Some black ROOT magic to get Minuit output into a log file
# see http://root.cern.ch/phpBB3/viewtopic.php?f=14&t=14473, http://root.cern.ch/phpBB3/viewtopic.php?f=13&t=16844, https://agenda.infn.it/getFile.py/access?resId=1&materialId=slides&confId=4933 slide 23

        r.gROOT.ProcessLine("gSystem->RedirectOutput(\"./minuitlogtmp/Minuit.log\", \"a\");")
        r.gROOT.ProcessLine("gSystem->Info(0,\"Next BCID\");")

        fitter = r.Fit.Fitter()
        opt = r.Fit.DataOptions()
        
        wff = r.Math.WrappedMultiTF1(fittedFunctions[0],1)
        wff1 = r.Math.WrappedMultiTF1(fittedFunctions[1],1)

        rangeff = r.Fit.DataRange()
        rangeff.SetRange(graph[0].GetXaxis().GetXmin(), graph[0].GetXaxis().GetXmax())
        dataff = r.Fit.BinData(opt,rangeff)
        r.Fit.FillData(dataff, graph[0])

        rangeff1 = r.Fit.DataRange()
        rangeff1.SetRange(graph[1].GetXaxis().GetXmin(), graph[1].GetXaxis().GetXmax())
        dataff1 = r.Fit.BinData(opt,rangeff1)
        r.Fit.FillData(dataff1, graph[1])
        
        chi2ff = r.Fit.Chi2Function(dataff, wff)
        chi2ff1 = r.Fit.Chi2Function(dataff1, wff1)
        print StartSigma[0],1.,StartPeak[0],StartFrac[0],0., StartSigma[1], StartPeak[1], StartFrac[1],0.
        parffAndff1 = array.array('d', [StartSigma[0],1.,StartPeak[0],StartFrac[0],0., StartSigma[1], StartPeak[1], StartFrac[1],0.])
        #import array as array
        #parffAndff1 = array.array('d', [1, 1, 1, 1, 0, 1, 1, 1, 0])
        #parffAndff1 = array.array('d',[5,5,-0.1,100, 30,10])

        fitter.Config().SetParamsSettings(nPars,parffAndff1)
        
        if LimitSigma_upper[0] > LimitSigma_lower[0]:
            fitter.Config().ParSettings(0).SetLimits(LimitSigma_lower[0],LimitSigma_upper[0] )
        if LimitRatio_upper[0] > LimitRatio_lower[0]:
            fitter.Config().ParSettings(1).SetLimits(LimitRatio_lower[0],LimitRatio_upper[0] )
        if LimitPeak_upper[0] > LimitPeak_lower[0]:
            fitter.Config().ParSettings(2).SetLimits(LimitPeak_lower[0],LimitPeak_upper[0]   )
        if LimitFrac_upper[0] > LimitFrac_lower[0]:
            fitter.Config().ParSettings(3).SetLimits(LimitFrac_lower[0],LimitFrac_upper[0]   )
        #if LimitConst_upper[0] > LimitConst_lower[0]:  #placeholder
        #    fitter.Config().ParSettings(5).SetLimits(LimitConst_lower[0],LimitConst_upper[0])  #placeholder
            
        
        if LimitSigma_upper[1] > LimitSigma_lower[1]:
            fitter.Config().ParSettings(5).SetLimits(LimitSigma_lower[1],LimitSigma_upper[1] ) 
        if LimitPeak_upper[1] > LimitPeak_lower[1]:
            fitter.Config().ParSettings(6).SetLimits(LimitPeak_lower[1],LimitPeak_upper[1]   )
        if LimitFrac_upper[1] > LimitFrac_lower[1]:
            fitter.Config().ParSettings(7).SetLimits(LimitFrac_lower[1],LimitFrac_upper[1]   )
        #if LimitConst_upper[1] > LimitConst_lower[1]:  #placeholder
        #    fitter.Config().ParSettings(10).SetLimits(LimitConst_lower[1],LimitConst_upper[1])  #placeholder
            
        fitter.Config().MinimizerOptions().SetPrintLevel(2)
        fitter.Config().SetMinimizer("Minuit2","Migrad")

        myfun = r.MyFCN(nPars,dataff.Size()+dataff1.Size(),chi2ff, chi2ff1)

        fitter.FitFCN(myfun,parffAndff1,dataff.Size()+dataff1.Size(), True)
        
        result = fitter.Result()
        fitStatus = -999 # becomes dummy variabe

        parff_draw = array.array('i', [0,1,2,3,4])
        fittedFunctions[0].SetFitResult( result, parff_draw);

        parff1_draw = array.array('i', [5,1,6,7,8])
        fittedFunctions[1].SetFitResult( result, parff1_draw);

        
        r.gROOT.ProcessLine("gSystem->RedirectOutput(0);")
        fComponents = []
        for i in range(0,2):
            sigma = fittedFunctions[i].GetParameter("#Sigma")
            m = fittedFunctions[i].GetParNumber("#Sigma")
            sigmaErr = fittedFunctions[i].GetParError(m)
            sigRatio = fittedFunctions[i].GetParameter("#sigma_{1}/#sigma_{2}")
            m = fittedFunctions[i].GetParNumber("#sigma_{1}/#sigma_{2}")
            sigRatioErr = fittedFunctions[i].GetParError(m)
            amp = fittedFunctions[i].GetParameter("Amp")
            m = fittedFunctions[i].GetParNumber("Amp")
            ampErr = fittedFunctions[i].GetParError(m)
            frac = fittedFunctions[i].GetParameter("Frac")
            m = fittedFunctions[i].GetParNumber("Frac")
            fracErr = fittedFunctions[i].GetParError(m)
            mean = fittedFunctions[i].GetParameter("Mean")
            m = fittedFunctions[i].GetParNumber("Mean")
            meanErr = fittedFunctions[i].GetParError(m) 
            #const = fittedFunctions[i].GetParameter("Const") #placeholder
            #m = fittedFunctions[i].GetParNumber("Const") #placeholder
            #constErr = fittedFunctions[i].GetParError(m) #placeholder
            const = -999.
            constErr = -999.

            title = graph[i].GetTitle()
            title_comps = title.split('_')
            scan = title_comps[0]
            type = title_comps[1]
            bcid = title_comps[2]
            chi2 = fittedFunctions[i].GetChisquare()
            ndof = fittedFunctions[i].GetNDF()

            #print  bcid, chi2

            #xmax = r.TMath.MaxElement(graph[1].GetN(),graph[1].GetX())

            sqrttwopi = math.sqrt(2*math.pi)
            CapSigma = sigma
            CapSigmaErr = sigmaErr
            peak = amp
            peakErr = ampErr
            area  = sqrttwopi*peak*CapSigma
            areaErr = (sqrttwopi*CapSigma*peakErr)*(sqrttwopi*CapSigma*peakErr) + (sqrttwopi*peak*CapSigmaErr)*(sqrttwopi*peak*CapSigmaErr)
            areaErr = math.sqrt(areaErr)
            #print 'param', result.GetParams()[i], result.GetParams()[1], result.GetParams()[2], result.GetParams()[3], result.GetParams()[4], result.GetParams()[5], result.GetParams()[6], result.GetParams()[7], result.GetParams()[8]
            #print 'param', result.GetErrors()[i], result.GetErrors()[1], result.GetErrors()[2], result.GetErrors()[3], result.GetErrors()[4], result.GetErrors()[5], result.GetErrors()[6], result.GetErrors()[7], result.GetErrors()[8]
            #print [x for x in list(result.GetParams()[]]

            print scan, type, bcid, sigma, sigmaErr, sigRatio, sigRatioErr, amp, ampErr, frac, fracErr, mean, meanErr, CapSigma, CapSigmaErr, peak, peakErr, area, areaErr, fitStatus, chi2, ndof
            if i==0:
                self.table_Luminometer1.append([scan, type, bcid, sigma, sigmaErr, sigRatio, sigRatioErr, amp, ampErr, frac, fracErr, mean, meanErr, const, constErr, CapSigma, CapSigmaErr, peak, peakErr, area, areaErr, fitStatus, chi2, ndof])
            else:
                self.table_Luminometer2.append([scan, type, bcid, sigma, sigmaErr, sigRatio, sigRatioErr, amp, ampErr, frac, fracErr, mean, meanErr, const, constErr, CapSigma, CapSigmaErr, peak, peakErr, area, areaErr, fitStatus, chi2, ndof])


# Define signal and background pieces of full function separately, for plotting

            h = frac
            s2 = CapSigma/(h*sigRatio+1-h)
            a1 = amp*h
            a2 = amp*(1-h)
            s1 = CapSigma*sigRatio/(h*sigRatio+1-h)

            fSignal1 = r.TF1("fSignal1","[2]*exp(-(x-[1])**2/(2*[0]**2))")
            fSignal1.SetParNames("#Sigma","Mean","Amp")
            fSignal1.SetParameters(s1, mean, a1)
            
            fSignal2 = r.TF1("fSignal2","[2]*exp(-(x-[1])**2/(2*[0]**2))")
            fSignal2.SetParNames("#Sigma","Mean","Amp")
            fSignal2.SetParameters(s2, mean, a2)

# Set background to zero for plotting

            fBckgrd =r.TF1("fBckgrd","[0]")
            fBckgrd.SetParNames("Const")
            const  = 0.
            fBckgrd.SetParameter(0, const)

            fComponents.append(fSignal1)
            fComponents.append(fSignal2)
            fComponents.append(fBckgrd)

        functions = [fittedFunctions[0], fComponents[0], fComponents[1], fComponents[2], fittedFunctions[1], fComponents[3], fComponents[4], fComponents[5]]

        return [functions, result]


    def doPlot(self, graph, functions, fill,tempPath ):
        
        canvas =  r.TCanvas()
        canvas = doPlot1D(graph, functions, fill, tempPath)
        return canvas


