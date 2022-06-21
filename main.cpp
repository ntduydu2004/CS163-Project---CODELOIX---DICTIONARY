#include <iostream>
#include <fstream>
#include <Windows.h>


using namespace std;

#include "Word.h"
#include "HashTable.h"


int main() {

    HashTable What(3, 7); //Init(P, N) (P < N, Better if P and N are prime numbers)
    ifstream fi("InputTest.txt");

    fi.close();
    return 0;
}
