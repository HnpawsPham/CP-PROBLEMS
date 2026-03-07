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
    cin>> s;

    int n = s.length();
    s += s;

    string fi1, fi0;
    for(int i = 0; i < 2 * n; i++){
        fi1.push_back('1');
        fi0.push_back('0');
        swap(fi1, fi0);
    }
    
    int cnt1 = 0, cnt2 = 0, minn = n + 5;
    for(int i = 0; i < 2 * n; i++){
        if(s[i] != fi1[i]) cnt1++;
        if(s[i] != fi0[i]) cnt2++;

        if(i >= n){
            if(s[i - n] != fi1[i - n]) cnt1--;
            if(s[i - n] != fi0[i - n]) cnt2--;
        }

        if(i >= n - 1)
            minn = min(minn, min(cnt1, cnt2));
    }
    cout<<minn;
    return 0;
}