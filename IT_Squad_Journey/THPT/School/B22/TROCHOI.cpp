#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, q;
const int maxn = (int)1e5 + 5;
int a[maxn], b[maxn], p[maxn];

int main(){
    freopen(".\\txt\\TROCHOI.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    p[0] = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        p[i] = a[i] + p[i - 1];
    }
    for(int i = 0; i < n; i++) cin>>b[i];

    int dp[n];
    


    return 0;
}