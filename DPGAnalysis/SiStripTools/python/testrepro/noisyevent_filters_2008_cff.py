import FWCore.ParameterSet.Config as cms

#------------------------------------------------------------------
# Filter against APV-induced noisy events
#------------------------------------------------------------------

from DPGAnalysis.SiStripTools.eventwithhistoryproducer_cfi import *
from DPGAnalysis.SiStripTools.configurableapvcyclephaseproducer_CRAFT08_cfi import *

from DPGAnalysis.SiStripTools.apvlatency.apvlatencyfromconddb_CRAFT_cff import *
essapvlatency.connect = cms.string("sqlite_file:/afs/cern.ch/cms/tracker/sistrlocrec/CRAFTReproIn31X/latency08_fromDPG.db")

from DPGAnalysis.SiStripTools.filters.Potential_TOB_HugeEvents_cfi import *
from DPGAnalysis.SiStripTools.filters.Potential_TIBTEC_HugeEvents_cfi import *

from DPGAnalysis.SiStripTools.filters.Potential_TOB_FrameHeaderEvents_firstpeak_cfi import *
potentialTOBFrameHeaderEventsFPeak.filterConfigurations = cms.untracked.VPSet(
          cms.PSet (absBXInCycleRangeLtcyAware = cms.untracked.vint32(19,21))
          )

from DPGAnalysis.SiStripTools.filters.Potential_TIBTEC_FrameHeaderEvents_firstpeak_cfi import *
potentialTIBTECFrameHeaderEventsFPeak.filterConfigurations = cms.untracked.VPSet(
          cms.PSet (absBXInCycleRangeLtcyAware = cms.untracked.vint32(19,21))
          )

potentialTOBFrameHeaderEventsAdditionalPeak = potentialTOBFrameHeaderEventsFPeak.clone() 
potentialTOBFrameHeaderEventsAdditionalPeak.filterConfigurations = cms.untracked.VPSet(
          cms.PSet (absBXInCycleRangeLtcyAware = cms.untracked.vint32(24,25))
          )

potentialTIBTECFrameHeaderEventsAdditionalPeak = potentialTIBTECFrameHeaderEventsFPeak.clone() 
potentialTIBTECFrameHeaderEventsAdditionalPeak.filterConfigurations = cms.untracked.VPSet(
          cms.PSet (absBXInCycleRangeLtcyAware = cms.untracked.vint32(24,25))
          )