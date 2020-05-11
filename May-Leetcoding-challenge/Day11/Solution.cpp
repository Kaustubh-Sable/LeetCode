class Solution {
public:
    vector<vector<int>> floodFillHelper(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
        if(image.size()==0 || sr==image.size() || sr<0 || sc==image[0].size() || sc<0 || 
           image[sr][sc]==newColor || image[sr][sc]!=oldColor)
            return image;
        
        image[sr][sc] = newColor;
        
        floodFillHelper(image, sr+1, sc, newColor, oldColor);
        floodFillHelper(image, sr, sc+1, newColor, oldColor);
        floodFillHelper(image, sr-1, sc, newColor, oldColor);
        floodFillHelper(image, sr, sc-1, newColor, oldColor);
        
        return image;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size()==0)
            return image;
        
        int oldColor = image[sr][sc];
        
        return floodFillHelper(image, sr, sc, newColor, oldColor);
    }
};
