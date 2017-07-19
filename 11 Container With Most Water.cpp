class Solution {
public:
    int maxArea(vector<int>& height) {
		int maxA = 0;
		int x = 0;
		int y = height.size()-1;
		while (x < y ){
			maxA = max(maxA,min(height[x] ,height[y]) * ( y - x ));
			if(height[x] <= height[y]){
				x ++ ;
				continue;
			}
			else if(height[y] < height[x]){
				y --;
				continue;
			}
		}
		return maxA;
    }
};