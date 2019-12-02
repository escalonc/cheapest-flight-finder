#include <vector>
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "../include/csv_parser.h"

using std::cout;
using std::getline;
using std::ios;
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

  int id;
  std::string line;

  getline(*file, line);

  while (getline(*this->file, line, ','))
  {
    cout << line << std::endl;
  }

  this->file->close();

  return cities;
}
