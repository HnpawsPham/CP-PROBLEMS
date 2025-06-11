#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

string s;
int k;

// get state of current right pointer (00, 01, 10, 11)
int get(int a, int b){
    return (a % 2 << 1) | (b % 2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>k;
    int n = s.length();
    int res = INT_MIN;
    vi minn;

    for(char a = '0'; a < '5'; a++){
        for(char b = '0'; b < '5'; b++){
            if(a == b) continue;
            
            minn.assign(4, INT_MAX);

            int cur_a = 0, cur_b = 0;
            int prev_a = 0, prev_b = 0;
            int l = 0;

            for(int r = 0; r < n; r++){
                cur_a += (s[r] == a);
                cur_b += (s[r] == b);
                                        // cnt(b) must be even
                while(r - l + 1 >= k && cur_b - prev_b >= 2){;
                    int prev_state = get(prev_a, prev_b);
                    minn[prev_state] = min(minn[prev_state], prev_a - prev_b);

                    prev_a += (s[l] == a);
                    prev_b += (s[l] == b);
                    l++;
                }

                int cur_state = get(cur_a, cur_b);
                // prevent overflow
                if(minn[cur_state ^ 2] != INT_MAX)
                    res = max(res, cur_a - cur_b - minn[cur_state ^ 2]); //2 = 10
            }
        }
    }
    cout<<res;
    return 0;
}