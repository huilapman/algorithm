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
    bool hasCycle(ListNode *head) {
        
        
        if (head == nullptr || head->next == nullptr) 
            return false;
        
        ListNode* fastNode = head;
        ListNode* slowNode = head;
        
        while (fastNode && slowNode && fastNode->next ) {

            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
            if (fastNode == slowNode) {
                return true;
            }
        }
        return false;
        
    }
};
