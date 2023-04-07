#ifndef POLL_H
#define POLL_H

#include "NonCopyable.h"

class Handle;

class Poll : public NonCopyable
{
    friend Handle;

public:
    static Poll &instance();

    int run();

private:
    int fd_;

    Poll();
    void attach(Handle *handle);
    void detech(Handle *handle);
};

#endif // !POLL_H
