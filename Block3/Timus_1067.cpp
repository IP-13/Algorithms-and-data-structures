#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void align(int k, vector <pair<int, int>> &road_signs, vector<int> &road) {
    if (k == 0) {
        return;
    }
    int i = 1;
    while (road_signs[0].first > road_signs[1].first && road_signs[1].first > 0) {
        if (i == k || road_signs[i].first == 0) {
            i = 1;
        }
        road.push_back(road_signs[0].second + 1);
        road.push_back(road_signs[i].second + 1);
        road_signs[0].first--;
        road_signs[i].first--;
        i++;
        sort(road_signs.rbegin(), road_signs.rend());
    }
}

void place_signs(int k, vector <pair<int, int>> &road_signs, vector<int> &road) {
    int index = k;
    for (int i = 1; i < k; i++) {
        if (road_signs[i].first != road_signs[0].first) {
            index = i;
            break;
        }
    }
    while (road_signs[0].first > 0) {
        if (index == k) {
            break;
        }
        int size = road_signs[0].first - road_signs[index].first;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < index; j++) {
                road.push_back(road_signs[j].second + 1);
                road_signs[j].first--;
            }
        }
        index++;
    }
    if (road_signs[0].first > 0) {
        int size = road_signs[0].first;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < k; j++) {
                road.push_back(road_signs[j].second + 1);
                road_signs[j].first--;
            }
        }
    }
}

void left(int k, vector <pair<int, int>> &road_signs, vector<int> &road) {
    for (int i = 0; i < road_signs[0].first; i++) {
        road.push_back(road_signs[0].second + 1);
    }
    road_signs[0].first = 0;
}

int main() {
    int k;
    cin >> k;
    vector <pair<int, int>> road_signs;
    vector<int> road;
    int num_of_signs = 0;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        road_signs.push_back(make_pair(x, i));
        num_of_signs += x;
    }
    sort(road_signs.rbegin(), road_signs.rend());
    align(k, road_signs, road);
    if (num_of_signs - road_signs[0].first >= road_signs[0].first) {
        place_signs(k, road_signs, road);
    } else {
        left(k, road_signs, road);
    }
    for (int i = 0; i < road.size(); i++) {
        cout << road[i] << ' ';
    }
    return 0;
}

