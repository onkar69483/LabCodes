#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//program to convert any base to decimal and vice versa

void dectobin(int dec){
	int bin[32];

    int i = 0;
    while (dec!= 0) {
        bin[i] = dec % 2;
        dec = dec / 2;
        i++;
    }
	int j;
	for (j = i - 1; j >= 0; j--)
        printf("%d",bin[j]);
}

int bintodec(int bin){
	int dec=0,rem =0,i=0;
    while(bin!=0){
    rem = bin%10;
    bin = bin/10;
    dec += rem*pow(2,i);
    i++;
    }
    return dec;
}

void dectooct(int dec)
{
    int oct[100];

    int i = 0;
    while (dec!= 0) {

        oct[i] = dec % 8;
        dec = dec / 8;
        i++;
    }
     int j=0;
    for (j = i - 1; j >= 0; j--)
        printf("%d", oct[j]);
}

int octtodec(int oct){
	int dec=0,rem =0,i=0;
    while(oct!=0){
    rem = oct%10;
    oct = oct/10;
    dec += rem*pow(8,i);
    i++;
    }
    return dec;
}

void dectohex(int dec){
	int hex[100];
    int i = 0;
    while (dec!= 0) {

        hex[i] = dec % 8;
        dec = dec / 8;
        i++;
    }
     int j=0;
    for (j = i - 1; j >= 0; j--)
        printf("%d", hex[j]);
}

int main() {
    	
	int dec,bin,oct,n;
	printf("Menu: ");
	printf("\n1. decimal to binary");
	printf("\n2. binary to decimal");
	printf("\n3. decimal to octal");
	printf("\n4. octal to decimal");
	printf("\n5. decimal to Hexadecimal");
	printf("\n6. Exit!");
	printf("\nEnter your choice: ");
	scanf("%d", &n);
	switch(n){
		case 1: printf("\nEnter a decimal number: ");
	scanf("%d",&dec);
    dectobin(dec);
    break;
         case 2:  printf("\nEnter a binary: ");
    scanf("%d",&bin);
    printf("%d",bintodec(bin));
    break;
     case 3: printf("\nEnter a decimal number: ");
	scanf("%d",&dec);
    dectooct(dec);
    break;
    case 4: printf("\nEnter a octal: ");
    scanf("%d",&oct);
    printf("%d",octtodec(oct));
    break;
    case 5: printf("\nEnter a decimal number: ");
	scanf("%d",&dec);
    dectohex(dec);
    break;
    case 6: return(0);
    break;
    default:
    	printf("Invalid output!");
    	break;
	}
    
		return 0;
}
