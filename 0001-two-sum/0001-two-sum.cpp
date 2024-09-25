class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;  // Create a hash map to store the numbers and their indices
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];  // Find the complement of the current number
            if (num_map.find(complement) != num_map.end()) {
                // If complement exists in the map, we found the pair
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;  // Otherwise, add the number to the map
        }
        return {};  // If no pair is found, return an empty vector
    }
};