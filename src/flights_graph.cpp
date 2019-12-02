#include "../include/flights_graph.h"

FlightsGraph::FlightsGraph(vector<Edge> const &edges)
{
  for (auto &edge : edges)
  {
    this->AddEdge(edge);
  }
}

void FlightsGraph::AddEdge(Edge const &entry)
{
  int src = entry.sourceId;
  int dest = entry.destinationId;
  int weight = entry.weight;

  this->adjacencyList[src].push_back(make_pair(dest, weight));
}
