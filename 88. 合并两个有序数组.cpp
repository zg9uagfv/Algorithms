class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos_a = m > 0 ? m-1:-1;
        int pos_b = n > 0 ? n-1: -1;
        int pos_c = m+n-1;
        while (pos_a >=0 && pos_b >= 0) {
            if (nums1[pos_a] > nums2[pos_b]) {
                nums1[pos_c] = nums1[pos_a];
                pos_a--;
            } else {
                nums1[pos_c] = nums2[pos_b];
                pos_b--;
            }
            pos_c--;
        }
        while (pos_a >= 0 ) {
            nums1[pos_c--] = nums1[pos_a--];
        }
        while (pos_b >= 0) {
            nums1[pos_c--] = nums2[pos_b--];
        }
        return;
    }
};
