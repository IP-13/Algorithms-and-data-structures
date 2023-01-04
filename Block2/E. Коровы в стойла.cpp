#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    int l = 0;
    int r = stalls[n - 1] - stalls[0] + 1;

    while (l < r) {
        int mid = (l + r) / 2;
        int previous_stall = stalls[0];
        int num_of_cows = 1;
        for (int i = 0; i < n; i++) {
            if (stalls[i] - previous_stall >= mid) {
                num_of_cows++;
                previous_stall = stalls[i];
            }
        }
        if (num_of_cows >= k)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l - 1;
}

