/*
 * Tests the strcount function.
*/

#include "common.h"

int main(void) {
    assert(strcount("foo bar baz", " ") == 2);
    assert(strcount("foo bar baz", "  ") == 0);
    assert(strcount("foo bar baz", "ba") == 2);
    assert(strcount("foo bar baz", "") == 0);

    /* Count being longer than the string */
    assert(strcount("foo", "bar baz") == 0);
    assert(strcount("foo", "foo bar baz") == 0);
    assert(strcount("fo", "foo") == 0);
    assert(strcount("f", "fo") == 0);

    /* Same length */
    assert(strcount("foo", "foo") == 1);
    assert(strcount("fo", "fo") == 1);
    assert(strcount("f", "f") == 1);

    /* No string to count in */
    assert(strcount("", "f") == 0);
    assert(strcount("", "") == 0);

    return EXIT_SUCCESS;
}
