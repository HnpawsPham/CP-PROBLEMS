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

    int dmin = 0, dmax = 0;
    for(const char& x : s){
        if(x == '('){
            dmin++;
            dmax++;
        }
        else if(x == ')'){
            dmin--;
            dmax--;
        }
        else{
            dmin--;
            dmax++;
        }

        if(dmin < 0) dmin = 0;
        if(dmax < 0) return cout<<0, 0;
    }
    cout<<!dmin;
    return 0;
}