#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Edge {
public:
    Edge(int a, int b, double rab, double cab) {
        this->a = a;
        this->b = b;
        this->rab = rab;
        this->cab = cab;
    }

    Edge() {}

    int a;
    int b;
    double rab;
    double cab;
};

int main() {
    int n, m, s;
    double v;
    cin >> n >> m >> s >> v;
    vector <Edge> edges(2 * m);
    vector<double> dist(n, INT32_MIN);
    dist[--s] = v;

    for (int i = 0; i < m; i++) {
        int a, b;
        double rab, cab, rba, cba;
        cin >> a >> b >> rab >> cab >> rba >> cba;
        a--;
        b--;
        edges[2 * i] = Edge(a, b, rab, cab);
        edges[2 * i + 1] = Edge(b, a, rba, cba);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            if (dist[edges[j].a] != INT32_MIN) {
                double newDist = (dist[edges[j].a] - edges[j].cab) *
                                 edges[j].rab;
                if (newDist > 0 && dist[edges[j].b] < newDist) {
                    dist[edges[j].b] = newDist;
                }
            }
        }
    }

    bool isIncreasable = false;

    for (int j = 0; j < edges.size(); j++) {
        if (dist[edges[j].a] != INT32_MIN) {
            double newDist = (dist[edges[j].a] - edges[j].cab) *
                             edges[j].rab;
            if (newDist > 0 && dist[edges[j].b] < newDist) {
                dist[edges[j].b] = newDist;
                isIncreasable = true;
            }
        }
    }

    if (isIncreasable) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

