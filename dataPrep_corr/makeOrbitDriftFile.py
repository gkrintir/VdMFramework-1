import sys, json, pickle, csv

def doMakeOrbitDriftFile(ConfigInfo):

    table = {}
    csvtable = []

    Fill = ConfigInfo["Fill"]
    InputDataDir = str(ConfigInfo['InputDataDir'])
    OrbitDriftType = str(ConfigInfo['OrbitDriftType'])

# get correction factors
# OrbitDrift_4954_arcBPM.json
    ODValuesFile = InputDataDir + '/OrbitDrift_' + Fill + '_' + OrbitDriftType + '.json'
    ODConfigInfo = open(ODValuesFile)
    ODValues =json.load(ODConfigInfo)
    ODConfigInfo.close()

    Names = ODValues['Names']
    TimeWindows = ODValues['TimeWindows']
    OrbitDrifts_X = ODValues['OrbitDrifts_X']
    OrbitDrifts_Y = ODValues['OrbitDrifts_Y']

    table['Names'] = Names
    table['TimeWindows'] = TimeWindows
    table['OrbitDrifts_X'] = OrbitDrifts_X
    table['OrbitDrifts_Y'] = OrbitDrifts_Y

    for entry in table:
        csvtable.append([entry])
        csvtable.append([table[entry]])

    return table, csvtable



if __name__ == '__main__':

# read config file
    ConfigFile = sys.argv[1]

    Config=open(ConfigFile)
    ConfigInfo = json.load(Config)
    Config.close()

    Fill = ConfigInfo["Fill"]
    OrbitDriftType = ConfigInfo["OrbitDriftType"]
    AnalysisDir = ConfigInfo["AnalysisDir"]
    OutputDir = AnalysisDir +'/'+ConfigInfo["OutputSubDir"]


    table = {}
    csvtable = []
    table, csvtable = doMakeOrbitDriftFile(ConfigInfo)

    csvfile = open(OutputDir+'/OrbitDrift_'+str(Fill)+'_'+OrbitDriftType+'.csv', 'wb')
    writer = csv.writer(csvfile)
    writer.writerows(csvtable)
    csvfile.close()


    with open(OutputDir+'/OrbitDrift_'+str(Fill)+'_'+OrbitDriftType+'.pkl', 'wb') as f:
        pickle.dump(table, f)
