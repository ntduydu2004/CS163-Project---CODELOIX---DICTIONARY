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
