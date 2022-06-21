#include "Word.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Constructor and Destructor

/*Word::Word(string &s) {
    Key = s;
}*/

#define F first
#define S second

Word::~Word() {
    for (IntVecString &c: typeDefEx) {
        c.S.clear();
    }
    typeDefEx.clear();
    trans.clear();
}

//Inner Functionsssssssssssssssssssssssssssssssssssssss

void Word::AddDef(int Def) {
    VecString vs;
    typeDefEx.push_back({Def, vs});
}

void Word::AddEx(int Def, string &Ex) {
    for (IntVecString &c: typeDefEx) {
        if (c.F == Def) {
            c.S.push_back(Ex);
            return;
        }
    }
}

void Word::AddTrans(string &Trans) {
    trans.push_back(Trans);
}

void Word::ShowData(int level) {
    if (level < 1) cout << Key << "\n";
    if (level < 2) {
        for (IntVecString &c: typeDefEx) {
            cout << "* " + GetDefString(c.F) + '\n';
            for (string &s: c.S) cout << " - " + s + '\n';
        }
    }
    if (level < 3)
        for (string &s: trans) cout << " " + s + ((s != trans.back()) ? "," : "\n");
}

//Outer Functionsssssssssssssssssssssssssssssssssssssss

string GetDefString(int Def) {
    if (Def == 1) return "noun";
    if (Def == 2) return "adj";
    if (Def == 3) return "verb";
    if (Def == 4) return "excl";
    if (Def == 5) return "tu dem";
    if (Def == 6) return "pronoun";
    if (Def == 7) return "adv";
    if (Def == 8) return "emo";
    return "unkn";
}

int GetDefInt(string Def) {
    if (Def == "noun") return 1;
    if (Def == "adj") return 2;
    if (Def == "verb") return 3;
    if (Def == "excl") return 4;
    if (Def == "tu dem") return 5;
    if (Def == "pronoun") return 6;
    if (Def == "adv") return 7;
    if (Def == "emo") return 8;
    return 0;
}

void readData(vector<Word> &vietanh, ifstream &fin) {
    while (!fin.eof()) {
        bool flag = false;
        Word toAdd;
        int type_count = 0;
        char prefix;
        string tmp_type;
        IntVecString tmp_typeDefEx;
        while (fin >> prefix) {
          if (prefix == '@') {
            if (flag) {
              toAdd.typeDefEx.push_back(tmp_typeDefEx);
              vietanh.push_back(toAdd);
              type_count = 0;
              tmp_typeDefEx.first = 0;
              tmp_typeDefEx.second.clear();
              toAdd.typeDefEx.clear();
              toAdd.trans.clear();
            }
            else {
              flag = true;
            }
            getline(fin, toAdd.Key, '\n');
          }
          else if (prefix == '*') {
            ++type_count;
            if (type_count > 1) {
              toAdd.typeDefEx.push_back(tmp_typeDefEx);
              tmp_typeDefEx.second.clear();
            }

            getline(fin, tmp_type, '\n');
            tmp_typeDefEx.first = GetDefInt(tmp_type);
          }
          else if (prefix == '-') {
            string tmp_trans;
            getline(fin, tmp_trans, '\n');
            toAdd.trans.push_back(tmp_trans);
          }
          else if (prefix == '=') {
            string tmp_ex;
            getline(fin, tmp_ex, '+');
            tmp_typeDefEx.second.push_back(tmp_ex);
            getline(fin, tmp_ex, '\n');
            tmp_typeDefEx.second.push_back(tmp_ex);
          }
        }
        toAdd.typeDefEx.push_back(tmp_typeDefEx);
        vietanh.push_back(toAdd);
    }
}
