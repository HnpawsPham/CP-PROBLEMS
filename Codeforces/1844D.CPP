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

string sol(){
    int n;
    cin>>n;

    if(n == 1) return "a";
    if(n == 2) return "ab";

    int en = 0;
    for(int i = 1; i < n; i++)
        if(n % i){
            en = i;
            break;
        }
    
    string s;
    for(int i = 0; i < n; i++)
        s.push_back(char((i % en) + 'a'));
    return s;
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