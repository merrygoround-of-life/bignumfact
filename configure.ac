#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([bignumfact], [0.0.1], [plantrue@tistory.com])
AC_CONFIG_SRCDIR([test/test.cpp])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_USE_SYSTEM_EXTENSIONS

AC_CONFIG_MACRO_DIR([m4])
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

LT_INIT
AC_PROG_LIBTOOL

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h sys/time.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_STRNLEN
AC_CHECK_FUNCS([gettimeofday memset])

AC_CONFIG_FILES([Makefile
                 libbignumfact/Makefile
                 test/Makefile])
AC_OUTPUT
