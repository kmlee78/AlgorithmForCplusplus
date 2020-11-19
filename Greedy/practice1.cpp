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

    /*guild 벡터의 오름차순 정렬*/
    sort(guild.begin(), guild.end());
    int lastNum = guild[0];
    int index = 0;

    /*guild 벡터의 첫 인덱스부터 각 자리에 해당하는
      숫자 만큼 인덱스 이동. 이동 마다 answer 하나씩 증가*/
    while(1){
        index += lastNum;
        if(index < N){
            lastNum = guild[index];
            answer++;
        }else{
            break;
        }
    }

    cout << answer << endl;
    return 0;
}
