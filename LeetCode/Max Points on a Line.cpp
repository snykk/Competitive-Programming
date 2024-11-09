class Solution {
public:
    int maxPoints(std::vector<std::vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return n;
        
        int maxPoints = 1; 
        
        for (int i = 0; i < n; ++i) {
            std::unordered_map<std::string, int> slopeCount;  
            int samePoint = 0;  
            int vertical = 0; 
            
            for (int j = i + 1; j < n; ++j) {
                if (points[i] == points[j]) {
                    samePoint++;
                    continue;
                }
                
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                if (dx == 0) {
                    vertical++;
                    continue;
                }
                
                int g = std::gcd(dx, dy);
                dx /= g;
                dy /= g;
                
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                
                std::string slope = std::to_string(dy) + "/" + std::to_string(dx);
                slopeCount[slope]++;
            }
            
            maxPoints = std::max(maxPoints, vertical + samePoint + 1);  
            for (auto& entry : slopeCount) {
                maxPoints = std::max(maxPoints, entry.second + samePoint + 1);
            }
        }
        
        return maxPoints;
    }
};
