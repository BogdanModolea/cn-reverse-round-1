#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int nr_gr(int n) {
    int g, k;
    g = sqrt(n);
    if (sqrt(n) != (int) sqrt(n)) g++;
    k = n - (g - 1) * (g - 1);
    return min(g, k);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    cout << nr_gr(n);
    return 0;
}
