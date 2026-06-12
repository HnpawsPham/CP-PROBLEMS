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
int m;

ll calc(int center, const vi& pos){
    ll sum = 0;
    for(int i = 0; i < m; i++)
        sum += abs(pos[i] - pos[center] - i + center);
    return sum;
}

ll sol(){
    int n;
    string s;
    cin>>n>>s;

    vi pos;
    for(int i = 0; i < n; i++)
        if(s[i] == '*') pos.push_back(i);

    m = pos.size();
    if(m & 1) return calc(m / 2, pos);
    return min(calc(m / 2, pos), calc((m + 1) / 2, pos)); 
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