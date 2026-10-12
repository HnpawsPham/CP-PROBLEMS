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

int sol(){
    int a, b, k;
    string s;
    cin>>a>>b>>k>>s;

    int n = s.length();
    ll cost = 0;

    int pos = n;
    for(int i = n - 2; i >= 0; i--){
        if(i == n - 2 || s[i] != s[i + 1])
            cost += (s[i] == 'A' ? a : b);
        if(cost > k) break;
        pos = i + 1;
    }
    return pos;
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