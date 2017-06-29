# Import packages
from netpyne import specs, sim, analysis
from random import randint, sample

# Varible Definitions
simTime = 276000
toneTrial = 44
shockTrials = 16
toneD_Num = [8, 24]
toneV_Num = [13, 24]
noise_freq_pyr = 0.5
noise_freq_int = 8
noise_tot_length = simTime
totNumCells = 100
numInter = 20
numAType = int((totNumCells - numInter) * 0.5)
numBType = int((totNumCells - numInter) * 0.3)
numCType = int((totNumCells - numInter) * 0.2)
toneStimD_List = []
toneStimV_List = []
shockStim_List = []
pyr_ConnList = []
int_ConnList = []
thal2pyr_ConnList = []
cort2pyr_ConnList = []
shock2pyr_ConnList = []
thal2int_ConnList = []
cort2int_ConnList = []
shock2int_ConnList = []
data_output = {}		# Data Dictionary
numSpikeA = 0
numSpikeB = 0
numSpikeC = 0
numSpikeInt = 0

# Generates a list of spike times in which we want the Thal, Cort, and Shock to stimulate the cells that they are connected to
for i in range(0, toneTrial):
	if i < toneD_Num[0]:
		interval = 50
		number = 10+1
		start = 3500+4000*i
		for i in range(0, number):
			toneStimD_List.append(start+interval*i)
	elif i >= toneD_Num[0] and i < toneD_Num[1]:
		interval = 50/2
		number = 10*2+1
		start = 3500+4000*i
		for i in range(0, number):
			toneStimD_List.append(start+interval*i)
	elif i >= toneD_Num[1]:
		interval = 50/2
		number = 10*2+1
		start = 100000+3500+4000*i
		for i in range(0, number):
			toneStimD_List.append(start+interval*i)

for i in range(0, toneTrial):
	if i < toneV_Num[0]:
		interval = 50
		number = 10+1
		start = 3500+4000*i
		for i in range(0, number):
			toneStimV_List.append(start+interval*i)
	elif i >= toneV_Num[0] and i < toneV_Num[1]:
		interval = 50/2
		number = 10*2+1
		start = 3500+4000*i
		for i in range(0, number):
			toneStimV_List.append(start+interval*i)
	elif i >= toneV_Num[1]:
		interval = 50/2
		number = 10*2+1
		start = 100000+3500+4000*i
		for i in range(0, number):
			toneStimV_List.append(start+interval*i)
			
for i in range(0, shockTrials):
		interval = 5
		number = 20+1
		start = 35900+4000*i
		for i in range(0, number):
			shockStim_List.append(start+interval*i)

# Create a list of cells for the Thal, Cort, and Shock to connect to randomly each run
# First create a list of the PYR and INT cells. Then randomly pick a percentage of the cells
# to connect to based on know connection percentages
for i in range(0, totNumCells - numInter):
	pyr_ConnList.append(int(i))
	
for i in range(0, numInter):
	int_ConnList.append(int(i))

for i in sample(pyr_ConnList, int((totNumCells-numInter)*0.53)):	# Creating 42 connections randomly
	thal2pyr_ConnList.append([0,i])

for i in sample(pyr_ConnList, int((totNumCells-numInter)*0.53)):	# Creating 42 connections randomly
	cort2pyr_ConnList.append([0,i])

for i in sample(pyr_ConnList, int((totNumCells-numInter)*0.7)):		# Creating 56 connections randomly
	shock2pyr_ConnList.append([0,i])

for i in sample(int_ConnList, int(numInter*0.53)):					# Creating 10 connections randomly
	thal2int_ConnList.append([0,i])		

for i in sample(int_ConnList, int(numInter*0.53)):					# Creating 10 connections randomly
	cort2int_ConnList.append([0,i])

for i in sample(int_ConnList, int(numInter*0.7)):					# Creating 14 connections randomly
	shock2int_ConnList.append([0,i])

