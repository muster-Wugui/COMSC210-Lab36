//COMSC-210 | Lab 36 | Xiao Zhang

//  main.cpp
//  COMSC210-Lab36
//
//  Created by Xiao Zhang on 11/27/24.
//

#include "BinaryTree.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int main() {
    BinaryTree tree;
    
    ifstream inputFile("codes.txt");
    string code;

    while (getline(inputFile, code)) {
        if (!code.empty()) {
            tree.insertNode(code);
        }
    }
    inputFile.close();

    int choice;
    
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add a code" << endl;
        cout << "2. Delete a code" << endl;
        cout << "3. Search for a code" << endl;
        cout << "4. Display tree (in-order)" << endl;
        cout << "5. Display tree (pre-order)" << endl;
        cout << "6. Display tree (post-order)" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "Enter a code to add: ";
                getline(cin, code);
                tree.insertNode(code);
                cout << "Code added." << endl;
                break;
            }
            case 2: {
                cout << "Enter a code to delete: ";
                getline(cin, code);
                tree.removeNode(code);
                cout << "Code removed if it existed." << endl;
                break;
            }
            case 3: {
                cout << "Enter a code to search: ";
                getline(cin, code);
                if (tree.searchNode(code)) {
                    cout << "Code found in the tree." << endl;
                } else {
                    cout << "Code not found." << endl;
                }
                break;
            }
            case 4: {
                cout << "Tree (in-order traversal):" << endl;
                tree.displayInOrder();
                break;
            }
            case 5: {
                cout << "Tree (pre-order traversal):" << endl;
                tree.displayPreOrder();
                break;
            }
            case 6: {
                cout << "Tree (post-order traversal):" << endl;
                tree.displayPostOrder();
                break;
            }
            case 7: {
                cout << "Exiting" << endl;
                break;
            }
        }
    } while (choice != 7);

    return 0;
}
