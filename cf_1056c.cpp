#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }


        // if I have a number a[i] at the end of the vector, then there must be at least a[i]-1 L values
        // in the array and I have to have at least a[0]-1 Rs in the vector. Does that help me?
        //
        // if a[n-1] + a[0] - 2 > n, it means that the sum of L values and R values is not compatible with the array size, so 0.
        // I will continue tomorrow

        // Submited not to lose my streak

        cout << "I don't know yet" << '\n';
    }
    return 0;
}
