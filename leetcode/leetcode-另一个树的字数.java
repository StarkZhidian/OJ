/**
 * link: https://leetcode-cn.com/problems/subtree-of-another-tree/submissions/
 * 
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 * 
 * 思路：写一个判断两个二叉树是否为同一结构的树的方法(isSameTree)，
 * 之后在主方法 isSubtree 中分别对 (s,t); (s.left,t) 和 (s.right,t) 递归判断是否为同一结构的二叉树即可
 */
class Solution {
    
    boolean isSameTree(TreeNode s1, TreeNode s2) {
        if (s1 == s2) {
            return true;
        }
        if (s1 == null || s2 == null) {
            return false;
        }
        return s1.val == s2.val && isSameTree(s1.left, s2.left) && isSameTree(s1.right, s2.right);
    }
    
    public boolean isSubtree(TreeNode s, TreeNode t) {
        return isSameTree(s, t) || (s != null && isSubtree(s.left, t)) || (s != null && isSubtree(s.right, t));
        
    }
}