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

int n, k;
string s;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>s;
    if(k == 0) return cout<<s, 0;
    if(n == 1) return cout<<0, 0;

    for(int i = 0; i < n && k; i++){
        if(i == 0 && s[i] > '1'){
            s[i] = '1';
            k--;
        }
        else if(i > 0 && s[i] > '0'){
            s[i] = '0';
            k--;
        }
    }
    cout<<s;
    return 0;
}