
add_definitions(
      -DFRIBIDI_ENTRY=extern
      -DFT2_BUILD_LIBRARY)

include_directories(include)

list(APPEND SOURCE
    fribidi.c
    fribidi-arabic.c
    fribidi-bidi.c
    fribidi-bidi-types.c
    fribidi-char-sets.c
    fribidi-char-sets-cap-rtl.c
    fribidi-char-sets-cp1255.c
    fribidi-char-sets-cp1256.c
    fribidi-char-sets-iso8859-6.c
    fribidi-char-sets-iso8859-8.c
    fribidi-char-sets-utf8.c
    fribidi-deprecated.c
    fribidi-joining.c
    fribidi-joining-types.c
    fribidi-mirroring.c
    fribidi-brackets.c
    fribidi-run.c
    fribidi-shape.c
    )

add_library(fribidi ${SOURCE})

if(USE_CLANG_CL)
    add_target_compile_flags(freetype "-Wno-tautological-constant-compare")
endif()
