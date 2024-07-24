class Solution {
public:
    int f[50005];
    int mergesort(int left,int right,vector<int>& record)
    {
        if(left>=right)return 0;
        int ret=0,mid=(left+right)>>1;
        ret+=mergesort(left,mid,record);
        ret+=mergesort(mid+1,right,record);

        int cur1=left,cur2=mid+1,i=0;
        while(cur1<=mid&&cur2<=right)
        {
            if(record[cur1]<=record[cur2])
            {
                f[i++]=record[cur1++];
            }
            else
            {
                ret+=mid-cur1+1;
                f[i++]=record[cur2++];
            }
        }

        while(cur1<=mid)f[i++]=record[cur1++];
        while(cur2<=right)f[i++]=record[cur2++];

        for(int j=left;j<=right;j++)
        record[j]=f[j-left];

        return ret;
    }
    int reversePairs(vector<int>& record) {
        return mergesort(0,record.size()-1,record);
    }
};