#include <vector>

typedef struct
{
    float average, max, min; 
}Stats;

namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>&);
}