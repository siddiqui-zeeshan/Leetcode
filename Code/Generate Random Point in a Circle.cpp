class Solution {
public:
    double x, y, r;
    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }
    
    vector<double> randPoint() {
        double t = (double)rand() / RAND_MAX * 2 * 3.14;
        double R = sqrt((double) rand() / RAND_MAX) * r;
        double X = R * sin(t) + x;
        double Y = R * cos(t) + y;
        return {X, Y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
