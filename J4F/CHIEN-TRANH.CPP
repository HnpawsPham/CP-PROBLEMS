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

    int n, m, k;
    cin>>n>>m>>k;
    int a[m];
    for(int i = 0; i < m; i++) cin>>a[i];

    int cur; 
    cin>>cur;

    int cnt = 0;
    for(int i = 0; i < m; i++)
        if(__builtin_popcount(cur ^ a[i]) <= k) cnt++;

    cout<<cnt;
    return 0;
}