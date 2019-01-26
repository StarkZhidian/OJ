/*
 Create by S 
 �ϲ�����
����һ������ļ��ϣ���ϲ������ص������䡣

ʾ�� 1:

����: [[1,3],[2,6],[8,10],[15,18]]
���: [[1,6],[8,10],[15,18]]
����: ���� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
ʾ�� 2:

����: [[1,4],[4,5]]
���: [[1,5]]
����: ���� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool com(Interval &i1, Interval &i2) {
	return i1.start < i2.start;
} 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int size = intervals.size();
        vector<Interval> res;
        if (size == 0) {
        	return res;
		}
		sort(intervals.begin(), intervals.end(), com);
		res.push_back(intervals[0]);
		int curSize = 1;
		int curEnd = intervals[0].end;
		for (int i = 1; i < size; i++) {
			if (curEnd < intervals[i].start) {
				res.push_back(intervals[i]);
				curSize++;
			} else {
				res[curSize - 1].end = max(curEnd, res[curSize - 1].end);
			}
			curEnd = intervals[i].end;
		}
		return res;
    }
};
