#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<double, int> a, pair<double, int> b){

    /*실패율이 높은 스테이지부터 내림차순.
      같으면 작은 번호의 스테이지 리턴.*/
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> users;
    double clear[501] = {0};
    double reach[501] = {0};
    int size = stages.size();

    /*스테이지에 도달했으나 클리어 하지 못한 
      경우는 clear 배열에, 스테이지에 도달한
      경우는 reach 배열에 그 값을 저장*/
    for(int a = 0; a < size; a++){
        clear[stages[a]]++;
        for(int b = stages[a]; b > 0; b--){
            reach[b]++;
        }
    }

    /*실패율과 스테이지 번호를 pair형태로 
      users 벡터에 저장. 스테이지에 도달한 유저가
      0 일시 실패율을 0으로 저장.*/
    for(int a = 1; a <= N; a++){
        if(reach[a] == 0){
            users.push_back(pair<double, int>(0, a));
        }else{
            users.push_back(pair<double, int>(clear[a]/reach[a], a));
        }
    }
    sort(users.begin(), users.end(), comp);

    for(int a = 0; a < N; a++){
        answer.push_back(users[a].second);
    }
    return answer;
}