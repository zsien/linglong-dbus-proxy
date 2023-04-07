#include "Descriptor.h"

#include <stdexcept>

#include <unistd.h>

Descriptor::Descriptor(int fd)
    : fd_(fd)
{
}

Descriptor::~Descriptor()
{
    close(fd_);
}
