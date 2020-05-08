class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double slope, x1,x2,y1,y2;        
        
        x1 = coordinates[0][0];
        x2 = coordinates[1][0];
        y1 = coordinates[0][1];
        y2 = coordinates[1][1];
        slope = (y2-y1)/(x2-x1);
        
        for(int i=2;i<coordinates.size();i++)
        {
            x1 = coordinates[i-1][0];
            x2 = coordinates[i][0];
            y1 = coordinates[i-1][1];
            y2 = coordinates[i][1];
            
            if((y2-y1)/(x2-x1) != slope)
                return false;
        }
        
        return true;
    }
};
