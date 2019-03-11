 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:

    Interval single_intersection(Interval & A, Interval & B) {
        Interval rtn;
        int a_start = A.start, a_end = A.end;
        int b_start = B.start, b_end = B.end;
        if (a_start > b_end) {
            rtn.start = a_start;
            rtn.end = b_end;
        } else if (b_start > a_end) {
            rtn.start = b_start;
            rtn.end = a_end;
        } else if(a_start < b_start) {
            rtn.start = b_start;
            rtn.end = (a_end < b_end) ? a_end : b_end;
        } else {
            rtn.start = a_start;
            rtn.end = (a_end < b_end) ? a_end : b_end;
        }
        return rtn;
    }

    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> vec_rtn;
        int i, j;
        for (i = 0; i < A.size(); ++i) {
            for (j = 0; j < B.size(); ++j) {
                Interval tmp_interval = single_intersection(A[i], B[j]);
                if (tmp_interval.end >= tmp_interval.start) {
                    vec_rtn.push_back(tmp_interval);
                }
            }
        }
        return vec_rtn;
    }

    // 在网上发现可以用归并排序的思想去做，时间复杂度可以降到O(n)
    // 两个指针指向每个间隔的end
    // 因为两个集合都是排好序的，才可以用归并
};