class Solution {
public:
    int numJewelsInStones(string J, string S) {
        // 65 - 123
        bool arr[125];
        
        for(int i=65;i<=123;i++)
            arr[i] = false;
        
        for(int i=0;i<J.size();i++)
            arr[J[i]] = true;
        
        int count = 0;
        
        for(int i=0;i<S.size();i++)
        {
          if(arr[S[i]])
          {
            count++;
          }
        }
        
        return count;
    }
};
