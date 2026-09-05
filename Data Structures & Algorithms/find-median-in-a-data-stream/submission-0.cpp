#include<bits/stdc++.h>
class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int,vector<int>,greater<int>> minH;
    MedianFinder() {
        maxH = priority_queue<int>();
        minH = priority_queue<int,vector<int>,greater<int>>();
    }
    
    void addNum(int num) {
        if(!minH.empty()&&num>minH.top())
           minH.push(num);
        else if (!maxH.empty()&&num<maxH.top())
           maxH.push(num);
        else
            minH.push(num);
       if(abs((int)maxH.size() - (int)minH.size()) > 1)
        {
            if(maxH.size()>minH.size())
                {
                    minH.push(maxH.top());
                    maxH.pop();
                }
            else
                {
                    maxH.push(minH.top());
                    minH.pop();
                }
        }   
    }
    
    double findMedian() {

       if(maxH.size()>minH.size())
            return (double)maxH.top();
        else if (maxH.size()<minH.size())
            return (double)minH.top();
        else 
            return ((double)minH.top()+(double)maxH.top())/2;
        

    }
};
