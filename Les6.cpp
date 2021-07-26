#include <iostream>
#include <cmath>
using namespace std;
void bubbles(int *a,size_t sizex,size_t sizey);
void TPK();
int main() {
    //test1
    /*int ary[3][3] = {
            { 1,9,2 },
            { 5,7,6},
            { 4,3,8 }
    };
    bubbles(*ary,3,3);
    for (int i = 0;i<3;++i){
        for (int j = 0;j<3;++j) {
            cout << ary[i][j] << " ";
        }
    }*/
    //test2
    //TPK();
    return 0;
}
void bubbles(int *a,size_t sizex,size_t sizey)
{
    for (int k = 0;k<sizex*sizey-1;++k){
        for (int i = 0;i<sizex*sizey-1;++i) {
            if (a[i] > a[i + 1]) {
                int k = a[i];
                a[i] = a[i + 1];
                a[i + 1] = k;
            }
        }
    }
}
void TPK()
{
    bool alert = false;
    int P1[11];
    int P2[11];
    int P3[11];
    for(int i=0;i<11;++i)
    {
        cin >> P1[i];

    }
    for(int i=0;i<11;++i)
    {
        P2[10-i] = P1[i];
        P3[i] = sqrt(fabs(P1[i])) + 5 * pow(P1[i], 3);
        if (P3[i] > 400 && !alert) {
            cout << "Value is more than 400! ALERT!" << endl;
            alert = true;
        }
    }
    //test
    for(int i=0;i<11;++i)
    {
        cout << P1[i] << " ";
    }
    cout << endl;
    for(int i=0;i<11;++i)
    {
        cout << P2[i] << " " ;
    }
    cout << endl;
    for(int i=0;i<11;++i)
    {
        cout << P3[i] << " " ;
    }
}