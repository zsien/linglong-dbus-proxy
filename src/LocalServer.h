#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include "Handle.h"

#include <functional>
#include <memory>
#include <string>

class LocalSocket;

class LocalServer : public Handle
{
public:
    LocalServer() = default;
    ~LocalServer();

    bool listen(const std::string &name);
    std::shared_ptr<LocalSocket> accept();

    void setOnNewConnection(const std::function<void()> &callback);

private:
    int fd_ = -1;
    std::function<void()> onNewConnection_;

    void onEvent(uint32_t events) override;
    int fd() override;
    uint32_t events() override;
};

#endif // !LOCALSERVER_H
