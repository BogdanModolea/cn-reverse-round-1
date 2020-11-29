#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, good;
char c[101][101];

void afis(){
    for(int i = 1; i <= n; i++)
        cout << c[i] << "\n";
}

int main() {
    cin >> n; cin.get();
    for(int i = 1; i <= n; i++)
        cin.getline(c[i],101);
    int cnt_last_row = 0, ok;
    int cnt_up_1 = 0, cnt_now_1 = 0;
    int cnt_up_2 = 0, cnt_now_2 = 0;
    for(int i = 0; i < 5; i++){
        if(c[n][i] == '0') cnt_last_row++;
        if((i == 0 || i == 1) && c[n][i] == '0'){
            cnt_up_1++;
            cnt_now_1++;
        }
        else if((i == 3 || i == 4) && c[n][i] == '0'){
            cnt_up_2++;
            cnt_now_2++;
        }
        if(c[n][2] == '0') ok =1;
    }
    if(cnt_last_row == n){
        for(int i = 1; i < n; i++)
            cout << c[i] << "\n";
        for(int i = 0; i <= 4; i++)
            cout << 'L';
    }
    else if(ok){
        if(cnt_now_1 == 2 && cnt_up_1 == 2 && c[n][3] == '0')
            c[n][0] = c[n][1] = c[n][2] = c[n-1][0] = c[n-1][1] = 'L', good = 1;
        else if(cnt_now_2 == 2 && cnt_up_2 == 2 && c[n][1] == '0')
            c[n][3] = c[n][4] = c[n][2] = c[n-1][3] = c[n-1][4] = 'L', good = 1;
        if(good) afis();
    }
    if(!good) cout <<"Trebuie sa astepte urmatorul autobuz";
}

