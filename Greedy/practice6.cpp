#include <string>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int size = food_times.size();
    int temp = size;
    while(k >= temp){
        k -= temp;
        for(int a = 0; a < size; a++){
            if(food_times[a] == 1){
                food_times[a]--;
                temp--;
            }else if(food_times[a] > 1){
                food_times[a]--;
            }
        }
    }
    while(k >= 0){
        if(food_times[answer] != 0)
            k--;
        answer++;
    }
    return answer;
}