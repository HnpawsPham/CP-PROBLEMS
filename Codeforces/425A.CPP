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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    int a[n] = {0};
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = -1e6;
    vi left, right;

    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            vi cur;
            left.clear();
            right.clear();

            int sum = 0;
            for(int i = l; i <= r; i++){
                cur.push_back(a[i]);
                sum += a[i];
            }
            
            for(int i = 0; i < l; i++)
                left.push_back(a[i]);

            for(int i = r + 1; i < n; i++)
                right.push_back(a[i]);

            sort(left.begin(), left.end());
            sort(right.begin(), right.end());
            sort(cur.begin(), cur.end(), greater<int>());

            int cnt = k;
            while(!left.empty() && !right.empty() && cnt && !cur.empty()){
                if(cur.back() > left.back() && cur.back() > right.back())
                    break;

                sum -= cur.back();
                cur.pop_back();

                if(left.back() > right.back()){
                    sum += left.back();
                    left.pop_back();
                }
                else if(left.back() <= right.back()){
                    sum += right.back();
                    right.pop_back();
                }
                cnt--;
            }

            while(!left.empty() && cnt && !cur.empty())
                if(cur.back() < left.back()){
                    sum -= cur.back();
                    sum += left.back();
                    left.pop_back();
                    cur.pop_back();
                    cnt--;
                }
                else break;

            while(!right.empty() && cnt && !cur.empty())
                if(cur.back() < right.back()){
                    sum -= cur.back();
                    sum += right.back();
                    right.pop_back();
                    cur.pop_back();
                    cnt--;
                }
                else break;

            res = max(res, sum);
        }
    }
    cout<<res;
    return 0;
}