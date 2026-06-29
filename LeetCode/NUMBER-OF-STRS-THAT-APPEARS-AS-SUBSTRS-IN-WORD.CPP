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
    string a[n], s;
    for(int i = 0; i < n; i++) cin>>a[i];
    cin>>s;

    int cnt = 0;
    for(const string& x : a)
        if(s.find(x) != string::npos) cnt++;
    cout<<cnt;
    return 0;
}

// 4
// a abc bc d
// abc