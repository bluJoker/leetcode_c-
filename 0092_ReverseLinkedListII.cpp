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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		
        ListNode *a = dummy;
        for(int i = 0; i < left - 1; i++) a = a->next;
		ListNode *b = a->next, *c = b->next;
		for(int i = 0; i < right - left; i++) {
			auto t = c->next;
			c->next = b;
			b = c, c = t;
		}
		//此时b为反转后的头结点
		a->next->next = c; //后--->前
		a->next = b; //前--->后
		return dummy->next;
    }
};

