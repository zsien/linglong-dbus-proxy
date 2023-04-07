#ifndef HANDLE_H
#define HANDLE_H

#include <stdint.h>

class Handle
{
    friend class Poll;

public:
    Handle();
    ~Handle();

    void attach();
    void detach();

protected:
    virtual void onEvent(uint32_t events) = 0;
    virtual int fd() = 0;
    virtual uint32_t events() = 0;

private:
    bool attached_;
};

#endif // !HANDLE_H
