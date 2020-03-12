class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wc_map;
        
        for(int i=0;i<words.size();i++)
        {
            if(wc_map.find(words[i])==wc_map.end())
            {
                wc_map[words[i]] = 0;
            }
            wc_map[words[i]]++;
        }
        
        vector<pair<string,int>> temp;
        for(auto i:wc_map)
        {
            temp.push_back(make_pair(i.first, i.second));
        }
        
        typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;
 
	    Comparator compFunctor =
			[](std::pair<std::string, int> elem1 ,std::pair<std::string, int> elem2)
			{
                if(elem1.second == elem2.second)
                {
                    return elem1.first.compare(elem2.first)<0;
                }
				return elem1.second > elem2.second;
			};
 
        sort(temp.begin(), temp.end(), compFunctor);
        
        vector<string> ans;
        for (int i=0;i<k;i++)
        {
            ans.push_back(temp[i].first);
        }
        
        return ans;
    }
};
