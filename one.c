#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    char ch = 'A';
    printf("ch value is %d which is the ASCII value of %c\n", ch, ch); // we can acquire the ascii decimal value via %d
    // Scanners
    int number;
    printf("What is your age?\n");
    scanf("%d",&number); // pointer?
    printf("%d",number);
    return 0;
}
