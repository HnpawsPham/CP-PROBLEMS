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
    int cnt0 = 0, cnt1 = 0;
    for(const char& x : s){
        cnt0 += (x == '0');
        cnt1 += (x == '1');
    }

    for(int i = (1 << cnt1); i <= (1 << n) - (1 << cnt0) + 1 ;i++) 
        cout<<i<<" ";
    return 0;
}