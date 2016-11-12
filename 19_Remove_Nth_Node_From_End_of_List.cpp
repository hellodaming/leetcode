//
// Created by will on 16-11-5.
//You are here!
//Your runtime beats 21.08% of cpp submissions.
//


#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int step = 0;
        ListNode *NthFromEnd = head;
        ListNode *movePoint = head;
        while (movePoint != nullptr) {
            if (step != n + 1) {
                movePoint = movePoint->next;
                step++;
            } else {
                NthFromEnd = NthFromEnd->next;
                movePoint = movePoint->next;
            }

        }
        if (step == n + 1) {
            NthFromEnd->next = NthFromEnd->next->next;
        } else {

            if (step == n) {//要删除的是头结点
                head = head->next;
            }
        }
        return head;

    }
};


int main() {

    ListNode *head = nullptr;
    ListNode *temp = nullptr;

    for (int i = 1; i != 6; ++i) {
        ListNode *node = new ListNode(i);
        if (head == nullptr) {
            head = node;
            temp = node;
        } else {
            temp->next = node;
            temp = temp->next;
        }

    }
    Solution s;
    ListNode *returnValue = s.removeNthFromEnd(head, 5);

    for (auto node = returnValue; node != nullptr; node = node->next) {
        cout << node->val << " ";
    }


    return 0;
}