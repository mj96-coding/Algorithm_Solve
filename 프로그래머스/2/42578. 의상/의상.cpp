#include <string>
#include <vector>

using namespace std;

struct ClothesType {
    string type;
    int count;
};

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<ClothesType> clothes_count; // 의상 종류와 개수를 저장할 벡터
    
    // 의상 종류별로 개수 세기
    for (int i = 0; i < clothes.size(); i++) {
        string cloth_type = clothes[i][1];
        bool found = false;
        for (int j = 0; j < clothes_count.size(); j++) {
            if (clothes_count[j].type == cloth_type) {
                clothes_count[j].count++;
                found = true;
                break;
            }
        }
        if (!found) {
            ClothesType new_type = {cloth_type, 1};
            clothes_count.push_back(new_type);
        }
    }
    
    // 각 종류의 의상 수 + 1(해당 종류의 의상을 입지 않는 경우)을 곱하기
    for (int i = 0; i < clothes_count.size(); i++) {
        answer *= (clothes_count[i].count + 1);
    }
    
    // 아무것도 입지 않는 경우(1가지) 제외
    return answer - 1;
}
