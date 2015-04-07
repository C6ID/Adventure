set (TARGET core)

set (SOURCES
    main/engineimpl.cpp
    main/engineimpl.h
    main/engineutils.cpp
    main/engineutils.h

    framework/assert.h
    framework/common.h
    framework/loglevel.h
    framework/logoutput.h
    framework/messageboxlogoutput.cpp
    framework/messageboxlogoutput.h
    framework/ostreamlogoutput.cpp
    framework/ostreamlogoutput.h

    system/sdlsystem.cpp
    system/sdlsystem.h
    system/system.cpp
    system/system.h

    events/event.h
)

add_library(${TARGET} OBJECT ${SOURCES})

set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS "-fPIC")

target_include_directories(
    ${TARGET} SYSTEM PRIVATE
    .
    ../public
    ${SDL2_INCLUDE_DIRS}
)
