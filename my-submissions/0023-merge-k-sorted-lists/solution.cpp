/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 struct op{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, op> pq;
        for(auto list: lists){
            if(list) pq.push(list);
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            tail->next=top;
            tail=tail->next;
            if(top->next){
                pq.push(top->next);
            }
        }
        return dummy.next;
    }
};
