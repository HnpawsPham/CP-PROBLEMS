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

    string s;
    cin>>s;

    int n = s.length();
    int cntl = 0, cntr = 0, suml = 0, sumr = 0;
    for(int i = 0; i < n / 2; i++){
        if(s[i] == '?') cntl++;
        else suml += (s[i] - '0');
    }

    for(int i = n / 2; i < n; i++){
        if(s[i] == '?') cntr++;
        else sumr += (s[i] - '0');
    }

    if((cntl + cntr) % 2) 
        return cout<<1, 0;

    if(cntl == cntr)   
        return cout<<(suml != sumr), 0;

    if((cntl > cntr && suml >= sumr)
    || (cntr > cntl && sumr >= suml)) 
        return cout<<1, 0;

    cout<<(min(suml, sumr) + abs(cntr - cntl) / 2 * 9 == max(suml, sumr));
    return 0;
}