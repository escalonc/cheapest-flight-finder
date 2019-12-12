#include <iostream>
#include <vector>

#include "../include/csv_parser.h"
#include "../include/flights_graph.h"
#include "../include/timer.h"

using std::vector;

int main()
{
  // CsvParser citiesParser("cities.csv");
  CsvParser flightsParser("data.csv");
  // auto cities = citiesParser.ParseCities();

  double start, finish;

  auto flights = flightsParser.ParseFlights();
  vector<Edge *> edges;

  for (auto flight : flights)
  {
    edges.push_back(new Edge{flight->sourceId, flight->destinationId, flight->weight});
  }

  auto flightsGraph = new FlightsGraph(edges);

  GET_TIME(start);
  flightsGraph->ShortestPath(1);
  GET_TIME(finish);

  std::cout << std::endl
            << "Total time: " << finish - start << std::endl;
}
