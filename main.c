#include<stdio.h>
#include<string.h>
#include <ctype.h>

int main() {
    int i, l, t = 0;
    int count = 0;
    char input[100];
    printf("Enter the input\n");
    scanf("%s", input);
    l = (int) strlen(input);
    for (i = 0; i < l; i++) {
        if (l < 11) {
            if (isdigit(input[0]) != 0 || input[0] == 40) {
                if (isalpha(input[i]) == 0) {
                    if (input[i] == 40 && input[i+1]!= 41) {
                        t++;
                        count--;
                    } else if (input[i] == 41) {
                        t--;
                        if (t < 0) {
                            break;
                        }
                    } else if (input[i] == 43 || input[i] == 45) {
                        count++;
                        if ((isdigit(input[i - 1]) != 0 && isdigit(input[i + 1]) != 0) || input[i - 1] == 41 ||
                            input[i + 1] == 40) {
                        } else {
                            break;
                        }
                    }
                } else {
                    break;
                }
            } else {
                break;
            }
        } else {
            break;
        }
    }
    if (i == l && t == 0 && count >= 0)
        printf("%s %s" ,input,"is valid");
    else
        printf("%s %s" ,input,"is invalid");
}