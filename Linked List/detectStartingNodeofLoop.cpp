// Detect starting node of a loop in singly LL

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // unordered_map<ListNode*,int> mpp;
        // ListNode *temp = head;
        // while(temp!=nullptr){
        //     if(mpp.find(temp)!=mpp.end()){
        //         return temp;
        //     }
        //     mpp[temp]++;
        //     temp=temp->next;
        // }
        ListNode *slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};