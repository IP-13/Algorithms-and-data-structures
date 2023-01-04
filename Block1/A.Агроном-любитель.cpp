#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int begin = 0;
    int end = 0;
    int streak = 1;
    int previous = 0;
    int max_begin = 0;
    int max_end = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == previous)
            streak++;
        else
            streak = 1;
        if (streak < 3) {
            end = i;
            if (max_end - max_begin < end - begin) {
                max_end = end;
                max_begin = begin;
            }
        } else {
            begin = i - 1;
            end = i;
        }
        previous = a;
    }
    cout << max_begin + 1 << ' ' << max_end + 1 << '\n';
}

