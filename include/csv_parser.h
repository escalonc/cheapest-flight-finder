#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "data.h"

using std::ifstream;
using std::string;
using std::vector;

class CsvParser
{
    std::string path;
    ifstream *file;

public:
    CsvParser(string path);
    vector<City *> ParseCities();
};
