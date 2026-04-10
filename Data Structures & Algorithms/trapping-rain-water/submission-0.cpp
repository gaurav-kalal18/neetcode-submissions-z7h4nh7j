class Solution {
public:
    //my solution
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int lm = 0, rm = 0;
        int ans = 0;

        while (left < right) {
            if (height[left] < height[right]) {  //water bounded by small so work on small
                if (height[left] >= lm)
                    lm = height[left];

                else
                    ans += lm - height[left]; //check by urself

                left++;

            }
            //sismilar for right
            else {

                if (height[right] >= rm)
                    rm = height[right];

                else
                    ans += rm - height[right];

                right--;
            }
        }
        return ans;
    }

    
}

;