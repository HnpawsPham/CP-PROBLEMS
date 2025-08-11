#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

string s;
int x;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>x;
    char res;
    if(s == "front"){
        if(x == 1) res = 'L';
        else res = 'R';
    }
    else{
        if(x == 1) res = 'R';
        else res = 'L';
    }
    cout<<res;
    return 0;
}