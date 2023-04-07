#include "DBus.h"

DBus::DBus(TYPE type)
{
    decltype(&sd_bus_open) f;

    switch (type) {
    case TYPE::USER:
        f = &sd_bus_open_user;
        break;
    case TYPE::SYSTEM:
        f = &sd_bus_open_system;
        break;
    }

    f(&bus_);
    attach();
}

DBus::~DBus()
{
    detach();
    sd_bus_close_unref(bus_);
}

void DBus::onEvent([[maybe_unused]] uint32_t events)
{
    sd_bus_process(bus_, nullptr);
}

int DBus::fd()
{
    return sd_bus_get_fd(bus_);
}

uint32_t DBus::events()
{
    return sd_bus_get_events(bus_);
}
