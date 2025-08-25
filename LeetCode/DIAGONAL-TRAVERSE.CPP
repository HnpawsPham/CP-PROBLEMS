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

    vi res;
    for(int c = 0; c < m; c++){
        int i = 0, j = c;
        vi tmp;
        while(i < n && j >= 0)
            tmp.push_back(a[i++][j--]);

        if(c % 2 == 0) reverse(tmp.begin(), tmp.end());
        for(int x : tmp) res.push_back(x);
    }

    for(int r = 1; r < n; r++){
        int i = r, j = m - 1;
        vi tmp;
        while(i < n && j >= 0)
            tmp.push_back(a[i++][j--]);

        if((r + m - 1) % 2 == 0) reverse(tmp.begin(), tmp.end());
        for(int x : tmp) res.push_back(x);
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 3 3
// 1 2 3
// 4 5 6
// 7 8 9