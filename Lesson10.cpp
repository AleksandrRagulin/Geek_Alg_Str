#include <iostream>
#include <cstring>
using namespace std;
//task 1
bool fun1(string S);
//functions for tasks 2 and 3
typedef struct Node{
    int dat;
    struct Node *next;
} Node;
typedef struct{
    Node *head;
    int size;
} List;
void init (List * lst);
void ins(List * lst, int data);
Node *rm(List * lst, int data);
void PrintNode(Node *n);
void PrintList(List * lst);
//task 2
void CopyList(List * From, List * TO);
//task 3
bool CheckSort(List * lst);

int main() {
    //task 1
    /*string S;
    cin >> S;
    if (fun1(S))   cout << "YES\n";
    else cout << "NO\n";*/

    //init data
    /*List *L = new List;
    List *L2 = new List;
    init(L);
    init(L2);
    ins(L,1);
    ins(L,1);
    ins(L,3);
    ins(L,2);*/
    //task2
    /*PrintList(L);
    CopyList(L,L2);
    PrintList(L);
    PrintList(L2);*/
    //task 3
    /*PrintList(L);
    if (CheckSort(L))   cout << "YES\n";
    else cout << "NO\n";*/
    return 0;
}

bool fun1(string S){
    int length = S.size();
    char * str = new char[length];
    strcpy(str,S.c_str());
    char tmp;
    int FL=0, FR=0, SL=0, SR=0, NR=0, NL=0; //массивы для подсчета скобок: фигурных, квадратных, обычных
    for(int i=0;i<length;++i)
    {
        tmp = str[i];
        switch (tmp) {
            case '{':
                FL++;
                break;
            case '}':
                FR++;
                break;
            case '[':
                SL++;
                break;
            case ']':
                SR++;
                break;
            case '(':
                NL++;
                break;
            case ')':
                NR++;
                break;
        }
        if (NR>NL || SR>SL || FR>FL)    return false;
    }
    return NR == NL && SR == SL && FR == FL;
}
void init (List * lst){
    lst->head=NULL;
    lst->size=0;
}
void ins(List * lst, int data){
    Node * Neu = new Node;
    Neu->dat = data;
    Neu->next = NULL;
    Node * current = lst->head;
    if (current==NULL)
    {
        lst->head = Neu;
        lst->size++;
    }
    else{
        while (current->next !=NULL) current=current->next;
        current->next = Neu;
        lst->size++;
    }
}
Node *rm(List * lst, int data){
    Node *current =lst->head;
    Node *parent=NULL;
    if(current==NULL)   return NULL;
    while(current->next !=NULL && current->dat!=data){
        parent=current;
        current=current->next;
    }
    if(current->dat!=data) return NULL;
    if(current==lst->head)
    {
        lst->head=current->next;
        lst->size--;
    }
    parent->next = current->next;
    lst->size--;
    return current;
}
void PrintNode(Node *n){
    if(n==NULL){
        cout << "[]";
        return;
    }
    cout << n->dat;
}
void PrintList(List * lst)
{
    Node *current=lst->head;
    if (current==NULL) PrintNode(current);
    else{
        do{
            PrintNode(current);
            cout << " ";
            current=current->next;
        } while (current!=NULL);
    }
    cout << endl << "Size: " << lst->size << endl;
}
void CopyList(List * From, List * TO){
    Node *current=From->head;
    if (current==NULL) ins(TO,current->dat);
    else{
        do{
            ins(TO,current->dat);
            current=current->next;
        } while (current!=NULL);
    }
}
bool CheckSort(List * lst)
{
    int tmp = -10^9;
    Node *current = lst->head;
    if (current==NULL) return true;
    else {
        do {
            if (current->dat < tmp) return false;
            tmp = current->dat;
            current = current->next;

        } while (current != NULL);
    }
    return true;
}