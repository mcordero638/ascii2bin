#include <stdio.h>
#include <unistd.h>

int main()
{
int offset = 48; // ascii value of '0'
int number = 0;
char ascii_value;
int digit;
int retval;

retval = read(0, &ascii_value, 1);
while (retval==1 && ascii_value != '\n') {
switch (ascii_value) {
case ('0'): //if ascii_value is 0 or 1 and number is not too big, break out of switch
case ('1'):
if (!(number & 0x80000000)) break;
default: return 0; //return 0 upon failure
}
digit = ascii_value - offset;
number = (number << 1) + digit;
retval = read(0, &ascii_value, 1);
}
printf("%u\n", number);
return 0;
}
