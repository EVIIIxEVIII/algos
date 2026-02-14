#include <bits/stdc++.h>
using namespace std;


int find_ttff(const vector<int>& set, auto condition) {
    int l = 0;
    int r = set.size() - 1;

    if (!condition(set[l])) return -1;

    while (l < r) {
        int m = l + (r - l + 1) / 2;
        if (condition(set[m])) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    return l;
}

int find_fftt(const vector<int>& set, auto condition) {
    int l = 0;
    int r = set.size() - 1;

    if (!condition(set[r])) return -1;

    while (l < r) {
        int m = l + (r - l) / 2;
        if (condition(set[m])) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    return r;
}

int find_exact(const vector<int>& set, int target) {
    int l = 0;
    int r = set.size() - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (target > set[m]) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return l >= 0 && l <= set.size() - 1 && set[l] == target ? l : -1;
}


