#ifndef __TJOBSTREAM__H
#define __TJOBSTREAM__H
class TJobStream {
private:
    int JobIntens; // интенсивность потока задач
public:
    TJobStream (int Intens);
    int GetNewJob(void); // генерация нового задания
};
#endif