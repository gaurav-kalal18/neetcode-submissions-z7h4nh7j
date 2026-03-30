class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //last places are placeholder so start from and no need to overwrite nums1
    int i=m-1,j=n-1,k=m+n-1;
    while(i>=0 && j>=0) //stop when one array is exhausted 
    {
        if(nums1[i]>nums2[j])
        nums1[k--]=nums1[i--];

        else
        nums1[k--]=nums2[j--];
    }
    // dry run 456000 123

    while(j>=0) //no loop needed for i as those elements already at correct place
    {           //we only need to place nums2 elements
        nums1[k--]=nums2[j--];
    }
    }

};