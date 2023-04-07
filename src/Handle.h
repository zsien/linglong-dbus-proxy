#ifndef HANDLE_H
#define HANDLE_H

#include <stdint.h>

#include "NonCopyable.h"

class Handle : public NonCopyable
{
    friend class Poll;

public:
    Handle();
    virtual ~Handle();

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
