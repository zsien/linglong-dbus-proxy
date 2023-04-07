#include "LocalServer.h"

#include "LocalSocket.h"

#include <sys/epoll.h>

#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

bool LocalServer::listen(const std::string &name)
{
    int fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd == -1) {
        return false;
    }

    fd_ = fd;

    sockaddr_un addr{};
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, name.data(), name.size());

    int ret = bind(*fd_, reinterpret_cast<const sockaddr *>(&addr), sizeof(sockaddr_un));
    if (ret == -1) {
        return false;
    }

    ret = ::listen(*fd_, 10);
    if (ret == -1) {
        return false;
    }

    attach();
    return true;
}

std::shared_ptr<LocalSocket> LocalServer::accept()
{
    sockaddr_un addr;
    socklen_t addrlen = sizeof(sockaddr_un);
    int fd = ::accept(*fd_, reinterpret_cast<sockaddr *>(&addr), &addrlen);
    if (fd == -1) {
        return nullptr;
    }

    return std::make_shared<LocalSocket>(fd);
}

void LocalServer::setOnNewConnection(const std::function<void()> &callback)
{
    onNewConnection_ = callback;
}

void LocalServer::onEvent(uint32_t events)
{
    if (events & EPOLLIN) {
        onNewConnection_();
    }
}

int LocalServer::fd()
{
    return *fd_;
}

uint32_t LocalServer::events()
{
    return EPOLLIN;
}
