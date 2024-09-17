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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* temp=head;
        while(temp->next!=NULL){
            if(temp->val==temp->next->val){
                ListNode* next1=temp->next->next; 
                ListNode* del=temp->next;
                delete(del);
                temp->next=next1;
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};
