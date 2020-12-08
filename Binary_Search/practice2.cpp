#include <iostream>
#include <vector>

using namespace std;

/*고정점 = 원소 중 그 값이 인덱스와 동일한 원소.
  이진 탐색을 통해 중간 인덱스가 실제 값 보다 크면
  배열의 오른쪽을, 작으면 왼쪽을 탐색한다.*/
int search(vector<int>& array, int start, int end){
    while(start <= end){
        int mid = (start + end) / 2;
        if(array[mid] == mid) return mid;
        if(mid > array[mid]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n, element;
    cin >> n;
    vector<int> array;
    for(int a = 0; a < n; a++){
        cin >> element;
        array.push_back(element);
    }

    int result = search(array, 0, n-1);

    cout << result << endl;
    return 0;
}