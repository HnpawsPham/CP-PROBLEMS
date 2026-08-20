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

const int maxn = 1e5 + 5;

struct BIT{
    int t[maxn];

    BIT(){
        memset(t, 0, sizeof t);
    }

    void add(int i, int val){
        while(i < maxn){
            t[i] += val;
            i += (i & -i);
        }
    }

    int query(int i){
        int res = 0;
        while(i > 0){
            res += t[i];
            i -= (i & -i);
        }
        return res;
    }
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vi p(n);
    for(int i = 0; i < n; i++) cin>>p[i];

    vi v = p;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int pos[n];
    for(int i = 0; i < n; i++)
        pos[i] = lower_bound(v.begin(), v.end(), p[i]) - v.begin() + 1;

    vi a = {p[0]}, b = {p[1]};
    BIT ta, tb;
    
    ta.add(pos[0], 1);
    tb.add(pos[1], 1);

    int sza = 0, szb = 0;
    for(int i = 2; i < n; i++){
        if(sza- ta.query(pos[i]) > szb - tb.query(pos[i])){
            a.push_back(p[i]);
            sza++;
            ta.add(pos[i], 1);
        }
        else if(sza - ta.query(pos[i]) < szb - tb.query(pos[i])){
            b.push_back(p[i]);
            szb++;
            tb.add(pos[i], 1);
        }
        else{
            if(sza <= szb){
                a.push_back(p[i]);
                ta.add(pos[i], 1);
                sza++;
            }
            else{
                b.push_back(p[i]);
                tb.add(pos[i], 1);
                szb++;
            }
        }
    }

    for(const int& x : b)
        a.push_back(x);

    for(const int& x : a)
        cout<<x<<" ";
    return 0;
}

// 4
// 2 1 3 3