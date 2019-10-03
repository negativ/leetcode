/**
 * 
 * https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        
        return mergeKLists(lists, 0, lists.size());
    }
    
private:
    ListNode* mergeKLists(vector<ListNode*>& lists, int start, int stop) {
        
        const auto N = (stop - start) / 2;
        
        if (N == 0)
            return lists[start];
        
        auto l = mergeKLists(lists, start, start + N);
        auto r = mergeKLists(lists, start + N, stop);
        
        return merge(l, r);
    } 
    
    inline ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr || l2 == nullptr)
            return l1 != nullptr? l1 : l2;

        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        
        if (l1->val < l2->val) {
            head = prev = l1;
            l1 = l1->next;
        }
        else {
            head = prev = l2;
            l2 = l2->next;
        }

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev = prev->next = l1;
                l1 = l1->next;
            }
            else {
                prev = prev->next = l2;
                l2 = l2->next;
            }
        }

        if (l1)
            prev->next = l1;
        else if (l2)
            prev->next = l2;

        return head;
    }
};
