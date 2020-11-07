/**
	58. 最后一个单词的长度

	题目描述

	官方题解


	给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

	如果不存在最后一个单词，请返回 0 。

	说明：一个单词是指由字母组成，但不包含任何空格的字符串。

	示例:

	输入: "Hello World"
	输出: 5
	
	思路：注意末尾含有空格的情况和只有一个单词的情况导致的下标越界（-1）
*/
class Solution {
    public int lengthOfLastWord(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int start, end = s.length() - 1;
        while (s.charAt(end) == ' ' && end > 0) {
            end--;
        }
        start = end;
        while (s.charAt(start) != ' ' && start > 0) {
            start--;
        }
        return end - start + (s.charAt(start) == ' ' ? 0 : 1);
    }
}