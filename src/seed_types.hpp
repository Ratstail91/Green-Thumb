#ifndef SEEDTYPES_HPP_
#define SEEDTYPES_HPP_

#include <chrono>
#include <vector>

extern const std::vector<std::vector<std::chrono::duration<int, std::ratio<1,1>>>> seedGrowth;

enum SeedType {
	BLUEFRUIT = 0,
	REDFRUIT = 1,
};

#endif
