class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nBugs = graph.size();
        int i, j, front, neighbourBugGroup;
	vector<int> bugGroup(nBugs), visited(nBugs);
	queue<int> bugQueue;

	for (i = 0; i < nBugs; i++)
	{
		bugGroup[i] = 0;
		visited[i] = false;
	}

	for (i = 0; i < nBugs; i++)
	{
		if (graph[i].size() <= 0 || visited[i] == true)
			continue;
		bugGroup[i] = 1;
		visited[i] = true;
		bugQueue.push(i);

		while (bugQueue.size() > 0)
		{
			front = bugQueue.front();
			visited[front] = true;
			bugQueue.pop();

			for (j = 0; j < graph[front].size(); j++)
			{
				neighbourBugGroup = bugGroup[graph[front][j]];
				if (neighbourBugGroup != 0 && neighbourBugGroup == bugGroup[front])
					return false;
				if (neighbourBugGroup != 0)
					continue;
				if (neighbourBugGroup == 0 && bugGroup[front] == 1)
					bugGroup[graph[front][j]] = 2;
				else
					bugGroup[graph[front][j]] = 1;
				bugQueue.push(graph[front][j]);
			}
		}
	}

	return true;
    }
   
};
