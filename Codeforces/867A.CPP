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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    string s;
    cin>>s;
    int sf = 0, fs = 0;
    for(int i = 1; i < n; i++)
        if(s[i] == 'S' && s[i - 1] == 'F') fs++;
        else if(s[i] == 'F' && s[i - 1] == 'S') sf++;
    cout<<(sf != fs ? "YES" : "NO");
    return 0;
}