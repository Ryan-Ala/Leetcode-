class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int max_num = arr[0],m = arr.size();
        int tmp=0;
        for(int i=1;i<m&&tmp<k;i++)
        {
            if(arr[i]>max_num)
            {
                max_num=arr[i];
                tmp=0;
            }
            tmp++;
        }
        return max_num;
    }
};