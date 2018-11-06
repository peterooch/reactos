
spec2def(winejoystick.drv winejoystick.drv.spec)

add_library(winejoystick.drv SHARED
    joystick.c
    ${CMAKE_CURRENT_BINARY_DIR}/winejoystick.def)

set_module_type(winejoystick.drv win32dll UNICODE)
target_link_libraries(winejoystick.drv wine)
add_importlibs(winejoystick.drv user32 winmm msvcrt kernel32 ntdll)
add_cd_file(TARGET winejoystick.drv DESTINATION reactos/system32 FOR all)
