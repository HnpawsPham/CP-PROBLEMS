#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;

void sol(){
    int n;
    cin>>n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b, b + n, greater<int>());
    
    for(int x : a)
        if(x == b[0]) cout<<x - b[1]<<" ";
        else cout<<x - b[0]<<" ";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}