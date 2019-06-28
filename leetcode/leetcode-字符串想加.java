
/**
	���ӣ�https://leetcode-cn.com/problems/add-strings

	���������ַ�����ʽ�ķǸ�����?num1 ��num2?���������ǵĺ͡�

	ע�⣺

	num1 ��num2?�ĳ��ȶ�С�� 5100.
	num1 ��num2 ��ֻ��������?0-9.
	num1 ��num2 ���������κ�ǰ���㡣
	�㲻��ʹ���κ΃Ƚ� BigInteger �⣬?Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��

	��Դ�����ۣ�LeetCode��
	
	˼·��ģ��ӷ����ɣ�ע��������ӵĽ�λ����
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

