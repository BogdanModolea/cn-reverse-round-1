#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char s[101];

char cifra(int nr) {
    if (nr == 2) return 'a';
    else if (nr == 22) return 'b';
    else if (nr == 222) return 'c';
    else if (nr == 3) return 'd';
    else if (nr == 33) return 'e';
    else if (nr == 333) return 'f';
    else if (nr == 4) return 'g';
    else if (nr == 44) return 'h';
    else if (nr == 444) return 'i';
    else if (nr == 5) return 'j';
    else if (nr == 55) return 'k';
    else if (nr == 555) return 'l';
    else if (nr == 6) return 'm';
    else if (nr == 66) return 'n';
    else if (nr == 666) return 'o';
    else if (nr == 7) return 'p';
    else if (nr == 77) return 'q';
    else if (nr == 777) return 'r';
    else if (nr == 7777) return 's';
    else if (nr == 8) return 't';
    else if (nr == 88) return 'u';
    else if (nr == 888) return 'v';
    else if (nr == 9) return 'w';
    else if (nr == 99) return 'x';
    else if (nr == 999) return 'y';
    else return 'z';
}

int main() {
    int i, n;
    cin.get(s, 101);
    n = strlen(s);
    for (i = 0; i < n; i++) {
        int j = i;
        while (s[j + 1] == s[i] && j + 1 < n) j++;
        int cnt = j - i + 1;
        int nr = 0;
        for (int g = 1; g <= cnt; g++)
            nr = nr * 10 + s[i] - '0';
        if (nr == 0) {
            if (cnt == 2) cout << " ";
        } else
            cout << cifra(nr);
        i = j;
    }
    return 0;
}

