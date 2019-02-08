/**
	82. ɾ�����������е��ظ�Ԫ�� II
	
	link: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/

	��Ŀ����

	����һ����������ɾ�����к����ظ����ֵĽڵ㣬ֻ����ԭʼ������ û���ظ����� �����֡�

	ʾ�� 1:

	����: 1->2->3->3->4->4->5
	���: 1->2->5
	ʾ�� 2:

	����: 1->1->1->2->3
	���: 2->3
	
	˼·���ȵ�һ�汾�鷳�㣬������ָ�룬���� "����" �ظ�Ԫ�ص�˼�룬ͬʱ��ֹ��ָ��
 */
 
 /**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) {
            return head;
        }
        ListNode prev = null;
        ListNode cur = head;
        ListNode next = head.next;
        boolean hasMulti = false;
        while (cur != null && next != null) {
            while (next != null && cur.val == next.val) {
                next = next.next;
                hasMulti = true;
            }
            if (hasMulti) {
                if (prev != null) {
                    prev.next = next;
                } else {
                    head = next;
                }
            }
            if (!hasMulti) {
                prev = cur;
            }
            hasMulti = false;
            cur = next;
            if (next != null) {
                next = next.next;
            }
        }
        return head;
    }
}