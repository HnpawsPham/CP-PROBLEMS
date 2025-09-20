#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    int res[n];
    res[0] = sqrt(a[0][0]);

    for(int i = 1; i < n; i++)
        res[i] = a[i][0] / res[0];
        
    for(int i = 0; i < n; i++) cout<<res[i]<<" ";
    return 0;
}

// 3
// 1 2 4
// 2 4 8
// 4 8 16