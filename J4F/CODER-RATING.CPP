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

struct coder{
    int a, h, id;
    coder(){};
    coder(int a1, int h1, int id1) : a(a1), h(h1), id(id1) {};

    bool operator<(const coder& other) const{
        if(a != other.a) return a < other.a;
        return h < other.h;
    }
};

int n;
const int maxa = 1e5 + 5;
int t[maxa];

void add(int i, int val){
    while(i < maxa){
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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(t, 0, sizeof t);

    coder b[n];
    for(int i = 0; i < n; i++){
        int a, h;
        cin>>a>>h;
        b[i] = {a, h, i};
    }
    sort(b, b + n);

    int res[n];
    for(int i = 0; i < n; i++){
        int j = i + 1;
        while(j < n && b[j].a == b[i].a && b[j].h == b[i].h) j++;

        int cnt = query(b[i].h + 1);
        for(int x = i; x < j; x++)
            res[b[x].id] = cnt;

        for(int x = i; x < j; x++)
            add(b[x].h + 1, 1);
        i = --j;
    }

    for(int i = 0; i < n; i++)
        cout<<res[i]<<el;
    return 0;
}