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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vi pos;
    ListNode* tmp = head;

    int prev1 = -1, prev2 = -1, i = 0;
    while(tmp != nullptr){
        if(prev1 == -1)
            prev1 = tmp->val;
        else if(prev2 == -1)
            prev2 = tmp->val;
        else{
            if((prev1 < prev2 && prev2 > tmp->val)
            || (prev1 > prev2 && prev2 < tmp->val))
                pos.push_back(i);

            prev1 = prev2;
            prev2 = tmp->val;
        }
        tmp = tmp->next;
        i++;
    }

    if(pos.size() < 2) 
        return cout<<"-1 -1", 0;

    int minn = i + 5;
    for(int i = 1; i < pos.size(); i++)
        minn = min(minn, pos[i] - pos[i - 1]);

    cout<<minn<<" "<<pos.back() - pos[0];
    return 0;
}