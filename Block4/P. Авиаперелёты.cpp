#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;


enum visited {
    VISITED,
    NOT_VISITED,
    IN,
    OUT
};

void dfsOut(int minTubSize, int curr, int inOrOut, vector <vector<int>> &bubundiaMap, vector<int> &visitedCities) {
    visitedCities[curr] = VISITED;
    for (int i = 0; i < visitedCities.size(); i++) {
        if (i != curr && visitedCities[i] == NOT_VISITED && bubundiaMap[curr][i] <= minTubSize) {
            dfsOut(minTubSize, i, IN, bubundiaMap, visitedCities);
        }
    }
}

void dfsIn(int minTubSize, int curr, int inOrOut, vector <vector<int>> &bubundiaMap, vector<int> &visitedCities) {
    visitedCities[curr] = VISITED;
    for (int i = 0; i < visitedCities.size(); i++) {
        if (i != curr && visitedCities[i] == NOT_VISITED && bubundiaMap[i][curr] <= minTubSize) {
            dfsIn(minTubSize, i, OUT, bubundiaMap, visitedCities);
        }
    }
}

bool isAllCitiesVisited(vector<int> &visitedCities) {
    for (int i = 0; i < visitedCities.size(); i++) {
        if (visitedCities[i] == NOT_VISITED) {
            return false;
        }
    }
    return true;
}


int main() {
    int n;
    cin >> n;

    vector <vector<int>> bubundiaMap(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            bubundiaMap[i][j] = a;
        }
    }

    int l = 0;
    int r = INT32_MAX;

    while (l < r) {
        vector<int> visitedCitiesIn(n, NOT_VISITED);
        vector<int> visitedCitiesOut(n, NOT_VISITED);
        dfsIn((l + r) / 2, 0, OUT, bubundiaMap, visitedCitiesIn);
        dfsOut((l + r) / 2, 0, OUT, bubundiaMap, visitedCitiesOut);
        if (isAllCitiesVisited(visitedCitiesIn) && isAllCitiesVisited(visitedCitiesOut)) {
            r = (l + r) / 2;
        } else {
            l = (l + r) / 2 + 1;
        }
    }

    cout << l;
}

