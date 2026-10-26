/*Name: Madhav Verma
Roll No: 25/DA/039*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> bellmanFord(int vertices, vector<vector<int>>& edges, int source) {
        const long long INF = numeric_limits<long long>::max() / 4;
        vector<long long> dist(vertices, INF);

        dist[source] = 0;

        for (int pass = 1; pass <= vertices - 1; pass++) {
            bool updated = false;

            for (const vector<int>& edge : edges) {
                int from = edge[0];
                int to = edge[1];
                long long weight = edge[2];

                if (dist[from] == INF) {
                    continue;
                }

                if (dist[from] + weight < dist[to]) {
                    dist[to] = dist[from] + weight;
                    updated = true;
                }
            }

            if (!updated) {
                break;
            }
        }

        for (const vector<int>& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            long long weight = edge[2];

            if (dist[from] != INF && dist[from] + weight < dist[to]) {
                return {-1};
            }
        }

        return dist;
    }
};

int main() {
    int vertices = 5;

    vector<vector<int>> edges = {
        {0, 1, 5}, {1, 2, 1}, {1, 3, 2},
        {2, 4, 1}, {4, 3, -1}
    };

    Solution sol;

    vector<long long> answer = sol.bellmanFord(vertices, edges, 0);

    for (long long distance : answer) {
        cout << distance << " ";
    }

    return 0;
}