class Solution {
public:
    string frequencySort(string s) {
        map<char,int> count;
        for(int i=0;i<s.size();i++)
        {
            count[s[i]]++;
        }
        
        priority_queue<pair<int,char>> pq;
        for (map<char,int>::iterator it=count.begin(); it!=count.end(); ++it)
            pq.push(make_pair(it->second, it->first));
        
        string ans="";
        while (!pq.empty()) 
        { 
            int n = pq.top().first;
            char c = pq.top().second;
            for(int i=0;i<n;i++)
                ans+=c;
            pq.pop(); 
        }
        
        return ans;
    }
};
