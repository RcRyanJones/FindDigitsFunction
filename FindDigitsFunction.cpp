
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
//Dean Alvarez and Ryan Jones

std::string findTheDigits(std::string x, std::string y) {
	//Ordered map of x
	map<char, int> digitsX;
	for (char c : x) {
		//If the current char is already a key, increments the value of the key
		if (!digitsX.empty() && digitsX.find(c) != digitsX.end()) {
			digitsX[c]++;
		}
		else {
			digitsX[c] = 1;
		}
	}

	//Ordered map of Y
	map<char, int> digitsY;
	for (char c : y) {
		//If the current char is already a key, increments the value of the key
		if (!digitsY.empty() && digitsY.find(c) != digitsY.end()) {
			digitsY[c]++;
		}
		else {
			digitsY[c] = 1;
		}
	}

	map<char, int> ::iterator itX;
	map<char, int> ::iterator itY;

	itX = digitsX.begin();

	string Added = "";
	//Iterates through Y (always bigger or same size as x)
	for (itY = digitsY.begin(); itY != digitsY.end(); itY++) {
		//If X still has keys to iterate through checks them
		if (itX != digitsX.end()) {
			//If current y not in x adds y based on it's value
			if (itY->first != itX->first) {
				for (int i = 0; i < itY->second; i++) {
					Added += itY->first;
				}
			}
			//If current y in x adds y based on much bigger it's value is than x's
			else {
				for (int i = itX->second; i < itY->second; i++) {
					Added += itY->first;
				}
				//only increments x when x and y at same key
				itX++;
			}
		}
		//If done iterating through x then adds remaining y's
		else {
			for (int i = 0; i < itY->second; i++) {
				Added += itY->first;
			}
		}
	}

	return Added;
}