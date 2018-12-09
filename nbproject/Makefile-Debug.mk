#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/field.o \
	${OBJECTDIR}/life.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/row.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wabi -Waddress -Waggressive-loop-optimizations -Warray-bounds -Wattributes -Wbool-compare -Wbuiltin-macro-redefined -Wc++0x-compat -Wc++14-compat -Wcast-align -Wchar-subscripts -Wchkp -Wclobbered -Wcomment -Wconversion-null -Wcoverage-mismatch -Wcpp -Wdate-time -Wdelete-incomplete -Wdelete-non-virtual-dtor -Wdeprecated -Wdeprecated-declarations -Wdisabled-optimization -Wdiv-by-zero -Wempty-body -Wendif-labels -Wenum-compare -Wformat-contains-nul -Wformat-extra-args -Wformat-security -Wformat-signedness -Wformat-y2k -Wformat-zero-length -Wfree-nonheap-object -Wignored-qualifiers -Winherited-variadic-ctor -Winit-self -Winline -Wint-to-pointer-cast -Winvalid-memory-model -Winvalid-offsetof -Winvalid-pch -Wliteral-suffix -Wlogical-not-parentheses -Wlogical-op -Wmain -Wmaybe-uninitialized -Wmemset-transposed-args -Wmissing-braces -Wmissing-declarations -Wmissing-field-initializers -Wmissing-include-dirs -Wmultichar -Wnarrowing -Wnoexcept -Wnon-template-friend -Wnon-virtual-dtor -Wnonnull -Wodr -Wold-style-cast -Wopenmp-simd -Woverflow -Woverlength-strings -Woverloaded-virtual -Wpacked -Wpacked-bitfield-compat -Wparentheses -Wall -Wpmf-conversions -Wpointer-arith -Wpragmas -Wredundant-decls -Wreorder -Wreturn-local-addr -Wreturn-type -Wsequence-point -Wshadow -Wshift-count-negative -Wshift-count-overflow -Wsign-compare -Wsign-promo -Wsized-deallocation -Wsizeof-array-argument -Wsizeof-pointer-memaccess -Wstack-protector -Wstrict-null-sentinel -Wswitch -Wswitch-bool -Wswitch-default -Wswitch-enum -Wsync-nand -Wsynth -Wsystem-headers -Wtrampolines -Wtrigraphs -Wtype-limits -Wuninitialized -Wunknown-pragmas -Wunsafe-loop-optimizations -Wunused -Wunused-but-set-parameter -Wunused-but-set-variable -Wunused-function -Wunused-label -Wunused-local-typedefs -Wunused-macros -Wunused-result -Wunused-value -Wunused-variable -Wvarargs -Wvariadic-macros -Wvector-operation-performance -Wvirtual-move-assign -Wvla -Wvolatile-register-var -Wwrite-strings
CXXFLAGS=-Wabi -Waddress -Waggressive-loop-optimizations -Warray-bounds -Wattributes -Wbool-compare -Wbuiltin-macro-redefined -Wc++0x-compat -Wc++14-compat -Wcast-align -Wchar-subscripts -Wchkp -Wclobbered -Wcomment -Wconversion-null -Wcoverage-mismatch -Wcpp -Wdate-time -Wdelete-incomplete -Wdelete-non-virtual-dtor -Wdeprecated -Wdeprecated-declarations -Wdisabled-optimization -Wdiv-by-zero -Wempty-body -Wendif-labels -Wenum-compare -Wformat-contains-nul -Wformat-extra-args -Wformat-security -Wformat-signedness -Wformat-y2k -Wformat-zero-length -Wfree-nonheap-object -Wignored-qualifiers -Winherited-variadic-ctor -Winit-self -Winline -Wint-to-pointer-cast -Winvalid-memory-model -Winvalid-offsetof -Winvalid-pch -Wliteral-suffix -Wlogical-not-parentheses -Wlogical-op -Wmain -Wmaybe-uninitialized -Wmemset-transposed-args -Wmissing-braces -Wmissing-declarations -Wmissing-field-initializers -Wmissing-include-dirs -Wmultichar -Wnarrowing -Wnoexcept -Wnon-template-friend -Wnon-virtual-dtor -Wnonnull -Wodr -Wold-style-cast -Wopenmp-simd -Woverflow -Woverlength-strings -Woverloaded-virtual -Wpacked -Wpacked-bitfield-compat -Wparentheses -Wall -Wpmf-conversions -Wpointer-arith -Wpragmas -Wredundant-decls -Wreorder -Wreturn-local-addr -Wreturn-type -Wsequence-point -Wshadow -Wshift-count-negative -Wshift-count-overflow -Wsign-compare -Wsign-promo -Wsized-deallocation -Wsizeof-array-argument -Wsizeof-pointer-memaccess -Wstack-protector -Wstrict-null-sentinel -Wswitch -Wswitch-bool -Wswitch-default -Wswitch-enum -Wsync-nand -Wsynth -Wsystem-headers -Wtrampolines -Wtrigraphs -Wtype-limits -Wuninitialized -Wunknown-pragmas -Wunsafe-loop-optimizations -Wunused -Wunused-but-set-parameter -Wunused-but-set-variable -Wunused-function -Wunused-label -Wunused-local-typedefs -Wunused-macros -Wunused-result -Wunused-value -Wunused-variable -Wvarargs -Wvariadic-macros -Wvector-operation-performance -Wvirtual-move-assign -Wvla -Wvolatile-register-var -Wwrite-strings

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/life

${CND_DISTDIR}/life: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}
	${LINK.cc} -o ${CND_DISTDIR}/life ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/field.o: field.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/field.o field.cpp

${OBJECTDIR}/life.o: life.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/life.o life.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/row.o: row.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/row.o row.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
