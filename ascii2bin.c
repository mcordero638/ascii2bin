#include <stdio.h>
#include <unistd.h> 

int main()
{
    int offset = 32;  // ascii value of '0'
    int number = 0;
    char ascii_value;
    
    int retval = read(0, &ascii_value, 1);
    while ((retval == 1) && (ascii_value != '\n')) {
        int digit = ascii_value - offset;
        if ((digit == 1) || (digit == 0))
            number = (number << 1) + digit;  
        retval = read(0, &ascii_value, 1);
    }    
    printf("%d\n", number);

    return 0;
}