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
#define taskname ""

int main(){
    #ifdef taskname
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin>>n>>s;

    for(int i = 0; i < n / 2; i++){
        int j = n / 2 + i;
        while(j < n && s[j] == '-') j++;

        if(s[i] == 'R') cout<<j + 1<<" "<<i + 1<<el;
        else cout<<i + 1<<" "<<j + 1<<el;
        s[i] = s[j] = '-';
    }
    return 0;
}