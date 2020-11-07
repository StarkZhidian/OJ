//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
//
// 进阶：
//
//
// 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
//
//
//
//
// 示例 1：
//
//
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
//
//
// 示例 2：
//
//
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
//
//
// 示例 3：
//
//
//输入：head = []
//输出：[]
//
//
//
//
// 提示：
//
//
// 链表中节点的数目在范围 [0, 5 * 104] 内
// -105 <= Node.val <= 105
//
// Related Topics 排序 链表
// 👍 810 👎 0


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
 * 思路：对链表进行归并排序，因为链表本身的特性，可以做到不申请额外的堆内存空间完成排序
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode first = head;
        ListNode second = head;
        ListNode pre = null;
        while (first != null && second != null && second.next != null) {
            pre = first;
            first = first.next;
            second = second.next.next;
        }
        // 断开前后两部分链表的联系
        pre.next = null;
        return mergeList(sortList(head), sortList(first));
    }

    /**
     * 按从小到大的顺序合并两个链表为一个链表
     * @return 合并后链表的头节点
     */
    ListNode mergeList(ListNode node1, ListNode node2) {
        if (node1 == null && node2 == null) {
            return null;
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
