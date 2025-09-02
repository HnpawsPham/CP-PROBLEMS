#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int oo = 1e9 + 1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int> pq;
    string q;
    while(1){
        getline(cin, q);
        if(q.empty()) break;

        if(q[0] == '-') {
            int maxx = oo;
            if(!pq.empty()) maxx = pq.top();

            while(!pq.empty() && pq.top() == maxx)
                pq.pop();
        }
        else if(pq.size() < 15000) 
            pq.push(stoi(q.substr(1)));
    }

    vi res;
    int prev = oo;
    while(!pq.empty()){
        if(pq.top() != prev) res.push_back(pq.top());
        prev = pq.top();
        pq.pop();
    }

    cout<<res.size()<<el;
    for(const int& x : res) cout<<x<<el;
    return 0;
}