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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* size = head;
        int count = 0;
        while(size != NULL){
            size = size->next;
            count++;
        }
        if(count==1){
            head=NULL; 
            return head;
        } 
        ListNode* nn = head;
        
        int tbd=0;
        while(nn->next != NULL){
            if(count-n-1 < 0){
                head = head->next;
                break;
            }
            if(tbd==count-n-1){
                nn->next=nn->next->next;
                break;
            }
            tbd++;
            nn = nn->next;
         }
        return head;
    }
};