#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void radical(int n, int &x, int &y) {
    x = y = 1;
    int d = 3, p = 0;
    while (n % 2 == 0) {
        n /= 2;
        p++;
    }
    if (p) {
        if (p % 2 == 0) x = x * pow(d, p / 2);
        else {
            y *= d;
            p--;
            if (p) x = x * pow(d, p / 2);
        }
    }
    while (n != 1) {
        p = 0;
        while (n % d == 0) {
            n /= d;
            p++;
        }
        if (p) {
            if (p % 2 == 0) x = x * pow(d, p / 2);
            else {
                y *= d;
                p--;
                if (p) x = x * pow(d, p / 2);
            }
        }
        d += 2;
    }
}


int main() {
    int n, x, y;
    cin >> n;
    radical(n, x, y);
    cout << x << " " << y;
}

