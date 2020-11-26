#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s, answer = "";
    int sum = 0;
    vector<char> ch;
    cin >> s;

    /*받은 문자열을 char 자료형의 벡터에
      알파벳을 하나씩 넣어준다.*/
    for(int a = 0; a < s.length(); a++){
        if(s[a] > 64 && s[a] < 91){
            ch.push_back(s[a]);
        }
        else{
            //숫자형이면 숫자로 변환해 합을 구한다.
            sum += s[a] - '0';
        }
    }
    sort(ch.begin(), ch.end());

    /*정렬된 벡터로부터 다시 알파벳을 하나씩
      가져와 answer 문자열에 붙인다.*/
    for(int b = 0; b < ch.size(); b++){
        answer += ch[b];
    }
    answer += to_string(sum);
    
    cout << answer << endl;
    return 0;
}