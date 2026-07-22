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
int t[maxn] = {0}, sum[maxn / 2] = {0};
int sz;

void build(int i, int l, int r){
    if(l == r){
        t[i] == sum[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    t[i] = max(t[2 * i], t[2 * i + 1]);
    return;
}

int get(int i, int st, int en, int l, int r){
    if(st > r || en < l) return 0;
    if(st >= l && en <= r) return t[i];

    int mid = (l + r) / 2;
    return max(get(2 * i, st, mid, l, r), get(2 * i + 1, mid + 1, en, l, r));
}

int query(int l, int r){
    if(l <= r) return get(1, 0, sz - 1, l, r);
    return 0;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    string s;
    cin>>s>>k;
    vector<vi> q(k, vi(2));
    for(int i = 0; i < k; i++)
        cin>>q[i][0]>>q[i][1];

    int n = s.length();
    int cnt1 = 0;
    for(const char& x : s)
        cnt1 += x == '1';

    vi sz0, posl, posr;
    for(int i = 0; i < n;){
        int st = i;
        while(i < n && s[st] == s[i]) i++;

        if(s[st] == '0'){
            sz0.push_back(i - st);
            posl.push_back(st);
            posr.push_back(i - 1);
        }
    }

    int m = sz0.size();
    if(m < 2){
        for(int i = 0; i < k; i++) 
            cout<<cnt1<<" ";
        return 0; 
    }

    sz = m - 1;
    for(int i = 0; i < sz; i++)
        sum[i] = sz0[i] + sz0[i + 1];

    build(1, 0, sz - 1);
    vi res;
    for(const vi& v : q){
        int l = v[0], r = v[1];
        int i = lower_bound(posr.begin(), posr.end(), l) - posr.begin();
        int j = upper_bound(posl.begin(), posl.end(), r) - posl.begin() - 1;

        if(i > m - 1 || j < 0 || i >= j){
            res.push_back(cnt1);
            continue;
        }

        int lenl = posr[i] - max(posl[i], l) + 1;
        int lenr = min(posr[j], r) - posl[j] + 1;

        if(i + 1 == j) //only 2
            res.push_back(cnt1 + lenl + lenr);
        else{ // > 2 block 0
            int d = max(lenl + sz0[i + 1], max(sz0[j - 1] + lenr, query(i + 1, j - 2)));
            res.push_back(cnt1 + d);
        }    
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}

// 01
// 1
// 0 1
