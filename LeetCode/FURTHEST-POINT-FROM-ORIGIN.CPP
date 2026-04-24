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

    string s;
    cin>>s;
    int n = s.length();
    int cntl = 0, cntr = 0;
    for(const char& x : s){
        if(x == 'L') cntl++;
        else if(x == 'R') cntr++;
    }

    if(cntl > cntr) return cout<<n - 2 * cntr;
    cout<<n - 2 * cntl;
    return 0;
}