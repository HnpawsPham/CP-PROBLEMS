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
    int n;
    string s;
    cin>>n>>s;

    vi a;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            sum += i;
            a.push_back(n - 2 * i - 1);
        }
        else{
            sum += n - i - 1;
            a.push_back(2 * i - n + 1);
        }
    }
    sort(a.begin(), a.end());
 
    for(int i = 0; i < n; i++){
        if(a.back() > 0){
            sum += a.back();
            a.pop_back();
        }
        cout<<sum<<" ";
    }
    return 0;
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
        // cout<<sol()<<el;
        sol();
        cout<<el;
    }
    return 0;
}