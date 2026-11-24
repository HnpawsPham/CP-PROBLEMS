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

struct elm{
    int val, cnt, time;
    elm() {};
    elm(int val1, int cnt1, int time1) : val(val1), cnt(cnt1), time(time1) {};

    bool operator<(const elm& other) const {
        if(cnt != other.cnt) return cnt < other.cnt;
        return time < other.time;
    }
};

class FreqStack {
public:
    priority_queue<elm> pq;
    unordered_map<int, int> mp;

    int t;

    FreqStack() {
        t = 0;
        mp.clear();

        while(!pq.empty()) 
            pq.pop();    
    }
    
    void push(int val) {
        mp[val]++;
        pq.push({val, mp[val], t++});
    }
    
    int pop() {
        elm cur = pq.top();
        mp[cur.val]--;
        if(mp[cur.val] == 0)
            mp.erase(cur.val);
        pq.pop();
        return cur.val;
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

    return 0;
}