#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <string>
#include <vector>

#include "GraphAdjList.hpp"

bool IsValidSchedule(const GraphAdjList<std::string, int>& g,
                     const std::vector<std::string>& locations,
                     const std::vector<std::pair<int, int>>& times);

#endif  // SOLUTION_HPP
