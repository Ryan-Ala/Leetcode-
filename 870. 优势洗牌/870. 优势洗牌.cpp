class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int m =nums1.size();
        vector<int> ret(m);
        for(int i=0;i<m;i++)
        ret[i]=i;
        sort(ret.begin(),ret.end(),[&](int i,int j){
            return nums2[i]<nums2[j];
        });
        sort(nums1.begin(),nums1.end());

        vector<int> ans(m);
        int left=0,right=m-1;
        for(auto &e:nums1)
        {
            if(nums2[ret[left]]>=e)
            ans[ret[right--]]=e;
            else
            ans[ret[left++]]=e;

        }
        return ans;
    }
};