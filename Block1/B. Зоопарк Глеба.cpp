#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <list>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack < pair < char, int >, vector < pair < char, int>>> animals;
    map<int, int> ans;
    int current_trap_index = 0;
    int current_animal_index = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a') {
            current_animal_index++;
        } else {
            current_trap_index++;
        }

        if (!animals.empty() && abs(animals.top().first - s[i]) == 'a' - 'A') {
            if (s[i] >= 'a') {
                ans[animals.top().second] = current_animal_index;
            } else {
                ans[current_trap_index] = animals.top().second;
            }
            animals.pop();
        } else {
            if (s[i] >= 'a') {
                animals.push(make_pair(s[i], current_animal_index));
            } else {
                animals.push(make_pair(s[i], current_trap_index));
            }
        }
    }

    if (animals.empty()) {
        cout << "Possible\n";
        for (auto a: ans) {
            cout << a.second << ' ';
        }
    } else {
        cout << "Impossible\n";
    }


    return 0;
}

