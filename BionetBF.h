//#include<stdio.h>
//#include<stdlib.h>
#include<string.h>
#include"murmur.h"

//int x2=18049,y2=18059;
//int x2=10993,y2=11003;
//int x2=12007,y2=12011;
//int x2=2503,y2=2521;
//int x2=2089,y2=2099;
//int x2=1759,y2=1777; 
//int x2=1583,y2=1597; 
int x2=1301,y2=1303; // Reset x2 and y2 according to size requirements
//int x2=503,y2=509;
//int x2=307,y2=311;
//int x2=97,y2=107;

//int seed=98899, seed1=79999, seed2=59971;
//int seed1=104021, seed2=104033, seed3=104047, seed4=104053;
int seed1=104009, seed2=104021, seed3=104033, seed4=104047, seed5=104053;
//unsigned int seed1=4093082899, seed2=3628273133, seed3=5463458053, seed4=104047, seed5=104053;

int bits=63;
int i;
//Dynamic memory allocation of BionetBF
unsigned long int **allocate2()
{
	int i,j,k,cnt=0;
	unsigned long int **a=(unsigned long int **)malloc(x2*sizeof(unsigned long int *));
	if(a==NULL)
	{
		printf("Unable to allocate!\n");
		return NULL;
	}

	for(i=0;i<x2;i++)
	{
		a[i]=(unsigned long int *)malloc(y2*sizeof(unsigned long int));
		if(a[i]==NULL)
		{
			printf("Unable to allocate!\n");
			return NULL;
		}
	}
	printf("\nAllocated and Initialized 2DBF Successfully...\n");
	return a;
}

void _set_2(unsigned long int **a,int i, int j, int pos)
{
	//int i=c;
	unsigned long int d=a[i][j];
	unsigned long int p=1<<pos;
	a[i][j]=d | p;
}

/*
Test whether a bit is set or not in a[i][j]
*/

int _test_2(unsigned long int **a,int i, int j, int pos)
{

	unsigned long int d=a[i][j];
	unsigned long int p=1<<pos;
	unsigned long int r=d^p;
	unsigned long int t=r & p;
	if((t==0) && (d!=0))
		return 1;
	return 0;
}


// Insetion operation of BionetBF 
void ICBionetBF (unsigned long int **b2, char *key, char *value){
	char w[40];
	unsigned int h=0,h1=0,h2=0; 
	int i,pos;
	int j=0,k;//,l,m,n,pos1;

	sprintf(w,"%s%s", key,value); //printf("%s\n",w);
	h=murmur2(w,strlen(w),seed2); //1
    i=h%x2;
	j=h%y2;
	pos=h%bits;
	_set_2(b2,i,j,pos); 

	h=murmur2(w,strlen(w),seed3);	//2
    i=h%x2;
	j=h%y2;
	pos=h%bits;
	_set_2(b2,i,j,pos);

}

// Query function of BionetBF  
int QCBionetBF(unsigned long int **b2, char *key, char *value){
	char w[40];
	unsigned int h=0,h1=0,h2=0; 
	int i,pos;
	int j=0,k;//,l,m,n,pos1;
	int flag=1;

	sprintf(w,"%s%s", key,value); 	//1
    h=murmur2(w,strlen(w),seed2);
	i=h%x2;
	j=h%y2;
	pos=h%bits;
	flag =flag & _test_2(b2,i,j,pos);

	h=murmur2(w,strlen(w),seed3); 	//2
	i=h%x2;
	j=h%y2;
	pos=h%bits;
	flag =flag & _test_2(b2,i,j,pos);


	if(flag==1)
		return 1;
	return 0;    
}

