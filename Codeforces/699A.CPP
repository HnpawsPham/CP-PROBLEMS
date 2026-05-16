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
    string s;
    cin>>n>>s;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    bool hasr = 0, ok = 0;
    for(const char& x : s){
        if(x == 'R') hasr = 1;
        if(x == 'L' && hasr){
            ok = 1;
            break; 
        }
    }
    if(!ok) return cout<<-1, 0;

    int minl = n + 1, minr = n + 1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L' && minr != n + 1) minl = min(minl, i);
        else minr = min(minr, i);
    }
    cout<<(minl - minr + 1) / 2;
    return 0;
}