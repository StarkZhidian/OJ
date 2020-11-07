

/**
  link：https://leetcode-cn.com/problems/leaf-similar-trees/ 
  
  题目描述： 
  请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。

<img src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png"></img> 

举个例子，如上图所示，给定一颗叶值序列为 (6, 7, 4, 9, 8) 的树。

如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。

如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。 

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void travelsal(TreeNode *node, vector<int> &v) {
        if (node == NULL) {
            return ;
        }
        // 如果是叶子节点，记录其值 
        if (node->left == NULL && node->right == NULL) {
            v.push_back(node->val);
        }
        travelsal(node->left, v);
        travelsal(node->right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
            return true;
        }
        if (root1 == NULL || root2 == NULL) {
            return false;
        }
        vector<int> v1, v2;
        travelsal(root1, v1);
        travelsal(root2, v2);
        return v1 == v2;
    }
};
