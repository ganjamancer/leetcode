class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        v=nums1;
        double ans;
        for(int i=0;i<nums2.size();i++){v.push_back(nums2[i]);}
        sort(v.begin(),v.end());
        int n=v.size();
        if(n%2==0){ans=(v[n/2]+v[n/2-1])/2.0;}
        else ans=v[n/2];

        return ans;
    }
};
