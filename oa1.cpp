#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    struct Node {
        array<Node*, 10> children;
        Node() {
            children.fill(nullptr);
        }
    };

    Node tree;

    for (int i = 0; i < n; ++i) {
        int num = a[i];
        int exp = 1;

        while (num > 0) {
            num /= 10;
            exp *= 10;
        }
        exp /= 10;

        num = a[i];
        Node* curr = &tree;

        while (exp > 0) {
            int digit = num / exp;
            num %= exp;
            exp /= 10;

            if (curr->children[digit] == nullptr) {
                curr->children[digit] = new Node();
            }
            curr = curr->children[digit];
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int num = b[i];
        int exp = 1;

        while (num > 0) {
            num /= 10;
            exp *= 10;
        }
        exp /= 10;

        num = b[i];

        long long local = 0;
        Node* curr = &tree;

        while (exp > 0) {
            int digit = num / exp;
            num %= exp;
            exp /= 10;

            if (curr->children[digit] != nullptr) {
                curr = curr->children[digit];
                local++;
            } else break;
        }

        ans = max(local, ans);
    }

    cout << ans << '\n';
}
