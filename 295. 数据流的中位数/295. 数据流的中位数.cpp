class MedianFinder {
public:
    priority_queue<int> q_left;
    priority_queue<int,vector<int>,greater<int>> q_right;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(q_left.size()==q_right.size())
        {
            if(q_left.size()==0||num<=q_left.top())   //num<=q_left.top()
            q_left.push(num);
            else
            {
                q_right.push(num);
                q_left.push(q_right.top());
                q_right.pop();
            }
        }
        else
        {
            if(num>q_left.top())
            q_right.push(num);
            else
            {
                q_left.push(num);
                q_right.push(q_left.top());
                q_left.pop();
            }
        }
    }
    
    double findMedian() {
        if(q_left.size()==q_right.size())
        return (q_left.top()+q_right.top())/2.0;
        return q_left.top();
    }
};

/* class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minqueue;
    priority_queue<int> maxqueue;
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxqueue.push(num);
        minqueue.push(maxqueue.top());
        maxqueue.pop();
        if(maxqueue.size() + 1 < minqueue.size()){
            maxqueue.push(minqueue.top());
            minqueue.pop();
        }
    }
    
    double findMedian() {
        if(minqueue.size() > maxqueue.size()){
            return minqueue.top();
        }
        else{
            return double(minqueue.top() + maxqueue.top()) / 2.0;
        }
    }
};
 */