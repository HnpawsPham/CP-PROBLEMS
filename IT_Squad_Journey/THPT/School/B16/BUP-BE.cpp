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
    ll sum = 0, last = 0;

    for(int i = 0;i<n;i++){
        int pos = lower_bound(a, a + n, a[i] + k) - a;

        while(check[pos] && pos < n) pos++;

        if(pos == n) {
            check[i] = 0;
            continue;
        }

        int pos1 = lower_bound(a, a + n, last + k) - a;

        if(a[pos1] - last < a[pos] - a[i] || i == 0) {
            check[pos1] = 1;
            last = a[pos1];
        }
        else{
            check[pos] = check[i] = 1;
            last = a[i];
        }
    }
    for(int i = 0;i<n;i++) 
        if(!check[i]) sum += a[i];

    cout<<sum<<el;

    return 0;
}