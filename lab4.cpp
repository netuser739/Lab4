#include <iostream>
#include <fstream>
using namespace std;

struct FlightInfo {
	int hours;
	int minuts;
	string mark;
	string boardingNumber;
	string flightPunkt;

	FlightInfo() = default;
};

FlightInfo* load(const char* fileName) {
	ifstream fin(fileName);
	int numb;
	fin >> numb;
	FlightInfo *flight = new FlightInfo[numb];
	for (int i = 0; i < numb; i++) {
		fin >> flight[i].hours;
		fin >> flight[i].minuts;
		fin >> flight[i].mark;
		fin >> flight[i].boardingNumber;
		fin >> flight[i].flightPunkt;
	}
	fin.close();
	return flight;
}

int main()
{
	setlocale(LC_ALL, "ru");
	const char* fileName = "test.txt";
	FlightInfo *flight = load(fileName);
	for(int i = 0; i < 3; i++)
	{
		cout << i << "\t" << flight[i].hours << ':' << flight[i].minuts << "\t" << flight[i].mark << "\t" << flight[i].boardingNumber << "\t" << flight[i].flightPunkt << endl;
	}
}

