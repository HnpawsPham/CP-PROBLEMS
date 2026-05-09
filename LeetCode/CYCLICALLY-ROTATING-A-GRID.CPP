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

void rotate(int u, int d, int l, int r, vector<vi>& a){
    vector<vi> res = a;
    // up
    for(int j = l; j < r; j++)
        res[u][j] = a[u][j + 1];
    res[u][r] = a[u + 1][r];

    // right
    for(int i = u + 1; i < d; i++)
        res[i][r] = a[i + 1][r];
    res[d][r] = a[d][r - 1];

    // left
    for(int i = d; i > u; i--)
        res[i][l] = a[i - 1][l];
    res[u][l] = a[u][l + 1];

    // down
    for(int j = r; j > l; j--)
        res[d][j] = a[d][j - 1];
    res[d][l] = a[d - 1][l];

    a = res;
    return;
}

void print(const vector<vi>& a){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout<<a[i][j]<<" ";
        cout<<el;
    }
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin>>n>>m>>k;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    int u = 0, d = n - 1, l = 0, r = m - 1;
    while(u < d && l < r){
        int sz = 2 * (d - u + 1 + r - l + 1) - 4;
        int t = k % sz;

        while(t--)
            rotate(u, d, l, r, a);
        u++;
        d--;
        l++;
        r--;
    }
    print(a);
    return 0;
}

// 2 2 1
// 40 10
// 30 20