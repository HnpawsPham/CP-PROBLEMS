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

string s;
ll t;
int n;

bool check(ll t, vi& cnt){
    while(t % 2 == 0){
        t /= 2;
        cnt[2]++;
    }

    for(int i = 3; i <= 7; i+=2)
        while(t % i == 0){
            t /= i;
            cnt[i]++;
        }
    return t == 1;
}

void update(int x, vi& cnt, int val){
    if(x == 2 || x == 3 || x == 5 || x == 7)
        cnt[x] += val;

    else if(x == 4) cnt[2] += 2 * val;
    else if(x == 6){
        cnt[2] += val;
        cnt[3] += val;
    }
    else if(x == 8) cnt[2] += 3 * val;
    else if(x == 9) cnt[3] += 2 * val;
}

int getSz(const vi& cnt){
    int c6 = (cnt[3] % 2 && cnt[2] % 3) ? 1 : 0;
    return cnt[3] / 2 + cnt[2] / 3 + cnt[7] + cnt[5] + c6 + (cnt[2] % 3 - c6) / 2 + (cnt[3] % 2 - c6) + (cnt[2] % 3 - c6) % 2;
}


int order[7] = {3, 2, 7, 5, 2, 3, 2};
string add = "9875432";
int con[7] = {2, 3, 1, 1, 2, 1, 1};

string sol(vi cnt, int sz){
    if(getSz(cnt) < sz) return "";

    string res;
    // 9 8 7
    for(int i = 0; i < 3; i++)
        while(cnt[order[i]] >= con[i]){
            cnt[order[i]] -= con[i];
            res.push_back(add[i]);
        }
    // 6
    while(cnt[3] >= 1 && cnt[2] >= 1){
        res.push_back('6');
        cnt[3]--;
        cnt[2]--;
    }
    //5 4 3 2
    for(int i = 3; i < 7; i++)
        while(cnt[order[i]] >= con[i]){
            cnt[order[i]] -= con[i];
            res.push_back(add[i]);
        }
    // 1
    while(res.size() < sz) res.push_back('1');

    reverse(res.begin(), res.end());
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

    cin>>s>>t;
    vi cntt(8, 0);
    if(!check(t, cntt)) 
        return cout<<-1, 0;

    n = s.length();

    vi cntn(8, 0);
    int pos0 = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            pos0 = i;
            break;
        }
        else update(s[i] - '0', cntn, 1);
    }

    // check n
    bool ok = (pos0 == -1) && (cntn[2] >= cntt[2]);
    for(int i = 3; (i <= 7) && ok; i+=2)
        ok &= (cntn[i] >= cntt[i]);
    
    if(ok) return cout<<s, 0;

    // sol
    int m = (pos0 == -1 ? n : pos0 + 1);
    vector<vi> p(m + 1, vi(8, 0));
    
    for(int i = 1; i <= m; i++){
        p[i] = p[i - 1];
        update(s[i - 1] - '0', p[i], 1);
    }

    for(int i = m - 1; i >= 0; i--){
        for(int j = s[i] - '0' + 1; j < 10; j++){
            vi del(8);
            update(j, p[i], 1);

            del[2] = cntt[2] - p[i][2];
            del[3] = cntt[3] - p[i][3];
            del[5] = cntt[5] - p[i][5];
            del[7] = cntt[7] - p[i][7];

            string back = sol(del, n - i - 1);
            if(back != "-1") 
                return cout<<s.substr(0, i) + to_string(j) + back, 0;
        }
    }
    return cout<<sol(cntt, max(n + 1, getSz(cntt))), 0;
    return 0;
}