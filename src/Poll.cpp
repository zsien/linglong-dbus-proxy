#include "Poll.h"

#include <sys/epoll.h>

#include <stdexcept>

#include <stdlib.h>

#include "Handle.h"

#define MAX_EVENTS 10

Poll &Poll::instance()
{
    static Poll poll;
    return poll;
}

Poll::Poll()
    : fd_(epoll_create1(EPOLL_CLOEXEC))
{
    if (fd_ == -1) {
        throw std::runtime_error("epoll_create1");
    }
}

void Poll::attach(Handle *handle)
{
    epoll_event ev{};
    ev.events = handle->events();
    ev.data.fd = handle->fd();
    ev.data.ptr = handle;

    if (epoll_ctl(fd_, EPOLL_CTL_ADD, handle->fd(), &ev) == -1) {
        // return EXIT_FAILURE;
    }
}

void Poll::detech(Handle *handler)
{
    if (epoll_ctl(fd_, EPOLL_CTL_DEL, handler->fd(), nullptr) == -1) {
        // return EXIT_FAILURE;
    }
}

int Poll::run()
{
    int listen_sock, conn_sock;

    epoll_event events[MAX_EVENTS];
    for (;;) {
        int nfds = epoll_wait(fd_, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            // perror("epoll_wait");
            return EXIT_FAILURE;
        }

        for (int i = 0; i < nfds; ++i) {
            static_cast<Handle *>(events[i].data.ptr)->onEvent(events[i].events);
        }
    }
}
