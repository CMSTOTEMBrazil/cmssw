#include "EventFilter/EcalRawToDigi/plugins/EcalUnpackerWorkerESProducer.h"

EcalUnpackerWorkerESProducer::EcalUnpackerWorkerESProducer(const edm::ParameterSet& iConfig)
{
  conf_ = iConfig;
  if (conf_.exists("ComponentName"))
    setWhatProduced(this,conf_.getParameter<std::string>("ComponentName"));
  else
    setWhatProduced(this,"");
}


EcalUnpackerWorkerESProducer::~EcalUnpackerWorkerESProducer(){}


EcalUnpackerWorkerESProducer::ReturnType
EcalUnpackerWorkerESProducer::produce(const EcalUnpackerWorkerRecord & iRecord)
{
   using namespace edm::es;

   EcalUnpackerWorkerESProducer::ReturnType euw(new EcalUnpackerWorker(conf_));

   //set eshandles
   euw->setHandles(iRecord);

   return euw;
}
