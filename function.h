#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

#include "Word.h"
#include "HashTable.h"

std::vector <std::string> loadHistoryFile();
void Mainmenu(int type);
void runProgram(int type);
void displayHistory(std::vector<std::string> hisSearch);
void saveHistory(std::vector<std::string> hisSearch);
void MenuEditDict();
void MenuMiniGame();
void MenuFavoriteList();
Word InputnewWord();
void AddnewWord();

// search function
void search (std::string to_search, HashTable t);