#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"


int main() {
    stdio_init_all();

    // drain garbage from the input buffer
    while(getchar_timeout_us(0) == PICO_ERROR_TIMEOUT);

    char buf[128];
    while(true) {
        printf("Move cursor into the bottom bar, then enter a string, int or float: ");
        fgets(buf, sizeof(buf), stdin);     //! NB: avoid scanf() like the plague

        printf("Received %u chars: %s\n", strlen(buf), buf);

        // try to parse the string as an integer
        int i;
        if (sscanf(buf, "%d", &i) == 1) {
            printf("As integer: %d\n", i);
        }

        // try to parse the string as a double (floats are a bit rubbish)
        double d;
        if (sscanf(buf, "%lf", &d) == 1) {
            printf("As double: %lf\n", d);
        }

    }
}