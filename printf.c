/** function printf(format_string, arguments)
    start_index = 0
    while there is a format specifier in format_string after start_index:
        find the next format specifier after start_index
        output the substring of format_string from start_index to the start of the format specifier
        if the format specifier is a string:
            output the corresponding argument as a string
        else if the format specifier is an integer:
            output the corresponding argument as an integer
        else if the format specifier is a floating-point number:
            output the corresponding argument as a floating-point number
        else if the format specifier is a character:
            output the corresponding argument as a character
        else if the format specifier is a pointer:
            output the corresponding argument as a memory address
        else:
            output an error message
        start_index = the end of the current format specifier
    output the substring of format_string from start_index to the end
**/


#include <stdarg.h>
#include <stdio.h>

void my_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    int i = 0;
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 'c': {
                    char c = va_arg(args, int);
                    putchar(c);
                    break;
                }
                case 's': {
                    char* s = va_arg(args, char*);
                    printf("%s", s);
                    break;
                }
                case 'd': {
                    int d = va_arg(args, int);
                    printf("%d", d);
                    break;
                }
                case 'x': {
                    int x = va_arg(args, int);
                    printf("%x", x);
                    break;
                }
                default:
                    break;
            }
        }
        else {
            putchar(format[i]);
        }
        i++;
    }
    va_end(args);
}
