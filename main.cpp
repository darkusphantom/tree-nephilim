#include <iostream>
#include <string>
#include "ArbolBinario.h"
#include "File.h"
#include "ListPlus.h"

using namespace std;

string nodeInitial, nodeEnding;

template <typename T>
void getDataInitialAndEnd(list<T> &linkedList) {
  int amountChar;
  string dataPerson;
  string delimiter= "-";
  string dataInitialAndEnd[1];

  string words;
  words = linkedList.front();
  linkedList.pop_front();

  int iteratorMaxPerson=0;
  while (((amountChar = words.find(delimiter)) != string::npos) && iteratorMaxPerson < 2) {
    dataPerson = words.substr(0, amountChar+2);
    words.erase(0, amountChar + delimiter.length() + 2);

    dataInitialAndEnd[iteratorMaxPerson] = dataPerson;
    iteratorMaxPerson++;
  }

  nodeInitial = dataInitialAndEnd[0];
  nodeEnding = dataInitialAndEnd[1];
}

int main() {
  list<string> dataList;
  readFileToSaveOnList(dataList);

  int numberTestCase;
  numberTestCase = stoi(dataList.front());
  dataList.pop_front();

  getDataInitialAndEnd(dataList);

  return 0;
}

// ArbolBinario<string> *humanTree = new ArbolBinario<string>;