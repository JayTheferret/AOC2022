#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
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

void star_one(){

	//cout << file_to_string("D1S1E.txt");
	string cal = file_to_string("D1S1.txt");

	string num;
	int num_tmp = 0; //saves for addition
	int m_cal = 0;

	for (int i = 0; i < cal.size(); i++) {
		num.push_back(cal[i]);
		//cout << cal[i] ;
		if (cal[i] == '\n') { //num finished
			num_tmp += atoi(num.c_str()); //string zu int...
			num = "0";

			if (num_tmp >= m_cal) {
				m_cal = num_tmp;
			}
			if (cal[i + 1] == '\n') { //if empty row follows
				num_tmp = 0;
			}
		}
	}
	cout << "Max Calories: " << m_cal << endl;
}

void star_two(){}

int main() {

	cout << "Solution for Day 1: " << endl << endl;
	cout << "Star one: ";
	star_one();
	cout << "Star two: ";
	star_two();
	
}

