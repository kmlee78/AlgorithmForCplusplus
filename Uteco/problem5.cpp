#include <vector>
#include <string>

using namespace std;

string solution(string penter, string pexit, string pescape, string data) {
    string answer = penter;
    string temp;
    int length = penter.length();
    for(int a = 0; a < data.length(); a += length){

        /*penter의 길이만큼 data에서 추출한다*/
        temp = data.substr(a, length);

        /*추출 데이터가 세 binary bits 중 하나라도 같다면
        pescape를 삽입해준다*/
        if(temp == penter || temp == pexit || temp == pescape){
            answer += pescape;
        }
        answer += temp;
    }
    answer += pexit;
    return answer;
}
