// Problem Link -> https://leetcode.com/problems/maximal-rectangle/

// Approach :- 
// * For every ith row we will calculate the height till ith row
// * And after this we will apply the same approach as we applied in Largest Area in Histogram


class Solution {
	int maxArea(vector<int>& heights, int n){
		int area = 0;
		stack<int> st;

		for(int i = 0; i <= n; i++){
			while(!st.empty() && (i == n || heights[st.top()] > heights[i])){
				int height = heights[st.top()];
				st.pop();
				int width = (st.empty() ? i : i - st.top() - 1);
				area = max(area, height * width);
			}
			st.push(i);
		}

		return area;
	}
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int area = 0;

        for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){
        		heights[j] += (matrix[i][j] == '0' ? -heights[j] : 1);
        	}
        	area = max(area, maxArea(heights, m));
        }

        return area;
    }
};