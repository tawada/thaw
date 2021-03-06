#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    int i;
    const int N=14;
    char* list[]={
        "tar -zxvf", ".tar.gz",
        "tar -zxvf", ".tgz",
        "gunzip", ".gz",
        "tar -Zxvf", ".tar.Z",
        "tar -Zxvf", ".taz",
        "gunzip", ".Z",
        "tar -jxvf", ".tar.bz2",
        "tar -jxvf", ".tbz2",
        "bunzip2", ".bz2",
        "tar -Jxvf", ".tar.xz",
        "tar -xvf", ".tar",
        "lha x", ".lha",
        "lha x", ".lzh",
        "unzip", ".zip"};

    if(argc<2 || argc>2){
        printf("usage: thaw <file>\n");
        return 0;
    }

    if(strcmp(argv[1], "-h")==0){
        printf("This application calls thaw application best suited to filename extension.\n");
        printf("This application is supporting below:\n");
        for(i=0;i<N;i++)
            printf("%s <file>%s\n", list[2*i], list[2*i+1]);
        return 0;
    }
    char command[1024];
    char* cp=command;
    for(i=0;i<N;i++){
        char* p=strstr(argv[1],list[2*i+1]);
        if(p==NULL)continue;
        if(strlen(p)!=strlen(list[2*i+1]))continue;
        break;
    }
    if(i==N){
        printf("Error: unknown filename extension\n");
        return 1;
    }
    strcpy(cp, list[2*i]);
    cp+=strlen(list[2*i]);
    *cp++=' ';
    strcpy(cp, argv[1]);

    printf("%s\n", command);
    system(command);
    return 0;
}