#### Network Parameters (Create a Network Object)
netParams = specs.NetParams()
# Set the size of area that the cells will be created in
# You see this area when you plot connections with this command: simConfig.analysis['plot2Dnet'] = True
netParams.sizeX = 130		# Horizontal Axis
netParams.sizeY = 50		# Vertical Axis
netParams.sizeZ = 100		# Horizontal Axis

#### Define Population Parameters
# Based on a percentage we define A, B, and C type cells with different dopamine properties
# Type A Type: 6 - Cell_A, 15 - Cell_ADA, 19 - Cell_ANE
netParams.popParams['PN_A'] = {'cellType': 'PYR_A', 'numCells': 6,'xRange': [0,25], 'yRange': [0,50], 'cellModel': 'LA_Mod'}
netParams.popParams['PN_ADA'] = {'cellType': 'PYR_ADA', 'numCells': 15,'xRange': [0,25], 'yRange': [0,50], 'cellModel': 'LA_Mod'}
netParams.popParams['PN_ANE'] = {'cellType': 'PYR_ANE', 'numCells': 19,'xRange': [0,25], 'yRange': [0,50], 'cellModel': 'LA_Mod'}
# Type B Type: 3 - Cell_B, 5 - Cell_BDA, 16 - Cell_BNE
netParams.popParams['PN_B'] = {'cellType': 'PYR_B', 'numCells': 3, 'xRange': [25,50], 'yRange': [0,50], 'cellModel': 'LA_Mod'}
netParams.popParams['PN_BDA'] = {'cellType': 'PYR_BDA', 'numCells': 5,'xRange': [25,50], 'yRange': [0,50], 'cellModel': 'LA_Mod'}
netParams.popParams['PN_BNE'] = {'cellType': 'PYR_BNE', 'numCells': 16,'xRange': [25,50], 'yRange': [0,50], 'cellModel': 'LA_Mod'}
# Type C Type: 5 - Cell_C, 2 - Cell_CDA, 9 - Cell_CNE
netParams.popParams['PN_C'] = {'cellType': 'PYR_C', 'numCells': 5, 'xRange': [50,75], 'yRange': [0,50], 'cellModel': 'LA_Mod'}
netParams.popParams['PN_CDA'] = {'cellType': 'PYR_CDA', 'numCells': 2,'xRange': [50,75], 'yRange': [0,50], 'cellModel': 'LA_Mod'}
netParams.popParams['PN_CNE'] = {'cellType': 'PYR_CNE', 'numCells': 9,'xRange': [50,75], 'yRange': [0,50], 'cellModel': 'LA_Mod'}
# Interneurons
netParams.popParams['INT'] = {'cellType': 'Interneuron', 'numCells': numInter, 'xRange': [75,100], 'yRange': [0,50], 'cellModel': 'LA_Mod'}

# Create Tone and Shock Cells via VecStim using the stimulation lists we define above
netParams.popParams['Thal_Tone_D'] = {'cellModel': 'VecStim', 'numCells': 1, 'xRange': [100,110], 'yRange': [0, 50], 'spkTimes': toneStimD_List} 	# Cell Number 100
netParams.popParams['Cort_Tone_V'] = {'cellModel': 'VecStim', 'numCells': 1, 'xRange': [110,120], 'yRange': [0, 50], 'spkTimes': toneStimV_List} 	# Cell Number 101
netParams.popParams['Shock'] = {'cellModel': 'VecStim', 'numCells': 1, 'xRange': [120,130], 'yRange': [0, 50], 'spkTimes': shockStim_List} 			# Cell Number 102

