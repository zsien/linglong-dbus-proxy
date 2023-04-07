#ifndef LOCALSOCKET_H
#define LOCALSOCKET_H

#include "Descriptor.h"
#include "Handle.h"

#include <string>

class LocalSocket : public Handle
{
public:
    LocalSocket(int fd);

    // bool connect(const std::string &name);
    void send(const std::string &msg);

private:
    Descriptor fd_;

    void onEvent(uint32_t events) override;
    int fd() override;
    uint32_t events() override;
};

#endif // !LOCALSOCKET_H
