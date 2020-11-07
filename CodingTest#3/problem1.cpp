#include <vector>
#include <string>

using namespace std;

int solution(vector<string> grades, vector<int> weights, int threshold) {
    int answer = -1234567890;

    /*새로운 벡터 temp를 만들어 그 안에 학점에 따른
    점수값을 넣음*/
    vector<int> temp;
    int total = 0;
    for(int a = 0; a < grades.size(); a++){
        if(grades[a] == "A+"){
            temp.push_back(10);
        }else if(grades[a] == "A0"){
            temp.push_back(9);
        }else if(grades[a] == "B+"){
            temp.push_back(8);
        }else if(grades[a] == "B0"){
            temp.push_back(7);
        }else if(grades[a] == "C+"){
            temp.push_back(6);
        } else if(grades[a] == "C0"){
            temp.push_back(5);
        }else if(grades[a] == "D+"){
            temp.push_back(4);
        } else if(grades[a] == "D0"){
            temp.push_back(3);
        }else{
            temp.push_back(0);
        }
    }
    
    /*벡터 temp와 weights가 같은 크기 이므로
    각 요소들을 곱해 총 점수 total을 구함*/
    for(int b = 0; b < temp.size(); b++){
        total += temp[b]*weights[b];
    }
    answer = total - threshold;
    return answer;
}