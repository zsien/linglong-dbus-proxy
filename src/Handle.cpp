#include "Handle.h"

#include "Poll.h"

Handle::Handle()
    : attached_(false)
{
}

Handle::~Handle()
{
    if (attached_) {
        detach();
    }
}

void Handle::attach()
{
    Poll::instance().attach(this);
    attached_ = true;
}

void Handle::detach()
{
    Poll::instance().detech(this);
}
