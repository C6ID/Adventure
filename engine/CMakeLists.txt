set(TARGET engine)

# Dependencies.
pkg_search_module(SDL2 REQUIRED sdl2 >= 2.0.0)
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image >= 2.0.0)
pkg_search_module(SDL2_MIXER REQUIRED SDL2_mixer >= 2.0.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_definitions(-D_C6ID_IN_LIB_BUILD)

add_subdirectory(core)
add_subdirectory(audio)

set(PUBLIC_HEADERS
    public/c6id_common.h
    public/c6id_uncommon.h
    public/adventure.h
    public/core/engine.h
)

add_library(${TARGET} SHARED
    adventure.cpp
    common.h
    ${PUBLIC_HEADERS}
    $<TARGET_OBJECTS:core>
    $<TARGET_OBJECTS:audio>
)

# Set default visibility to hidden.
set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS -fvisibility=hidden)

# Include directories.
target_include_directories(
    ${TARGET} SYSTEM PRIVATE
    .
    public
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS}
)

target_include_directories(
    ${TARGET} PUBLIC
    public
)

# Libraries.
target_link_libraries(
    ${TARGET}
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
)
