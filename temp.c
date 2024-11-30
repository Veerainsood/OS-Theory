#include <unistd.h>
#include <stdarg.h>
#include<stdio.h>
void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 'd') {
                int i = va_arg(args, int);
                char buffer[20];
                int len = snprintf(buffer, sizeof(buffer), "%d", i);
                write(1, buffer, len);
            } else if (*format == 'c') {
                char c = (char)va_arg(args, int);
                write(1, &c, 1);
            } else if (*format == 's') {
                char *s = va_arg(args, char *);
                while (*s) {
                    write(1, s++, 1);
                }
            }
        } else {
            write(1, format, 1);
        }
        format++;
    }

    va_end(args);
}

int main() {
    my_printf("Hello, %s! You are %d years old and your grade is %c.\n", "Alice", 30, 'A');
    return 0;
}