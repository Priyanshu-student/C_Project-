#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int charToNumberConverter(char ch);
int checker(char a);
int hex2dec(); // Function prototype

int main() {
    hex2dec(); // Call the function
    return 0;
}

int hex2dec() {
    char str[60];
    int len, returns, store = 1;
    printf("ENTER THE HEXADECIMAL NUMBER:");
    scanf("%s", str);
    len = strlen(str);
    for (int i = 0; i < len; i++) {
        returns = checker(str[i]);
        if (returns == 0) {
            printf("INVALID NUMBER ENTERED");
            store = 0;
            break;
        }
    }
    if (store == 1) {
        int sum = 0;
        for (int i = 0, j = (len - 1); i < len; i++, j--) {
            sum = sum + charToNumberConverter(str[j]) * pow(16, i);
        }
        printf("The conversion of (%s)16 is (%d)10", str, sum);
    }
    return 0; // Indicate successful execution
}

int charToNumberConverter(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else if (ch >= 'A' && ch <= 'F') {
        return ch - 'A' + 10;
    } else if (ch >= 'a' && ch <= 'f') {
        return ch - 'a' + 10;
    }
    // Need a default return in case none of the conditions are met.
    return -1; // Or any suitable error code
}

int checker(char a) {
    if ((a >= '0' && a <= '9') || (a >= 'A' && a <= 'F') || (a >= 'a' && a <= 'f')) {
        return 1;
    }
    return 0;
}
