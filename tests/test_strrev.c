/*
 * Tests the strrev function.
*/

#include "common.h"

int main(void) {
    char string_a[256 + 1] = "foo bar";
    char string_b[256 + 1] = "";
    char string_c[256 + 1] = "f";
    char string_d[256 + 1] = "fo";
    
    assert(strcmp(string_a, "foo bar") == 0);
    assert(strrev(string_a) == string_a);
    assert(strcmp(string_a, "rab oof") == 0);

    /* Empty string */
    assert(strcmp(string_b, "") == 0);
    assert(strrev(string_b) == string_b);
    assert(strcmp(string_b, "") == 0);

    /* Length 1 string */
    assert(strcmp(string_c, "f") == 0);
    assert(strrev(string_c) == string_c);
    assert(strcmp(string_c, "f") == 0);

    /* Length 2 string */
    assert(strcmp(string_d, "fo") == 0);
    assert(strrev(string_d) == string_d);
    assert(strcmp(string_d, "of") == 0);

    return EXIT_SUCCESS;
}
