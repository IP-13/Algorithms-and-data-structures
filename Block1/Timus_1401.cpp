#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

bool is_zero_here(int size, int row, int column, int x, int y);

void block_1(int size, int row, int column, int x, int y, vector <vector<int>> &square, int &num_of_figure);

void block_2(int size, int row, int column, int x, int y, vector <vector<int>> &square, int &num_of_figure);

void block_3(int size, int row, int column, int x, int y, vector <vector<int>> &square, int &num_of_figure);

void block_4(int size, int row, int column, int x, int y, vector <vector<int>> &square, int &num_of_figure);

void zero_in_block_1(int size, int row, int column, vector <vector<int>> &square, int &num_of_figure);

void zero_in_block_2(int size, int row, int column, vector <vector<int>> &square, int &num_of_figure);

void zero_in_block_3(int size, int row, int column, vector <vector<int>> &square, int &num_of_figure);

void zero_in_block_4(int size, int row, int column, vector <vector<int>> &square, int &num_of_figure);

bool is_zero_here(int size, int row, int column, int x, int y) {
    if (row <= x && x <= row + size - 1 &&
        column <= y && y <= column + size - 1) {
        return true;
    }
    return false;
}

void block_1(int size, int row, int column, int x, int y, vector <vector<int>> &square, int &num_of_figure) {
    num_of_figure++;
    if (size == 2) {
        if (!is_zero_here(size, row, column, x, y)) {
            square[row + 1][column] = num_of_figure;
            square[row][column] = num_of_figure;
            square[row][column + 1] = num_of_figure;
        }
    } else {
        square[row + size / 2][column + size / 2 - 1] = num_of_figure;
        square[row + size / 2 - 1][column + size / 2 - 1] = num_of_figure;
        square[row + size / 2 - 1][column + size / 2] = num_of_figure;
        block_1(size / 2, row, column, x, y, square, num_of_figure);
        block_2(size / 2, row, column + size / 2, x, y, square, num_of_figure);
        block_1(size / 2, row + size / 2, column + size / 2, x, y, square, num_of_figure);
        block_4(size / 2, row + size / 2, column, x, y, square, num_of_figure);
    }
}

void block_2(int size, int row, int column, int x, int y, vector <vector<int>> &square, int &num_of_figure) {
    num_of_figure++;
    if (size == 2) {
        if (!is_zero_here(size, row, column, x, y)) {
            square[row][column] = num_of_figure;
            square[row][column + 1] = num_of_figure;
            square[row + 1][column + 1] = num_of_figure;
        }
    } else {
        square[row + size / 2 - 1][column + size / 2 - 1] = num_of_figure;
        square[row + size / 2 - 1][column + size / 2] = num_of_figure;
        square[row + size / 2][column + size / 2] = num_of_figure;
        block_2(size / 2, row, column + size / 2, x, y, square, num_of_figure);
        block_3(size / 2, row + size / 2, column + size / 2, x, y, square, num_of_figure);
        block_2(size / 2, row + size / 2, column, x, y, square, num_of_figure);
        block_1(size / 2, row, column, x, y, square, num_of_figure);
    }
}

void block_3(int size, int row, int column, int x, int y, vector <vector<int>> &square, int &num_of_figure) {
    num_of_figure++;
    if (size == 2) {
        if (!is_zero_here(size, row, column, x, y)) {
            square[row][column + 1] = num_of_figure;
            square[row + 1][column + 1] = num_of_figure;
            square[row + 1][column] = num_of_figure;
        }
    } else {
        square[row + size / 2 - 1][column + size / 2] = num_of_figure;
        square[row + size / 2][column + size / 2] = num_of_figure;
        square[row + size / 2][column + size / 2 - 1] = num_of_figure;
        block_3(size / 2, row + size / 2, column + size / 2, x, y, square, num_of_figure);
        block_4(size / 2, row + size / 2, column, x, y, square, num_of_figure);
        block_3(size / 2, row, column, x, y, square, num_of_figure);
        block_2(size / 2, row, column + size / 2, x, y, square, num_of_figure);
    }
}

void block_4(int size, int row, int column, int x, int y, vector <vector<int>> &square, int &num_of_figure) {
    num_of_figure++;
    if (size == 2) {
        if (!is_zero_here(size, row, column, x, y)) {
            square[row + 1][column + 1] = num_of_figure;
            square[row + 1][column] = num_of_figure;
            square[row][column] = num_of_figure;
        }
    } else {
        square[row + size / 2][column + size / 2] = num_of_figure;
        square[row + size / 2][column + size / 2 - 1] = num_of_figure;
        square[row + size / 2 - 1][column + size / 2 - 1] = num_of_figure;
        block_4(size / 2, row + size / 2, column, x, y, square, num_of_figure);
        block_1(size / 2, row, column, x, y, square, num_of_figure);
        block_4(size / 2, row, column + size / 2, x, y, square, num_of_figure);
        block_3(size / 2, row + size / 2, column + size / 2, x, y, square, num_of_figure);
    }
}

