#include <stdio.h>

int main(){
    int a, b, pot;
    scanf("%d %d", &a, &b);
    pot = 1;

    for(int i=0; i<b; i++)
        pot = pot * a;

    printf("%d\n", pot);
}