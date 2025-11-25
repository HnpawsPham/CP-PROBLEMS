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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin>>k;
    if(k == 2 || k == 5) return cout<<-1, 0;

    ll x = 0;
    for(int i = 1; i <= k; i++){
        x = (x * 10 + 1) % k;
        if(x == 0) return cout<<i, 0;
    }
    cout<<-1;
    return 0;
}