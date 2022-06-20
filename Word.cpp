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
    if (Def == 2) return "adv";
    if (Def == 3) return "adj";
    if (Def == 4) return "verb";
    if (Def == 5) return "excl";
    return "emo";
}

int GetDefInt(string Def) {
    if (Def == "noun") return 1;
    if (Def == "adv") return 2;
    if (Def == "adj") return 3;
    if (Def == "verb") return 4;
    if (Def == "excl") return 5;
    return 6;
}

void readData(vector<Word> &vietanh, ifstream &fin) {
  while (!fin.eof()) {
    bool flag = false;
    Word toAdd;
    int type_count = 0;
    char prefix;
    string tmp_type;
    pair<int, vector <string> > tmp_typeDefEx;
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
        if (tmp_type == "noun") {
          tmp_typeDefEx.first = 1;
        }
        else if (tmp_type == "adj") {
          tmp_typeDefEx.first = 2;
        }
        else if (tmp_type == "verb") {
          tmp_typeDefEx.first = 3;
        }
        else if (tmp_type == "excl") {
          tmp_typeDefEx.first = 4;
        }
        else if (tmp_type == "tu dem") {
          tmp_typeDefEx.first = 5;
        }
        else if (tmp_type == "pronoun") {
          tmp_typeDefEx.first = 6;
        }
        else if (tmp_type == "adv") {
          tmp_typeDefEx.first = 7;
        }
        else {
          tmp_typeDefEx.first = 0;
        }
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
