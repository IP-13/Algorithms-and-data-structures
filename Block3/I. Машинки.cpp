#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;


    vector <pair<int, int>> cars(p);                            // <car number, next position>
    map<int, int> old_cars;                                    // <car number, last position>
    map<int, int, greater<int>> cars_on_floor;                    // <next position, car number>
    map<int, int> on_floor;                                    // <car number, next position>
    int f = p + 1;

    for (size_t i = 0; i < p; i++) {
        int x;
        cin >> x;
        if (old_cars.find(x) == old_cars.end()) {
            old_cars[x] = i;
            cars[i] = {x, f++};
        } else {
            cars[old_cars[x]] = {x, i};
            old_cars[x] = i;
            cars[i] = {x, f++};
        }
    }

    size_t operations = 0;

    for (size_t i = 0; i < p; i++) {
        if (on_floor.find(cars[i].first) == on_floor.end()) {
            operations++;
            if (on_floor.size() < k) {
                cars_on_floor[cars[i].second] = cars[i].first;
                on_floor[cars[i].first] = cars[i].second;
            } else {
                int car = static_cast <int> (cars_on_floor.begin()->second);
                int pos = static_cast <int> (cars_on_floor.begin()->first);
                on_floor.erase(car);
                cars_on_floor.erase(pos);
                on_floor[cars[i].first] = cars[i].second;
                cars_on_floor[cars[i].second] = cars[i].first;
            }
        } else {
            cars_on_floor.erase(on_floor[cars[i].first]);
            cars_on_floor[cars[i].second] = cars[i].first;
            on_floor[cars[i].first] = cars[i].second;
        }
    }

    cout << operations;

    return 0;
}

