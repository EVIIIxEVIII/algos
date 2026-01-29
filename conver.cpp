#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main () {


    // exercise 4:

    char type;
    cin >> type;

    if (type == 'b') {
        string bin;
        cin >> bin;

        int n = bin.size();

        long long ans = 0;

        for (int i = n-1; i >= 0; --i) {
            if (bin[i] == '1') {
                ans |= 1 << (n - 1 - i);
            }
        }

        cout << ans << '\n';
    } else if (type == 'h') {
        string hex;
        cin >> hex;

        int n = hex.size();
        std::array<char, 16> map = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        std::string ans_h;

        for (int i = n-1; i >= 3; i-=4) {
            int b1 = hex[i] == '1' ? 1 : 0;
            int b2 = hex[i-1] == '1' ? 1 : 0;
            int b3 = hex[i-2] == '1' ? 1 : 0;
            int b4 = hex[i-3] == '1' ? 1 : 0;

            int idx = (b1 << 0) | (b2 << 1) | (b3 << 2) | (b4 << 3);
            ans_h.push_back(map[idx]);
        }

        std::reverse(ans_h.begin(), ans_h.end());

        cout << ans_h;
    } else if (type == 'c') {
        array<char, 16> map = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

        string hex;
        cin >> hex;

        int n = hex.size();
        string ans;

        for (int i = 0; i < n; ++i) {


        }

        //
    }




    return 0;
}
