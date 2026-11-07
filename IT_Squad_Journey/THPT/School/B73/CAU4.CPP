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
#define taskname "CAU4"

int m, n, s;
const int maxn = 1e5 + 5;
int a[6][maxn];

void sub1(){
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
        mp[a[1][i]]++;

    ll cnt = 0;
    for(int i = 0; i < n; i++)
        if(mp.count(s - a[0][i])) 
            cnt += mp[s - a[0][i]];
    cout<<cnt;
}

void sub2(){
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            mp[a[2][i] + a[3][j]]++;

    ll cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(mp.count(s - a[0][i] - a[1][j]))
                cnt += mp[s - a[0][i] - a[1][j]];
    cout<<cnt;
}

void sub3(){
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            mp[a[3][i] + a[4][j]]++;

    ll cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int z = 0; z < n; z++)
                if(mp.count(s - a[0][i] - a[1][j] - a[2][z]))
                    cnt += mp[s - a[0][i] - a[1][j] - a[2][z]];
    cout<<cnt;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n>>s;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    if(m == 2) sub1();
    else if(m == 4) sub2();
    else if(m == 5) sub3();
    return 0;
}

// 2 3 5
// 1 2 1
// 3 4 4

// 4 10 6
// 0 1 2 3 4 5 6 7 8 9
// 0 1 2 3 4 5 6 7 8 9
// 0 1 2 3 4 5 6 7 8 9
// 0 1 2 3 4 5 6 7 8 9

// 5 2 2
// 1 2
// 1 2
// 1 2
// 1 2
// -2 -2