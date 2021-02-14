#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int a, int b)
{
    return a > b;
}

int main(){
/*min 함수와 max 함수*/
    int a = 50;
    int b = 60;
    cout << min(a,b) << endl;       //50
    cout << max(a,b) << endl;       //60


/*sort 함수*/
    int array[10] = {3,4,2,6,5,7,8,1,9,10};
    sort(array, array+10);          //오름차순으로 정렬
    for(int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";    //1 2 3 4 5 6 7 8 9 10
    }

    cout << endl;
/*내림차순으로 정리하는 법*/
    sort(array, array+10, comp);    //comp 라는 새로운 함수 사용
    for(int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";    //10 9 8 7 6 5 4 3 2 1
    }    

    cout << endl;

/*vector에서 사용할 수 있는 것*/
    vector<int> num;
    num.push_back(1);               
    num.push_back(2);               
    num.push_back(3);
    reverse(num.begin(), num.end());      //123 -> 321 벡터 안 요소들 순서 반전
/*vector를 sort 하기*/
    sort(num.begin(), num.end());

    for(vector<int>::iterator it = num.begin(); it != num.end(); it++)
    {
        cout << *it << " ";                      //1 2 3
    }    
    
    int biggest;
    int smallest;
    biggest = *max_element(num.begin(), num.end());         //벡터 요소들 중 가장 큰 값 
    smallest = *min_element(num.begin(), num.end());        //벡터 요소들 중 가장 작은 값
    
    //ex)*max_element(v.begin()+a, v.begin()+b);    이런 식으로 사용하면 v[a] 부터 v[b-1] 까지의 가장 큰 값을 찾아낸다. 
    
     /*벡터 내 중복되는 요소들을 전부 없애고 정렬하는 법*/
    vector<int> sum{3,2,5,1,4,3,6,1,4,3,6,2,5,4,7,12,11,14,10,13,12,15,10};
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
}