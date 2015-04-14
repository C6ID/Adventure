set(TARGET audio)

set (SOURCES
)

add_library(${TARGET} OBJECT ${SOURCES})

set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS "-fPIC")
