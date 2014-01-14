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

	Type SetType(Type t) { return type = t; }
	Type GetType() { return type; }
	Clock::time_point ResetAge() { return birth = Clock::now(); }
	Clock::duration GetAge() { return Clock::now() - birth; }

private:
	Type type = Type::NONE;
	Clock::time_point birth = Clock::now();
};

#endif
