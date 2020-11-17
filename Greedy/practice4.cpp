#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    int N, num;
    vector<int> sum;
    cin >> N;

    /*새로 입력되는 단위의 화폐 마다 
      본인을 포함해 기존에 벡터 안에 
      들어있던 모든 금액과 더한 값을 넣어준다. */
    for(int a = 0; a < N; a++){
        cin >> num;
        int size = sum.size();
        for(int b = 0; b < size; b++){
            sum.push_back(sum[b] + num);
        }
        sum.push_back(num);
    }

    /*중복되는 값들은 하나만 남도록 하고
      오름차순으로 정렬한다.*/
    sort(sum.begin(), sum.end());
    sum.erase(unique(sum.begin(), sum.end()), sum.end());

    int answer = 1, index = 0;
    while(true){
        if(sum[index] != answer)
            break;
        answer++;
        index++;
    }
    
    cout << answer << endl;
    return 0;
}
