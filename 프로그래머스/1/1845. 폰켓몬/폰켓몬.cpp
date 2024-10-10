#include <vector>

using namespace std;



int solution(vector<int> nums)
{
    int answer = 0;
    
    int dat[200001]={};    
    
    int cnt=0;
    
    for(int i : nums)
    {
        if(dat[i]==0)
        {
            dat[i]=1;
            cnt++;
        }
    }
    
    if(cnt >= nums.size()/2)
    {
        answer=nums.size()/2;
    }
    else
    {
        answer=cnt;
    }
    
    
    return answer;
}