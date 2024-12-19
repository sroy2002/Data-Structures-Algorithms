/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//Brute Force Approach with extra memory

class Solution{
    public:
        bool hasCycle(ListNode *head){
            if(head==NULL || head->next==NULL) return false;
            unorderd_map<ListNode*,int>mpp;
            ListNode *temp=head;
            while(temp!=nullptr){
                if(mpp.find(temp)!=mpp.end()){
                    return true;
                }
                mpp[temp]++;
                temp=temp->next;
            }
            return false;
        }
}


 // Optimal approach TC:O(N) SC:O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr)return false;
        ListNode* slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return true;
        }
        return false;
    }
};