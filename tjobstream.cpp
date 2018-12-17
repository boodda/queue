#include "tjobstream.h"
#include <cstdlib>
TJobStream::TJobStream(int Intens){
    JobIntens = Intens;
}
int TJobStream::GetNewJob(){
    static int id = 0;
    if(rand()%100<JobIntens)
        return id++;
    else 
        return -1;
}