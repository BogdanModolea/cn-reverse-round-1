#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,k,a[150][150];

int irelj(int i,int j)
{
    int u, v;
    for (u = 1; u <= a[i][0]; u++)
        for (v = 1; v <= a[j][0]; v++)
            if (a[i][u] == a[j][v])
                return 1;
    return 0;
}

int apartine(int val,int linie)
{
    int j, lg = a[linie][0];
    for (j = 1; j <= lg; j++)
        if (val == a[linie][j])
            return 1;
    return 0;
}

void reuneste(int i,int j)
{
    int u;
    for (u = 1; u <= a[j][0]; u++)
        if (!apartine(a[j][u], i)) {
            a[i][0]++;
            a[i][a[i][0]] = a[j][u];
        }
}

int main() {
    int viz[150], viz2[150], i, j, val, ok;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= k; j++) {
            cin >> val;
            if (!apartine(val, i)) {
                a[i][0]++;
                a[i][a[i][0]] = val;
            }
        }
    for (i = 1; i <= n; i++)
        viz[i] = i;
    for (i = 1; i <= n; i++) {
        ok = 0;
        if (a[i][0]) {
            for (j = i + 1; j <= n; j++)
                if (irelj(i, j)) {
                    viz[j] = viz[i];
                    reuneste(i, j);
                    a[j][0] = 0;
                    ok = 1;
                }
        }
        if (ok) i--;
    }
    for(i=1;i<=n;i++)
        viz2[i]=viz[i];
    int cnt = 0, ans = 0;
    for (i = 1; i <= n; i++) {
        cnt = 0;
        if (viz[i]) {
            cnt++;
            for (j = i + 1; j <= n; j++) {
                if (viz[i] == viz[j]) {
                    cnt++;
                    viz[j] = 0;
                }
            }
        }
        if (cnt == 1) ans++;
    }
    ok = 0;
    cout << ans << "\n";
    for (i = 1; i <= n; i++) {
        if (viz2[i]) {
            cout << i << " ";
            for (j = i + 1; j <= n; j++)
                if (viz2[i] == viz2[j]) {
                    cout << j << " ";
                    viz2[j] = 0;
                }
            cout << "\n";
        }
    }
    return 0;
}