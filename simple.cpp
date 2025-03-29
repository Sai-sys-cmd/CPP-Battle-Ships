#include <iostream>
using namespace std;

void level1();
void level2();
void level3();

int main() {
    int choice;
    bool valid = false;
    
    cout << "=== BATTLESHIP GAME ===\nBy: Sai\n\n";
    cout << "Levels: \n";
    cout << "(1) Easy \n";
    cout << "(2) Medium \n";
    cout << "(3) Hard \n\n";
    
    while (!valid) {
        cout << "Select Difficulty: ";
        cin >> choice;
        
        if (cin.fail() || (choice < 1 || choice > 3)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input! Please enter 1, 2, or 3.\n";
        } 
        else valid = true;
    }
    
    if (choice == 1) level1();
    else if (choice == 2) level2();
    else if (choice == 3) level3();
    
    return 0;
}



void level1() {
    int row, column, tries = 15, counter = 0;
    string level[5][5] = {
        { "-", "-", "-", "-", "*" },
        { "-", "*", "*", "-", "*" },
        { "-", "*", "-", "-", "*" },
        { "-", "*", "-", "-", "*" },
        { "-", "*", "-", "-", "*" }
    };
    cout << "\n\nDifficulty: EASY\nYou have 15 tries!\n5 by 5 Grid\n\n";
    while (tries > 0) {
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter column: ";
        cin >> column;
        if (row < 1 || row > 5 || column < 1 || column > 5) {
            cout << "Invalid input! Please enter a valid row and column between 1 and 5.\n";
            continue;
        }
        if (level[row-1][column-1] == "*") {
            cout << "\n\nHIT!\n\n";
            level[row-1][column-1] = "-";
            counter++;
        }
        else cout << "\nMISS!\n\n";
        tries--;
        if (counter >= 10) {
            cout << "\n\nYOU WIN!\nYou took " << (15 - tries) << " tries\n";
            break;
        }
    }
    if (tries <= 0 && counter < 10) cout << "\n\nYOU LOSE!\n\n";
}

void level2() {
    int row, column, tries = 30, counter = 0;
    string level[7][7] = {
        { "-", "-", "*", "*", "*", "*", "*" },
        { "-", "-", "-", "-", "-", "-", "-" },
        { "-", "*", "*", "*", "-", "-", "-" },
        { "-", "*", "-", "-", "-", "-", "-" },
        { "-", "*", "-", "-", "-", "*", "*" },
        { "-", "*", "-", "-", "-", "*", "-" },
        { "-", "-", "-", "-", "-", "*", "-" }
    };
    cout << "\n\nDifficulty: MEDIUM\nYou have 30 tries!\n7 by 7 Grid\n\n";
    while (tries > 0) {
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter column: ";
        cin >> column;
        if (row < 1 || row > 7 || column < 1 || column > 7) {
            cout << "Invalid input! Please enter a valid row and column between 1 and 7.\n";
            continue;
        }
        if (level[row-1][column-1] == "*") {
            cout << "\n\nHIT!\n\n";
            level[row-1][column-1] = "-";
            counter++;
        }
        else cout << "\nMISS!\n\n";
        tries--;
        if (counter >= 15) {
            cout << "\n\nYOU WIN!\nYou took " << (30 - tries) << " tries\n";
            break;
        }
    }
    if (tries <= 0 && counter < 15) cout << "\n\nYOU LOSE!\n\n";
}

void level3() {
    int row, column, tries = 40, counter = 0;
    string level[8][8] = {
        { "-", "-", "-", "*", "-", "-", "-", "-" },
        { "*", "*", "-", "*", "-", "-", "-", "-" },
        { "-", "*", "-", "*", "-", "-", "-", "-" },
        { "-", "*", "-", "*", "-", "-", "-", "-" },
        { "-", "*", "-", "*", "-", "-", "*", "-" },
        { "-", "*", "-", "*", "-", "-", "*", "-" },
        { "-", "*", "-", "-", "-", "-", "*", "-" },
        { "-", "-", "-", "*", "*", "*", "*", "-" },
    };
    cout << "\n\nDifficulty: HARD\nYou have 40 tries!\n8 by 8 Grid\n\n";
    while (tries > 0) {
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter column: ";
        cin >> column;
        if (row < 1 || row > 8 || column < 1 || column > 8) {
            cout << "Invalid input! Please enter a valid row and column between 1 and 8.\n";
            continue;
        }
        if (level[row-1][column-1] == "*") {
            cout << "\n\nHIT!\n\n";
            level[row-1][column-1] = "-";
            counter++;
        }
        else cout << "\nMISS!\n\n";
        tries--;
        if (counter >= 20) {
            cout << "\n\nYOU WIN!\nYou took " << (40 - tries) << " tries\n";
            break;
        }
    }
    if (tries <= 0 && counter < 20) cout << "\n\nYOU LOSE!\n\n";
}
