#include <iostream>
#include <fstream>
#include <Windows.h>


using namespace std;

#include "Word.h"
#include "HashTable.h"


int main() {

    HashTable What(31, 14027); //Init(P, N) (P < N, Better if P and N are prime numbers)

    string FilePath = "Data/";
    string FileName = "vietanh.txt";
    string File = FilePath + FileName;

    What.FileInput(File);

    while (1) {
        string word;
        getline(cin, word);
        if (word == "0") break;
        HashNode* Temp = What.FindWord(word);
        if (Temp == nullptr) {
            cout << "Cannot found " + word + "!\n";
            continue;
        }
        Temp->data.ShowData(3);
        Temp = nullptr;
    }
    return 0;
}
