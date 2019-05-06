#include <iostream>
#include <assert.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* list);

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* reverse_list = NULL;
        int carry = 0;
        // iterator two list and merge(add) to ans_list
        while (l1 != NULL && l2 != NULL) {
            ListNode* head = new ListNode(0);
            // head->val = l1->val + l2->val + carry;
            // carry = 0;
            // if (head->val >= 10) {
            //     carry = 1;
            //     head->val = head->val - 10;
            // }
            // make progress
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            head->val = sum % 10;
            head-> next = reverse_list;
            reverse_list = head;
            l1 = l1->next;
            l2 = l2->next; 
        }// one or two of the lists reach end
        // printf("one or two of lists reach end\n\n");
        while (l1 != NULL) {
            // ListNode* head = new ListNode(l1->val + carry);
            // carry = 0;
            // if (head->val >= 10) {
            //     carry = 1;
            //     head->val = head->val - 10;
            // }
            // make progress
            int sum = l1-> val + carry;
            carry = sum / 10;
            ListNode* head = new ListNode(sum % 10);
            head-> next = reverse_list;
            reverse_list = head;
            l1 = l1->next;
        }
        // printf("list 1 reach end\n\n");
        while (l2 != NULL) {
            // ListNode* head = new ListNode(l2->val + carry);
            // carry = 0;
            // if (head->val >= 10) {
            //     carry = 1;
            //     head->val = head->val - 10;
            // }
            // make progress
            int sum = l2-> val + carry;
            carry = sum / 10;
            ListNode* head = new ListNode(sum % 10);
            head-> next = reverse_list;
            reverse_list = head;
            l2 = l2->next;
        }
        // printf("list 2 reach end\n\n");
        // handle carry
        if (carry != 0) {
            ListNode* head = new ListNode(carry);
            head->next = reverse_list;
            reverse_list = head;
        }
        // reverse list
        // printList(reverse_list);
        ListNode* ans_list = NULL;
        assert(ans_list == NULL);
        while (reverse_list != NULL) {
            // forever remember this bug
            // ListNode* head = reverse_list;
            ListNode* head = new ListNode(reverse_list->val);
            head->next = ans_list;
            ans_list = head;
            reverse_list = reverse_list->next;
        }
        return ans_list;
    }
};

void printList(ListNode* list) {
    int i = 0;
    while (list != NULL) {
        if ((i + 1) % 6 == 0) {
            printf("%d\n", list->val);
        } else {
            printf("%d\t", list->val);
        }
        list = list->next;
        i++;
    }
    printf("\n");
}

int main(void) {
    Solution sln;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    printList(sln.addTwoNumbers(l1, l2));
    ListNode* l3 = new ListNode(9);
    l3->next = new ListNode(8);
    ListNode* l4 = new ListNode(1);
    printList(sln.addTwoNumbers(l3, l4));
    ListNode* l5 = new ListNode(5);
    ListNode* l6 = new ListNode(5);
    printList(sln.addTwoNumbers(l5, l6));
    return 0;
}