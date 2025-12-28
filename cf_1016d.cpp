#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int q; cin >> q;

        vector<array<int, 2>> nic;
        vector<int> cfn;

        for (int i = 0; i < q; ++i) {
            string op;
            cin >> op;

            if (op == "->") {
                int x, y;
                cin >> x >> y;
                nic.push_back({x, y});
            } else if (op == "<-") {
                int x;
                cin >> x;
                cfn.push_back(x);
            }
        }

        for (int i = 0; i < cfn.size(); ++i) {
            int y = 0, x = 0;
            int msb = 31 - __builtin_clz(cfn[i]);
            int pairs = (msb + 1) / 2;

            int iter = 0;

            while (iter < pairs) {
                int idx = ((cfn[i] - 1) >> (iter*2)) & 3;

                switch(idx) {
                    case 0: {
                        x += (1 << (iter - 1)) - 1;
                        y += (1 << (iter - 1)) - 1;
                        break;
                    }

                    case 1: {
                        x += (1 << (iter + 1)) - 1;
                        y += (1 << (iter + 1)) - 1;
                        break;
                    }


                    case 2: {
                        x += (1 << (iter)) - 1;
                        y += (1 << (iter + 1)) - 1;
                        break;
                    }

                    case 3: {
                        x += (1 << (iter + 1)) - 1;
                        y += (1 << (iter)) - 1;
                        break;
                    }

                    default: break;
                }

                iter += 1;
            }

            cout << y+1 << ' ' << x+1 << '\n';
        }
    }
    return 0;
}
