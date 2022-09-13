#include<vector>
 
using namespace std;
 
class CpuMonitor 
{
	private:
		int Value = 0;

	public:
		int getValue() const;
		void setValue(int newValue);
};

class Client 
{
	void AlertService(vector<CpuMonitor*> &cpuMonitors);
};