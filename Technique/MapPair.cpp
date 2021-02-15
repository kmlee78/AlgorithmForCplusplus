#include <iostream>
#include <map>

using namespace std;

int main(){

/*map 만들기*/
    map<string, int> m;     //key값의 자료형은 string, value값의 자료형은 int
    m["a"] = 1;
    m["b"] = 2;
    m["c"] = 3;
    cout << m["c"] << endl;     //3

    m.erase("a");       //해당 key값 지움

    /*여기서 만약 cout << m["a"];를 하게 된다면
    0으로 출력되지만 그와 동시에 m["a"]를 생성
    하게 되므로 m.size()는 3이 된다*/
    
    m.empty();          //비어있으면 true
    cout << m.size() << endl;   //2  원소들의 수


/*pair 만들기*/
    pair<int, string> a;       //각각의 data type
    a = make_pair(1,"name");
    cout << a.first  << " " << a.second << endl;   //1 name 첫번째, 두번째 인자 출력

    pair<int,int> b;
    b = pair<int, int>(1,2);   //이렇게도 기입 가능
    cout << b.first << " " << b.second << endl;     //1 2
}