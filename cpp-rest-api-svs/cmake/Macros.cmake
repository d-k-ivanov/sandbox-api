# Generate a list of subdirectories
macro(SUBDIRLIST result curdir)
    file(GLOB children RELATIVE ${curdir} ${curdir}/*)
    set(dirlist "")
    foreach(child ${children})
        if(IS_DIRECTORY ${curdir}/${child})
            list(APPEND dirlist ${child})
        endif()
    endforeach()
    set(${result} ${dirlist})
endmacro()

macro(fix_project_version)
    if (NOT CMAKE_PROJECT_VERSION_PATCH)
        set(CMAKE_PROJECT_VERSION_PATCH 0)
    endif()

    if (NOT CMAKE_PROJECT_VERSION_TWEAK)
        set(CMAKE_PROJECT_VERSION_TWEAK 0)
    endif()
endmacro()
