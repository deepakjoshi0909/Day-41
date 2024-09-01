#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int visiblePoints(std::vector<std::vector<int>>& points, int angle, std::vector<int>& location) {
        std::vector<double> angles;
        int sameLocationCount = 0;
        
        for (const auto& point : points) {
            int dx = point[0] - location[0];
            int dy = point[1] - location[1];
            
            if (dx == 0 && dy == 0) {
                sameLocationCount++;
                continue;
            }
            
            double ang = atan2(dy, dx) * 180 / M_PI;
            angles.push_back(ang);
        }
        
        std::sort(angles.begin(), angles.end());
        
        int n = angles.size();
        for (int i = 0; i < n; ++i) {
            angles.push_back(angles[i] + 360);
        }
        
        int maxPoints = 0;
        int j = 0;
        
        for (int i = 0; i < n; ++i) {
            while (j < angles.size() && angles[j] <= angles[i] + angle) {
                j++;
            }
            maxPoints = std::max(maxPoints, j - i);
        }
        
        return maxPoints + sameLocationCount;
    }
};
