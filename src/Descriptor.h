#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

class Descriptor {
public:
    Descriptor(int fd);
    ~Descriptor();

    int operator *() {
        return fd_;
    }

private:
    int fd_;
};

#endif // !DESCRIPTOR_H
