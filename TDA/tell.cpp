#include<iostream>
#include<string>

#include "tell.h"
 
using namespace std;

int CpuMonitor::getValue() const {
    return Value;
}

void CpuMonitor::setValue(int val) {
    Value = val;
}

const bool CpuMonitor::getExceedsThreshold() {

    return getValue() >= _alertThreshold;
}

void Client::AlertService(std::vector<CpuMonitor*> &cpuMonitors) {

    for (auto monitor : cpuMonitors) {
        if(monitor->getExceedsThreshold()) {

            // Alert

        }
    }
}

int main()
{
	// for compilation only
}
