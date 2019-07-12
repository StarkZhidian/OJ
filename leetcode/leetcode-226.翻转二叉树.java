/**
	��תһ�ö�������

	ʾ����

	���룺

		 4
	   /   \
	  2     7
	 / \   / \
	1   3 6   9
	�����

		 4
	   /   \
	  7     2
	 / \   / \
	9   6 3   1
	��ע:
	����������ܵ� Max Howell �� ԭ���� ������ ��

	�ȸ裺����90���Ĺ���ʦʹ������д�����(Homebrew)��������ȴ�޷�������ʱ�ڰװ���д����ת����������⣬��̫����ˡ�

	��Դ�����ۣ�LeetCode��
	���ӣ�https://leetcode-cn.com/problems/invert-binary-tree
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
	
	˼·���ݹ飬�ȷ�ת�������������ת����
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
    public TreeNode invertTree(TreeNode root) {
        if (root != null) {
            invertTree(root.left);
            invertTree(root.right);
            TreeNode t = root.left;
            root.left = root.right;
            root.right = t;
        }
        return root;
    }
}