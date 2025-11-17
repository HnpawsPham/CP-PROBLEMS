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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin>>n>>s;
    int cntl = 0, cntr = 0;
    for(char x : s)
        if(x == '<') cntl++;
        else break;

    for(int i = n - 1; i >= 0; i--)
        if(s[i] == '>') cntr++;
        else break;
    
    cout<<cntl + cntr;
    return 0;
}