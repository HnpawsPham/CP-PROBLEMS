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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vi> q(m, vi(4));
    for(int i = 0; i < m; i++)
        cin>>q[i][0]>>q[i][1]>>q[i][2]>>q[i][3];

    vector<vi> d(n + 1, vi(n + 1, 0));
    for(const auto& v : q){
        d[v[0]][v[1]]++;
        d[v[0]][v[3] + 1]--;
        d[v[2] + 1][v[1]]--;
        d[v[2] + 1][v[3] + 1]++;
    }

    for(int i = 0; i < n; i++)
        for(int j = 1; j < n; j++)
            d[i][j] += d[i][j - 1];

    for(int j = 0; j < n; j++)
        for(int i = 1; i < n; i++)
            d[i][j] += d[i - 1][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout<<d[i][j]<<" ";
        cout<<el;
    }
    return 0;
}

// 3 2
// 1 1 2 2 
// 0 0 1 1

// 2 1
// 0 0 1 1
