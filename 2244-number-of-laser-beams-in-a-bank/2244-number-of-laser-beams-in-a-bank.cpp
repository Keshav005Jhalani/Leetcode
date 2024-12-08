class Solution {
public:
    int countInRow(const string &str) {
        int count = 0;
        for (char ch : str) {
            if (ch == '1') count++;
        }
        return count;
    }

    int numberOfBeams(vector<string>& bank) {
        vector<int> devices;
        int beams = 0;

        // Store counts of devices in rows with at least one device
        for (const auto& row : bank) {
            int count = countInRow(row);
            if (count > 0) devices.push_back(count);
        }

        // Calculate beams between consecutive rows with devices
        for (size_t i = 1; i < devices.size(); i++) {
            beams += devices[i - 1] * devices[i];
        }

        return beams;
    }
};
