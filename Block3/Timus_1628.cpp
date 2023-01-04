#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isolated_day(int x, int y, int m, int n, set <pair<int, int>> &bad_days) {
    int isolation = 0;
    if (x == 0) {
        isolation++;
    }
    if (x == m - 1) {
        isolation++;
    }
    if (x != 0 && bad_days.find({x - 1, y}) != bad_days.end()) {
        isolation++;
    }
    if (x != m - 1 && bad_days.find({x + 1, y}) != bad_days.end()) {
        isolation++;
    }
    if (y == 0) {
        isolation++;
    }
    if (y == n - 1) {
        isolation++;
    }
    if (y != 0 && bad_days.find({x, y - 1}) != bad_days.end()) {
        isolation++;
    }
    if (y != n - 1 && bad_days.find({x, y + 1}) != bad_days.end()) {
        isolation++;
    }
    return isolation == 4;
}

int gorizontal_white_lines(int m, int n, set <pair<int, int>> &bad_days) {
    int num_of_white_stripes = 0;
    auto bad_day = bad_days.begin();
    int previous_bad_day = n;
    for (int i = 0; i < m + 1; i++) {
        if (n - previous_bad_day > 2) {
            num_of_white_stripes++;
        } else if (n - previous_bad_day == 2) {
            if (isolated_day(i - 1, n - 1, m, n, bad_days)) {
                num_of_white_stripes++;
            }
        }
        previous_bad_day = -1;
        while (bad_day != bad_days.end() && bad_day->first == i) {
            if (bad_day->second - previous_bad_day > 2) {
                num_of_white_stripes++;
            } else if (bad_day->second - previous_bad_day == 2) {
                if (isolated_day(i, previous_bad_day + 1, m, n, bad_days)) {
                    num_of_white_stripes++;
                }
            }
            previous_bad_day = bad_day->second;
            bad_day++;
        }
    }
    return num_of_white_stripes;
}

int vertical_white_lines(int m, int n, set <pair<int, int>> &reversed_bad_days) {
    int num_of_white_stripes = 0;
    auto bad_day = reversed_bad_days.begin();
    int previous_bad_day = m;
    for (int j = 0; j < n + 1; j++) {
        if (m - previous_bad_day > 2) {
            num_of_white_stripes++;
        }
        previous_bad_day = -1;
        while (bad_day != reversed_bad_days.end() && bad_day->first == j) {
            if (bad_day->second - previous_bad_day > 2) {
                num_of_white_stripes++;
            }
            previous_bad_day = bad_day->second;
            bad_day++;
        }
    }
    return num_of_white_stripes;
}

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    set <pair<int, int>> bad_days;
    set <pair<int, int>> reversed_bad_days;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        bad_days.insert({x - 1, y - 1});
        reversed_bad_days.insert({y - 1, x - 1});
    }
    cout << gorizontal_white_lines(m, n, bad_days) + vertical_white_lines(m, n, reversed_bad_days);
}

