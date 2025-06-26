//
// Created by FPT on 6/26/2025.
//
#include <ctype.h>
#include<stdio.h>
#include<string.h>

int isPalindrome(char *str,int start,int end) {
    if (start >= end) {
        return 1;
    }
    if (tolower(str[start]) != tolower(str[end])) {
        return 0;
    }
    return isPalindrome(str,start+1,end-1);
}


int main() {
    char inputStr[100];
    char cleanedStr[100];
    int j =0;
    fgets(inputStr,sizeof(inputStr),stdin);

    inputStr[strcspn(inputStr,"\n")] = 0;
    for(int i =0;i<inputStr[i];i++) {
        if(isalnum(inputStr[i])) {
            cleanedStr[j++] = inputStr[i++];
        }
    }
    cleanedStr[j] = '\0';

    if (strlen(cleanedStr)==0) {
        printf("Palindrome invalid\n");
    }else {
        if (isPalindrome(cleanedStr,0,strlen(cleanedStr)-1)) {
            printf("Palindrome valid\n");
        }else {
            printf("Palindrome invalid\n");
        }
    }





    return 0;



}