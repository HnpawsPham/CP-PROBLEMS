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

ll x;

int sum(ll n){
    int res = 0;
    while(n > 0){
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>x;
    string s = to_string(x);
    ll t = (s[0] - '0') - 1;
    
    for(int i = 1; i < s.size(); i++)
        t = t * 10 + 9;

    if(sum(t) > sum(x)) cout<<t;
    else cout<<x;
    return 0;
}