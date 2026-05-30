#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pci pair<char, int>
#define fi first
#define se second
//#define taskname ""

int tc = 1;

string concat(const char& a, const char& b){
    return {min(a, b), max(a, b)};
}

int sol(){
    int n;
    string s;
    cin>>n>>s;
    
    int res = n - 1;
    for(int i = 0; i < n - 2; i++)
        if(s[i] == s[i + 2]) res--;
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