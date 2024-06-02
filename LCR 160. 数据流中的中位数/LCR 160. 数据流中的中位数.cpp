class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;  
    // left == right
    // left == right + 1
    MedianFinder() {}
    
    void addNum(int num) {
        if(left.size()==right.size())   // == 0
        {
            if(left.size()==0||num<=left.top())
            left.push(num);
            else
            {
                right.push(num);
                left.push(right.top());
                right.pop();
            }
        }
        else
        {
            if(num>left.top())
            right.push(num);
            else
            {
                left.push(num);
                right.push(left.top());
                left.pop();
            }
        }
    }
    
    double findMedian() {
        if(right.size()==left.size())
        return (right.top()+left.top())/2.0;
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */