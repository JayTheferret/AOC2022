#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string file_to_string(string filename) {

	ifstream input(filename);

	if (!input.is_open()) {
		cout << "Couldn't open/find file " << filename << endl;
	}

	string in_str;

	ostringstream ss;
	ss << input.rdbuf();
	in_str = ss.str();

	//cout << num;
	return in_str;
}

void star_one() {
	//string input = file_to_string("D2E.txt");
	string input = file_to_string("D2.txt");
	//cout << input;

	//a rock x -> 1
	//b paper y -> 2
	//c scissors z -> 3

	//0 lost, 3 draw, 6 win

	int score = 0;

	for (int i = 0; i < input.size(); i++) {
		//cout << input[i];

		if (input[i] == 'A') { //enemy chooses rock
			//cout << "a chosen";
			if (input[i + 2] == 'X') {
				score += 3 + 1; //draw + rock
			}
			if (input[i + 2] == 'Y') {
				score += 6 + 2; //win + paper
			}
			if (input[i + 2] == 'Z') {
				score += 0 + 3; //lost + scissors
			}
		}

		if (input[i] == 'B') { //enemy chooses paper
			if (input[i + 2] == 'X') {
				score += 0 + 1; //lost + rock
			}
			if (input[i + 2] == 'Y') {
				score += 3 + 2; //draw + paper
			}
			if (input[i + 2] == 'Z') {
				score += 6 + 3; //win + scissors
			}
		}

		if (input[i] == 'C') { //enemy chooses scissors
			if (input[i + 2] == 'X') {
				score += 6 + 1; //win + rock
			}
			if (input[i + 2] == 'Y') {
				score += 0 + 2; //lost + paper
			}
			if (input[i + 2] == 'Z') {
				score += 3 + 3; //draw + scissors
			}
		}
	}
	std::cout << score << endl;
}

void star_two() {
	//string input = file_to_string("D2E.txt");
	string input = file_to_string("D2.txt");
	//cout << input;

	//a rock  -> 1
	//b paper  -> 2
	//c scissors -> 3

	// x loose
	// Y draw
	// Z win

	//0 lost, 3 draw, 6 win

	int score = 0;

	for (int i = 0; i < input.size(); i++) {
		//cout << input[i];

		if (input[i] == 'A') { //enemy chooses rock
			//cout << "a chosen";
			if (input[i + 2] == 'X') {
				score += 0 + 3; //loose +scissors
			}
			if (input[i + 2] == 'Y') {
				score += 3 + 1; //draw + rock
			}
			if (input[i + 2] == 'Z') {
				score += 6 + 2; //win + paper
			}
		}

		if (input[i] == 'B') { //enemy chooses paper
			if (input[i + 2] == 'X') {
				score += 0 + 1; //loose + rock
			}
			if (input[i + 2] == 'Y') {
				score += 3 + 2; //draw + paper
			}
			if (input[i + 2] == 'Z') {
				score += 6 + 3; //win + scissors
			}
		}

		if (input[i] == 'C') { //enemy chooses scissors
			if (input[i + 2] == 'X') {
				score += 0 + 2; //loose + paper
			}
			if (input[i + 2] == 'Y') {
				score += 3 + 3; //draw + scissors
			}
			if (input[i + 2] == 'Z') {
				score += 6 + 1; //win + rock
			}
		}
	}
	std::cout << score << endl;
}

int main() {

	cout << "Solution for Day 2: " << endl << endl;
	cout << "Star one: ";
	star_one();
	cout << "Star two: ";
	star_two();
}