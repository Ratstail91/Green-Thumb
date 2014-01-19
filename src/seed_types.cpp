#include "seed_types.hpp"

#define SEC(x) std::chrono::seconds(x)

const std::vector<std::vector<std::chrono::duration<int, std::ratio<1,1>>>> seedGrowth = {
	//blue fruit
	{SEC(2), SEC(4), SEC(6), },
	//red fruit
	{SEC(5), SEC(10), SEC(15), },
};