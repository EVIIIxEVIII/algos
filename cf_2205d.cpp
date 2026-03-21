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
    // the array will be either of size 3 or size 4

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // the final array will be decreasing first then increasing again,
    // such that in the end the maximum values are either at a[0] or a[n-1] where n is the number
    // of numbers left. This is because for every value a[i] the value at a[i+1] or a[i-1] must be greater than
    // it and then by induction we can prove that either a[0] is the maximum or a[n-1] is the maximum.

    // the maximum number a[i] cannot be removed from the array and can be either placed at the end or the start.

    // if we choose to put a[i] at the start then the next few elements must be in decreasing order, and ascending order
    // if a[i] is placed at the end.

    // if we split the array into 2 parts: the left on and the right one based on the position of the maximum then the maximum
    // in those subarrays can be used as either the start/end or all the elemtents between the local maximum and the global maximum
    // must be removed.

    // if we want to keep an element a[i] to the left of the global maximum, it means that all the elements to right of the global
    // maximum must be removed, also if a[i] is to the left of
    //

    // for every a[i] check: is it to the left of the global maximum or to the rigth, if it is to the left => everything to the rigth
    // must be removed WLOG. Then find the maximum of this new left side and check if a[i] is to the left or to the right of the local
    // maximum, if it is to the left then everything between the local maximum and the global maximum must be removed or everything
    // from the start to the local maximum must be removed depending on the side which was chosen in the global maximum. The splitting
    // implies a log(n) complexity and this has to be done per element, so nlog(n), which allows us to count the number of elements that
    // have to be removed to obtain a correct array. We can find the minimum value in a[].

    vector<pair<int, int>> graph(n+1, {0, 0});

    stack<int> s;
    for (int i = 0; i < n; ++i) {
        int prev = 0;

        while (!s.empty() && a[s.top()] < a[i]) {
            prev = a[s.top()];
            s.pop();
        }

        graph[a[i]].first = prev;

        if (!s.empty()) {
            graph[a[s.top()]].second = a[i];
        }

        s.push(i);
    }

    int root = n;

    auto max_depth = [&](auto&& self, int v, int depth) -> int {
        int ans = depth;
        if (graph[v].first != 0) {
            ans = max(ans, self(self, graph[v].first, depth + 1));
        }

        if (graph[v].second != 0) {
            ans = max(ans, self(self, graph[v].second, depth + 1));
        }

        return ans;
    };

    cout << n - max_depth(max_depth, root, 1) << '\n';
}
