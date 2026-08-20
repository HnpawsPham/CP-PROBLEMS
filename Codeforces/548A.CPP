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

string s;
int k, sz;

bool check(int l){
    int r = l + sz - 1;

    for(int i = 0; i < sz / 2; i++)
        if(s[l + i] != s[r - i]) return 0;
    return 1;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>s>>k;
    int n = s.length();

    if(n % k) return cout<<"NO", 0;
    sz = n / k;

    for(int i = 0; i < n; i += sz)
        if(!check(i)) return cout<<"NO", 0;
    cout<<"YES";
    return 0;
}