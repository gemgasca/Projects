#include "rpn.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	//string test[] = {"2", "12", "6", "-", "/", "5", "3", "+", "*"};
	// string test[] = {"10", "2", "*", "6", "3", "-", "4", "2", "**", "*","+", "4", "3", "/",">", "+"};
	// int n = 9;
	
	// get length of array from input
	int n;
	cout << "ENTER N, length of string array: \n> ";
	cin >> n; 

	// initialize array of size n
	string test[n]; 

	// get each value of array one by one until user inputs done, push all values into array
	cout << "ENTER string array, each value one line at a time." << endl;
	string in; 
	int i = 0;
	while (i < n){
		cout << "> ";
		cin >> in; 
		if (in == "done"){
			break;
		}
		// add string to test array
		test[i] = in;
		i++;
	}

	bool l;
	string yn;
	cout << "ENTER 'y' for -l, ENTER 'n' for no. \n> ";
	cin >> yn; 
	if (yn == "y"){
		l = true; 
	}
	else if (yn == "n"){
		l = false; 
	}
	else{
		cout << "Not a valid response, exiting" << endl;
		exit(0);
	}

	double result = rpn(test, n, l);
	cout << "Result: " << result << endl;
}