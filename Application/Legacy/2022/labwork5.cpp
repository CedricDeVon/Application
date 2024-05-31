#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

struct student
{
	string studentName;
	double score;
};

void readFromRecord(student studScoreRec[]);
double recAverage(student studScoreRec[], int s);
double recSTDev(student studScoreRec[], int s);
void writeResultToFile(double ave, double stDev);

void readFromRecord(student studScoreRec[])
{
	ifstream file;
	file.open("StudentScore.txt");
	if (!file.is_open())
	{
		cout << "'StudentScore.txt' is currently not open at this moment" << '\n';
	}

	int index = 0;
	while (!file.eof())
	{
		getline(file, studScoreRec[index].studentName, '\t');
		file >> studScoreRec[index].score;
		string newLineRemover;
		getline(file, newLineRemover, '\n');
		index += 1;
	}
	file.close();
}

double recAverage(student studScoreRec[], int s)
{
	double ave = 0;
	for (int index = 0; index < s; index += 1)
	{
		ave += studScoreRec[index].score;
	}

	return ave / s;
}

double recSTDev(student studScoreRec[], int s)
{
	double stDev = 0;
	double ave = recAverage(studScoreRec, s);
	for (int index = 0; index < s; index += 1)
	{
		stDev += pow(studScoreRec[index].score - ave, 2);
	}

	return sqrt(stDev / (s - 1));
}

void writeResultToFile(double ave, double stDev)
{
	ofstream file;
	file.open("scoreDescStat.txt");
	if (!file.is_open())
	{
		cout << "'scoreDescStat.txt' is currently not open at this moment" << '\n';
	}

	file << "ave: " << '\t' << ave << '\n';
	file << "stDev: " << '\t' << stDev << '\n';
	file.close();
}

int main()
{
	student studScoreRec[7];
	int s = sizeof(studScoreRec) / sizeof(studScoreRec[0]);
	readFromRecord(studScoreRec);
	double ave = recAverage(studScoreRec, s);
	double stDev = recSTDev(studScoreRec, s);
	writeResultToFile(ave, stDev);

	return 0;
}
