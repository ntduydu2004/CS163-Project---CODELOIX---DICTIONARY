#pragma once

#include <iostream>
#include <vector>
#include <fstream>

typedef std::vector <std::string> VecString;
typedef std::pair <int, VecString > IntVecString;

struct Int_VS_VS {
    int Type;
    VecString Trans;// 1 type contains many trans
    std::vector<VecString> Exam; // 1 trans contains many examples
};

struct Word
{
    std::string Key = "";
    std::vector <Int_VS_VS> typeDefEx;

    //Word(std::string &s);
    ~Word();

    void AddType(int Type);
    void AddEx(int Type, int Trans, std::string &Ex);
    void AddTrans(int Type, std::string &Trans);

    void ShowData(int level, std::vector <std::string> &GetDef);
};

std::string GetTypeString(int Type, VecString &GetType) ;
int GetTypeInt(std::string Def, VecString &GetDef) ;
void readData(std::vector<Word> &vietanh, std::ifstream &fin, std::vector <std::string> &GetDef);
void AddDef(std::string &Def, std::vector <std::string> &GetDef);
extern VecString GetType;
