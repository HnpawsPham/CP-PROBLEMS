#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>

int best(int r, int c, int n, int m, const vector<vi>& a){
    int str = n, enr = r, stc = m, enc = c;
    for(int i = r; i <= n; i++)
        for(int j = c; j <= m; j++)
            if(a[i][j]){
                str = min(str, i);
                enr = max(enr, i);
                stc = min(stc, j);
                enc = max(enc, j);
            }
    if(str > enr || stc > enc) return 0;
    return (enr - str + 1) * (enc - stc + 1);
}

vector<vi> rotate(const vector<vi>& a){
    int n = a.size(), m = a[0].size();
    vector<vi> res(m, vi(n));

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            res[i][n - j - 1] = a[j][i];
    return res;
}

int sol(const vector<vi>& a){
    int res = INT_MAX;
    int n = a.size(), m = a[0].size();

    // [][][]
    for(int i = 0; i < m - 1; i++){
        for(int j = 0; j < m - 1; j++){
            int fi = best(0, 0, n - 1, i, a);
            int se = best(0, i + 1, n - 1, j, a);
            int th = best(0, j + 1, n - 1, m - 1, a);
            res = min(res, fi + se + th);
        }
    }
    // [  ]
    // [][]
    for(int i = 0; i < n - 1; i++){
        int fi = best(0, 0, i, m - 1, a);

        for(int j = 0; j < m - 2; j++){
            int se = best(i + 1, 0, n - 1, j, a);
            int th = best(i + 1, j + 1, n - 1, m - 1, a);
            res = min(res, fi + se + th);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    int res = n * m;
    for(int i = 0; i < 4; i++){
        res = min(res, sol(a));
        a = rotate(a);
    }
    cout<<res;
    return 0;
}

// 2 3
// 1 0 1
// 1 1 1