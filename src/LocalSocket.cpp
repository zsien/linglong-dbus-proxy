#include "LocalSocket.h"

#include <sys/epoll.h>

LocalSocket::LocalSocket(int fd)
    : fd_(fd)
{
}

void LocalSocket::onEvent(uint32_t events)
{
    if (events & EPOLLIN) { }
}

int LocalSocket::fd()
{
    return fd_;
}

uint32_t LocalSocket::events()
{
    return EPOLLIN;
}
