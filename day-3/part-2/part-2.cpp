#include <fstream>
#include <iostream>
#include <regex>

int main() {
	const std::string filename = "day-3/part-2/input/data";
	std::ifstream inputFile(filename);
	std::stringstream buffer;
	buffer << inputFile.rdbuf();
	std::string corruptedMemory = buffer.str();
	const std::regex pattern(R"(mul\((-?\d+(\.\d+)?),\s*(-?\d+(\.\d+)?)\)|don't\(\)|do\(\))");
	auto matches = std::sregex_iterator(corruptedMemory.begin(), corruptedMemory.end(), pattern);
	auto end = std::sregex_iterator();
	int result = 0;
	bool calculate = true;
	for (auto it = matches; it != end; ++it) {
		if (it->str() == "don't()") {
			calculate = false;
		} else if (it->str() == "do()") {
			calculate = true;
		} else if (calculate) {
			size_t openParenthesis = it->str().find('(');
			size_t comma = it->str().find(',');
			int firstNumber = std::stoi(it->str().substr(openParenthesis + 1, comma - openParenthesis - 1));
			int secondNumber = std::stoi(it->str().substr(comma + 1, it->str().find(')') - comma - 1));
			result += firstNumber * secondNumber;
		}
	}
	std::cout << result << std::endl;
}