//给定一棵二叉搜索树，请找出其中第k大的节点。
//
//
//
// 示例 1:
//
// 输入: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//输出: 4
//
// 示例 2:
//
// 输入: root = [5,3,6,2,4,null,null,1], k = 3
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//输出: 4
//
//
//
// 限制：
//
// 1 ≤ k ≤ 二叉搜索树元素个数
// Related Topics 树
// 👍 80 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

/**
 * 思路：二叉搜索树的特性为：任意节点的左子树(如果有)一定小于父节点值，任意节点的右子树(如果有)一定大于父节点值
 * 根据这个特性，如果我们对二叉搜索树进行中序遍历，得到的结果是一个升序的数组。
 * 如果我们从最右下角的节点开始遍历，顺序为：右-根-左，得到的结果是一个降序的数组。
 * 那么，我们只需要按照这种遍历方式，当遍历到第 k 个节点时，这个节点的值就是结果，
 * 而后就没有必要再遍历了，通过一个实例字段记录结果，如果得到了结果，遍历方法就可以直接 return
 */
class Solution {
    /* 结果缓存节点 */
    private TreeNode result;
    /* 遍历的节点数 */
    private int counts;

    public int kthLargest(TreeNode root, int k) {
        if (root == null) {
            throw new IllegalArgumentException("Argument root can not be null!");
        }
        traversal(root, k);
        return result.val;
    }

    private void traversal(TreeNode root, int k) {
        // 如果 result 已经找到了，则没必要继续遍历了，直接 return
        if (root == null || result != null) {
            return;
        }
        if (root.right != null) {
            traversal(root.right, k);
        }
        // find it!
        if (++counts == k) {
            result = root;
            return;
        }
        if (root.left != null) {
            traversal(root.left, k);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
