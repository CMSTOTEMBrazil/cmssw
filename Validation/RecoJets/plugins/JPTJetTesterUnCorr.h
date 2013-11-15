#ifndef ValidationRecoJetsJPTJetTesterUnCorr_h
#define ValidationRecoJetsJPTJetTesterUnCorr_h

// Producer for validation histograms for JPTJet objects
// F. Ratnikov, Sept. 7, 2006
// Modified by J F Novak July 10, 2008

#include <string>

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "DQMServices/Core/interface/MonitorElement.h"
#include "JetMETCorrections/Objects/interface/JetCorrector.h"
#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"
#include "DataFormats/JetReco/interface/JPTJetCollection.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"

namespace reco {
  class JPTJet;
  class GenJet;
}
namespace edm {class HepMCProduct;}

class MonitorElement;

class JPTJetTesterUnCorr : public edm::EDAnalyzer {
public:

  JPTJetTesterUnCorr (const edm::ParameterSet&);
  ~JPTJetTesterUnCorr();

  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void beginJob() ;
  virtual void endJob() ;

private:

  void fillMatchHists (const reco::GenJet& fGenJet, const reco::JPTJet& fJPTJet);
  double getSumPt (const reco::TrackRefVector& tracks);

  edm::EDGetTokenT<reco::JPTJetCollection> mInputCollection_;
  edm::EDGetTokenT<reco::GenJetCollection> mInputGenCollection_;
  edm::EDGetTokenT<edm::HepMCProduct> hepMC_Token_;
  edm::EDGetTokenT<CaloTowerCollection> caloTower_Token_;

  std::string mOutputFile;

  // count number of events
  MonitorElement* numberofevents;

  // Generic Jet Parameters
  MonitorElement* mEta;
  MonitorElement* mEtaFineBin;
  MonitorElement* mEtaFineBin1p;
  MonitorElement* mEtaFineBin2p;
  MonitorElement* mEtaFineBin3p;
  MonitorElement* mEtaFineBin1m;
  MonitorElement* mEtaFineBin2m;
  MonitorElement* mEtaFineBin3m;
  MonitorElement* mPhi;
  MonitorElement* mPhiFineBin;
  MonitorElement* mE;
  MonitorElement* mE_80;
  MonitorElement* mE_3000;
  MonitorElement* mP;
  MonitorElement* mP_80;
  MonitorElement* mP_3000;
  MonitorElement* mPt;
  MonitorElement* mPt_80;
  MonitorElement* mPt_3000;
  MonitorElement* mMass;
  MonitorElement* mMass_80;
  MonitorElement* mMass_3000;
  //  MonitorElement* mConstituents;
  //  MonitorElement* mConstituents_80;
  //  MonitorElement* mConstituents_3000;
  MonitorElement* mHadTiming;
  MonitorElement* mEmTiming;

  //Corr jets
  MonitorElement* mCorrJetPt;
  MonitorElement* mCorrJetPt_80;
  MonitorElement* mCorrJetPt_3000;
  MonitorElement* mCorrJetEta;
  MonitorElement* mCorrJetPhi;
  MonitorElement* mpTRatio;
  MonitorElement* mpTRatioB_d;
  MonitorElement* mpTRatioE_d;
  MonitorElement* mpTRatioF_d;
  MonitorElement* mpTRatio_30_200_d;
  MonitorElement* mpTRatio_200_600_d;
  MonitorElement* mpTRatio_600_1500_d;
  MonitorElement* mpTRatio_1500_3500_d;
  MonitorElement* mjetArea;

  // Leading Jet Parameters
  MonitorElement* mEtaFirst;
  MonitorElement* mPhiFirst;
  MonitorElement* mEFirst;
  MonitorElement* mEFirst_80;
  MonitorElement* mEFirst_3000;
  MonitorElement* mPtFirst;
  MonitorElement* mPtFirst_80;
  MonitorElement* mPtFirst_3000;

