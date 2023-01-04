#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string last;
    cin >> last;
    string first = last;
    sort(first.begin(), first.end());
    first = ' ' + first;
    vector<int> permutation(last.size());
    int j = 0;
    for (int i = 1; i <= last.size(); i++) {
        if (first[i] != first[i - 1] || j == last.size()) {
            j = 0;
        }
        while (first[i] != last[j]) {
            j++;
        }
        permutation[i - 1] = j++;
    }
    n--;
    for (int i = 0; i < last.size(); i++) {
        cout << last[permutation[n]];
        n = permutation[n];
    }
}

