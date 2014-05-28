/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL)
            return head;
            
        struct ListNode * head_node = new struct ListNode(0);
        head_node->next = NULL;
            
        struct ListNode *sorted_run = head_node;
        struct ListNode *unsorted_run = head;
        
        while(unsorted_run != NULL)
        {
            sorted_run = head_node;
            while(sorted_run->next != NULL && unsorted_run->val > sorted_run->next->val)
            {
                sorted_run = sorted_run->next;
            }
        
            struct ListNode *tmp = unsorted_run->next;
            unsorted_run->next = sorted_run->next;
            sorted_run->next = unsorted_run;
            unsorted_run = tmp;
            
        }
        
        struct ListNode *ret = head_node->next;
        delete(head_node);
        return ret;
    }
};