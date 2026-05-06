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

struct pos{
    pii tail, head;
    int dir, w; 
    pos() {};
    pos(pii tail1, pii head1, int dir1) : tail(tail1), head(head1), dir(dir1), w(0) {};

    bool operator<(const pos& other) const{
        if(tail != other.tail) return tail < other.tail;
        return head < other.head;
    }
};

int n;
int dy[2] = {1, 0},
    dx[2] = {0, 1};

bool check(int i, int j, const vector<vector<int>>& a){
    return (i >= 0 && i < n && j >= 0 && j < n && !a[i][j]);
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
    vector<vi> a(n, vi(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    queue<pos> q;
    q.push({{0,0}, {0, 1}, 0});
    set<pos> s;

    while(!q.empty()){
        pos cur = q.front();
        q.pop();

        if(cur.tail.fi == n - 1 && cur.tail.se == n - 2 && cur.head.fi == n - 1 && cur.head.se == n - 1)
            return cout<<cur.w, 0;

        for(int x = 0; x < 2; x++){
            pos tmp = cur;
            tmp.head.fi += dy[x];
            tmp.tail.fi += dy[x];
            tmp.head.se += dx[x];
            tmp.tail.se += dx[x];
            tmp.w++;

            if(s.find(tmp) != s.end()) continue;
            if(check(tmp.head.fi, tmp.head.se, a) && check(tmp.tail.fi, tmp.tail.se, a)){
                q.push(tmp);
                s.insert(tmp);
            }
        }

        pos tmp = cur;
        tmp.w++;
        if(tmp.dir == 0 && 
        check(tmp.head.fi + 1, tmp.head.se - 1, a) && 
        check(tmp.head.fi + 1, tmp.head.se, a)){ // clockwise
            tmp.head.fi++;
            tmp.head.se--;
            tmp.dir = 1;
            if(s.find(tmp) != s.end()) continue;
            q.push(tmp);
            s.insert(tmp);
        }
        else if(tmp.dir && 
        check(tmp.head.fi - 1, tmp.head.se + 1, a) && 
        check(tmp.head.fi, tmp.head.se + 1, a)){ // counter clockwise
            tmp.head.fi--;
            tmp.head.se++;
            tmp.dir = 0;
            if(s.find(tmp) != s.end()) continue;
            q.push(tmp);
            s.insert(tmp);
        }
    }
    cout<<-1;
    return 0;
}

// 6
// 0 0 0 0 0 1
// 1 1 0 0 1 0
// 0 0 0 0 1 1
// 0 0 1 0 1 0 
// 0 1 1 0 0 0
// 0 1 1 0 0 0