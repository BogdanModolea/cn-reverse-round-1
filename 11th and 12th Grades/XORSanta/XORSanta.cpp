#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll countValues(ll n) {
    ll unset_bits = 0;
    while (n) {
        if ((n & 1) == 0)
            unset_bits++;
        n = n >> 1;
    }
    return 1 << unset_bits;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin >> n;
    cout << countValues(n);
    return 0;
}

