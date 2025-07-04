#include <iostream>
#include "src/processService.hpp"
#include <vector>
#include "src/processLog.hpp"
#include "src/cfs.hpp"
#include <fstream>

int main(int argv, char* argc[]) {
    std::vector<Process> processObjs = getProcessFromJson("../resources/process.json");
    std::vector<Process*> processes;
    for (auto& p : processObjs) {
        processes.push_back(&p);
    }
    cfs scheduler;
    std::vector<ProcessLog*> logs = scheduler.schedule(processes);
    
    std::ofstream outFile("../process_schedule.csv");
    
    outFile << "pid,start_time,end_time" << std::endl;
    
    for(auto processLog: logs) {
        outFile << processLog->pid << ","
                << processLog->startTime << ","
                << processLog->endTime << std::endl;
    }
    
    outFile.close();
    return 0;
}


// Higher-priority processes "age" slower in vruntime, so they get scheduled more frequently.