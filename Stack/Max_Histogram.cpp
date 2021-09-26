/* https://leetcode.com/problems/largest-rectangle-in-histogram/ */

// Approach - 1
// * Calculate Next Smaller Element to Right
// * Calculate Next Smaller Element to Left
// * Using These we can calculate width for every height;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        stack<pair<int, int>> nsl;
        vector<int> left;
        
        for(int i = 0; i < n; i++){
            if(nsl.empty()){
                left.push_back(-1);
            }
            else if(!nsl.empty() && nsl.top().first < heights[i]){
                left.push_back(nsl.top().second);
            }
            else{
                while(!nsl.empty() && nsl.top().first >= heights[i]){
                    nsl.pop();
                }
                if(nsl.empty()){
                    left.push_back(-1);
                }
                else{
                    left.push_back(nsl.top().second);
                }
            }
            nsl.push(make_pair(heights[i], i));
        }
        
        while(!nsl.empty()){
            nsl.pop();
        }
        
        vector<int> right;
        
        for(int i = n - 1; i >= 0; i--){
            
            if(nsl.empty()){
                right.push_back(n);
            }
            else if(!nsl.empty() && nsl.top().first < heights[i]){
                right.push_back(nsl.top().second);
            }
            else{
                while(!nsl.empty() && nsl.top().first >= heights[i]){
                    nsl.pop();
                }
                
                if(nsl.empty()){
                    right.push_back(n);
                }
                else{
                    right.push_back(nsl.top().second);
                }
            }
            nsl.push(make_pair(heights[i], i));
        }
        
        reverse(right.begin(), right.end());
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            ans = max(ans, heights[i] * width);
        }
       
        return ans;
    }
};

// TC -> O(2N)
// SC -> O(2N)
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// Approach - 2
// For this we will maintain our stack in linearly increasing manner, and whenever I encounter a element which is greater than 
// top of the stack then for that top element we will calculate our ans, we will do this till we get a element which lesser than the current element

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        stack<int> st;
        int area = 0;
        
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width = i;
                }
                else{
                    width = i - st.top() - 1;
                }
                area = max(area, height * width);
            }
            st.push(i);
        }
        
        return area;
    }
};

// TC -> O(2N)
// SC -> O(N)