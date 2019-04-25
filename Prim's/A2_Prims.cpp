#include<bits/stdc++.h>

using namespace std;

struct node {
    int id;
    int key;
    int par;

    node(int _id, int _key, int _par) {
        id = _id;
        key = _key;
        par = _par;
    }

    bool operator <(node a) const {
        return key > a.key;
    }
};

int main() {
    priority_queue<node> PQ;

    PQ.push(node(1, 20, 0));
    PQ.push(node(2, 30, 0));
    PQ.push(node(3, 10, 0));
    PQ.push(node(4, 100, 0));
    PQ.push(node(5, 50, 0));

    while(!PQ.empty()) {
        node u = PQ.top();
        PQ.pop();

        cout << u.id << " " << u.key << endl;
    }
}

















