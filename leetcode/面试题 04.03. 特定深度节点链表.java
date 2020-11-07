//给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。
//
//
//
// 示例：
//
// 输入：[1,2,3,4,5,null,7,8]
//
//        1
//       /  \
//      2    3
//     / \    \
//    4   5    7
//   /
//  8
//
//输出：[[1],[2,3],[4,5,7],[8]]
//
// Related Topics 树 广度优先搜索
// 👍 24 👎 0


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
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

/**
 * 思路：层序遍历二叉树，但是需要分隔每一层的节点，这里通过链表的 add(null) 来作为每一层的节点分隔
 */
class Solution {
    public ListNode[] listOfDepth(TreeNode tree) {
        if (tree == null) {
            return null;
        }
        List<ListNode> result = new LinkedList<>();
        ListNode tempList = null;
        ListNode tempResultList = null;
        LinkedList<TreeNode> queue = new LinkedList<>();
        TreeNode tempNode;
        queue.add(tree);
        // null 作为每一层的分隔
        queue.add(null);
        // 防止每一层的节点分隔 null 被重复添加
        boolean isLastNull = true;
        while (!queue.isEmpty()) {
            tempNode = queue.pollFirst();
            if (tempNode == null) {
                if (tempResultList != null) {
                    result.add(tempResultList);
                }
                tempResultList = null;
                if (!isLastNull) {
                    // null 作为每一层的分隔
                    queue.add(null);
                    isLastNull = true;
                }
                continue;
            }
            if (tempResultList == null) {
                tempResultList = tempList = new ListNode(tempNode.val);
            } else {
                tempList.next = new ListNode(tempNode.val);
                tempList = tempList.next;
            }
            if (tempNode.left != null) {
                queue.add(tempNode.left);
                isLastNull = false;
            }
            if (tempNode.right != null) {
                queue.add(tempNode.right);
                isLastNull = false;
            }
        }
        return result.toArray(new ListNode[0]);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
