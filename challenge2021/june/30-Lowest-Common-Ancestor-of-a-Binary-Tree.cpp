#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//  * Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (p == root || q == root) return root;
        if (p == q) return p;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) {
            return root;
        } else if (right == NULL) {
            return left;
        } else if (left == NULL) { 
            return right;
        }
        return NULL;
    }    
    TreeNode* lowestCommonAncestor_wrong(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root || q == root) return root;
        if (p == q) return p;

        // build a vector form
        vector<TreeNode*> tree_vector;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        int idx_p, idx_q;


        while(!myqueue.empty()) {
            TreeNode* ptr = myqueue.front();
            myqueue.pop();
            if(ptr != NULL) {
                myqueue.push(ptr->left);
                myqueue.push(ptr->right);

            } else {
                myqueue.push(NULL);
                myqueue.push(NULL);
            }
            
            tree_vector.push_back(ptr);
            if (ptr == p) {
                idx_p = tree_vector.size() - 1;
                printf("p at %d\n", idx_p);
            } else if (ptr == q) {
                idx_q = tree_vector.size() -1;
                printf("q at %d\n", idx_q);
            }

            cout << "tree: ";
            for (int i=0; i<tree_vector.size(); i++) {
                if(tree_vector[i] != NULL) 
                    cout << (tree_vector[i])->val << " ";
                else
                    cout << "null" << " "; 
            }
            cout << "\n";
        }

        return root;       
    }
};

int main(int argc, char **argv) {
    Solution sln;

    return 0;
}