
spec2def(joystick.drv joystick.drv.spec)

add_library(joystick.drv SHARED
    joystick.c
    joystick.rc
    ${CMAKE_CURRENT_BINARY_DIR}/joystick.def)

set_module_type(joystick.drv win32dll UNICODE)
set_target_properties(joystick.drv PROPERTIES SUFFIX "")
target_link_libraries(joystick.drv wine)
add_importlibs(joystick.drv user32 winmm msvcrt kernel32 ntdll)
add_cd_file(TARGET joystick.drv DESTINATION reactos/system32 FOR all)
