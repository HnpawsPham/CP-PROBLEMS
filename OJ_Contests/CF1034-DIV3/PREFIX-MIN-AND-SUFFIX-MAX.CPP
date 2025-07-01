#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++) cin>>a[i];

        int l[n], r[n];
        l[0] = a[0];
        r[n - 1] = a[n - 1];
        for(int i = 1; i < n; i++) 
            l[i] = min(l[i - 1], a[i]);
        
        for(int i = n - 2; i >= 0; i--)
            r[i] = max(r[i + 1], a[i]);

        for(int i = 0; i < n; i++)
            if(l[i] == a[i] || r[i] == a[i]) cout<<1;
            else cout<<0;
        cout<<el;
    }

    return 0;
}