//
//  population.hpp
//  Genetic
//
//  Created by Indi Kernick on 22/9/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef population_hpp
#define population_hpp

#include <vector>
#include <algorithm>
#include "random.hpp"
#include "chromosome.hpp"

template <typename Chromosome>
using Population = std::vector<Chromosome>;

template <typename Chromosome>
Population<Chromosome> makePopulation(const size_t size) {
  return {size};
}

template <typename Chromosome>
Seed initRandom(Population<Chromosome> &pop, const Seed seed) {
  Generator gen(seed);
  Distribution<Allele<Chromosome>> dist;
  for (Chromosome &c : pop) {
    for (Allele<Chromosome> &a : c) {
      a = dist(gen);
    }
  }
  return gen();
}

template <typename Chromosome>
void initConstant(Population<Chromosome> &pop, const Allele<Chromosome> allele) {
  Chromosome chromosome;
  std::uninitialized_fill(chromosome.begin(), chromosome.end(), allele);
  initConstant(pop, chromosome);
}

template <typename Chromosome>
void initConstant(Population<Chromosome> &pop, const Chromosome chromosome) {
  std::fill(pop.begin(), pop.end(), chromosome);
}

#endif
