#include<stdio.h>
#define N 10000
#define F(x,y,a) for(i=x;i<N;i+=y)if(!a[i])
int i,j,a[N],b[N];
int main(){
        F(2,1,a)for(j=i+i;j<N;j+=i)a[j]=1;
        F(3,2,a)for(j=1;i+2*j*j<N;j++)b[i+2*j*j]=1;
        F(7,2,b)if(a[i])return printf("%d\n",i);
    }