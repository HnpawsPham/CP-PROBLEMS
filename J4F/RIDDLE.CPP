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
    int n = s.length();

    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]){
            cnt++;
            continue;
        }

        int j = i + 1;
        while(j < n && s[j] == s[i + 1]) j++;
        if(j < n && s[j] == s[i]) cnt++;
    }
    cout<<cnt;
    return 0;
}