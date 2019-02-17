/**
	93. ��ԭIP��ַ

	link:https://leetcode-cn.com/problems/restore-ip-addresses/

	��Ŀ����

	����һ��ֻ�������ֵ��ַ�������ԭ�����������п��ܵ� IP ��ַ��ʽ��

	ʾ��:

	����: "25525511135"
	���: ["255.255.11.135", "255.255.111.35"]
	
	˼·���ݹ飬���ݣ�IP ��ַ��һ���� 4 �Σ�ÿһ�ε����ֵΪ 255����СֵΪ 0����ÿһ�εĿ���ֵ�����Դ���
	���������ֵõ��� IP ��ַ�����ϣ�����ݽ�����һ��������Դ�
*/
class Solution {
    private static final int MAX_LENGTH = 12; // ip ��ַ��Ϊ������ʾʱ��󳤶�Ϊ 12
    private static final int MAX_VALUE = 255; // ÿһ�� ip ��ַ�����ֵ
	private static final int MIN_VALUE = 0; // ÿһ�� ip ��ַ����Сֵ
    
    private List<String> res = new ArrayList<>();
    
    private static int string2Int(String s) {
        try {
            return Integer.valueOf(s);
        } catch (Exception e) {
            return -1;
        }
    }
    
    private static boolean isValidValue(String str) {
        if (str.charAt(0) == '0' && str.length() > 1) {
            return false;
        }
        int value = string2Int(str);
        return value >= MIN_VALUE && value <= MAX_VALUE;
    }
    
    private void solve(String s, String curRes, int curIndex, int curPart) {
        if (curPart == 4 && s.length() == curIndex) {
            res.add(curRes);
            return ;
        }
        int startIndex = curIndex, endIndex = Math.min(startIndex + 3, s.length());
        int value;
        String subStr, temp;
		// ��ǰ�� (part) �� ip ��ַ���ȿ���Ϊ 1-3
        for (int i = startIndex + 1; i <= endIndex; i++) {
            subStr = s.substring(startIndex, i);
			// �����ǰ��ֵ���� ip ��ַ�Σ���ݹ���һ��
            if (isValidValue(subStr)) {
                temp = curRes;
                curRes += curPart != 0 ? "." : "";
                curRes += subStr;
                solve(s, curRes, i, curPart + 1);
				// ���ݣ���ֹ�ݹ���ֵ�ĸ���
                curRes = temp;
            }
        }
    }
    
    
    
    public List<String> restoreIpAddresses(String s) {
		if (s == null || s.length() > MAX_LENGTH) {
            return res;
        }
        solve(s, "", 0, 0);
        return res;
    }
}
