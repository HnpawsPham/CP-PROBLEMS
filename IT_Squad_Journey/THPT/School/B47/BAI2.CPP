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
#define taskname "BAI2"

string s;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int n = s.length();
    int i = 0, j = n - 1;
    while(i < n && s[i] == '0') i++;
    while(j >= 0 && s[j] == '0') j--;
    
    int cnt = 0;
    for(int it = i; it <= j; it++)
        if(s[it] == '0') cnt++;

    // cout<<s.substr(i, j - i + 1);
    cout<<cnt;
    return 0;
}

// 000101010000
// 000000100000