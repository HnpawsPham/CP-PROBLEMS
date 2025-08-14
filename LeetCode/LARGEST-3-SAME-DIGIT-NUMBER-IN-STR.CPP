#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.length();
    string res = "";

    int cnt = 0;
    for(int i = 2; i < n; i++){
        if(s[i] == s[i - 1] && s[i] == s[i - 2]) 
            res = max(res, s.substr(i - 2, 3));
    }
    cout<<res;
    return 0;
}