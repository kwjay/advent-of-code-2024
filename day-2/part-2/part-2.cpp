#include <cstdio>
#include <fstream>
#include <vector>
#include <sstream>


constexpr int MIN_DIFF = 1;
constexpr int MAX_DIFF = 3;

bool isSorted(const std::vector<int> &vector, const bool allowMistake) {
	int ascendingCount = 0, descendingCount = 0;
	for (int i = 0; i < vector.size() - 1; i++) {
		if (vector[i] > vector[i + 1]) {
			descendingCount++;
		} else if (vector[i] < vector[i + 1]) {
			ascendingCount++;
		}
	}
	if (allowMistake) return (ascendingCount >= vector.size() - 2) || (descendingCount >= vector.size() - 2);
	return ascendingCount == vector.size() - 1 || descendingCount == vector.size() - 1;
}

bool inRange(const int firstValue, const int secondValue) {
	const int difference = abs(firstValue - secondValue);
	return MIN_DIFF <= difference && difference <= MAX_DIFF;
}

bool checkReport(const std::vector<int> &report, const bool problemDampener) {
	const bool isSafe = isSorted(report, problemDampener);
	bool allowRangeViolation = problemDampener;
	for (int i = 0; isSafe && i < report.size() - 1; i++) {
		if (allowRangeViolation && !inRange(report[i], report[i + 1])) {
			if (i != 0 && !inRange(report[i - 1], report[i + 1])) {
				return false;
			}
			allowRangeViolation = false;
		}
	}
	return isSafe;
}

int main() {
	const std::string filename = "day-2/part-2/input/data";
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
		if (checkReport(report, true)) {;
			result += 1;
		}
	}
	printf("The result is: %d\n", result);
}