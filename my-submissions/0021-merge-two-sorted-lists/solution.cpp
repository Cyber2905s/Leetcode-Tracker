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
 ListNode* mergelist(ListNode* list1,ListNode* list2){
    ListNode* curr=list1;
    ListNode* next1=curr->next;
    ListNode* temp=list2;
    ListNode* temp1=temp->next;
    if (next1==NULL) {
        curr->next = temp;
        return list1;
    }
    while(next1!=NULL && temp!=NULL){
        if((curr->val<=temp->val) && (temp->val<=next1->val)){
            temp1=temp->next;
            curr->next=temp;
            temp->next=next1;
            curr=temp;
            temp=temp1;
        }
        else{
            curr=next1;
            next1=next1->next;
        }
        if(next1==NULL){
            curr->next=temp;
        }
    }
    return list1;
 }
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        } 
        if(list2==NULL){
            return list1;
        }
        if(list1->val<=list2->val){
            return mergelist(list1,list2);
        }
        else{
            return mergelist(list2,list1);
        }
    }
};
