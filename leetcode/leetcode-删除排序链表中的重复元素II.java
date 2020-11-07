/**
	82. 删除排序链表中的重复元素 II
	
	link: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/

	题目描述

	给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

	示例 1:

	输入: 1->2->3->3->4->4->5
	输出: 1->2->5
	示例 2:

	输入: 1->1->1->2->3
	输出: 2->3
	
	思路：比第一版本麻烦点，用三个指针，采用 "跳过" 重复元素的思想，同时防止空指针
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