#include "tproc.h"
#include <cstdlib>

TProc::TProc(int Rate){
    ProcRate = Rate;
    JobId = -1;
}
bool TProc::IsProcBusy(){
    return JobId!=-1;
}
void TProc::LoadNewJob(int JobId){
    this->JobId = JobId;
}
void TProc::Run(){
    if(rand()%100<ProcRate){
        JobId = -1;
    }
}