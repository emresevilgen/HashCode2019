#include <iostream>
using namespace std;
int main() {
    int nop;
    int index1 = 0, index2 = 0, maks1 = 0, maks2 = 0;
    photo p[80010];
    cin << nop;
    for( int i = 0; i < nop; i++) {
        int maks, index;
        photo tmp;
        maks = 0;
        index = i;
        for( int j = i; j < nop ; j++){
            if( p[j].notags > maks) {
                maks = p[j].notags;
                index = j;
            }
        }
        tmp = p[i];
        p[i] = p[index];
        p[index] = tmp;
    }
    for( int i = 1; i < 101; i++){
        int a;
        a = getpoint(p[0],p[i]);
        if( a > maks1) {
            index2 = index1;
            index1 = i;
        }
        else if( a > maks2)
            index2 = i;
    }
    photo tmp;
    tmp = p[1];
    p[1] = p[index1];
    p[index1] = tmp;
    tmp = p[2];
    p[2] = p[index2];
    p[index2] = tmp;
    for( int i = 1; i < nop; i++) {
        int maks = 0, index = i;
        for( int j = i + 2; j < i + 100; j++) {
            int a;
            a = getpoint(p[i],p[j]);
            if( a > maks)
                index  = j;
        }
        tmp = p[i + 2];
        p[i + 2] = p[index];
        p[index] = tmp;
    }
    return 0;
}
