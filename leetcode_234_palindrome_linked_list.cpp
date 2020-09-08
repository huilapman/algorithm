/**
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> s;
        ListNode* curr = head;
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->next;
        }
        
        curr = head;

        while (!s.empty()) {
            ListNode* top = s.top();
            if (top->val != curr->val) {
                return false;
            }
            s.pop();
            curr = curr->next;
        } 
        
        return true;
    }
};


