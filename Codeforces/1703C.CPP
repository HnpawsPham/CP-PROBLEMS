#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

int tc = 1;

int sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int i = 0; i < n; i++){
        int m;
        string s;
        cin>>m>>s;
        
        for(const char& x : s){
            if(x == 'D') a[i] = (a[i] + 1) % 10;
            else a[i] = (a[i] - 1 + 10) % 10;
        }
        cout<<a[i]<<" ";
    }
    return 0;
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