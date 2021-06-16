#include <iostream>
using namespace std;
int task1(const char *str);
void task2(int kops);
int main() {
    //test task1
    cout << task1("Hello") << endl;
    //test task2
    task2(98);
    return 0;
}

int task1(const char* str){
    int c = 0;
    while (*str != '\0') {
        c += *str;
        str++;
    }
    return c;
}

void task2(int kops){
    int nominals[] = {50,10,5,2,1};
    int j=0;
    while(kops!=0) {
        int i=j;
        while (kops < nominals[i]) ++i;
        cout << nominals[i] << " ";
        kops -= nominals[i];
        if (kops < nominals[i]) ++j;
    }
}
