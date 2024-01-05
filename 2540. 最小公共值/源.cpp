class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = 0, n2 = 0;
        while (n1 < nums1.size() && n2 < nums2.size())
        {
            if (nums1[n1] < nums2[n2])
                n1++;
            else if (nums1[n1] > nums2[n2])
                n2++;
            else
                return nums1[n1];
        }
        return -1;
    }
};