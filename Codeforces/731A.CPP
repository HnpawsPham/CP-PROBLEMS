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
    int p = 0;

    int cnt = 0;
    for(char x : s){
        int i = x - 'a';
        cnt += min(abs(p - i), 26 - abs(p - i));
        p = i;
    }
    cout<<cnt;
    return 0;
}