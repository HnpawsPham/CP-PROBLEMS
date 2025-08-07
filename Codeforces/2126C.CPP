#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define pii pair<int, int>
#define fi first
#define se second

int t, n, k;

string sol(){
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    int x = a[k], left = a[k];
    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++){
        if(a[i] <= x) continue;
        
        if(a[i] - x > left) return "NO";
        x = a[i];
    }
    return "YES";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<sol()<<el;
    }

    return 0;
}