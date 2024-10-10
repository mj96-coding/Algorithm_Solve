#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> ans(nums.begin(),nums.end());
    
    return min(nums.size()/2,ans.size());
}