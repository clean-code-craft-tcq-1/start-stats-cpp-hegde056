#include <vector>

typedef struct
{
    float average, max, min; 
}Stats;

namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>&);
}

class IAlerter
{
public:
    virtual void SetAlert() = 0;
};

class EmailAlert : public IAlerter
{
public:
    bool emailSent;
    EmailAlert();
    void SetAlert();
};

class LEDAlert : public IAlerter
{
public:
    bool ledGlows;
    LEDAlert();
    void SetAlert();
};

class StatsAlerter
{
private : 
    float maxTh; 
    std::vector<IAlerter*> alerter; 

public : 
    StatsAlerter(const float , std::vector<IAlerter*>&);

    void checkAndAlert(const std::vector<float>&);
};


