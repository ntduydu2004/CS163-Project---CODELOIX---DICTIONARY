#include "function.h"

#include "Word.h"
#include "HashTable.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void Mainmenu(int type){
    // type = 1: Anh Viet
    // type = 2: Viet Anh
    // type = 3: Anh Anh
    if (type == 1){
        cout << setw(90) << " " << "The English - Vietnamese Dictionary - Made by CodeLoix Group" << endl;
    }
    else if (type == 2){
        cout << setw(90) << " " << "The Vietnamese - English Dictionary - Made by CodeLoix Group" << endl;
    }
    else{
        cout << setw(90) << " " << "The English Dictionary - Made by CodeLoix Group" << endl;
    }
    cout << setw(105) << " " << "1. Switch Between Dictionaries" << endl;
    cout << setw(105) << " " << "2. Search" << endl;
    cout << setw(105) << " " << "3. Edit Dictionary" << endl;
    cout << setw(105) << " " << "4. View Random Word" << endl;
    cout << setw(105) << " " << "5. Favorite List" << endl;
    cout << setw(105) << " " << "6. Minigame" << endl;
    cout << setw(105) << " " << "7. Exit" << endl;
    cout << setw(105) << " " << "Your choice: ";
}
void runProgram(int type) {
    system("cls");
    int choice, temp;
    Mainmenu(type);
    cin >> choice;
    if (choice == 1) {
        system("cls");
        cout << setw(105) << " " << "1. English to English" << endl;
        cout << setw(105) << " " << "2. English to Vietnamese" << endl;
        cout << setw(105) << " " << "3. Vietnamese to English" << endl;
        cout << setw(105) << " " << "4. Back" << endl;
        cout << setw(105) << " " << "Your choice: ";
        cin >> temp;
        if (temp == 4) runProgram(type);
        else runProgram(temp);
        return;
    }
    else if (choice == 2) {
        system("cls");
        cout << setw(105) << " " << "1. Search by Keyword" << endl;
        cout << setw(105) << " " << "2. Search by Definition" << endl;
        cout << setw(105) << " " << "3. View Search History" << endl;
        cout << setw(105) << " " << "4. Back" << endl;
        cout << setw(105) << " " << "Your choice: ";
        cin >> temp;
        if (temp == 4) {
            runProgram(type);
            return;
        }
    }
    else if (choice == 3) {
        system("cls");
        cout << setw(105) << " " << "1. Add New Word" << endl;
        cout << setw(105) << " " << "2. Edit Definition" << endl;
        cout << setw(105) << " " << "3. Remove Word" << endl;
        cout << setw(105) << " " << "4. Reset Dictionary" << endl;
        cout << setw(105) << " " << "5. Back" << endl;
        cout << setw(105) << " " << "Your choice: ";
        cin >> temp;
        if (temp == 5) {
            runProgram(type);
            return;
        }
    }
    else if (choice == 4) {
        system("cls");

    }
    else if (choice == 5) {
        system("cls");
        cout << setw(105) << " " << "1. View Favorite List" << endl;
        cout << setw(105) << " " << "2. Add Word to Favorite List" << endl;
        cout << setw(105) << " " << "3. Remove Word from Favorite List" << endl;
        cout << setw(105) << " " << "4. Back" << endl;
        cout << setw(105) << " " << "Your choice: ";
        cin >> temp;
        if (temp == 4) {
            runProgram(type);
            return;
        }
    }
    else if (choice == 6) {
        system("cls");
        cout << setw(105) << " " << "1. Guess Word" << endl;
        cout << setw(105) << " " << "2. Guess Meaning" << endl;
        cout << setw(105) << " " << "3. Back" << endl;
        cout << setw(105) << " " << "Your choice: ";
        cin >> temp;
        if (temp == 3) {
            runProgram(type);
            return;
        }
    }
    else if (choice == 7) {
        return;
    }
    else {
        cout << setw(105) << " " << "Invalid input." << endl;
        system("pause");
        runProgram(type);
        return;
    }
}
