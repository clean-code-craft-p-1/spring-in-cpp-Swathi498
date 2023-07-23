#include "stats.h"
#include <limits.h>

Statistics::Stats Statistics::ComputeStatistics(const std::vector<double>& vec) 
{
    //Implement statistics here
    Stats stat;
    
    if(vec.empty())
    {
        stat.average = NAN;
        stat.max 	  = NAN;
        stat.min 	  = NAN;
        return stat;
    }
    
    stat.average = accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
    stat.max 	  = *max_element(vec.begin(), vec.end());
    stat.min 	  = *min_element(vec.begin(), vec.end());
    return stat;
}


void EmailAlert::sendAlert()
{
    emailSent = true;
}

void LEDAlert::sendAlert()
{
    ledGlows = true;
}

StatsAlerter::StatsAlerter(float maxThreshold, std::vector<IAlerter*> alerters)
{
    this->maxThreshold = maxThreshold;

    for(unsigned int i = 0; i < alerters.size(); i++)
    {
        this->alerters.push_back(alerters[i]);
    }
    
} 
void StatsAlerter::checkAndAlert(const std::vector<double>& val)
{
    auto computeMax = Statistics::ComputeStatistics(val);
    if(computeMax.max > maxThreshold)
    {
        for(unsigned int i = 0; i < alerters.size(); i++)
        {
            //send sendAlert for all the alerters classes
            alerters[i]->sendAlert();
        }
    }
}