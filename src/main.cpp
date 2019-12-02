#include <iostream>
#include "../include/csv_parser.h"

int main()
{
  CsvParser parser("cities.csv");
  parser.ParseCities();
  std::cout
      << "Hello Easy C++ project!" << std::endl;
}
