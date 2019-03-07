
list(APPEND TESTS
    biditest.c
	lpkgetextent.c
	psmtest.c
	precomp.h)
	
add_executable(unidemo
    main.c
	${TESTS}
    strings.rc)

set_module_type(unidemo win32gui UNICODE)
add_importlibs(unidemo lpk usp10 gdi32 user32 shell32 comctl32 msvcrt kernel32 ntdll)
add_rostests_file(TARGET unidemo SUBDIR suppl)
