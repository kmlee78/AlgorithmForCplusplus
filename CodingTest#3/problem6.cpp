#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

/*수험자의 수험번호와 각 문제에 따른 점수를
담기 위해 [10000][101] 크기의 배열을 전역변수로
만들어준다*/
int user[10000][101];

vector<string> solution(vector<string> logs) {
    vector<string> answer;
    string temp1, temp2, temp3, score, temp4;

    /*stringstream을 통해 logs의 각 문자열을 읽어준다.
    문자열을 정수형으로 변환해야 하기 때문에 stoi함수를
    사용해준다*/
     for(int a = 0; a < logs.size(); a++){
         stringstream ss(logs[a]);
         ss >> temp1;
         ss >> temp2;
         ss >> temp3;
         if(user[stoi(temp1)][stoi(temp2)] == 0) user[stoi(temp1)][0]++;
         user[stoi(temp1)][stoi(temp2)] = stoi(temp3);
     }

     /*5문제 이상 맞춘 경우만을 추출하여 수험번호는 정수형으로,
     문제번호 및 점수를 모두 연결한 문자열을 문자형으로 가지는
     pair을 담은 새로운 벡터를 만들어준다*/
    vector<pair<int, string>> test;
    for(int b = 0; b < 10000; b++){
        if(user[b][0] >= 5){
            score = "";
            for(int c = 1; c < 101; c++){
                if(user[b][c] != 0) score += to_string(user[b][c]);
            }
            test.push_back(pair<int, string>(b, score));
        }
    }

    /*test벡터의 pair 중 문자열 부분이 같다면 같은 문제와 같은 점수를
    받았다 보고 해당 수험번호들을 모두 answer벡터에 push 해준다. 
    단, 수험번호들은 반드시 push 전 0들을 삽입해 네자릿수로 만들고
    문자열 형태로 변환해준다*/
    int size = test.size();
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(test[i].second == test[j].second){
                temp4 = to_string(test[i].first);
                while(temp4.length() < 4){
                        temp4 = "0" + temp4;
                }
                answer.push_back(temp4);
                temp4 = to_string(test[j].first);
                while(temp4.length() < 4){
                        temp4 = "0" + temp4;
                }
                answer.push_back(temp4);
            }
        }
    }

    /*수험번호들을 사전순으로 정렬하되 중복되는 
    수험번호들은 삭제하도록 한다*/
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    /*만약 answer벡터가 아무 요소도 가지지 않는다면
    "None" 이라는 문자열을 넣어준다*/
    if(answer.size() == 0){
        answer.push_back("None");
    }
    return answer;
}