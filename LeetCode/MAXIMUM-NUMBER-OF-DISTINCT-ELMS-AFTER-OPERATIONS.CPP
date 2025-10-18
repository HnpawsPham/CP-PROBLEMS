#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    ll d = -1e15;
    int res = 0;
    for(int x : a){
        d = max(d, x - k);
        if(d <= x + l){
            d++;
            res++;
        }
    }
    cout<<res;
    return 0;
}

// 6 2
// 1 2 2 3 3 4

// 4 1
// 4 4 4 4