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

struct Task{
    int id, a, b;
    Task(){};
    Task(int id1, int a1, int b1) : id(id1), a(a1), b(b1){};

    bool operator<(const Task& other) const {
        int check1 = a <= b;
        int check2 = other.a <= other.b;

        if(check1 != check2) return check1;
        if(check1) return a < other.a;
        return b > other.b;
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
    Task task[n];
    for(int i = 0; i < n; i++){
        cin>>task[i].a;
        task[i].id = i;
    }
    for(int i = 0; i < n; i++)
        cin>>task[i].b;
    sort(task, task + n);

    int ta = 0, tb = 0;
    for(int i = 0; i < n; i++){
        ta += task[i].a;
        tb = max(ta, tb) + task[i].b;
    }

    cout<<max(ta, tb)<<el;
    for(int i = 0; i < n; i++)
        cout<<task[i].id + 1<<" ";
    return 0;
}