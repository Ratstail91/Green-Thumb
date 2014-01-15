#include "plant.hpp"

#include <vector>

#define D(x) std::chrono::seconds(x)

static const std::vector<std::vector<Plant::Clock::duration>> plantTable = {
	//NONE
	{},
	//BASIC: 4
	{D(5), D(10), D(15), },
};

void Plant::Update(double delta) {
	if (GetAge() > plantTable[type][state]) {
		state++;
	}
}
