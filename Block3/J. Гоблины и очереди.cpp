#include <iostream>
#include <list>
#include <queue>

using namespace std;

template<typename T>
class Goblins_Line {
public:
    Goblins_Line() {
        first_half_size = 0;
        second_half_size = 0;
    }

    void middle(T element) {
        if (first_half_size == second_half_size) {
            first_half.emplace(element);
            first_half_size++;
        } else {
            second_half.push_front(element);
            second_half_size++;
        }
    }

    void back(T element) {
        if (first_half_size == 0 && second_half_size == 0) {
            first_half.emplace(element);
            first_half_size++;
        } else if (first_half_size == second_half_size) {
            T temp = second_half.front();
            second_half.pop_front();
            first_half.emplace(temp);
            second_half.push_back(element);
            first_half_size++;
        } else {
            second_half.push_back(element);
            second_half_size++;
        }
    }

    T front() {
        if (first_half_size == second_half_size) {
            T first_element = first_half.front();
            first_half.pop();
            first_half.emplace(second_half.front());
            second_half.pop_front();
            second_half_size--;
            return first_element;
        } else {
            T first_element = first_half.front();
            first_half.pop();
            first_half_size--;
            return first_element;
        }
    }

    int size() {
        return first_half_size + second_half_size;
    }

private:
    int first_half_size;
    int second_half_size;
    queue <T> first_half;
    list <T> second_half;
};


int main() {
    int n;
    cin >> n;

    Goblins_Line<int> goblins_line;
    for (int i = 0; i < n; i++) {
        char sign;
        cin >> sign;
        if (sign == '-') {
            cout << goblins_line.front() << '\n';
            continue;
        }
        int num;
        cin >> num;
        if (sign == '+') {
            goblins_line.back(num);
        } else {
            goblins_line.middle(num);
        }
    }
}

