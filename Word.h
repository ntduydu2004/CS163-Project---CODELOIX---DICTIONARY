#pragma once

#include <iostream>
#include <vector>
#include <fstream>

typedef std::vector <std::string> VecString;
typedef std::pair <int, VecString > IntVecString;

struct Word
{
    std::string Key = "";
    std::vector <IntVecString> typeDefEx;
    VecString trans;

    //Word(std::string &s);
    ~Word();

    void AddDef(int Def);
    void AddEx(int Def, std::string &Ex);
    void AddTrans(std::string &Trans);

    void ShowData(int level);
};

std::string GetDefString(int Def);
int GetDefInt(std::string Def);
void readData(std::vector<Word> &vietanh, std::ifstream &fin);