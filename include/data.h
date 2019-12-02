#pragma once

#include <string>
using std::string;

struct City
{
  int id;
  string name;
};

struct Edge
{
  int sourceId, destinationId, weight;
};
