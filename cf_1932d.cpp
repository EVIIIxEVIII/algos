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
    int n;
    cin >> n;
    char tr;
    cin >> tr;


    int need = 0;
    int trumps = 0;

    vector<pair<int,char>> cards(2*n);

    for (int i = 0; i < 2*n; ++i) {
        int num; char suit;
        cin >> num;
        cin >> suit;

        if (suit == tr) {
            trumps++;
        }

        cards[i] = { num, suit };
    }

    sort(cards.begin(), cards.end(), [&](auto a, auto b) {
        bool at = (a.second == tr);
        bool bt = (b.second == tr);

        if (at != bt) {
            return !at;
        }
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    int cur = 1;

    for (int i = 1; i < 2 * n - trumps; ++i) {
        if (cards[i-1].second == cards[i].second) {
            cur++;
        } else {
            need += (cur % 2);
            cur = 1;
        }
    }

    if (2 * n - trumps > 0) {
        need += (cur % 2);
    }

    if (need > trumps || (trumps - need) % 2) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }

    int t = 2*n - trumps;
    for (int i = 0; i < 2*n-trumps;) {
        string c1;
        string c2;

        if (cards[i].second != cards[i+1].second) {
            c1 = to_string(cards[i].first) + cards[i].second;
            c2 = to_string(cards[t].first) + cards[t].second;

            t++;
            i++;
        } else {
            c1 = to_string(cards[i].first) + cards[i].second;
            c2 = to_string(cards[i+1].first) + cards[i+1].second;

            i += 2;
        }

        cout << c1 << ' ' << c2 << '\n';
    }

    for (int i = t; i < 2*n; i+=2) {
        string c1 = to_string(cards[i].first) + cards[i].second;
        string c2 = to_string(cards[i+1].first) + cards[i+1].second;

        cout << c1 << ' ' << c2 << '\n';
    }
}
