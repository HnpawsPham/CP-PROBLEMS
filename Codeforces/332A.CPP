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

int n;
string s;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    int m = s.length();
    int cnt = 0;

    for(int i =3; i < m; i++){
        if(i % n == 0)
            if(s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3]){
                cnt++;
                s[i] = s[i - 1];
            }
    }
    cout<<cnt;
    return 0;
}