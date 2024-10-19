//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

//The overall run time complexity should be O(log (m+n)).


//Most Optimal Solution: Using Binary Search TC: O(log(m+n))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n1;
        int n = (n1 + n2);
        int left = (n + 1) / 2;
        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if ((mid1 - 1) >= 0)
                l1 = nums1[mid1 - 1];
            if ((mid2 - 1) >= 0)
                l2 = nums2[mid2 - 1];
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            } else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }

        /// BETTER SOLUTION START TC: O(m+n)
        
        // int n1 = nums1.size(), n2 = nums2.size();
        // int i = 0, j = 0;
        // int n = n1 + n2;
        // int cnt = 0;
        // int ind2 = n / 2;
        // int ind1 = ind2 - 1;
        // int ind1el = -1, ind2el = -1;
        // while (i < n1 && j < n2) {
        //     if (nums1[i] < nums2[j]) {
        //         if (cnt == ind1)
        //             ind1el = nums1[i];
        //         if (cnt == ind2)
        //             ind2el = nums1[i];
        //         cnt++;
        //         i++;
        //     } else {
        //         if (cnt == ind1)
        //             ind1el = nums2[j];
        //         if (cnt == ind2)
        //             ind2el = nums2[j];
        //         cnt++;
        //         j++;
        //     }
        // }
        // while (i < n1) {
        //     if (cnt == ind1)
        //         ind1el = nums1[i];
        //     if (cnt == ind2)
        //         ind2el = nums1[i];
        //     cnt++;
        //     i++;
        // }
        // while (j < n2) {
        //     if (cnt == ind1)
        //         ind1el = nums2[j];
        //     if (cnt == ind2)
        //         ind2el = nums2[j];
        //     cnt++;
        //     j++;
        // }

        // if(n%2==1){
        //     return ind2el;
        // }

        // return (double)((double)(ind1el+ind2el))/2.0;
        return 0;
    }
};