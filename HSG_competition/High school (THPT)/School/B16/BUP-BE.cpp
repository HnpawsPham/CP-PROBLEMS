#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
ll k;

int main(){
    freopen(".\\txt\\BUP-BE.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    ll a[n];
    for(int i = 0;i<n;i++) cin>>a[i];
    sort(a, a + n);

    bool check[n] = {0};
    ll sum = 0, last = -LLONG_MAX;

    for(int i = 0;i<n;i++){
        int pos = lower_bound(a, a + n, a[i] + k) - a;

        while(check[pos] && pos < n) pos++;

        if(pos == n) {
            check[i] = 0;
            continue;
        }

        int pos1 = lower_bound(a, a + n, last + k) - a;

        if(a[pos1] - last < a[pos] - a[i])  swap(pos, pos1);
        check[pos] = 1;
        check[pos1] = 0;
        last = a[pos];
        
        check[i] = 1;
    }
    for(int i = 0;i<n;i++) 
        if(!check[i]) sum += a[i];

    cout<<sum<<el;

    return 0;
}