#### Define Cell Property by importing from cell template "LA_Template.py"
# See template for more details of each individual cell
# A Rules
netParams.importCellParams(label='Type_A_Rule', conds={'cellType': 'PYR_A', 'cellModel': 'LA_Mod'}, fileName='LA_Template.py', cellName='Cell_A')
netParams.importCellParams(label='Type_ADA_Rule', conds={'cellType': 'PYR_ADA', 'cellModel': 'LA_Mod'}, fileName='LA_Template.py', cellName='Cell_ADA')
netParams.importCellParams(label='Type_ANE_Rule', conds={'cellType': 'PYR_ANE', 'cellModel': 'LA_Mod'}, fileName='LA_Template.py', cellName='Cell_ANE')
# B Rules
netParams.importCellParams(label='Type_B_Rule', conds={'cellType': 'PYR_B', 'cellModel': 'LA_Mod'}, fileName='LA_Template.py', cellName='Cell_B')
netParams.importCellParams(label='Type_BDA_Rule', conds={'cellType': 'PYR_BDA', 'cellModel': 'LA_Mod'}, fileName='LA_Template.py', cellName='Cell_BDA')
netParams.importCellParams(label='Type_BNE_Rule', conds={'cellType': 'PYR_BNE', 'cellModel': 'LA_Mod'}, fileName='LA_Template.py', cellName='Cell_BNE')
# C Rules
netParams.importCellParams(label='Type_C_Rule', conds={'cellType': 'PYR_C', 'cellModel': 'LA_Mod'}, fileName='LA_Template.py', cellName='Cell_C')
netParams.importCellParams(label='Type_CDA_Rule', conds={'cellType': 'PYR_CDA', 'cellModel': 'LA_Mod'}, fileName='LA_Template.py', cellName='Cell_CDA')
netParams.importCellParams(label='Type_CNE_Rule', conds={'cellType': 'PYR_CNE', 'cellModel': 'LA_Mod'}, fileName='LA_Template.py', cellName='Cell_CNE')
# Int Rules
netParams.importCellParams(label='Inter_Rule', conds={'cellType': 'Interneuron', 'cellModel': 'LA_Mod'}, fileName='LA_Template.py', cellName='Inter')

'''
#### Create current clamp to check single cell response to current injection
# Need one current clamp for interneurons and one for pyramidal cells
netParams.stimSourceParams['CurClamp'] =  {'type': 'IClamp', 'delay': 200, 'dur': 600, 'amp': 0.4/4.6}#-0.1/4.6}
netParams.stimSourceParams['CurClampInt'] =  {'type': 'IClamp', 'delay': 100, 'dur': 600, 'amp': -0.1}

# Connect current clamps to cells
netParams.stimTargetParams['curClamp->1'] = {'source': 'CurClamp', 'conds': {'popLabel': 'PN_A'}, 'sec':'soma','loc': 0.5}
netParams.stimTargetParams['curClamp->2'] = {'source': 'CurClamp', 'conds': {'popLabel': 'PN_B'}, 'sec':'soma','loc': 0.5}
netParams.stimTargetParams['curClamp->3'] = {'source': 'CurClamp', 'conds': {'popLabel': 'PN_C'}, 'sec':'soma','loc': 0.5}
#netParams.stimTargetParams['curClampInt->4'] = {'source': 'CurClampInt', 'conds': {'popLabel': 'INT'}, 'sec':'dend','loc': 0.5}
'''

#### Define Synaptic mechanism parameters
# Interneuron Cells to Pyramidal Cells GABA with local Ca2+ pool and read public soma Ca2+ pool
netParams.synMechParams['interD2pyrD_STFD'] = {'mod': 'interD2pyrD_STFD'}	# Synaptic weight range: 0.7 - 2 ('initW': 0.7)
# Pyramidal Cells to Interneuron Cells AMPA+NMDA with local Ca2+ pool
netParams.synMechParams['pyrD2interD_STFD'] = {'mod': 'pyrD2interD_STFD'} 	# Synaptic weight range: 1 - 2
# Pyramidal Cells to Pyramidal Cells AMPA+NMDA with local Ca2+ pool
netParams.synMechParams['pyrD2pyrD_STFD'] = {'mod': 'pyrD2pyrD_STFD'}		# Synaptic weight range: 0.5 - 1

# Shock to Interneuron Cells AMPA+NMDA with local Ca2+ pool
netParams.synMechParams['shock2interD'] = {'mod': 'shock2interD'}			# Synaptic weight range: 9 - 12
# Shock to Pyramidal Cells AMPA+NMDA with local Ca2+ pool
netParams.synMechParams['shock2pyrD'] = {'mod': 'shock2pyrD'}				# Synaptic weight range: 2 - 4.5 ( 10/4.6 (2) - 12/4.6 (2.6) )

