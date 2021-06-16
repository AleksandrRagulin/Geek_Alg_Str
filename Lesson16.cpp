#include <iostream>
using namespace std;

//метод цезаря
char *  task1_enc(char * str, int key);
char *  task1_dec(char * str, int key);


//метод перестановки
char *  task2_enc(char * str, int cols);
char *  task2_dec(char * str, int cols);

int main() {
    //task 1 test
    char * test1 = task1_enc("AVECAESAR",3);
    task1_dec(test1,3);
    //task 2 test
    /*char * test2 = task2_enc("Thisisasecretmessag",4);
    task2_dec(test2,4);*/
    return 0;
}

char *  task1_enc(char * str, int key) {
    int len=0;
    while(str[len]!=0) len++;
    char *mes = new char[len];
    for(int i=0;i<len;++i){
        if( 91 > str[i]+key && str[i]+key >64) mes[i] = str[i]+key;
        else if(str[i]+key > 90) mes[i] = str[i]+key-26;
        else mes[i] = str[i]+key+26;
    }
    cout << mes << endl;
    return mes;
}

char *  task1_dec(char * str, int key) {
    int len=0;
    key=-key;
    while(str[len]!=0) len++;
    char *mes = new char[len];
    for(int i=0;i<len;++i){
        if( 91 > str[i]+key && str[i]+key >64) mes[i] = str[i]+key;
        else if(str[i]+key > 90) mes[i] = str[i]+key-26;
        else mes[i] = str[i]+key+26;
    }
    cout << mes << endl;
    return mes;
}


char *  task2_enc(char * str, int cols){
    int len=0;
    while(str[len]!=0) len++;
    char *mes = new char[len];
    int rows = len/cols;
    if(len%cols!=0) rows++;
    for(int i=0;i<rows; ++i){
        for(int j=0;j<cols; ++j){
                mes[i*cols+j] = str[i + rows*j];
        }
    }
    int i=0;
    char  * res = new char[len];
    while(i<len) {
        res[i] = mes[i];
        i++;
    }
    cout << res << endl;
    return res;
}

char *  task2_dec(char * str, int cols){
    int len=0;
    while(str[len]!=0) len++;
    char *mes = new char[len];
    int rows = len/cols;
    if(len%cols!=0) rows++;
    int flag=0;
    for(int i=0;i<cols; ++i){
        for(int j=0;j<rows; ++j){
                mes[i*rows+j] = str[i + cols*j];
        }
    }
    cout << mes << endl;
    return mes;
}




