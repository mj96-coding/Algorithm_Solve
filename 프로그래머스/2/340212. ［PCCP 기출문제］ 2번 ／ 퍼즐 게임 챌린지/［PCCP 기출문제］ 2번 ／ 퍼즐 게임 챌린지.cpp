#include <string>
#include <vector>

using namespace std;

long long cal_time(int level, const vector<int>& diffs, const vector<int>& times) 
{
    // level에 따라 전체 소요 시간을 계산하는 함수
    long long total_time = 0;

    for (int i = 0; i < diffs.size(); i++) 
    {
        if (diffs[i] > level)
        {
            int miss = diffs[i] - level;

            if (i > 0)
            {
                total_time += (miss + 1) * times[i] + miss * times[i - 1];
            }
            else
            {
                total_time += (miss + 1) * times[i];
            }
        }
        else 
        {
            total_time += times[i];
        }
    }
    return total_time;
}

int solution(vector<int> diffs, vector<int> times, long long limit)
{
    // 1부터 시작
    int st = 1;
    int en = 100000;
    int ret = en;

    while (st <= en)
    {
        int mid = (st + en) / 2;
        
        // level(mid) 값을 통해 계산한 총 시간
        if (cal_time(mid, diffs, times) <= limit)
        {  
            // 더 작은 level을 시도
            // 여기서 답 구함
            ret = mid;  
            en = mid - 1;
        }
        else 
        {
            // 제한 시간 초과 더 높은 level 필요
            st = mid + 1;  
        }
    }

    return ret;
}