# Tone to Interneuron Cells AMPA+NMDA with local Ca2+ pool								# Synaptic weight range: 2 - 4
netParams.synMechParams['tone2interD'] = {'mod': 'tone2interD'}
# Tone to Pyramidal Cells AMPA+NMDA with local Ca2+ pool								# Synaptic weight range: 0.7 - 2
netParams.synMechParams['tone2pyrD'] = {'mod': 'tone2pyrD'}

# Background to Interneuron Cells AMPA+NMDA 
netParams.synMechParams['bg2inter'] = {'mod': 'bg2inter'}
# Background to Pyramidal Cells AMPA+NMDA 
netParams.synMechParams['bg2pyr'] = {'mod': 'bg2pyr'}

#### Define Stimulation parameters
# Generate Background Noise (Define sources and targets to connect to )
netParams.stimSourceParams['bg2inter_stim'] = {'type': 'NetStim', 'interval': 1000/noise_freq_int, 'number': noise_tot_length*noise_freq_int/1000, 'start': 0, 'noise': 1}
netParams.stimSourceParams['bg2pyr_stim'] = {'type': 'NetStim', 'interval': 1000/noise_freq_pyr, 'number': noise_tot_length*noise_freq_pyr/1000, 'start': 0, 'noise': 1}

netParams.stimTargetParams['bkg->inter'] = {'source': 'bg2inter_stim', 'conds': {'popLabel': 'INT'}, 'sec': 'dend', 'loc': 0.9, 'delay': 1, 'weight': 1, 'synMech': 'bg2inter'}
netParams.stimTargetParams['bkg->pyr_a'] = {'source': 'bg2pyr_stim', 'conds': {'popLabel': ['PN_A','PN_ADA','PN_ANE']}, 'loc': 0.9, 'delay': 1, 'weight': 2, 'synMech': 'bg2pyr'}
netParams.stimTargetParams['bkg->pyr_b'] = {'source': 'bg2pyr_stim', 'conds': {'popLabel': ['PN_B','PN_BDA','PN_BNE']}, 'loc': 0.9, 'delay': 1, 'weight': 1.55, 'synMech': 'bg2pyr'}
netParams.stimTargetParams['bkg->pyr_c'] = {'source': 'bg2pyr_stim', 'conds': {'popLabel': ['PN_C','PN_CDA','PN_CNE']}, 'loc': 0.9, 'delay': 1, 'weight': 1.5, 'synMech': 'bg2pyr'}

#### Cell Connectivity Rules (Connect the cells together) -- Total connections approximately: Greater than 3200
# Connectivity Between Pyramidal and Interneurons
netParams.connParams['PNs->PNs'] = {					# Gives approx. 1600 Connections
	'preConds': {'popLabel': ['PN_A','PN_ADA','PN_ANE','PN_B','PN_BDA','PN_BNE','PN_C','PN_CDA','PN_CNE']},  	# connection from
	'postConds': {'popLabel': ['PN_A','PN_ADA','PN_ANE','PN_B','PN_BDA','PN_BNE','PN_C','PN_CDA','PN_CNE']},	# connnection to
	'probability': 0.25, 								# probability of connection (.25)
	'weight': 1,										# synaptic weight: 1
	'delay': randint(10,20),							# transmission delay (ms)
	'threshold': -10,									# threshold voltage (mv)
    'loc': 0.9,											# location of synapse
	'synMech': 'pyrD2pyrD_STFD'}   						# target synaptic mechanism

netParams.connParams['INTs->PNs'] = {					# Gives approx. 960 Connections
	'preConds': {'popLabel': 'INT'},  					# connection from
	'postConds': {'popLabel': ['PN_A','PN_ADA','PN_ANE','PN_B','PN_BDA','PN_BNE','PN_C','PN_CDA','PN_CNE']},	# connnection to
	'probability': 0.6, 								# probability of connection
	'weight': 1, 										# synaptic weight: 1
	'delay': randint(10,20),							# transmission delay (ms)
	'threshold': -10,									# threshold voltage (mv)
	'loc': 0.9,											# location of synapse
	'synMech': 'interD2pyrD_STFD'}   					# target synaptic mechanism

