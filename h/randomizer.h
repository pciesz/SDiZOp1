#ifndef SDIZOP1_RANDOMIZER_H
#define SDIZOP1_RANDOMIZER_H

#include <random>

class randomizer
{
public:
	static long random(long min, long max)
	{
		std::random_device r;
		std::default_random_engine e(r());
		std::uniform_int_distribution<long> uniform_dist(min, max);
		return uniform_dist(e);
	}
};

#endif //SDIZOP1_RANDOMIZER_H
