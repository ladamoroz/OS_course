#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
int main(){
    DIR* dirp = opendir("tmp");
    struct stat buf;
    struct dirent  *dp;
    char a[10][10];
    int b[100];
    int i = 0;
    while ((dp = readdir(dirp)) != NULL) {
        char str[80];
        strcpy(str,"tmp/");
        strcat(str,dp->d_name);
        int status = stat(str, &buf);
        nlink_t count = buf.st_nlink;
        if (count > 1){
            //printf("%s ", dp->d_name);
            strcpy(a[i],dp->d_name);
            //printf("%s ", a[i]);
            ino_t inode = buf.st_ino; /* inode's number */
            b[i] = inode;
            i++;
        }
    }
    
    for (int j = 0; j < i; j++){
        int temp = b[j];
        char str[80];
        strcpy(str, "");
        int c = 0;
        for (int k = 0; k < i;k++){
            if (b[k] == temp && temp !=-1){
                strcat(str,a[k]);
                strcat(str," ");
                c++;
                b[k] = -1;
            }
        }
        if (c > 1 && temp!=-1){
            printf("%d ",temp);
            printf("%s ",str);
            printf("\n");
        }
        b[j] = -1;
        
    }
    return 0;
}
