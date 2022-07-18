class MedianFinder {
public:
    priority_queue<int, vector<int>> pqmax;
    priority_queue<int, vector<int>, greater<int>> pqmin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pqmax.size() == pqmin.size()){
            if(pqmax.size() == 0){
                pqmax.push(num);
            }
            else if(num < pqmax.top()){
                pqmax.push(num);
            }
            else{
                pqmin.push(num);
            }
        }
        else{
            if(pqmax.size() > pqmin.size()){
                if(num >= pqmax.top()){
                    pqmin.push(num);
                }
                else{
                    int val = pqmax.top();
                    pqmax.pop();
                    pqmin.push(val);
                    pqmax.push(num);
                }
            }
            else{
                if(num <= pqmin.top()){
                   pqmax.push(num);
                }
                else{
                    int val = pqmin.top();
                    pqmin.pop();
                    pqmin.push(num);
                    pqmax.push(val);
                }
            }
        }
    }
    
    double findMedian() {
        if(pqmin.size() == pqmax.size()){
            double ans = (pqmin.top() + pqmax.top())/2.0;
            return ans;
        }
        else if(pqmax.size() > pqmin.size()){
            return pqmax.top();
        }
        else{
            return pqmin.top();
        }
    }
};