#include <vector>
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "../include/csv_parser.h"

using std::getline;
using std::ios;
using std::stringstream;
using std::vector;

CsvParser::CsvParser(string path)
{
  this->path = path;
}

vector<City *> CsvParser::ParseCities()
{
  this->file = new ifstream();
  this->file->open(this->path.c_str());
  vector<City *> cities;

  if (!this->file->is_open())
  {
    throw std::runtime_error("Could not open file");
  }

  string idRecord;
  string nameRecord;
  std::string line;

  while (getline(*this->file, line))
  {
    std::stringstream ss(line);

    getline(ss, idRecord, ',');
    getline(ss, nameRecord, ',');

    stringstream formatter(idRecord);

    int id;
    formatter >> id;

    cities.push_back(new City{id, nameRecord});
  }

  this->file->close();

  return cities;
}

vector<Flight *> CsvParser::ParseFlights()
{
  this->file = new ifstream();
  this->file->open(this->path.c_str());
  vector<Flight *> flights;

  if (!this->file->is_open())
  {
    throw std::runtime_error("Could not open file");
  }

  string sourceIdRecord;
  string destinationIdRecord;
  string weightRecord;
  std::string line;

  while (getline(*this->file, line))
  {
    std::stringstream ss(line);

    getline(ss, sourceIdRecord, ',');
    getline(ss, destinationIdRecord, ',');
    getline(ss, weightRecord, ',');

    stringstream sourceFormatter(sourceIdRecord);
    stringstream destinationFormatter(destinationIdRecord);
    stringstream weightFormatter(weightRecord);

    int sourceId, destinationId, weight;
    sourceFormatter >> sourceId;
    destinationFormatter >> destinationId;
    weightFormatter >> weight;

    flights.push_back(new Flight{sourceId, destinationId, weight});
  }

  this->file->close();

  return flights;
}
