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

template <typename T>
void getDataToInsertInTree(list<T> &linkedList, int numberTestCase) {
  string inorden, preorden, postorden;
  string inordenChar="INORDEN", preordenChar="PREORDEN", postordenChar="POSTORDEN";
  list<T> list1, list2;

  inorden = inordenChar.length();
  preorden = preordenChar.length();
  postorden = postordenChar.length();

  int iterator=0;
  while(iterator <= numberTestCase) {
    string dataFront = linkedList.front();

    if (iterator == 0) {
      list1.push_back(dataFront);
    }
    else if (iterator == 1) {
      list2.push_back(dataFront);
    } else {
      linkedList.pop_front();
    }
    linkedList.pop_front();
    iterator++;
  }

  // showElementsInList(list1);
  // showElementsInList(list2);
  showElementsInList(linkedList);
}

int main() {
  list<string> dataList;
  readFileToSaveOnList(dataList);

  int numberTestCase;
  numberTestCase = stoi(dataList.front());
  dataList.pop_front();

  getDataInitialAndEnd(dataList);
  getDataToInsertInTree(dataList, numberTestCase);

  return 0;
}

// ArbolBinario<string> *humanTree = new ArbolBinario<string>;