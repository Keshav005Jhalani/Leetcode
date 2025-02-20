class Solution {
public:
    class Car {
    public:
        int pos;
        int speed;
        Car(int p, int s) : pos(p), speed(s) {}
    };

    static bool myComp(Car &a, Car &b) {
        return a.pos < b.pos;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;
        vector<Car> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back(Car(position[i], speed[i]));
        }
        sort(cars.begin(), cars.end(), myComp);
        stack<float> st; 
        for (auto car : cars) {
            float time = (target - car.pos) / (float)car.speed;
            while(!st.empty()&&time >= st.top()) {
                st.pop();
            }   
            st.push(time);
        }
        return st.size();
    }
};
