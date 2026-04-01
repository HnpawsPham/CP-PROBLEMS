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

struct robot{
    int pos, idx, w;
    char dir;
    robot() {};
    robot(int pos1, int idx1, int w1, char dir1) : pos(pos1), idx(idx1), w(w1), dir(dir1) {};

    bool operator<(const robot& other){
        return pos < other.pos;
    }
};

bool comp(const robot& a, const robot& b){
    return a.idx < b.idx;
}

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
    int pos[n], w[n];
    string s;
    for(int i = 0; i < n; i++) cin>>pos[i];
    for(int i = 0; i < n; i++) cin>>w[i];
    cin>>s;

    vector<robot> a;
    for(int i = 0; i < n; i++)
        a.push_back({pos[i], i, w[i], s[i]});
    sort(a.begin(), a.end());

    stack<int> st;
    vector<robot> alive;
    for(int i = 0; i < n; i++){
        if(a[i].dir == 'R'){
            st.push(i);
            continue;
        }

        bool ok = 1;
        if(!st.empty())
            while(!st.empty() && ok){
                if(a[i].w <= a[st.top()].w) ok = 0;
                if(a[st.top()].w <= a[i].w){
                    st.pop();
                    a[i].w--;
                }
                else a[st.top()].w--;
            }

        if(st.empty() && ok) alive.push_back(a[i]);
    }

    while(!st.empty()){
        alive.push_back(a[st.top()]);
        st.pop();
    }

    sort(alive.begin(), alive.end(), comp);
    vi res;
    for(const robot& x : alive)
        res.push_back(x.w);

    for(int x : res) cout<<x<<" ";
    return 0;
}

// 5
// 5 4 3 2 1
// 2 17 9 15 10
// RRRRR

// 4
// 3 5 2 6
// 10 10 15 12
// RLRL

// 4
// 1 2 5 6
// 10 10 11 11
// RLRL