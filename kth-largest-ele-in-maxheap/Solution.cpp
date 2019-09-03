class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heapList;
	heapList.push_back(NULL);

	if (nums.size() < 1)
		return -1;

	heapList.push_back(nums[0]);
	
	int i = 1, ele, pos, temp;

	while (i < nums.size())
	{
		ele = nums[i];
		heapList.push_back(ele);

		pos = heapList.size() - 1;
		while (pos/2>=1 && heapList[pos / 2] < heapList[pos])
		{
			temp = heapList[pos / 2];
			heapList[pos / 2] = heapList[pos];
			heapList[pos] = temp;
			pos = pos / 2;
		}
		i++;
	}


	// Max Heap is created in heapList

	nums.clear();
	while (heapList.size() > 1)
	{
		nums.push_back(heapList[1]);

		heapList[1] = heapList[heapList.size() - 1];
		heapList.pop_back();

		pos = 1;
		while (pos * 2 < heapList.size() - 1)
		{
			if (pos * 2 + 1 < heapList.size() - 1 && heapList[pos * 2] < heapList[pos * 2 + 1])
			{
				if (heapList[pos] > heapList[pos * 2 + 1])
					break;

				temp = heapList[pos * 2 + 1];
				heapList[pos * 2 + 1] = heapList[pos];
				heapList[pos] = temp;
				pos = pos * 2 + 1;
			}
			else
			{
				if (heapList[pos] > heapList[pos * 2])
					break;

				temp = heapList[pos * 2];
				heapList[pos * 2] = heapList[pos];
				heapList[pos] = temp;
				pos = pos * 2;
			}
		}
	}
        
        return nums[k-1];
    }
};
