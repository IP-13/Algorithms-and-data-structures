#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>


using namespace std;

int malloc(int needed_size, multiset<int> &memory_pos, set <pair<int, int>, greater<pair<int, int>>>& memory_size) {
    if (memory_pos.size() > 0) {
        int size = static_cast <int> (memory_size.begin()->first);
        int begin = static_cast <int> (memory_size.begin()->second);
        int end = begin + size - 1;

        if (size > needed_size) {
            memory_pos.erase(memory_pos.lower_bound(begin));
            memory_pos.insert(begin + needed_size);
            memory_size.erase({size, begin});
            memory_size.insert({size - needed_size, begin + needed_size});
            return begin;
        } else if (size == needed_size) {
            memory_pos.erase(memory_pos.lower_bound(begin));
            memory_pos.erase(memory_pos.lower_bound(end));
            memory_size.erase({size, begin});
            return begin;
        }
    }

    return -1;
}


void free(int begin, int end, multiset<int> &memory_pos, set <pair<int, int>, greater<pair<int, int>>>& memory_size) {
    auto prev = memory_pos.find(begin - 1);
    auto next = memory_pos.find(end + 1);

    if (prev != memory_pos.end()) {
        if (next != memory_pos.end()) {
            prev = memory_pos.upper_bound(begin - 1);
            prev--;
            int p = static_cast <int> (*prev);
            int n = static_cast <int> (*next);
            prev--;
            next++;
            int p1 = static_cast <int> (*prev);
            int n1 = static_cast <int> (*next);
            memory_size.erase({p - p1 + 1, p1});
            memory_size.erase({n1 - n + 1, n});
            memory_size.insert({n1 - p1 + 1, p1});
            memory_pos.erase(memory_pos.lower_bound(p));
            memory_pos.erase(memory_pos.lower_bound(n));
        } else {
            prev = memory_pos.upper_bound(begin - 1);
            prev--;
            int p = static_cast <int> (*prev);
            prev--;
            int p1 = static_cast <int> (*prev);
            memory_size.erase({p - p1 + 1, p1});
            memory_size.insert({end - p1 + 1, p1});
            memory_pos.erase(memory_pos.lower_bound(p));
            memory_pos.insert(end);
        }
    } else if (next != memory_pos.end()) {
        int n = static_cast <int> (*next);
        next++;
        int n1 = static_cast <int> (*next);
        memory_size.erase({n1 - n + 1, n});
        memory_size.insert({n1 - begin + 1, begin});
        memory_pos.erase(memory_pos.lower_bound(n));
        memory_pos.insert(begin);
    } else {
        memory_size.insert({end - begin + 1, begin});
        memory_pos.insert(begin);
        memory_pos.insert(end);
    }
}


int main() {
    int n;
    int m;
    cin >> n >> m;
    multiset <int> memory_pos;
    set <pair<int, int>, greater<pair<int,int>>> memory_size;
    memory_pos.insert(1);
    memory_pos.insert(n);
    memory_size.insert({ n , 1 });
    vector <pair <int, int>> requests(m);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            if (requests[-x - 1].first != -1) {
                free(requests[-x - 1].first, requests[-x - 1].second, memory_pos, memory_size);
            }
        }
        else {
            int pos = malloc(x, memory_pos, memory_size);
            requests[i] = { pos, pos + x - 1 };
            cout << pos << '\n';
        }
    }

    return 0;
}