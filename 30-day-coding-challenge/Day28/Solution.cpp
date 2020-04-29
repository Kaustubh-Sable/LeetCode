class FirstUnique {
    
    LinkedHashSet<Integer> unique;
    HashSet<Integer> hset;

    public FirstUnique(int[] nums) 
    {
        hset = new HashSet<Integer>();
        unique = new LinkedHashSet<Integer>();
    
        for(int num:nums)
        {
            if(!unique.contains(num) && !hset.contains(num))
            {
                unique.add(num);
            } 
            else 
            {
                if(unique.contains(num))
                {
                    unique.remove(num);
                    hset.add(num);
                }
            }
        }
    }
    
    public int showFirstUnique() 
    {
        if(unique.size()==0)
            return -1;
        for(int num : unique)
        {
            return num;
        }
        return -1;
    }
    
    public void add(int value) {
        if(!unique.contains(value) && !hset.contains(value))
        {
            unique.add(value);
        } else 
        {
            if(unique.contains(value))
            {
                unique.remove(value);
                hset.add(value);
            }            
        }
    }
}

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique obj = new FirstUnique(nums);
 * int param_1 = obj.showFirstUnique();
 * obj.add(value);
 */
