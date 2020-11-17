#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;

    /*연속되는 0의 개수, 연속되는 1의 개수를
      array이름의 배열안에 저장. status변수
      를 통해 숫자가 변하는지 판단*/
    int array[2] = {0, 0}, length = s.length();
    int status = s[0] - '0';
    
    array[status]++;
    for(int a = 1; a < length; a++){
        if(s[a] - '0' != status){
            array[s[a]-'0']++;
            status = s[a] - '0';
        }
    }

    cout << min(array[0], array[1]) << endl;
    return 0;
}