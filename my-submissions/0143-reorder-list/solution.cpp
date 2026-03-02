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
    ListNode* getmid(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(curr!=NULL){
            next= curr->next;
            curr->next = prev;
            prev= curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head->next==NULL){
            return;
        }
        ListNode* mid = getmid(head);
        ListNode* head2=mid->next;
        mid->next=NULL;
        head2= reverse(head2);
        ListNode* p1=head;
        ListNode* p2=head2;
        while(p2!=NULL){
            ListNode* temp1= p1->next;
            ListNode* temp2= p2->next;
            p1->next=p2;
            p2->next=temp1;
            p1=temp1;
            p2=temp2;
        }
        return;
    }
};
