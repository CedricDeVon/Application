#pragma once

#include <iostream>
#include <string>

using namespace std;

void programTerminationHandler()
{
	string input = "";
	cout << "\nEnter any key to terminate the program..." << '\n';
	cin >> input;
}
