class Solution {
public:
    void leftrotate(string &s, int d) 
    { 
        reverse(s.begin(), s.begin()+d); 
        reverse(s.begin()+d, s.end()); 
        reverse(s.begin(), s.end()); 
    } 

    // void rightrotate(string &s, int d) 
    // { 
    //    leftrotate(s, s.length()-d); 
    // }
    
    string stringShift(string s, vector<vector<int>>& shift) {
        int leftCount = 0;
        
        for(int i=0;i<shift.size();i++)
        {
            if(shift[i][0]==0)
                leftCount += shift[i][1];
            else
                leftCount -= shift[i][1];
        }
        
        cout<<leftCount;
        
        if(leftCount>0)
            leftrotate(s, leftCount%s.length());
        else if(leftCount<0)
            leftrotate(s, s.length()-abs(leftCount)%s.length());
        
        return s;
    }
};
