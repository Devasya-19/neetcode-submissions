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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. Find the middle

        ListNode* slow = head;

        ListNode* fast = head;

        while (fast->next && fast->next->next) {

            slow = slow->next;

            fast = fast->next->next;

        }

        // 2. Split the list

        ListNode* second = slow->next;

        slow->next = nullptr;

        // 3. Reverse the second half

        ListNode* prev = nullptr;

        ListNode* curr = second;

        while (curr) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;

            curr = next;

        }

        second = prev;

        // 4. Merge the two halves alternately

        ListNode* first = head;

        while (second) {

            ListNode* firstNext = first->next;

            ListNode* secondNext = second->next;

            first->next = second;

            second->next = firstNext;

            first = firstNext;

            second = secondNext;

        }
    }
};
