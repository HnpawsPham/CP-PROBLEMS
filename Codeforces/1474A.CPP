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
    string s;
    cin>>n>>s;

    string a = "1";
    for(int i = 1; i < n; i++){
        if((s[i] - '0') + 1 == (a.back() - '0') + (s[i - 1] - '0'))
            a.push_back('0');
        else a.push_back('1');
    }
    return a;
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