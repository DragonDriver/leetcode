#include <iostream>
#include <assert.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rtn_list;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            ListNode* temp_node = new ListNode(0);
            temp_node->val = l1->val + l2->val + carry;
            if (temp_node->val >= 10) {
                carry = 1;
                temp_node->val = temp_node->val - 10;
            }
            temp_node-> next = rtn_list;
            rtn_list = temp_node;
            l1 = l1->next;
            l2 = l2->next; 
        }
        while (l1 != NULL) {
            ListNode* temp_node = new ListNode(l1->val) + carry;
            if (temp_node->val >= 10) {
                carry = 1;
                temp_node->val = temp_node->val - 10;
            }
            temp_node-> next = rtn_list;
            rtn_list = temp_node;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            ListNode* temp_node = new ListNode(l2->val) + carry;
            if (temp_node->val >= 10) {
                carry = 1;
                temp_node->val = temp_node->val - 10;
            }
            temp_node-> next = rtn_list;
            rtn_list = temp_node;
            l2 = l2->next;
        }
    }
};