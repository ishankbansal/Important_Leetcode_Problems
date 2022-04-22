/*
Problem link -> https://leetcode.com/problems/sliding-window-maximum/

Approach :- 
* we will maintain a deque in decreasing fashion by which always front element is our answer
* we will pop out all the elements from the deque which are less than current element
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq;
        vector<int> res;
        
        for(int i = 0; i < n; i++){
            if(!dq.empty() && dq.front() == i - k){
                dq.pop_front();
            }
            while(!dq.empty() && arr[dq.back()] < arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i + 1 >= k){
                res.push_back(arr[dq.front()]);
            }
        }
        
        return res;
    }
};