  MonitorElement* mNJetsEtaC;
  MonitorElement* mNJetsEtaF;

  MonitorElement* mNJets1;
  MonitorElement* mNJets2;

  // DiJet Parameters
  MonitorElement* mMjj;
  MonitorElement* mMjj_3000;

  // JPTJet specific
  MonitorElement* mPtFractionPionInVertexInCalo;
  MonitorElement* mPtFractionPionInVertexOutCalo;
  MonitorElement* mPtFractionPionOutVertexInCalo;

  MonitorElement* mPtFractionMuonInVertexInCalo;
  MonitorElement* mPtFractionMuonInVertexOutCalo;
  MonitorElement* mPtFractionMuonOutVertexInCalo;

  MonitorElement* mPtFractionElecInVertexInCalo;
  MonitorElement* mPtFractionElecInVertexOutCalo;
  MonitorElement* mPtFractionElecOutVertexInCalo;

  //
  MonitorElement* mMultiplicityPionInVertexInCalo;
  MonitorElement* mMultiplicityPionInVertexOutCalo;
  MonitorElement* mMultiplicityPionOutVertexInCalo;

  MonitorElement* mMultiplicityMuonInVertexInCalo;
  MonitorElement* mMultiplicityMuonInVertexOutCalo;
  MonitorElement* mMultiplicityMuonOutVertexInCalo;

  MonitorElement* mMultiplicityElecInVertexInCalo;
  MonitorElement* mMultiplicityElecInVertexOutCalo;
  MonitorElement* mMultiplicityElecOutVertexInCalo;
  /*
    MonitorElement* mMaxEInEmTowers;
    MonitorElement* mMaxEInHadTowers;
    MonitorElement* mHadEnergyInHO;
    MonitorElement* mHadEnergyInHB;
    MonitorElement* mHadEnergyInHF;
    MonitorElement* mHadEnergyInHE;
    MonitorElement* mHadEnergyInHO_80;
    MonitorElement* mHadEnergyInHB_80;
    MonitorElement* mHadEnergyInHE_80;
    MonitorElement* mHadEnergyInHO_3000;
    MonitorElement* mHadEnergyInHB_3000;
    MonitorElement* mHadEnergyInHE_3000;
    MonitorElement* mEmEnergyInEB;
    MonitorElement* mEmEnergyInEE;
    MonitorElement* mEmEnergyInHF;
    MonitorElement* mEmEnergyInEB_80;
    MonitorElement* mEmEnergyInEE_80;
    MonitorElement* mEmEnergyInEB_3000;
    MonitorElement* mEmEnergyInEE_3000;
    MonitorElement* mEnergyFractionHadronic;
    MonitorElement* mEnergyFractionEm;
    MonitorElement* mHFTotal;
    MonitorElement* mHFTotal_80;
    MonitorElement* mHFTotal_3000;
    MonitorElement* mHFLong;
    MonitorElement* mHFLong_80;
    MonitorElement* mHFLong_3000;
    MonitorElement* mHFShort;
    MonitorElement* mHFShort_80;
    MonitorElement* mHFShort_3000;
    MonitorElement* mN90;
  */

  // pthat
  MonitorElement* mPthat_80;
  MonitorElement* mPthat_3000;

  // GenJet Generic Jet Parameters
  MonitorElement* mGenEta;
  MonitorElement* mGenPhi;
  MonitorElement* mGenPt;
  MonitorElement* mGenPt_80;
  MonitorElement* mGenPt_3000;

  // GenJet Leading Jet Parameters
  MonitorElement* mGenEtaFirst;
  MonitorElement* mGenPhiFirst;

  // JPTJet<->GenJet matching
  MonitorElement* mAllGenJetsPt;
  MonitorElement* mMatchedGenJetsPt;
  MonitorElement* mAllGenJetsEta;
  MonitorElement* mMatchedGenJetsEta;
  MonitorElement* mGenJetMatchEnergyFraction;
  MonitorElement* mReverseMatchEnergyFraction;
  MonitorElement* mRMatch;
  MonitorElement* mDeltaEta;
  MonitorElement* mDeltaPhi;
  MonitorElement* mEScale;
  MonitorElement* mlinEScale;  //new
  MonitorElement* mDeltaE;

