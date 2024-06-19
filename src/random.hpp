#ifndef RANDOM_HPP
#define RANDOM_HPP

#include "include.hpp"

namespace ML
{
    std::mt19937 rng;

    void set_rng_seed(const uint32_t& seed)
    {
        rng.seed(seed);
    }
}
#endif
