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

    // the number of elements which can be used to remove other elements is fixed and decreases with each move,
    // i.e elements a[i] where a[i] = max{a[i-1], a[i], a[i+1]} when an element is removed the number of options is decreased.

    // the maximum number a[i] cannot be removed from the array and can be either placed at the end or the start.

}
