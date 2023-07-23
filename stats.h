#include <vector>
#include <math.h>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;
namespace Statistics {
    // define the Stats structure here. See the tests to infer its properties
    
    struct Stats
    {
        double average = 0;
        double max = 0;
        double min = 0;
    };
    
    Stats ComputeStatistics(const std::vector<double>&);

}

class IAlerter
{
public:
	virtual void sendAlert() = 0;
};

class EmailAlert : public IAlerter
{
public:
	virtual void sendAlert() override;
    bool emailSent = false;
};


class LEDAlert :public IAlerter
{
public:
	virtual void sendAlert() override;
    bool ledGlows = false;
};



class StatsAlerter
{
public:
	StatsAlerter(float maxThreshold, std::vector<IAlerter*> alerters);
	void checkAndAlert(const std::vector<double>& val);
private:
	float maxThreshold;
	std::vector<IAlerter*> alerters;
};