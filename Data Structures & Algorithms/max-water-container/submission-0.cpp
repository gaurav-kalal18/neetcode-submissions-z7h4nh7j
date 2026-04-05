class Solution {
public:
    int maxArea(vector<int>& height) {
        long long l=0;
        long long r=height.size()-1;
        long long a=0;
        long long ans=0;
        while(l<r)
        {
            long long x=min(height[l],height[r]);
            long long y=r-l;;
            a=x*y;
            ans=max(ans,a);
            if(height[r]>height[l]) l++;
            else r--;
        }

        return ans;
        
    }
};