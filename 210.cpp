#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> children(numCourses, vector<int>(0));
        vector<int> degrees(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); ++i) {
            int child = prerequisites[i][0];
            int parent = prerequisites[i][1];

            children[parent].push_back(child);
            degrees[child]++;
        }

        queue<int> bfs;
        for (int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0) {
                bfs.push(i);
            }
        }

        if (bfs.size() == 0) {
            return {};
        }

        vector<int> ans;
        vector<bool> vis(numCourses, false);

        while (bfs.size() > 0) {
            int parent = bfs.front(); bfs.pop();
            vector<int> nodeChildren = children[parent];
            ans.push_back(parent);

            for (int j = 0; j < nodeChildren.size(); ++j) {
                if(--degrees[nodeChildren[j]] == 0) {
                    bfs.push(nodeChildren[j]);
                }
            }
        }

        if (ans.size() != numCourses) return {};
        return ans;
    }
};
