class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        
        unordered_map<int, int> hash;
        vector<int> v;
        
        for(int i = 0; i < numbers.size(); i++)
        {
            hash[numbers[i]] = i;
        }
        
        for(int i = 0; i < numbers.size(); i++)
        {
            int tmp = target - numbers[i];
            if( hash.count(tmp) > 0 )
            {
                int r = hash[tmp];
                if( r < i )
                {
                    v.push_back(r+1);
                    v.push_back(i+1);
                    return v;
                }
                else if(r > i)
                {
                    v.push_back(i+1);
                    v.push_back(r+1);
                }
            }
        }
    }
};