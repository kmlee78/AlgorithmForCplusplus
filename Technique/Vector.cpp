#include <iostream>
#include <vector>

using namespace std;

int main(){
    /*vector의 정의 및 활용*/
    vector<int> num1;
    num1.push_back(1);               //1을 맨 뒤에서 넣어줌
    num1.push_back(2);               //2를 맨 뒤에서 넣어줌
    num1.push_back(3);
    num1.pop_back();                 //맨 뒤에 있는 값 3을 삭제
    cout << num1.size() << endl;     //2     벡터 크기

    /*num1의 값 그대로를 가지는 
    새로운 벡터 num2 탄생*/
    vector<int> num2(num1);

    vector<char> character(10, 'A');    //A를 10개 가지는 벡터 생성
    vector<int> num3(3, 9);             //9를 3개 가지는 벡터 생성
    
    /*벡터의 element 직접 지정*/
    vector<vector<int>> v{{1},{2,3},{4,5,6}};
    /*2차원 벡터의 크기 규정 및
      특정 값으로 초기화*/
    vector<vector<int>> v(3, vector<int>(3));
    vector<vector<int>> v(3, vector<int>(3,1));    //모든 요소가 1인 3X3 크기의 벡터
    
    
    
    /*num2의 요소들과 num3의 요소들
    서로 바꾸기*/
    num2.swap(num3);

    

    /*vector의 반복자 사용*/
    vector<int>::iterator it;
    for(it = num2.begin(); it != num2.end(); it++)
    {
        cout << *it << " ";                //9 9 9
    }         
 
    
    
    /*벡터 내 특정 원소 제거하기*/
    num1.erase(num1.begin());       //첫번째 원소 제거 v.erase(v.begin()+4); 하면 5번째 인덱스의 원소 제거
    
    /*벡터의 특정 구간 내 원소 제거*/
    vector<int> v(10, 3);
    v.erase(v.begin()+2, v.begin()+5);       //세 번째부터 다섯 번째 까지의 원소를 지움. 마지막꺼는 포함 안함
    
    
    
    /*기타*/
    cout << v.front();          //v의 첫 번째 원소를 참조
    cout << v.back();           //v의 마지막 원소를 참조
    v.clear();          //v의 모든 원소를 제거
    
    
    
    /*벡터 내 특정 값이 존재 하는지 확인하는 법*/
    vector<int> v;
    v.push_back(10);
    if (find(v.begin(), v.end(), 10) != v.end()){
        cout << "있다" << endl;
    }
}