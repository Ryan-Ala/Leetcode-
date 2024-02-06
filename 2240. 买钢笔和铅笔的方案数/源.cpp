class Solution {
    public long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long count = 0;
        int cnt_1 = 0, cnt_2 = 0;
        while (cnt_1 * cost1 <= total)
        {
            count += (total - cnt_1 * cost1) / cost2 + 1;
            cnt_1++;
        }
        return count;
    }
}