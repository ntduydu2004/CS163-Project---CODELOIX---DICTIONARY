#include <iostream>
#include <fstream>
#include <Windows.h>


using namespace std;

#include "Word.h"
#include "HashTable.h"


int main() {

    HashTable What(3, 7); //Init(P, N) (P < N, Better if P and N are prime numbers)

    string FilePath = "Data/";
    string FileName = "data.txt";
    string File = FilePath + FileName;

    What.FileInput(File);
    What.ShowAllWord();

    return 0;
}
