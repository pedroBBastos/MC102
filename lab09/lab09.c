#include <stdio.h>

int main()
{
    int operando1[30];
    int operando2[30];

    int n1;

    scanf("%d", &n1);

    int fator = 10;
    for(int i=0; i<30; i++)
    {
        int digito = n1 % fator;
        printf("digito %d\n", digito);

        fator = fator * 10;
    }
}