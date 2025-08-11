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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    bool a[n + 1] = {0};
    for(int i = 1; i <= n; i++) cin>>a[i];

    for(int i = k; i <= n; i++)
        if(a[i]) return cout<<i, 0;

    for(int i = 1; i < k; i++)
        if(a[i]) return cout<<i, 0;
    return 0;   
}