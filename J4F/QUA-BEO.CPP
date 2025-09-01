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

    int n, s, k;
    cin>>n>>s>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 0;
    ll cnt = 0;
    multiset<int> ms;
    for(int r = 0; r < n; r++){
        ms.insert(a[r]);
        
        while(*ms.rbegin() - *ms.begin() > k)
            ms.erase(ms.lower_bound(a[l++]));

        cnt += max(r - l + 1 - s, 0);
    }
    cout<<cnt;
    return 0;
}