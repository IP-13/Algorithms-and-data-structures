#include <iostream>

using namespace std;

int bacterium(int a, int b, int c, int d, long long k) {
    if (a == a * b - c)
        return a;
    for (long long i = 0; i < k; i++) {
        a = a * b - c;
        if (a <= 0)
            return 0;
        if (a > d)
            return d;
    }
    return a;
}

int main() {
    int a, b, c, d;
    long long k;
    cin >> a >> b >> c >> d >> k;
    cout << bacterium(a, b, c, d, k);
}

