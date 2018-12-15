

/**
  link��https://leetcode-cn.com/problems/leaf-similar-trees/ 
  
  ��Ŀ������ 
  �뿼��һ�Ŷ����������е�Ҷ�ӣ���ЩҶ�ӵ�ֵ�������ҵ�˳�������γ�һ�� Ҷֵ���� ��

<img src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png"></img> 

�ٸ����ӣ�����ͼ��ʾ������һ��Ҷֵ����Ϊ (6, 7, 4, 9, 8) ������

��������Ŷ�������Ҷֵ��������ͬ����ô���Ǿ���Ϊ������ Ҷ���� �ġ�

�������������ͷ���ֱ�Ϊ root1 �� root2 ������Ҷ���Ƶģ��򷵻� true�����򷵻� false �� 

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
        // �����Ҷ�ӽڵ㣬��¼��ֵ 
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
