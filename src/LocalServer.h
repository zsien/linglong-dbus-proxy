#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include "Descriptor.h"
#include "Handle.h"

#include <functional>
#include <memory>
#include <string>

class LocalSocket;

class LocalServer : public Handle
{
public:
    bool listen(const std::string &name);
    std::shared_ptr<LocalSocket> accept();

    void setOnNewConnection(const std::function<void()> &callback);

private:
    Descriptor fd_;
    std::function<void()> onNewConnection_;

    void onEvent(uint32_t events) override;
    int fd() override;
    uint32_t events() override;
};

#endif // !LOCALSERVER_H
