#include <string>
#include <vector>

using namespace std;

string c_s;

void setInput(const string& s)
{
    c_s = s;
}

int calculation(string a)
{
    return stoi(a);    
}

int solution(string s)
{
    int answer = 0;
    
    setInput(s);
    
    answer=calculation(c_s);
    
    return answer;
}