#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1 = "abcde";
    cout << s1.empty() << endl;     //0     비어있으면 1 반환
    cout << s1.length() << endl;    //5     문자열의 길이
    s1.clear();                     //string 비워주기
    cout << s1 << endl;             //아무것도 없는 빈칸 반환


    s1 = "abcde";
/*substr 을 이용해 문자열의 일부분을 추출할 수 있다. 
  문자열.substr(추출을 시작할 index번호, 추출할 문자의 수)*/
    string s2 = s1.substr(1,2);
    cout << s2 << endl;         //bc
    

/*문자열의 특정 부분을 지우는 방법
  문자열.erase(시작 위치, 지울 문자 개수);*/
    string ss = "abcde";
    cout << ss << endl;         //abcde
    ss.erase(1, 2);             //1번 인덱스 부터 두개의 요소를 지운다
    cout << ss << endl;         //ade


/*두 문자열을 비교할 수 있다.
같으면 0 반환*/
    string s3 = "abcde";
    cout << s1.compare(s3) << endl;     //0


/*두 문자열의 사전적 순서*/
    if(s1 < s2)
    {
        cout << "s2가 사전적으로 뒤에 있음" << endl;    //s2가 사전적으로 뒤에 있음
    }    


/*문자를 숫자로 바꾸는 방법*/
    char num = '9';             //한자릿수 일 때
    int k = num - '0';          //- '0'을 이용한다
    cout << k << endl;          //9
    
    string number = "12345";        //한자릿수 이상일 때
    int intNumber = stoi(number);       //stoi 함수 사용. 이 말고도 stod나 stol도 있다
    cout << intNumber << endl;      //12345
    //cout << stoi(number,nullptr,8);    8진수의 number을 10진수로 바꿔준다
    
    
    
/*숫자를 문자열로 바꾸기
  to_string()*/
    int sNum = 1234;
    string temp = to_string(sNum);      //to_string 함수를 사용
    


/*문자열의 대소문자 변환
  toupper(), tolower()*/
    string hello = "HellO WorLd";
    for(int i = 0; i < hello.length(); i++){
        hello[i] = toupper(hello[i]);       //소문자를 대문자로 변환
    }
    cout << hello << endl;                  //HELLO WORLD
    
    for(int i = 0; i < hello.length(); i++){
        hello[i] = tolower(hello[i]);       //대문자를 소문자로 변환
    }
    cout << hello << endl;                  //hello world
    
    
    
/*문자열 추가하는 법
      문자열.append(추가할 문자열);          추가할 문자열을 맨 끝에 추가함
      문자열.append(추가할 문자열, 시작위치, 개수);        추가할 문자열의 시작 위치부터 개수만큼만 맨 끝에 추가함
      문자열.append(개수, 추가할 문자);       추가할 문자를 개수만큼 맨 끝에 추가함*/
    string add = "abcde";
    string input1, input2, input3;
    input1.append(add);          //abcde
    input2.append(add, 3, 2);       //de
    input3.append(3,'x');           //xxx
    
    
    
/*특정 문자열을 찾아 그 시작 위치를 리턴
    문자열.find(찾을 문자열);
    문자열.find(찾을 문자);
    문자열.find(찾을 문자열, 시작 위치);    시작 위치부터 문자열을 찾음*/
    string findme = "abcdefgh";
    cout << findme.find("efg") << endl;         //4
    cout << findme.find('b') << endl;           //1
    cout << findme.find("hij") << endl;         //존재하지 않을 경우 쓰레기값 
    
    
    
/*특정 문자열을 찾아 다른 문자열로 대체하는 법
    문자열.replace(대체할 문자열 시작 위치, 대체할 문자열 길이, 새로운 문자열);*/
    string repl = "I am a good man";
    repl.replace(7, 4, "bad");
    cout << repl << endl;       //I am a bad man    
}