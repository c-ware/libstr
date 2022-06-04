/*
 * Tests the strstarts function.
*/

#include "common.h"

int main(void) {
    assert(strstarts("foo bar", "foo") == 1);
    assert(strstarts("foo bar", "fo") == 1);
    assert(strstarts("foo bar", "foob") == 0);

    /* Sub-string longer than string */
    assert(strstarts("foo", "foob") == 0);
    assert(strstarts("fo", "foob") == 0);
    assert(strstarts("f", "foob") == 0);

    /* Empty arguments */
    assert(strstarts("", "foob") == 0);
    assert(strstarts("foo", "") == 1);

    return EXIT_SUCCESS;
}
