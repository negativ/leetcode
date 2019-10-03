/**
 * 
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * 
 */

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        auto* p = head;
        ListNode* q = nullptr, *uniq = nullptr;

        while (p) {
            if (p && p->next) {
                if (p->next->val != p->val) {
                    if (uniq)
                        uniq->next = p;
                    else
                        q = p;

                    uniq = p;
                    p = p->next;
                    uniq->next = nullptr;

                    continue;
                }
                else {
                    auto d = p->val;

                    while (p && p->val == d)
                            p = p->next;
                }
            }
            else if (p) {
                if (uniq)
                    uniq->next = p;
                else
                    q = p;

                uniq = p;
                p = p->next;
            }
        }
        return q;
    }
};
