
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"BionetBF.h"
#include <sys/mman.h>
#include<fcntl.h>

int main(){ 
    unsigned long int **b2=allocate2();       

    char fname[3][100]={"/IDKmer-dataset/10IDkmer20.txt","/IDKmer-dataset/10IDkmer20-mix.txt","/IDKmer-dataset/10IDkmer20-2.txt"};

    //char fname[3][100]={"IDKmer-dataset/20IDkmer20.txt","/IDKmer-dataset/20IDkmer20-mix.txt","/IDKmer-dataset/20IDkmer20-2.txt"};

    //char fname[3][100]={"/IDKmer-dataset/30IDkmer20.txt","/IDKmer-dataset/30IDkmer20-mix.txt","/IDKmer-dataset/30IDkmer20-2.txt"};

    //char fname[3][100]={"/IDKmer-dataset/40IDkmer20.txt","/IDKmer-dataset/40IDkmer20-mix.txt","/IDKmer-dataset/40IDkmer20-2.txt"};

    //Bionetwork dataset
    //char fname[3][30]={"chemical-gene.txt","chemical-gene-mix.txt","chemical-gene2.txt"};
    //char fname[3][30]={"gene-disease.txt","gene-disease-mix.txt","gene-disease2.txt"};
    //char fname[3][30]={"gene-gene.txt","gene-gene-mix.txt","gene-gene2.txt"};
    
   //Inserting
    int fp = open(fname[0], O_RDONLY);
    if (fp ==-1)
        printf("Error in opening %s file\n",fname[0]);   
           
    off_t fileLength = lseek(fp, 0, SEEK_END);    //Get its size.

    //Map its contents into memory.
    char* buff = mmap(NULL, fileLength, PROT_READ, MAP_SHARED, fp, 0);

    clock_t start, end; 
    char key[23],value[23]; 
    int i;
    off_t bindex=0; //bindex <- buffer index 

    start=clock();
    while(bindex<fileLength){ 
        i=0;
        while (buff[bindex]!=' '){
            key[i]=buff[bindex];
            i++; bindex++;
        }
        key[i]='\0';  bindex++; i=0;
        while (buff[bindex]!='\n' && bindex<fileLength){        
            value[i]=buff[bindex];
            i++; bindex++;
        }
        value[i]='\0'; bindex++;
        
        ICBionetBF(b2,key,value); 
    }
    end=clock();
    close(fp);    
    printf("\nElapsed Time of insertion:%f\n", (double)(end-start)/CLOCKS_PER_SEC);
    

    //Query same dataset
    int fcount=0,found;  //fcount<- file count
    for (fcount=0;fcount<=2;fcount++){
        fp=open(fname[fcount], O_RDONLY);
        if (fp ==-1)
            printf("Error in opening %s file\n",fname[0]);

        fileLength = lseek(fp, 0, SEEK_END);    //Get file size.
        //Map its contents into memory.
        char* buff = mmap(NULL, fileLength, PROT_READ, MAP_SHARED, fp, 0);    
        
        found=0; bindex=0;
        start=clock();
        while(bindex<fileLength){ 
            i=0;
            while (buff[bindex]!=' '){
                key[i]=buff[bindex];
                i++; bindex++;
            }
            key[i]='\0';  bindex++; i=0;
            while (buff[bindex]!='\n' && bindex<fileLength){        
                value[i]=buff[bindex];
                i++; bindex++;
            }
            value[i]='\0'; bindex++;
            if(QCBionetBF(b2,key,value)==1) 
                    found++;  
        }
        end=clock();
        close(fp);
        if(fcount==0)
            printf("Elements found in Same dataset: %d\n",found);
        else if(fcount==1)
            printf("Elements found in Mixed dataset: %d\n",found);
        else 
            printf("Elements found in Disjoint dataset: %d\n",found);
        printf("Elapsed Time of query:%f\n", (double)(end-start)/CLOCKS_PER_SEC); 
        
    } 
    
    free(b2); 
	return 0;
}
