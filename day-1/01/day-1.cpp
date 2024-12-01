#include <algorithm>
#include <cstdio>
#include <fstream>
#include <map>
#include <vector>

int main()
{
    const std::string filename = "day-1/01/input/data";
    std::ifstream inputFile(filename);
    std::map<int, int> secondColumn;
    std::vector<int> firstColumn;
    int firstValue, secondValue;
    while (inputFile >> firstValue >> secondValue)
    {
        firstColumn.push_back(firstValue);
        if (secondColumn.find(secondValue) != secondColumn.end()) {
            secondColumn[secondValue]++;
        }
        else {
            secondColumn[secondValue] = 1;
        }
    }

    int result = 0;
    for (const auto& row : firstColumn) {
        if (secondColumn.find(row) != secondColumn.end()) {
            result += row * secondColumn[row];
        }
    }
    printf("The result is: %d\n", result);
}