#ifndef ListPlus_h
#define ListPlus_h

#include <iostream>
#include <string>
#include <list>

using namespace std;

template<typename T>
void showElementsInList(list<T> &linkedList) {
	cout << "--------- List -----------" << endl;
	for (const auto &node : linkedList) {
		cout << "Node: " << node << endl;
	}
}

string convertToUpper(string word) {
	string convertWord;
	convertWord = word;

	for (int i = 0; i < word.length(); ++i) {
		convertWord[i] = toupper(word[i]);
	}

	return convertWord;
}

#endif