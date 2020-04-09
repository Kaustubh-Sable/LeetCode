class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int nS=S.size();
        vector<char> sv;
        for(int i=0;i<nS;i++)
        {
            if(S[i]=='#')
            {
                if(sv.size()>0)
                {
                    sv.pop_back();
                }
            }
            else
            {
                sv.push_back(S[i]);
            }
        }
        
        int nT=T.size();
        vector<char> tv;
        for(int i=0;i<nT;i++)
        {
            if(T[i]=='#')
            {
                if(tv.size()>0)
                {
                    tv.pop_back();
                }
            }
            else
            {
                tv.push_back(T[i]);
            }
        }
        
        string newS(sv.begin(), sv.end());
        string newT(tv.begin(), tv.end());
        
        return (newS.compare(newT)==0);
    }
};
