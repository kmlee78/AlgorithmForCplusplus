#include <vector>
#include <string>

using namespace std;

int solution(int money, vector<string> expected, vector<string> actual) {
    int answer = -1;
    int bet = 100;
    int size = actual.size();
    for(int a = 0; a < size; a++){

        /*남아있는 돈이 베팅 금액 보다 적으면
        남아있는 돈 모두를 베팅한다*/
        if(bet > money){
            bet = money;
        }

        /*expected 벡터와 actual 벡터를 비교하여
        일치 시 베팅한 금액만큼을 추가로 받고 베팅
        금액을 100원으로 초기화 한다. 만약 일치하지
        않으면 베팅한 금액을 잃고 베팅 금액은 2배로
        늘어난다*/
        if(expected[a] == actual[a]){
            money += bet;
            bet = 100;
        }else{
            money -= bet;
            bet *= 2;
        }
        if(money == 0) break;
    }
    answer = money;
    return answer;
}