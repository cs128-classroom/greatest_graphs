// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : <Your Name>                  Environment : ubuntu:bionic               //
//  Date ......: <00/00/00>                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"
/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>
#include <vector>

#include "solution.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("Should Throw Invalid Argument", "[Test 1]") {
  GraphAdjList<std::string, int> g;

  std::vector<std::pair<int, int>> times = {
      {9, 10}, {25, 30}, {32, 40}, {60, 62}, {82, 100}};
  std::vector<std::string> locations = {
      "David Kinley Hall", "CIF", "Siebel CS", "Main Library", "ISR", "ECEB"};
  REQUIRE_THROWS(
      IsValidSchedule(g, locations, times));  // unequal locations and events

  g.AddVertex("David Kinley Hall");
  locations.pop_back();

  REQUIRE_THROWS(
      IsValidSchedule(g, locations, times));  // Locations not present in graph

  g.AddVertex("CIF");
  g.AddVertex("Siebel CS");
  g.AddVertex("Main Library");
  g.AddVertex("ISR");
  g.AddEdge("CIF", "Siebel CS", 1);
  g.AddEdge("Siebel CS", "Main Library", 17);
  g.AddEdge("Main Library", "ISR", 20);

  REQUIRE_THROWS(IsValidSchedule(
      g, locations, times));  // No direct edge between locations in schedule

  g.AddEdge("David Kinley Hall", "CIF", 15);

  times.pop_back();
  times.push_back({82, 81});

  REQUIRE_THROWS(IsValidSchedule(
      g, locations, times));  // end time before start isnt valid
}

TEST_CASE("Valid Schedules", "[Test 2]") {
  GraphAdjList<std::string, int> g;
  g.AddVertex("A");
  g.AddVertex("B");
  g.AddVertex("C");
  g.AddVertex("D");
  g.AddEdge("A", "B", 10);
  g.AddEdge("B", "C", 5);
  g.AddEdge("C", "D", 12);
  std::vector<std::string> locations = {"A", "B", "C", "D"};
  std::vector<std::pair<int, int>> times = {
      {9, 10}, {20, 25}, {35, 40}, {55, 60}};
  REQUIRE(IsValidSchedule(g, locations, times));
}

TEST_CASE("Invalid Schedules", "[Test 2]") {
  GraphAdjList<std::string, int> g;
  g.AddVertex("A");
  g.AddVertex("B");
  g.AddVertex("C");
  g.AddVertex("D");
  g.AddEdge("A", "B", 10);
  g.AddEdge("B", "C", 5);
  g.AddEdge("C", "D", 12);
  std::vector<std::string> locations = {"A", "B", "C"};
  std::vector<std::pair<int, int>> times = {{9, 10}, {20, 25}, {29, 40}};
  REQUIRE(!IsValidSchedule(g, locations, times));
}

/////////////////////////////////////////////////////////////////////////////////////////////