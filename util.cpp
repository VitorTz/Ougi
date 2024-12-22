#include "util.h"
#include <random>
#include <limits>


static std::random_device rd{};
static std::mt19937 gen(rd());
static std::uniform_int_distribution<int> distrib(0, std::numeric_limits<int>::max());
static std::uniform_int_distribution<long long> distrib_l(0, std::numeric_limits<long long>::max());


int og::randint(const int start, const int end) {
	return start + distrib(gen) % (end - start);
}