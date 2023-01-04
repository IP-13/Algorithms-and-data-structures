#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

enum {
    RED,
    BLUE,
    COLORLESS
};

class Country {
public:
    int color = COLORLESS;
    vector<int> neighbors;
};

void dfs(int curr, int prev, vector <Country> &countries) {
    if (countries[prev].color == BLUE) {
        countries[curr].color = RED;
    } else {
        countries[curr].color = BLUE;
    }
    for (int i = 0; i < countries[curr].neighbors.size(); i++) {
        if (countries[countries[curr].neighbors[i]].color == COLORLESS) {
            dfs(countries[curr].neighbors[i], curr, countries);
        }
    }
}

string isPossible(vector <Country> &countries) {
    string ans = "";
    for (int i = 0; i < countries.size(); i++) {
        ans += to_string(countries[i].color);
        for (int j = 0; j < countries[i].neighbors.size(); j++) {
            if (countries[i].color ==
                countries[countries[i].neighbors[j]].color) {
                return "-1";
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector <Country> countries(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        while (a != 0) {
            a--;
            countries[i].neighbors.push_back(a);
            countries[a].neighbors.push_back(i);
            cin >> a;
        }
    }
    countries[0].color = BLUE;
    dfs(0, 0, countries);
    cout << isPossible(countries) << '\n';
}

