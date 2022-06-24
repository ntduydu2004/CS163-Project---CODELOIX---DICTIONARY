#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Word.h"
std::vector <std::string> loadHistoryFile();
void Mainmenu(int type);
void runProgram(int type);
void displayHistory(vector<string> hisSearch);
void saveHistory(vector<string> hisSearch);
void MenuEditDict();
void MenuMiniGame();
void MenuFavoriteList();
Word InputnewWord();
void AddnewWord();