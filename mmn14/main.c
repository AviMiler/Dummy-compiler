#include "stdio.h"

int main(){

    int z;
    int x=5,y=-10,a=4,b=2;

    void f();
    z=x++ - --y*b/a;
    printf("%d",z);

    return 0;

}

void f(){
    int n =8;
    float a=5.3;
    /*printf("%f",a);*/
    if(a==a)
        printf("%d",sizeof (int));
}