#include <string>

using namespace std;

string toString(long long int value, int emptyDigitCount = 1)
{
	string reversedOutput = "";
	int digitCount = 0;
	while (value > 0)
	{
		reversedOutput += (value % 10) + 48;
		digitCount += 1;
		value /= 10;
	}
	if (digitCount < emptyDigitCount)
	{
		while (digitCount < emptyDigitCount)
		{
			reversedOutput += '0';
			digitCount += 1;
		}
	}

	string finalOutput = "";
	for (int currentIndex = reversedOutput.size() - 1; currentIndex >= 0; currentIndex -= 1)
	{
		finalOutput += reversedOutput[currentIndex];
	}

	return finalOutput;
}

string millisecondsToTimeString(long long int milliseconds)
{
	long long int totalSeconds = milliseconds / 1000;
	long long int totalMinutes = totalSeconds / 60;
	long long int totalHours = totalMinutes / 60;
	long long int totalDays = totalHours / 24;
	long long int totalYears = totalDays / 365;

	return toString(totalYears) + ":" +
		toString(totalDays % 365, 3) + ":" +
		toString(totalHours % 24, 2) + ":" + 
		toString(totalMinutes % 60, 2) + ":" + 
		toString(totalSeconds % 60, 2) + ":" + 
		toString(milliseconds % 1000, 3);
}


