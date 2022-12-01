#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
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
			
			if (cal[i + 1] == '\n') { //if empty row follows
				if (num_tmp >= m_cal) {
					m_cal = num_tmp;
				}
				num_tmp = 0;
			}
		}
	}
	cout << "Max Calories: " << m_cal << endl;
}


void star_two() {

	//cout << file_to_string("D1S1E.txt");
	string cal = file_to_string("D1S1.txt");

	string num;
	int num_tmp = 0; //saves for addition
	int m_cal = 0;

	vector<int> elves;

	for (int i = 0; i < cal.size(); i++) {
		num.push_back(cal[i]);
		//cout << cal[i] ;
		if (cal[i] == '\n') { //num finished
			num_tmp += atoi(num.c_str()); //string zu int...
			num = "0";

			if (cal[i + 1] == '\n') { //if empty row follows
				//in array einfügen
				elves.push_back(num_tmp);
				num_tmp = 0;
			}
		}
	}
	elves.push_back(atoi(num.c_str())); //manual addition as file doesnt end on \n

	int n = elves.size();

	sort(elves.begin(), elves.end());

	cout << "Max Calories total: " << elves[n-3] + elves[n-1] + elves[n-2];
}

void star_o(){

	string cal = file_to_string("D1S1E.txt");

	string num;
	int num_tmp = 0; //saves for addition

	int m_cal1 = 0; //highest
	int m_cal2 = 0; //second highest
	int m_cal3 = 0;

	for (int i = 0; i < cal.size(); i++) {
		num.push_back(cal[i]);
		//cout << cal[i] ;
		if (cal[i] == '\n') { //num finished
			num_tmp += atoi(num.c_str()); //string zu int...
			num = "0";

			if (cal[i + 1] == '\n') { //if empty row follows

				if (m_cal1 == 0) {
					m_cal1 == num_tmp;
					num_tmp = 0;
				}
				if (m_cal2 == 0) {
					m_cal2 == num_tmp;
					num_tmp = 0;
				}
				if (m_cal3 == 0) {
					m_cal3 == num_tmp;
					num_tmp = 0;
				}

				if (num_tmp >= m_cal1) {
					m_cal1 = num_tmp;
				}
				else if (num_tmp >= m_cal2) {
					m_cal2 = num_tmp;
				}
				else if (num_tmp >= m_cal3) {
					m_cal3 = num_tmp;
				}
				num_tmp = 0;
			}
		}
	}
	cout << "Calories: " << m_cal1+ m_cal2 + m_cal3 << endl;
}

int main() {

	cout << "Solution for Day 1: " << endl << endl;
	cout << "Star one: ";
	star_one();
	cout << "Star two: ";
	star_two();
	
}

