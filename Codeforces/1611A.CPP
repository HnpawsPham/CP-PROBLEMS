#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;

int sol(){
    int n;
    cin>>n;
    if(n % 2 == 0) return 0;
   
    bool first = 1;
    string s = to_string(n);
    int m = s.length();
    for(int i = 0; i < m; i++){
        if(int(s[i] - '0') % 2 == 0) return 2 - first;
        first = 0;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }

    return 0;
}