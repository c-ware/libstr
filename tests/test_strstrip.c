/*
 * Tests the strstrip function.
*/

#include "common.h"

int main(void) {
    char string_a[256 + 1] = "foo bar baz";

    assert(strcmp(string_a, "foo bar baz") == 0);
    assert(strstrip(string_a, "f b") == 5);
    assert(strcmp(string_a, "ooaraz") == 0);

    assert(strstrip(string_a, "oar") == 5);
    assert(strcmp(string_a, "z") == 0);

    /* Stripping characters not present in the source string */
    assert(strstrip(string_a, "m") == 0);
    assert(strcmp(string_a, "z") == 0);

    /* Stripping one character */
    assert(strstrip(string_a, "z") == 1);
    assert(strcmp(string_a, "") == 0);

    return EXIT_SUCCESS;
}
