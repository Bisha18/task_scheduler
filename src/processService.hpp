#ifndef PROCESS_SERVICE_HPP
#define PROCESS_SERVICE_HPP

#include <string>
#include <vector>

enum PROCESS_NATURE {
    CPU_BOUND,
    IO_BOUND,
};

struct ProcessState {
    long long counter;
};

struct Process {
    int pid;
    long long vruntime;
    int cpu_burst_time;
    int priority;
    ProcessState processState;
    PROCESS_NATURE processNature;
};

PROCESS_NATURE stringToProcessNature(const std::string& nature);
std::vector<Process> getProcessFromJson(const std::string& filePath);

#endif
