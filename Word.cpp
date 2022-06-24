#include "Word.h"
#include "Const.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//Constructor and Destructor

/*Word::Word(string &s) {
    Key = s;
}*/

#define F Type
#define S Exam
#define T Trans

Word::~Word() {
    for (Int_VS_VS &c: typeDefEx) {
        c.S.clear();
        c.T.clear();
    }
    typeDefEx.clear();
}

//Inner Functionsssssssssssssssssssssssssssssssssssssss

void Word::AddType(int Type) {
    for (Int_VS_VS &c: typeDefEx)
        if (c.Type == Type) return;
    VecString _Trans;
    vector <VecString> _Exams;
    typeDefEx.push_back({Type, _Trans, _Exams});
}

void Word::AddEx(int Type, int Trans, string &Ex) {// Trans index tu 1 den n
    for (Int_VS_VS &c: typeDefEx) {
        if (c.F == Type) {
            c.S[Trans - 1].push_back(Ex);
            return;
        }
    }
}

void Word::AddTrans(int Type, string &_Trans) {
    for (Int_VS_VS &c: typeDefEx) {
        if (c.F == Type) {
            c.T.push_back(_Trans);
            c.S.resize(c.S.size() + 1);
            return;
        }
    }
}

void Word::ShowData(int level, VecString &GetType) {
    if (level >= 1) cout << Key << "\n";
    if (level >= 2) {
        for (Int_VS_VS &c: typeDefEx) {
            cout << "* " + GetTypeString(c.F, GetType) + '\n';
            for (int i = 0; i < c.T.size() - 1; i++){
                cout << " - " << c.T[i] <<  endl;
                if (!c.S[i].empty()){
                    cout << " Example:" << endl;
                    for (int j = 0; j < c.S[i].size(); j++){
                        cout << "  +" << c.S[i][j] << endl;
                    }
                }
            }
        }
    }
}

//Outer Functionsssssssssssssssssssssssssssssssssssssss

string GetTypeString(int Type, VecString &GetType) {
    if (Type >= int(GetType.size())) return "unknown";
    return GetType[Type];
}

int GetTypeInt(string Def, VecString &GetDef) {
    for (int i = 0; i < int(GetDef.size()); i++)
            if (Def == GetDef[i]) return i;
    return oo;
}

void readData(vector <Word> &vietanh, ifstream &fin, VecString &GetDef) {
    while (!fin.eof()) {
        bool flag = false;
        Word toAdd;
        int type_count = 0;
        char prefix;
        string tmp_type;
        Int_VS_VS tmp_typeDefEx;
        while (fin >> prefix) {
          if (prefix == '@') {
            if (flag) {
              toAdd.typeDefEx.push_back(tmp_typeDefEx);
              vietanh.push_back(toAdd);
              type_count = 0;
              tmp_typeDefEx.Type = 0;
              tmp_typeDefEx.Exam.clear();
              tmp_typeDefEx.Trans.clear();
              toAdd.typeDefEx.clear();
            }
            else {
              flag = true;
            }
            getline(fin, toAdd.Key, '\n');
          }
          else if (prefix == '*') {
            if (type_count > 0) {
              toAdd.typeDefEx.push_back(tmp_typeDefEx);
              tmp_typeDefEx.Exam.clear();
              tmp_typeDefEx.Trans.clear();
            }

            getline(fin, tmp_type, '\n');
            tmp_typeDefEx.Type = GetTypeInt(tmp_type, GetDef);
            ++type_count;
          }
          else if (prefix == '-') {
            string tmp_trans;
            getline(fin, tmp_trans, '\n');
            tmp_typeDefEx.Trans.push_back(tmp_trans);
            tmp_typeDefEx.Exam.resize(tmp_typeDefEx.Exam.size() + 1);
          }
          else if (prefix == '=') {
            string tmp_ex;
            getline(fin, tmp_ex, '\n');
            if (tmp_ex.find("+") != string::npos) {
                stringstream ss(tmp_ex);
                getline(ss, tmp_ex, '+');
                tmp_typeDefEx.Exam.back().push_back(tmp_ex);
                getline(ss, tmp_ex, '\n' );
                tmp_typeDefEx.Exam.back().push_back(tmp_ex);
            }
            else {
                tmp_typeDefEx.Exam.back().push_back(tmp_ex);
            }
          }
        }
        toAdd.typeDefEx.push_back(tmp_typeDefEx);
        vietanh.push_back(toAdd);
    }
}


void AddDef(string &Def, VecString &GetDef) {
    if (GetDefInt(Def, GetDef) == oo) GetDef.push_back(Def);
}
