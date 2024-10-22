#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

vector<int> solution(vector<int> sequence, int k) 
{
    vector<int> answer(2);
    
    int n = sequence.size();
    
    int st = 0;
    int en = 0;
    
    int sum = sequence[0];

    int Length = INT_MAX;

    while (en < n) 
    {
        if (sum < k) 
        {
            en++;
            if (en < n)
            {
                sum += sequence[en];
            }
        } 
        else if (sum > k)
        {
            sum -= sequence[st];
            st++;
        } 
        else 
        {
            if (en - st < Length) 
            {
                Length = en - st;
                
                answer[0] = st;
                answer[1] = en;
            }
            
            sum -= sequence[st];
            st++;
        }
    }
    
    return answer;
}
