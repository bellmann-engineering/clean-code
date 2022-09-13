#include <vector>

class CpuMonitor 
{
	private:
		int Value = 0;
		const int _alertThreshold;

	public:
		CpuMonitor(int alertTreshold);

		int getValue() const;
		void setValue(int value);
		const bool getExceedsThreshold();
};

class Client 
{
    public:
        void AlertService(std::vector<CpuMonitor*> &cpuMonitors);
};