#include<iostream>
#include "tqueue.h"
#include "tproc.h"
#include "tjobstream.h"
#include <iomanip>  
using  namespace std;
#define ditailed 20
int main(){
    srand(time(0));
    int qLen = 4;
    int pRate = 40;
    int jsIntens = 20;
    int clockCount = 21;
    cout<<"Vvtdite dlinu ocheredi: ";
    cin>>qLen;
    cout<<"Vvtdite chastotu processora: ";
    cin>>pRate;
    cout<<"Vvtdite intensivnost' potoka zadach: ";
    cin>>jsIntens;
    cout<<"Vvtdite kolichestvo taktov imitatsii: ";
    cin>>clockCount;
    TQueue<int> queue(qLen);
    TProc proc(pRate);
    TJobStream js(jsIntens);
    int overflow = 0;
    int downtime = 0;
    int recivedtasks = 0;
    bool vivod = clockCount<=20;
    if(vivod) cout<<"nomer takta      sostoyanie potoka zadach        sostoyanie processora    zadach v ocheredi"<<endl;
    for(int i=0;i<clockCount;i++){
        if(vivod) cout<<i<<". "<<setw(25-i/10);
        int nj = js.GetNewJob();
        if(nj!=-1){
            if(!queue.IsFull()){
                queue.Push(nj);
                if(vivod) cout<<"OK ";//<<"Zadacha popala v ochered'. ";

            }
            else{
                overflow+=1;
                if(vivod) cout<<"overflow ";//<<"Zadacha ne popala v ochered' iz-za perepolniniya. ";
            }
        }
        else{
            if(vivod) cout<<"not recived ";//<<"Zadacha ne poluchena is potoka zadach. ";
        }
        cout<<setw(30);
        if(!proc.IsProcBusy()){
            if(!queue.IsEmpty()){
                proc.LoadNewJob(queue.Pop());
                recivedtasks+=1;
                if(vivod) cout<<"OK ";//<<"Zadacha postupila v sistemu.";
            }
            else{
                downtime+=1;
                if(vivod) cout<<"downtime ";//<<"Prostoy iz-za otsutstviya zadach v ocheredi.";

            }
        }
        else{
            if(vivod) cout<<"busy ";//<<"Processor zanyat predidushey zadachey.";
        }
        if(vivod) cout<<setw(20)<<queue.getSize()<<endl;
        proc.Run();
    }
    cout<<"Kolichestvo taktov prostoya iz-za otsutstviya zadach v ocheredi: "<<downtime<<" ("<<(float)downtime/clockCount*100<<"%)"<<endl;
    cout<<"Kolichestvo taktov prostoya iz-za perepolniniya ocheredi: "<<overflow<<" ("<<(float)overflow/clockCount*100<<"%)"<<endl;
    cout<<"Kolichestvo zadaniy postupivshih v sistemu: "<<recivedtasks<<endl;
    cout<<"Srednee kolichestvo taktov na vypolnenie zadaniya: "<<(float)clockCount/recivedtasks<<endl;

    return 0;
}