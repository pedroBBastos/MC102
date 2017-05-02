#include <stdio.h>

int main(){
    char c; float temp;

    scanf("%c", &c);
    scanf("%f", &temp);

    if(c == 'F')
        printf("%.2f", 5*(temp-32)/9);
    else
        if(c == 'C')
            printf("%.2f", (9*temp/5)+32);

}