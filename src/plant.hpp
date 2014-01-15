#ifndef PLANT_HPP_
#define PLANT_HPP_

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

	Plant(Type argType, int argX, int argY) {
		type = argType;
		x = argX;
		y = argY;
	}

	Type SetType(Type t) { return type = t; }
	Type GetType() { return type; }
	Clock::time_point ResetAge() { return birth = Clock::now(); }
	Clock::duration GetAge() { return Clock::now() - birth; }
	int SetX(int argX) { return x = argX; }
	int GetX() { return x; }
	int SetY(int argY) { return y = argY; }
	int GetY() { return y; }

private:
	Type type = Type::NONE;
	Clock::time_point birth = Clock::now();
	int x = 0, y = 0;
};

#endif
