/**
	58. ���һ�����ʵĳ���

	��Ŀ����

	�ٷ����


	����һ����������Сд��ĸ�Ϳո� ' ' ���ַ��������������һ�����ʵĳ��ȡ�

	������������һ�����ʣ��뷵�� 0 ��

	˵����һ��������ָ����ĸ��ɣ����������κοո���ַ�����

	ʾ��:

	����: "Hello World"
	���: 5
	
	˼·��ע��ĩβ���пո�������ֻ��һ�����ʵ�������µ��±�Խ�磨-1��
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