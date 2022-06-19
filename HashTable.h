#pragma once

#include <iostream>

struct HashNode {
    std::string data;
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
    void insertBucket(std::string &s);
    void displayChain();
    void deleteBucket(std::string &s);
    HashNode* FindWord(std::string &s);
};
