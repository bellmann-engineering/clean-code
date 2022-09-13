#include<iostream>
#include<string>

#include "ask.h"
 
using namespace std;

int CpuMonitor::getValue() const 
{
    return Value;
}

void CpuMonitor::setValue(int newValue) 
{
    Value = newValue;
}

void Client::AlertService(vector<CpuMonitor*> &cpuMonitors) 
{
    
    for (auto cpuMonitor : cpuMonitors) 
    {
            if (cpuMonitor->getValue() > 90) 
            {
                // alert
            }
    }
}

int main()
{
	// for compilation only
}