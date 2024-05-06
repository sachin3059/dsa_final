#include<bits/stdc++.h>
using namespace std;

struct Record {
    int roll;
    string name;
    int chain;
};

class Hashing {
    Record table[10];

public:
    Hashing() {
        for (int i = 0; i < 10; i++) {
            table[i].roll = -1;
            table[i].chain = -1;
        }
    }

    void insert(int roll1, string name1) {
        int pos = roll1 % 10;
        int curr = pos;

        while (true) {
            if (table[curr].roll == -1) {
                table[curr].roll = roll1;
                table[curr].name = name1;
                break;
            } 
            else if ((table[curr].roll) % 10 == pos && table[curr].chain == -1) {
                for (int i = curr; i <= curr + 10; i++) {
                    if (table[i % 10].roll == -1) {
                        table[i % 10].roll = roll1;
                        table[i % 10].name = name1;
                        table[curr].chain = i % 10;
                        break;
                    }
                }
                break;
            } 
            else {
                for (int i = curr; i <= curr + 10; i++) {
                    if (table[i % 10].roll == -1) {
                        table[i % 10].roll = roll1;
                        table[i % 10].name = name1;
                        table[i % 10].chain = -1;
                        break;
                    } 
                    else if (table[i % 10].roll % 10 == pos) {
                        if (table[i % 10].chain == -1) {
                            for (int j = i; j <= i + 10; j++) {
                                if (table[j % 10].roll == -1) {
                                    table[j % 10].roll = roll1;
                                    table[j % 10].name = name1;
                                    table[i % 10].chain = j % 10;
                                    break;
                                }
                            }
                        } 
                        else {
                            while (table[i].chain != -1) {
                                i = table[i].chain;
                            }
                            for (int j = i; j <= i + 10; j++) {
                                if (table[j % 10].roll == -1) {
                                    table[j % 10].roll = roll1;
                                    table[j % 10].name = name1;
                                    table[i % 10].chain = j % 10;
                                    break;
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
    }

    void search(int roll1) {
        int curr = roll1 % 10;
        while (true) {
            if (table[curr].roll == roll1) {
                cout << "Found: " << table[curr].name << endl;
                return;
            }
            curr = table[curr].chain;
            if (curr == -1) {
                cout << "Not found\n";
                return;
            }
        }
    }

    void display() {
        cout << "HashTable:\n";
        for (int i = 0; i < 10; i++) {
            cout << table[i].roll << " " << table[i].name << " " << table[i].chain << endl;
        }
    }

    void remove(int roll1) {
        int curr = roll1 % 10;
        for (int j = 0; j < 10; j++) {
            if (table[curr % 10].roll == -1) {
                cout << "Empty\n";
                break;
            } 
            else if (table[curr % 10].roll == -2) {
                curr++;
            } 
            else if (table[curr % 10].roll == roll1) {
                table[curr % 10].roll = -2;
                table[curr % 10].name = "";
                break;
            }
        }
    }
};


int main() {
    Hashing obj;
    int roll;
    string name;
    
    for (int i = 0; i < 10; i++) {
        cin >> roll >> name;
        obj.insert(roll, name);
    }
    obj.display();

    
    cout << "Enter the number of roll numbers to search: ";
    int m; cin >> m;
    while (m--) {
        cout << "Enter the roll number to search: ";
        int rollNo; cin >> rollNo;
        obj.search(rollNo);
    }

    cout << "Enter the number of roll numbers to delete: ";
    int del; cin >> del;
    while (del--) {
        cout << "Enter the roll number to delete: ";
        int rollNo; cin >> rollNo;
        obj.remove(rollNo);
    }

    obj.display();
    return 0;

    // input of roll no should be between (1 - 10);
}
