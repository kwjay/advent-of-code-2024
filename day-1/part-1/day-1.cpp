#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
  const std::string filename = "day-1/part-1/input/data";
  std::ifstream inputFile(filename);
  std::vector<int> firstColumn, secondColumn;

  int firstValue, secondValue;
  while (inputFile >> firstValue >> secondValue)
  {
    firstColumn.push_back(firstValue);
    secondColumn.push_back(secondValue);
  }
  std::sort(firstColumn.begin(), firstColumn.end());
  std::sort(secondColumn.begin(), secondColumn.end());

  int result = 0;
  for (int i = 0; i < firstColumn.size(); i++)
  {
    result += abs(firstColumn[i] - secondColumn[i]);
  }
  printf("The result is: %d\n", result);
}