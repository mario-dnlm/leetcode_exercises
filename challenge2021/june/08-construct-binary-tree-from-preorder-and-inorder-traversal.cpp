#include <iostream>
#include <vector>
#include <algorithm>    // std::find
#include <map>
#include <unordered_map>

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
    //================ sample 0 ms submission ========================
    int count=0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int start,int end,int i,map<int,int> &m)
    {
        if(start>end || i>preorder.size()-1)
            return NULL;
        
        struct TreeNode* root=new struct TreeNode;
        
        int idx= m.find(preorder[i])->second;
        root->val=preorder[i];
       count++;
        root->left=build(preorder,inorder,start,idx-1,count,m);
         root->right=build(preorder,inorder,idx+1,end,count,m);
        
        return root;
    }
    TreeNode* buildTree_ver00ms(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int>m;
        int n=preorder.size();
        for(int i=0;i<n;i++)
        {
            m[inorder[i]]=i;
        }
        
       return build(preorder,inorder,0,n-1,0,m);
    }

    //================ sample 8 ms submission ========================
    TreeNode *buildTree_ver08ms(vector<int> &preorder, vector<int> &inorder)
	{
		int preStart = 0; // imp to have this variable, as it is pass by reference, so we need an lvalue
        
        unordered_map<int, int> inIdxs;
        
        for (int i=0; i<inorder.size(); i++)
            inIdxs[inorder[i]] = i;

		return buildFromPre(preorder, inorder, inIdxs, preStart, 0, inorder.size() - 1);
	}

	TreeNode *buildFromPre(
		vector<int> &pre, vector<int> &in,
        unordered_map<int, int> &inIdxs,
		int &preStart, int inStart, int inEnd)
	{
		if (inStart > inEnd)
			return nullptr;

		TreeNode *node = new TreeNode(pre[preStart++]);

		if (inStart == inEnd) // leaf node
			return node;

		int inIdx = inIdxs[pre[preStart - 1]];

		node->left = buildFromPre(pre, in, inIdxs, preStart, inStart, inIdx - 1);
		node->right = buildFromPre(pre, in, inIdxs, preStart, inIdx + 1, inEnd);

		return node;
	}



    //================ My first trial ========================
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = nullptr;
        if (preorder.size() != 0) {
            vector<int>::iterator it_root = std::find(inorder.begin(), inorder.end(), preorder[0]);
            int root_inorder_idx = distance(inorder.begin(), it_root);
            int size_leftsubtree = root_inorder_idx;
            int size_rightsubtree = inorder.size() - root_inorder_idx;
            
            // find the left subtree
            vector<int> left_preorder(preorder.begin()+1, preorder.begin()+1+size_leftsubtree);
            vector<int> left_inorder(inorder.begin(), inorder.begin()+size_leftsubtree);
            // find the right subtree
            vector<int> right_preorder(preorder.begin()+1+size_leftsubtree,preorder.end());
            vector<int> right_inorder(inorder.begin()+size_leftsubtree+1, inorder.end());
                        
            root = new TreeNode(preorder[0], buildTree(left_preorder, left_inorder), buildTree(right_preorder, right_inorder));
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