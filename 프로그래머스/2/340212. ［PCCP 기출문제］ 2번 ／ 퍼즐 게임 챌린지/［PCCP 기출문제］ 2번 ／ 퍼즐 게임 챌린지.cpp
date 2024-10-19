#include <string>
#include <vector>

using namespace std;

// 전역 변수 선언
vector<int> global_diffs, global_times;
long long global_limit;

// 전역 변수 초기화 함수
void setInput(const vector<int>& diffs, const vector<int>& times, long long limit) {
    global_diffs = diffs;
    global_times = times;
    global_limit = limit;
}

// level에 따라 전체 소요 시간을 계산하는 함수
long long cal_time(int level) {
    long long total_time = 0;

    for (int i = 0; i < global_diffs.size(); i++) {
        if (global_diffs[i] > level) {
            int miss = global_diffs[i] - level;

            if (i > 0) {
                total_time += (miss + 1) * global_times[i] + miss * global_times[i - 1];
            } else {
                total_time += (miss + 1) * global_times[i];
            }
        } else {
            total_time += global_times[i];
        }
    }
    return total_time;
}

// 이진 탐색을 통해 최소 level을 찾는 함수
int find_min_level() {
    int st = 1;
    int en = 100000;
    int ret = en;

    while (st <= en) {
        int mid = (st + en) / 2;

        // level(mid)로 계산한 총 시간이 제한 시간 이내인지 확인
        if (cal_time(mid) <= global_limit) {
            ret = mid;
            en = mid - 1;  // 더 작은 level을 시도
        } else {
            st = mid + 1;  // 더 높은 level 필요
        }
    }

    return ret;
}

// solution 함수 (복사된 파라미터를 사용)
int solution(vector<int> diffs, vector<int> times, long long limit) {
    setInput(diffs, times, limit);  // 전역 변수 초기화
    return find_min_level();        // 최소 level 계산
}
