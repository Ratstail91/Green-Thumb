#ifndef PLANT_HPP_
#define PLANT_HPP_

#include "seed_types.hpp"

#include <chrono>

class Plant {
public:
	typedef std::chrono::steady_clock Clock;

	Plant() = delete;

	Plant(SeedType argType) {
		type = argType;
	}

	void Update(double delta) {
		//ensure that you don't overgrow the number of stages defined in seedGrowth
		//check to see if the plant is old enough to grow
		if (stage < seedGrowth[type].size() && Clock::now() - birth > seedGrowth[type][stage]) {
			stage++;
		}
	}

	int SetStage(int i) { return stage = i; }
	int GetStage() { return stage; }

	SeedType SetType(SeedType t) { return type = t; }
	SeedType GetType() { return type; }

	Clock::time_point ResetAge() { return birth = Clock::now(); }
	Clock::duration GetAge() { return Clock::now() - birth; }

private:
	int stage = 0;
	SeedType type;
	Clock::time_point birth = Clock::now();
};

#endif
