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
    int x;
    cin>>x;
    
    string s = bitset<31>(x).to_string();
    string res = "";
    for(int i = 0; i < 31; i++)
        res.push_back('0');

    int cnt1 = 0;
    for(int i = 0; i < 31; i++)
        if(s[i] == '1') cnt1++;

    for(int i = 30; i >= 0; i--)
        if(s[i] == '1'){
            res[i] = '1';
            break;
        }

    if(cnt1 == 1){
        for(int i = 30; i >= 0; i--)
            if(res[i] == '0'){
                res[i] = '1';
                break;
            }
    }
    return bitset<31>(res).to_ulong();
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