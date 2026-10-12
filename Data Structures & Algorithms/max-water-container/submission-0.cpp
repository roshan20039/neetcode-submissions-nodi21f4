class Solution {
public:
    int maxArea(vector<int>& heights) {
        //max((j-i) * min(height[i], height[j]))
        int n = heights.size();
        int i = 0, j = n-1, maxarea = 0;
        while(i < j) {
            int area = abs(j-i)*min(heights[i], heights[j]);
            maxarea = max(area, maxarea);
            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return maxarea;
    }
};
