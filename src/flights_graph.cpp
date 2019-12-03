#include "../include/flights_graph.h"

FlightsGraph::FlightsGraph(vector<Edge *> const edges)
{
  for (auto edge : edges)
  {
    this->AddEdge(edge);
  }
}

void FlightsGraph::AddEdge(Edge *edge)
{
  int src = edge->sourceId;
  int dest = edge->destinationId;
  int weight = edge->weight;

  this->adjacencyList[src].push_back(make_pair(dest, weight));
}
