#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::vector<std::unordered_map<std::string, std::vector<int>>> map;
        int ws = beginWord.size();
        map.resize(ws);

        std::vector<bool> explored(wordList.size(), false);

        for (int i = 0; i < wordList.size(); ++i) {
            std::string str = wordList[i];
            for (int j = 0; j < ws; ++j) {
                std::string key = "";
                for (int k = 0; k < ws; ++k) {
                    if (j == k) continue;
                    key.push_back(str[k]);
                }

                map[j][key].push_back(i);
            }
        }

        std::queue<std::string> bfs;
        bfs.push(beginWord);

        int ans = 0;
        while(true) {
            if (bfs.size() == 0)
                return 0;

            ans++;
            int queueSize = bfs.size();
            for (int i = 0; i < queueSize; ++i) {
                std::string str = bfs.front();

                if (str == endWord) {
                    return ans;
                }

                for (int j = 0; j < ws; ++j) {
                    std::string key = "";
                    for (int k = 0; k < ws; ++k) {
                        if (j != k) {
                            key.push_back(str[k]);
                        }
                    }

                    auto children = map[j][key];
                    for (int k = 0; k < children.size(); ++k) {
                        if (!explored[children[k]]) {
                            bfs.push(wordList[children[k]]);
                            explored[children[k]] = true;
                        }
                    }
                }

                bfs.pop();
            }
        }

    }
};
