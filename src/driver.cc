#include <iostream>

#include "solution.hpp"

int main() {
  GraphAdjList<std::string, int> g;
  g.AddVertex("David Kinley Hall");
  g.AddVertex("CIF");
  g.AddVertex("Siebel CS");
  g.AddVertex("Main Library");
  g.AddVertex("ISR");
  g.AddEdge("David Kinley Hall", "CIF", 15);
  g.AddEdge("CIF", "Siebel CS", 1);
  g.AddEdge("Siebel CS", "Main Library", 17);
  g.AddEdge("Main Library", "ISR", 20);

  std::vector<std::pair<int, int>> times = {
      {9, 10}, {25, 30}, {32, 40}, {60, 62}, {82, 100}};
  std::vector<std::string> locations = {
      "David Kinley Hall", "CIF", "Siebel CS", "Main Library", "ISR"};
  std::cout << (IsValidSchedule(g, locations, times) ? "Valid" : "Invalid")
            << std::endl;
  return 0;
}
