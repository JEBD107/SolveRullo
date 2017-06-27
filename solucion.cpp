#include <stdio.h>

#define n 8

int mr[n+1][n+1];
int mat[n+1][n+1];
int rv[n+1],rh[n+1];

int pot(int x, int y)
{
    int i=0;
    int r=1;
    for(i=0;i<y;i++)
        r=r*x;
    return r;
}

int log(int b,int x)
{
    int i=-1;
    int r=0;
    if(x==0)
        return -1;
    do
    {
        i++;
        r=pot(b,i);
    }while(r!=x);
    return i;
}

int verificar()
{
    int i,j,so,r=0;
    /*for(i=1;i<=n;i++)
    {
        so=0;
        for(j=1;j<=n;j++)
        {
            if(mr[i][j]==1)
                so=so+mat[i][j];
        }
        if(so==rv[i])
            r=1;
        else
        {
            r=0;
            break;
        }
    }*/
    for(i=1;i<=n;i++)
    {
        so=0;
        for(j=1;j<=n;j++)
        {
            if(mr[j][i]==1)
                so=so+mat[j][i];
        }
        if(so==rh[i])
            r=1;
        else
        {
            r=0;
            break;
        }
    }
    return r;
}

void solucion(int k, int i)
{
    int j=0,so=0,r=0;
    printf("\n%d %d",k,i);
    while(i<pot(2,n)&&k<=n)
    {
        if(verificar())
        {
            printf("solucion");
            break;
        }
        so=0;
        for(j=1;j<=n;j++)
            mr[k][j]=0;
        for(j=1;j<pot(2,n);j=j*2)
            so=so+mat[k][log(2,i&j)+1];
        if(so==rv[k])
        {
            for(j=1;j<pot(2,n);j=j*2)
                mr[k][log(2,i&j)+1]=1;
            solucion(k+1,1);
            printf("\n%d %d",k,i);
        }
        i++;
    }
    return;
}

int main()
{
    int i=0,j=0;
    rv[0]=0;rh[0]=0;
    for(i=1;i<=n;i++)
    {
        mat[0][i]=0;
        mat[i][0]=0;
        mr[0][i]=0;
        mr[i][0]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("\nIngresa Numero [%d][%d]: ",i,j);
            scanf("%d",&mat[i][j]);
            mr[i][j]=0;
        }
    }
    for(i=1;i<=n;i++)
    {
        printf("\nIngresa RV [%d]: ",i);
        scanf("%d",&rv[i]);
    }
    for(i=1;i<=n;i++)
    {
        printf("\nIngresa RH [%d]: ",i);
        scanf("%d",&rh[i]);
    }
    solucion(1,1);
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("-%2d ",mr[i][j]);
        printf("\n");
    }
    return 0;
}
