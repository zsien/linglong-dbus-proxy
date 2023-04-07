set(LL_DBUS_PROXY_SOURCES
    main.cpp
    NonCopyable.h
    Descriptor.h
    Descriptor.cpp
    Poll.h
    Poll.cpp
    Handle.h
    Handle.cpp
    LocalServer.h
    LocalServer.cpp
    LocalSocket.h
    LocalSocket.cpp
    DBus.h
    DBus.cpp
)

add_executable(ll-dbus-proxy
    ${LL_DBUS_PROXY_SOURCES}
)

target_link_libraries(ll-dbus-proxy PRIVATE
    PkgConfig::libsystemd
)
