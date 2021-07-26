#include <iostream>
#include <cmath>
using namespace std;
#define SIZE 1000
#define SZ 10
// task 1
typedef struct{
    int pr;
    int dat;
} Node;
Node *arr[SZ];
int head;
int tail;
int items;
void init();
void ins(int pr,int dat);
Node* rem();
void PrintQueue();
// task 2
int Stack[SIZE];
int cursor = -1;
void DecToBin(int a);
bool Push(int data);
int Pop();
int main() {
    //task 1
    ins(15,1);
    ins(6,2);
    ins(2,3);
    ins(3,4);
    ins(8,5);
    ins(9,6);
    ins(5,7);
    ins(7,8);
    PrintQueue();
    rem();
    PrintQueue();
    rem();
    PrintQueue();
    ins(10,6);
    PrintQueue();
    //task 2
    DecToBin(15);
    return 0;
}
//task 1
void init()
{
    for(int i=0;i<SZ;++i)
    {
        head=0;
        tail=0;
        items=0;
    }
}
void ins(int pr,int dat)
{
    Node * node = new Node;
    node->dat=dat;
    node->pr=pr;
    if (items == SZ)
    {
        cout << "Queue uis full" << endl;
        return;
    }
    else {
        arr[tail++]=node;
        items++;
    }
}
Node* rem()
{
    if (items==0) return NULL;
    else {
        int max_pr=-1;
        int index_max = -1;
        for (int i=head;i<tail;++i)
        {
            if( arr[i]->pr > max_pr)
            {
                max_pr = arr[i]->pr;
                index_max=i;
            }
        }
        int idx=index_max;

        Node *tmp = arr[idx];
        /*arr[idx]=NULL;
        items--;
        tail--;*/
        if (idx!=tail)
        {
            for (int i=idx;i<tail;i++)
            {
                arr[i] = arr[i+1];
            }
            arr[tail]=NULL;
        }
        tail--;
        items--;
        return tmp;
    }
}
void PrintQueue(){
    cout << "[";
    for(int i=0;i<SZ;++i)
    {
        if(arr[i]==NULL) cout << "[*,*]";
        else cout << "[" << arr[i]->pr << "," << arr[i]->dat << "]";
    }
    cout << "]\n";
}


//task 2
void DecToBin(int a)
{
    int Razr;
    if (a<0)
    {
        cout << "-";
        a=-a;
    }
    if(a==0) Razr=1;
    else
    {
        double tmp = log10(a)/log10(2);
        Razr = tmp + 1;
    }
    for (int i=0;i<Razr;++i)
    {
        Push(a%2);
        a=a/2;
    }
    for (int i=0;i<Razr;++i)
    {
        cout << Pop();
    }
}
bool Push(int data)
{
    if(cursor<SIZE)
    {
        Stack[++cursor] = data;
        return true;
    }
    else{
        cout << "Stack overflow"<< endl;
        return false;
    }
}
int Pop(){
    if(cursor!=-1)  return Stack[cursor--];
    else{
        cout << "Stack is empty";
        return -1;
    }
};