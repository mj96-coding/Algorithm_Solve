#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    // 전화번호부를 정렬
    sort(phone_book.begin(), phone_book.end());
    
    // 인접한 전화번호들을 비교하여 접두어 관계가 있는지 확인
    for (int i = 0; i < phone_book.size() - 1; ++i) {
        // 앞 전화번호가 뒷 전화번호의 접두사인지 확인
        if (phone_book[i + 1].find(phone_book[i]) == 0) {
            answer = false;
            break;
        }
    }
    
    return answer;
}
