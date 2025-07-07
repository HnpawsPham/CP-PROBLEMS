#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>

struct comp{
    bool operator()(const vi& a, const vi& b){
        return a[1] > b[1];
    }
};

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<vi> a(n);
    int maxx = 0;
    for(int i = 0; i < n; i++){
        int l, r;
        cin>>l>>r;
        a[i] = {l, r};
        maxx = max(maxx, r);
    }

    sort(a.begin(), a.end());

    priority_queue<vi, vector<vi>, comp> pq;
    int cnt = 0, j = 0;

    for(int i = 1; i <= maxx; i++){
        while(j < n && a[j][0] == i){
            pq.push(a[j]);
            j++;
        }

        while(!pq.empty() && pq.top()[1] < i) 
            pq.pop();
        
        if(!pq.empty()){
            cnt++;
            pq.pop();
        }
    }
    cout<<cnt;
    return 0;
}