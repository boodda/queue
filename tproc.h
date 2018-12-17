class TProc {
private:
    int ProcRate; // производительность процессора
    int JobId; // Id выполняемого задания
public:
    TProc (int Rate);
    bool IsProcBusy(void) ; // процессор занят?
    void LoadNewJob (int JobId); // приступить к выполнению нового задания
    void Run();
};