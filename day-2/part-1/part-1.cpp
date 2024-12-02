#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

bool checkRange(const int firstValue, const int secondValue) {
    const int difference = abs(secondValue - firstValue);
    return 1 <= difference && difference <= 3;
}

bool checkReport(const std::vector<int> &report) {
    const bool ascending = report[0] - report[1] < 0;
    for (int i = 0; i < report.size() - 1; i++) {
        if (ascending != report[i] < report[i + 1]) return false;
        if (!checkRange(report[i], report[i + 1])) return false;
    }
    return true;
}

int main() {
    const std::string filename = "day-2/part-1/input/data";
    std::ifstream inputFile(filename);
    std::vector<std::vector<int>> reports;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<int> currentReport;
        std::istringstream lineStream(line);
        int level;
        while (lineStream >> level) {
            currentReport.push_back(level);
        }
        reports.push_back(currentReport);
    }
    int result = 0;
    for (const auto & report : reports) {
        if (checkReport(report)) {;
            result += 1;
        }
    }
    printf("The result is: %d\n", result);
}