/**
 * ��������
    �� O(n log n) ʱ�临�ӶȺͳ������ռ临�Ӷ��£��������������

    ʾ�� 1:

    ����: 4->2->1->3
    ���: 1->2->3->4
    ʾ�� 2:

    ����: -1->5->3->4->0
    ���: -1->0->3->4->5
 *
 * ˼·���鲢����
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
        // ������һ��Ϊ 2 ����ֹ���޵ݹ�
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