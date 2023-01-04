#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> counter;
    vector<int> elements(n);

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        elements[i] = x;
        if (counter.find(x) == counter.end()) {
            counter[x] = 0;
        }
        counter[x]++;
    }

    vector<int> answer;

    answer.push_back(counter.begin()->first);

    for (int i = k; i < n; i++) {
        int x;
        cin >> x;
        elements[i] = x;
        if (counter.find(x) == counter.end()) {
            counter[x] = 0;
        }
        counter[x]++;
        counter[elements[i - k]]--;
        if (counter[elements[i - k]] == 0)
            counter.erase(elements[i - k]);
        answer.push_back(counter.begin()->first);
    }

    for (auto a: answer)
        cout << a << ' ';

}

