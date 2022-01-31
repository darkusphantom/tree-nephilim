#ifndef File_h
#define File_h

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

int readFileToSaveOnList(list<string> &linkedList) {
	fstream myFile;
	string  lineSurfing;

	myFile.open("input.txt", ios::in);
	if(!myFile.is_open()){
		cout << "Hubo un error al leer el archivo \"input.txt\". Verifique si existe." << endl;
		return 1;
	}

	cout << "Leyendo archivo..." << endl;

	while(getline(myFile,lineSurfing)){
		linkedList.push_back(lineSurfing);
	}

	cout << "Archivo leido...\n" << endl;

	myFile.close();
	return (0);
}

#endif