#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;

        ListNode* ptr = head;
        ListNode* pre = nullptr;
        while(ptr!=nullptr && ptr->next!=nullptr) {
            int count =1;
            ListNode* ptr2 = ptr;
            ListNode* post=ptr2->next;

            while(ptr2!= nullptr &&ptr2->next!= nullptr && count <k) {
                count++;
                ptr2=ptr2->next;
                post = ptr2->next;
            }
            
            if(count == k) {
                // start reverse the substring
                ListNode* tmp = ptr;
                ListNode* tmp_post = tmp->next;
                for(int i=0;i<k-1;i++) {
                    ListNode* tmp3 = tmp_post;

                    tmp_post = tmp_post->next;
                    tmp3->next = tmp;
                    tmp = tmp3;
                }
                
                if (pre == nullptr) {
                    head = ptr2;
                    ptr->next = post;
                    pre = ptr;
                    ptr = ptr->next;
                } else {
                    pre->next = ptr2;
                    ptr->next = post;
                    pre = ptr;
                    ptr = ptr->next;
                }
            }
            else {
                return head;
            }
        }        

        return head;
    }
};

int main(int argc, char **argv) {
    Solution sln;
    // vector<int> nums={1,2,3,4,5};
    // int k = 3;
    vector<int> nums={1,2};
    int k = 2;

    ListNode* head=nullptr;
    for(int i=nums.size()-1; i>=0; i--) {
        head = new ListNode(nums[i], head);
    }

    ListNode* output = sln.reverseKGroup(head,k);
    return 0;
}