netParams.connParams['PNs->INTs'] = {					# Gives approx. 528 Connections
	'preConds': {'popLabel': ['PN_A','PN_ADA','PN_ANE','PN_B','PN_BDA','PN_BNE','PN_C','PN_CDA','PN_CNE']}, 	# connection from
	'postConds': {'popLabel': 'INT'},					# connnection to
	'probability': 0.33, 								# probability of connection
	'weight': 1, 										# synaptic weight: 1
	'delay': randint(10,20),							# transmission delay (ms)
	'threshold': -10,									# threshold voltage (mv)
	'loc': 0.9,											# location of synapse
	'synMech': 'pyrD2interD_STFD'}   					# target synaptic mechanism	

## Connectivity Between Cells and Tone/Shock
# Pyramidal Cells and Input 
netParams.connParams['Thal->PNs'] = {					# Gives 42 Connections
	'preConds': {'popLabel': 'Thal_Tone_D'}, 
	'postConds': {'popLabel': ['PN_A','PN_ADA','PN_ANE','PN_B','PN_BDA','PN_BNE','PN_C','PN_CDA','PN_CNE']}, 
	'connList': thal2pyr_ConnList,						# connection list
	'weight': 1, 										# synaptic weight: 1
	'delay': randint(10,20),							# transmission delay (ms)
	'threshold': 0.5,									# threshold voltage (mv)
	'loc': 0.9,											# location of synapse
	'synMech': 'tone2pyrD'}   							# target synaptic mechanism

netParams.connParams['Cort->PNs'] = {					# Gives 42 Connections
	'preConds': {'popLabel': 'Cort_Tone_V'}, 
	'postConds': {'popLabel': ['PN_A','PN_ADA','PN_ANE','PN_B','PN_BDA','PN_BNE','PN_C','PN_CDA','PN_CNE']},
	'connList': cort2pyr_ConnList,						# connection list
	'weight': 1, 										# synaptic weight: 1
	'delay': randint(10,20),							# transmission delay (ms)
	'threshold': 0.5,									# threshold voltage (mv)
	'loc': 0.9,											# location of synapse
	'synMech': 'tone2pyrD'}   							# target synaptic mechanism

netParams.connParams['Shock->PNs'] = {					# Gives 56 Connections
	'preConds': {'popLabel': 'Shock'}, 
	'postConds': {'popLabel': ['PN_A','PN_ADA','PN_ANE','PN_B','PN_BDA','PN_BNE','PN_C','PN_CDA','PN_CNE']},
	'connList': shock2pyr_ConnList,						# connection list
	'weight': 1, 										# synaptic weight: 1
	'delay': randint(10,20),							# transmission delay (ms) 
	'threshold': 0.5,									# threshold voltage (mv)
	'loc': 0.9,											# location of synapse
	'synMech': 'shock2pyrD'}   							# target synaptic mechanism

# Interneurons and Input
netParams.connParams['Thal->INTs'] = {					# Gives 10 Connections
	'preConds': {'popLabel': 'Thal_Tone_D'}, 			# 1 Thal Tone Cell
	'postConds': {'popLabel': 'INT'}, 					# 20 Interneuron Cells
	'connList': thal2int_ConnList,						# connection list
	'weight': 1, 										# synaptic weight: 1
	'delay': randint(10,20),							# transmission delay (ms)
	'threshold': 0.5,									# threshold voltage (mv)
	'sec': 'dend',										# section
	'loc': 0.9,											# location of synapse
	'synMech': 'tone2interD'}   						# target synaptic mechanism

netParams.connParams['Cort->INTs'] = {					# Gives 10 Connections
	'preConds': {'popLabel': 'Cort_Tone_V'}, 
	'postConds': {'popLabel': 'INT'},
	'connList': cort2int_ConnList,						# connection list
	'weight': 1, 										# synaptic weight: 2 - 4
	'delay': randint(10,20),							# transmission delay (ms)
	'threshold': 0.5,									# threshold voltage (mv)
	'sec': 'dend',										# section
	'loc': 0.9,											# location of synapse
	'synMech': 'tone2interD'}   						# target synaptic mechanism

