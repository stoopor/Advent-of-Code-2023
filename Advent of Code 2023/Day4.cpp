#include "day4.h"

void day4part1(std::ifstream * input) {
	int total = 0;
	vector<int> winningNums;
	string line;
	while (!input->eof()) {
		getline(*input, line);
		if (line.empty()) break;
		int colonPos = line.find(":");
		int cardNumber = std::stoi(line.substr(4, colonPos - 4));
		int ip = colonPos + 2;
		int numStart = ip;
		char cur = line.at(ip);
		int cardValue = 0;
		while (cur != '|') {
			while (cur == ' ') {
				ip++;
				cur = line.at(ip);
			}
			numStart = ip;
			while (cur != ' ') {
				ip++;
				cur = line.at(ip);
			}
			int num = std::stoi(line.substr(numStart, ip - numStart));
			winningNums.push_back(num);
			ip++;
			cur = line.at(ip);
		}
		ip += 2;
		bool hasMatch = false;
		int matchesOnCard = 0;
		while (ip < line.length()) {
			cur = line.at(ip);
			while (cur == ' ') {
				ip++;
				cur = line.at(ip);
			}
			numStart = ip;
			while (cur != ' ' && ip < line.length() - 1) {
				ip++;
				cur = line.at(ip);
			}
			if (ip == line.length() - 1)ip++;
			int num = std::stoi(line.substr(numStart, ip - numStart));
			for (int i = 0; i < winningNums.size(); i++) {
				if (num == winningNums.at(i)) {
					hasMatch = true;
					matchesOnCard++;
					break;
				}
			}
			ip++;
		}
		if (hasMatch) {
			total += (int)pow(2, matchesOnCard - 1);
		}
		winningNums.clear();
	}
	printf("The total points is: %i\n", total);
}

void day4part2(std::ifstream* input) {
	int total = 0;
	vector<int> winningNums;
	vector<int> numOfMatching;
	vector<int> numOfCopies;
	string line;
	while (!input->eof()) {
		getline(*input, line);
		if (line.empty()) break;
		numOfCopies.push_back(1);
		int colonPos = line.find(":");
		int cardNumber = std::stoi(line.substr(4, colonPos - 4));
		int ip = colonPos + 2;
		int numStart = ip;
		char cur = line.at(ip);
		int cardValue = 0;
		while (cur != '|') {
			while (cur == ' ') {
				ip++;
				cur = line.at(ip);
			}
			numStart = ip;
			while (cur != ' ') {
				ip++;
				cur = line.at(ip);
			}
			int num = std::stoi(line.substr(numStart, ip - numStart));
			winningNums.push_back(num);
			ip++;
			cur = line.at(ip);
		}
		ip += 2;
		bool hasMatch = false;
		int matchesOnCard = 0;
		while (ip < line.length()) {
			cur = line.at(ip);
			while (cur == ' ') {
				ip++;
				cur = line.at(ip);
			}
			numStart = ip;
			while (cur != ' ' && ip < line.length() - 1) {
				ip++;
				cur = line.at(ip);
			}
			if (ip == line.length() - 1)ip++;
			int num = std::stoi(line.substr(numStart, ip - numStart));
			for (int i = 0; i < winningNums.size(); i++) {
				if (num == winningNums.at(i)) {
					hasMatch = true;
					matchesOnCard++;
					break;
				}
			}
			ip++;
		}
		numOfMatching.push_back(matchesOnCard);
		winningNums.clear();
	}
	int totalCopies = 0;
	for (int i = 0; i < numOfMatching.size(); i++) {
		for (int j = 0; j < numOfMatching.at(i); j++) {
			numOfCopies.at(i + j + 1) += numOfCopies.at(i);
		}
		totalCopies += numOfCopies.at(i);
	}
	printf("The total amount of copies is: %i\n", total);
}


void day4() {
	std::ifstream input;
	string filename = "day4_input.txt";
	if (!loadInput(&input, filename)) {
		printf("Error, file %s not found. Exiting.", filename);
	}
	day4part1(&input);
	input.clear();
	input.seekg(0);
	day4part2(&input);

	

}