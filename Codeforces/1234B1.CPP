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

int n, k;
const int maxn = 205;
deque<int> a;
set<int> s;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int x;
    for(int i = 0; i < n; i++){
        cin>>x;
        if(!s.count(x)){
            if(a.size() == k){
                s.erase(a.back());
                a.pop_back();
            }
            a.push_front(x);
            s.insert(x);
        }
    }
    cout<<a.size()<<el;
    for(const int& x: a) cout<<x<<" ";
    return 0;
}