netParams.connParams['Shock->INTs'] = {					# Gives 14 Connections
	'preConds': {'popLabel': 'Shock'}, 
	'postConds': {'popLabel': 'INT'},
	'connList': shock2int_ConnList,						# connection list
	'weight': 1, 										# synaptic weight: 9 - 12
	'delay': randint(10,20),							# transmission delay (ms)
	'threshold': 0.5,									# threshold voltage (mv)
	'sec': 'dend',										# section
	'loc': 0.9,											# location of synapse
	'synMech': 'shock2interD'}   						# target synaptic mechanism

#### Simulation options
simConfig = specs.SimConfig()							# Object of class SimConfig to store simulation configuration
simConfig.duration = simTime							# Duration of the simulation, in ms
simConfig.dt = 0.05 #0.025 								# Internal integration timestep to use
simConfig.hParams = {'celsius': 31,'clamp_resist': 0.001,'steps_per_ms': 20} # Define some hParams of the network
simConfig.verbose = 0									# Show detailed messages, set to 1 if you want detailed output
simConfig.recordTraces = {'V_soma':{'sec':'soma','loc':0.5,'var':'v'}}  # Dict with traces to record
simConfig.recordStep = 0.01#0.025 						# Step size in ms to save data (eg. V traces, LFP, etc)
simConfig.filename = 'model_output'  					# Set file output name
simConfig.saveMat = True;								# Save .mat file after simulation
simConfig.timestampFilename = True						# Add time stamp to filename

#simConfig.analysis['plotRaster'] = True #{'orderInverse': True, 'saveFig': 'tut_import_raster.png'}								# Plot a raster
#simConfig.analysis['plotTraces'] = {'include': [('PN_A', [4,5,6]),('PN_B', [4,5,6])], 'overlay':True} 								# Plot recorded traces for this list of cells
#simConfig.analysis['plotTraces'] = {'include': [77]} 																				# Plot recorded traces for this list of cells
#simConfig.analysis['plot2Dnet'] = True           																					# Plot 2D visualization of cell positions and connections

# Create network and run simulation
sim.createSimulate(netParams = netParams, simConfig = simConfig)
sim.saveData()
import pylab; pylab.show()  # this line is only necessary in certain systems where figures appear empty


'''
# Methods to modify your network
modifyCells(params) 				# Modify the cells in your network
modifySynMechs(params) 				# Modify the Synapse Mechanisms
modifyConns(params)					# Modify the connections of your network
modifyStims(params)					# Modify the stimulations of you network
'''

'''
#### Simulation setup to run multiple runs at once
simConfig = specs.SimConfig()								# Object of class SimConfig to store simulation configuration
simConfig.duration = simTime								# Duration of the simulation, in ms
simConfig.dt = 0.05  										# Internal integration timestep to use
simConfig.hParams = {'celsius': 31,'clamp_resist': 0.001,'steps_per_ms': 20}
simConfig.verbose = 0										# Show detailed messages
simConfig.recordTraces = {'V_soma':{'sec':'soma','loc':0.5,'var':'v'}}  # Dict with traces to record
simConfig.recordStep = 0.01		 							# Step size in ms to save data (eg. V traces, LFP, etc)
simConfig.saveMat = True;									# Save .mat file after simulation
simConfig.timestampFilename = True							# Add time stamp to filename

# Create simulation
sim.create(netParams, simConfig)

# Create network and run simulation
for i in range(1, 5):
    simConfig.filename = 'Run_Freq_' + str(noise_freq_int+i)
	#sim.net.modifyConns({'conds':{'label': 'Shock->INTs'}, 'weight': 1+0.1*i})
    #sim.net.modifySynMechs({'conds':{'label': 'interD2pyrD_STFD'}, 'initW': 0.7+i*0.1})
	sim.net.modifyStims(({'conds':{'label': 'bg2inter_stim'}, 'interval': 1000/(noise_freq_int+i)})
    sim.simulate()
    sim.saveData()
'''