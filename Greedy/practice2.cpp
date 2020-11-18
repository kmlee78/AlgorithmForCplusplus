#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    /*answer은 문자열 s의 첫번째 문자로 시작*/
    int answer = s[0] - '0';
    int length = s.length();

    /*answer가 1 이하 이거나 다음 문자열이 1 이하일 
      때만 더하기 그 외에는 전부 곱하기*/
    for(int a = 1; a < length; a++){
        if(s[a]-'0' <= 1 || answer <= 1){
            answer += s[a] - '0';
        }else{
            answer *= s[a] - '0';
        }
    }

    cout << answer << endl;
    return 0;
}
