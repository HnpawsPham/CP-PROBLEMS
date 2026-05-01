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

    int n = s.size(), i = 0;    
    vi a = {-1};

    while(i < n){
        int it = s.find("bear", i);
        if(it != string::npos){
            a.push_back(it);
            i += 4;
        }
        else i++;
    }

    ll cnt = 0;
    int m = a.size();

    for(int i = 1; i < m; i++){
        int l = a[i] - a[i - 1], r = n - a[i] - 3;
        //cout<<l<<" "<<r<<el;
        cnt += 1LL * l * r;
    }
    cout<<cnt;
    return 0;
}