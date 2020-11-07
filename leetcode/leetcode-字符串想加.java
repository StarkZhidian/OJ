
/**
	链接：https://leetcode-cn.com/problems/add-strings

	给定两个字符串形式的非负整数?num1 和num2?，计算它们的和。

	注意：

	num1 和num2?的长度都小于 5100.
	num1 和num2 都只包含数字?0-9.
	num1 和num2 都不包含任何前导零。
	你不能使用任何內建 BigInteger 库，?也不能直接将输入的字符串转换为整数形式。

	来源：力扣（LeetCode）
	
	思路：模拟加法即可，注意两数想加的进位处理
*/
class Solution {
    public String addStrings(String num1, String num2) {
        if (num1 == null) {
            return num2;
        } else if (num2 == null) {
            return num1;
        }
        StringBuilder res = new StringBuilder();
        int carry = 0;
        for (int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0 || carry != 0; i--, j--) {
            if (i >= 0)
                carry += num1.charAt(i) - '0';
            if (j >= 0)
                carry += num2.charAt(j) - '0';
            res.append(carry % 10);
            carry /= 10;
        }
        return res.reverse().toString();
    }
}

