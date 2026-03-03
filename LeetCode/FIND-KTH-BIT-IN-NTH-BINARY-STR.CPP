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

string invert(string s){
    string res(s.rbegin(), s.rend());
    for(char& x : res)
        x ^= 1;
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

    int n, k;
    cin>>n>>k;

    string s = "0";
    for(int i = 1; i < n; i++)
        s = s + '1' + invert(s);
    cout<<s[k - 1];
    return 0;
}