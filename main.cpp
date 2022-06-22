#include <iostream>
#include <fstream>
#include <Windows.h>


using namespace std;

#include "Word.h"
#include "HashTable.h"

string GetDefVA[] = {"unk", "noun", "adj", "verb", "excl", "tu dem", "pronoun", "adv", "emo"};
string GetDefAV[] = {"khong xac dinh", "danh tu", "tinh tu", "dong tu", "excl", "tu dem", "dai tu", "trang tu", "bieu cam"};

int main() {

    //HashTable VietAnh(31, 14027, GetDefVA); //Init(P, N) (P < N, Better if P and N are prime numbers)

    string FilePath = "Data/";
    string FileName = "data.txt";

    string File = FilePath + FileName;
    HashTable VietAnh(2, 5, GetDefVA);
    VietAnh.FileInput(File);

    ios_base::sync_with_stdio(0); cin.tie(0);

    VietAnh.ShowAllWord();

    /*while (1) {
        string word;
        getline(cin, word);
        if (word == "0") break;
        HashNode* Temp = VietAnh.FindWord(word);
        if (Temp == nullptr) {
            cout << "Cannot found " + word + "!\n";
            continue;
        }
        Temp->data.ShowData(3, VietAnh.GetDef);
        Temp = nullptr;
    }*/
    return 0;
}
