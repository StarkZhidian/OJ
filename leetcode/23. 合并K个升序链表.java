//给你一个链表数组，每个链表都已经按升序排列。
//
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。
//
//
//
// 示例 1：
//
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
//解释：链表数组如下：
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//将它们合并到一个有序链表中得到。
//1->1->2->3->4->4->5->6
//
//
// 示例 2：
//
// 输入：lists = []
//输出：[]
//
//
// 示例 3：
//
// 输入：lists = [[]]
//输出：[]
//
//
//
//
// 提示：
//
//
// k == lists.length
// 0 <= k <= 10^4
// 0 <= lists[i].length <= 500
// -10^4 <= lists[i][j] <= 10^4
// lists[i] 按 升序 排列
// lists[i].length 的总和不超过 10^4
//
// Related Topics 堆 链表 分治算法
// 👍 987 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 *
 * 思路：写一个合并两个排序链表的函数，然后循环调用合并 k 个
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        int startIndex = 0;
        while (lists[startIndex] == null) {
            startIndex++;
        }
        ListNode resultList = lists[startIndex++];
        for (int i = startIndex; i < lists.length; i++) {
            if (lists[i] != null) {
                resultList = mergeList(resultList, lists[i]);
            }
        }
        return resultList;
    }

    /**
     * 按从小到大的顺序合并两个链表为一个链表
     * @return 合并后链表的头节点
     */
    ListNode mergeList(ListNode node1, ListNode node2) {
        if (node1 == null) {
            return node2;
        }
        if (node2 == null) {
            return node1;
        }
        ListNode resHead = null, tempTail = null;
        // 先把结果链表的头节点算出来
        if (node1 != null && node1.val < node2.val) {
            resHead = tempTail = node1;
            node1 = node1.next;
        } else {
            resHead = tempTail = node2;
            node2 = node2.next;
        }
        while (node1 != null && node2 != null) {
            if (node1.val < node2.val) {
                tempTail.next = node1;
                node1 = node1.next;
            } else {
                tempTail.next = node2;
                node2 = node2.next;
            }
            tempTail = tempTail.next;
        }
        while (node1 != null) {
            tempTail.next = node1;
            node1 = node1.next;
            tempTail = tempTail.next;
        }
        while (node2 != null) {
            tempTail.next = node2;
            node2 = node2.next;
            tempTail = tempTail.next;
        }
        return resHead;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
