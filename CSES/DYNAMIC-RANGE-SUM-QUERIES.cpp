#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
 
const int maxn = 2 * (int)1e5 + 5;
int n, q, node;
ll a[maxn * 4];
 
void build(){
    for(int i = node - 1; i > 0; i--) a[i] = a[i * 2] + a[i * 2 + 1];
    return;
}
 
void update(int pos, ll val){
    pos += node;
    a[pos] = val;
    
    do{
        pos /= 2;
        a[pos] = a[pos * 2] + a[pos * 2 + 1];
    }
    while(pos > 0);
    return;
}
 
ll sum(int l, int r){
    ll res = 0;
    
    l += node;
    r += node;
    
    while(l <= r){
        if(l % 2 == 1){
            res += a[l];
            l++;
        }
        if(r % 2 == 0){
            res += a[r];
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return res;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>q;
    node = n + (n % 2);
    for(int i = 0; i < n; i++) cin>>a[i + node];
    
    build();
    
    while(q--){
        int c;
        cin>>c;
        
        if(c == 1){
            int k; ll u;
            cin>>k>>u;
            update(k - 1, u);
        }
        else{
            int l, r;
            cin>>l>>r;
            cout<<sum(l - 1, r - 1)<<el;
        }
    }
    
    return 0;
}