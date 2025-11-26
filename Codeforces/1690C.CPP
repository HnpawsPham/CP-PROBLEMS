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
    int st[n + 1], en[n + 1] = {0};
    for(int i = 1; i <= n; i++) cin>>st[i];
    for(int i = 1; i <= n; i++) cin>>en[i];

    for(int i = 1; i <= n; i++)
        cout<<en[i] - max(st[i], en[i - 1])<<" ";
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