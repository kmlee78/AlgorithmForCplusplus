#include <iostream>
#include <sstream>

using namespace std;

int main(){

    /*stringstream은 문자열 내 빈칸으로 구분되어 있는
    각각의 문자열들을 구별하는 역할을 해준다*/
     
    string s1 = "ab cd ef gh";
    string s2 = "fig dhe swe";

    stringstream ss(s1);        //s1을 읽어줄 것임
    string k;                   //읽어줄 변수를 지정

    while(ss >> k)
    {
        cout << k << " ";       //ab cd ef gh       빈칸 무시
    }
    cout << endl;

    ss.clear();             //다른 문자열을 읽어주기 위해선 한번 초기화 해야됨
    ss.str(s2);             //s2를 읽어줄 거다

    while(ss >> k)
    {
        cout << k << " ";       //fig dhe swe
    }
}