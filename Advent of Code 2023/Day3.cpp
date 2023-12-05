#include "Day3.h"
#include "helper.h"

bool checkForSymbols(char u, char c, char d) {
	if (u != '.' && u < '0' || u > '9') {
		return true;	
	}
	if (c != '.' && c < '0' || c > '9') {
		return true;
	}
	if (d != '.' && d < '0' || d > '9') {
		return true;
	}
	return false;
}


void day3part1(std::ifstream* input) {
	int rows = 0,cols = 1;
	int total = 0;
	string line;
	getline(*input, line);
	rows = line.length() - 1;
	while (!input->eof()) {
		getline(*input, line);
		cols++;
	}
	input->clear();
	input->seekg(0);
	string prev = "";
	for (int i = 0; i < cols; i++) {
		prev.append(".");
	}
	string next = "";
	
	getline(*input, line);
	bool done = false;
	while (!done) {
		if (!input->eof()) {
			getline(*input, next);
		}
		if (next.empty())
		{
			next = "";
			for (int i = 0; i < cols; i++) {
				next.append(".");
			}
			done = true;
		}
		for (int i = 0; i < line.length(); i++) {
			char cur = line.at(i);
			if (cur >= '0' && cur <= '9') {
				int numDigits = 1;
				while (i + numDigits < line.length() && (cur = line.at(i + numDigits)) != '.' && cur >= '0' 
					&& cur <= '9'
				) {
					numDigits++;
				}
				int value = std::stoi(line.substr(i, numDigits));
				printf("%i \n", value);
				if (value == 737) {
					printf("here");
				}
				
				bool isPart = false;
				if (i > 0) {
					if (!isPart && checkForSymbols(prev.at(i - 1), line.at(i - 1), next.at(i - 1))) {
						isPart = true;
					}
				}
				for (int j = i; j < i + numDigits; j++) {
					if (!isPart && checkForSymbols(prev.at(j), '.', next.at(j))) {
						isPart = true;
					}
				}
				if (i + numDigits < line.length()) {
					if (!isPart && checkForSymbols(prev.at(i + numDigits), line.at(i + numDigits), next.at(i + numDigits))) {
						isPart = true;
					}
				}
				if (isPart) {
					printf("WOW, it's a part~\n");
					total += value;
				}
				i += numDigits;
			}
		}
		prev = line;
		line = next;
	}
	printf("The total is %i \n", total);
}

int dayThree() {
	std::ifstream input;
	string filename = "day3_input.txt";
	if (!loadInput(&input, filename)) {
		printf("Error, file %s not found. Exiting.", filename);
	}
	day3part1(&input);
	return 1;
}

