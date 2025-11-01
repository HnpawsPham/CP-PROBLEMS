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

    int n;
    cin>>n;
    for(int i = n; ; i++){
        string s = bitset<64>(i).to_string();
        if(__builtin_popcount(i) == s.substr(s.find('1')).length()) 
            return cout<<i, 0;
    }
    return 0;
}