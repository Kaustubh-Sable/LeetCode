class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        
        int i=0,j=0, as=A.size(), bs=B.size();
        while(i<as && j<bs)
        {
            vector<int> temp;
            if(A[i][0]<=B[j][0])
            {
                if(A[i][1]<B[j][0])
                {
                    i++;
                    continue;
                }
                temp.push_back(B[j][0]);
                if(B[j][1]>A[i][1])
                {
                    temp.push_back(A[i][1]);
                    i++;
                } else if(B[j][1]<A[i][1])
                {
                    temp.push_back(B[j][1]);
                    j++;
                } else
                {
                    temp.push_back(A[i][1]);
                    i++;
                    j++;
                }
            }
            else
            {
                if(B[j][1]<A[i][0])
                {
                    j++;
                    continue;
                }
                temp.push_back(A[i][0]);
                if(A[i][1]>B[j][1])
                {
                    temp.push_back(B[j][1]);
                    j++;
                } else if(A[i][1]<B[j][1])
                {
                    temp.push_back(A[i][1]);
                    i++;
                } else
                {
                    temp.push_back(B[j][1]);
                    i++;
                    j++;
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};
