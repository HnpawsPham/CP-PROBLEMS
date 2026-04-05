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

    int x = 0, y = 0;
    for(const char& c : s)
        if(c == 'U') y--;
        else if(c == 'D') y++;
        else if(c == 'L') x--;
        else x++;
    cout<<(x == 0 && y == 0);
    return 0;
}