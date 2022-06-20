#include "HashTable.h"

#include <iostream>

#include <vector>
#include <string>

using namespace std;

HashNode::HashNode(string &_data) {
    data = _data;
}

HashTable::HashTable(int _P, int _N) {
    P = _P;
    N = _N;
    List = new HashLinkedList [N];
}

HashTable::~HashTable() {
    for (int i = 0; i < N; i++) {
        HashNode *pD = nullptr;
        List[i].pTail = nullptr;
        while (List[i].pHead) {
            pD = List[i].pHead;
            List[i].pHead = List[i].pHead->pNext;
            delete pD;
            pD = nullptr;
        }
    }

    delete [] List;
}

int HashTable::GetHash(string &s) {

    int res = 0, p = P;
    for (char &c: s) {
        res = (res + c * p) % N;
        p = (p * P) % N;
    }
    return res;
}

void HashTable::insertBucket(string &s) {
    int location = GetHash(s);
    if (List[location].pHead == nullptr) {
        HashNode* temp = new HashNode(s);
        List[location].pHead = List[location].pTail = temp;
    }
    else {
        HashNode* temp = new HashNode(s);
        List[location].pTail->pNext = temp;
        List[location].pTail = List[location].pTail->pNext;
    }
}

void HashTable::displayChain() {
    for (int i = 0; i < N; ++i) {
        cout << "Key" << " " << i << " :";
        if (List[i].pHead != nullptr) {
            HashNode* current = List[i].pHead;
            while (current != nullptr) {
                cout << current->data << "      ";
                current = current->pNext;
            }
        }
        cout << '\n';
    }
}

void HashTable::deleteBucket(string &s) {
    int location = GetHash(s);
    if (List[location].pHead == nullptr) return;

    if (List[location].pHead->data == s) {
        HashNode* pD = List[location].pHead;
        if (List[location].pTail->data == s) List[location].pTail = nullptr;
        List[location].pHead = List[location].pHead->pNext;
        delete pD;
        pD = nullptr;
    }
    else {
        HashNode* Cur = List[location].pHead;
        while (Cur->pNext) {

            if (Cur->pNext->data == s) {
                HashNode* pD = Cur->pNext;
                if (Cur->pNext == List[location].pTail) List[location].pTail = Cur;
                Cur->pNext = Cur->pNext->pNext;
                delete pD;
                pD = nullptr;
                return;
            }

            Cur = Cur->pNext;
        }
    }

}

HashNode* HashTable::FindWord(string &s) {
    int HashKey = GetHash(s);

    HashNode* Cur = List[HashKey].pHead;

    while (Cur) {
        if (Cur->data == s) return Cur;
        Cur = Cur->pNext;
    }

    return nullptr;
}
