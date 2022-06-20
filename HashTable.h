#pragma once

#include <iostream>
#include "Word.h"

struct HashNode {
    Word data;
    HashNode* pNext = nullptr;

    HashNode (std::string &_data);
};

struct HashLinkedList {
    HashNode* pHead = nullptr;
    HashNode* pTail = nullptr;
};

struct HashTable {
    int P, N;
    HashLinkedList *List;

    HashTable(int _P, int _N);
    ~HashTable();

    int GetHash(std::string &s);
    void InsertNewWord(std::string &s);

    void displayChain();
    void DeleteWord(std::string &s);
    HashNode* FindWord(std::string &s);
};
