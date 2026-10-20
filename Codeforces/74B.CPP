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

int n, m, k;
int dx[3] = {-1, 1, 0};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    string dir, s;
    cin.ignore();
    getline(cin, dir);
    cin>>s;

    int d = 1;
    if(dir == "to head") d *= -1;

    unordered_set<int> pos, tmp;
    pos.insert(--m);
    k--;
    int sz = s.length();

    for(int i =0 ; i < sz; i++){
        int prevk = k;
        k += d;
        if(k == 0 || k == n - 1)
            d *= -1;

        if(s[i] == '1'){
            if(i == sz - 1) return cout<<"Stowaway", 0;

            pos.clear();
            for(int j = 0; j < n; j++)
                if(j != k) pos.insert(j);
            continue;
        }

        for(int x : pos)
            for(int j = 0; j < 3; j++){
                if(x + dx[j] < 0 || x + dx[j] == n || x + dx[j] == k) continue;
                if(x == k && x + dx[j] == prevk) continue;
                tmp.insert(x + dx[j]);
            }
        pos = tmp;

        if(pos.empty()){
            cout<<"Controller "<<i + 1;
            return 0;
        }
        tmp.clear();
    }
    cout<<"Stowaway";
    return 0;
}