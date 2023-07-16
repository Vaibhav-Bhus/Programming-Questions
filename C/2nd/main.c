#include <stdio.h>
#include <string.h>

int main(void) {
    char st1[] = "this is a string";
    char st2[] = "is";
    if (strstr(st1, st2) == NULL)
        printf("%s not in %s", st2, st1);
    else
        printf("%s", strstr(st1, st2));
    return 0;
}
