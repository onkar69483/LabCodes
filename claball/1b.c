#include <stdio.h>
#include <string.h>

int main(){
    char str[50],strs[50];
    int i;
    printf("Enter string: ");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++){
       if(str[i]>='A' && str[i]<='Z'){
        strs[i] = str[i]+ 32;
       }
       else{
        strs[i] = str[i];
       }
    }
    strs[i] = '\0';
    printf("small letters: %s" ,strs);
    return 0;
}