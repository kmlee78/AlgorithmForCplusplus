#include <iostream>
#include <vector>

using namespace std;

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
    int n, target, element;
    cout << "원소의 개수와 찾고자 하는 문자열 입력: ";
    cin >> n >> target;
    vector<int> array;
    cout << "전체 원소 크기 순서대로 입력: ";
    for(int a = 0; a < n; a++){
        cin >> element;
        array.push_back(element);
    }
    
    int result = search(target, array, 0, n-1);

    if(result == -1){
        cout << "해당 원소 없음" << endl;
    }else{
        cout << result + 1 << endl;
    }
    return 0;
}