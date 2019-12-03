#include <iostream>
#include <vector>

#include "../include/csv_parser.h"
#include "../include/flights_graph.h"

using std::vector;

int main()
{
  // CsvParser citiesParser("cities.csv");
  CsvParser flightsParser("data.csv");
  // auto cities = citiesParser.ParseCities();

  auto flights = flightsParser.ParseFlights();
  vector<Edge *> edges;

  for (auto flight : flights)
  {
    edges.push_back(new Edge{flight->sourceId, flight->destinationId, flight->weight});
  }

  auto flightsGraph = new FlightsGraph(edges);

  flightsGraph->ShortestPath(1);
}
