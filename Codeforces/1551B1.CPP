#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc = 1;

int sol(){
    string s;
    cin>>s;
    int check[26] = {0};

    int red = 0, green = 0;
    for(char x : s){
        if(check[x - 'a'] == 0) red++;
        else if(check[x - 'a'] == 1) green++;
        check[x - 'a']++;
    }
    return (red + green) / 2;
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