#include <stdbool.h>
#include <string.h>

bool is_number(char c) {
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

bool validate_pin(const char *pin) {
    int len = strlen(pin);

    if (len == 4 || len == 6) {

        for (int i = 0; i < len; i++) {
            if (is_number(pin[i]) == false)
                return false;
        }
        return true;
    }

    return false;
}
