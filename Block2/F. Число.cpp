#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string max_string(string s1, string s2) {
    if (s1 == s2)
        return s1;

    if (s1.size() < s2.size())
        swap(s1, s2);

    int size1 = s1.size();
    int size2 = s2.size();

    for (int i = 0; i < size2; i++)
        if (s1[i] > s2[i])
            return s1;
        else if (s1[i] < s2[i])
            return s2;

    string temp = s1.substr(size2, size1 - size2);

    if (temp == max_string(temp, s2))
        return s1;
    else
        return s2;
}

void bubble_sort(vector <string> &str) {
    for (int i = 0; i < str.size(); i++)
        for (int j = i; j < str.size(); j++) {
            if (str[j] == max_string(str[i], str[j])) {
                swap(str[i], str[j]);
            }
        }
}

int main() {
    string s;
    vector <string> str;
    while (cin >> s)
        str.push_back(s);
    bubble_sort(str);
    for (auto c: str)
        cout << c;
}

