#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int total_price = 0;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
        total_price += prices[i];
    }

    sort(prices.rbegin(), prices.rend());

    for (int i = 0; i < n / k; i++) {
        total_price -= prices[k - 1 + k * i];
    }
    cout << total_price;
}

