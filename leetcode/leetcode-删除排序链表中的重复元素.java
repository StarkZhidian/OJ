/**
	83. ɾ�����������е��ظ�Ԫ��

	https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

	����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�

	ʾ�� 1:

	����: 1->1->2
	���: 1->2
	ʾ�� 2:

	����: 1->1->2->3->3
	���: 1->2->3
	
	˼·: ûʲô˼·��������������ͬ��Ԫ��һ����һ����ôֻҪ���������ɣ����в���ʱע���ָ��
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
        ListNode prev = head;
        ListNode next = head.next;
        while (prev != null && next != null) {
            if (prev.val == next.val) {
                prev.next = next.next;
            } else {
                prev = next;
            }
            next = next.next;
        }
        return head;
    }
}