void zero_in_block_1(int size, int row, int column, vector <vector<int>> &square, int &num_of_figure) {
    num_of_figure++;
    square[row + size / 2 - 1][column + size / 2] = num_of_figure;
    square[row + size / 2][column + size / 2] = num_of_figure;
    square[row + size / 2][column + size / 2 - 1] = num_of_figure;
}

void zero_in_block_2(int size, int row, int column, vector <vector<int>> &square, int &num_of_figure) {
    num_of_figure++;
    square[row + size / 2][column + size / 2] = num_of_figure;
    square[row + size / 2][column + size / 2 - 1] = num_of_figure;
    square[row + size / 2 - 1][column + size / 2 - 1] = num_of_figure;
}

void zero_in_block_3(int size, int row, int column, vector <vector<int>> &square, int &num_of_figure) {
    num_of_figure++;
    square[row + size / 2][column + size / 2 - 1] = num_of_figure;
    square[row + size / 2 - 1][column + size / 2 - 1] = num_of_figure;
    square[row + size / 2 - 1][column + size / 2] = num_of_figure;
}

void zero_in_block_4(int size, int row, int column, vector <vector<int>> &square, int &num_of_figure) {
    num_of_figure++;
    square[row + size / 2 - 1][column + size / 2 - 1] = num_of_figure;
    square[row + size / 2 - 1][column + size / 2] = num_of_figure;
    square[row + size / 2][column + size / 2] = num_of_figure;
}

void fill_square(int size, int row, int column, int x, int y, vector <vector<int>> &square, int &num_of_figure) {
    if (size > 2) {
        if (is_zero_here(size / 2, row, column, x, y)) {
            zero_in_block_1(size, row, column, square, num_of_figure);
            block_2(size / 2, row, column + size / 2, x, y, square, num_of_figure);
            block_3(size / 2, row + size / 2, column + size / 2, x, y, square, num_of_figure);
            block_4(size / 2, row + size / 2, column, x, y, square, num_of_figure);
            fill_square(size / 2, row, column, x, y, square, num_of_figure);
        } else if (is_zero_here(size / 2, row, column + size / 2, x, y)) {
            zero_in_block_2(size, row, column, square, num_of_figure);
            block_1(size / 2, row, column, x, y, square, num_of_figure);
            block_3(size / 2, row + size / 2, column + size / 2, x, y, square, num_of_figure);
            block_4(size / 2, row + size / 2, column, x, y, square, num_of_figure);
            fill_square(size / 2, row, column + size / 2, x, y, square, num_of_figure);
        } else if (is_zero_here(size / 2, row + size / 2, column + size / 2, x, y)) {
            zero_in_block_3(size, row, column, square, num_of_figure);
            block_1(size / 2, row, column, x, y, square, num_of_figure);
            block_2(size / 2, row, column + size / 2, x, y, square, num_of_figure);
            block_4(size / 2, row + size / 2, column, x, y, square, num_of_figure);
            fill_square(size / 2, row + size / 2, column + size / 2, x, y, square, num_of_figure);
        } else {
            zero_in_block_4(size, row, column, square, num_of_figure);
            block_1(size / 2, row, column, x, y, square, num_of_figure);
            block_2(size / 2, row, column + size / 2, x, y, square, num_of_figure);
            block_3(size / 2, row + size / 2, column + size / 2, x, y, square, num_of_figure);
            fill_square(size / 2, row + size / 2, column, x, y, square, num_of_figure);
        }
    }
}

void print_vector(vector <vector<int>> &square) {
    for (int i = 0; i < square.size(); i++) {
        for (int j = 0; j < square[i].size(); j++) {
            cout << square[i][j] << '\t';
        }
        cout << '\n';
    }
}

void last_figure(int size, int x, int y, vector <vector<int>> &square, int &num_of_figure) {
    if (size == 2) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (square[i][j] == -1) {
                    square[i][j] = 1;
                }
            }
        }
    } else {
        if (x == size - 1) {
            x--;
        }
        if (y == size - 1) {
            y--;
        }
        if (x == 0) {
            x++;
        }
        if (y == 0) {
            y++;
        }
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (square[i][j] == -1) {
                    square[i][j] = num_of_figure + 1;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int size = pow(2, n);
    int x, y;
    cin >> x >> y;

    vector <vector<int>> square(size, vector<int>(size, -1));

    square[--x][--y] = 0;
    int num_of_figure = 0;

    fill_square(size, 0, 0, x, y, square, num_of_figure);
    last_figure(size, x, y, square, num_of_figure);
    print_vector(square);
    return 0;
}

