// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// You may not alter the values in the nodes, only nodes itself may be changed.

// Only constant memory is allowed.

// For example,
// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *newHead = NULL, *prev = NULL;
        ListNode *subHead = head, *subTail = head;
        do {
            int i = 0;
            while(i < k-1 && subTail) {
                subTail = subTail->next;
                ++i;
            }
            if(!subTail) {
                if(prev) {
                    prev->next = subHead;
                    return newHead;
                }
                return head;
            }
            ListNode *next = subTail->next;
            subTail->next = NULL;
            revList(subHead);
            if(!newHead) newHead = subTail;
            if(prev) prev->next = subTail;
            prev = subHead;
            subHead = subTail = next;
        } while(subHead);
        return newHead;
    }
    
    ListNode *revList(ListNode *head) {
        ListNode *prev = NULL, *cur = head;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
