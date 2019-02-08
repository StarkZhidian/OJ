/**
	83. 删除排序链表中的重复元素

	https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

	给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

	示例 1:

	输入: 1->1->2
	输出: 1->2
	示例 2:

	输入: 1->1->2->3->3
	输出: 1->2->3
	
	思路: 没什么思路，排序后的链表相同的元素一定在一起，那么只要遍历链表即可，进行操作时注意空指针
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