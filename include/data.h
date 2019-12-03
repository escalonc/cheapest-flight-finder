#pragma once

#include <string>
using std::string;

struct City
{
  int id;
  string name;
};

struct Flight
{
  int sourceId, destinationId, weight;
};

struct Edge
{
  int sourceId, destinationId, weight;
};
