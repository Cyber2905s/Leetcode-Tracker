/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
void insertcopy(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        Node* nexele=temp->next;
        Node* copy=new Node(temp->val);
        copy->next=nexele;
        temp->next=copy;
        temp=nexele;
    }
}
void conrandom(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        Node* copy=temp->next;
        if(temp->random){
            copy->random=temp->random->next;
        }
        else{
            copy->random=NULL;
        }
        temp=temp->next->next;
    }
}
Node* getdeepcopy(Node* head){
    Node* temp = head;
    Node* dummyNode = new Node(-1); 
    Node* res = dummyNode;             
    while(temp != NULL){
        res->next = temp->next;
        res = res->next;
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;
}
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        insertcopy(head);
        conrandom(head);
        return getdeepcopy(head);
    }
};
