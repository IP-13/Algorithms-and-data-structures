#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>

using namespace std;

int main() {
    string s;
    map <string, stack<int>> variables;
    stack <string> current;
    stack<int> strings_in_block;
    strings_in_block.push(0);

    vector<int> ans;

    while (cin >> s) {
        if (s == "{") {
            strings_in_block.push(0);
        } else if (s == "}") {
            for (int i = 0; i < strings_in_block.top(); i++) {
                variables[current.top()].pop();
                current.pop();
            }
            strings_in_block.pop();
        } else {
            strings_in_block.top()++;
            string variable = "";
            string value = "";
            int i = 0;
            while (s[i] != '=') {
                variable += s[i];
                i++;
            }
            i++;
            while (i < s.size()) {
                value += s[i];
                i++;
            }

            if (variables.find(value) != variables.end()) {
                int v;
                if (!variables[value].empty()) {
                    v = variables[value].top();
                } else {
                    v = 0;
                }
                current.push(variable);
                variables[variable].push(v);
                ans.push_back(v);
            } else if (value[0] <= '9' && value[0] >= '0' || value[0] == '-') {
                current.push(variable);
                variables[variable].push(stoi(value));
            } else {
                current.push(variable);
                variables[variable].push(0);
                ans.push_back(0);
            }
        }
    }

    for (auto a: ans) {
        cout << a << '\n';
    }

    return 0;
}

