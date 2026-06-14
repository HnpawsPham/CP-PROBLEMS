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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    string s;
    cin>>n>>d>>s;

    int last = -1, cnt = 0;
    for(int i = 0; i != n - 1;){
        for(int j = 1; j <= d && i + j < n; j++)
            if(s[i + j] == '1') last = i + j;

        if(last <= i) return cout<<-1, 0;
        i = last;
        cnt++;
    }
    cout<<cnt;
    return 0;
}