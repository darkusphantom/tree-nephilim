#include <iostream>
#include <string>
#include "ArbolBinario.h"
#include "File.h"
#include "ListPlus.h"

using namespace std;

template <typename T>
void readData(T &data, string info) {
  cout << "Ingrese " << info << " : " << endl;
  cin >> data;
}

void saveDataInList(list<string> &linkedList1, list<string> &linkedList2) {
  string stringToken;

  cout << "Ingrese una lista incluyendo el orden y los nodos de la lista: " << endl;
  getline(cin, stringToken);
  linkedList1.push_back(stringToken);

  cout << "Ingrese una segunda lista incluyendo el orden diferente al anterior y los nodos de la lista: " << endl;
  getline(cin, stringToken);
  linkedList2.push_back(stringToken);

}

void saveData(list<string> &linkedList) {
  int numberTestCase;
  string testCase;

  readData(testCase, "el numero de casos de prueba");
  linkedList.push_back(testCase);

  char testCaseChar;
  testCase[testCase.size()];
  numberTestCase = atoi(testCaseChar);

  // list<string> linkedList1, linkedList2;
  // for (int i = 0; i < 2; ++i) {
  //   string pointInitial, pointEnding;

  //   readData(pointInitial, "el punto de partida del recorrido");
  //   linkedList.push_back(pointInitial);

  //   readData(pointEnding, "el punto de final del recorrido");
  //   linkedList.push_back(pointEnding);

  //   saveDataInList(linkedList1, linkedList2);
  //   linkedList.merge(linkedList1);
  //   linkedList.merge(linkedList2);
  //   linkedList.push_back(" ");
  // }
}

int main() {
  list<string> linkedListFileIn, linkedListFileOut;

  saveData(linkedListFileIn);




  return 0;
}



// string nodeInitial, nodeEnding;
// list<string> linkedFinal;

// template <typename T>
// void getDataInitialAndEnd(list<T> &linkedList) {
//   int amountChar;
//   string dataPerson;
//   string delimiter= "-";
//   string dataInitialAndEnd[1];

//   string words;
//   words = linkedList.front();
//   linkedList.pop_front();

//   int iteratorMaxPerson=0;
//   while (((amountChar = words.find(delimiter)) != string::npos) && iteratorMaxPerson < 2) {
//     dataPerson = words.substr(0, amountChar+2);
//     words.erase(0, amountChar + delimiter.length() + 2);

//     dataInitialAndEnd[iteratorMaxPerson] = dataPerson;
//     iteratorMaxPerson++;
//   }

//   nodeInitial = dataInitialAndEnd[0];
//   nodeEnding = dataInitialAndEnd[1];
// }

// template <typename T>
// void setTree(list<T> &linkedList1, list<T> &linkedList2) {
//   ArbolBinario<string> *humanTree = new ArbolBinario<string>;
//   list<string> lista;

//   showElementsInList(linkedList1);

//   humanTree->preordenInorden(linkedList1, linkedList2);

//   cout << humanTree->peso() << endl;
// }


// template <typename T>
// void getDataToInsertInTree(list<T> &linkedList, int numberTestCase) {
//   string inorden, preorden, postorden;
//   string inordenChar="INORDEN", preordenChar="PREORDEN", postordenChar="POSTORDEN";
//   list<T> list1, list2;

//   inorden = inordenChar.length();
//   preorden = preordenChar.length();
//   postorden = postordenChar.length();

//   for (int iterator = 0; iterator < linkedList.size(); ++iterator) {
//     string dataFront = linkedList.front();

//     if (iterator == 0) {
//       list1.push_back(dataFront);
//     }
//     else if (iterator == 1) {
//       list2.push_back(dataFront);
//     } else {
//       linkedList.pop_front();
//     }
//     linkedList.pop_front();
//   }

//   setTree(list1, list2);
// }



// int main() {
//   list<string> dataList;
//   readFileToSaveOnList(dataList);

//   int numberTestCase;
//   numberTestCase = stoi(dataList.front());
//   dataList.pop_front();

//   getDataInitialAndEnd(dataList);
//   getDataToInsertInTree(dataList, numberTestCase);

//   return 0;
// }