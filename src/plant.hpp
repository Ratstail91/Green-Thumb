#ifndef PLANT_HPP_
#define PLANT_HPP_

#include "bbox.hpp"
#include "vector2.hpp"

#include <chrono>

class Plant {
public:
	typedef std::chrono::steady_clock Clock;

	enum Type {
		NONE,
		BASIC,
	};

	Plant() = default;
	~Plant() = default;

	Plant(Type argType, double argX, double argY, double argW, double argH) {
		type = argType;
		pos = {argX, argY};
		bbox = {0,0,argW,argH};
	}

	Vector2 SetPos(Vector2 v) { return pos = v; }
	Vector2 GetPos() { return pos; }

	BBox SetBBox(BBox bb) { return bbox = bb; }
	BBox GetBBox() { return bbox; }	

	Type SetType(Type t) { return type = t; }
	Type GetType() { return type; }

	Clock::time_point ResetAge() { return birth = Clock::now(); }
	Clock::duration GetAge() { return Clock::now() - birth; }

private:
	Vector2 pos;
	BBox bbox;
	Type type = Type::NONE;
	Clock::time_point birth = Clock::now();
};

#endif
