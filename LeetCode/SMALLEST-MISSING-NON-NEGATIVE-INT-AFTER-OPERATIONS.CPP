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

    int n, k;
    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt[k] = {0};
    for(int x : a){
        int r = ((x % k) + k) % k; 
        cnt[r]++;
    }

    int res = 0;
    while(res <= n){
        if(!cnt[res % k]--) break;
        res++;
    }
    cout<<res;
    return 0;
}