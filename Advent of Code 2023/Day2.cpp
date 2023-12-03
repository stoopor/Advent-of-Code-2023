#include "Day2.h"

int dayTwo() {
	string filename = "day2_input.txt";
	std::ifstream input;
	if (!loadInput(&input, filename)) {
		printf("Error, file %s not found. Exiting.", filename);
	}
	day2part2(&input);
	return 1;
}

using std::string;

int day2part1(std::ifstream *input) {
	int total = 0;
	int maxRed = 12;
	int maxGreen = 13;
	int maxBlue = 14;
	int totalGames = 0;
	while (!input->eof()) {
		string line;
		getline(*input, line);
		if (line.empty()) break;
		totalGames++;
		int colonPos = line.find(":");
		int gameNumber = std::stoi(line.substr(5, colonPos - 5));
		printf("Game : %i \n",gameNumber);
		
		line = line.substr(colonPos + 2, line.length() - colonPos + 2);
		//int length =
		bool gameOver = false;
		bool impossible = false;
		while (!gameOver) {
			int semicolonPos = line.find(";");
			string currentDraw;
			if (semicolonPos == string::npos) {
				gameOver = true;
				currentDraw = line;
			}
			else {
				currentDraw = line.substr(0, semicolonPos);
				line = line.substr(semicolonPos + 2, line.length() - semicolonPos + 2);
			}
			bool countOver = false;
			while (!countOver) {
				int space = currentDraw.find(" ");
				int value = std::stoi(currentDraw.substr(0, space));
				int nextDrawPos = -1;
				switch (currentDraw.at(space + 1)) {
					case 'r':
						nextDrawPos = space + 6;
						if (value > maxRed) {
							gameOver = true;
							countOver = true;
							impossible = true;
						}
						break;
					case 'g':
						nextDrawPos = space + 8;
						if (value > maxGreen) {
							gameOver = true;
							countOver = true;
							impossible = true;
						}
						break;
					case 'b':
						nextDrawPos = space + 7;
						if (value > maxBlue) {
							gameOver = true;
							countOver = true;		
							impossible = true;
						}
						break;
					default:
						break;
				}
				if (nextDrawPos > currentDraw.length()) {
					countOver = true;
				}
				else {
					currentDraw = currentDraw.substr(nextDrawPos, currentDraw.length() - nextDrawPos);
				}
			}
			
		}
		if (!impossible) total += gameNumber;

	}
	printf("The total of the indices of valiable games is %i \n", total);
	return 1;
}

int day2part2(std::ifstream* input) {
	int total = 0;
	while (!input->eof()) {
		string line;
		int lowestRed = 0;
		int lowestGreen = 0;
		int lowestBlue = 0;
		getline(*input, line);
		if (line.empty()) break;
		int colonPos = line.find(":");
		int gameNumber = std::stoi(line.substr(5, colonPos - 5));

		line = line.substr(colonPos + 2, line.length() - colonPos + 2);
		bool gameOver = false;
		while (!gameOver) {
			int semicolonPos = line.find(";");
			string currentDraw;
			if (semicolonPos == string::npos) {
				gameOver = true;
				currentDraw = line;
			}
			else {
				currentDraw = line.substr(0, semicolonPos);
				line = line.substr(semicolonPos + 2, line.length() - semicolonPos + 2);
			}
			bool countOver = false;
			while (!countOver) {
				int space = currentDraw.find(" ");
				int value = std::stoi(currentDraw.substr(0, space));
				int nextDrawPos = -1;
				switch (currentDraw.at(space + 1)) {
					case 'r':
						nextDrawPos = space + 6;
						if (lowestRed == 0 || value > lowestRed) {
							lowestRed = value;
						}
						break;
					case 'g':
						nextDrawPos = space + 8;
						if (lowestGreen == 0 || value > lowestGreen) {
							lowestGreen = value;
						}
						break;
					case 'b':
						nextDrawPos = space + 7;
						if (lowestBlue == 0 || value > lowestBlue) {
							lowestBlue = value;
						}
						break;
					default:
						break;
				}
				if (nextDrawPos > currentDraw.length()) {
					countOver = true;
				}
				else {
					currentDraw = currentDraw.substr(nextDrawPos, currentDraw.length() - nextDrawPos);
				}
			}
		}
		
		total += lowestRed * lowestGreen * lowestBlue;
	}
	printf("The total of every power of the minimum set of cubes is %i \n", total);
	return 1;
}