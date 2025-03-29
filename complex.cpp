#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

enum class Difficulty { 
    EASY = 5, 
    MEDIUM = 7, 
    HARD = 8 
};

struct Grid {
    vector<vector<char>> board;
    int size;
    int shipCount;
    int tries;

    Grid(int s, int ships, int t) : size(s), shipCount(ships), tries(t) {
        board.resize(size, vector<char>(size, '-'));
        placeShips();
    }

    void placeShips() {
        srand(time(0));
        int placed = 0;
        while (placed < shipCount) {
            int r = rand() % size;
            int c = rand() % size;
            if (board[r][c] != '*') {
                board[r][c] = '*';
                placed++;
            }
        }
    }

    void printBoard() {
        cout << "\nCurrent Board:\n";
        for (const auto &row : board) {
            for (const auto &cell : row) {
                cout << (cell == '*' ? '-' : cell) << " ";
            }
            cout << "\n";
        }
    }
};

void playGame(Grid &grid) {
    int row, col, hits = 0;
    while (grid.tries > 0) {
        cout << "Enter row (1-" << grid.size << "): ";
        cin >> row;
        cout << "Enter column (1-" << grid.size << "): ";
        cin >> col;

        if (row < 1 || row > grid.size || col < 1 || col > grid.size) {
            cout << "Invalid input! Try again.\n";
            continue;
        }

        if (grid.board[row - 1][col - 1] == '*') {
            cout << "\nHIT!\n";
            grid.board[row - 1][col - 1] = 'X';
            hits++;
        } 
        else {
            cout << "\nMISS!\n";
            grid.board[row - 1][col - 1] = 'O';
        }
        grid.tries--;
        grid.printBoard();

        if (hits >= grid.shipCount) {
            cout << "\nYOU WIN! You hit " << hits << " ships. Tries left: " << grid.tries << "\n";
            return;
        }
    }
    cout << "\nYOU LOSE! You hit " << hits << " ships.\n";
}

int main() {
    int choice;
    cout << "=== BATTLESHIP GAME ===\n";
    cout << "(1) Easy\n(2) Medium\n(3) Hard\nSelect Difficulty: ";
    cin >> choice;

    Difficulty level;
    switch (choice) {
        case 1: level = Difficulty::EASY; break;
        case 2: level = Difficulty::MEDIUM; break;
        case 3: level = Difficulty::HARD; break;
        default: cout << "Invalid choice!\n"; return 0;
    }

    constexpr int easyShips = 10, mediumShips = 15, hardShips = 20;
    Grid game((int)level, (choice == 1 ? easyShips : choice == 2 ? mediumShips : hardShips), (choice == 1 ? 15 : choice == 2 ? 30 : 40));

    playGame(game);
    return 0;
}
