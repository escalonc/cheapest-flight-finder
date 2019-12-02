#pragma once

#include <fstream>
#include <string>

#include "data.h"

using std::ifstream;
using std::string;

class CsvParser
{
    string path;
    ifstream *file;

public:
    CsvParser(string path);
    vector<City *> ParseCities();
};
