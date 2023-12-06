/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    ArrayList<Integer> ret = new ArrayList<>();
    public Solution(ListNode head) {
        while (head != null)
        {
            ret.add(head.val);
            head = head.next;
        }
    }

    public int getRandom() {
        Random r = new Random(0);
        return ret.get(r.nextInt(ret.size()));
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */