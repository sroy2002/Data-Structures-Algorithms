//Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.


//time complexity: O(n*maxElement)



//Optimal Solution using Binary Search
class Solution {
private:
    bool calculate(vector<int>& piles, int rate, int deadline) {
        int totalHours = 0;
        for (int i = 0; i < piles.size(); i++) {
            // totalHours += ceil((double)piles[i] / (double)rate);
            totalHours += (piles[i] + rate - 1) / rate;
            if (totalHours > deadline)
                return false;
        }

        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxNum = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxNum;
        int ans = 0;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (calculate(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};