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
//#define taskname ""

int tc = 1;

string sol(){
    int n;
    ll k;
    string s;
    cin>>n>>k>>s;

    string res;
    ll cnt1 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') cnt1++;
        else{
            ll tmp = min(cnt1, k);
            k -= tmp;

            res.append(cnt1 - tmp, '1');
            res.push_back('0');

            cnt1 = tmp;
        }
    }
    res.append(cnt1, '1');
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}