  MonitorElement* mEScale_pt10;  //new
  MonitorElement* mEScaleFineBin;  //new

  MonitorElement* mpTScaleB_s;
  MonitorElement* mpTScaleE_s;
  MonitorElement* mpTScaleF_s;
  MonitorElement* mpTScaleB_d;
  MonitorElement* mpTScaleE_d;
  MonitorElement* mpTScaleF_d;
  MonitorElement* mpTScalePhiB_d;
  MonitorElement* mpTScalePhiE_d;
  MonitorElement* mpTScalePhiF_d;

  MonitorElement* mpTScale_30_200_s;
  MonitorElement* mpTScale_200_600_s;
  MonitorElement* mpTScale_600_1500_s;
  MonitorElement* mpTScale_1500_3500_s;

  MonitorElement* mpTScale_30_200_d;
  MonitorElement* mpTScale_200_600_d;
  MonitorElement* mpTScale_600_1500_d;
  MonitorElement* mpTScale_1500_3500_d;

  MonitorElement* mpTScale1DB_30_200;
  MonitorElement* mpTScale1DE_30_200;
  MonitorElement* mpTScale1DF_30_200;
  MonitorElement* mpTScale1DB_200_600;
  MonitorElement* mpTScale1DE_200_600;
  MonitorElement* mpTScale1DF_200_600;
  MonitorElement* mpTScale1DB_600_1500;
  MonitorElement* mpTScale1DE_600_1500;
  MonitorElement* mpTScale1DF_600_1500;
  MonitorElement* mpTScale1DB_1500_3500;
  MonitorElement* mpTScale1DE_1500_3500;
  MonitorElement* mpTScale1DF_1500_3500;
  MonitorElement* mpTScale1D_30_200;
  MonitorElement* mpTScale1D_200_600;
  MonitorElement* mpTScale1D_600_1500;
  MonitorElement* mpTScale1D_1500_3500;

  MonitorElement* mDelEta;
  MonitorElement* mDelPhi;
  MonitorElement* mDelPt;

  // Matching parameters
  double mMatchGenPtThreshold;
  double mGenEnergyFractionThreshold;
  double mReverseEnergyFractionThreshold;
  double mRThreshold;

  std::string JetCorrectionService;

  // Switch on/off unimportant histogram
  std::string  mTurnOnEverything;

  // Energy Profiles
  MonitorElement* mHadEnergyProfile;
  MonitorElement* mEmEnergyProfile;
  MonitorElement* mJetEnergyProfile;
  /*
    MonitorElement* mHadJetEnergyProfile;
    MonitorElement* mEMJetEnergyProfile;
  */

  // CaloMET
  MonitorElement* mCaloMEx;
  MonitorElement* mCaloMEx_3000;
  MonitorElement* mCaloMEy;
  MonitorElement* mCaloMEy_3000;
  MonitorElement* mCaloMET;
  MonitorElement* mCaloMET_3000;
  MonitorElement* mCaloMETPhi;
  MonitorElement* mCaloSumET;
  MonitorElement* mCaloSumET_3000;
  MonitorElement* mCaloMETSig;
  MonitorElement* mCaloMETSig_3000;

  // RecHits
  MonitorElement* mHBEne;
  MonitorElement* mHBTime;
  MonitorElement* mHEEne;
  MonitorElement* mHETime;
  MonitorElement* mHOEne;
  MonitorElement* mHOTime;
  MonitorElement* mHFEne;
  MonitorElement* mHFTime;
  MonitorElement* mEBEne;
  MonitorElement* mEBTime;
  MonitorElement* mEEEne;
  MonitorElement* mEETime;


};
#endif
