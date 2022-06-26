#include <iostream>
#include <fstream>
#include <Windows.h>


using namespace std;

#include "Word.h"
#include "HashTable.h"
#include "function.h"
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //HashTable VietAnh(31, 14027, GetDefVA); //Init(P, N) (P < N, Better if P and N are prime numbers)

    string VietAnhFilePath = "Data/";
    string VietAnhFileName = "vietanh.txt";

    string VietAnhFile = VietAnhFilePath + VietAnhFileName;

    HashTable VietAnh(31, 14067);
    VietAnh.FileInput(VietAnhFile);


    //VietAnh.ShowAllWord();
    runProgram(1);
    
    string word;
    while (getline(cin, word) && word != "stop") {
        //cin.ignore();
        search(word, VietAnh);
    }

    /*string AnhVietFilePath = "Data/";
    string AnhVietFileName = "AVdata.txt";

    string AnhVietFile = AnhVietFilePath + AnhVietFileName;

    HashTable AnhViet(3, 7);
    AnhViet.FileInput(AnhVietFile);
    AnhViet.ShowAllWord();*/
    return 0;
}
