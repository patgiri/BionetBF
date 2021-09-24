#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    FILE *fr, *f;
    char ch, buff[30]; 
    int kmer=23; //Length of kmer

    //char fname[3][30]={"10IDkmer20.txt","10IDkmer20-2.txt","10IDkmer20-mix.txt"};  const int tlines=10000000;        //tlines=no of lines 
    //char fname[3][30]={"20IDkmer20.txt","20IDkmer20-2.txt","20IDkmer20-mix.txt"};const int tlines=20000000;        //tlines=no of lines
    char fname[3][30]={"30IDkmer20.txt","30IDkmer20-2.txt","30IDkmer20-mix.txt"}; const int tlines=30000000;        //tlines=no of lines
    //char fname[3][30]={"40IDkmer20.txt","40IDkmer20-2.txt","40IDkmer20-mix.txt"}; const int tlines=40000000;        //tlines=no of lines
    
    fr=fopen("DNASequences.fasta","r");       //Reading DNA file
    if(fr == NULL)
   	{
      		printf("File cannot be opened!");   
      		exit(1);             
   	}
    
    const long long int initial=100000000000000;  //initial= starting identifer value
    
    int i;
    long long int id,range;
    //Same Set
    f=fopen(fname[0],"w");       
    if(f == NULL)
   	{
      		printf("File cannot be opened!");   
      		exit(1);             
   	}
    id=initial;     
    range=initial+tlines;
    while(id<range){
        for (i=0;i<kmer;i++){
            ch=fgetc(fr);
            if(ch==' ' || ch=='\n')
                ch=fgetc(fr);
            else if (ch==EOF){
                rewind(fr);
                ch=fgetc(fr);
            }
            buff[i]=ch;
        }
        buff[++i]='\0'; 
        fprintf(f,"%lld %s\n",id,buff);
        id++;
    }
    printf("Same Set Generated\n");
    fclose(f);
    fclose(fr);

    // Disjoint Set
    //rewind(fr);  //Rewind to begining of the file
    f=fopen(fname[1],"w");  
    fr=fopen(fname[0],"r");       
    if(f == NULL && fr == NULL)
   	{
      		printf("File cannot be opened!");   
      		exit(1);             
   	}
    id=6*initial;
    range=id+tlines;
    
    char key[20], value[30];
    while (id<range){                    //Reading from Same set
        fscanf(fr,"%s %s", key, value);
        fprintf(f,"%lld %s\n",id, value);
        id++;
    }
    printf("Disjoint Set Generated\n");
    fclose(f);
    fclose(fr);

    //Mixed Set
    FILE *fs,*fd;
    f=fopen(fname[2],"w");       
    fs=fopen(fname[0],"r");       //Reading Same set file
    fd=fopen(fname[1],"r");       //Reading Disjoint set file
    if(f == NULL && fs == NULL && fd == NULL)
   	{
      		printf("File cannot be opened!");   
      		exit(1);             
   	}

    i=0; 
    
    range=tlines/2; printf("Mixed set: range=%lld\n",range); 
    while (i<range){                    //Reading from Same set
        fscanf(fs,"%s %s", key, value);
        fprintf(f,"%s %s\n",key, value);
        i++;
    }
    fclose(fs);
    i=0;
    while (i<range){        //Reading from Disjoint set
        fscanf(fd,"%s %s", key, value);
        fprintf(f,"%s %s\n",key, value);
        i++;
    }
    fclose(fd);
    fclose(f);
    printf("Mixed Set Generated\n");
}