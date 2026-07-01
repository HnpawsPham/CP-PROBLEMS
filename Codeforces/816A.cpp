#include <bits/stdc++.h>
#include <windows.h>
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


bool check(const string& s){
    string rs = s;
    reverse(rs.begin(), rs.end());
    return rs == s;
}

void update(string& s, int x, int st){
    if(x < 10){
        s[st] = '0';
        s[st + 1] = x + '0';
    }
    else{
        s[st + 1] = x % 10 + '0';
        x /= 10;
        s[st] = x + '0';
    }
    return;
}

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
    
    int cnt = 0;
    while(!check(s)){
        int h = stoi(s.substr(0, 2)), m = stoi(s.substr(3, 2));
        m++;
        
        if(m == 60){
            m = 0;
            h = (h + 1) % 24;
        }

        update(s, h, 0);
        update(s, m, 3);
        cnt++;
    }
    cout<<cnt;
    return 0;
}