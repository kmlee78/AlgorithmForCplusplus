#include <string>
#include <vector>

using namespace std;

vector<long long> solution(string s, string op) {
    vector<long long> answer;
    int length = s.length();
    int temp1, temp2;

    /*총 연산 횟수는 (s의 길이 - 1) 이고,
    각 연산마다 추출해야 할 문자열의 길이가
    첫 부분이 1씩 늘면 다른 부분이 1씩 줄어든다*/
    for(int a = 0; a < length-1; a++){
        temp1 = stoi(s.substr(0, a+1));
        temp2 = stoi(s.substr(a+1, length-a-1));
        if(op == "+"){
            answer.push_back(temp1+temp2);
        }else if(op == "-"){
            answer.push_back(temp1-temp2);
        }else{
            answer.push_back(temp1*temp2);
        }
    }
    return answer;
}