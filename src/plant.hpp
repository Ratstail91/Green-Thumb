#ifndef PLANT_HPP_
#define PLANT_HPP_

#include "seed_types.hpp"

#include "bbox.hpp"
#include "vector2.hpp"

#include <chrono>

class Plant {
public:
	typedef std::chrono::steady_clock Clock;

	Plant() = default;
	~Plant() = default;

	Plant(SeedType argType, double argX, double argY, double argW, double argH) {
		type = argType;
		pos = {argX, argY};
		bbox = {0,0,argW,argH};
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

	Vector2 SetPos(Vector2 v) { return pos = v; }
	Vector2 GetPos() { return pos; }

	BBox SetBBox(BBox bb) { return bbox = bb; }
	BBox GetBBox() { return bbox; }	

	SeedType SetType(SeedType t) { return type = t; }
	SeedType GetType() { return type; }

	Clock::time_point ResetAge() { return birth = Clock::now(); }
	Clock::duration GetAge() { return Clock::now() - birth; }

private:
	int stage = 0;
	Vector2 pos;
	BBox bbox;
	SeedType type;
	Clock::time_point birth = Clock::now();
};

#endif
