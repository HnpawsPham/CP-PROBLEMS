#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    int n = s.length();

    ll lct = 0, l = 0, tprev = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == 'T') tprev++;
        else if(s[i] == 'C') l += tprev;
    }
    ll d = l;

    ll allt = count(s.begin(), s.end(), 'T');

    l = 0;
    ll t = 0, lc = 0, maxc = 0;
    for(int i = 0; i < n; i++){
        ll tr = allt - t;
        maxc = max(maxc, 1LL * l * tr);

        if(s[i] == 'L') l++;
        else if(s[i] == 'C') lc += l;
        else if(s[i] == 'T'){
            lct += lc;
            t++;
        }
    }
    cout<<lct + max({d, maxc, lc});
    return 0;
}