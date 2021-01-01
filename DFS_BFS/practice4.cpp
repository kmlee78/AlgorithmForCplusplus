#include <string>
#include <vector>

using namespace std;

/*문자열의 괄호 방향을 뒤집어서 리턴하는 함수*/
string change(string u){
    for(int a = 0; a < u.length(); a++){
        if(u[a] == '(') u[a] = ')';
        else u[a] = '(';
    }
    return u;
}

/*해당 문자열이 올바른 괄호 문자열인지 올바르지 않은
  괄호 문자열인지 리턴하는 bool형 함수*/
bool check(string u){
    int num1 = 0, num2 = 0;
    for(int a = 0; a < u.length(); a++){
        if(u[a] == '(') num1++;
        else num2++;
        if(num2 > num1) return false;
    }
    return true;
}

/*주어진 문자열을 u, v 두개의 문자열로 나누고 u의 올바름 유무에 따라
  적절한 수행을 통해 완성된 문자열을 반환하는 함수*/
string process(string w){
    if(w == "") return "";
    string u, v;
    int num1 = 0, num2 = 0, counting = 0;
    for(int a = 0; a < w.length(); a++){
        if(w[a] == '(') num1++;
        else num2++;
        counting++;

        if(num1 == num2){
            u = w.substr(0, counting);
            v = w.substr(counting, w.length()-counting);
            break;
        }
    }

    if(check(u)) return u + process(v);
    else return "(" + process(v) + ")" + change(u.substr(1, u.length()-2));
}

/*여기서부터 시작!*/
string solution(string p){
    string answer = "";
    answer = process(p);
    return answer;
}