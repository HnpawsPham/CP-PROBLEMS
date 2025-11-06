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
    int n = s.length();
    
    int maxx = sum(x);
    ll res = x;

    for(int i = 0; i < n; i++){
        string tmp = s;
        tmp[i] = tmp[i] - '0' - 1 + '0';
        for(int j = i + 1; j < n; j++)
            tmp[j] = '9';
        
        ll cur = stoll(tmp);
        int ssum = sum(cur);
        if(ssum > maxx || (ssum == maxx && cur > res)){
            maxx = ssum;
            res = cur;
        }
    }
    cout<<res;
    return 0;
}

// 39188