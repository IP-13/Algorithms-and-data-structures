#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> moneyBoxes(n);
    vector<int> cycles(n, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        moneyBoxes[i] = x - 1;
    }

    int currCycle = 1;

    for (int i = 0; i < n; i++) {
        int j = i;

        bool cycle = cycles[j] == 0;

        if (cycle) {
            while (cycles[j] == 0) {
                cycles[j] = currCycle;
                j = moneyBoxes[j];
            }

            if (cycles[j] == currCycle) {
                currCycle++;
            } else {
                int k = i;
                int prevCycle = cycles[j];
                while (cycles[k] != prevCycle) {
                    cycles[k] = prevCycle;
                    k = moneyBoxes[k];
                }
            }
        }
    }

    cout << currCycle - 1;
}

