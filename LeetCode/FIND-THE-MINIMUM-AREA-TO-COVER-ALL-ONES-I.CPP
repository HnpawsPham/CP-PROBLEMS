#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    // int sr, tr, sc, tc;
    // bool run = 1;

    // for(int i = 0; i < n && run; i++)
    //     for(int j = 0; j < m; j++)
    //         if(a[i][j]){
    //             sr = i;
    //             run = 0;
    //             break;
    //         }

    // run = 1;
    // for(int j = 0; j < m && run; j++) 
    //     for(int i = 0; i < n; i++)
    //         if(a[i][j]){
    //             sc = j;
    //             run = 0;
    //             break;
    //         }
    
    // run = 1;
    // for(int i = n - 1; i >= 0 && run; i--) 
    //     for(int j = 0; j < m; j++)
    //         if(a[i][j]){
    //             tr = i;
    //             run = 0;
    //             break;
    //         }

    // run = 1;
    // for(int j = m - 1; j >= 0 && run; j--)
    //     for(int i = 0; i < n; i++)
    //         if(a[i][j]){
    //             tc = j;
    //             run = 0;
    //             break;
    //         }

    int sr = n, tr = 0, sc = m, tc = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j]){
                sr = min(sr, i);
                tr = max(tr, i);
                sc = min(sc, j);
                tc = max(tc, j);
            }

    // cout<<sr<<" "<<tr<<" "<<sc<<" "<<tc;
    cout<<(tr - sr + 1) * (tc - sc + 1);
    return 0;
}

// 2 3
// 0 1 0
// 1 0 1

// 2 2
// 1 0
// 0 0