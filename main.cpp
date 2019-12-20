#include <iostream>
#include <stdlib.h>
using namespace std;

#define check_term() if (getenv("TERM"))  {system("clear");}

void display_board(char ttt[][10]) {
    for (int i = 0; i < 5; ++i) {

        for (int j = 0; j < 5; ++j) {
            if (i == 1 || i == 3) {
                cout << "~~";
            }
            else if (j == 1 || j == 3) {
                cout << " | ";
            }
            else {
                cout << ttt[i][j];
            }
        }
        cout << "\n";
    }

}
void initialize_board(char ttt[][10]) {
    int i, j, k = 49;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (!(i%2)) {
                if (!(j%2)) {
                    ttt[i][j] = k;
                    ++k;

                }

            }
        }
    }
}

bool process_choice(char ttt[][10], char player_choice, char cur_symbol, int *player) {
    for (int i = 0; i <= 4; i+=2) {
        for (int j = 0; j <= 4; j+=2) {
            if (ttt[i][j] == player_choice) {
                ttt[i][j] = cur_symbol;
                if (*player == 1) {
                    *player = 2;
                }
                else {
                    *player = 1;
                }
                return true;
            }

        }
    }
}

bool check_win(char ttt[][10]) {
    //rows
    if (ttt[0][0] == ttt[0][2] == ttt[0][4]) return true;
    if (ttt[2][0] == ttt[2][2] == ttt[2][4]) return true;
    if (ttt[4][0] == ttt[4][2] == ttt[4][4]) return true;
    cout << "Not rows\n";
    //columns
    if (ttt[0][0] == ttt[2][0] == ttt[4][0]) {
        return true;
    }
    if (ttt[0][2] == ttt[2][2] == ttt[4][2]) return true;
    if (ttt[0][4] == ttt[2][4] == ttt[4][4]) return true;
    cout << "Not columns\n";
    //diagonals
    if (ttt[0][0] == ttt[2][2] == ttt[4][4]) return true;
    if (ttt[4][0] == ttt[2][2] == ttt[0][4]) return true;
    cout << "Not diagonals\n";

    return false;
}

int main(void) {
    char ttt[10][10] = {};
    int player = 1;
    char player_choice = 'A';
    char cur_symbol = 'E';
    bool found;
    bool win = false;

    initialize_board(ttt);
    display_board(ttt);
    check_term()


    cout << "Player 1 = * / Player 2 = o.\n";
    while (!win) {
        found = false;
        if (player == 1) {
            cur_symbol = '*';
        }
        else {
            cur_symbol = 'o';
        }
        cout << "Choose a number (Q to Quit): ";
        cin >> player_choice;
        cout << endl;
        if (player_choice == 'q' || player_choice == 'Q') {
            break;
        }

        if (player_choice < '1' || player_choice > '9') {
            cout << "INVALID ENTRY!\n";
            continue;
        }

        found = process_choice(ttt, player_choice, cur_symbol, &player);
        win = check_win(ttt);
        if (win) {
            cout << "YOU WON\n";
        }
        else {
            cout << "GAME ON\n";
        }

        display_board(ttt);
        if (!found)
        {
            cout << "Invalid Selection!\n";
        }

    }
    return 0;
}
