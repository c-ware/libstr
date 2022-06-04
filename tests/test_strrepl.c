/*
 * Tests the strrepl function.
*/

#include "common.h"

int main(void) {
    char string[256 + 1] = {0};
    char string_b[12 + 1] = {0};

    strcat(string, "foo++bar++baz");
    assert(strrepl(string, "++", "-", 256) == 2);
    assert(strcmp(string, "foo-bar-baz") == 0);
    memset(string, 0, 257);

    strcat(string, "foo++++bar++++baz");
    assert(strrepl(string, "++++", "--", 256) == 2);
    assert(strcmp(string, "foo--bar--baz") == 0);
    memset(string, 0, 257);

    /* Same length of find and replace */
    strcat(string, "foo++++bar++++baz");
    assert(strrepl(string, "++++", "----", 256) == 2);
    assert(strcmp(string, "foo----bar----baz") == 0);
    memset(string, 0, 257);

    /* 'Delete' find */
    strcat(string, "foo++++bar++++baz");
    assert(strrepl(string, "++++", "", 256) == 2);
    assert(strcmp(string, "foobarbaz") == 0);
    memset(string, 0, 257);

    /* Replace > find */
    strcat(string, "foo++++bar++++baz");
    assert(strrepl(string, "++", "---", 256) == 4);
    assert(strcmp(string, "foo------bar------baz") == 0);
    memset(string, 0, 257);

    strcat(string, "foo++++bar++++baz");
    assert(strrepl(string, "+", "---", 256) == 8);
    assert(strcmp(string, "foo------------bar------------baz") == 0);
    memset(string, 0, 257);

    /* Now, for the nail-biter. Whether or not the code successfully
     * respects buffer boundaries. The string used from here on has a
     * length of 12 bytes, + 1 for the NUL byte.*/
    
    strcat(string_b, "foo_bar_baz"); /* Takes up 11 bytes */
    assert(strrepl(string_b, "_", "++", 12) == -1);
    assert(strcmp(string_b, "foo_bar_baz") == 0);
    memset(string_b, 0, 13);

    strcat(string_b, "foo_bar_baz"); /* Takes up 11 bytes */
    assert(strrepl(string_b, "_", "+", 12) == 2);
    assert(strcmp(string_b, "foo+bar+baz") == 0);
    memset(string_b, 0, 13);

    /* Will create a full buffer */
    strcat(string_b, "foo_ba_baz"); /* Takes up 12 bytes */
    assert(strrepl(string_b, "_", "++", 12) == 2);
    assert(strcmp(string_b, "foo++ba++baz") == 0);
    memset(string_b, 0, 13);

    /* Take up the entire buffer */
    strcat(string_b, "foo_bar_baz_"); /* Takes up 12 bytes */
    assert(strrepl(string_b, "_", "+", 12) == 3);
    assert(strcmp(string_b, "foo+bar+baz+") == 0);
    memset(string_b, 0, 13);

    strcat(string_b, "foo_bar_baz_"); /* Takes up 12 bytes */
    assert(strrepl(string_b, "_", "++", 12) == -1);
    assert(strcmp(string_b, "foo_bar_baz_") == 0);
    memset(string_b, 0, 13);

    strcat(string_b, "foo_bar_baz+"); /* Takes up 12 bytes */
    assert(strrepl(string_b, "_", "", 12) == 2);
    assert(strcmp(string_b, "foobarbaz+") == 0);
    memset(string_b, 0, 13);

    strcat(string_b, "foo_bar_baz_"); /* Takes up 12 bytes */
    assert(strrepl(string_b, "_", "", 12) == 3);
    assert(strcmp(string_b, "foobarbaz") == 0);
    memset(string_b, 0, 13);

    return EXIT_SUCCESS;
}
