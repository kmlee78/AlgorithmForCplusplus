#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> guild;
    int N, fear, answer = 0;
    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> fear;
        guild.push_back(fear);
    }
    
    /*가장 큰 값이 맨 오른쪽으로 갈 수 있도록 정렬*/
    sort(guild.begin(), guild.end());
    int lastNum = guild[N-1];
    int index = N-1;

    /*guild 벡터의 맨 마지막에서부터 각 자리에 해당하는
      숫자 만큼 인덱스 이동. 이동 마다 answer 하나씩 증가*/  
    while(1){
        index -= lastNum;
        if(index >= 0){
            lastNum = guild[index];
            answer++;
        }else if(index == -1){
            answer++;
            break;
        }else{
            break;
        }
    }

    cout << answer << endl;
    return 0;
}