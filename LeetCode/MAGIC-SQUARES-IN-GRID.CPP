#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int n, m;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    bool check[10];
    int cnt = 0;
    for(int i = 0; i + 2 < n; i++)
        for(int j = 0; j + 2 < m; j++){
            memset(check, 0, sizeof check);
            for(int ii = i; ii < i + 3; ii++)
                for(int jj = j; jj < j + 3; jj++){
                    if(!(1 <= a[ii][jj] && a[ii][jj] <= 9) ||check[a[ii][jj]]) goto skip;
                    else check[a[ii][jj]] = 1;
                }

            int sum, tmp;
            for(int ii = i; ii < i + 3; ii++){
                tmp = 0;
                for(int jj = j; jj < j + 3; jj++)
                    tmp += a[ii][jj];

                if(ii == i) sum = tmp;
                else if(tmp != sum) goto skip;
            }

            for(int jj = j; jj < j + 3; jj++){
                tmp = 0;
                for(int ii = i; ii < i + 3; ii++)
                    tmp += a[ii][jj];

                if(tmp != sum) goto skip;
            }

            tmp = a[i + 2][j] + a[i + 1][j + 1] + a[i][j + 2];
            if(tmp != sum) goto skip;

            tmp = a[i][j] + a[i + 1][j + 1] + a[i + 2][j + 2];
            if(tmp == sum) cnt++;
            skip:;
        }
    cout<<cnt;
    return 0;
}

// 3 4
// 4 3 8 4
// 9 5 1 9
// 2 7 6 2