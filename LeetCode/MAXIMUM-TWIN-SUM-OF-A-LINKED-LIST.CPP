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

    int n = 0;
    ListNode* tmp = head;
    while(tmp != nullptr){
        tmp = tmp->next;
        n++;
    }

    vector<int> prev(n / 2);
    for(int i = 0; i < n / 2; i++){
        prev[i] = head->val;
        head = head->next;
    }
    for(int i = n / 2; i < n; i++){
        prev[n - i - 1] += head->val;
        head = head->next;
    }
    
    cout<<*max_element(prev.begin(), prev.end());
    return 0;
}