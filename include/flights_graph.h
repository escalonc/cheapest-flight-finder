#include <vector>
#include <utility>
#include <string>

#include "data.h"

using std::make_pair;
using std::pair;
using std::string;
using std::vector;

typedef pair<int, int> Pair;

class FlightsGraph
{
	vector<vector<Pair>> adjacencyList;

public:
	FlightsGraph(vector<Edge> const &edges);
	void AddEdge(Edge const &edges);
};
