// Implement https://play2048.co/
// Struct and Implementation Design

#include <bits/stdc++.h>
using namespace std;

/** TODO:
 * random_populate not better
 * check if the move is valid before random_populate
 */


struct Game2048 {
    int board[4][4];

    void score() {
        int score = 0;
        for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 2048) score += 1280;
            if (board[i][j] == 1024) score += 640;
            if (board[i][j] == 512) score += 320;
            if (board[i][j] == 256) score += 160;
            if (board[i][j] == 128) score += 80;
            if (board[i][j] == 64) score += 40;
            if (board[i][j] == 32) score += 20;
            if (board[i][j] == 16) score += 10;
            if (board[i][j] == 8) score += 5;
        }
        }
        cout << "Your Score " << score << '\n';
    }

    void random_populate() {
        while (1) {
            int i = rand() % 4;
            int j = rand() % 4;
            if (board[i][j] == 0) {
                int value = rand() % 2;
                if (value == 0) board[i][j] = 2;
                else if (value == 1) board[i][j] = 4;
                return;
            }
        }
    }

    void init() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                board[i][j] = 0;
            }
        }
        random_populate();
        random_populate();
    }

    bool end() {
        for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
            return false;
            }
        }
        }
        return true;
    }

    void swipe_right(int array[]) {
        int last_placed = 4;
        int can_merge = 1;
        for (int i = 3; i >= 0; i--) {
        if (array[i] != 0) {
            if (can_merge) {
                if (array[last_placed] == array[i]) {
                    array[last_placed] *= 2;
                    array[i] = 0;
                    can_merge = 0;
                } else {
                    array[last_placed - 1] = array[i];
                    if (i != last_placed - 1) array[i] = 0;
                    last_placed--;
                    can_merge = 1;
                }
            } else {
                array[last_placed - 1] = array[i];
                if (i != last_placed - 1) array[i] = 0;
                last_placed--;
                can_merge = 1;
            }
        }
        }
    }

    void print_board() {
        for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) cout << setw(4) << board[i][j];
            else if (board[i][j] == 0) cout << setw(4) << "-";
        }
        cout << '\n';
        cout << " ---------------\n";
        }
        score();
    }

    void up() {
        int flag = 0;
        for (int column = 0; column < 4; column++) {
        int array[4], array_check[4];
        int count = 0;
        for (int row = 0; row < 4; row++) {
            array[row] = board[3 - row][column];
            array_check[row] = array[row];
        }
        swipe_right(array);
        for (int i = 0; i < 4; i++) {
            if (array_check[i] == array[i]) count++;
        }
        if (count == 4) flag += 1;
        for (int row = 0; row < 4; row++) {
            board[3 - row][column] = array[row];
        }
        }
        if (flag == 4) cout << "Input Not Allowed!\n";
        else {
            random_populate();
            print_board();
        }
    }

    void down() {
        int flag = 0;
        for (int column = 0; column < 4; column++) {
        int array[4], array_check[4];
        int count = 0;
        for (int row = 0; row < 4; row++) {
            array[row] = board[row][column];
            array_check[row] = array[row];
        }
        swipe_right(array);
        for (int i = 0; i < 4; i++) {
            if (array_check[i] == array[i]) count++;
        }
        if (count == 4) flag += 1;
        for (int row = 0; row < 4; row++) {
            board[row][column] = array[row];
        }
        }
        if (flag == 4) cout << "Input Not Allowed!\n";
        else {
            random_populate();
            print_board();
        }
    }

    void left() {
        int flag = 0;
        for (int row = 0; row < 4; row++) {
        int array[4], array_check[4];
        int count = 0;
        for (int column = 0; column < 4; column++) {
            array[column] = board[row][3 - column];
            array_check[column] = array[column];
        }
        swipe_right(array);
        for (int i = 0; i < 4; i++) {
            if (array_check[i] == array[i]) count++;
        }
        if (count == 4) flag += 1;
        for (int column = 0; column < 4; column++) {
            board[row][3 - column] = array[column];
        }
        }
        if (flag == 4) cout << "Input Not Allowed!\n";
        else {
            random_populate();
            print_board();
        }
    }

    void right() {
        int flag = 0;
        for (int row = 0; row < 4; row++) {
        int array[4], array_check[4];
        int count = 0;
        for (int column = 0; column < 4; column++) {
            array[column] = board[row][column];
            array_check[column] = array[column];
        }
        swipe_right(array);
        for (int i = 0; i < 4; i++) {
            if (array_check[i] == array[i]) count++;
        }
        if (count == 4) flag += 1;
        for (int column = 0; column < 4; column++) {
            board[row][column] = array[column];
        }
        }
        if (flag == 4) cout << "Input Not Allowed!\n";
        else {
            random_populate();
            print_board();
        }
    }
};

int main() {
    srand(time(0));
    Game2048 mygame;
    mygame.init();
    mygame.print_board();
    while (!mygame.end()) {
        cout << "What Move?(U,D,L,R): ";
        char ch;
        cin >> ch;
        if (ch == 'U') {
        mygame.up();
        } else if (ch == 'D') {
        mygame.down();
        } else if (ch == 'L') {
        mygame.left();
        } else if (ch == 'R') {
        mygame.right();
        } else {
        cout << "Invalid Input\n";
        }
    }
    cout << "GAME Ends!\n";
    return 0;
}
