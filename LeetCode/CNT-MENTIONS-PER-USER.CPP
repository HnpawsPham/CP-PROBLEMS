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
#define vs vector<string>
//#define taskname ""

int getid(const string& s){
    return stoi(s.substr(2));
}

bool comp(const vs& a, const vs& b){
    int ta = stoi(a[1]), tb = stoi(b[1]);
    if(ta != tb) return ta < tb;
    return a[0] == "OFFLINE" && b[0] == "MESSAGE";
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vs> a(m, vs(3));
    for(int i = 0; i < m; i++){
        cin>>a[i][0]>>a[i][1];
        getline(cin, a[i][2]);
        a[i][2].erase(0, 1);
    }

    vi res(n, 0), onl(n, 0);
    sort(a.begin(), a.end(), comp);

    for(const vs& v : a){
        string opt = v[0], tmp = v[2];
        int t = stoi(v[1]);

        if(opt == "MESSAGE"){
            if(tmp[0] == 'i'){
                stringstream ss(tmp);
                string x;

                while(ss >> x)
                    res[getid(x)]++;
            }
            else if(tmp == "HERE"){
                for(int i = 0; i < n; i++)
                    if(onl[i] <= t) res[i]++;
            }
            else{
                for(int i = 0; i < n; i++) 
                    res[i]++;
            }
        }
        else onl[stoi(tmp)] = t + 60;
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 2 3
// MESSAGE 10 id1 id0
// OFFLINE 11 0
// MESSAGE 71 HERE

// 2 2
// OFFLINE 10 0
// MESSAGE 12 HERE