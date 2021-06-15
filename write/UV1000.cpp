#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int a,b,q[10001],d[10001],w[5]={0,1,10,100,1000};//a,b为起点和终点，
bool p[10001],f[10001];
void prime()//只需10000以内素数表，因为只有四位数
{
	int j,i,k;
	bool flag;
	memset(p,false,sizeof(p));
	p[1]=false; p[2]=true;
	for (i=3; i<=9999; i+=2)
	{
		flag=true;
		k=(int)sqrt(i*1.0);
		for (j=2; j<=k; j++)
			if (i%j==0)
			{
				flag=false;
				break;
			}
		if (flag) p[i]=true;
	}
}

int main()
{
	int t,i,j,num,k,ne,l,r,sum;
	scanf ("%d",&t);
	prime();
	while (t--)
	{
		scanf ("%d%d",&a,&b);
		memset(f,false,sizeof(f));
		memset(d,0,sizeof(d));
		if (a==b)
		{
			printf ("0\n");
			continue;
		}
		l=0; r=1; 
		q[1]=a; f[a]=true; d[a]=0;//d[]代表从开始到这个素数的步数
        sum=-1;
		while (l<r)
		{
			l++; k=q[l];
			if (k==b)
			{
				sum=d[b];
				break;
			}
			for (i=1; i<=4; i++)//分别改变这个数的各个位数
			{
				num=(k/w[i])%10;//各个位上的数
				for (j=0; j<=9; j++)
				{
					ne=k-num*w[i]+j*w[i];
					if (p[ne]&&ne>1000&&!f[ne])
					{
						d[ne]=d[k]+1;
						f[ne]=true;
						r++;
						q[r]=ne;
                        cout<<ne<<" "<<d[ne]<<endl;
					}
				}
			}
		}
		if (sum==-1) printf ("Impossible.\n");//没有找到
		else printf ("%d\n",sum);
	}
    system("pause");
	return 0;
}