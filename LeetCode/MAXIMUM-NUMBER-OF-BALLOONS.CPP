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

    int cntb = 0, cnta = 0, cntl = 0, cnto = 0, cntn = 0;
    for(const char& x : s){
        if(x == 'b') cntb++;
        if(x == 'a') cnta++;
        if(x == 'l') cntl++;
        if(x == 'o') cnto++;
        if(x == 'n') cntn++;
    }
    cout<<min({cntb, cnta, cntl / 2, cnto / 2, cntn});
    return 0;
}