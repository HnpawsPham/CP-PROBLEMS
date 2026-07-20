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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin>>n>>m>>k;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    while(k--){
        vector<int> tmp;
        tmp.push_back(a[n - 1][m - 1]);
        for(int i = 1; i < n; i++)
            tmp.push_back(a[i - 1][m - 1]);
        
        for(int i = 0; i < n; i++)
            for(int j = m - 1; j > 0; j--)
                a[i][j] = a[i][j - 1];

        for(int i = 0; i < n; i++)
            a[i][0] = tmp[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout<<a[i][j]<<" ";
        cout<<el;
    }
    return 0;
}

// 3 3 1
// 1 2 3
// 4 5 6
// 7 8 9