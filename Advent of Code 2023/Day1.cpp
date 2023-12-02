#include "Day1.h"


int dayOne() {
	string filename = "day1_test.txt";
	ifstream input;
	if (!loadInput(&input, filename)) {
		printf("Error, file %s not found. Exiting.", filename);
	}
	// call partOne to get that answer.
	partTwo(&input);
	return 1;
}

void partOne(ifstream input) {
	int total = 0;
	while (!input.eof()) {
		char first, last;
		string line;
		getline(input, line);
		if (line.empty()) continue;
		for (int i = 0; i < line.length(); i++) {
			char cur = line.at(i);
			if (cur >= '0' && cur <= '9') {
				first = cur;
				break;
			}
		}
		for (int i = line.length() - 1; i >= 0; i--) {
			char cur = line.at(i);
			if (cur >= '0' && cur <= '9') {
				last = cur;
				break;
			}

		}
		int value = (first - 48) * 10 + (last - 48);
		total += value;
	}
	printf("The total is %i", total);
}

bool checkKeyword(string line, int start, string keyword, int * first, int * last, int value) {
	if (start + keyword.length() - 2 > line.length()) return false;
	string sub = line.substr(start , keyword.length());
	if (sub == keyword) {
		//printf("Keyword found: %i \n", value);
		if (*first == -1) *first = value;
		*last = value;
	}
}

int partTwo(ifstream * input) {
	int total = 0;
	while (!input->eof()) {
		string line;
		int first = -1;
		int last = -1;
		getline(*input, line);
		if (line.empty()) break;
		for (int i = 0; i < line.length(); i++) {
			int len = line.length();
			char cur = line.at(i);
			switch (cur) {
				case 'o': checkKeyword(line, i + 1, "ne", &first, &last, 1);
					break;
				case 't': 
					if (len - 1 - i > 0 && line.at(i + 1) == 'w') {
						checkKeyword(line, i + 1, "wo", &first, &last, 2);
					}
					else {
						checkKeyword(line, i + 1, "hree", &first, &last, 3);
					}
					break;
				case 'f':
					if (len - 1 - i > 0 && line.at(i + 1) == 'o') {
						checkKeyword(line, i + 1, "our", &first, &last, 4);
					}
					else {
						checkKeyword(line, i + 1, "ive", &first, &last, 5);
					}
					break;
				case 's':
					if (len - 1 - i > 0 && line.at(i + 1) == 'i') {
						checkKeyword(line, i + 1, "ix", &first, &last, 6);
					}
					else {
						checkKeyword(line, i + 1, "even", &first, &last, 7);
					}
					break;
				case 'e':
					checkKeyword(line, i + 1, "ight", &first, &last, 8);
					break;
				case 'n':
					checkKeyword(line, i + 1, "ine", &first, &last, 9);
					break;
				default:
					if (cur >= '0' && cur <= '9') {
						if (first == -1) first = cur - 48;
						last = cur - 48;
					}
				
			}
		}
		int value = first * 10 + last;
		total += value;
	}
	printf("The total is %i. \n", total);
	return 1;
}