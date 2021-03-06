/**
 * number and not the value in the nodes.
 * You should try to do it in place. The program should run in O(1) space complexity and
 * O(nodes) time complexity.
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 * Note:
 * The relative order inside both the even and odd groups should remain as it was in the input. 
 * The first node is considered odd, the second node even and so on ...
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * Author: Adam Yu Wen
 * Date: April 25, 2018
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenStart = head->next;
        while (odd && odd->next && even && even->next) {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = evenStart;
        return head;
    }
};