
/**
	110. 平衡二叉树

	link: https://leetcode-cn.com/problems/balanced-binary-tree/

	题目描述

	给定一个二叉树，判断它是否是高度平衡的二叉树。

	本题中，一棵高度平衡二叉树定义为：

	一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

	示例 1:

	给定二叉树 [3,9,20,null,null,15,7]

		3
	   / \
	  9  20
		/  \
	   15   7
	返回 true 。

	示例 2:

	给定二叉树 [1,2,2,3,3,null,null,4,4]

		   1
		  / \
		 2   2
		/ \
	   3   3
	  / \
	 4   4
	返回 false 。
	
	思路：递归，写一个求二叉树高度的方法，先判断子树是否是平衡二叉树，在判断本身是否是平衡二叉树
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
        int left = getHeight(node.left);
        if (left == -1) {
            return left;
        }
        int right = getHeight(node.right);
        if (right == -1) {
            return -1;
        }
        return Math.abs(left - right) > 1 ? -1 : 1 + Math.max(left, right);
    }
    
    public boolean isBalanced(TreeNode root) {
        return getHeight(root) != -1;
    }
}