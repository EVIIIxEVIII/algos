#include <bits/stdc++.h>
using namespace std;

struct Node {
    array<Node*, 26> next;
    Node() {
        next.fill(nullptr);
    }
};

int main() {
    vector<string> strs1 = { "helloworld", "hellocountry", "something" };
    vector<string> strs2 = { "helloworld", "hellocountry", "something" };

    Node* root = new Node();
    for (auto& s : strs1) {
        Node* cur = root;
        for (char c : s) {
            if (cur->next[c-'a'] == nullptr) {
                cur->next[c-'a'] = new Node();
            }
            cur = cur->next[c-'a'];
        }
    }
}
