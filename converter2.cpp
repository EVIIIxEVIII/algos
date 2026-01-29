#include <iostream>
#include <string>
#include <algorithm>

std::string to_base(unsigned long long n, unsigned base) {
    if (n == 0)
        return "0";

    std::string digits = "0123456789ABCDEF";
    std::string res;

    while (n > 0) {
        res.push_back(digits[n % base]);
        n /= base;
    }

    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    unsigned long long n;
    std::cin >> n;

    std::cout << "Binary: " << to_base(n, 2) << '\n';
    std::cout << "Octal: " << to_base(n, 8) << '\n';
    std::cout << "Hexadecimal: " << to_base(n, 16) << '\n';
}

