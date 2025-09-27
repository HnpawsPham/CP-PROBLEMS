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

    int n;
    cin>>n;
    vector<vi> a(n, vi(2));
    for(int i = 0; i < n; i++) cin>>a[i][0]>>a[i][1];

    db res = 0.0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int z = j + 1; z < n; z++)
                res = max(res, (db)abs(a[i][0] * (a[j][1] - a[z][1]) + 
                                    a[j][0] * (a[z][1] - a[i][1]) + 
                                    a[z][0] * (a[i][1] - a[j][1])) / 2.0);
    cout<<fixed<<setprecision(5)<<res;
    return 0;
}

// 5
// 0 0
// 0 1
// 1 0
// 0 2
// 2 0