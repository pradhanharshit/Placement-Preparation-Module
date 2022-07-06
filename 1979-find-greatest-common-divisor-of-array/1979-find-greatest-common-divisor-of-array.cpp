class Solution {
public:
    int euclid(int a, int b){
        if(b==0)
            return a;
        return euclid(b,a%b);
    }
    
    int findGCD(vector<int>& nums) {
        int largest = max(nums[0],nums[1]);
        int smallest = min(nums[0],nums[1]);
        
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] > largest)
                largest = nums[i];
            if(nums[i] < smallest)
                smallest = nums[i];
        }
        return euclid(smallest,largest);
    }
};