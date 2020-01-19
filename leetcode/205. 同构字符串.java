/**
 给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"
输出: true
示例 2:

输入: s = "foo", t = "bar"
输出: false
示例 3:

输入: s = "paper", t = "title"
输出: true
说明:
你可以假设 s 和 t 具有相同的长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/isomorphic-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public static boolean solve(String str1, String str2) {
	if (str1 == null || str2 == null || str1.length() != str2.length()) {
		return false;
	}
	int len = str1.length();
	// 题目要求：所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
	// 因此，这里需要进行替换和被替换之间的双向绑定
	char[] map = new char[256];
	char[] mapValue = new char[256];
	char c;
	char c2;
	for (int i = 0; i < len; i++) {
		c = str1.charAt(i);
		c2 = str2.charAt(i);
		if ((map[(int) c] != 0 || mapValue[(int) c2] != 0) &&
				(map[(int) c] != c2 || mapValue[(int) c2] != c)) {
			return false;
		}
		map[(int) c] = c2;
		mapValue[(int) c2] = c;
	}
	return true;
}