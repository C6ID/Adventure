set(TARGET launcher)

add_executable(${TARGET}
    main.cpp
)

target_include_directories(
    ${TARGET} SYSTEM PRIVATE
    $<TARGET_PROPERTY:engine,INTERFACE_INCLUDE_DIRECTORIES>
)

target_link_libraries(
    ${TARGET}
    $<TARGET_FILE:engine>
)
