/**
 * 排序链表
    在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

    示例 1:

    输入: 4->2->1->3
    输出: 1->2->3->4
    示例 2:

    输入: -1->5->3->4->0
    输出: -1->0->3->4->5
 *
 * 思路：归并排序
 *
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode first = head, pre = first, second = head;
        while (first != null && second != null && second.next != null) {
            pre = first;
            first = first.next;
            second = second.next.next;
        }
        // 将链表一分为 2 ，防止无限递归
        pre.next = null;
        return merge(sortList(head), sortList(first));
    }
    
    ListNode merge(ListNode node1, ListNode node2) {
        ListNode tt = null, t, res = null;
        while (node1 != null && node2 != null) {
            if (node1.val > node2.val) {
                t = node2.next;
                if (tt == null) {
                    res = tt = node2;
                }
                tt.next = node2;
                node2 = t;
            } else {
                t = node1.next;
                if (tt == null) {
                    res = tt = node1;
                }
                tt.next = node1;
                node1 = t;
            }
            tt = tt.next;
        }
        while (node1 != null) {
            tt.next = node1;
            node1 = node1.next;
            tt = tt.next;
        }
        while (node2 != null) {
            tt.next = node2;
            node2 = node2.next;
            tt = tt.next;
        }
        return res;
    }
    
}