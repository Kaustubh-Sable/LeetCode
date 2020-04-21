/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims = binaryMatrix.dimensions();
        int row = 0;
        int col = dims[1]-1;
        
        while(row<dims[0] && col>=0)
        {
            if(binaryMatrix.get(row,col)==1)
                col--;
            else
                row++;
        }
        
        if(col==dims[1]-1)
            return -1;
        
        return col+1;
    }
};
