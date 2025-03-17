#include <stdio.h>


void Ordem(int l, int c, int m[l][c], int n)
{
    int ct = 1;
    for(int h = 0; h < (n/2) + 1; h++)
    {
        for(int i = ct - 1; i <= n - ct; i++)
        {
            for(int j = ct - 1; j <= n - ct; j++)
            {
                m[i][j] = ct;
            }
        }
        ct++;
    }

}


void LerMatriz(int l, int c, int m[l][c], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-1; j ++)
            printf("%3d ",m[i][j]);

        printf("%3d\n",m[i][n-1]);
    }
    if ( n != 0 ) printf("\n");
}


int main()
{
    int m[100][100], r = 1;



    while(r > 0)
    {
        scanf("%d", &r);

        Ordem(100,100,m,r);

        LerMatriz(100,100,m,r);
    }




    return 0;
}