#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*concept1 문제랑은 다르게 고려해야 할 요소가 4개나 있으니
  단순히 pair나 map을 이용해서 풀기 힘들다. 그럴 경우 
  class를 이용하여 안의 속성들을 정렬하는 방식으로 푼다.*/
class Student {
public:
    string name;
    int kor, eng, math;

    Student(string name, int kor, int eng, int math){
        this->name = name;
        this->kor = kor;
        this->eng = eng;
        this->math = math;
    }

    /*이 메소드를 기억해 두자. 객체 끼리
      비교할 수 있는 기준을 세워 주는 메소드다.*/
    bool operator <(Student &other){
        if(this->kor == other.kor){
            if(this->eng == other.eng){
                if(this->math == other.math){
                    return this->name < other.name;
                }else{
                    return this->math > other.math;
                }
            }else{
                return this->eng < other.eng;
            }
        }else{
            return this->kor > other.kor;
        }
    }
};

int main(){
   int n;
   string name;
   int kor, eng, math;
   vector<Student> scores;
   cin >> n;
   for(int a = 0; a < n; a++){
        cin >> name >> kor >> eng >> math;

        /*이름과 점수들을 입력 받을 때 마다 객체를 생성자를 통해
          생성하여 scores 벡터 안에 넣어준다.*/
        scores.push_back(Student(name, kor, eng, math));
   }

   /*sort 함수에 따라 정렬을 수행하면 operator 메소드의
     정렬 방식에 따라 정렬이 수행된다.*/
   sort(scores.begin(), scores.end());

   for(int b = 0; b < n; b++){
        cout << scores[b].name << endl;
   }
   return 0;
}
