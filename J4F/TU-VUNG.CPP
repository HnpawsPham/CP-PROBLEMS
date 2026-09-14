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
#define taskname "CAU4"

bool isVow(char x){
    return (x == 'a' || x == 'e' || x == 'o' || x == 'i' || x == 'u');
}

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
    int cntvow = 0, cntcon = 0;

    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(isVow(s[i])){
            cntvow++;
            cnt += cntcon;
        }
        else{
            cntcon++;
            cnt += cntvow;
        }
    }
    cout<<cnt;
    return 0;
}