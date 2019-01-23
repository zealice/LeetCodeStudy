/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //复杂度O(N)
 //48 ms, Your runtime beats 35.19 % of cpp submissions. Add Two Numbers.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1,*p2 = l2;
        ListNode* rl = new ListNode(0);
        ListNode * rrl = rl;
        while(p1 != NULL && p2 != NULL){
            if((rl->val + p1->val + p2->val) / 10 != 0){
                rl->next = new ListNode(0);
                rl->next->val += (rl->val + p1->val + p2->val) / 10;
            }
            rl->val = (rl->val + p1->val + p2->val) % 10;
            p1 = p1->next;
            p2 = p2->next;
            if(p1 == NULL && p2 == NULL){
                break;
            }else if(p1 == NULL){
                p1 = new ListNode(0);
            }else if(p2 == NULL){
                p2 = new ListNode(0);
            }
            if(rl->next ==NULL){
                rl->next = new ListNode(0);                
            }
            rl = rl->next;
        }
        //if(rl->val == 0){
           // delete rl;//不可如此，因为调用完整个函数，rl会自动delete，会有双重delete的错误
            //rl = NULL;
        //}
        return rrl;
    }
};
