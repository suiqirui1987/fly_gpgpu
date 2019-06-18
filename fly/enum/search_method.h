/** @file search_method.h
  * Definition of enum for search method used to explore configuration space during kernel tuning.
  */
#pragma once

namespace fly
{

/** @enum SearchMethod
  * Enum for search method used to explore configuration space during kernel tuning.
  */
enum class SearchMethod
{
    /** Explores kernel configurations in deterministic order. No additional search parameters are needed.
      */
    FullSearch,

    /** Explores kernel configurations in random order. No additional search parameters are needed.
      */
    RandomSearch,

    /** Explores kernel configurations using simulated annealing method. Additional parameter specifies maximum temperature.
      */
    Annealing,

    /** Explores kernel configurations using Markov chain Monte Carlo method. No additional search parameters are needed.
      */
    MCMC
};

} // namespace fly
