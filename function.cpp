#include "function.h"

using namespace std;

void MenuSearch(){
    cout << setw(105) << " " << "1. Search by Keyword" << endl;
    cout << setw(105) << " " << "2. Search by Definition" << endl;
    cout << setw(105) << " " << "3. View Search History" << endl;
    cout << setw(105) << " " << "4. Back" << endl;
    cout << setw(105) << " " << "Your choice: ";
}
Word InputnewWord(){
    Word p;
    cout << "Input word: ";
    cin >> p.Key;
    while (true){
        cout << "What is the type of this word? (Enter None to exit): ";
        string tmp1;
        getline(cin, tmp1);
        if (tmp1 == "None") break;
        int x = GetTypeInt(tmp1, GetType);
        p.AddType(x);
        while (true){
            cout << "What is the meaning of this word? (Enter None to exit): ";
            string tmp2;
            getline(cin, tmp2);
            if (tmp2 == "None") break;
            p.AddTrans(x, tmp2);
            int y = p.typeDefEx.size() - 1;
            while (true){
                cout << "What example you can give for this meaning? (Enter None to exit): ";
                string tmp3;
                getline(cin, tmp3);
                if (tmp3 == "None") break;
                p.AddEx(x, y, tmp3);
            }
        }
    }
    return p;
}
void AddnewWord(){
    cout << "1. Add by hand" << endl;
    cout << "2. Add by a text file" << endl;
    cout << "3. Back" << endl;
    cout << "Choose: ";
    int tmp;
    cin >> tmp;
    switch (tmp)
    {
        case 1:
        {
            cout << "1. English to Vietnamese" << endl;
            cout << "2. Vietnamese to English" << endl;
            cout << "3. English to English" << endl;
            cout << "4. Back" << endl;
            cout << "Choose the form you want to add " << endl;

            cin >> tmp;
            switch(tmp)
            {
                case 1:
                {
                    Word p = InputnewWord();
                }
                case 2:
                {

                }
                case 3:
                {

                }
                case 4:
                {
                    AddnewWord();
                    break;
                }
            }
        }

        case 2:
        {

        }
        case 3:
        {
            runProgram(1);
            break;
        }
    }
}
void LoadFavoriteList(){

}
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
        switch(temp)
        {
            case 1:
            {
                AddnewWord();
                break;
            }
            case 2:
            {

            }
            case 3:
            {

            }
            case 4:
            {

            }
            case 5:
            {
                runProgram(type);
                break;
            }
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

void saveHistory(vector<string> hisSearch) {
    ofstream fout;
    string filePath = "Data/his.txt";
    fout.open(filePath);
    for (int i = 0; i < hisSearch.size(); ++i) {
        fout << hisSearch[i] << endl;
    }
    fout.close();
}

vector <string> loadHistoryFile() {
    ifstream fin;
    vector<string> hisSearch;
    string filePath = "Data/his.txt", temp;
    fin.open(filePath);
    while(!fin.eof()) {
        fin >> temp;
        hisSearch.push_back(temp);
    }
    fin.close();
}

void displayHistory(vector<string> hisSearch) {
    cout << setw(93) << "Search History" << endl; 
    for (int i = 0; i < hisSearch.size(); ++i) {
        cout << setw(93) << " " << i + 1 << ". " << hisSearch[i] << endl;
    }
}

// search function
void search(string to_search, HashTable t) {
    HashNode* in_hash = t.FindWord(to_search);
    if (!in_hash) {
        cout << "No result found!" << endl;
        return;
    }
    in_hash->data.ShowData(2, t.GetDef);
    delete in_hash;
    in_hash = nullptr;
}