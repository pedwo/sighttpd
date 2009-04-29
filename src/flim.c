#include <stdio.h>
#include <string.h>

#include "params.h"

#define FLIM_TEXT "flim flim flim\n"

params_t *
flim_append_headers (params_t * response_headers)
{
        char length[16];

        response_headers = params_append (response_headers, "Content-Type", "text/plain");
        snprintf (length, 16, "%d", strlen (FLIM_TEXT));
        response_headers = params_append (response_headers, "Content-Length", length);
}

int
flim_stream_body (int fd)
{
        write (fd, FLIM_TEXT, strlen(FLIM_TEXT));
}

