#include <iostream>
#include <vector>
#include <algorithm>    // std::find

using namespace std;

/** Depth First Traversals:
 * *    Inorder (Left, Root, Right)
 * *    Preorder (Root, Left, Right)
 * *    Postorder (Left, Right, Root)
 * */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& precoder, vector<int>& inorder) {
        TreeNode* root = nullptr;
        if (precoder.size() != 0) {
            vector<int>::iterator it_root = std::find(inorder.begin(), inorder.end(), precoder[0]);
            int root_inorder_idx = distance(inorder.begin(), it_root);
            int size_leftsubtree = root_inorder_idx;
            int size_rightsubtree = inorder.size() - root_inorder_idx;
            
            // find the left subtree
            vector<int> left_preorder(precoder.begin()+1, precoder.begin()+1+size_leftsubtree);
            vector<int> left_inorder(inorder.begin(), inorder.begin()+size_leftsubtree);
            // find the right subtree
            vector<int> right_preorder(precoder.begin()+1+size_leftsubtree,precoder.end());
            vector<int> right_inorder(inorder.begin()+size_leftsubtree+1, inorder.end());
                        
            root = new TreeNode(precoder[0], buildTree(left_preorder, left_inorder), buildTree(right_preorder, right_inorder));
            

        }
        return root;
    }

    void printTree(TreeNode* root) {
        TreeNode* ptr = root;
        if (ptr != nullptr) {
            cout << ptr->val << ", ";
            printTree(ptr->left);
            printTree(ptr->right);
            
        }
        
    }
    void printVector(vector<int> arr) {
        for(vector<int>::iterator itr=arr.begin(); itr!=arr.end();itr++) {
            cout << *itr << " ";
        }
        cout << endl;
    }
};

int main(int argc, char **argv){
    Solution sln;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* btree = sln.buildTree(preorder, inorder);

    cout<<"Preorder : ";    sln.printVector(preorder);
    cout<<"Inorder : ";     sln.printVector(inorder);    
    cout<<"Tree : ";        sln.printTree(btree);
    cout << endl;

    return 0;
}