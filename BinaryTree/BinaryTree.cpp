#include <iostream>

using namespace std;

/*트리 전체 크기 
  15로 배정*/
int number = 15;            

typedef struct node* tree;
typedef struct node{
    int data;
    tree left, right;
}node;
/*preorder
  자신 탐색 ->
  왼쪽 자식 탐색 ->
  오른쪽 자식 탐색*/
void preorder(tree ptr){        
    if(ptr)
    {
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
/*inorder
  왼쪽 자식 탐색 ->
  자신 탐색 ->
  오른쪽 자식 탐색*/
void inorder(tree ptr){         
    if(ptr)
    {
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}
/*postorder
  왼쪽 자식 탐색 ->
  오른쪽 자식 탐색 ->
  자신 탐색*/
void postorder(tree ptr){       
    if(ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " ";
    }
}

int main(){
    node nodes[number];

    //data 입력해주기
    for(int a = 0; a < number; a++)        
    {
        nodes[a].data = a;
        nodes[a].left = NULL;
        nodes[a].right = NULL;
    }
    //연결해주기
    for(int b = 1; b < number; b++)        
    {
        if(b%2 == 0){
            nodes[(b-1)/2].right = &nodes[b];
        }else{
            nodes[b/2].left = &nodes[b];
        }
    }
     //root인 0부터 탐색 시작
    preorder(&nodes[0]);               
    cout << endl;
    inorder(&nodes[0]);
    cout << endl;
    postorder(&nodes[0]);

    return 0;
}