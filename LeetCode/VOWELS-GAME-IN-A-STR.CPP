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
    string vow = "aeiou";
    for(const char& x : s) 
        for(const char& y : vow)
            if(x == y) return cout<<"true", 0;

    cout<<"false";
    return 0;
}