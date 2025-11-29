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

int tc = 1;

int sol(){
    string s;
    cin>>s;
    int n = s.length();
  
    int res = n + 5;
    for(char c = 'a'; c <= 'z'; c++){
        int maxx = 0, diff = 0, sum = 0;
        for(char x : s){ 
            if(x != c) diff++;
            else{
                maxx = max(maxx, diff);
                diff = 0;
            }
        }

        maxx = max(maxx, diff);
        int cnt = 0;
        while(maxx > 0){
            maxx /= 2;
            cnt++;
        }
        res = min(res, cnt);
    }
    return res;
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