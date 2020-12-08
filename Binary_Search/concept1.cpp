#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*BinarySearch_Loop.cpp 코드랑 같다.
  다만 탐색하고자 하는 값을 총 m번, 
  특정 벡터로 받아 원소 하나하나에 대한
  탐색의 성공 유무를 출력했을 뿐이다.*/
int search(int target, vector<int>& array, int start, int end){
    int mid = (start + end) / 2;
    while(array[mid] != target){
        mid = (start + end) / 2;
        if(start > end) return -1;
        if(target > array[mid]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return mid;
}

int main(){
    int n, m, element, answer;
    cin >> n;
    vector<int> array;
    vector<int> target;
    for(int a = 0; a < n; a++){
        cin >> element;
        array.push_back(element);
    }
    cin >> m;
    for(int b = 0; b < m; b++){
        cin >> element;
        target.push_back(element);
    }

    /*이진 탐색을 하기 위해선 트리 내
      데이터들을 정렬해야 된다.*/
    sort(array.begin(), array.end());

    for(int a = 0; a < m; a++){
        answer = search(target[a], array, 0, n-1);
        if(answer == -1){
            cout << "no" << " ";
        }else{
            cout << "yes" << " ";
        }
    }
    return 0;
}