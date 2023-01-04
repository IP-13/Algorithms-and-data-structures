#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

enum color {
    COLORLESS,
    WHITE,
    BLACK
};

void dfs(int lkshonok, int prev, vector <vector<int>> &lkshata, vector<int> &colors) {
    if (colors[prev] == BLACK) {
        colors[lkshonok] = WHITE;
    } else {
        colors[lkshonok] = BLACK;
    }

    for (int i = 0; i < lkshata[lkshonok].size(); i++) {
        if (lkshata[lkshonok][i] == prev) {
            continue;
        }

        if (colors[lkshata[lkshonok][i]] == COLORLESS) {
            dfs(lkshata[lkshonok][i], lkshonok, lkshata, colors);
        }
    }
}

bool containCycle(vector <vector<int>> &lkshata, vector<int> &colors) {
    for (int i = 0; i < lkshata.size(); i++) {
        for (int j = 0; j < lkshata[i].size(); j++) {
            if (colors[lkshata[i][j]] == colors[i]) {
                return true;
            }
        }
    }
    return false;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector <vector<int>> lkshata(n);
    vector<int> colors(n, COLORLESS);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        lkshata[a].push_back(b);
        lkshata[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (colors[i] == COLORLESS) {
            dfs(i, i, lkshata, colors);
        }
    }

    if (containCycle(lkshata, colors)) {
        cout << "NO";
    } else {
        cout << "YES";
    }

}

