/**
	93. 复原IP地址

	link:https://leetcode-cn.com/problems/restore-ip-addresses/

	题目描述

	给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

	示例:

	输入: "25525511135"
	输出: ["255.255.11.135", "255.255.111.35"]
	
	思路：递归，回溯，IP 地址的一共有 4 段，每一段的最大值为 255，最小值为 0，对每一段的可能值进行试触，
	如果到最后发现得到的 IP 地址不符合，则回溯进行下一种情况的试触
*/
class Solution {
    private static final int MAX_LENGTH = 12; // ip 地址作为数字显示时最大长度为 12
    private static final int MAX_VALUE = 255; // 每一段 ip 地址的最大值
	private static final int MIN_VALUE = 0; // 每一段 ip 地址的最小值
    
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
		// 当前段 (part) 的 ip 地址长度可能为 1-3
        for (int i = startIndex + 1; i <= endIndex; i++) {
            subStr = s.substring(startIndex, i);
			// 如果当前的值符合 ip 地址段，则递归下一段
            if (isValidValue(subStr)) {
                temp = curRes;
                curRes += curPart != 0 ? "." : "";
                curRes += subStr;
                solve(s, curRes, i, curPart + 1);
				// 回溯，防止递归中值的干扰
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
