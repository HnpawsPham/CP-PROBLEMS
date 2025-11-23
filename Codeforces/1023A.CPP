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

int n, m;
string s, t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>s>>t;
    if(s == t) return cout<<"YES", 0;
    if(n - 1 > m) return cout<<"NO", 0;

    int l = 0, r = 0;
    bool ok = 0;

    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){
            if(s[i] == '*') {
                ok = 1;
                break;
            }
            else return cout<<"NO", 0;
        }
        l++;
    }

    for(int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--, j--){
        if(s[i] != t[j]){
            if(s[i] == '*') break; 
            else return cout<<"NO", 0;
        }
        r++;
    }

    if(ok && l + r <= m) cout<<"YES";
    else cout<<"NO";
    return 0;
}