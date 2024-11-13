#include <bits/stdc++.h>

using namespace std;

long long inf = (long long) 1 << 59;

struct node {
    vector<long long> neighbors;
    long long best;
    long long bestval;
    long long parent;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<node> nodes;
    node start;
    start.best = 0;
    start.bestval = 0;
    start.parent = -1;
    nodes.push_back(start);

    long long n, m;
    cin >> n >> m;

    map<string, long long> to_num;
    to_num["English"] = 0;

    for(long long i = 1; i <= n; i++) {
        string name;
        cin >> name;
        to_num[name] = i;

        node temp;
        temp.best = inf;
        temp.bestval = inf;
        temp.parent = -1;
        nodes.push_back(temp);
    }

    vector<vector<long long>> adj;
    adj.resize(n+1, vector<long long>(n+1, inf));
    for(long long i = 0; i <= n; i++) {
        adj[i][i] = 0;
    }

    for(long long i = 0; i < m; i++) {
        string s1, s2;
        long long dist;
        cin >> s1 >> s2 >> dist;

        nodes[to_num[s1]].neighbors.push_back(to_num[s2]);
        nodes[to_num[s2]].neighbors.push_back(to_num[s1]);
        adj[to_num[s1]][to_num[s2]] = dist;
        adj[to_num[s2]][to_num[s1]] = dist;
    }

    queue<long long> q;
    q.push(0);

    while(!q.empty()) {
        long long curr = q.front();
        q.pop();

        for(auto i : nodes[curr].neighbors) {
            if(nodes[curr].best + 1 < nodes[i].best) {
                nodes[i].best = nodes[curr].best + 1;
                nodes[i].bestval = nodes[curr].bestval + adj[curr][i];
                nodes[i].parent = curr;
                q.push(i);
            }

            // If we can get to a node with the same translations and less money
            else if(nodes[curr].best + 1 == nodes[i].best) {
                if(adj[i][curr] <= adj[i][nodes[i].parent]) {
                    nodes[i].best = nodes[curr].best + 1;
                    nodes[i].bestval = nodes[curr].bestval + adj[curr][i];
                    nodes[i].parent = curr;
                    q.push(i);
                }
            }
        }
    }

    long long total = 0;
    for(long long i = 1; i < nodes.size(); i++) {
        node curr = nodes[i];
        if(curr.best > inf/2) {
            cout << "Impossible" << endl;
            return 0;
        }
        total += adj[curr.parent][i];
    }

    cout << total << endl;
}