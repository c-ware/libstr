#include "common.h"

int main(void) {
    char buffer[256 + 1];

    ls_snprintf(buffer, 256, "%s bar %s tuna\n", "foo", "baz");

    return EXIT_SUCCESS;
}
