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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.length();
    int res = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            while(i < n - 1 && s[i + 1] == '0') i++;
            res += cnt;
        }
        else cnt++;
    }
    cout<<res;
    return 0;
}

// 1001101

// 00111