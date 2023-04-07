#ifndef DBUS_H
#define DBUS_H

#include <systemd/sd-bus.h>

#include "Handle.h"

class DBus : public Handle
{
public:
    enum class TYPE { USER, SYSTEM };

    DBus(TYPE type);
    ~DBus();

private:
    sd_bus *bus_;

    void onEvent(uint32_t events) override;
    int fd() override;
    uint32_t events() override;
};

#endif // !DBUS_H
