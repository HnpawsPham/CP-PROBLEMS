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

int n, m;
const int maxn = 105;
string a[maxn], s;
unordered_map<string, array<int, 3>> mp;
int maxx[3] = {0}, maxcnt[3] = {0};

// 0: taxi, 1: pizza, 2: girl
int type(const string& s){
    int d = 0, prev = 10;
    bitset<10> check;
    bool decrease = 1;

    for(const char& x : s){
        if(x == '-') continue;

        if(!check[x - '0']) d++;
        check[x - '0'] = 1; 

        if(x - '0' >= prev) decrease = 0;
        prev = x - '0';
    }

    if(d == 1) return 0;
    if(decrease) return 1;
    return 2;
}

void print(int type){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(mp[a[i]][type] != maxx[type]) continue;
        cout<<a[i];
        cnt++;

        if((maxcnt[type] == 0 && i < n - 1) || (maxcnt[type] > 0 && cnt < maxcnt[type]))
            cout<<", "; 
    }
    cout<<"."<<el;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>m>>a[i];
        while(m--){
            cin>>s;
            int stype = type(s);
            mp[a[i]][stype]++;

            if(maxx[stype] < mp[a[i]][stype]){
                maxx[stype] = mp[a[i]][stype];
                maxcnt[stype] = 1;
            }
            else if(maxx[stype] == mp[a[i]][stype]) maxcnt[stype]++;            
        }
    }

    cout<<"If you want to call a taxi, you should call: ";
    print(0);
    cout<<"If you want to order a pizza, you should call: ";
    print(1);
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
    print(2);
    return 0;
}