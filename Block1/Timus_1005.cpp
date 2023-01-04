#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> stones(n);
    int total_weight = 0;

    for (int i = 0; i < n; i++) {
        cin >> stones[i];
        total_weight += stones[i];
    }

    sort(stones.rbegin(), stones.rend());

    int min_difference = total_weight;

    for (int i = 0; i < (1 << n); i++) {
        int current_weight = 0;
        int j = i;
        int k = 0;
        while (j > 0) {
            if (j % 2) {
                current_weight += stones[k];
            }
            j /= 2;
            k++;
        }
        int current_difference = abs(total_weight - 2 * current_weight);
        if (current_difference < min_difference) {
            min_difference = current_difference;
        }
    }
    cout << min_difference;
}

