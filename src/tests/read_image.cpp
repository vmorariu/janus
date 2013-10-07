#include <stdio.h>
#include <stdlib.h>

#include "janus.h"
#include "janus_io.h"

// Makes assumptions that are tested by `initialize`
int main(int argc, char *argv[])
{
    (void) argc;
    janus_initialize(argv[1]);

    const char *file = "../data/Kirchner0.jpg";
    janus_image image = janus_read_image(file);
    if (image == NULL) {
        printf("Failed to read image: %s\n", file);
        abort();
    }
    janus_free_image(image);

    janus_finalize();
    return 0;
}
