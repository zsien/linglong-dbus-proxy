#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

class NonCopyable {
public:
    NonCopyable() = default;
    ~NonCopyable() = default;

protected:
    NonCopyable(const NonCopyable &) = delete;
    const NonCopyable &operator=(const NonCopyable &) = delete;

    NonCopyable(NonCopyable &&) = default;
    NonCopyable &operator=(NonCopyable &&) = default;
};

#endif // !NONCOPYABLE_H
