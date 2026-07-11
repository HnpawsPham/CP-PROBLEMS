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

bool valid(int i, int l, int r){
    return (i >= l && i <= r);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    string t;
    cin>>n>>q>>t;

    while(q--){
        int l, r;
        cin>>l>>r;
        l--; r--;

        string s = t;
        int i = l, dir = 1;
        int cnt[10] = {0};
        bool del[n] = {0};

        while(valid(i, l, r)){
            if(del[i]){
                i += dir;
                continue;
            }

            if('0' <= s[i] && s[i] <= '9'){
                cnt[s[i] - '0']++;
                if(s[i] == '0') del[i] = 1;
                else s[i]--;
            }
            else{
                if(s[i] == '>') dir = 1;
                else dir = -1;

                int next = i + dir;
                while(valid(next, l, r) && del[next]) next += dir;

                if(valid(next, l, r) && (s[next] == '<' || s[next] == '>'))
                    del[i] = 1;
            }
            i += dir;
        }

        for(int i = 0; i < 10; i++)
            cout<<cnt[i]<<" ";
        cout<<el;
    }
    return 0;
}