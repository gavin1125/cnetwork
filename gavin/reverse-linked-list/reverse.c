#include "lib/common.h"


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *successor;

struct ListNode *reverseN(struct ListNode *node, int n) {
    if (n == 1) {
        successor = node->next;
        return node;
    }

    struct ListNode *last = reverseN(node->next, n - 1);
    node->next->next = node;
    node->next = successor;
    return last;
}

struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
    if (left == 1) {
        return reverseN(head, right);
    }

    struct ListNode *last = reverseBetween(head->next, left - 1, right - 1);
    head->next = last;
    return head;
}


int main(int argc, char **argv) {
    struct ListNode a1;
    struct ListNode a2;
    struct ListNode a3;
    struct ListNode a4;
    struct ListNode a5;
    a1.val = 1;
    a1.next = &a2;
    a2.val = 2;
    a2.next = &a3;
    a3.val = 3;
    a3.next = &a4;
    a4.val = 4;
    a4.next = &a5;
    a5.val = 5;
    a5.next = NULL;

    struct ListNode *re = reverseBetween(&a1, 2, 4);


    printf("sfsf:%s", "gavin");

    return 0;
}





