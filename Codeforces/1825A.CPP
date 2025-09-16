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
    string s;
    cin>>s;
    int cnt[26] = {0};
    for(char x : s) cnt[x - 'a']++;

    int d = 0;
    for(int i = 0; i < 26; i++)
        d += (cnt[i] > 0);

    return (d > 1 ? s.length() - 1 : -1);
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