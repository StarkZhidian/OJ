
/**
	110. ƽ�������

	link: https://leetcode-cn.com/problems/balanced-binary-tree/

	��Ŀ����

	����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������

	�����У�һ�ø߶�ƽ�����������Ϊ��

	һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��

	ʾ�� 1:

	���������� [3,9,20,null,null,15,7]

		3
	   / \
	  9  20
		/  \
	   15   7
	���� true ��

	ʾ�� 2:

	���������� [1,2,2,3,3,null,null,4,4]

		   1
		  / \
		 2   2
		/ \
	   3   3
	  / \
	 4   4
	���� false ��
	
	˼·���ݹ飬дһ����������߶ȵķ��������ж������Ƿ���ƽ������������жϱ����Ƿ���ƽ�������
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    int getHeight(TreeNode node) {
        if (node == null) {
            return 0;
        }
        return 1 + Math.max(getHeight(node.left), getHeight(node.right));
    }
    
    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }
        return isBalanced(root.left) && isBalanced(root.right) &&  Math.abs(getHeight(root.left) - getHeight(root.right)) <= 1;
    }
}