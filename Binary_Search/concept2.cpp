#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*설정해야 할 절단기의 길이를 이진 탐색을
  이용하여 찾는다. 순차 탐색을 이용해도
  답을 구할 수는 있지만, 떡 길이의 범위가
  10억 까지 있으므로 이진 탐색이 필수다.*/
int main(){
    int n, m, element, answer;
    cin >> n >> m;
    vector<int> array;
    for(int a = 0; a < n; a++){
        cin >> element;
        array.push_back(element);
    }

    /*첫 시작점은 0, 끝점은 가장 긴 떡의 길이로 한다.*/
    int start = 0, end = *max_element(array.begin(), array.end());
    while(start <= end){
        int mid = (start + end) / 2;
        int result = 0;

        //잘랐을 때 떡의 총 길이 계산
        for(int a = 0; a < n; a++){
            if(array[a] > mid) result += array[a] - mid;
        }
        if(result < m){
            end = mid - 1;
        }else{
            start = mid + 1;
            answer = mid;
        }
    }

    cout << answer << endl;
    return 0;
}
