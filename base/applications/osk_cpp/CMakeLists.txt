set_cpp(WITH_RUNTIME)

if(NOT MSVC)
    # HACK: this should be enabled globally!
    add_compile_flags_language("-std=c++11" "CXX")
endif()

list(APPEND SOURCE
    base.cpp
    keyboard.cpp
    main.cpp
    mainwindow.cpp)

file(GLOB osk_cpp_rc_deps res/*.*)
add_rc_deps(rsrc.rc ${osk_cpp_rc_deps})
add_executable(osk_cpp ${SOURCE} rsrc.rc)
set_module_type(osk_cpp win32gui UNICODE)
add_importlibs(osk_cpp winmm shell32 user32 gdi32 advapi32 comctl32 msvcrt kernel32 ntdll)
add_cd_file(TARGET osk_cpp DESTINATION reactos/system32 FOR all)
