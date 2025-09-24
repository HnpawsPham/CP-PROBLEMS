#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin>>x>>y;

    unordered_map<ll, int> mp;
    if(x == 0) return cout<<0, 0;

    string res = "";
    if((x < 0) ^ (y < 0)) res += '-';
    
    ll a = llabs(x);
    ll b = llabs(y);

    res += to_string(a / b);
    ll r = a % b;

    if(r == 0) return res;
    res += '.';

    while(r){
        if(mp.count(r)){
            res.insert(mp[r], 1, '(');
            res += ')';
            break;
        }

        mp[r] = res.length();
        r *= 10;
        res += (r / b) + '0';
        r %= b;
    }

    cout<<res;
    return 0;
}   