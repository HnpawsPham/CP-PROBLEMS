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

int tc = 1;

int sol(){
    int n;
    string s;
    cin>>n>>s;

    int res = 0, cnt = 1;
    for(int i = 1; i < n; i++)
        if(s[i] != s[i - 1]){
            if(cnt % 2){
               res++;
                s[i] = (s[i] == '0' ? '1' : '0');
                cnt = 0;
            }
            else cnt = 1;
        }
        else cnt++;
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}