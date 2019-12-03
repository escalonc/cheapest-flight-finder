// #include <bits/stdc++.h>
#include <queue>
#include <iostream>
#include <functional>
#include <list>
#include "../include/flights_graph.h"

#define INF 0x3f3f3f3f
#define V 25

using std::greater;
using std::list;
using std::priority_queue;

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

  std::cout << weight << std::endl;

  this->adjacencyList[src].push_back(make_pair(dest, weight));
}

void FlightsGraph::ShortestPath(int src)
{

  priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

  vector<int> dist(V, INF);

  pq.push(make_pair(0, src));
  dist[src] = 0;

  while (!pq.empty())
  {

    int u = pq.top().second;
    pq.pop();

    vector<pair<int, int>>::iterator i;
    for (i = adjacencyList[u].begin(); i != adjacencyList[u].end(); ++i)
    {

      int v = (*i).first;
      int weight = (*i).second;

      if (dist[v] > dist[u] + weight)
      {

        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
  }

  printf("Vertex   Distance from Source\n");
  for (int i = 0; i < V; ++i)
    printf("%d \t\t %d\n", i, dist[i]);
}
