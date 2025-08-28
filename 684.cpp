#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> bucketIdx(edges.size()+1, 0);
        vector<vector<int>> buckets(edges.size()+1, vector<int>(1));

        for (int i = 1; i <= edges.size(); ++i) buckets[i][0] = i;
        for (int i = 1; i <= edges.size(); ++i) bucketIdx[i] = i;

        for (int i = 0; i < edges.size(); ++i) {
            if (bucketIdx[edges[i][0]] == bucketIdx[edges[i][1]]) {
                return edges[i];
            } else {
                int u = edges[i][0], v = edges[i][1];
                int a = bucketIdx[u], b = bucketIdx[v];
                if (a == b)  return edges[i];

                if (buckets[a].size() < buckets[b].size()) std::swap(a, b);

                for (int j = 0; j < buckets[b].size(); ++j) {
                    buckets[a].push_back(buckets[b][j]);
                    bucketIdx[buckets[b][j]] = a;
                }
            }
        }

        return {};
    }
};
