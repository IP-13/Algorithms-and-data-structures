#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> weight(26);
    for (int i = 0; i < 26; i++)
        cin >> weight[i];

    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); i++)
        freq[s[i] - 'a']++;


    multimap<int, char> letters;

    for (int i = 0; i < 26; i++)
        if (freq[i] > 1)
            letters.emplace(weight[i], char('a' + i));

    s = "";

    for (auto letter: letters) {
        s += letter.second;
        int i = letter.second - 'a';
        freq[i] -= 2;
    }

    string end = s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < freq[i]; j++)
            s += char('a' + i);

    s += end;
    cout << s;
}

