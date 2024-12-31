class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size() - 1;

        while (high - low >= k) {
            if (x - arr[low] > arr[high] - x) {
                low++; 
            } else if (x - arr[low] == arr[high] - x) {
                if (arr[low] < arr[high]) {
                    high--;
                } else {
                    low++;
                }
            } else {
                high--;
            }
        }
        return vector<int>(arr.begin() + low, arr.begin() + high + 1);
    }
};