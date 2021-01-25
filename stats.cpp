#include "stats.h"

#include <algorithm>
#include <cmath>

Stats Statistics::ComputeStatistics(const std::vector<float>& numVect) {
    //Implement statistics here
    Stats ret_stat ; 
    /*Init*/
    ret_stat.average = 0.0;
    ret_stat.min = 0.0;
    ret_stat.max = 0.0; 

    /*Check Validity*/
    if (numVect.empty())
    {
        ret_stat.average = std::nan("");
        ret_stat.min = std::nan("");
        ret_stat.max = std::nan("");
        return ret_stat;
    }
    else 
    {
        /*Calc Average*/
        for (auto i : numVect)
        {
            ret_stat.average += i;
        }
        ret_stat.average = ret_stat.average / numVect.size();

        /*Get max*/
        ret_stat.max = *max_element(numVect.begin(), numVect.end());

        /*Get min*/
        ret_stat.min = *min_element(numVect.begin(), numVect.end());

        return ret_stat;
    }
    
}

EmailAlert::EmailAlert() 
{ 
    emailSent = false; 
}

void EmailAlert::SetAlert()
{
    this->emailSent = true;
}

LEDAlert::LEDAlert() 
{ 
    ledGlows = false; 
}

void LEDAlert::SetAlert()
{
    this->ledGlows = true; 
}

StatsAlerter::StatsAlerter(const float m , std::vector<IAlerter*>& a)
    :maxTh(m) , alerter(a)
{}

void StatsAlerter::checkAndAlert(const std::vector<float>& numVect)
{
    for (auto i : numVect)
    {
        if (i > maxTh)
        { 
            for (int j = 0; j < alerter.size(); ++j)
            {
                this->alerter.at(j)->SetAlert();
            }
            break;
        }
    }
}

