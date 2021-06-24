#include <iostream>
#include <vector>

using namespace std;

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

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* pre_leftptr;
        ListNode* head2;
        ListNode* end2;
        ListNode* ptr = head;
        int index = 1;

        if (left == right) {    return head; }
        if (left > 1) {
            for(index = 2; index < left; index++) {
                ptr = ptr->next;
            }
            pre_leftptr = ptr;
            end2 = ptr->next;
            head2 = end2;
            ptr = head2->next;
            end2->next = nullptr;

            for (index = left + 1; index < right; index++) {
                ListNode *tmp = ptr->next;
                ptr->next = head2;
                head2 = ptr;
                ptr = tmp;
            }   

            ListNode *tmp = ptr->next;
            ptr->next = head2;
            head2 = ptr;
            end2->next = tmp;
            pre_leftptr->next = head2;
        }
        else {
            end2 = head;
            head2 = end2;
            ptr = end2->next;
            end2->next = nullptr;

            for(index = 2; index < right; index++){
                ListNode *tmp = ptr->next;
                ptr->next = head2;
                head2 = ptr;
                ptr = tmp;
            }

            ListNode *tmp = ptr->next;
            ptr->next = head2;
            head2 = ptr;
            end2->next = tmp;
            head = head2;
        }

        // if (head->val != left) {
        //     while(ptr->next->val != left && ptr->next->next != nullptr) {
        //         ptr = ptr->next;
        //     }
        //     if (ptr->next->next != nullptr) {
        //         // ptr->next->val == left
        //         // start reverse the sub-list
        //         pre_leftptr = ptr;
        //         end2 = ptr->next;
        //         head2 = end2;
        //         ptr = head2->next;
        //         end2->next = nullptr;

        //         while(ptr->val != right && ptr->next != nullptr) {
        //             ListNode *tmp = ptr->next;
        //             ptr->next = head2;
        //             head2 = ptr;
        //             ptr = tmp;
        //             printListNode(head2);
        //         }

        //         ListNode *tmp = ptr->next;
        //         ptr->next = head2;
        //         head2 = ptr;
        //         end2->next = tmp;
        //         pre_leftptr->next = head2;
        //     }
        // } else {
        //     end2 = ptr;
        //     head2 = end2;
        //     ptr = head2->next;
        //     end2->next = nullptr;
        //     while(ptr->val != right && ptr->next != nullptr) {
        //         ListNode *tmp = ptr->next;
        //         ptr->next = head2;
        //         head2 = ptr;
        //         ptr = tmp;
        //         printListNode(head2);
        //     }
        //     ListNode *tmp = ptr->next;
        //     ptr->next = head2;
        //     head2 = ptr;
        //     end2->next = tmp;
        //     head = head2;
        // }
        printListNode(head);
        return head;
    }

    void printListNode(ListNode *ptr){
        while(ptr != nullptr){
            cout << ptr->val << "->";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    ListNode *list = new ListNode(1);
    ListNode *ptr = list;
    int left = 1, right = 2;
    int n = 2;
    for (int i=2; i<=n; i++) {
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }

    ptr = sln.reverseBetween(list, left, right);
    return 0;
}