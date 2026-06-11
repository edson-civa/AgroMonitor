#define EIF_EXCEPTION_TRACE
#define GE_USE_BOEHM_GC

/*
	description:

		"C declarations for the Gobo Eiffel runtime."

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2005-2026, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_EIFFEL_H
#define GE_EIFFEL_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Class name mapping as defined in the FreeELKS library. */
#ifndef EIF_INTEGER
#define EIF_INTEGER EIF_INTEGER_32
#endif
#ifndef EIF_CHARACTER
#define EIF_CHARACTER EIF_CHARACTER_8
#endif
#ifndef EIF_REAL
#define EIF_REAL EIF_REAL_32
#endif
#ifndef EIF_DOUBLE
#define EIF_DOUBLE EIF_REAL_64
#endif
#ifndef GE_ms
#if EIF_CHARACTER == EIF_CHARACTER_8
#define GE_ms(s,c) GE_ms8((s),(c))
#else
#define GE_ms(s,c) GE_ms32((s),(c))
#endif
#endif

#if defined(__USE_POSIX) || defined(__unix__) || defined(_POSIX_C_SOURCE)
#include <unistd.h>
#endif
#if !defined(WIN32) && \
	(defined(WINVER) || defined(_WIN32_WINNT) || defined(_WIN32) || \
	defined(__WIN32__) || defined(__TOS_WIN__) || defined(_MSC_VER) || \
	defined(__MINGW32__))
#define WIN32 1
#endif
#ifdef WIN32
#define EIF_WINDOWS 1
#define GE_WINDOWS
#define WIN32_LEAN_AND_MEAN 1 /* Needed when using winsock2.h. */
#include <windows.h>
#endif

/* See https://sourceforge.net/p/predef/wiki/OperatingSystems/ */
#if (defined(macintosh) || defined(Macintosh))
#define EIF_MAC 1
#define EIF_MACOSX 1
#define GE_MACOS
#endif
#if (defined(__APPLE__) && defined(__MACH__))
/* Apparently ISE does not define EIF_MASOSX for Mac OS X >=10.4 (see EXECUTION_ENVIRONMENT.available_cpu_count) */
#define EIF_MAC 1
#define GE_MACOS
#endif

#if (defined(VMS) || defined(__VMS))
#define EIF_VMS 1
#endif

#if (defined(__VXWORKS__) || defined(__vxworks))
#define EIF_VXWORKS 1
#endif

#if defined(__OpenBSD__)
#define GE_OPENBSD
#endif

#define BYTEORDER 0x1234

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stddef.h>

#define EIF_OS_WINNT 	1
#define EIF_OS_LINUX 	2
#define EIF_OS_DARWIN 	4
#define EIF_OS_VXWORKS	11
#define EIF_OS_VMS	12

/* Platform definition */
/* Unix definition */
#define EIF_IS_UNIX EIF_TRUE
#define EIF_OS EIF_OS_LINUX
/* Windows definition */
#ifdef EIF_WINDOWS
#define EIF_IS_WINDOWS EIF_TRUE
#undef EIF_OS
#define EIF_OS EIF_OS_WINNT
#undef EIF_IS_UNIX
#define EIF_IS_UNIX EIF_FALSE
#else
#define EIF_IS_WINDOWS EIF_FALSE
#endif
/* VMS definition */
#ifdef EIF_VMS
#define EIF_IS_VMS EIF_TRUE
#undef EIF_OS
#define EIF_OS EIF_OS_VMS
#undef EIF_IS_UNIX
#define EIF_IS_UNIX EIF_FALSE
#else
#define EIF_IS_VMS EIF_FALSE
#endif
/* MAC definition */
#ifdef EIF_MAC
#define EIF_IS_MAC EIF_TRUE
#undef EIF_OS
#define EIF_OS EIF_OS_DARWIN
#undef EIF_IS_UNIX
#define EIF_IS_UNIX EIF_FALSE
#else
#define EIF_IS_MAC EIF_FALSE
#endif
/* VxWorks definition */
#ifdef EIF_VXWORKS
#define EIF_IS_VXWORKS EIF_TRUE
#undef EIF_OS
#define EIF_OS EIF_OS_VXWORKS
#undef EIF_IS_UNIX
#define EIF_IS_UNIX EIF_FALSE
#else
#define EIF_IS_VXWORKS EIF_FALSE
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _MSC_VER /* MSVC */
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed __int64 int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned __int64 uint64_t;
#else
#if defined (__BORLANDC__) && (__BORLANDC__ < 0x600) /* Borland before 6.0 */
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed long int int32_t;
typedef signed __int64 int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned __int64 uint64_t;
#else
#include <inttypes.h>
#endif
#endif

/* Portable integer pointers */
#ifdef EIF_WINDOWS
#ifndef _INTPTR_T_DEFINED
#define _INTPTR_T_DEFINED
#ifdef _WIN64
typedef __int64 intptr_t;
#else
typedef int intptr_t;
#endif
#endif
#ifndef _UINTPTR_T_DEFINED
#define _UINTPTR_T_DEFINED
#ifdef _WIN64
typedef unsigned __int64 uintptr_t;
#else
typedef unsigned int uintptr_t;
#endif
#endif
#endif

/* C type for underlying integer type identifying object's dynamic type. */
typedef uint16_t EIF_TYPE_INDEX;

/*
 * Abstraction representing an Eiffel type.
 * It is made of a compiler type-id,
 * and of some annotations (attached/detachable/separate/variant/frozen).
 */
typedef volatile struct {
	EIF_TYPE_INDEX volatile id;
	EIF_TYPE_INDEX volatile annotations;
} EIF_TYPE;

/*
 * Since EIF_TYPE and EIF_ENCODED_TYPE have the same size, the encoded version
 * is basically a memcpy version of the EIF_TYPE representation.
 * It is used to provide backward compatibility to most Eiffel and
 * C APIs manipulating types as an INTEGER.
 */
typedef int32_t EIF_ENCODED_TYPE;
typedef EIF_ENCODED_TYPE EIF_TYPE_ID;
#define EIF_NO_TYPE (EIF_TYPE_ID)(-1)

/* SCOOP */
#ifdef GE_USE_SCOOP
typedef struct GE_scoop_region_struct GE_scoop_region;
#endif

/* Basic Eiffel types */
typedef char EIF_BOOLEAN;
typedef unsigned char EIF_CHARACTER_8;
typedef uint32_t EIF_CHARACTER_32;
typedef int8_t EIF_INTEGER_8;
typedef int16_t EIF_INTEGER_16;
typedef int32_t EIF_INTEGER_32;
typedef int64_t EIF_INTEGER_64;
typedef uint8_t EIF_NATURAL_8;
typedef uint16_t EIF_NATURAL_16;
typedef uint32_t EIF_NATURAL_32;
typedef uint64_t EIF_NATURAL_64;
typedef volatile void* EIF_POINTER;
typedef float EIF_REAL_32;
typedef double EIF_REAL_64;

typedef volatile struct {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
#ifdef GE_USE_SCOOP
	GE_scoop_region* volatile region;
#endif
} EIF_ANY;
typedef EIF_ANY* EIF_REFERENCE;

typedef volatile struct {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
#ifdef GE_USE_SCOOP
	GE_scoop_region* volatile region;
#endif
#ifdef GE_HAS_STRING_8_ONCE_PER_OBJECT
	void* volatile onces;
#endif
	EIF_REFERENCE volatile area;
	EIF_INTEGER volatile count;
} EIF_STRING_8;

typedef volatile struct {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
#ifdef GE_USE_SCOOP
	GE_scoop_region* volatile region;
#endif
#ifdef GE_HAS_STRING_32_ONCE_PER_OBJECT
	void* volatile onces;
#endif
	EIF_REFERENCE volatile area;
	EIF_INTEGER volatile count;
} EIF_STRING_32;

typedef volatile struct {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
#ifdef GE_USE_SCOOP
	GE_scoop_region* volatile region;
#endif
#ifdef GE_HAS_IMMUTABLE_STRING_8_ONCE_PER_OBJECT
	void* volatile onces;
#endif
	EIF_REFERENCE volatile area;
	EIF_INTEGER volatile count;
} EIF_IMMUTABLE_STRING_8;

typedef volatile struct {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
#ifdef GE_USE_SCOOP
	GE_scoop_region* volatile region;
#endif
#ifdef GE_HAS_IMMUTABLE_STRING_32_ONCE_PER_OBJECT
	void* volatile onces;
#endif
	EIF_REFERENCE volatile area;
	EIF_INTEGER volatile count;
} EIF_IMMUTABLE_STRING_32;

typedef volatile struct {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
#ifdef GE_USE_SCOOP
	GE_scoop_region* volatile region;
#endif
#ifdef GE_HAS_SPECIAL_ONCE_PER_OBJECT
	void* volatile onces;
#endif
	EIF_INTEGER volatile capacity;
	EIF_INTEGER volatile count;
} EIF_SPECIAL;

/* SCOOP */
typedef uint16_t EIF_SCP_PID; /* Processor ID */
#ifdef GE_USE_SCOOP
#define RTS_PID(o) (EIF_SCP_PID)(uintptr_t)(((EIF_REFERENCE)(o))->region)
#else
#define RTS_PID(o) (EIF_SCP_PID)0
#endif

#ifdef EIF_WINDOWS
typedef wchar_t EIF_NATIVE_CHAR;
#else
typedef char EIF_NATIVE_CHAR;
#endif
typedef EIF_NATIVE_CHAR* EIF_FILENAME;

#define EIF_VOID ((EIF_REFERENCE)0)
#define EIF_FALSE ((EIF_BOOLEAN)'\0')
#define EIF_TRUE ((EIF_BOOLEAN)'\1')
#define EIF_TEST(x) ((x) ? EIF_TRUE : EIF_FALSE)

#define EIF_IS_WORKBENCH EIF_FALSE
#define EIF_POINTER_DISPLAY "lX"

/* For INTEGER and NATURAL manifest constants */
#define GE_int8(x) x
#define GE_nat8(x) x
#define GE_int16(x) x
#define GE_nat16(x) x
#define GE_int32(x) x##L
#define GE_nat32(x) x##U
#if defined (_MSC_VER) && (_MSC_VER < 1400) /* MSC older than v8 */
#define GE_int64(x) x##i64
#define GE_nat64(x) x##ui64
#elif defined(__BORLANDC__) && (__BORLANDC__ < 0x600) /* Borland before 6.0 */
#define GE_int64(x) x##i64
#define GE_nat64(x) x##ui64
#else /* ISO C 99 */
#define GE_int64(x) x##LL
#define GE_nat64(x) x##ULL
#endif
#ifdef __LCC__
/* lcc-win32 reports a constant overflow for -21474836478. */
#define GE_min_int32 (-GE_int32(2147483647)-GE_int32(1))
#else
#define GE_min_int32 GE_int32(-2147483648)
#endif
#define GE_max_int32 GE_int32(2147483647)
#if defined(__LCC__) || defined(__GNUC__) || defined(__MINGW32__)
/* lcc-win32 reports a constant overflow for -9223372036854775808. */
/* gcc and mingw-win64 warn that integer constant is so large that it is unsigned. */
#define GE_min_int64 (-GE_int64(9223372036854775807)-GE_int64(1))
#else
#define GE_min_int64 GE_int64(-9223372036854775808)
#endif
#if defined(__LCC__) && !defined(_WIN64)
/* lcc-win32 does not consider 64 bit constants as constants in case statement. */
#define GE_case_int64(x) ((int32_t)(x))
#define GE_case_nat64(x) ((uint32_t)(x))
#else
#define GE_case_int64(x) (x)
#define GE_case_nat64(x) (x)
#endif

#ifdef _WIN64
#define GE_IS_64_BITS EIF_TRUE
#else
#define GE_IS_64_BITS EIF_TEST(sizeof(void*)==8)
#endif

/*
 * Workaround for crashes (illegal instruction signal) when calling 
 * `memset` in Azure Devops pipelines under Windows.
 */
#if defined(GE_WINDOWS) && defined(__clang__)
extern void* GE_memset(void* str, int c, size_t n);
#define memset(x, y, z) GE_memset((x), (y), (z))
#else
#define GE_memset(x, y, z) memset((x), (y), (z))
#endif

/* Posix threads */
#if !defined(EIF_WINDOWS)
#define GE_USE_POSIX_THREADS
#endif

/*
 * Gobo compiler version.
 * Starts with 6080 (looks like GOBO) followed by 5 digits.
 */
#define GE_compiler_version() 608000001

/*
	Interoperability with ISE.
*/
#define RTI64C(x) GE_int64(x)
#define RTU64C(x) GE_nat64(x)
#ifdef GE_USE_BOEHM_GC
#define EIF_OBJECT EIF_REFERENCE*
#else
#define EIF_OBJECT void*
#endif
#define EIF_OBJ EIF_OBJECT
#define OVERHEAD sizeof(EIF_ANY)
/* Function pointer call to make sure all arguments are correctly pushed onto stack. */
/* FUNCTION_CAST is for standard C calls. */
/* FUNCTION_CAST_TYPE is for non-standard C calls. */
#define FUNCTION_CAST(r_type,arg_types) (r_type (*) arg_types)
#define FUNCTION_CAST_TYPE(r_type,call_type,arg_types) (r_type (call_type *) arg_types)
#define SIGBLOCK
#define SIGRESUME
#define rt_public				/* default C scope */
#define rt_private static		/* static outside a block means private */
#define rt_shared				/* data shared between modules, but not public */
typedef intptr_t rt_int_ptr;
typedef uintptr_t rt_uint_ptr;
#define RTMS(s) GE_str8(s)
#define RTMS_EX(s,c) GE_ms8((s),(c))

#ifdef __cplusplus
}
#endif

#endif

/*
	description:

		"C functions used to implement once features"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2017-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_ONCE_H
#define GE_ONCE_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Struct to keep track of the call status
 * and results of once features.
 */
typedef volatile struct {
	EIF_BOOLEAN* volatile boolean_value;
	EIF_REFERENCE* volatile boolean_exception;
	unsigned char* volatile boolean_status;
	uint32_t volatile boolean_count;
	EIF_CHARACTER_8* volatile character_8_value;
	EIF_REFERENCE* volatile character_8_exception;
	unsigned char* volatile character_8_status;
	uint32_t volatile character_8_count;
	EIF_CHARACTER_32* volatile character_32_value;
	EIF_REFERENCE* volatile character_32_exception;
	unsigned char* volatile character_32_status;
	uint32_t volatile character_32_count;
	EIF_INTEGER_8* volatile integer_8_value;
	EIF_REFERENCE* volatile integer_8_exception;
	unsigned char* volatile integer_8_status;
	uint32_t volatile integer_8_count;
	EIF_INTEGER_16* volatile integer_16_value;
	EIF_REFERENCE* volatile integer_16_exception;
	unsigned char* volatile integer_16_status;
	uint32_t volatile integer_16_count;
	EIF_INTEGER_32* volatile integer_32_value;
	EIF_REFERENCE* volatile integer_32_exception;
	unsigned char* volatile integer_32_status;
	uint32_t volatile integer_32_count;
	EIF_INTEGER_64* volatile integer_64_value;
	EIF_REFERENCE* volatile integer_64_exception;
	unsigned char* volatile integer_64_status;
	uint32_t volatile integer_64_count;
	EIF_NATURAL_8* volatile natural_8_value;
	EIF_REFERENCE* volatile natural_8_exception;
	unsigned char* volatile natural_8_status;
	uint32_t volatile natural_8_count;
	EIF_NATURAL_16* volatile natural_16_value;
	EIF_REFERENCE* volatile natural_16_exception;
	unsigned char* volatile natural_16_status;
	uint32_t volatile natural_16_count;
	EIF_NATURAL_32* volatile natural_32_value;
	EIF_REFERENCE* volatile natural_32_exception;
	unsigned char* volatile natural_32_status;
	uint32_t volatile natural_32_count;
	EIF_NATURAL_64* volatile natural_64_value;
	EIF_REFERENCE* volatile natural_64_exception;
	unsigned char* volatile natural_64_status;
	uint32_t volatile natural_64_count;
	EIF_POINTER* volatile pointer_value;
	EIF_REFERENCE* volatile pointer_exception;
	unsigned char* volatile pointer_status;
	uint32_t volatile pointer_count;
	EIF_REAL_32* volatile real_32_value;
	EIF_REFERENCE* volatile real_32_exception;
	unsigned char* volatile real_32_status;
	uint32_t volatile real_32_count;
	EIF_REAL_64* volatile real_64_value;
	EIF_REFERENCE* volatile real_64_exception;
	unsigned char* volatile real_64_status;
	uint32_t volatile real_64_count;
	EIF_REFERENCE* volatile reference_value;
	EIF_REFERENCE* volatile reference_exception;
	unsigned char* volatile reference_status;
	uint32_t volatile reference_count;
	EIF_REFERENCE* volatile procedure_exception;
	unsigned char* volatile procedure_status;
	uint32_t volatile procedure_count;
} GE_onces;

/*
 * Variable to keep track of the call status
 * and results of once-per-process features.
 */
extern GE_onces* GE_process_onces;

/*
 * Initialize `GE_process_onces'.
 */
extern void GE_init_onces(
	uint32_t a_boolean_count,
	uint32_t a_character_8_count,
	uint32_t a_character_32_count,
	uint32_t a_integer_8_count,
	uint32_t a_integer_16_count,
	uint32_t a_integer_32_count,
	uint32_t a_integer_64_count,
	uint32_t a_natural_8_count,
	uint32_t a_natural_16_count,
	uint32_t a_natural_32_count,
	uint32_t a_natural_64_count,
	uint32_t a_pointer_count,
	uint32_t a_real_32_count,
	uint32_t a_real_64_count,
	uint32_t a_reference_count,
	uint32_t a_procedure_count);

/*
 * Create a new 'GE_onces' struct which can deal with the
 * numbers of once features passed as argument.
 */
extern GE_onces* GE_new_onces(
	uint32_t a_boolean_count,
	uint32_t a_character_8_count,
	uint32_t a_character_32_count,
	uint32_t a_integer_8_count,
	uint32_t a_integer_16_count,
	uint32_t a_integer_32_count,
	uint32_t a_integer_64_count,
	uint32_t a_natural_8_count,
	uint32_t a_natural_16_count,
	uint32_t a_natural_32_count,
	uint32_t a_natural_64_count,
	uint32_t a_pointer_count,
	uint32_t a_real_32_count,
	uint32_t a_real_64_count,
	uint32_t a_reference_count,
	uint32_t a_procedure_count);

/*
 * Free memory allocated by `a_onces'.
 */
extern void GE_free_onces(GE_onces* a_onces);

#ifdef __cplusplus
}
#endif

#endif

/*
	description:

		"C functions used to implement class EXCEPTION"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2007-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_EXCEPTION_H
#define GE_EXCEPTION_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif
#ifndef GE_ONCE_H
#include "ge_once.h"
#endif
#ifdef GE_USE_THREADS
#ifndef GE_THREAD_TYPES_H
#include "ge_thread_types.h"
#endif
#endif

#include <setjmp.h>

/*
 * On Linux glibc systems, we need to use sig* versions of jmp_buf,
 * setjmp and longjmp to preserve the signal handling context.
 * One way to detect this is if _SIGSET_H_types has
 * been defined in /usr/include/setjmp.h.
 * NOTE: ANSI only recognizes the non-sig versions.
 */
#if (defined(_SIGSET_H_types) && !defined(__STRICT_ANSI__))
#define GE_jmp_buf sigjmp_buf
#define GE_setjmp(x) sigsetjmp(*(GE_jmp_buf*)&(x),1)
#define GE_longjmp(x,y) siglongjmp(*(GE_jmp_buf*)&(x),(y))
#else
#define GE_jmp_buf jmp_buf
#define GE_setjmp(x) setjmp(*(GE_jmp_buf*)&(x))
#define GE_longjmp(x,y) longjmp(*(GE_jmp_buf*)&(x),(y))
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Predefined exception codes.
 */
#define GE_EX_VOID		1			/* Feature applied to void reference */
#define GE_EX_MEM		2			/* No more memory */
#define GE_EX_PRE		3			/* Pre-condition violated */
#define GE_EX_POST		4			/* Post-condition violated */
#define GE_EX_FLOAT		5			/* Floating point exception (signal SIGFPE) */
#define GE_EX_CINV		6			/* Class invariant violated */
#define GE_EX_CHECK		7			/* Check instruction violated */
#define GE_EX_FAIL		8			/* Routine failure */
#define GE_EX_WHEN		9			/* Unmatched inspect value */
#define GE_EX_VAR		10			/* Non-decreasing loop variant */
#define GE_EX_LINV		11			/* Loop invariant violated */
#define GE_EX_SIG		12			/* Operating system signal */
#define GE_EX_BYE		13			/* Eiffel run-time panic */
#define GE_EX_RESC		14			/* Exception in rescue clause */
#define GE_EX_OMEM		15			/* Out of memory (cannot be ignored) */
#define GE_EX_RES		16			/* Resumption failed (retry did not succeed) */
#define GE_EX_CDEF		17			/* Create on deferred */
#define GE_EX_EXT		18			/* External event */
#define GE_EX_VEXP		19			/* Void assigned to expanded */
#define GE_EX_HDLR		20			/* Exception in signal handler */
#define GE_EX_IO		21			/* I/O error */
#define GE_EX_SYS		22			/* Operating system error */
#define GE_EX_RETR		23			/* Retrieval error */
#define GE_EX_PROG		24			/* Developer exception */
#define GE_EX_FATAL		25			/* Eiffel run-time fatal error */
#define GE_EX_DOL		26			/* $ applied to melted feature */
#define GE_EX_ISE_IO	27			/* I/O error raised by the ISE Eiffel runtime */
#define GE_EX_COM		28			/* COM error raised by EiffelCOM runtime */
#define GE_EX_RT_CHECK	29			/* Runtime check error such as out-of-bound array access */
#define GE_EX_OLD		30			/* Old violation */
#define GE_EX_SEL		31			/* Serialization failure */
#define GE_EX_DIRTY		32			/* SCOOP processor dirty exception. */
#define GE_EX_NEX		32			/* Number of internal exceptions */

/*
 * String buffer used to build the exception trace.
 */
typedef volatile struct {
	char* volatile area;
	uint32_t volatile count;
	uint32_t volatile capacity;
} GE_exception_trace_buffer;

/*
 * Information about the feature being executed.
 */
typedef volatile struct GE_call_struct GE_call;
struct GE_call_struct {
#ifdef GE_USE_CURRENT_IN_EXCEPTION_TRACE
	void* volatile object; /* Current object */
#endif
	const char* volatile class_name;
	const char* volatile feature_name;
	GE_call* volatile caller; /* previous feature in the call chain */
};

/*
 * Context of features containing a rescue clause.
 */
typedef volatile struct GE_rescue_struct GE_rescue;
struct GE_rescue_struct {
	GE_jmp_buf jb;
	GE_rescue* volatile previous; /* previous context in the call chain */
};

/*
 * Information about the execution context.
 * One such struct per thread.
 */
typedef volatile struct GE_context_struct GE_context;
struct GE_context_struct {
	GE_call* volatile call; /* Call stack */
	uint32_t volatile in_assertion; /* Is an assertion evaluated? */
	GE_rescue* volatile last_rescue; /* Context of last feature entered containing a rescue clause */
	uint32_t volatile in_rescue; /* Number of rescue clauses currently being executed */
	uint32_t volatile in_qualified_call; /* Is the current call a qualified call? 1 means that it is a regular call, 2 means that it is a creation call. */
	EIF_REFERENCE volatile exception_manager; /* Exception manager */
	char volatile raising_exception; /* Is an exception currently being raised? */
	char volatile exception_trace_enabled; /* Should exception trace be displayed? */
	long volatile exception_code; /* Code of the exception currently being raised, 0 otherwise */
	const char* volatile exception_tag; /* Tag of the exception currently being raised, NULL otherwise */
	GE_exception_trace_buffer exception_trace_buffer; /* String buffer used to build the exception trace */
	GE_exception_trace_buffer last_exception_trace; /* Last non-routine-failure exception trace */
	int volatile signal_number; /* Number of last signal received */
	int volatile pre_ecma_mapping_status; /* Do we map old names to new name? (i.e. STRING to STRING_8, INTEGER to INTEGER_32, ...). */
	char volatile storable_discard_pointer_values; /* Should POINTER values be set to NUll when retrieving Storables? */
#ifdef GE_USE_THREADS
	GE_thread_context* volatile thread; /* Thread context */
	GE_onces* volatile process_onces; /* Cache for status and results of onces-per-process */
	GE_onces* volatile thread_onces; /* Status and results of onces-per-thread */
#endif
#ifdef GE_USE_SCOOP
	GE_scoop_region* volatile region; /* SCOOP region whose processor is executing the current code */
	char volatile is_region_alive;
#endif
};
#define TC GE_context

/*
 * New execution context.
 */
extern GE_context* GE_new_context(int is_scoop_processor);

/*
 * Execution context of main thread.
 */
extern GE_context* GE_main_context;

/*
 * Execution context of current thread.
 */
extern GE_context* GE_current_context(void);

/*
 * Initialization of exception handling.
 */
extern void GE_init_exception(GE_context* context);

/*
 * Free memory allocated in `a_context' for exception handling.
 */
extern void GE_free_exception(GE_context* a_context);

/*
 * Pointer to function to create a new exception manager object
 * (of type ISE_EXCEPTION_MANAGER).
 */
extern EIF_REFERENCE (*GE_new_exception_manager)(GE_context*, EIF_BOOLEAN);

/*
 * Pointer to Eiffel routine ISE_EXCEPTION_MANAGER.init_exception_manager.
 */
extern void (*GE_init_exception_manager)(GE_context*);

/*
 * Pointer to Eiffel routine ISE_EXCEPTION_MANAGER.last_exception.
 */
extern EIF_REFERENCE (*GE_last_exception)(GE_context*);

/*
 * Pointer to Eiffel routine ISE_EXCEPTION_MANAGER.once_raise.
 */
extern void (*GE_once_raise)(GE_context*, EIF_REFERENCE);

/*
 * Pointer to Eiffel routine ISE_EXCEPTION_MANAGER.set_exception_data.
 */
extern void (*GE_set_exception_data)(GE_context*, EIF_INTEGER_32, EIF_BOOLEAN, EIF_INTEGER_32, EIF_INTEGER_32, EIF_REFERENCE, EIF_REFERENCE, EIF_REFERENCE, EIF_REFERENCE, EIF_REFERENCE, EIF_REFERENCE, EIF_INTEGER_32, EIF_BOOLEAN);

/*
 * Exception tag associated with `a_code'.
 */
extern char* GE_exception_tag(long a_code);

/*
 * Append `a_string' to `a_trace'.
 * Resize area if needed.
 */
extern void GE_append_to_exception_trace_buffer(GE_exception_trace_buffer* a_trace, char* a_string);

/*
 * Wipe out `a_trace'.
 */
extern void GE_wipe_out_exception_trace_buffer(GE_exception_trace_buffer* a_trace);

/*
 * Raise an exception with code `a_code'.
 */
extern void GE_raise(long a_code);

/*
 * Raise an exception with code `a_code' and message `msg'.
 */
extern void GE_raise_with_message(long a_code, const char* msg);

/*
 * Raise an exception from EXCEPTION_MANAGER.
 */
extern void GE_developer_raise(long a_code, EIF_POINTER a_meaning, EIF_POINTER a_message);

/*
 * Raise exception which was raised the first time a once routine
 * was executed when executing it again.
 */
extern void GE_raise_once_exception(GE_context* a_context, EIF_REFERENCE a_exception);

/*
 * Raise exception which was raised when an old expression was evaluated.
 */
extern int GE_raise_old_exception(GE_context* a_context, EIF_REFERENCE a_exception);

/*
 * Exception, if any, which was last raised in `a_context'.
 */
extern EIF_REFERENCE GE_last_exception_raised(GE_context* a_context);

/*
 * Jump to execute the rescue of the last routine with a rescue
 * in the call stack.
 */
extern void GE_jump_to_last_rescue(GE_context* a_context);

/*
 * Set `in_assertion' to 'not b'.
 * Return the opposite of previous value.
 */
extern EIF_BOOLEAN GE_check_assert(EIF_BOOLEAN b);

/*
 * Check whether the type id of `obj' is not in `type_ids'.
 * If it is, then raise a CAT-call exception. Don't do anything if `obj' is Void.
 * `nb' is the number of ids in `type_ids' and is expected to be >0.
 * `type_ids' is sorted in increasing order.
 * Return `obj'.
 */
#define GE_catcall(obj,type_ids,nb) GE_check_catcall((obj),(type_ids),(nb))
extern EIF_REFERENCE GE_check_catcall(EIF_REFERENCE obj, EIF_TYPE_INDEX type_ids[], int nb);

/*
 * Check whether `obj' is Void.
 * If it is, then raise a call-on-void-target exception.
 * If `i' is provided, then include it in the message displayed
 * in the console to make debugging easier when `obj' is Void.
 * Return `obj'.
 */
#define GE_void(obj) ((obj)?(obj):GE_check_void(obj))
extern EIF_REFERENCE GE_check_void(EIF_REFERENCE obj);
#ifdef GE_DEBUG
#define GE_void2(obj,i) ((obj)?(obj):GE_check_void2((obj),(i)))
extern EIF_REFERENCE GE_check_void2(EIF_REFERENCE obj, EIF_INTEGER i);
#else
#define GE_void2(obj,i) ((obj)?(obj):GE_check_void(obj))
#endif

/*
 * Check whether `ptr' is a null pointer.
 * If it is, then raise a no-more-memory exception.
 * Return `ptr'.
 */
#define GE_null(ptr) GE_check_null(ptr)
extern void* GE_check_null(void* ptr);

/* Make a qualified call to `call'. */
#define GE_qualified(ac, call) (((ac)->in_qualified_call = 1), (call))
/* Make an unqualified call to `call'. */
#define GE_unqualified(ac, call) (((ac)->in_qualified_call = 0), (call))
/* Make a creation call to `call'. */
#define GE_creation(ac, call) (((ac)->in_qualified_call = 2), (call))

#ifdef EIF_WINDOWS
/*
 * Set default exception handler.
 */
extern void GE_set_windows_exception_filter(void);
#endif

#ifdef __cplusplus
}
#endif

#endif

/*
	description:

		"C functions used to manipulate native strings"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2013-2018, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_NATIVE_STRING_H
#define GE_NATIVE_STRING_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif

#include <string.h>
#ifdef EIF_WINDOWS
#ifdef __LCC__
/* With lcc-win32, stat.h should be included before wchar.h. */
#include <sys/stat.h>
#endif
#include <wchar.h>
#else
#include <sys/types.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef EIF_WINDOWS

/* Macro used to manipulate native strings, i.e: (wchar_t*) */
#define GE_nstrlen wcslen /* size of string */
#define GE_nstrncpy wcsncpy /* Copy n characters of one string to another */
#define GE_nstrcpy wcscpy /* Copy one string to another */
#define GE_nstrncat wcsncat /* Append characters of a string */
#define GE_nstrcat wcscat /* Append a string */
#define GE_nstrstr wcsstr /* Return a pointer to the first occurrence of a search string in a string. */
#define GE_nmakestr(quote) L##quote /* Manifest Native string declaration */
#define GE_nstr_fopen _wfopen /* Open file using native string name */
#define GE_nstrcmp wcscmp /* Compare two strings. */
#define GE_nstrdup _wcsdup /* Duplicate string. */
#define GE_nstr_cat_ascii(dest, src) {							\
		int i;													\
		size_t dest_len, src_len;								\
		dest_len = rt_nstrlen (dest);							\
		src_len = strlen (src);									\
		for (i = 0; i < src_len; i++) {							\
			dest[dest_len + i] = (EIF_NATIVE_CHAR)src[i];		\
		}														\
		dest[dest_len + src_len] = (EIF_NATIVE_CHAR)0;			\
	}

#else /* not EIF_WINDOWS */

/* Macro used to manipulate native strings, i.e: (char*) */
#define GE_nstrlen strlen /* size of string */
#define GE_nstrncpy strncpy /* Copy n characters of one string to another */
#define GE_nstrcpy strcpy /* Copy one string to another */
#define GE_nstrncat strncat /* Append characters of a string */
#define GE_nstrcat strcat /* Append a string */
#define GE_nstrstr strstr /* Return a pointer to the first occurrence of a search string in a string. */
#define GE_nmakestr(quote) quote /* Manifest Native string declaration */
#define GE_nstr_fopen fopen /* Open file using native string name */
#define GE_nstrcmp strcmp /* Compare two strings. */
#define GE_nstrdup strdup /* Duplicate string. */
#define GE_nstr_cat_ascii strcat

#endif


#ifdef __cplusplus
}
#endif

#endif

/*
	description:

		"C functions used to implement class ARGUMENTS"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2007-2017, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_ARGUMENTS_H
#define GE_ARGUMENTS_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern int GE_argc;
extern EIF_NATIVE_CHAR** GE_argv;

#ifdef __cplusplus
}
#endif

#endif

/*
	description:

		"C functions used to implement type information"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2016-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_TYPES_H
#define GE_TYPES_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif
#ifndef GE_EXCEPTION_H
#include "ge_exception.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Type annotations.
 * When a type has no annotation, it means a detachable, non-separate, variant type.
 * In all other cases, there will be an annotation.
 */
#define ANNOTATION_MASK			0x007F	/* All possible annotations. */
#define ATTACHED_FLAG			0x0001
#define DETACHABLE_FLAG			0x0002	/* Only present when overriding an attached type. */
#define SEPARATE_FLAG			0x0004
#define VARIANT_FLAG			0x0008	/* Only present when overriding a frozen/poly type. */
#define UNUSABLE_FLAG			0x0010	/* Reserved for backward compatibility for storables. */
#define FROZEN_FLAG				0x0020
#define POLY_FLAG				0x0040

/*
 * Type flags.
 */
#define GE_TYPE_FLAG_SPECIAL		0x0010
#define GE_TYPE_FLAG_TUPLE			0x0020
#define GE_TYPE_FLAG_EXPANDED		0x0040
#define GE_TYPE_FLAG_DEFERRED		0x0080
#define GE_TYPE_FLAG_NONE			0x0100
#define GE_TYPE_FLAG_FORMAL			0x0200
#define GE_TYPE_FLAG_BASIC_MASK		0x000F /* One of "BOOLEAN", "CHARACTER_8", "CHARACTER_32", "INTEGER_8", "INTEGER_16", "INTEGER_32", "INTEGER_64", "NATURAL_8", "NATURAL_16", "NATURAL_32", "NATURAL_64", "POINTER", "REAL_32", "REAL_64" */
#define GE_TYPE_FLAG_BOOLEAN		0x0001
#define GE_TYPE_FLAG_CHARACTER_8	0x0002
#define GE_TYPE_FLAG_CHARACTER_32	0x0003
#define GE_TYPE_FLAG_INTEGER_8		0x0004
#define GE_TYPE_FLAG_INTEGER_16		0x0005
#define GE_TYPE_FLAG_INTEGER_32		0x0006
#define GE_TYPE_FLAG_INTEGER_64		0x0007
#define GE_TYPE_FLAG_NATURAL_8		0x0008
#define GE_TYPE_FLAG_NATURAL_16		0x0009
#define GE_TYPE_FLAG_NATURAL_32		0x000A
#define GE_TYPE_FLAG_NATURAL_64		0x000B
#define GE_TYPE_FLAG_POINTER		0x000C
#define GE_TYPE_FLAG_REAL_32		0x000D
#define GE_TYPE_FLAG_REAL_64		0x000E

/*
 * Convention for attribute types.
 * The values are in sync with REFLECTOR_CONSTANTS.
 */
#define GE_TYPE_KIND_INVALID		-1
#define GE_TYPE_KIND_POINTER		0
#define GE_TYPE_KIND_REFERENCE		1
#define GE_TYPE_KIND_CHARACTER_8	2
#define GE_TYPE_KIND_BOOLEAN		3
#define GE_TYPE_KIND_INTEGER_32		4
#define GE_TYPE_KIND_REAL_32		5
#define GE_TYPE_KIND_REAL_64		6
#define GE_TYPE_KIND_EXPANDED		7
#define GE_TYPE_KIND_INTEGER_8		9
#define GE_TYPE_KIND_INTEGER_16		10
#define GE_TYPE_KIND_INTEGER_64 	11
#define GE_TYPE_KIND_CHARACTER_32	12
#define GE_TYPE_KIND_NATURAL_8		13
#define GE_TYPE_KIND_NATURAL_16		14
#define GE_TYPE_KIND_NATURAL_32 	15
#define GE_TYPE_KIND_NATURAL_64 	16

/*
 * Object flags.
 */
#define GE_OBJECT_FLAG_MARKED		0x0001

/*
 * Ancestor relationship between two types X and Y.
 */
#ifdef GE_USE_ANCESTORS
typedef volatile struct {
	EIF_TYPE_INDEX volatile type_id; /* Type id of Y */
	EIF_BOOLEAN volatile conforms; /* Does X conform to Y? */
	void (**volatile qualified_calls)(); /* Function pointers, indexed by call id, when the static type of the target is Y and the dynamic type is X */
} GE_ancestor;
#endif

/*
 * Attribute.
 */
#ifdef GE_USE_ATTRIBUTES
typedef volatile struct {
#ifdef GE_USE_ATTRIBUTE_NAME
	const char* volatile name; /* Attribute name */
#endif
#ifdef GE_USE_ATTRIBUTE_TYPE_ID
	EIF_ENCODED_TYPE volatile type_id; /* Static type id */
#endif
#ifdef GE_USE_ATTRIBUTE_STORABLE_TYPE_ID
	EIF_ENCODED_TYPE volatile storable_type_id; /* Static type id used in Storable files */
	/* with formal generic parameters when the actual generic parameter is not a basic type */
#endif
#ifdef GE_USE_ATTRIBUTE_DYNAMIC_TYPE_SET
	EIF_TYPE_INDEX* volatile dynamic_type_set; /* Dynamic type set */
	uint32_t volatile dynamic_type_count; /* Number of types in `dynamic_type_set` */
#endif
#ifdef GE_USE_ATTRIBUTE_OFFSET
	uint32_t volatile offset; /* Address offset in object */
#endif
#ifdef GE_USE_ATTRIBUTE_SIZE
	uint32_t volatile size; /* Size of attribute in object */
#endif
} GE_attribute;
#endif

/*
 * Type information.
 */
typedef volatile struct {
	EIF_TYPE_INDEX volatile type_id;
	uint16_t volatile flags;
#ifdef GE_USE_TYPE_GENERATOR
	const char* volatile generator; /* Generator class name */
#endif
#ifdef GE_USE_TYPE_NAME
	const char* volatile name; /* Full type name */
#endif
#ifdef GE_USE_TYPE_GENERIC_PARAMETERS
	EIF_ENCODED_TYPE* volatile generic_parameters;
	uint32_t volatile generic_parameter_count;
#endif
#ifdef GE_USE_ANCESTORS
	GE_ancestor** volatile ancestors;
	uint32_t volatile ancestor_count;
#endif
#ifdef GE_USE_ATTRIBUTES
	GE_attribute** volatile attributes;
	uint32_t volatile attribute_count;
#endif
#ifdef GE_USE_TYPE_OBJECT_SIZE
	uint64_t volatile object_size;
#endif
	EIF_REFERENCE (*new_instance)();
	void (*volatile dispose)(GE_context*, EIF_REFERENCE);
} GE_type_info;

typedef volatile struct {
	EIF_TYPE_INDEX volatile id; /* Type id of the "TYPE [X]" object */
	uint16_t volatile flags; 
#ifdef GE_USE_SCOOP
	GE_scoop_region* volatile region;
#endif
	EIF_INTEGER volatile type_id; /* Type id of the type "X" */
	EIF_BOOLEAN volatile is_special;
	void (*volatile dispose)(GE_context*, EIF_REFERENCE);
	EIF_REFERENCE volatile a1; /* internal_name */
	EIF_REFERENCE volatile a2; /* internal_name_32 */
} EIF_TYPE_OBJ;

/*
 * Types indexed by type id.
 * Generated by the compiler.
 */
#ifdef GE_USE_SCOOP
extern EIF_TYPE_OBJ GE_types[][4];
#else
extern EIF_TYPE_OBJ GE_types[][2];
#endif
extern GE_type_info GE_type_infos[];

/*
 * Number of type infos in `GE_type_infos'.
 * Do not take into account the fake item at index 0.
 */
extern int GE_type_info_count;

/*
 * Encode a EIF_TYPE into a EIF_ENCODED_TYPE.
 * The lower part of EIF_ENCODED_TYPE contains the .id field,
 * and the upper part the .annotations.
 */
extern EIF_ENCODED_TYPE GE_encoded_type(EIF_TYPE a_type);

/*
 * Decode a EIF_ENCODED_TYPE into a EIF_TYPE.
 * The lower part of EIF_ENCODED_TYPE contains the .id field,
 * and the upper part the .annotations.
 */
extern EIF_TYPE GE_decoded_type(EIF_ENCODED_TYPE a_type);

/*
 * Type with `a_id' and `a_annotations'.
 */
extern EIF_TYPE GE_new_type(EIF_TYPE_INDEX a_id, EIF_TYPE_INDEX a_annotations);

/*
 * Type of object `obj'.
 */
#define GE_object_type(obj)	GE_new_type(((EIF_REFERENCE)(obj))->id, 0x0)
#define GE_object_encoded_type(obj) GE_encoded_type(GE_object_type(obj))

/*
 * Attachment status of `a_type'.
 */
#define GE_is_attached_type(a_type) EIF_TEST(((a_type).annotations & ATTACHED_FLAG) || GE_is_expanded_type_index((a_type).id))
#define GE_is_attached_encoded_type(a_type) GE_is_attached_type(GE_decoded_type(a_type))

/*
 * Associated detachable type of `a_type' if any,
 * otherwise `a_type'.
 */
extern EIF_TYPE GE_non_attached_type(EIF_TYPE a_type);
#define GE_non_attached_encoded_type(a_type) GE_encoded_type(GE_non_attached_type(GE_decoded_type(a_type)))

/*
 * Associated attached type of `a_type' if any,
 * otherwise `a_type'.
 */
extern EIF_TYPE GE_attached_type(EIF_TYPE a_type);
#define GE_attached_encoded_type(t) GE_encoded_type(GE_attached_type(GE_decoded_type(t)))

/*
 * Is `a_type' a SPECIAL type?
 */
#define GE_is_special_type_index(a_type) EIF_TEST(GE_type_infos[a_type].flags & GE_TYPE_FLAG_SPECIAL)
#define GE_is_special_encoded_type(a_type) GE_is_special_type_index(GE_decoded_type(a_type).id)
#define GE_is_special_object(obj) GE_is_special_type_index(((EIF_REFERENCE)(obj))->id)

/*
 * Is `a_type' a SPECIAL type of user-defined expanded type?
 */
extern EIF_BOOLEAN GE_is_special_of_expanded_type_index(EIF_TYPE_INDEX a_type);
#define GE_is_special_of_expanded_encoded_type(a_type) GE_is_special_of_expanded_type_index(GE_decoded_type(a_type).id)
#define GE_is_special_of_expanded_object(obj) GE_is_special_of_expanded_type_index(((EIF_REFERENCE)(obj))->id)

/*
 * Is `a_type' a SPECIAL type of reference type?
 */
extern EIF_BOOLEAN GE_is_special_of_reference_type_index(EIF_TYPE_INDEX a_type);
#define GE_is_special_of_reference_encoded_type(a_type) GE_is_special_of_reference_type_index(GE_decoded_type(a_type).id)
#define GE_is_special_of_reference_object(obj) GE_is_special_of_reference_type_index(((EIF_REFERENCE)(obj))->id)

/*
 * Is `a_type' a SPECIAL type of reference type or basic expanded type?
 * (Note that user-defined expanded types are excluded.)
 */
extern EIF_BOOLEAN GE_is_special_of_reference_or_basic_expanded_type_index(EIF_TYPE_INDEX a_type);
#define GE_is_special_of_reference_or_basic_expanded_encoded_type(a_type) GE_is_special_of_reference_or_basic_expanded_type_index(GE_decoded_type(a_type).id)
#define GE_is_special_of_reference_or_basic_expanded_object(obj) GE_is_special_of_reference_or_basic_expanded_type_index(((EIF_REFERENCE)(obj))->id)

/*
 * Is `a_type' a TUPLE type?
 */
#define GE_is_tuple_type_index(a_type) EIF_TEST(GE_type_infos[a_type].flags & GE_TYPE_FLAG_TUPLE)
#define GE_is_tuple_encoded_type(a_type) GE_is_tuple_type_index(GE_decoded_type(a_type).id)
#define GE_is_tuple_object(obj) GE_is_tuple_type_index(((EIF_REFERENCE)(obj))->id)

/*
 * Is `a_type' an expanded type?
 */
#define GE_is_expanded_type_index(a_type) EIF_TEST(GE_type_infos[a_type].flags & GE_TYPE_FLAG_EXPANDED)
#define GE_is_expanded_encoded_type(a_type) GE_is_expanded_type_index(GE_decoded_type(a_type).id)
#define GE_is_expanded_object(obj) GE_is_expanded_type_index(((EIF_REFERENCE)(obj))->id)

/*
 * Is `a_type' a type whose base class is deferred?
 */
#define GE_is_deferred_type_index(a_type) EIF_TEST(GE_type_infos[a_type].flags & GE_TYPE_FLAG_DEFERRED)
#define GE_is_deferred_encoded_type(a_type) GE_is_deferred_type_index(GE_decoded_type(a_type).id)

/*
 * Does `i'-th field of `a_object + a_physical_offset' (which is expected to be reference)
 * denote a reference with copy semantics?
 */
extern EIF_BOOLEAN GE_is_copy_semantics_field(EIF_INTEGER i, EIF_POINTER a_object, EIF_INTEGER a_physical_offset);

/*
 * Does `i'-th item of special `a_object' (which is expected to be reference)
 * denote a reference with copy semantics?
 */
extern EIF_BOOLEAN GE_is_special_copy_semantics_item(EIF_INTEGER i, EIF_POINTER a_object);

/*
 * Generator class name of `a_type'.
 */
extern EIF_REFERENCE GE_generator_of_type_index(EIF_TYPE_INDEX a_type);
#define GE_generator_of_encoded_type(a_type) GE_generator_of_type_index(GE_decoded_type(a_type).id)
extern EIF_REFERENCE GE_generator_8_of_type_index(EIF_TYPE_INDEX a_type);
#define GE_generator_8_of_encoded_type(a_type) GE_generator_8_of_type_index(GE_decoded_type(a_type).id)

/*
 * Full name of `a_type'.
 */
extern EIF_REFERENCE GE_generating_type_of_encoded_type(EIF_ENCODED_TYPE a_type);
extern EIF_REFERENCE GE_generating_type_8_of_encoded_type(EIF_ENCODED_TYPE a_type);

/*
 * Encoded type whose name is `a_name'.
 * -1 if no such type.
 */
extern EIF_ENCODED_TYPE GE_encoded_type_from_name(EIF_POINTER a_name);

/*
 * Does `a_type_1' conform to `a_type_2'?
 */
extern EIF_BOOLEAN GE_encoded_type_conforms_to(EIF_ENCODED_TYPE a_type_1, EIF_ENCODED_TYPE a_type_2);

/*
 * Number of generic parameters.
 */
extern EIF_INTEGER GE_generic_parameter_count_of_type_index(EIF_TYPE_INDEX a_type);
#define GE_generic_parameter_count_of_encoded_type(a_type) GE_generic_parameter_count_of_type_index(GE_decoded_type(a_type).id)

/*
 * Type of `i'-th generic parameter of `a_type'.
 */
extern EIF_INTEGER GE_generic_parameter_of_type_index(EIF_TYPE_INDEX a_type, EIF_INTEGER i);
#define GE_generic_parameter_of_encoded_type(a_type,i) GE_generic_parameter_of_type_index(GE_decoded_type(a_type).id, (i))

/*
 * Number of fields of an object of dynamic type `a_type'.
 */
extern EIF_INTEGER GE_field_count_of_type_index(EIF_TYPE_INDEX a_type);
#define GE_field_count_of_encoded_type(a_type) GE_field_count_of_type_index(GE_decoded_type(a_type).id)

/*
 * Physical offset of the `i'-th field for an object of dynamic type `a_type'.
 */
extern EIF_INTEGER GE_field_offset_of_type_index(EIF_INTEGER i, EIF_TYPE_INDEX a_type);
#define GE_field_offset_of_encoded_type(i, a_type) GE_field_offset_of_type_index((i), GE_decoded_type(a_type).id)

/*
 * Name of the `i'-th field for an object of dynamic type `a_type'.
 */
extern EIF_POINTER GE_field_name_of_type_index(EIF_INTEGER i, EIF_TYPE_INDEX a_type);
#define GE_field_name_of_encoded_type(i, a_type) GE_field_name_of_type_index((i), GE_decoded_type(a_type).id)

/*
 * Static type of the `i'-th field for an object of dynamic type `a_type'.
 */
extern EIF_INTEGER GE_field_static_type_of_type_index(EIF_INTEGER i, EIF_TYPE_INDEX a_type);
#define GE_field_static_type_of_encoded_type(i, a_type) GE_field_static_type_of_type_index((i), GE_decoded_type(a_type).id)

/*
 * Kind of type of the `i'-th field for an object of dynamic type `a_type'.
 */
extern EIF_INTEGER GE_field_type_kind_of_type_index(EIF_INTEGER i, EIF_TYPE_INDEX a_type);
#define GE_field_type_kind_of_encoded_type(i, a_type) GE_field_type_kind_of_type_index((i), GE_decoded_type(a_type).id)

/*
 * Physical size of `a_object'.
 */
extern EIF_NATURAL_64 GE_object_size(EIF_POINTER a_object);

/*
 * Is `i'-th field of objects of type `a_type' a user-defined expanded attribute?
 */
extern EIF_BOOLEAN GE_is_field_expanded_of_type_index(EIF_INTEGER i, EIF_TYPE_INDEX a_type);
#define GE_is_field_expanded_of_encoded_type(i, a_type) GE_is_field_expanded_of_type_index((i), GE_decoded_type(a_type).id)

#define GE_field_address_at(a_field_offset, a_object, a_physical_offset) ((char*)(a_object) + (a_physical_offset) + (a_field_offset))
#define GE_object_at_offset(a_enclosing, a_physical_offset) (EIF_REFERENCE)(GE_field_address_at(0, (a_enclosing), (a_physical_offset)))
#define GE_raw_object_at_offset(a_enclosing, a_physical_offset) (EIF_POINTER)(GE_field_address_at(0, (a_enclosing), (a_physical_offset)))
#define GE_object_encoded_type_at_offset(a_enclosing, a_physical_offset) GE_object_encoded_type(GE_raw_object_at_offset((a_enclosing), (a_physical_offset)))
#define GE_boolean_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_BOOLEAN*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_character_8_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_CHARACTER_8*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_character_32_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_CHARACTER_32*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_integer_8_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_INTEGER_8*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_integer_16_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_INTEGER_16*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_integer_32_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_INTEGER_32*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_integer_64_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_INTEGER_64*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_natural_8_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_NATURAL_8*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_natural_16_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_NATURAL_16*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_natural_32_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_NATURAL_32*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_natural_64_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_NATURAL_64*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_pointer_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_POINTER*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_real_32_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_REAL_32*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_real_64_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_REAL_64*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_raw_reference_field_at(a_field_offset, a_object, a_physical_offset) (EIF_POINTER)*(EIF_REFERENCE*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_reference_field_at(a_field_offset, a_object, a_physical_offset) *(EIF_REFERENCE*)(GE_field_address_at((a_field_offset), (a_object), (a_physical_offset)))
#define GE_set_boolean_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_boolean_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value
#define GE_set_character_8_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_character_8_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value
#define GE_set_character_32_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_character_32_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value
#define GE_set_integer_8_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_integer_8_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value
#define GE_set_integer_16_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_integer_16_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value
#define GE_set_integer_32_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_integer_32_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value
#define GE_set_integer_64_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_integer_64_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value
#define GE_set_natural_8_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_natural_8_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value
#define GE_set_natural_16_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_natural_16_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value
#define GE_set_natural_32_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_natural_32_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value
#define GE_set_natural_64_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_natural_64_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value
#define GE_set_pointer_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_pointer_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value
#define GE_set_real_32_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_real_32_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value
#define GE_set_real_64_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_real_64_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value
#define GE_set_reference_field_at(a_field_offset, a_object, a_physical_offset, a_value) GE_reference_field_at((a_field_offset), (a_object), (a_physical_offset)) = a_value

#if defined(GE_USE_ATTRIBUTES) && defined(GE_USE_ATTRIBUTE_OFFSET)
#define GE_field_address(i, a_object, a_physical_offset) GE_field_address_at(GE_type_infos[((EIF_REFERENCE)(a_object))->id].attributes[(i) - 1]->offset, (a_object), (a_physical_offset))
#define GE_boolean_field(i, a_object, a_physical_offset) *(EIF_BOOLEAN*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_character_8_field(i, a_object, a_physical_offset) *(EIF_CHARACTER_8*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_character_32_field(i, a_object, a_physical_offset) *(EIF_CHARACTER_32*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_integer_8_field(i, a_object, a_physical_offset) *(EIF_INTEGER_8*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_integer_16_field(i, a_object, a_physical_offset) *(EIF_INTEGER_16*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_integer_32_field(i, a_object, a_physical_offset) *(EIF_INTEGER_32*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_integer_64_field(i, a_object, a_physical_offset) *(EIF_INTEGER_64*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_natural_8_field(i, a_object, a_physical_offset) *(EIF_NATURAL_8*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_natural_16_field(i, a_object, a_physical_offset) *(EIF_NATURAL_16*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_natural_32_field(i, a_object, a_physical_offset) *(EIF_NATURAL_32*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_natural_64_field(i, a_object, a_physical_offset) *(EIF_NATURAL_64*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_pointer_field(i, a_object, a_physical_offset) *(EIF_POINTER*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_real_32_field(i, a_object, a_physical_offset) *(EIF_REAL_32*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_real_64_field(i, a_object, a_physical_offset) *(EIF_REAL_64*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_reference_field(i, a_object, a_physical_offset) *(EIF_REFERENCE*)(GE_field_address((i), (a_object), (a_physical_offset)))
#define GE_set_boolean_field(i, a_object, a_physical_offset, a_value) GE_boolean_field((i), (a_object), (a_physical_offset)) = (a_value)
#define GE_set_character_8_field(i, a_object, a_physical_offset, a_value) GE_character_8_field((i), (a_object), (a_physical_offset)) = (a_value)
#define GE_set_character_32_field(i, a_object, a_physical_offset, a_value) GE_character_32_field((i), (a_object), (a_physical_offset)) = (a_value)
#define GE_set_integer_8_field(i, a_object, a_physical_offset, a_value) GE_integer_8_field((i), (a_object), (a_physical_offset)) = (a_value)
#define GE_set_integer_16_field(i, a_object, a_physical_offset, a_value) GE_integer_16_field((i), (a_object), (a_physical_offset)) = (a_value)
#define GE_set_integer_32_field(i, a_object, a_physical_offset, a_value) GE_integer_32_field((i), (a_object), (a_physical_offset)) = (a_value)
#define GE_set_integer_64_field(i, a_object, a_physical_offset, a_value) GE_integer_64_field((i), (a_object), (a_physical_offset)) = (a_value)
#define GE_set_natural_8_field(i, a_object, a_physical_offset, a_value) GE_natural_8_field((i), (a_object), (a_physical_offset)) = (a_value)
#define GE_set_natural_16_field(i, a_object, a_physical_offset, a_value) GE_natural_16_field((i), (a_object), (a_physical_offset)) = (a_value)
#define GE_set_natural_32_field(i, a_object, a_physical_offset, a_value) GE_natural_32_field((i), (a_object), (a_physical_offset)) = (a_value)
#define GE_set_natural_64_field(i, a_object, a_physical_offset, a_value) GE_natural_64_field((i), (a_object), (a_physical_offset)) = (a_value)
#define GE_set_pointer_field(i, a_object, a_physical_offset, a_value) GE_pointer_field((i), (a_object), (a_physical_offset)) = (a_value)
#define GE_set_real_32_field(i, a_object, a_physical_offset, a_value) GE_real_32_field((i), (a_object), (a_physical_offset)) = (a_value)
#define GE_set_real_64_field(i, a_object, a_physical_offset, a_value) GE_real_64_field((i), (a_object), (a_physical_offset)) = (a_value)
#define GE_set_reference_field(i, a_object, a_physical_offset, a_value) GE_reference_field((i), (a_object), (a_physical_offset)) = (a_value)
#else
#define GE_boolean_field(i, a_object, a_physical_offset) (EIF_BOOLEAN)0
#define GE_character_8_field(i, a_object, a_physical_offset) (EIF_CHARACTER_8)0
#define GE_character_32_field(i, a_object, a_physical_offset) (EIF_CHARACTER_32)0
#define GE_integer_8_field(i, a_object, a_physical_offset) (EIF_INTEGER_8)0
#define GE_integer_16_field(i, a_object, a_physical_offset) (EIF_INTEGER_16)0
#define GE_integer_32_field(i, a_object, a_physical_offset) (EIF_INTEGER_32)0
#define GE_integer_64_field(i, a_object, a_physical_offset) (EIF_INTEGER_64)0
#define GE_natural_8_field(i, a_object, a_physical_offset) (EIF_NATURAL_8)0
#define GE_natural_16_field(i, a_object, a_physical_offset) (EIF_NATURAL_16)0
#define GE_natural_32_field(i, a_object, a_physical_offset) (EIF_NATURAL_32)0
#define GE_natural_64_field(i, a_object, a_physical_offset) (EIF_NATURAL_64)0
#define GE_pointer_field(i, a_object, a_physical_offset) (EIF_POINTER)0
#define GE_real_32_field(i, a_object, a_physical_offset) (EIF_REAL_32)0
#define GE_real_64_field(i, a_object, a_physical_offset) (EIF_REAL_64)0
#define GE_reference_field(i, a_object, a_physical_offset) (EIF_REFERENCE)0
#define GE_set_boolean_field(i, a_object, a_physical_offset, a_value)
#define GE_set_character_8_field(i, a_object, a_physical_offset, a_value)
#define GE_set_character_32_field(i, a_object, a_physical_offset, a_value)
#define GE_set_integer_8_field(i, a_object, a_physical_offset, a_value)
#define GE_set_integer_16_field(i, a_object, a_physical_offset, a_value)
#define GE_set_integer_32_field(i, a_object, a_physical_offset, a_value)
#define GE_set_integer_64_field(i, a_object, a_physical_offset, a_value)
#define GE_set_natural_8_field(i, a_object, a_physical_offset, a_value)
#define GE_set_natural_16_field(i, a_object, a_physical_offset, a_value)
#define GE_set_natural_32_field(i, a_object, a_physical_offset, a_value)
#define GE_set_natural_64_field(i, a_object, a_physical_offset, a_value)
#define GE_set_pointer_field(i, a_object, a_physical_offset, a_value)
#define GE_set_real_32_field(i, a_object, a_physical_offset, a_value)
#define GE_set_real_64_field(i, a_object, a_physical_offset, a_value)
#define GE_set_reference_field(i, a_object, a_physical_offset, a_value)
#endif

/*
 * Number of non-transient fields of an object of dynamic type `a_type'.
 * TODO: storable not implemented yet.
 */
#define GE_persistent_field_count_of_type_index(a_type) GE_field_count_of_type_index(a_type)
#define GE_persistent_field_count_of_encoded_type(a_type) GE_persistent_field_count_of_type_index(GE_decoded_type(a_type).id)

/*
 * Is `i'-th field of objects of type `a_type' a transient field?
 * TODO: storable not implemented yet.
 */
#define GE_is_field_transient_of_type_index(i, a_type) EIF_FALSE
#define GE_is_field_transient_of_encoded_type(i, a_type) GE_is_field_transient_of_type_index((i), GE_decoded_type(a_type).id)

/*
 * Storable version of objects of type `a_type'.
 * TODO: storable not implemented yet.
 */
#define GE_storable_version_of_type_index(a_type) EIF_VOID
#define GE_storable_version_of_encoded_type(a_type) GE_storable_version_of_type_index(GE_decoded_type(a_type).id)

/*
 * Get a lock on `GE_mark_object' and `GE_unmark_object' routines so that
 * 2 threads cannot `GE_mark_object' and `GE_unmark_object' at the same time.
 */
extern void GE_lock_marking(void);

/*
 * Release a lock on `GE_mark_object' and `GE_unmark_object', so that another
 * thread can use `GE_mark_object' and `GE_unmark_object'.
 */
extern void GE_unlock_marking(void);

/*
 * Is `obj' marked?
 */
extern EIF_BOOLEAN GE_is_object_marked(EIF_POINTER obj);

/*
 * Mark `obj'.
 */
extern void GE_mark_object(EIF_POINTER obj);

/*
 * Unmark `obj'.
 */
extern void GE_unmark_object(EIF_POINTER obj);

/*
 * New instance of dynamic `a_type'.
 * Note: returned object is not initialized and may
 * hence violate its invariant.
 * `a_type' cannot represent a SPECIAL type, use
 * `GE_new_special_of_reference_instance_of_type_index' instead.
 */
extern EIF_REFERENCE GE_new_instance_of_type_index(GE_context* a_context, EIF_TYPE_INDEX a_type);
#define GE_new_instance_of_encoded_type(a_context, a_type) GE_new_instance_of_type_index((a_context), GE_decoded_type(a_type).id)

/*
 * New instance of dynamic `a_type' that represents
 * a SPECIAL with can contain `a_capacity' elements of reference type.
 * To create a SPECIAL of basic type, use class SPECIAL directly.
 */
extern EIF_REFERENCE GE_new_special_of_reference_instance_of_type_index(GE_context* a_context, EIF_TYPE_INDEX a_type, EIF_INTEGER a_capacity);
#define GE_new_special_of_reference_instance_of_encoded_type(a_context, a_type, a_capacity) GE_new_special_of_reference_instance_of_type_index((a_context), GE_decoded_type(a_type).id, (a_capacity))

/*
 * New instance of tuple of type `a_type'.
 * Note: returned object is not initialized and may
 * hence violate its invariant.
 */
#define GE_new_tuple_instance_of_type_index(a_context, a_type) GE_new_instance_of_type_index((a_context), (a_type))
#define GE_new_tuple_instance_of_encoded_type(a_context, a_type) GE_new_tuple_instance_of_type_index((a_context), GE_decoded_type(a_type).id)

/*
 * New instance of TYPE for object of type `a_type'.
 */
extern EIF_REFERENCE GE_new_type_instance_of_encoded_type(GE_context* a_context, EIF_ENCODED_TYPE a_type);

/*
 * Check whether the `a_type' is in `a_dynamic_type_set'.
 * `nb' is the number of ids in `a_dynamic_type_set'.
 * `a_dynamic_type_set' is sorted in increasing order.
 * A type-id 0 means Void (aka 'detachable NONE').
 */
extern EIF_BOOLEAN GE_type_in_dynamic_type_set(EIF_TYPE_INDEX a_type, EIF_TYPE_INDEX a_dynamic_type_set[], int nb);

#ifdef GE_USE_ATTRIBUTES
/*
 * Attribute with name `a_name' (in lower-case) in type `a_type`.
 * Null if no such attribute.
 */
extern GE_attribute* GE_attribute_with_name(EIF_TYPE_INDEX a_type, char* name);
#endif


#ifdef __cplusplus
}
#endif

#endif

/*
	description:

		"C functions used to manipulate strings"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2016-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_STRING_H
#define GE_STRING_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * New Eiffel empty string of type "STRING_8" with can
 * contain `c' characters.
 * Note: The implementation of this function is generated
 * by the Eiffel compiler.
 */
extern EIF_REFERENCE GE_new_str8(EIF_INTEGER c);

/*
 * New Eiffel empty string of type "IMMUTABLE_STRING_8" with can
 * contain `c' characters.
 * Note: The implementation of this function is generated
 * by the Eiffel compiler.
 */
extern EIF_REFERENCE GE_new_istr8(EIF_INTEGER c);

/*
 * New Eiffel empty string of type "STRING_32" with can
 * contain `c' characters.
 * Note: The implementation of this function is generated
 * by the Eiffel compiler.
 */
extern EIF_REFERENCE GE_new_str32(EIF_INTEGER c);

/*
 * New Eiffel empty string of type "IMMUTABLE_STRING_32" with can
 * contain `c' characters.
 * Note: The implementation of this function is generated
 * by the Eiffel compiler.
 */
extern EIF_REFERENCE GE_new_istr32(EIF_INTEGER c);

/*
 * New Eiffel string of type "STRING_8" containing the
 * first `c' characters found in ISO 8859-1 string `s'.
 */
extern EIF_REFERENCE GE_ms8(const char* s, EIF_INTEGER c);

/*
 * New Eiffel string of type "STRING_8" containing all
 * characters found in the null-terminated ISO 8859-1 string `s'.
 */
extern EIF_REFERENCE GE_str8(const char* s);

/*
 * New Eiffel string of type "IMMUTABLE_STRING_8" containing the
 * first `c' characters found in ISO 8859-1 string `s'.
 */
extern EIF_REFERENCE GE_ims8(const char* s, EIF_INTEGER c);

/*
 * New Eiffel string of type "STRING_32" containing the
 * first `c' characters found in ISO 8859-1 string `s'.
 */
extern EIF_REFERENCE GE_ms32(const char* s, EIF_INTEGER c);

/*
 * New Eiffel string of type "STRING_32" containing the
 * first `c' 32-bit characters built from `s' by reading
 * groups of four bytes with little-endian byte order.
 */
extern EIF_REFERENCE GE_ms32_from_utf32le(const char* s, EIF_INTEGER c);

/*
 * New Eiffel string of type "STRING_32" containing all
 * characters found in the null-terminated ISO 8859-1 string `s'.
 */
extern EIF_REFERENCE GE_str32(const char* s);

/*
 * New Eiffel string of type "IMMUTABLE_STRING_32" containing
 * the first `c' characters found in ISO 8859-1 string `s'.
 */
extern EIF_REFERENCE GE_ims32(const char* s, EIF_INTEGER c);

/*
 * New Eiffel string of type "IMMUTABLE_STRING_32" containing the
 * first `c' 32-bit characters built from `s' by reading
 * groups of four bytes with little-endian byte order.
 */
extern EIF_REFERENCE GE_ms32_from_utf32le(const char* s, EIF_INTEGER c);

/*
 * New Eiffel string of type "IMMUTABLE_STRING_32" containing all
 * characters found in the null-terminated ISO 8859-1 string `s'.
 */
extern EIF_REFERENCE GE_istr32(const char* s);

/*
 * New Eiffel string of type "IMMUTABLE_STRING_32" containing the
 * first `n' native characters found in native string `s'.
 * Invalid native characters are escaped.
 */
extern EIF_REFERENCE GE_ims32_from_nstr(EIF_NATIVE_CHAR* s, EIF_INTEGER n);

/*
 * New Eiffel string of type "IMMUTABLE_STRING_32" containing all
 * characters found in the null-terminated native string `s'.
 * Invalid native characters are escaped.
 */
extern EIF_REFERENCE GE_istr32_from_nstr(EIF_NATIVE_CHAR* s);

/*
 * New Eiffel string of type "STRING" containing all
 * characters found in the null-terminated ISO 8859-1 string `s'
 */
extern EIF_REFERENCE GE_str(const char* s);

/*
 * Base address of `o' of type "SPECIAL [CHARACTER_8].
 * The base address is the addresss of the first character in `o'.
 * Note: The implementation of this function is generated
 * by the Eiffel compiler.
 */
extern EIF_POINTER GE_sp8_base_address(EIF_REFERENCE o);

/*
 * Base address of `o' of type "SPECIAL [CHARACTER_832.
 * The base address is the addresss of the first character in `o'.
 * Note: The implementation of this function is generated
 * by the Eiffel compiler.
 */
extern EIF_POINTER GE_sp32_base_address(EIF_REFERENCE o);

#ifdef __cplusplus
}
#endif

#endif

/*
	description:

		"C functions used to implement class CONSOLE"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2007-2017, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_CONSOLE_H
#define GE_CONSOLE_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Initialize mutex to determine whether a new
 * console needs to be created.
 */
#ifdef EIF_WINDOWS
extern void GE_init_console(void);
#else
#define GE_init_console()
#endif

/*
 * Create a new DOS console if needed (i.e. in case of a Windows application).
 */
#ifdef EIF_WINDOWS
extern void GE_show_console(void);
#else
#define GE_show_console()
#endif

#ifdef __cplusplus
}
#endif

#endif

/*
	description:

		"C functions used to implement the program initialization"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2007-2017, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_MAIN_H
#define GE_MAIN_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern int GE_main(int argc, EIF_NATIVE_CHAR** argv);

/*
 * System name.
 */
extern char* GE_system_name;

/*
 * Root class name.
 */
extern char* GE_root_class_name;

#ifdef EIF_WINDOWS

#include <windows.h>

/*
 * Used in WEL.
 */
extern HINSTANCE eif_hInstance;
extern HINSTANCE eif_hPrevInstance;
extern LPWSTR eif_lpCmdLine;
extern int eif_nCmdShow;

/*
 * Main entry point when compiling a Windows application.
 * See:
 *    http://en.wikipedia.org/wiki/WinMain
 *    http://msdn2.microsoft.com/en-us/library/ms633559.aspx
 */
extern int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

#endif

#ifdef __cplusplus
}
#endif

#endif

/*
	description:

		"C functions used to access garbage collector facilities"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2007-2026, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_GC_H
#define GE_GC_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EXCEPTION_H
#include "ge_exception.h"
#endif

#ifdef GE_USE_BOEHM_GC
/*
 *	Use the Boehm garbage collector.
 *	See:
 *		http://en.wikipedia.org/wiki/Boehm_GC
 *		http://www.hpl.hp.com/personal/Hans_Boehm/gc/
 */

/* 
 * In the case of multithreaded code, gc.h should be included after the threads header file, 
 * and after defining the appropriate GC_XXXX_THREADS macro. (For 6.2alpha4 and later, 
 * simply defining GC_THREADS should suffice.) The header file gc.h must be included in files 
 * that use either GC or threads primitives, since threads primitives will be redefined to 
 * cooperate with the GC on many platforms. 
 * See: https://hboehm.info/gc/gcinterface.html
*/
#ifdef GE_USE_POSIX_THREADS
#include <pthread.h>
#include <semaphore.h>
#elif defined EIF_WINDOWS
#include <windows.h>
#include <process.h>
#endif

#define GC_IGNORE_WARN
#define GC_NOT_DLL
#define GC_THREADS
#define PARALLEL_MARK
#define THREAD_LOCAL_ALLOC
#define GC_ENABLE_SUSPEND_THREAD
#define LARGE_CONFIG
#define ALL_INTERIOR_POINTERS
#define ENABLE_DISCLAIM
#define GC_ATOMIC_UNCOLLECTABLE
#define GC_GCJ_SUPPORT
#define JAVA_FINALIZATION
#define NO_EXECUTE_PERMISSION
#define USE_MMAP
#define USE_MUNMAP

#if defined(GE_WINDOWS)
#	undef GC_NO_THREAD_DECLS
#	undef GC_NO_THREAD_REDIRECTS
#	define EMPTY_GETENV_RESULTS
#	define DONT_USE_USER32_DLL
#else
#	if !defined(GE_MACOS)
#		define GC_PTHREAD_START_STANDALONE
#	endif
#	ifndef _REENTRANT
#		define _REENTRANT
#	endif
#	define HANDLE_FORK
#endif

#if defined(__clang__) || defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW64__)
#	define GC_BUILTIN_ATOMIC
#endif

#if defined(__clang__)
#	define HAVE_DL_ITERATE_PHDR
#	define GC_REQUIRE_WCSDUP
#	define HAVE_DLADDR
#	define HAVE_SYS_TYPES_H
#	define HAVE_UNISTD_H
#	if defined(GE_MACOS)
#		define HAVE_PTHREAD_SETNAME_NP_WITHOUT_TID
#	elif !defined(GE_WINDOWS)
#		if defined(GE_OPENBSD)
#			define HAVE_PTHREAD_SET_NAME_NP
#		else
#			define HAVE_PTHREAD_SETNAME_NP_WITH_TID
#		endif
#		define HAVE_PTHREAD_SIGMASK
#		define NO_GETCONTEXT
#	endif
#endif

#include "gc.h"
#else
#include <stdlib.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * GC initialization.
 */

#if !defined(GE_USE_BOEHM_GC)
#define GE_init_gc() /* do nothing */
#elif defined(GE_WINDOWS) || (defined(GE_MACOS) && !defined(__aarch64__)) || !defined(__clang__)
#define GE_init_gc() \
	GC_INIT(); \
	GC_allow_register_threads(); \
	GC_enable_incremental()
#else
/*
 * No incremental GC under Macos arm64 and Linux when compiled wtih zig/clang,
 * because otherwise the program does not behave as expected.
 */
#define GE_init_gc() \
	GC_INIT(); \
	GC_allow_register_threads()
#endif

/*
 * Memory allocation.
 */

/*
 * Allocate memory that can contain pointers to collectable objects.
 * The allocated memory is not necessarily zeroed.
 * The allocated object is itself collectable.
 * Do not raise an exception when no-more-memory.
 */
#ifdef GE_USE_BOEHM_GC
#define GE_unprotected_malloc(size) GC_MALLOC(size)
#else /* No GC */
#define GE_unprotected_malloc(size) malloc(size)
#endif

/*
 * Allocate memory that can contain pointers to collectable objects.
 * The allocated memory is not necessarily zeroed.
 * The allocated object is itself collectable.
 * Raise an exception when no-more-memory.
 */
#define GE_malloc(size) GE_null(GE_unprotected_malloc(size))

/*
 * Allocate memory that does not contain pointers to collectable objects.
 * The allocated memory is not necessarily zeroed.
 * The allocated object is itself collectable.
 * Do not raise an exception when no-more-memory.
 */
#ifdef GE_USE_BOEHM_GC
#define GE_unprotected_malloc_atomic(size) GC_MALLOC_ATOMIC(size)
#else /* No GC */
#define GE_unprotected_malloc_atomic(size) GE_unprotected_malloc(size)
#endif

/*
 * Allocate memory that does not contain pointers to collectable objects.
 * The allocated memory is not necessarily zeroed.
 * The allocated object is itself collectable.
 * Raise an exception when no-more-memory.
 */
#define GE_malloc_atomic(size) GE_null(GE_unprotected_malloc_atomic(size))

/*
 * Allocate memory that can contain pointers to collectable objects.
 * The allocated memory is zeroed.
 * The allocated object is itself collectable.
 * Do not raise an exception when no-more-memory.
 */
#ifdef GE_USE_BOEHM_GC
#define GE_unprotected_calloc(nelem, elsize) GC_MALLOC((nelem) * (elsize))
#else /* No GC */
#define GE_unprotected_calloc(nelem, elsize) calloc((nelem), (elsize))
#endif

/*
 * Allocate memory that can contain pointers to collectable objects.
 * The allocated memory is zeroed.
 * The allocated object is itself collectable.
 * Raise an exception when no-more-memory.
 */
#define GE_calloc(nelem, elsize) GE_null(GE_unprotected_calloc((nelem), (elsize)))

/*
 * Allocate memory that does not contain pointers to collectable objects.
 * The allocated memory is zeroed.
 * The allocated object is itself collectable.
 * Raise an exception when no-more-memory.
 */
#ifdef GE_USE_BOEHM_GC
#define GE_calloc_atomic(nelem, elsize) GE_memset(GE_null(GC_MALLOC_ATOMIC((nelem) * (elsize))), 0, (nelem) * (elsize))
#else /* No GC */
#define GE_calloc_atomic(nelem, elsize) GE_calloc((nelem), (elsize))
#endif

/*
 * Allocate memory that can contain pointers to collectable objects.
 * The allocated memory is not necessarily zeroed.
 * The allocated object is itself not collectable.
 * Do not raise an exception when no-more-memory.
 */
#ifdef GE_USE_BOEHM_GC
#define GE_unprotected_malloc_uncollectable(size) GC_MALLOC_UNCOLLECTABLE(size)
#else /* No GC */
#define GE_unprotected_malloc_uncollectable(size) malloc(size)
#endif

/*
 * Allocate memory that can contain pointers to collectable objects.
 * The allocated memory is not necessarily zeroed.
 * The allocated object is itself not collectable.
 * Raise an exception when no-more-memory.
 */
#define GE_malloc_uncollectable(size) GE_null(GE_unprotected_malloc_uncollectable(size))

/*
 * Allocate memory that does not contain pointers to collectable objects.
 * The allocated memory is not necessarily zeroed.
 * The allocated object is itself not collectable.
 * Do not raise an exception when no-more-memory.
 */
#ifdef GE_USE_BOEHM_GC
#define GE_unprotected_malloc_atomic_uncollectable(size) GC_malloc_atomic_uncollectable(size)
#else /* No GC */
#define GE_unprotected_malloc_atomic_uncollectable(size) malloc(size)
#endif

/*
 * Allocate memory that does not contain pointers to collectable objects.
 * The allocated memory is not necessarily zeroed.
 * The allocated object is itself not collectable.
 * Raise an exception when no-more-memory.
 */
#define GE_malloc_atomic_uncollectable(size) GE_null(GE_unprotected_malloc_atomic_uncollectable(size))
/*
 * Allocate memory that can contain pointers to collectable objects.
 * The allocated memory is zeroed.
 * The allocated object is itself not collectable.
 * Do not raise an exception when no-more-memory.
 */
#ifdef GE_USE_BOEHM_GC
#define GE_unprotected_calloc_uncollectable(nelem, elsize) GC_MALLOC_UNCOLLECTABLE((nelem) * (elsize))
#else /* No GC */
#define GE_unprotected_calloc_uncollectable(nelem, elsize) calloc((nelem), (elsize))
#endif

/*
 * Allocate memory that can contain pointers to collectable objects.
 * The allocated memory is zeroed.
 * The allocated object is itself not collectable.
 * Raise an exception when no-more-memory.
 */
#define GE_calloc_uncollectable(nelem, elsize) GE_null(GE_unprotected_calloc_uncollectable((nelem), (elsize)))


/*
 * Allocate memory that does not contain pointers to collectable objects.
 * The allocated memory is zeroed.
 * The allocated object is itself not collectable.
 * Do not raise an exception when no-more-memory.
 */
#ifdef GE_USE_BOEHM_GC
extern void* GE_unprotected_calloc_atomic_uncollectable(size_t nelem, size_t elsize);
#else /* No GC */
#define GE_unprotected_calloc_atomic_uncollectable(nelem, elsize) GE_unprotected_calloc((nelem), (elsize))
#endif

/*
 * Allocate memory that does not contain pointers to collectable objects.
 * The allocated memory is zeroed.
 * The allocated object is itself not collectable.
 * Raise an exception when no-more-memory.
 */
#define GE_calloc_atomic_uncollectable(nelem, elsize) GE_null(GE_unprotected_calloc_atomic_uncollectable((nelem), (elsize)))

/*
 * Allocate more memory for the given pointer.
 * The reallocated pointer keeps the same properties (e.g. atomic or not, collectable or not).
 * The extra allocated memory is not necessarily zeroed.
 * Do not raise an exception when no-more-memory.
 */
#ifdef GE_USE_BOEHM_GC
#define GE_unprotected_realloc(p, size) GC_REALLOC((void*)(p), (size))
#else /* No GC */
#define GE_unprotected_realloc(p, size) realloc((void*)(p), (size))
#endif

/*
 * Allocate more memory for the given pointer.
 * The reallocated pointer keeps the same properties (e.g. atomic or not, collectable or not).
 * The extra allocated memory is not necessarily zeroed.
 * Raise an exception when no-more-memory.
 */
#define GE_realloc(p, size) GE_null(GE_unprotected_realloc((p), (size)))

/*
 * Allocate more memory for the given pointer.
 * The reallocated pointer keeps the same properties (e.g. atomic or not, collectable or not).
 * The extra allocated memory is zeroed.
 * Do not raise an exception when no-more-memory.
 */
extern void* GE_unprotected_recalloc(void* p, size_t old_nelem, size_t new_nelem, size_t elsize);

/*
 * Allocate more memory for the given pointer.
 * The reallocated pointer keeps the same properties (e.g. atomic or not, collectable or not).
 * The extra allocated memory is zeroed.
 * Raise an exception when no-more-memory.
 */
#define GE_recalloc(p, old_nelem, new_nelem, elsize) GE_null(GE_unprotected_recalloc((void*)(p), (old_nelem), (new_nelem), (elsize)))

/*
 * Explicitly deallocate an object.
 */
#ifdef GE_USE_BOEHM_GC
#define GE_free(p) GC_FREE((void*)(p))
#else /* No GC */
#define GE_free(p) free((void*)(p))
#endif

#if defined(GE_WINDOWS) && defined(__clang__)
/*
 * Memory setting.
 * Workaround for crashes (illegal instruction signal) when calling 
 * `memset` in Azure Devops pipelines under Windows.
 */
extern void* GE_memset(void* str, int c, size_t n);
#endif

/*
 * Dispose
 */

/*
 * Register dispose routine `disp' to be called on object `obj' when it will be collected.
 */
#ifdef GE_USE_BOEHM_GC
extern void GE_boehm_dispose(void* C, void* disp); /* Call dispose routine on object `C'. */
#define GE_register_dispose(obj, disp) GC_REGISTER_FINALIZER_NO_ORDER((void*)(obj), (void (*) (void*, void*)) &GE_boehm_dispose, (void*)(disp), NULL, NULL)
#else /* No GC */
#define GE_register_dispose(obj, disp) /* do nothing */
#endif

/*
 * Register dispose routine `disp' to be called on once-per-object `data' when it will be collected.
 */
#ifdef GE_USE_BOEHM_GC
extern void GE_boehm_dispose_once_per_object_data(void* data, void* disp); /* Call dispose routine `disp' on once-per-object data `data'. */
#define GE_register_dispose_once_per_object_data(data, disp) GC_REGISTER_FINALIZER_NO_ORDER((void*)(data), (void (*) (void*, void*)) &GE_boehm_dispose_once_per_object_data, (void*)(disp), NULL, NULL)
#else /* No GC */
#define GE_register_dispose_once_per_object_data(data, disp) /* do nothing */
#endif

/*
 * Access to objects, useful with GCs which move objects in memory.
 * This is not the case here, since the Boehm GC is not a moving GC.
 */

/* Access object through hector. */
#ifdef GE_USE_BOEHM_GC
#define eif_access(obj) (*(EIF_REFERENCE*)(obj))
#else
#define eif_access(obj) (EIF_REFERENCE)(obj)
#endif

/* Freeze memory address. */
#define eif_freeze(obj) eif_access(obj)

/* The C side protects an object. */
extern EIF_OBJECT eif_protect(EIF_REFERENCE object);

/* The C side adopts an object. */
#define eif_adopt(obj) eif_protect(eif_access(obj))

/* The C side weans adopted object. */
extern EIF_REFERENCE eif_wean(EIF_OBJECT object);

/* Forget a frozen memory address. */
#define eif_unfreeze(obj)

/* Always frozen since they do not move. */
#define eif_frozen(obj) 1

/* Always frozen since they do not move. */
#define spfrozen(obj) 1

#ifdef __cplusplus
}
#endif

#endif

/*
	description:

		"C functions used to handle signals"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_SIGNAL_H
#define GE_SIGNAL_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Set signal handlers.
 * To be called at the beginning of the main thread.
 */
extern void GE_init_signal(void);

/* Initialize `GE_ignored_signals_mutex'. */
extern void GE_init_ignored_signals_mutex(void);

/* Description of sinal `a_sig'. */
extern char *GE_signal_name(EIF_INTEGER a_sig);

/* Is signal `a_sig' defined? */
extern char GE_is_signal_defined(EIF_INTEGER a_sig);

/* C signal code for signal of index `idx'. */
extern EIF_INTEGER GE_signal_map(EIF_INTEGER idx);

/*
 * Catch signal `a_sig'.
 * Check that the signal is defined.
 */
extern void GE_catch_signal(EIF_INTEGER a_sig);

/* 
 * Ignore signal `a_sig'.
 * Check that the signal is defined.
 */
extern void GE_ignore_signal(EIF_INTEGER a_sig);

/*
 * Is signal of number `a_sig' caught?
 * Check that the signal is defined.
 */
extern char GE_is_signal_caught(EIF_INTEGER a_sig);

/* Reset all the signals to their default handling. */
extern void GE_reset_all_signals(void);

/* Reset signal `a_sig' to its default handling. */
extern void GE_reset_signal_to_default(EIF_INTEGER a_sig);

/* Number of last signal. */
extern EIF_INTEGER GE_signal_number();

#ifdef __cplusplus
}
#endif

#endif

/*
	description:

		"C functions used to implement class IDENTIFIED"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2007-2017, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_IDENTIFIED_H
#define GE_IDENTIFIED_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Initialize data to keep track of object ids.
 */
extern void GE_init_identified(void);

/*
 * Get a new id for `object', assuming it is NOT in the stack.
 */
extern EIF_INTEGER_32 GE_object_id(EIF_REFERENCE object);

/*
 * Return the object associated with `id'.
 */
extern EIF_REFERENCE GE_id_object(EIF_INTEGER_32 id);

/*
 * Remove the object associated with `id' from the stack.
 */
extern void GE_object_id_free(EIF_INTEGER_32 id);

#ifdef __cplusplus
}
#endif

#endif

#ifdef __cplusplus
extern "C" {
#endif

#define T0 EIF_ANY

/* CHARACTER */
#define EIF_CHARACTER EIF_CHARACTER_8

/* WIDE_CHARACTER */
#define EIF_WIDE_CHAR EIF_CHARACTER_32

/* INTEGER */
#define EIF_INTEGER EIF_INTEGER_32

/* NATURAL */
#define EIF_NATURAL EIF_NATURAL_32

/* REAL */
#define EIF_REAL EIF_REAL_32

/* DOUBLE */
#define EIF_DOUBLE EIF_REAL_64

/* BOOLEAN */
#define T1 EIF_BOOLEAN
extern T0* GE_boxed1(TC* ac, T1 a1);
extern T0* GE_boxed_pointer1(TC* ac, volatile T1* a1);
typedef volatile struct Sb1 Tb1;

/* CHARACTER_8 */
#define T2 EIF_CHARACTER_8
extern T0* GE_boxed2(TC* ac, T2 a1);
extern T0* GE_boxed_pointer2(TC* ac, volatile T2* a1);
typedef volatile struct Sb2 Tb2;

/* CHARACTER_32 */
#define T3 EIF_CHARACTER_32
extern T0* GE_boxed3(TC* ac, T3 a1);
extern T0* GE_boxed_pointer3(TC* ac, volatile T3* a1);
typedef volatile struct Sb3 Tb3;

/* INTEGER_8 */
#define T4 EIF_INTEGER_8
extern T0* GE_boxed4(TC* ac, T4 a1);
extern T0* GE_boxed_pointer4(TC* ac, volatile T4* a1);
typedef volatile struct Sb4 Tb4;

/* INTEGER_16 */
#define T5 EIF_INTEGER_16
extern T0* GE_boxed5(TC* ac, T5 a1);
extern T0* GE_boxed_pointer5(TC* ac, volatile T5* a1);
typedef volatile struct Sb5 Tb5;

/* INTEGER_32 */
#define T6 EIF_INTEGER_32
extern T0* GE_boxed6(TC* ac, T6 a1);
extern T0* GE_boxed_pointer6(TC* ac, volatile T6* a1);
typedef volatile struct Sb6 Tb6;

/* INTEGER_64 */
#define T7 EIF_INTEGER_64
extern T0* GE_boxed7(TC* ac, T7 a1);
extern T0* GE_boxed_pointer7(TC* ac, volatile T7* a1);
typedef volatile struct Sb7 Tb7;

/* NATURAL_8 */
#define T8 EIF_NATURAL_8
extern T0* GE_boxed8(TC* ac, T8 a1);
extern T0* GE_boxed_pointer8(TC* ac, volatile T8* a1);
typedef volatile struct Sb8 Tb8;

/* NATURAL_16 */
#define T9 EIF_NATURAL_16
extern T0* GE_boxed9(TC* ac, T9 a1);
extern T0* GE_boxed_pointer9(TC* ac, volatile T9* a1);
typedef volatile struct Sb9 Tb9;

/* NATURAL_32 */
#define T10 EIF_NATURAL_32
extern T0* GE_boxed10(TC* ac, T10 a1);
extern T0* GE_boxed_pointer10(TC* ac, volatile T10* a1);
typedef volatile struct Sb10 Tb10;

/* NATURAL_64 */
#define T11 EIF_NATURAL_64
extern T0* GE_boxed11(TC* ac, T11 a1);
extern T0* GE_boxed_pointer11(TC* ac, volatile T11* a1);
typedef volatile struct Sb11 Tb11;

/* REAL_32 */
#define T12 EIF_REAL_32
extern T0* GE_boxed12(TC* ac, T12 a1);
extern T0* GE_boxed_pointer12(TC* ac, volatile T12* a1);
typedef volatile struct Sb12 Tb12;

/* REAL_64 */
#define T13 EIF_REAL_64
extern T0* GE_boxed13(TC* ac, T13 a1);
extern T0* GE_boxed_pointer13(TC* ac, volatile T13* a1);
typedef volatile struct Sb13 Tb13;

/* POINTER */
#define T14 EIF_POINTER
extern T0* GE_boxed14(TC* ac, T14 a1);
extern T0* GE_boxed_pointer14(TC* ac, volatile T14* a1);
typedef volatile struct Sb14 Tb14;

/* SPECIAL [CHARACTER_8] */
typedef volatile struct S15 T15;

/* SPECIAL [CHARACTER_32] */
typedef volatile struct S16 T16;

/* STRING_8 */
typedef volatile struct S17 T17;

/* STRING_32 */
typedef volatile struct S18 T18;

/* ISE_EXCEPTION_MANAGER */
typedef volatile struct S21 T21;

/* APPLICATION */
typedef volatile struct S26 T26;

/* CELL [detachable EXCEPTION] */
typedef volatile struct S27 T27;

/* HASH_TABLE [INTEGER_32, INTEGER_32] */
typedef volatile struct S28 T28;

/* CELL [detachable TUPLE [INTEGER_32, INTEGER_32, INTEGER_32, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, INTEGER_32, BOOLEAN]] */
typedef volatile struct S29 T29;

/* CELL [NO_MORE_MEMORY] */
typedef volatile struct S30 T30;

/* C_STRING */
typedef volatile struct S31 T31;

/* TUPLE [INTEGER_32, INTEGER_32, INTEGER_32, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, INTEGER_32, BOOLEAN] */
typedef volatile struct S32 T32;

/* ESTUFA */
typedef volatile struct S33 T33;

/* STD_FILES */
typedef volatile struct S34 T34;

/* SENSOR_TEMPERATURA */
typedef volatile struct S35 T35;

/* SENSOR_UMIDADE */
typedef volatile struct S36 T36;

/* VOID_TARGET */
typedef volatile struct S41 T41;

/* TYPE [VOID_TARGET] */
#define T42 EIF_TYPE_OBJ

/* ROUTINE_FAILURE */
typedef volatile struct S43 T43;

/* TYPE [ROUTINE_FAILURE] */
#define T44 EIF_TYPE_OBJ

/* OLD_VIOLATION */
typedef volatile struct S45 T45;

/* TYPE [OLD_VIOLATION] */
#define T46 EIF_TYPE_OBJ

/* NO_MORE_MEMORY */
typedef volatile struct S47 T47;

/* INVARIANT_VIOLATION */
typedef volatile struct S48 T48;

/* OPERATING_SYSTEM_SIGNAL_FAILURE */
typedef volatile struct S49 T49;

/* IO_FAILURE */
typedef volatile struct S50 T50;

/* OPERATING_SYSTEM_FAILURE */
typedef volatile struct S51 T51;

/* COM_FAILURE */
typedef volatile struct S52 T52;

/* EIFFEL_RUNTIME_PANIC */
typedef volatile struct S53 T53;

/* PRECONDITION_VIOLATION */
typedef volatile struct S55 T55;

/* POSTCONDITION_VIOLATION */
typedef volatile struct S56 T56;

/* FLOATING_POINT_FAILURE */
typedef volatile struct S57 T57;

/* CHECK_VIOLATION */
typedef volatile struct S58 T58;

/* BAD_INSPECT_VALUE */
typedef volatile struct S59 T59;

/* VARIANT_VIOLATION */
typedef volatile struct S60 T60;

/* LOOP_INVARIANT_VIOLATION */
typedef volatile struct S61 T61;

/* RESCUE_FAILURE */
typedef volatile struct S62 T62;

/* RESUMPTION_FAILURE */
typedef volatile struct S63 T63;

/* CREATE_ON_DEFERRED */
typedef volatile struct S64 T64;

/* EXTERNAL_FAILURE */
typedef volatile struct S65 T65;

/* VOID_ASSIGNED_TO_EXPANDED */
typedef volatile struct S66 T66;

/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE */
typedef volatile struct S67 T67;

/* MISMATCH_FAILURE */
typedef volatile struct S68 T68;

/* DEVELOPER_EXCEPTION */
typedef volatile struct S69 T69;

/* ADDRESS_APPLIED_TO_MELTED_FEATURE */
typedef volatile struct S70 T70;

/* SERIALIZATION_FAILURE */
typedef volatile struct S71 T71;

/* PRIMES */
typedef volatile struct S72 T72;

/* SPECIAL [INTEGER_32] */
typedef volatile struct S73 T73;

/* SPECIAL [BOOLEAN] */
typedef volatile struct S74 T74;

/* IRRIGACAO */
typedef volatile struct S75 T75;

/* CONTROLADOR */
typedef volatile struct S76 T76;

/* CONSOLE */
typedef volatile struct S78 T78;

/* TYPE [detachable VOID_TARGET] */
#define T81 EIF_TYPE_OBJ

/* UTF_CONVERTER */
typedef volatile struct S83 T83;
extern T0* GE_boxed83(TC* ac, T83 a1);
extern T0* GE_boxed_pointer83(TC* ac, T83* a1);
typedef volatile struct Sb83 Tb83;

/* CELL [INTEGER_32] */
typedef volatile struct S84 T84;

/* MANAGED_POINTER */
typedef volatile struct S85 T85;

/* TYPE [detachable ROUTINE_FAILURE] */
#define T86 EIF_TYPE_OBJ

/* TYPE [detachable OLD_VIOLATION] */
#define T87 EIF_TYPE_OBJ

/* TYPE [detachable NO_MORE_MEMORY] */
#define T88 EIF_TYPE_OBJ

/* TYPE [detachable INVARIANT_VIOLATION] */
#define T89 EIF_TYPE_OBJ

/* TYPE [detachable OPERATING_SYSTEM_SIGNAL_FAILURE] */
#define T90 EIF_TYPE_OBJ

/* TYPE [detachable IO_FAILURE] */
#define T91 EIF_TYPE_OBJ

/* TYPE [detachable OPERATING_SYSTEM_FAILURE] */
#define T92 EIF_TYPE_OBJ

/* TYPE [detachable COM_FAILURE] */
#define T93 EIF_TYPE_OBJ

/* TYPE [detachable EIFFEL_RUNTIME_PANIC] */
#define T94 EIF_TYPE_OBJ

/* TYPE [detachable PRECONDITION_VIOLATION] */
#define T95 EIF_TYPE_OBJ

/* TYPE [detachable POSTCONDITION_VIOLATION] */
#define T96 EIF_TYPE_OBJ

/* TYPE [detachable FLOATING_POINT_FAILURE] */
#define T97 EIF_TYPE_OBJ

/* TYPE [detachable CHECK_VIOLATION] */
#define T98 EIF_TYPE_OBJ

/* TYPE [detachable BAD_INSPECT_VALUE] */
#define T99 EIF_TYPE_OBJ

/* TYPE [detachable VARIANT_VIOLATION] */
#define T100 EIF_TYPE_OBJ

/* TYPE [detachable LOOP_INVARIANT_VIOLATION] */
#define T101 EIF_TYPE_OBJ

/* TYPE [detachable RESCUE_FAILURE] */
#define T102 EIF_TYPE_OBJ

/* TYPE [detachable RESUMPTION_FAILURE] */
#define T103 EIF_TYPE_OBJ

/* TYPE [detachable CREATE_ON_DEFERRED] */
#define T104 EIF_TYPE_OBJ

/* TYPE [detachable EXTERNAL_FAILURE] */
#define T105 EIF_TYPE_OBJ

/* TYPE [detachable VOID_ASSIGNED_TO_EXPANDED] */
#define T106 EIF_TYPE_OBJ

/* TYPE [detachable EXCEPTION_IN_SIGNAL_HANDLER_FAILURE] */
#define T107 EIF_TYPE_OBJ

/* TYPE [detachable MISMATCH_FAILURE] */
#define T108 EIF_TYPE_OBJ

/* TYPE [detachable DEVELOPER_EXCEPTION] */
#define T109 EIF_TYPE_OBJ

/* TYPE [detachable ADDRESS_APPLIED_TO_MELTED_FEATURE] */
#define T110 EIF_TYPE_OBJ

/* TYPE [detachable SERIALIZATION_FAILURE] */
#define T111 EIF_TYPE_OBJ

/* STRING_TO_INTEGER_CONVERTOR */
typedef volatile struct S112 T112;

/* TYPED_POINTER [ANY] */
typedef volatile struct S113 T113;
extern T0* GE_boxed113(TC* ac, T113 a1);
extern T0* GE_boxed_pointer113(TC* ac, T113* a1);
typedef volatile struct Sb113 Tb113;

/* ENCODING */
typedef volatile struct S117 T117;

/* FILE_INFO */
typedef volatile struct S119 T119;

/* EXCEPTIONS */
typedef volatile struct S120 T120;

/* TYPED_POINTER [NATURAL_8] */
typedef volatile struct S121 T121;
extern T0* GE_boxed121(TC* ac, T121 a1);
extern T0* GE_boxed_pointer121(TC* ac, T121* a1);
typedef volatile struct Sb121 Tb121;

/* INTEGER_OVERFLOW_CHECKER */
typedef volatile struct S122 T122;

/* SYSTEM_ENCODINGS_IMP */
typedef volatile struct S125 T125;

/* SPECIAL [NATURAL_8] */
typedef volatile struct S127 T127;

/* TYPED_POINTER [NATURAL_16] */
typedef volatile struct S128 T128;
extern T0* GE_boxed128(TC* ac, T128 a1);
extern T0* GE_boxed_pointer128(TC* ac, T128* a1);
typedef volatile struct Sb128 Tb128;

/* SPECIAL [NATURAL_64] */
typedef volatile struct S130 T130;

/* HEXADECIMAL_STRING_TO_INTEGER_CONVERTER */
typedef volatile struct S131 T131;

/* ENCODING_IMP */
typedef volatile struct S132 T132;

/* UNICODE_CONVERSION */
typedef volatile struct S133 T133;

/* TYPED_POINTER [INTEGER_32] */
typedef volatile struct S134 T134;
extern T0* GE_boxed134(TC* ac, T134 a1);
extern T0* GE_boxed_pointer134(TC* ac, T134* a1);
typedef volatile struct Sb134 Tb134;

/* CONVERSION_FAILURE */
typedef volatile struct S135 T135;

/* DESCRIPTOR_CACHE */
typedef volatile struct S136 T136;

/* TYPED_POINTER [BOOLEAN] */
typedef volatile struct S137 T137;
extern T0* GE_boxed137(TC* ac, T137 a1);
extern T0* GE_boxed_pointer137(TC* ac, T137* a1);
typedef volatile struct Sb137 Tb137;

/* STRING_TABLE [READABLE_STRING_8] */
typedef volatile struct S138 T138;

/* HASH_TABLE [POINTER, READABLE_STRING_8] */
typedef volatile struct S139 T139;

/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8] */
typedef volatile struct S140 T140;

/* TYPED_POINTER [NATURAL_32] */
typedef volatile struct S141 T141;
extern T0* GE_boxed141(TC* ac, T141 a1);
extern T0* GE_boxed_pointer141(TC* ac, T141* a1);
typedef volatile struct Sb141 Tb141;

/* TYPE [detachable CONVERSION_FAILURE] */
#define T142 EIF_TYPE_OBJ

/* SPECIAL [READABLE_STRING_GENERAL] */
typedef volatile struct S143 T143;

/* SPECIAL [READABLE_STRING_8] */
typedef volatile struct S144 T144;

/* SPECIAL [POINTER] */
typedef volatile struct S145 T145;

/* CHARACTER_PROPERTY */
typedef volatile struct S146 T146;

/* SPECIAL [NATURAL_16] */
typedef volatile struct S147 T147;

/* SPECIAL [NATURAL_32] */
typedef volatile struct S148 T148;

/* ARRAY [NATURAL_16] */
typedef volatile struct S149 T149;

/* ARRAY [NATURAL_32] */
typedef volatile struct S150 T150;

/* Struct for boxed version of type BOOLEAN */
struct Sb1 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T1 volatile* volatile p1; /* pointer */
	T1 volatile z1; /* item */
};

/* Struct for boxed version of type CHARACTER_8 */
struct Sb2 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T2 volatile* volatile p1; /* pointer */
	T2 volatile z1; /* item */
};

/* Struct for boxed version of type CHARACTER_32 */
struct Sb3 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T3 volatile* volatile p1; /* pointer */
	T3 volatile z1; /* item */
};

/* Struct for boxed version of type INTEGER_8 */
struct Sb4 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T4 volatile* volatile p1; /* pointer */
	T4 volatile z1; /* item */
};

/* Struct for boxed version of type INTEGER_16 */
struct Sb5 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T5 volatile* volatile p1; /* pointer */
	T5 volatile z1; /* item */
};

/* Struct for boxed version of type INTEGER_32 */
struct Sb6 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile* volatile p1; /* pointer */
	T6 volatile z1; /* item */
};

/* Struct for boxed version of type INTEGER_64 */
struct Sb7 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T7 volatile* volatile p1; /* pointer */
	T7 volatile z1; /* item */
};

/* Struct for boxed version of type NATURAL_8 */
struct Sb8 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T8 volatile* volatile p1; /* pointer */
	T8 volatile z1; /* item */
};

/* Struct for boxed version of type NATURAL_16 */
struct Sb9 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T9 volatile* volatile p1; /* pointer */
	T9 volatile z1; /* item */
};

/* Struct for boxed version of type NATURAL_32 */
struct Sb10 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T10 volatile* volatile p1; /* pointer */
	T10 volatile z1; /* item */
};

/* Struct for boxed version of type NATURAL_64 */
struct Sb11 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T11 volatile* volatile p1; /* pointer */
	T11 volatile z1; /* item */
};

/* Struct for boxed version of type REAL_32 */
struct Sb12 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T12 volatile* volatile p1; /* pointer */
	T12 volatile z1; /* item */
};

/* Struct for boxed version of type REAL_64 */
struct Sb13 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T13 volatile* volatile p1; /* pointer */
	T13 volatile z1; /* item */
};

/* Struct for boxed version of type POINTER */
struct Sb14 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T14 volatile* volatile p1; /* pointer */
	T14 volatile z1; /* item */
};

/* Struct for type UTF_CONVERTER */
struct S83 {
	char volatile dummy;
};

/* Struct for boxed version of type UTF_CONVERTER */
struct Sb83 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T83* volatile p1; /* pointer */
	T83 z1; /* item */
};

/* Struct for type TYPED_POINTER [NATURAL_32] */
struct S141 {
	T14 volatile a1; /* to_pointer */
};

/* Struct for boxed version of type TYPED_POINTER [NATURAL_32] */
struct Sb141 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T141* volatile p1; /* pointer */
	T141 z1; /* item */
};

/* Struct for type TYPED_POINTER [BOOLEAN] */
struct S137 {
	T14 volatile a1; /* to_pointer */
};

/* Struct for boxed version of type TYPED_POINTER [BOOLEAN] */
struct Sb137 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T137* volatile p1; /* pointer */
	T137 z1; /* item */
};

/* Struct for type TYPED_POINTER [INTEGER_32] */
struct S134 {
	T14 volatile a1; /* to_pointer */
};

/* Struct for boxed version of type TYPED_POINTER [INTEGER_32] */
struct Sb134 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T134* volatile p1; /* pointer */
	T134 z1; /* item */
};

/* Struct for type TYPED_POINTER [NATURAL_16] */
struct S128 {
	T14 volatile a1; /* to_pointer */
};

/* Struct for boxed version of type TYPED_POINTER [NATURAL_16] */
struct Sb128 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T128* volatile p1; /* pointer */
	T128 z1; /* item */
};

/* Struct for type TYPED_POINTER [NATURAL_8] */
struct S121 {
	T14 volatile a1; /* to_pointer */
};

/* Struct for boxed version of type TYPED_POINTER [NATURAL_8] */
struct Sb121 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T121* volatile p1; /* pointer */
	T121 z1; /* item */
};

/* Struct for type TYPED_POINTER [ANY] */
struct S113 {
	T14 volatile a1; /* to_pointer */
};

/* Struct for boxed version of type TYPED_POINTER [ANY] */
struct Sb113 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T113* volatile p1; /* pointer */
	T113 z1; /* item */
};

/* Struct for type SPECIAL [CHARACTER_8] */
struct S15 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T6 volatile a2; /* count */
	T2 volatile z2[]; /* item */
};

/* Struct for type SPECIAL [CHARACTER_32] */
struct S16 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T6 volatile a2; /* count */
	T3 volatile z2[]; /* item */
};

/* Struct for type STRING_8 */
struct S17 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* area */
	T6 volatile a2; /* count */
	T6 volatile a3; /* internal_hash_code */
	T6 volatile a4; /* internal_case_insensitive_hash_code */
};

/* Struct for type STRING_32 */
struct S18 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* area */
	T6 volatile a2; /* count */
	T6 volatile a3; /* internal_hash_code */
	T6 volatile a4; /* internal_case_insensitive_hash_code */
};

/* Struct for type ISE_EXCEPTION_MANAGER */
struct S21 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
};

/* Struct for type APPLICATION */
struct S26 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
};

/* Struct for type CELL [detachable EXCEPTION] */
struct S27 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* item */
};

/* Struct for type HASH_TABLE [INTEGER_32, INTEGER_32] */
struct S28 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T0* volatile a2; /* content */
	T0* volatile a3; /* keys */
	T0* volatile a4; /* deleted_marks */
	T0* volatile a5; /* indexes_map */
	T6 volatile a6; /* iteration_position */
	T6 volatile a7; /* count */
	T6 volatile a8; /* deleted_item_position */
	T6 volatile a9; /* control */
	T6 volatile a10; /* found_item */
	T1 volatile a11; /* has_default */
	T6 volatile a12; /* item_position */
	T6 volatile a13; /* ht_lowest_deleted_position */
	T6 volatile a14; /* ht_deleted_item */
	T6 volatile a15; /* ht_deleted_key */
	T1 volatile a16; /* object_comparison */
};

/* Struct for type CELL [detachable TUPLE [INTEGER_32, INTEGER_32, INTEGER_32, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, INTEGER_32, BOOLEAN]] */
struct S29 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* item */
};

/* Struct for type CELL [NO_MORE_MEMORY] */
struct S30 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* item */
};

/* Struct for type C_STRING */
struct S31 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* managed_data */
	T6 volatile a2; /* count */
};

/* Struct for type TUPLE [INTEGER_32, INTEGER_32, INTEGER_32, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, INTEGER_32, BOOLEAN] */
struct S32 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile z1;
	T6 volatile z2;
	T6 volatile z3;
	T0* volatile z4;
	T0* volatile z5;
	T0* volatile z6;
	T0* volatile z7;
	T0* volatile z8;
	T0* volatile z9;
	T6 volatile z10;
	T1 volatile z11;
};

/* Struct for type ESTUFA */
struct S33 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* sensor_temperatura */
	T0* volatile a2; /* sensor_umidade */
	T0* volatile a3; /* nome */
	T0* volatile a4; /* irrigacao */
	T0* volatile a5; /* controlador */
};

/* Struct for type STD_FILES */
struct S34 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* default_output */
};

/* Struct for type SENSOR_TEMPERATURA */
struct S35 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T12 volatile a1; /* valor */
};

/* Struct for type SENSOR_UMIDADE */
struct S36 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T12 volatile a1; /* valor */
};

/* Struct for type VOID_TARGET */
struct S41 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type ROUTINE_FAILURE */
struct S43 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* routine_name */
	T0* volatile a4; /* class_name */
	T0* volatile a5; /* internal_trace */
	T0* volatile a6; /* recipient_name */
	T0* volatile a7; /* type_name */
};

/* Struct for type OLD_VIOLATION */
struct S45 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type NO_MORE_MEMORY */
struct S47 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T6 volatile a3; /* internal_code */
	T0* volatile a4; /* internal_trace */
	T0* volatile a5; /* recipient_name */
	T0* volatile a6; /* type_name */
};

/* Struct for type INVARIANT_VIOLATION */
struct S48 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T1 volatile a3; /* is_entry */
	T0* volatile a4; /* internal_trace */
	T0* volatile a5; /* recipient_name */
	T0* volatile a6; /* type_name */
};

/* Struct for type OPERATING_SYSTEM_SIGNAL_FAILURE */
struct S49 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T6 volatile a3; /* signal_code */
	T0* volatile a4; /* internal_trace */
	T0* volatile a5; /* recipient_name */
	T0* volatile a6; /* type_name */
};

/* Struct for type IO_FAILURE */
struct S50 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T6 volatile a3; /* internal_code */
	T6 volatile a4; /* error_code */
	T0* volatile a5; /* internal_trace */
	T0* volatile a6; /* recipient_name */
	T0* volatile a7; /* type_name */
};

/* Struct for type OPERATING_SYSTEM_FAILURE */
struct S51 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T6 volatile a3; /* error_code */
	T0* volatile a4; /* internal_trace */
	T0* volatile a5; /* recipient_name */
	T0* volatile a6; /* type_name */
};

/* Struct for type COM_FAILURE */
struct S52 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T6 volatile a3; /* hresult_code */
	T0* volatile a4; /* exception_information */
	T6 volatile a5; /* hresult */
	T0* volatile a6; /* internal_trace */
	T0* volatile a7; /* recipient_name */
	T0* volatile a8; /* type_name */
};

/* Struct for type EIFFEL_RUNTIME_PANIC */
struct S53 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T6 volatile a3; /* internal_code */
	T0* volatile a4; /* internal_trace */
	T0* volatile a5; /* recipient_name */
	T0* volatile a6; /* type_name */
};

/* Struct for type PRECONDITION_VIOLATION */
struct S55 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type POSTCONDITION_VIOLATION */
struct S56 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type FLOATING_POINT_FAILURE */
struct S57 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type CHECK_VIOLATION */
struct S58 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type BAD_INSPECT_VALUE */
struct S59 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type VARIANT_VIOLATION */
struct S60 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type LOOP_INVARIANT_VIOLATION */
struct S61 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type RESCUE_FAILURE */
struct S62 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type RESUMPTION_FAILURE */
struct S63 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type CREATE_ON_DEFERRED */
struct S64 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type EXTERNAL_FAILURE */
struct S65 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type VOID_ASSIGNED_TO_EXPANDED */
struct S66 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type EXCEPTION_IN_SIGNAL_HANDLER_FAILURE */
struct S67 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type MISMATCH_FAILURE */
struct S68 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type DEVELOPER_EXCEPTION */
struct S69 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type ADDRESS_APPLIED_TO_MELTED_FEATURE */
struct S70 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type SERIALIZATION_FAILURE */
struct S71 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type PRIMES */
struct S72 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
};

/* Struct for type SPECIAL [INTEGER_32] */
struct S73 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T6 volatile a2; /* count */
	T6 volatile z2[]; /* item */
};

/* Struct for type SPECIAL [BOOLEAN] */
struct S74 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T6 volatile a2; /* count */
	T1 volatile z2[]; /* item */
};

/* Struct for type IRRIGACAO */
struct S75 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T1 volatile a1; /* ligada */
};

/* Struct for type CONTROLADOR */
struct S76 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
};

/* Struct for type CONSOLE */
struct S78 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* last_integer */
	T12 volatile a2; /* last_real */
	T14 volatile a3; /* file_pointer */
	T0* volatile a4; /* last_string_32 */
	T6 volatile a5; /* mode */
	T0* volatile a6; /* last_string */
	T0* volatile a7; /* internal_name */
	T0* volatile a8; /* internal_detachable_name_pointer */
	T1 volatile a9; /* is_sequence_an_expected_numeric */
	T2 volatile a10; /* last_character */
	T0* volatile a11; /* internal_encoding */
};

/* Struct for type CELL [INTEGER_32] */
struct S84 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* item */
};

/* Struct for type MANAGED_POINTER */
struct S85 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T14 volatile a1; /* item */
	T6 volatile a2; /* count */
	T1 volatile a3; /* is_shared */
};

/* Struct for type STRING_TO_INTEGER_CONVERTOR */
struct S112 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* sign */
	T11 volatile a2; /* part1 */
	T11 volatile a3; /* part2 */
	T6 volatile a4; /* last_state */
	T0* volatile a5; /* leading_separators */
	T0* volatile a6; /* trailing_separators */
	T6 volatile a7; /* conversion_type */
	T1 volatile a8; /* internal_overflowed */
	T1 volatile a9; /* leading_separators_acceptable */
	T1 volatile a10; /* trailing_separators_acceptable */
};

/* Struct for type ENCODING */
struct S117 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* encoding_i */
	T0* volatile a2; /* code_page */
};

/* Struct for type FILE_INFO */
struct S119 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T1 volatile a1; /* is_following_symlinks */
	T1 volatile a2; /* exists */
	T0* volatile a3; /* buffered_file_info */
};

/* Struct for type EXCEPTIONS */
struct S120 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
};

/* Struct for type INTEGER_OVERFLOW_CHECKER */
struct S122 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* integer_overflow_state1 */
	T0* volatile a2; /* integer_overflow_state2 */
	T0* volatile a3; /* natural_overflow_state1 */
	T0* volatile a4; /* natural_overflow_state2 */
};

/* Struct for type SYSTEM_ENCODINGS_IMP */
struct S125 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
};

/* Struct for type SPECIAL [NATURAL_8] */
struct S127 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T6 volatile a2; /* count */
	T8 volatile z2[]; /* item */
};

/* Struct for type SPECIAL [NATURAL_64] */
struct S130 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T6 volatile a2; /* count */
	T11 volatile z2[]; /* item */
};

/* Struct for type HEXADECIMAL_STRING_TO_INTEGER_CONVERTER */
struct S131 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* last_state */
	T1 volatile a2; /* internal_overflowed */
	T11 volatile a3; /* part1 */
	T11 volatile a4; /* part2 */
	T0* volatile a5; /* leading_separators */
	T0* volatile a6; /* trailing_separators */
	T6 volatile a7; /* sign */
	T6 volatile a8; /* conversion_type */
	T2 volatile a9; /* internal_lookahead */
	T1 volatile a10; /* leading_separators_acceptable */
	T1 volatile a11; /* trailing_separators_acceptable */
};

/* Struct for type ENCODING_IMP */
struct S132 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T1 volatile a1; /* last_conversion_successful */
	T0* volatile a2; /* last_converted_string */
	T1 volatile a3; /* last_was_wide_string */
};

/* Struct for type UNICODE_CONVERSION */
struct S133 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T1 volatile a1; /* last_conversion_successful */
	T0* volatile a2; /* last_converted_string */
	T1 volatile a3; /* last_was_wide_string */
};

/* Struct for type CONVERSION_FAILURE */
struct S135 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type DESCRIPTOR_CACHE */
struct S136 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* cache */
	T0* volatile a2; /* converted_pair */
};

/* Struct for type STRING_TABLE [READABLE_STRING_8] */
struct S138 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T1 volatile a1; /* has_default */
	T0* volatile a2; /* keys */
	T0* volatile a3; /* indexes_map */
	T0* volatile a4; /* deleted_marks */
	T6 volatile a5; /* capacity */
	T1 volatile a6; /* is_case_insensitive */
	T0* volatile a7; /* found_item */
	T0* volatile a8; /* content */
	T6 volatile a9; /* deleted_item_position */
	T6 volatile a10; /* item_position */
	T6 volatile a11; /* count */
	T6 volatile a12; /* control */
	T6 volatile a13; /* iteration_position */
	T6 volatile a14; /* ht_lowest_deleted_position */
	T0* volatile a15; /* ht_deleted_item */
	T0* volatile a16; /* ht_deleted_key */
	T1 volatile a17; /* object_comparison */
};

/* Struct for type HASH_TABLE [POINTER, READABLE_STRING_8] */
struct S139 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T14 volatile a1; /* found_item */
	T6 volatile a2; /* control */
	T6 volatile a3; /* capacity */
	T0* volatile a4; /* content */
	T0* volatile a5; /* keys */
	T0* volatile a6; /* deleted_marks */
	T0* volatile a7; /* indexes_map */
	T6 volatile a8; /* iteration_position */
	T6 volatile a9; /* count */
	T6 volatile a10; /* deleted_item_position */
	T1 volatile a11; /* has_default */
	T6 volatile a12; /* item_position */
	T6 volatile a13; /* ht_lowest_deleted_position */
	T14 volatile a14; /* ht_deleted_item */
	T0* volatile a15; /* ht_deleted_key */
	T1 volatile a16; /* object_comparison */
};

/* Struct for type HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8] */
struct S140 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T1 volatile a1; /* has_default */
	T0* volatile a2; /* keys */
	T0* volatile a3; /* indexes_map */
	T0* volatile a4; /* deleted_marks */
	T6 volatile a5; /* capacity */
	T0* volatile a6; /* content */
	T6 volatile a7; /* iteration_position */
	T6 volatile a8; /* count */
	T6 volatile a9; /* deleted_item_position */
	T6 volatile a10; /* control */
	T0* volatile a11; /* found_item */
	T6 volatile a12; /* item_position */
	T6 volatile a13; /* ht_lowest_deleted_position */
	T0* volatile a14; /* ht_deleted_item */
	T0* volatile a15; /* ht_deleted_key */
	T1 volatile a16; /* object_comparison */
};

/* Struct for type SPECIAL [READABLE_STRING_GENERAL] */
struct S143 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T6 volatile a2; /* count */
	T0* volatile z2[]; /* item */
};

/* Struct for type SPECIAL [READABLE_STRING_8] */
struct S144 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T6 volatile a2; /* count */
	T0* volatile z2[]; /* item */
};

/* Struct for type SPECIAL [POINTER] */
struct S145 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T6 volatile a2; /* count */
	T14 volatile z2[]; /* item */
};

/* Struct for type CHARACTER_PROPERTY */
struct S146 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
};

/* Struct for type SPECIAL [NATURAL_16] */
struct S147 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T6 volatile a2; /* count */
	T9 volatile z2[]; /* item */
};

/* Struct for type SPECIAL [NATURAL_32] */
struct S148 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T6 volatile a2; /* count */
	T10 volatile z2[]; /* item */
};

/* Struct for type ARRAY [NATURAL_16] */
struct S149 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* area */
	T6 volatile a2; /* lower */
	T6 volatile a3; /* upper */
};

/* Struct for type ARRAY [NATURAL_32] */
struct S150 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* area */
	T6 volatile a2; /* lower */
	T6 volatile a3; /* upper */
};


extern T83 GE_default83;
extern T113 GE_default113;
extern T121 GE_default121;
extern T128 GE_default128;
extern T134 GE_default134;
extern T137 GE_default137;
extern T141 GE_default141;

extern T0* GE_new_str8(T6 c);
extern T0* GE_new_str32(T6 c);
extern T0* GE_new_istr8(T6 c);
extern T0* GE_new_istr32(T6 c);
extern T14 GE_sp8_base_address(T0* a1);
extern T14 GE_sp32_base_address(T0* a1);
/* New instance of type BOOLEAN */
extern T0* GE_new1(TC* ac, T1 initialize);
/* New instance of type CHARACTER_8 */
extern T0* GE_new2(TC* ac, T1 initialize);
/* New instance of type CHARACTER_32 */
extern T0* GE_new3(TC* ac, T1 initialize);
/* New instance of type INTEGER_8 */
extern T0* GE_new4(TC* ac, T1 initialize);
/* New instance of type INTEGER_16 */
extern T0* GE_new5(TC* ac, T1 initialize);
/* New instance of type INTEGER_32 */
extern T0* GE_new6(TC* ac, T1 initialize);
/* New instance of type INTEGER_64 */
extern T0* GE_new7(TC* ac, T1 initialize);
/* New instance of type NATURAL_8 */
extern T0* GE_new8(TC* ac, T1 initialize);
/* New instance of type NATURAL_16 */
extern T0* GE_new9(TC* ac, T1 initialize);
/* New instance of type NATURAL_32 */
extern T0* GE_new10(TC* ac, T1 initialize);
/* New instance of type NATURAL_64 */
extern T0* GE_new11(TC* ac, T1 initialize);
/* New instance of type REAL_32 */
extern T0* GE_new12(TC* ac, T1 initialize);
/* New instance of type REAL_64 */
extern T0* GE_new13(TC* ac, T1 initialize);
/* New instance of type POINTER */
extern T0* GE_new14(TC* ac, T1 initialize);
/* New instance of type SPECIAL [CHARACTER_8] */
extern T0* GE_new15(TC* ac, T6 a1, T1 initialize);
/* New instance of type SPECIAL [CHARACTER_32] */
extern T0* GE_new16(TC* ac, T6 a1, T1 initialize);
/* New instance of type STRING_8 */
extern T0* GE_new17(TC* ac, T1 initialize);
/* New instance of type STRING_32 */
extern T0* GE_new18(TC* ac, T1 initialize);
/* New instance of type ISE_EXCEPTION_MANAGER */
extern T0* GE_new21(TC* ac, T1 initialize);
/* New instance of type APPLICATION */
extern T0* GE_new26(TC* ac, T1 initialize);
/* New instance of type CELL [detachable EXCEPTION] */
extern T0* GE_new27(TC* ac, T1 initialize);
/* New instance of type HASH_TABLE [INTEGER_32, INTEGER_32] */
extern T0* GE_new28(TC* ac, T1 initialize);
/* New instance of type CELL [detachable TUPLE [INTEGER_32, INTEGER_32, INTEGER_32, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, INTEGER_32, BOOLEAN]] */
extern T0* GE_new29(TC* ac, T1 initialize);
/* New instance of type CELL [NO_MORE_MEMORY] */
extern T0* GE_new30(TC* ac, T1 initialize);
/* New instance of type C_STRING */
extern T0* GE_new31(TC* ac, T1 initialize);
/* New instance of type TUPLE [INTEGER_32, INTEGER_32, INTEGER_32, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, INTEGER_32, BOOLEAN] */
extern T0* GE_new32(TC* ac, T1 initialize);
/* New instance of type ESTUFA */
extern T0* GE_new33(TC* ac, T1 initialize);
/* New instance of type STD_FILES */
extern T0* GE_new34(TC* ac, T1 initialize);
/* New instance of type SENSOR_TEMPERATURA */
extern T0* GE_new35(TC* ac, T1 initialize);
/* New instance of type SENSOR_UMIDADE */
extern T0* GE_new36(TC* ac, T1 initialize);
/* New instance of type VOID_TARGET */
extern T0* GE_new41(TC* ac, T1 initialize);
/* New instance of type ROUTINE_FAILURE */
extern T0* GE_new43(TC* ac, T1 initialize);
/* New instance of type OLD_VIOLATION */
extern T0* GE_new45(TC* ac, T1 initialize);
/* New instance of type NO_MORE_MEMORY */
extern T0* GE_new47(TC* ac, T1 initialize);
/* New instance of type INVARIANT_VIOLATION */
extern T0* GE_new48(TC* ac, T1 initialize);
/* New instance of type OPERATING_SYSTEM_SIGNAL_FAILURE */
extern T0* GE_new49(TC* ac, T1 initialize);
/* New instance of type IO_FAILURE */
extern T0* GE_new50(TC* ac, T1 initialize);
/* New instance of type OPERATING_SYSTEM_FAILURE */
extern T0* GE_new51(TC* ac, T1 initialize);
/* New instance of type COM_FAILURE */
extern T0* GE_new52(TC* ac, T1 initialize);
/* New instance of type EIFFEL_RUNTIME_PANIC */
extern T0* GE_new53(TC* ac, T1 initialize);
/* New instance of type PRECONDITION_VIOLATION */
extern T0* GE_new55(TC* ac, T1 initialize);
/* New instance of type POSTCONDITION_VIOLATION */
extern T0* GE_new56(TC* ac, T1 initialize);
/* New instance of type FLOATING_POINT_FAILURE */
extern T0* GE_new57(TC* ac, T1 initialize);
/* New instance of type CHECK_VIOLATION */
extern T0* GE_new58(TC* ac, T1 initialize);
/* New instance of type BAD_INSPECT_VALUE */
extern T0* GE_new59(TC* ac, T1 initialize);
/* New instance of type VARIANT_VIOLATION */
extern T0* GE_new60(TC* ac, T1 initialize);
/* New instance of type LOOP_INVARIANT_VIOLATION */
extern T0* GE_new61(TC* ac, T1 initialize);
/* New instance of type RESCUE_FAILURE */
extern T0* GE_new62(TC* ac, T1 initialize);
/* New instance of type RESUMPTION_FAILURE */
extern T0* GE_new63(TC* ac, T1 initialize);
/* New instance of type CREATE_ON_DEFERRED */
extern T0* GE_new64(TC* ac, T1 initialize);
/* New instance of type EXTERNAL_FAILURE */
extern T0* GE_new65(TC* ac, T1 initialize);
/* New instance of type VOID_ASSIGNED_TO_EXPANDED */
extern T0* GE_new66(TC* ac, T1 initialize);
/* New instance of type EXCEPTION_IN_SIGNAL_HANDLER_FAILURE */
extern T0* GE_new67(TC* ac, T1 initialize);
/* New instance of type MISMATCH_FAILURE */
extern T0* GE_new68(TC* ac, T1 initialize);
/* New instance of type DEVELOPER_EXCEPTION */
extern T0* GE_new69(TC* ac, T1 initialize);
/* New instance of type ADDRESS_APPLIED_TO_MELTED_FEATURE */
extern T0* GE_new70(TC* ac, T1 initialize);
/* New instance of type SERIALIZATION_FAILURE */
extern T0* GE_new71(TC* ac, T1 initialize);
/* New instance of type PRIMES */
extern T0* GE_new72(TC* ac, T1 initialize);
/* New instance of type SPECIAL [INTEGER_32] */
extern T0* GE_new73(TC* ac, T6 a1, T1 initialize);
/* New instance of type SPECIAL [BOOLEAN] */
extern T0* GE_new74(TC* ac, T6 a1, T1 initialize);
/* New instance of type IRRIGACAO */
extern T0* GE_new75(TC* ac, T1 initialize);
/* New instance of type CONTROLADOR */
extern T0* GE_new76(TC* ac, T1 initialize);
/* New instance of type CONSOLE */
extern T0* GE_new78(TC* ac, T1 initialize);
/* New instance of type UTF_CONVERTER */
extern T0* GE_new83(TC* ac, T1 initialize);
/* New instance of type CELL [INTEGER_32] */
extern T0* GE_new84(TC* ac, T1 initialize);
/* New instance of type MANAGED_POINTER */
extern T0* GE_new85(TC* ac, T1 initialize);
/* New instance of type STRING_TO_INTEGER_CONVERTOR */
extern T0* GE_new112(TC* ac, T1 initialize);
/* New instance of type TYPED_POINTER [ANY] */
extern T0* GE_new113(TC* ac, T1 initialize);
/* New instance of type ENCODING */
extern T0* GE_new117(TC* ac, T1 initialize);
/* New instance of type FILE_INFO */
extern T0* GE_new119(TC* ac, T1 initialize);
/* New instance of type EXCEPTIONS */
extern T0* GE_new120(TC* ac, T1 initialize);
/* New instance of type TYPED_POINTER [NATURAL_8] */
extern T0* GE_new121(TC* ac, T1 initialize);
/* New instance of type INTEGER_OVERFLOW_CHECKER */
extern T0* GE_new122(TC* ac, T1 initialize);
/* New instance of type SYSTEM_ENCODINGS_IMP */
extern T0* GE_new125(TC* ac, T1 initialize);
/* New instance of type SPECIAL [NATURAL_8] */
extern T0* GE_new127(TC* ac, T6 a1, T1 initialize);
/* New instance of type TYPED_POINTER [NATURAL_16] */
extern T0* GE_new128(TC* ac, T1 initialize);
/* New instance of type SPECIAL [NATURAL_64] */
extern T0* GE_new130(TC* ac, T6 a1, T1 initialize);
/* New instance of type HEXADECIMAL_STRING_TO_INTEGER_CONVERTER */
extern T0* GE_new131(TC* ac, T1 initialize);
/* New instance of type ENCODING_IMP */
extern T0* GE_new132(TC* ac, T1 initialize);
/* New instance of type UNICODE_CONVERSION */
extern T0* GE_new133(TC* ac, T1 initialize);
/* New instance of type TYPED_POINTER [INTEGER_32] */
extern T0* GE_new134(TC* ac, T1 initialize);
/* New instance of type CONVERSION_FAILURE */
extern T0* GE_new135(TC* ac, T1 initialize);
/* New instance of type DESCRIPTOR_CACHE */
extern T0* GE_new136(TC* ac, T1 initialize);
/* New instance of type TYPED_POINTER [BOOLEAN] */
extern T0* GE_new137(TC* ac, T1 initialize);
/* New instance of type STRING_TABLE [READABLE_STRING_8] */
extern T0* GE_new138(TC* ac, T1 initialize);
/* New instance of type HASH_TABLE [POINTER, READABLE_STRING_8] */
extern T0* GE_new139(TC* ac, T1 initialize);
/* New instance of type HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8] */
extern T0* GE_new140(TC* ac, T1 initialize);
/* New instance of type TYPED_POINTER [NATURAL_32] */
extern T0* GE_new141(TC* ac, T1 initialize);
/* New instance of type SPECIAL [READABLE_STRING_GENERAL] */
extern T0* GE_new143(TC* ac, T6 a1, T1 initialize);
/* New instance of type SPECIAL [READABLE_STRING_8] */
extern T0* GE_new144(TC* ac, T6 a1, T1 initialize);
/* New instance of type SPECIAL [POINTER] */
extern T0* GE_new145(TC* ac, T6 a1, T1 initialize);
/* New instance of type CHARACTER_PROPERTY */
extern T0* GE_new146(TC* ac, T1 initialize);
/* New instance of type SPECIAL [NATURAL_16] */
extern T0* GE_new147(TC* ac, T6 a1, T1 initialize);
/* New instance of type SPECIAL [NATURAL_32] */
extern T0* GE_new148(TC* ac, T6 a1, T1 initialize);
/* New instance of type ARRAY [NATURAL_16] */
extern T0* GE_new149(TC* ac, T1 initialize);
/* New instance of type ARRAY [NATURAL_32] */
extern T0* GE_new150(TC* ac, T1 initialize);
/* APPLICATION.make */
extern T0* T26c2(TC* ac);
/* ESTUFA.mostrar_status */
extern void T33f9(TC* ac, T0* C);
/* SENSOR_UMIDADE.ler_valor */
extern T12 T36f2(TC* ac, T0* C);
/* SENSOR_UMIDADE.ler_valor */
extern T12 T36f2p1(TC* ac, T0* C);
/* SENSOR_TEMPERATURA.ler_valor */
extern T12 T35f2(TC* ac, T0* C);
/* SENSOR_TEMPERATURA.ler_valor */
extern T12 T35f2p1(TC* ac, T0* C);
/* ESTUFA.print */
extern void T33s10(TC* ac, T0* a1);
/* STRING_8.as_string_32 */
extern T0* T17f7(TC* ac, T0* C);
/* STRING_32.put_code */
extern void T18f20(TC* ac, T0* C, T10 a1, T6 a2);
/* STRING_32.reset_hash_codes */
extern void T18f21(TC* ac, T0* C);
/* STRING_8.code */
extern T10 T17f5(TC* ac, T0* C, T6 a1);
/* INTEGER_32.to_natural_32 */
extern T10 T6f7(TC* ac, T6 volatile* C);
/* INTEGER_32.is_greater */
extern T1 T6f4(TC* ac, T6 volatile* C, T6 a1);
/* STRING_32.set_count */
extern void T18f19(TC* ac, T0* C, T6 a1);
/* STRING_32.make */
extern void T18f18(TC* ac, T0* C, T6 a1);
/* STRING_32.make */
extern T0* T18c18(TC* ac, T6 a1);
/* SPECIAL [CHARACTER_32].make_filled */
extern T0* T16c7(TC* ac, T3 a1, T6 a2);
/* SPECIAL [CHARACTER_32].fill_with */
extern void T16f10(TC* ac, T0* C, T3 a1, T6 a2, T6 a3);
/* SPECIAL [CHARACTER_32].extend */
extern void T16f11(TC* ac, T0* C, T3 a1);
/* INTEGER_32.min */
extern T6 T6f15(TC* ac, T6 volatile* C, T6 a1);
/* INTEGER_32.is_less_equal */
extern T1 T6f17(TC* ac, T6 volatile* C, T6 a1);
/* SPECIAL [CHARACTER_32].make_empty */
extern void T16f9(TC* ac, T0* C, T6 a1);
/* SPECIAL [CHARACTER_32].make_empty */
extern T0* T16c9(TC* ac, T6 a1);
/* STD_FILES.put_string */
extern void T34f11(TC* ac, T0* C, T0* a1);
/* CONSOLE.put_string */
extern void T78f32(TC* ac, T0* C, T0* a1);
/* CONSOLE.console_ps */
extern void T78s38(TC* ac, T14 a1, T14 a2, T6 a3);
/* STD_FILES.standard_default */
extern T0* T34f4(TC* ac, T0* C);
/* STD_FILES.output */
extern T0* T34s6(TC* ac);
/* CONSOLE.make_open_stdout */
extern T0* T78c30(TC* ac, T0* a1);
/* CONSOLE.set_write_mode */
extern void T78f36(TC* ac, T0* C);
/* CONSOLE.console_def */
extern T14 T78s15(TC* ac, T6 a1);
/* CONSOLE.make_with_name */
extern void T78f33(TC* ac, T0* C, T0* a1);
/* STRING_32.make_empty */
extern T0* T18c22(TC* ac);
/* CONSOLE.make_with_name */
extern void T78f33p1(TC* ac, T0* C, T0* a1);
/* STRING_8.make_empty */
extern T0* T17c39(TC* ac);
/* STRING_8.make */
extern void T17f31(TC* ac, T0* C, T6 a1);
/* STRING_8.make */
extern T0* T17c31(TC* ac, T6 a1);
/* SPECIAL [CHARACTER_8].make_filled */
extern T0* T15c7(TC* ac, T2 a1, T6 a2);
/* SPECIAL [CHARACTER_8].fill_with */
extern void T15f10(TC* ac, T0* C, T2 a1, T6 a2, T6 a3);
/* SPECIAL [CHARACTER_8].extend */
extern void T15f14(TC* ac, T0* C, T2 a1);
/* SPECIAL [CHARACTER_8].make_empty */
extern void T15f11(TC* ac, T0* C, T6 a1);
/* SPECIAL [CHARACTER_8].make_empty */
extern T0* T15c11(TC* ac, T6 a1);
/* CONSOLE.default_pointer */
extern T14 T78s20(TC* ac);
/* CONSOLE.set_name */
extern void T78f39(TC* ac, T0* C, T0* a1);
/* FILE_INFO.file_name_to_pointer */
extern T0* T119f6(TC* ac, T0* C, T0* a1, T0* a2);
/* C_STRING.set_string */
extern void T31f7(TC* ac, T0* C, T0* a1);
/* C_STRING.set_substring */
extern void T31f8(TC* ac, T0* C, T0* a1, T6 a2, T6 a3);
/* MANAGED_POINTER.put_natural_8 */
extern void T85f14(TC* ac, T0* C, T8 a1, T6 a2);
/* POINTER.memory_copy */
extern void T14f13(TC* ac, T14 volatile* C, T14 a1, T6 a2);
/* POINTER.c_memcpy */
extern void T14s17(TC* ac, T14 a1, T14 a2, T6 a3);
/* NATURAL_32.to_natural_8 */
extern T8 T10f6(TC* ac, T10 volatile* C);
/* C_STRING.make_shared_from_pointer_and_count */
extern T0* T31c9(TC* ac, T14 a1, T6 a2);
/* MANAGED_POINTER.share_from_pointer */
extern T0* T85c16(TC* ac, T14 a1, T6 a2);
/* MANAGED_POINTER.increment_counter */
extern void T85f15(TC* ac, T0* C);
/* UTF_CONVERTER.escaped_utf_32_substring_into_utf_8_0_pointer */
extern void T83s17(TC* ac, T0* a1, T6 a2, T6 a3, T0* a4, T6 a5, T0* a6);
/* NATURAL_32.is_less_equal */
extern T1 T10f7(TC* ac, T10 volatile* C, T10 a1);
/* UTF_CONVERTER.to_natural_32 */
extern T10 T83s9(TC* ac, T0* a1);
/* HEXADECIMAL_STRING_TO_INTEGER_CONVERTER.parsed_natural_32 */
extern T10 T131f12(TC* ac, T0* C);
/* HEXADECIMAL_STRING_TO_INTEGER_CONVERTER.parse_string_with_type */
extern void T131f19(TC* ac, T0* C, T0* a1, T6 a2);
/* NATURAL_32.is_valid_character_8_code */
extern T1 T10f23(TC* ac, T10 volatile* C);
/* CHARACTER_32.is_character_8 */
extern T1 T3f7(TC* ac, T3 volatile* C);
/* HEXADECIMAL_STRING_TO_INTEGER_CONVERTER.parse_character */
extern void T131f22(TC* ac, T0* C, T2 a1);
/* HEXADECIMAL_STRING_TO_INTEGER_CONVERTER.overflowed */
extern T1 T131f16(TC* ac, T0* C);
/* INTEGER_OVERFLOW_CHECKER.will_overflow */
extern T1 T122f7(TC* ac, T0* C, T11 a1, T11 a2, T6 a3, T6 a4);
/* NATURAL_64.is_greater */
extern T1 T11f7(TC* ac, T11 volatile* C, T11 a1);
/* HEXADECIMAL_STRING_TO_INTEGER_CONVERTER.overflow_checker */
extern T0* T131f15(TC* ac, T0* C);
/* INTEGER_OVERFLOW_CHECKER.make */
extern T0* T122c13(TC* ac);
/* NATURAL_64.to_natural_64 */
extern T11 T11f10(TC* ac, T11 volatile* C);
/* NATURAL_32.to_natural_64 */
extern T11 T10f18(TC* ac, T10 volatile* C);
/* NATURAL_16.to_natural_64 */
extern T11 T9f6(TC* ac, T9 volatile* C);
/* INTEGER_64.to_natural_64 */
extern T11 T7f6(TC* ac, T7 volatile* C);
/* INTEGER_32.to_natural_64 */
extern T11 T6f21(TC* ac, T6 volatile* C);
/* INTEGER_16.to_natural_64 */
extern T11 T5f6(TC* ac, T5 volatile* C);
/* INTEGER_8.to_natural_64 */
extern T11 T4f6(TC* ac, T4 volatile* C);
/* SPECIAL [NATURAL_64].extend */
extern void T130f5(TC* ac, T0* C, T11 a1);
/* SPECIAL [NATURAL_64].make_empty */
extern T0* T130c4(TC* ac, T6 a1);
/* STRING_8.has */
extern T1 T17f13(TC* ac, T0* C, T2 a1);
/* NATURAL_8.to_natural_64 */
extern T11 T8f10(TC* ac, T8 volatile* C);
/* CHARACTER_8.to_hexa_digit */
extern T8 T2f24(TC* ac, T2 volatile* C);
/* INTEGER_8.to_natural_8 */
extern T8 T4f12(TC* ac, T4 volatile* C);
/* NATURAL_8.to_integer_8 */
extern T4 T8f17(TC* ac, T8 volatile* C);
/* CHARACTER_8.natural_32_code */
extern T10 T2f22(TC* ac, T2 volatile* C);
/* CHARACTER_8.is_hexa_digit */
extern T1 T2f23(TC* ac, T2 volatile* C);
/* NATURAL_8.is_greater */
extern T1 T8f5(TC* ac, T8 volatile* C, T8 a1);
/* CHARACTER_8.character_types */
extern T8 T2f7(TC* ac, T2 volatile* C, T6 a1);
/* CHARACTER_8.internal_character_types */
extern T0* T2f9(TC* ac, T2 volatile* C);
/* SPECIAL [NATURAL_8].extend */
extern void T127f6(TC* ac, T0* C, T8 a1);
/* SPECIAL [NATURAL_8].make_empty */
extern void T127f5(TC* ac, T0* C, T6 a1);
/* SPECIAL [NATURAL_8].make_empty */
extern T0* T127c5(TC* ac, T6 a1);
/* STRING_8.area_lower */
extern T6 T17f10(TC* ac, T0* C);
/* HEXADECIMAL_STRING_TO_INTEGER_CONVERTER.reset */
extern void T131f18(TC* ac, T0* C, T6 a1);
/* UTF_CONVERTER.ctoi_convertor */
extern T0* T83s10(TC* ac);
/* HEXADECIMAL_STRING_TO_INTEGER_CONVERTER.set_trailing_separators_acceptable */
extern void T131f21(TC* ac, T0* C, T1 a1);
/* HEXADECIMAL_STRING_TO_INTEGER_CONVERTER.set_leading_separators_acceptable */
extern void T131f20(TC* ac, T0* C, T1 a1);
/* HEXADECIMAL_STRING_TO_INTEGER_CONVERTER.make */
extern T0* T131c17(TC* ac);
/* STRING_8.make_from_string */
extern T0* T17c42(TC* ac, T0* a1);
/* SPECIAL [CHARACTER_8].copy_data */
extern void T15f8(TC* ac, T0* C, T0* a1, T6 a2, T6 a3, T6 a4);
/* SPECIAL [CHARACTER_8].force */
extern void T15f13(TC* ac, T0* C, T2 a1, T6 a2);
/* SPECIAL [CHARACTER_8].move_data */
extern void T15f12(TC* ac, T0* C, T6 a1, T6 a2, T6 a3);
/* SPECIAL [CHARACTER_8].overlapping_move */
extern void T15f16(TC* ac, T0* C, T6 a1, T6 a2, T6 a3);
/* SPECIAL [CHARACTER_8].non_overlapping_move */
extern void T15f15(TC* ac, T0* C, T6 a1, T6 a2, T6 a3);
/* UTF_CONVERTER.is_hexa_decimal */
extern T1 T83s8(TC* ac, T0* a1);
/* HEXADECIMAL_STRING_TO_INTEGER_CONVERTER.is_integral_integer */
extern T1 T131f14(TC* ac, T0* C);
/* STRING_8.substring */
extern T0* T17f16(TC* ac, T0* C, T6 a1, T6 a2);
/* STRING_8.set_count */
extern void T17f36(TC* ac, T0* C, T6 a1);
/* STRING_8.reset_hash_codes */
extern void T17f37(TC* ac, T0* C);
/* STRING_8.new_string */
extern T0* T17f14(TC* ac, T0* C, T6 a1);
/* STRING_8.character_32_item */
extern T3 T17f15(TC* ac, T0* C, T6 a1);
/* INTEGER_32.is_greater_equal */
extern T1 T6f11(TC* ac, T6 volatile* C, T6 a1);
/* UTF_CONVERTER.utf_8_bytes_count */
extern T6 T83s5(TC* ac, T0* a1, T6 a2, T6 a3);
/* INTEGER_32.do_nothing */
extern void T6s31(TC* ac);
/* FILE_INFO.wchar_length */
extern T6 T119s4(TC* ac);
/* FILE_INFO.wchar_length */
extern T6 T119i4(TC* ac);
/* FILE_INFO.multi_byte_to_utf_16 */
extern T6 T119s8(TC* ac, T14 a1, T14 a2, T6 a3);
/* FILE_INFO.multi_byte_to_utf_16 */
extern T6 T119i8(TC* ac, T14 a1, T14 a2, T6 a3);
/* FILE_INFO.default_pointer */
extern T14 T119s7(TC* ac);
/* C_STRING.item */
extern T14 T31f3(TC* ac, T0* C);
/* C_STRING.make */
extern T0* T31c6(TC* ac, T0* a1);
/* C_STRING.make_empty */
extern void T31f4(TC* ac, T0* C, T6 a1);
/* C_STRING.make_empty */
extern T0* T31c4(TC* ac, T6 a1);
/* UTF_CONVERTER.escaped_utf_32_substring_into_utf_16_0_pointer */
extern void T83s16(TC* ac, T0* a1, T6 a2, T6 a3, T0* a4, T6 a5, T0* a6);
/* MANAGED_POINTER.put_natural_16 */
extern void T85f17(TC* ac, T0* C, T9 a1, T6 a2);
/* NATURAL_32.to_natural_16 */
extern T9 T10f14(TC* ac, T10 volatile* C);
/* NATURAL_32.is_greater */
extern T1 T10f13(TC* ac, T10 volatile* C, T10 a1);
/* UTF_CONVERTER.utf_16_bytes_count */
extern T6 T83s6(TC* ac, T0* a1, T6 a2, T6 a3);
/* MANAGED_POINTER.make */
extern T0* T85c12(TC* ac, T6 a1);
/* EXCEPTIONS.raise */
extern void T120s2(TC* ac, T0* a1);
/* DEVELOPER_EXCEPTION.raise */
extern void T69f17(TC* ac, T0* C);
/* ISE_EXCEPTION_MANAGER.raise */
extern void T21s19(TC* ac, T0* a1);
/* CONVERSION_FAILURE.code */
extern T6 T135f10(TC* ac, T0* C);
/* DEVELOPER_EXCEPTION.code */
extern T6 T69f9(TC* ac, T0* C);
/* ISE_EXCEPTION_MANAGER.default_pointer */
extern T14 T21s9(TC* ac);
/* ISE_EXCEPTION_MANAGER.set_last_exception */
extern void T21s17(TC* ac, T0* a1);
/* CELL [detachable EXCEPTION].put */
extern void T27f2(TC* ac, T0* C, T0* a1);
/* CELL [detachable EXCEPTION].put */
extern T0* T27c2(TC* ac, T0* a1);
/* ISE_EXCEPTION_MANAGER.last_exception_cell */
extern T0* T21s2(TC* ac);
/* CONVERSION_FAILURE.set_throwing_exception */
extern void T135f14(TC* ac, T0* C, T0* a1);
/* DEVELOPER_EXCEPTION.set_throwing_exception */
extern void T69f12(TC* ac, T0* C, T0* a1);
/* ISE_EXCEPTION_MANAGER.in_rescue */
extern T1 T21s8(TC* ac);
/* CONVERSION_FAILURE.is_ignored */
extern T1 T135f8(TC* ac, T0* C);
/* ISE_EXCEPTION_MANAGER.is_ignored */
extern T1 T21s13(TC* ac, T0* a1);
/* HASH_TABLE [INTEGER_32, INTEGER_32].has */
extern T1 T28f34(TC* ac, T0* C, T6 a1);
/* HASH_TABLE [INTEGER_32, INTEGER_32].same_keys */
extern T1 T28f26(TC* ac, T0* C, T6 a1, T6 a2);
/* HASH_TABLE [INTEGER_32, INTEGER_32].hash_code_of */
extern T6 T28f25(TC* ac, T0* C, T6 a1);
/* INTEGER_32.hash_code */
extern T6 T6f16(TC* ac, T6 volatile* C);
/* TYPE [detachable CONVERSION_FAILURE].type_id */
extern T6 T142f1(TC* ac, T0* C);
/* TYPE [detachable SERIALIZATION_FAILURE].type_id */
extern T6 T111f1(TC* ac, T0* C);
/* TYPE [detachable ADDRESS_APPLIED_TO_MELTED_FEATURE].type_id */
extern T6 T110f1(TC* ac, T0* C);
/* TYPE [detachable DEVELOPER_EXCEPTION].type_id */
extern T6 T109f1(TC* ac, T0* C);
/* TYPE [detachable MISMATCH_FAILURE].type_id */
extern T6 T108f1(TC* ac, T0* C);
/* TYPE [detachable EXCEPTION_IN_SIGNAL_HANDLER_FAILURE].type_id */
extern T6 T107f1(TC* ac, T0* C);
/* TYPE [detachable VOID_ASSIGNED_TO_EXPANDED].type_id */
extern T6 T106f1(TC* ac, T0* C);
/* TYPE [detachable EXTERNAL_FAILURE].type_id */
extern T6 T105f1(TC* ac, T0* C);
/* TYPE [detachable CREATE_ON_DEFERRED].type_id */
extern T6 T104f1(TC* ac, T0* C);
/* TYPE [detachable RESUMPTION_FAILURE].type_id */
extern T6 T103f1(TC* ac, T0* C);
/* TYPE [detachable RESCUE_FAILURE].type_id */
extern T6 T102f1(TC* ac, T0* C);
/* TYPE [detachable LOOP_INVARIANT_VIOLATION].type_id */
extern T6 T101f1(TC* ac, T0* C);
/* TYPE [detachable VARIANT_VIOLATION].type_id */
extern T6 T100f1(TC* ac, T0* C);
/* TYPE [detachable BAD_INSPECT_VALUE].type_id */
extern T6 T99f1(TC* ac, T0* C);
/* TYPE [detachable CHECK_VIOLATION].type_id */
extern T6 T98f1(TC* ac, T0* C);
/* TYPE [detachable FLOATING_POINT_FAILURE].type_id */
extern T6 T97f1(TC* ac, T0* C);
/* TYPE [detachable POSTCONDITION_VIOLATION].type_id */
extern T6 T96f1(TC* ac, T0* C);
/* TYPE [detachable PRECONDITION_VIOLATION].type_id */
extern T6 T95f1(TC* ac, T0* C);
/* TYPE [detachable EIFFEL_RUNTIME_PANIC].type_id */
extern T6 T94f1(TC* ac, T0* C);
/* TYPE [detachable COM_FAILURE].type_id */
extern T6 T93f1(TC* ac, T0* C);
/* TYPE [detachable OPERATING_SYSTEM_FAILURE].type_id */
extern T6 T92f1(TC* ac, T0* C);
/* TYPE [detachable IO_FAILURE].type_id */
extern T6 T91f1(TC* ac, T0* C);
/* TYPE [detachable OPERATING_SYSTEM_SIGNAL_FAILURE].type_id */
extern T6 T90f1(TC* ac, T0* C);
/* TYPE [detachable INVARIANT_VIOLATION].type_id */
extern T6 T89f1(TC* ac, T0* C);
/* TYPE [detachable NO_MORE_MEMORY].type_id */
extern T6 T88f1(TC* ac, T0* C);
/* TYPE [detachable OLD_VIOLATION].type_id */
extern T6 T87f1(TC* ac, T0* C);
/* TYPE [detachable ROUTINE_FAILURE].type_id */
extern T6 T86f1(TC* ac, T0* C);
/* TYPE [detachable VOID_TARGET].type_id */
extern T6 T81f1(TC* ac, T0* C);
/* ISE_EXCEPTION_MANAGER.ignored_exceptions */
extern T0* T21s3(TC* ac);
/* HASH_TABLE [INTEGER_32, INTEGER_32].make */
extern T0* T28c35(TC* ac, T6 a1);
/* SPECIAL [INTEGER_32].make_filled */
extern T0* T73c5(TC* ac, T6 a1, T6 a2);
/* SPECIAL [INTEGER_32].fill_with */
extern void T73f8(TC* ac, T0* C, T6 a1, T6 a2, T6 a3);
/* SPECIAL [INTEGER_32].extend */
extern void T73f9(TC* ac, T0* C, T6 a1);
/* SPECIAL [BOOLEAN].make_filled */
extern T0* T74c4(TC* ac, T1 a1, T6 a2);
/* SPECIAL [BOOLEAN].fill_with */
extern void T74f7(TC* ac, T0* C, T1 a1, T6 a2, T6 a3);
/* SPECIAL [BOOLEAN].extend */
extern void T74f9(TC* ac, T0* C, T1 a1);
/* SPECIAL [BOOLEAN].make_empty */
extern void T74f6(TC* ac, T0* C, T6 a1);
/* SPECIAL [INTEGER_32].make_empty */
extern void T73f4(TC* ac, T0* C, T6 a1);
/* SPECIAL [INTEGER_32].make_empty */
extern T0* T73c4(TC* ac, T6 a1);
/* PRIMES.higher_prime */
extern T6 T72s1(TC* ac, T6 a1);
/* PRIMES.is_prime */
extern T1 T72s3(TC* ac, T6 a1);
/* PRIMES.default_create */
extern T0* T72c5(TC* ac);
/* CONVERSION_FAILURE.exception_manager */
extern T0* T135s7(TC* ac);
/* DEVELOPER_EXCEPTION.is_ignored */
extern T1 T69f8(TC* ac, T0* C);
/* DEVELOPER_EXCEPTION.exception_manager */
extern T0* T69s6(TC* ac);
/* DEVELOPER_EXCEPTION.set_description */
extern void T69f14(TC* ac, T0* C, T0* a1);
/* C_STRING.set_count */
extern void T31f5(TC* ac, T0* C, T6 a1);
/* UTF_CONVERTER.utf_32_string_into_utf_8_0_pointer */
extern void T83s12(TC* ac, T0* a1, T0* a2, T6 a3, T0* a4);
/* CELL [INTEGER_32].put */
extern void T84f2(TC* ac, T0* C, T6 a1);
/* CELL [INTEGER_32].put */
extern T0* T84c2(TC* ac, T6 a1);
/* DEVELOPER_EXCEPTION.default_create */
extern T0* T69c11(TC* ac);
/* EXCEPTIONS.default_create */
extern T0* T120c1(TC* ac);
/* MANAGED_POINTER.default_pointer */
extern T14 T85s4(TC* ac);
/* POINTER.memory_calloc */
extern T14 T14s4(TC* ac, T6 a1, T6 a2);
/* POINTER.c_calloc */
extern T14 T14s7(TC* ac, T6 a1, T6 a2);
/* INTEGER_32.max */
extern T6 T6f8(TC* ac, T6 volatile* C, T6 a1);
/* MANAGED_POINTER.resize */
extern void T85f13(TC* ac, T0* C, T6 a1);
/* POINTER.memory_set */
extern void T14f12(TC* ac, T14 volatile* C, T6 a1, T6 a2);
/* POINTER.c_memset */
extern void T14s16(TC* ac, T14 a1, T6 a2, T6 a3);
/* POINTER.memory_realloc */
extern T14 T14f5(TC* ac, T14 volatile* C, T6 a1);
/* POINTER.c_realloc */
extern T14 T14s8(TC* ac, T14 a1, T6 a2);
/* CONSOLE.buffered_file_info */
extern T0* T78f17(TC* ac, T0* C);
/* FILE_INFO.make */
extern T0* T119c9(TC* ac);
/* FILE_INFO.make_filled_area */
extern void T119f10(TC* ac, T0* C, T8 a1, T6 a2);
/* SPECIAL [NATURAL_8].make_filled */
extern T0* T127c4(TC* ac, T8 a1, T6 a2);
/* SPECIAL [NATURAL_8].fill_with */
extern void T127f7(TC* ac, T0* C, T8 a1, T6 a2, T6 a3);
/* FILE_INFO.stat_size */
extern T6 T119s5(TC* ac);
/* STD_FILES.put_string_32 */
extern void T34f10(TC* ac, T0* C, T0* a1);
/* CONSOLE.put_string_32 */
extern void T78f31(TC* ac, T0* C, T0* a1);
/* CONSOLE.put_string_general */
extern void T78f37(TC* ac, T0* C, T0* a1);
/* UTF_CONVERTER.string_32_to_utf_8_string_8 */
extern T0* T83s3(TC* ac, T0* a1);
/* UTF_CONVERTER.utf_32_string_to_utf_8_string_8 */
extern T0* T83s4(TC* ac, T0* a1);
/* UTF_CONVERTER.utf_32_string_into_utf_8_string_8 */
extern void T83s14(TC* ac, T0* a1, T0* a2);
/* UTF_CONVERTER.utf_32_code_into_utf_8_string_8 */
extern void T83s15(TC* ac, T10 a1, T0* a2);
/* STRING_8.extend */
extern void T17f41(TC* ac, T0* C, T2 a1);
/* STRING_8.resize */
extern void T17f34(TC* ac, T0* C, T6 a1);
/* SPECIAL [CHARACTER_8].aliased_resized_area_with_default */
extern T0* T15f4(TC* ac, T0* C, T2 a1, T6 a2);
/* SPECIAL [CHARACTER_8].aliased_resized_area */
extern T0* T15f5(TC* ac, T0* C, T6 a1);
/* STRING_8.additional_space */
extern T6 T17f9(TC* ac, T0* C);
/* STRING_8.capacity */
extern T6 T17f8(TC* ac, T0* C);
/* STRING_32.code */
extern T10 T18f9(TC* ac, T0* C, T6 a1);
/* STRING_8.grow */
extern void T17f40(TC* ac, T0* C, T6 a1);
/* STRING_32.as_string_32 */
extern T0* T18f7(TC* ac, T0* C);
/* STRING_32.to_string_8 */
extern T0* T18f6(TC* ac, T0* C);
/* STRING_8.put_code */
extern void T17f38(TC* ac, T0* C, T10 a1, T6 a2);
/* STRING_32.is_valid_as_string_8 */
extern T1 T18f5(TC* ac, T0* C);
/* STRING_32.area_lower */
extern T6 T18f8(TC* ac, T0* C);
/* ENCODING.same_as */
extern T1 T117f3(TC* ac, T0* C, T0* a1);
/* STRING_8.is_case_insensitive_equal */
extern T1 T17f17(TC* ac, T0* C, T0* a1);
/* STRING_8.same_caseless_characters */
extern T1 T17f18(TC* ac, T0* C, T0* a1, T6 a2, T6 a3, T6 a4);
/* CHARACTER_8.as_lower */
extern T2 T2f20(TC* ac, T2 volatile* C);
/* CHARACTER_8.lower_value */
extern T0* T2f21(TC* ac, T2 volatile* C);
/* SYSTEM_ENCODINGS.utf8 */
extern T0* T118s2(TC* ac);
/* ENCODING.make */
extern T0* T117c11(TC* ac, T0* a1);
/* ENCODING.regular_encoding_imp */
extern T0* T117f7(TC* ac, T0* C);
/* ENCODING_IMP.default_create */
extern T0* T132c43(TC* ac);
/* ENCODING.last_converted_string_8 */
extern T0* T117f6(TC* ac, T0* C);
/* ENCODING.last_converted_stream */
extern T0* T117f5(TC* ac, T0* C);
/* UNICODE_CONVERSION.last_converted_stream */
extern T0* T133f5(TC* ac, T0* C);
/* UNICODE_CONVERSION.string_general_to_stream */
extern T0* T133s7(TC* ac, T0* a1);
/* UNICODE_CONVERSION.string_32_to_multi_byte */
extern T0* T133s9(TC* ac, T0* a1);
/* STRING_8.append_code */
extern void T17f35(TC* ac, T0* C, T10 a1);
/* UNICODE_CONVERSION.is_little_endian */
extern T1 T133s10(TC* ac);
/* PLATFORM.is_little_endian */
extern T1 T126s3(TC* ac);
/* TYPED_POINTER [NATURAL_8].memory_copy */
extern void T121f5(TC* ac, T121* C, T14 a1, T6 a2);
/* TYPED_POINTER [NATURAL_8].c_memcpy */
extern void T121s6(TC* ac, T14 a1, T14 a2, T6 a3);
/* STRING_8.to_string_8 */
extern T0* T17f21(TC* ac, T0* C);
/* UNICODE_CONVERSION.string_16_to_stream */
extern T0* T133s6(TC* ac, T0* a1);
/* STRING_8.append_character */
extern void T17f46(TC* ac, T0* C, T2 a1);
/* MANAGED_POINTER.read_natural_8 */
extern T8 T85f7(TC* ac, T0* C, T6 a1);
/* UNICODE_CONVERSION.wide_string_to_pointer */
extern T0* T133s8(TC* ac, T0* a1);
/* ENCODING_IMP.last_converted_stream */
extern T0* T132f5(TC* ac, T0* C);
/* ENCODING_IMP.string_general_to_stream */
extern T0* T132s8(TC* ac, T0* a1);
/* ENCODING_IMP.string_32_to_multi_byte */
extern T0* T132s13(TC* ac, T0* a1);
/* ENCODING_IMP.is_little_endian */
extern T1 T132s18(TC* ac);
/* ENCODING_IMP.string_16_to_stream */
extern T0* T132s7(TC* ac, T0* a1);
/* ENCODING_IMP.wide_string_to_pointer */
extern T0* T132s12(TC* ac, T0* a1);
/* ENCODING.last_conversion_successful */
extern T1 T117f4(TC* ac, T0* C);
/* ENCODING.convert_to */
extern void T117f12(TC* ac, T0* C, T0* a1, T0* a2);
/* ENCODING.is_conversion_possible */
extern T1 T117f10(TC* ac, T0* C, T0* a1);
/* ENCODING_IMP.is_code_page_convertible */
extern T1 T132f4(TC* ac, T0* C, T0* a1, T0* a2);
/* CONVERSION_FAILURE.raise */
extern void T135f12(TC* ac, T0* C);
/* ENCODING_IMP.conversion_exception */
extern T0* T132f10(TC* ac, T0* C, T6 a1);
/* CONVERSION_FAILURE.make_message */
extern T0* T135c11(TC* ac, T0* a1);
/* CONVERSION_FAILURE.set_description */
extern void T135f13(TC* ac, T0* C, T0* a1);
/* ENCODING_IMP.is_codeset_convertible */
extern T1 T132f9(TC* ac, T0* C, T0* a1, T0* a2, T134 a3);
/* DESCRIPTOR_CACHE.put */
extern void T136f8(TC* ac, T0* C, T14 a1, T0* a2);
/* HASH_TABLE [POINTER, READABLE_STRING_8].force */
extern void T139f36(TC* ac, T0* C, T14 a1, T0* a2);
/* SPECIAL [POINTER].force */
extern void T145f5(TC* ac, T0* C, T14 a1, T6 a2);
/* SPECIAL [POINTER].extend */
extern void T145f7(TC* ac, T0* C, T14 a1);
/* HASH_TABLE [POINTER, READABLE_STRING_8].position */
extern T6 T139f21(TC* ac, T0* C);
/* SPECIAL [READABLE_STRING_8].force */
extern void T144f5(TC* ac, T0* C, T0* a1, T6 a2);
/* SPECIAL [READABLE_STRING_8].extend */
extern void T144f7(TC* ac, T0* C, T0* a1);
/* SPECIAL [BOOLEAN].force */
extern void T74f5(TC* ac, T0* C, T1 a1, T6 a2);
/* HASH_TABLE [POINTER, READABLE_STRING_8].deleted_position */
extern T6 T139f24(TC* ac, T0* C, T6 a1);
/* HASH_TABLE [POINTER, READABLE_STRING_8].add_space */
extern void T139f38(TC* ac, T0* C);
/* HASH_TABLE [POINTER, READABLE_STRING_8].accommodate */
extern void T139f39(TC* ac, T0* C, T6 a1);
/* HASH_TABLE [POINTER, READABLE_STRING_8].set_indexes_map */
extern void T139f43(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [POINTER, READABLE_STRING_8].set_deleted_marks */
extern void T139f42(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [POINTER, READABLE_STRING_8].set_keys */
extern void T139f41(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [POINTER, READABLE_STRING_8].set_content */
extern void T139f40(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [POINTER, READABLE_STRING_8].put */
extern void T139f44(TC* ac, T0* C, T14 a1, T0* a2);
/* HASH_TABLE [POINTER, READABLE_STRING_8].set_conflict */
extern void T139f46(TC* ac, T0* C);
/* HASH_TABLE [POINTER, READABLE_STRING_8].found */
extern T1 T139f17(TC* ac, T0* C);
/* HASH_TABLE [POINTER, READABLE_STRING_8].occupied */
extern T1 T139f30(TC* ac, T0* C, T6 a1);
/* HASH_TABLE [POINTER, READABLE_STRING_8].empty_duplicate */
extern T0* T139f29(TC* ac, T0* C, T6 a1);
/* HASH_TABLE [POINTER, READABLE_STRING_8].compare_objects */
extern void T139f45(TC* ac, T0* C);
/* HASH_TABLE [POINTER, READABLE_STRING_8].make */
extern T0* T139c34(TC* ac, T6 a1);
/* SPECIAL [READABLE_STRING_8].make_empty */
extern T0* T144c4(TC* ac, T6 a1);
/* SPECIAL [POINTER].make_empty */
extern T0* T145c4(TC* ac, T6 a1);
/* HASH_TABLE [POINTER, READABLE_STRING_8].soon_full */
extern T1 T139f23(TC* ac, T0* C);
/* HASH_TABLE [POINTER, READABLE_STRING_8].not_found */
extern T1 T139f22(TC* ac, T0* C);
/* HASH_TABLE [POINTER, READABLE_STRING_8].internal_search */
extern void T139f37(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [POINTER, READABLE_STRING_8].same_keys */
extern T1 T139f27(TC* ac, T0* C, T0* a1, T0* a2);
/* STRING_8.is_equal */
extern T1 T17f28(TC* ac, T0* C, T0* a1);
/* SPECIAL [CHARACTER_8].same_items */
extern T1 T15f6(TC* ac, T0* C, T0* a1, T6 a2, T6 a3, T6 a4);
/* HASH_TABLE [POINTER, READABLE_STRING_8].hash_code_of */
extern T6 T139f26(TC* ac, T0* C, T0* a1);
/* STRING_8.hash_code */
extern T6 T17f24(TC* ac, T0* C);
/* ENCODING_IMP.c_iconv_open */
extern T14 T132s16(TC* ac, T14 a1, T14 a2, T134 a3, T137 a4);
/* ENCODING_IMP.c_iconv_open */
extern T14 T132i16(TC* ac, T14 a1, T14 a2, T134* a3, T137* a4);
/* ENCODING_IMP.multi_byte_to_pointer */
extern T0* T132s15(TC* ac, T0* a1);
/* DESCRIPTOR_CACHE.found */
extern T1 T136f4(TC* ac, T0* C);
/* DESCRIPTOR_CACHE.search */
extern void T136f7(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [POINTER, READABLE_STRING_8].search */
extern void T139f35(TC* ac, T0* C, T0* a1);
/* ENCODING_IMP.descriptor_cache */
extern T0* T132f14(TC* ac, T0* C);
/* DESCRIPTOR_CACHE.make */
extern T0* T136c6(TC* ac);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].make */
extern T0* T140c35(TC* ac, T6 a1);
/* STRING_8.plus */
extern T0* T17f12(TC* ac, T0* C, T0* a1);
/* STRING_8.append */
extern void T17f33(TC* ac, T0* C, T0* a1);
/* ENCODING.is_valid */
extern T1 T117f9(TC* ac, T0* C);
/* ENCODING_IMP.is_code_page_valid */
extern T1 T132f6(TC* ac, T0* C, T0* a1);
/* ENCODING_IMP.is_known_code_page */
extern T1 T132f11(TC* ac, T0* C, T0* a1);
/* ENCODING_IMP.c_codeset_valid */
extern T1 T132f17(TC* ac, T0* C, T0* a1, T134 a2);
/* STRING_8.is_empty */
extern T1 T17f19(TC* ac, T0* C);
/* UNICODE_CONVERSION.convert_to */
extern void T133f17(TC* ac, T0* C, T0* a1, T0* a2, T0* a3);
/* UNICODE_CONVERSION.utf16_to_utf32 */
extern T0* T133s14(TC* ac, T0* a1);
/* STRING_32.append_code */
extern void T18f27(TC* ac, T0* C, T10 a1);
/* STRING_32.resize */
extern void T18f25(TC* ac, T0* C, T6 a1);
/* SPECIAL [CHARACTER_32].aliased_resized_area_with_default */
extern T0* T16f5(TC* ac, T0* C, T3 a1, T6 a2);
/* SPECIAL [CHARACTER_32].aliased_resized_area */
extern T0* T16f6(TC* ac, T0* C, T6 a1);
/* STRING_32.capacity */
extern T6 T18f15(TC* ac, T0* C);
/* NATURAL_32.is_greater_equal */
extern T1 T10f26(TC* ac, T10 volatile* C, T10 a1);
/* UNICODE_CONVERSION.utf32_to_utf16 */
extern T0* T133s13(TC* ac, T0* a1);
/* UNICODE_CONVERSION.utf32_to_utf8 */
extern T0* T133f12(TC* ac, T0* C, T0* a1);
/* UNICODE_CONVERSION.utf8_to_utf32 */
extern T0* T133f11(TC* ac, T0* C, T0* a1);
/* UTF_CONVERTER.utf_8_string_8_to_string_32 */
extern T0* T83s11(TC* ac, T0* a1);
/* UTF_CONVERTER.utf_8_string_8_into_string_32 */
extern void T83s18(TC* ac, T0* a1, T0* a2);
/* STRING_32.extend */
extern void T18f29(TC* ac, T0* C, T3 a1);
/* STRING_32.additional_space */
extern T6 T18f16(TC* ac, T0* C);
/* STRING_32.grow */
extern void T18f28(TC* ac, T0* C, T6 a1);
/* ENCODING_IMP.convert_to */
extern void T132f45(TC* ac, T0* C, T0* a1, T0* a2, T0* a3);
extern T1 T132f45ot1(TC* ac, T0* a1);
/* ENCODING_IMP.pointer_to_multi_byte */
extern T0* T132s36(TC* ac, T14 a1, T6 a2);
/* NATURAL_8.to_natural_32 */
extern T10 T8f12(TC* ac, T8 volatile* C);
/* ENCODING_IMP.string_16_switch_endian */
extern T0* T132s35(TC* ac, T0* a1);
/* ENCODING_IMP.pointer_to_wide_string */
extern T0* T132s34(TC* ac, T14 a1, T6 a2);
/* NATURAL_16.to_natural_32 */
extern T10 T9f9(TC* ac, T9 volatile* C);
/* MANAGED_POINTER.read_natural_16 */
extern T9 T85f9(TC* ac, T0* C, T6 a1);
/* TYPED_POINTER [NATURAL_16].memory_copy */
extern void T128f5(TC* ac, T128* C, T14 a1, T6 a2);
/* TYPED_POINTER [NATURAL_16].c_memcpy */
extern void T128s6(TC* ac, T14 a1, T14 a2, T6 a3);
/* ENCODING_IMP.is_endianness_specified */
extern T1 T132f33(TC* ac, T0* C, T0* a1);
/* ENCODING_IMP.reverse_endian */
extern T1 T132f32(TC* ac, T0* C, T10 a1);
/* ENCODING_IMP.string_32_switch_endian */
extern T0* T132s31(TC* ac, T0* a1);
/* STRING_32.substring */
extern T0* T18f13(TC* ac, T0* C, T6 a1, T6 a2);
/* SPECIAL [CHARACTER_32].copy_data */
extern void T16f12(TC* ac, T0* C, T0* a1, T6 a2, T6 a3, T6 a4);
/* SPECIAL [CHARACTER_32].force */
extern void T16f15(TC* ac, T0* C, T3 a1, T6 a2);
/* SPECIAL [CHARACTER_32].move_data */
extern void T16f14(TC* ac, T0* C, T6 a1, T6 a2, T6 a3);
/* SPECIAL [CHARACTER_32].overlapping_move */
extern void T16f13(TC* ac, T0* C, T6 a1, T6 a2, T6 a3);
/* SPECIAL [CHARACTER_32].non_overlapping_move */
extern void T16f16(TC* ac, T0* C, T6 a1, T6 a2, T6 a3);
/* STRING_32.new_string */
extern T0* T18f14(TC* ac, T0* C, T6 a1);
/* ENCODING_IMP.same_endian */
extern T1 T132f30(TC* ac, T0* C, T10 a1);
/* STRING_32.is_empty */
extern T1 T18f12(TC* ac, T0* C);
/* ENCODING_IMP.pointer_to_string_32 */
extern T0* T132s29(TC* ac, T14 a1, T6 a2);
/* MANAGED_POINTER.read_natural_32 */
extern T10 T85f8(TC* ac, T0* C, T6 a1);
/* TYPED_POINTER [NATURAL_32].memory_copy */
extern void T141f4(TC* ac, T141* C, T14 a1, T6 a2);
/* TYPED_POINTER [NATURAL_32].c_memcpy */
extern void T141s6(TC* ac, T14 a1, T14 a2, T6 a3);
/* ENCODING_IMP.iconv_imp */
extern T14 T132f27(TC* ac, T0* C, T0* a1, T0* a2, T14 a3, T6 a4, T134 a5, T134 a6);
/* DESCRIPTOR_CACHE.record_converted_pair */
extern void T136f9(TC* ac, T0* C, T0* a1, T0* a2);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].force */
extern void T140f36(TC* ac, T0* C, T0* a1, T0* a2);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].position */
extern T6 T140f26(TC* ac, T0* C);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].deleted_position */
extern T6 T140f25(TC* ac, T0* C, T6 a1);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].add_space */
extern void T140f38(TC* ac, T0* C);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].accommodate */
extern void T140f39(TC* ac, T0* C, T6 a1);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].set_indexes_map */
extern void T140f43(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].set_deleted_marks */
extern void T140f42(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].set_keys */
extern void T140f41(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].set_content */
extern void T140f40(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].put */
extern void T140f44(TC* ac, T0* C, T0* a1, T0* a2);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].set_conflict */
extern void T140f46(TC* ac, T0* C);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].found */
extern T1 T140f32(TC* ac, T0* C);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].occupied */
extern T1 T140f30(TC* ac, T0* C, T6 a1);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].empty_duplicate */
extern T0* T140f29(TC* ac, T0* C, T6 a1);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].compare_objects */
extern void T140f45(TC* ac, T0* C);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].soon_full */
extern T1 T140f24(TC* ac, T0* C);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].not_found */
extern T1 T140f23(TC* ac, T0* C);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].internal_search */
extern void T140f37(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].same_keys */
extern T1 T140f22(TC* ac, T0* C, T0* a1, T0* a2);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].hash_code_of */
extern T6 T140f21(TC* ac, T0* C, T0* a1);
/* ENCODING_IMP.c_iconv */
extern T14 T132s42(TC* ac, T14 a1, T14 a2, T6 a3, T134 a4, T134 a5);
/* ENCODING_IMP.c_iconv */
extern T14 T132i42(TC* ac, T14 a1, T14 a2, T6 a3, T134* a4, T134* a5);
/* DESCRIPTOR_CACHE.found_item */
extern T14 T136f3(TC* ac, T0* C);
/* ENCODING_IMP.byte_order_mark_16_reverse */
extern T3 T132f26(TC* ac, T0* C);
/* ENCODING_IMP.is_two_byte_code_page */
extern T1 T132f25(TC* ac, T0* C, T0* a1);
/* STRING_TABLE [READABLE_STRING_8].has */
extern T1 T138f24(TC* ac, T0* C, T0* a1);
/* STRING_TABLE [READABLE_STRING_8].same_keys */
extern T1 T138f34(TC* ac, T0* C, T0* a1, T0* a2);
/* STRING_8.same_string_general */
extern T1 T17f27(TC* ac, T0* C, T0* a1);
/* STRING_8.same_characters_general */
extern T1 T17f30(TC* ac, T0* C, T0* a1, T6 a2, T6 a3, T6 a4);
/* STRING_8.is_case_insensitive_equal_general */
extern T1 T17f26(TC* ac, T0* C, T0* a1);
/* STRING_8.same_caseless_characters_general */
extern T1 T17f29(TC* ac, T0* C, T0* a1, T6 a2, T6 a3, T6 a4);
/* CHARACTER_PROPERTY.to_lower */
extern T3 T146f1(TC* ac, T0* C, T3 a1);
/* CHARACTER_PROPERTY.to_lower_table_16 */
extern T0* T146f18(TC* ac, T0* C);
/* CHARACTER_PROPERTY.to_lower_table_15 */
extern T0* T146f17(TC* ac, T0* C);
/* CHARACTER_PROPERTY.to_lower_table_14 */
extern T0* T146f16(TC* ac, T0* C);
/* CHARACTER_PROPERTY.to_lower_table_13 */
extern T0* T146f15(TC* ac, T0* C);
/* CHARACTER_PROPERTY.to_lower_table_12 */
extern T0* T146f14(TC* ac, T0* C);
/* CHARACTER_PROPERTY.to_lower_table_11 */
extern T0* T146f13(TC* ac, T0* C);
/* CHARACTER_PROPERTY.to_lower_table_10 */
extern T0* T146f12(TC* ac, T0* C);
/* CHARACTER_PROPERTY.to_lower_table_9 */
extern T0* T146f11(TC* ac, T0* C);
/* CHARACTER_PROPERTY.to_lower_table_8 */
extern T0* T146f10(TC* ac, T0* C);
/* CHARACTER_PROPERTY.to_lower_table_7 */
extern T0* T146f9(TC* ac, T0* C);
/* CHARACTER_PROPERTY.to_lower_table_6 */
extern T0* T146f8(TC* ac, T0* C);
/* CHARACTER_PROPERTY.to_lower_table_5 */
extern T0* T146f7(TC* ac, T0* C);
/* CHARACTER_PROPERTY.to_lower_table_4 */
extern T0* T146f6(TC* ac, T0* C);
/* CHARACTER_PROPERTY.to_lower_table_3 */
extern T0* T146f5(TC* ac, T0* C);
/* CHARACTER_PROPERTY.to_lower_table_2 */
extern T0* T146f4(TC* ac, T0* C);
/* NATURAL_32.to_integer_32 */
extern T6 T10f27(TC* ac, T10 volatile* C);
/* CHARACTER_PROPERTY.to_lower_table_1 */
extern T0* T146f3(TC* ac, T0* C);
/* CHARACTER_32.plus */
extern T3 T3f9(TC* ac, T3 volatile* C, T10 a1);
/* CHARACTER_32.is_less_equal */
extern T1 T3f8(TC* ac, T3 volatile* C, T3 a1);
/* CHARACTER_32.is_less */
extern T1 T3f10(TC* ac, T3 volatile* C, T3 a1);
/* STRING_8.character_properties */
extern T0* T17f25(TC* ac, T0* C);
/* CHARACTER_PROPERTY.make */
extern T0* T146c19(TC* ac);
/* STRING_TABLE [READABLE_STRING_8].hash_code_of */
extern T6 T138f25(TC* ac, T0* C, T0* a1);
/* STRING_8.case_insensitive_hash_code */
extern T6 T17f23(TC* ac, T0* C);
/* ENCODING_IMP.two_byte_code_pages */
extern T0* T132f41(TC* ac, T0* C);
/* STRING_TABLE [READABLE_STRING_8].put */
extern void T138f36(TC* ac, T0* C, T0* a1, T0* a2);
/* SPECIAL [READABLE_STRING_GENERAL].force */
extern void T143f5(TC* ac, T0* C, T0* a1, T6 a2);
/* SPECIAL [READABLE_STRING_GENERAL].extend */
extern void T143f7(TC* ac, T0* C, T0* a1);
/* STRING_TABLE [READABLE_STRING_8].deleted_position */
extern T6 T138f19(TC* ac, T0* C, T6 a1);
/* STRING_TABLE [READABLE_STRING_8].add_space */
extern void T138f40(TC* ac, T0* C);
/* STRING_TABLE [READABLE_STRING_8].accommodate */
extern void T138f41(TC* ac, T0* C, T6 a1);
/* STRING_TABLE [READABLE_STRING_8].set_indexes_map */
extern void T138f45(TC* ac, T0* C, T0* a1);
/* STRING_TABLE [READABLE_STRING_8].set_deleted_marks */
extern void T138f44(TC* ac, T0* C, T0* a1);
/* STRING_TABLE [READABLE_STRING_8].set_keys */
extern void T138f43(TC* ac, T0* C, T0* a1);
/* STRING_TABLE [READABLE_STRING_8].set_content */
extern void T138f42(TC* ac, T0* C, T0* a1);
/* STRING_TABLE [READABLE_STRING_8].occupied */
extern T1 T138f33(TC* ac, T0* C, T6 a1);
/* STRING_TABLE [READABLE_STRING_8].empty_duplicate */
extern T0* T138f32(TC* ac, T0* C, T6 a1);
/* STRING_TABLE [READABLE_STRING_8].compare_objects */
extern void T138f46(TC* ac, T0* C);
/* STRING_TABLE [READABLE_STRING_8].make */
extern void T138f37(TC* ac, T0* C, T6 a1);
/* STRING_TABLE [READABLE_STRING_8].make */
extern T0* T138c37(TC* ac, T6 a1);
/* SPECIAL [READABLE_STRING_GENERAL].make_empty */
extern T0* T143c4(TC* ac, T6 a1);
/* STRING_TABLE [READABLE_STRING_8].soon_full */
extern T1 T138f28(TC* ac, T0* C);
/* STRING_TABLE [READABLE_STRING_8].position */
extern T6 T138f27(TC* ac, T0* C);
/* STRING_TABLE [READABLE_STRING_8].set_conflict */
extern void T138f39(TC* ac, T0* C);
/* STRING_TABLE [READABLE_STRING_8].found */
extern T1 T138f21(TC* ac, T0* C);
/* STRING_TABLE [READABLE_STRING_8].internal_search */
extern void T138f38(TC* ac, T0* C, T0* a1);
/* STRING_TABLE [READABLE_STRING_8].make_caseless */
extern T0* T138c35(TC* ac, T6 a1);
/* ENCODING_IMP.string_32_to_pointer */
extern T0* T132f24(TC* ac, T0* C, T0* a1);
/* MANAGED_POINTER.put_natural_32 */
extern void T85f18(TC* ac, T0* C, T10 a1, T6 a2);
/* STRING_32.precede */
extern void T18f23(TC* ac, T0* C, T3 a1);
/* ENCODING_IMP.byte_order_mark_32_reverse */
extern T3 T132f23(TC* ac, T0* C);
/* ENCODING_IMP.byte_order_mark */
extern T3 T132f22(TC* ac, T0* C);
/* DESCRIPTOR_CACHE.converted */
extern T1 T136f5(TC* ac, T0* C, T0* a1, T0* a2);
/* HASH_TABLE [READABLE_STRING_8, READABLE_STRING_8].has */
extern T1 T140f19(TC* ac, T0* C, T0* a1);
/* STRING_32.twin */
extern T0* T18f10(TC* ac, T0* C);
/* STRING_32.copy */
extern void T18f24(TC* ac, T0* C, T0* a1);
/* SPECIAL [CHARACTER_32].resized_area */
extern T0* T16f4(TC* ac, T0* C, T6 a1);
/* ENCODING_IMP.is_four_byte_code_page */
extern T1 T132f21(TC* ac, T0* C, T0* a1);
/* ENCODING_IMP.four_byte_code_pages */
extern T0* T132f40(TC* ac, T0* C);
/* ENCODING_IMP.is_little_endian_code_page */
extern T1 T132f20(TC* ac, T0* C, T0* a1);
/* ENCODING_IMP.little_endian_code_pages */
extern T0* T132f39(TC* ac, T0* C);
/* ENCODING_IMP.is_big_endian_code_page */
extern T1 T132f19(TC* ac, T0* C, T0* a1);
/* ENCODING_IMP.big_endian_code_pages */
extern T0* T132f38(TC* ac, T0* C);
/* CONVERSION_FAILURE.original */
extern T0* T135f9(TC* ac, T0* C);
/* NO_MORE_MEMORY.original */
extern T0* T47f10(TC* ac, T0* C);
/* SERIALIZATION_FAILURE.original */
extern T0* T71f10(TC* ac, T0* C);
/* OLD_VIOLATION.original */
extern T0* T45f10(TC* ac, T0* C);
/* COM_FAILURE.original */
extern T0* T52f11(TC* ac, T0* C);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.original */
extern T0* T70f10(TC* ac, T0* C);
/* DEVELOPER_EXCEPTION.original */
extern T0* T69f10(TC* ac, T0* C);
/* MISMATCH_FAILURE.original */
extern T0* T68f10(TC* ac, T0* C);
/* OPERATING_SYSTEM_FAILURE.original */
extern T0* T51f10(TC* ac, T0* C);
/* IO_FAILURE.original */
extern T0* T50f10(TC* ac, T0* C);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.original */
extern T0* T67f10(TC* ac, T0* C);
/* VOID_ASSIGNED_TO_EXPANDED.original */
extern T0* T66f10(TC* ac, T0* C);
/* EXTERNAL_FAILURE.original */
extern T0* T65f10(TC* ac, T0* C);
/* CREATE_ON_DEFERRED.original */
extern T0* T64f10(TC* ac, T0* C);
/* RESUMPTION_FAILURE.original */
extern T0* T63f10(TC* ac, T0* C);
/* RESCUE_FAILURE.original */
extern T0* T62f10(TC* ac, T0* C);
/* EIFFEL_RUNTIME_PANIC.original */
extern T0* T53f10(TC* ac, T0* C);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.original */
extern T0* T49f10(TC* ac, T0* C);
/* LOOP_INVARIANT_VIOLATION.original */
extern T0* T61f10(TC* ac, T0* C);
/* VARIANT_VIOLATION.original */
extern T0* T60f10(TC* ac, T0* C);
/* BAD_INSPECT_VALUE.original */
extern T0* T59f10(TC* ac, T0* C);
/* ROUTINE_FAILURE.original */
extern T0* T43f10(TC* ac, T0* C);
/* CHECK_VIOLATION.original */
extern T0* T58f10(TC* ac, T0* C);
/* INVARIANT_VIOLATION.original */
extern T0* T48f10(TC* ac, T0* C);
/* FLOATING_POINT_FAILURE.original */
extern T0* T57f10(TC* ac, T0* C);
/* POSTCONDITION_VIOLATION.original */
extern T0* T56f10(TC* ac, T0* C);
/* PRECONDITION_VIOLATION.original */
extern T0* T55f10(TC* ac, T0* C);
/* VOID_TARGET.original */
extern T0* T41f10(TC* ac, T0* C);
/* ENCODING_IMP.exception_manager */
extern T0* T132s37(TC* ac);
/* POINTER.memory_free */
extern void T14f11(TC* ac, T14 volatile* C);
/* POINTER.default_pointer */
extern T14 T14s9(TC* ac);
/* POINTER.c_free */
extern void T14s14(TC* ac, T14 a1);
/* ENCODING_IMP.default_pointer */
extern T14 T132s28(TC* ac);
/* UNICODE_CONVERSION.reset */
extern void T133f16(TC* ac, T0* C);
/* ENCODING_IMP.reset */
extern void T132f44(TC* ac, T0* C);
/* UNICODE_CONVERSION.is_code_page_convertible */
extern T1 T133f4(TC* ac, T0* C, T0* a1, T0* a2);
/* ENCODING.unicode_conversion */
extern T0* T117f8(TC* ac, T0* C);
/* UNICODE_CONVERSION.default_create */
extern T0* T133c15(TC* ac);
/* SYSTEM_ENCODINGS.utf32 */
extern T0* T118s1(TC* ac);
/* CONSOLE.encoding */
extern T0* T78f14(TC* ac, T0* C);
/* CONSOLE.default_encoding */
extern T0* T78f23(TC* ac, T0* C);
/* SYSTEM_ENCODINGS.console_encoding */
extern T0* T118s3(TC* ac);
/* SYSTEM_ENCODINGS_IMP.console_code_page */
extern T0* T125f1(TC* ac, T0* C);
/* SYSTEM_ENCODINGS_IMP.system_code_page */
extern T0* T125f3(TC* ac, T0* C);
/* SYSTEM_ENCODINGS_IMP.pointer_to_multi_byte */
extern T0* T125s6(TC* ac, T14 a1, T6 a2);
/* SYSTEM_ENCODINGS_IMP.c_strlen */
extern T6 T125s5(TC* ac, T14 a1);
/* SYSTEM_ENCODINGS_IMP.c_current_codeset */
extern T14 T125s4(TC* ac);
/* SYSTEM_ENCODINGS_IMP.c_current_codeset */
extern T14 T125i4(TC* ac);
/* SYSTEM_ENCODINGS_IMP.is_utf8_activated */
extern T1 T125s2(TC* ac);
/* SYSTEM_ENCODINGS_IMP.is_utf8_activated */
extern T1 T125i2(TC* ac);
/* SYSTEM_ENCODINGS.system_encodings_i */
extern T0* T118s4(TC* ac);
/* SYSTEM_ENCODINGS_IMP.default_create */
extern T0* T125c7(TC* ac);
/* ESTUFA.io */
extern T0* T33s6(TC* ac);
/* STD_FILES.set_output_default */
extern void T34f12(TC* ac, T0* C);
/* STD_FILES.default_create */
extern T0* T34c7(TC* ac);
/* REAL_32.out */
extern T0* T12f4(TC* ac, T12 volatile* C);
/* STRING_8.out */
extern T0* T17f6(TC* ac, T0* C);
/* STRING_8.append_string_general */
extern void T17f32(TC* ac, T0* C, T0* a1);
/* STRING_8.append */
extern void T17f32p1(TC* ac, T0* C, T0* a1);
/* ESTUFA.monitorar */
extern void T33f8(TC* ac, T0* C);
/* CONTROLADOR.verificar_temperatura */
extern void T76f4(TC* ac, T0* C, T12 a1);
/* CONTROLADOR.print */
extern void T76s5(TC* ac, T0* a1);
/* CONTROLADOR.io */
extern T0* T76s1(TC* ac);
/* REAL_32.is_greater */
extern T1 T12f6(TC* ac, T12 volatile* C, T12 a1);
/* CONTROLADOR.controlar_umidade */
extern void T76f3(TC* ac, T0* C, T12 a1, T0* a2);
/* IRRIGACAO.desligar */
extern void T75f4(TC* ac, T0* C);
/* IRRIGACAO.ligar */
extern void T75f3(TC* ac, T0* C);
/* SENSOR_UMIDADE.set_valor */
extern void T36f4(TC* ac, T0* C, T12 a1);
/* SENSOR_TEMPERATURA.set_valor */
extern void T35f4(TC* ac, T0* C, T12 a1);
/* STD_FILES.last_real */
extern T12 T34s2(TC* ac);
/* STD_FILES.input */
extern T0* T34s3(TC* ac);
/* CONSOLE.make_open_stdin */
extern T0* T78c27(TC* ac, T0* a1);
/* CONSOLE.set_read_mode */
extern void T78f34(TC* ac, T0* C);
/* STD_FILES.read_real */
extern void T34s9(TC* ac);
/* CONSOLE.read_real */
extern void T78f29(TC* ac, T0* C);
/* CONSOLE.console_readreal */
extern T12 T78s22(TC* ac, T14 a1);
/* STD_FILES.last_integer */
extern T6 T34s5(TC* ac);
/* STD_FILES.read_integer */
extern void T34s8(TC* ac);
/* CONSOLE.read_integer */
extern void T78f28(TC* ac, T0* C);
/* STRING_TO_INTEGER_CONVERTOR.parsed_integer_32 */
extern T6 T112f11(TC* ac, T0* C);
/* CONSOLE.ctoi_convertor */
extern T0* T78f16(TC* ac, T0* C);
/* STRING_TO_INTEGER_CONVERTOR.set_trailing_separators_acceptable */
extern void T112f21(TC* ac, T0* C, T1 a1);
/* STRING_TO_INTEGER_CONVERTOR.set_leading_separators_acceptable */
extern void T112f20(TC* ac, T0* C, T1 a1);
/* STRING_TO_INTEGER_CONVERTOR.set_leading_separators */
extern void T112f19(TC* ac, T0* C, T0* a1);
/* STRING_TO_INTEGER_CONVERTOR.make */
extern T0* T112c16(TC* ac);
/* STRING_TO_INTEGER_CONVERTOR.reset */
extern void T112f17(TC* ac, T0* C, T6 a1);
/* CONSOLE.read_integer_with_no_type */
extern void T78f35(TC* ac, T0* C);
/* CONSOLE.consume_characters */
extern void T78f41(TC* ac, T0* C);
/* CONSOLE.read_character */
extern void T78f42(TC* ac, T0* C);
/* CONSOLE.console_readchar */
extern T2 T78s21(TC* ac, T14 a1);
/* CONSOLE.end_of_file */
extern T1 T78f19(TC* ac, T0* C);
/* CONSOLE.console_eof */
extern T1 T78s25(TC* ac, T14 a1);
/* CONSOLE.read_number_sequence */
extern void T78f40(TC* ac, T0* C, T0* a1, T6 a2);
/* STRING_TO_INTEGER_CONVERTOR.parse_successful */
extern T1 T112f12(TC* ac, T0* C);
/* STRING_TO_INTEGER_CONVERTOR.parse_character */
extern void T112f18(TC* ac, T0* C, T2 a1);
/* STRING_TO_INTEGER_CONVERTOR.overflowed */
extern T1 T112f14(TC* ac, T0* C);
/* STRING_TO_INTEGER_CONVERTOR.overflow_checker */
extern T0* T112f13(TC* ac, T0* C);
/* CHARACTER_8.is_digit */
extern T1 T2f6(TC* ac, T2 volatile* C);
/* APPLICATION.io */
extern T0* T26s1(TC* ac);
/* APPLICATION.print */
extern void T26s3(TC* ac, T0* a1);
/* ESTUFA.make */
extern T0* T33c7(TC* ac, T0* a1);
/* CONTROLADOR.make */
extern T0* T76c2(TC* ac);
/* IRRIGACAO.make */
extern T0* T75c2(TC* ac);
/* SENSOR_UMIDADE.make */
extern T0* T36c3(TC* ac);
/* SENSOR_TEMPERATURA.make */
extern T0* T35c3(TC* ac);
/* ISE_EXCEPTION_MANAGER.set_exception_data */
extern void T21s16(TC* ac, T6 a1, T1 a2, T6 a3, T6 a4, T0* a5, T0* a6, T0* a7, T0* a8, T0* a9, T0* a10, T6 a11, T1 a12);
/* CONVERSION_FAILURE.set_type_name */
extern void T135f17(TC* ac, T0* C, T0* a1);
/* NO_MORE_MEMORY.set_type_name */
extern void T47f18(TC* ac, T0* C, T0* a1);
/* SERIALIZATION_FAILURE.set_type_name */
extern void T71f16(TC* ac, T0* C, T0* a1);
/* OLD_VIOLATION.set_type_name */
extern void T45f16(TC* ac, T0* C, T0* a1);
/* COM_FAILURE.set_type_name */
extern void T52f24(TC* ac, T0* C, T0* a1);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_type_name */
extern void T70f16(TC* ac, T0* C, T0* a1);
/* DEVELOPER_EXCEPTION.set_type_name */
extern void T69f16(TC* ac, T0* C, T0* a1);
/* MISMATCH_FAILURE.set_type_name */
extern void T68f16(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_FAILURE.set_type_name */
extern void T51f18(TC* ac, T0* C, T0* a1);
/* IO_FAILURE.set_type_name */
extern void T50f20(TC* ac, T0* C, T0* a1);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_type_name */
extern void T67f16(TC* ac, T0* C, T0* a1);
/* VOID_ASSIGNED_TO_EXPANDED.set_type_name */
extern void T66f16(TC* ac, T0* C, T0* a1);
/* EXTERNAL_FAILURE.set_type_name */
extern void T65f16(TC* ac, T0* C, T0* a1);
/* CREATE_ON_DEFERRED.set_type_name */
extern void T64f16(TC* ac, T0* C, T0* a1);
/* RESUMPTION_FAILURE.set_type_name */
extern void T63f16(TC* ac, T0* C, T0* a1);
/* RESCUE_FAILURE.set_type_name */
extern void T62f16(TC* ac, T0* C, T0* a1);
/* EIFFEL_RUNTIME_PANIC.set_type_name */
extern void T53f18(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_type_name */
extern void T49f18(TC* ac, T0* C, T0* a1);
/* LOOP_INVARIANT_VIOLATION.set_type_name */
extern void T61f16(TC* ac, T0* C, T0* a1);
/* VARIANT_VIOLATION.set_type_name */
extern void T60f16(TC* ac, T0* C, T0* a1);
/* BAD_INSPECT_VALUE.set_type_name */
extern void T59f16(TC* ac, T0* C, T0* a1);
/* ROUTINE_FAILURE.set_type_name */
extern void T43f20(TC* ac, T0* C, T0* a1);
/* CHECK_VIOLATION.set_type_name */
extern void T58f16(TC* ac, T0* C, T0* a1);
/* INVARIANT_VIOLATION.set_type_name */
extern void T48f18(TC* ac, T0* C, T0* a1);
/* FLOATING_POINT_FAILURE.set_type_name */
extern void T57f16(TC* ac, T0* C, T0* a1);
/* POSTCONDITION_VIOLATION.set_type_name */
extern void T56f16(TC* ac, T0* C, T0* a1);
/* PRECONDITION_VIOLATION.set_type_name */
extern void T55f16(TC* ac, T0* C, T0* a1);
/* VOID_TARGET.set_type_name */
extern void T41f16(TC* ac, T0* C, T0* a1);
/* CONVERSION_FAILURE.set_recipient_name */
extern void T135f16(TC* ac, T0* C, T0* a1);
/* NO_MORE_MEMORY.set_recipient_name */
extern void T47f17(TC* ac, T0* C, T0* a1);
/* SERIALIZATION_FAILURE.set_recipient_name */
extern void T71f15(TC* ac, T0* C, T0* a1);
/* OLD_VIOLATION.set_recipient_name */
extern void T45f15(TC* ac, T0* C, T0* a1);
/* COM_FAILURE.set_recipient_name */
extern void T52f23(TC* ac, T0* C, T0* a1);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_recipient_name */
extern void T70f15(TC* ac, T0* C, T0* a1);
/* DEVELOPER_EXCEPTION.set_recipient_name */
extern void T69f15(TC* ac, T0* C, T0* a1);
/* MISMATCH_FAILURE.set_recipient_name */
extern void T68f15(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_FAILURE.set_recipient_name */
extern void T51f17(TC* ac, T0* C, T0* a1);
/* IO_FAILURE.set_recipient_name */
extern void T50f19(TC* ac, T0* C, T0* a1);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_recipient_name */
extern void T67f15(TC* ac, T0* C, T0* a1);
/* VOID_ASSIGNED_TO_EXPANDED.set_recipient_name */
extern void T66f15(TC* ac, T0* C, T0* a1);
/* EXTERNAL_FAILURE.set_recipient_name */
extern void T65f15(TC* ac, T0* C, T0* a1);
/* CREATE_ON_DEFERRED.set_recipient_name */
extern void T64f15(TC* ac, T0* C, T0* a1);
/* RESUMPTION_FAILURE.set_recipient_name */
extern void T63f15(TC* ac, T0* C, T0* a1);
/* RESCUE_FAILURE.set_recipient_name */
extern void T62f15(TC* ac, T0* C, T0* a1);
/* EIFFEL_RUNTIME_PANIC.set_recipient_name */
extern void T53f17(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_recipient_name */
extern void T49f17(TC* ac, T0* C, T0* a1);
/* LOOP_INVARIANT_VIOLATION.set_recipient_name */
extern void T61f15(TC* ac, T0* C, T0* a1);
/* VARIANT_VIOLATION.set_recipient_name */
extern void T60f15(TC* ac, T0* C, T0* a1);
/* BAD_INSPECT_VALUE.set_recipient_name */
extern void T59f15(TC* ac, T0* C, T0* a1);
/* ROUTINE_FAILURE.set_recipient_name */
extern void T43f19(TC* ac, T0* C, T0* a1);
/* CHECK_VIOLATION.set_recipient_name */
extern void T58f15(TC* ac, T0* C, T0* a1);
/* INVARIANT_VIOLATION.set_recipient_name */
extern void T48f17(TC* ac, T0* C, T0* a1);
/* FLOATING_POINT_FAILURE.set_recipient_name */
extern void T57f15(TC* ac, T0* C, T0* a1);
/* POSTCONDITION_VIOLATION.set_recipient_name */
extern void T56f15(TC* ac, T0* C, T0* a1);
/* PRECONDITION_VIOLATION.set_recipient_name */
extern void T55f15(TC* ac, T0* C, T0* a1);
/* VOID_TARGET.set_recipient_name */
extern void T41f15(TC* ac, T0* C, T0* a1);
/* CONVERSION_FAILURE.set_exception_trace */
extern void T135f15(TC* ac, T0* C, T0* a1);
/* NO_MORE_MEMORY.set_exception_trace */
extern void T47f13(TC* ac, T0* C, T0* a1);
/* SERIALIZATION_FAILURE.set_exception_trace */
extern void T71f13(TC* ac, T0* C, T0* a1);
/* OLD_VIOLATION.set_exception_trace */
extern void T45f13(TC* ac, T0* C, T0* a1);
/* COM_FAILURE.set_exception_trace */
extern void T52f21(TC* ac, T0* C, T0* a1);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_exception_trace */
extern void T70f13(TC* ac, T0* C, T0* a1);
/* DEVELOPER_EXCEPTION.set_exception_trace */
extern void T69f13(TC* ac, T0* C, T0* a1);
/* MISMATCH_FAILURE.set_exception_trace */
extern void T68f13(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_FAILURE.set_exception_trace */
extern void T51f15(TC* ac, T0* C, T0* a1);
/* IO_FAILURE.set_exception_trace */
extern void T50f17(TC* ac, T0* C, T0* a1);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_exception_trace */
extern void T67f13(TC* ac, T0* C, T0* a1);
/* VOID_ASSIGNED_TO_EXPANDED.set_exception_trace */
extern void T66f13(TC* ac, T0* C, T0* a1);
/* EXTERNAL_FAILURE.set_exception_trace */
extern void T65f13(TC* ac, T0* C, T0* a1);
/* CREATE_ON_DEFERRED.set_exception_trace */
extern void T64f13(TC* ac, T0* C, T0* a1);
/* RESUMPTION_FAILURE.set_exception_trace */
extern void T63f13(TC* ac, T0* C, T0* a1);
/* RESCUE_FAILURE.set_exception_trace */
extern void T62f13(TC* ac, T0* C, T0* a1);
/* EIFFEL_RUNTIME_PANIC.set_exception_trace */
extern void T53f15(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_exception_trace */
extern void T49f15(TC* ac, T0* C, T0* a1);
/* LOOP_INVARIANT_VIOLATION.set_exception_trace */
extern void T61f13(TC* ac, T0* C, T0* a1);
/* VARIANT_VIOLATION.set_exception_trace */
extern void T60f13(TC* ac, T0* C, T0* a1);
/* BAD_INSPECT_VALUE.set_exception_trace */
extern void T59f13(TC* ac, T0* C, T0* a1);
/* ROUTINE_FAILURE.set_exception_trace */
extern void T43f17(TC* ac, T0* C, T0* a1);
/* CHECK_VIOLATION.set_exception_trace */
extern void T58f13(TC* ac, T0* C, T0* a1);
/* INVARIANT_VIOLATION.set_exception_trace */
extern void T48f15(TC* ac, T0* C, T0* a1);
/* FLOATING_POINT_FAILURE.set_exception_trace */
extern void T57f13(TC* ac, T0* C, T0* a1);
/* POSTCONDITION_VIOLATION.set_exception_trace */
extern void T56f13(TC* ac, T0* C, T0* a1);
/* PRECONDITION_VIOLATION.set_exception_trace */
extern void T55f13(TC* ac, T0* C, T0* a1);
/* VOID_TARGET.set_exception_trace */
extern void T41f13(TC* ac, T0* C, T0* a1);
/* ISE_EXCEPTION_MANAGER.exception_from_data */
extern T0* T21s10(TC* ac);
extern T1 T21s10ot1(TC* ac, T0* a1);
extern T1 T21s10ot2(TC* ac, T0* a1);
extern T1 T21s10ot3(TC* ac, T0* a1);
extern T1 T21s10ot4(TC* ac, T0* a1);
extern T1 T21s10ot5(TC* ac, T0* a1);
extern T1 T21s10ot6(TC* ac, T0* a1);
extern T1 T21s10ot7(TC* ac, T0* a1);
/* NO_MORE_MEMORY.set_description */
extern void T47f16(TC* ac, T0* C, T0* a1);
/* SERIALIZATION_FAILURE.set_description */
extern void T71f14(TC* ac, T0* C, T0* a1);
/* OLD_VIOLATION.set_description */
extern void T45f14(TC* ac, T0* C, T0* a1);
/* COM_FAILURE.set_description */
extern void T52f22(TC* ac, T0* C, T0* a1);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_description */
extern void T70f14(TC* ac, T0* C, T0* a1);
/* MISMATCH_FAILURE.set_description */
extern void T68f14(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_FAILURE.set_description */
extern void T51f16(TC* ac, T0* C, T0* a1);
/* IO_FAILURE.set_description */
extern void T50f18(TC* ac, T0* C, T0* a1);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_description */
extern void T67f14(TC* ac, T0* C, T0* a1);
/* VOID_ASSIGNED_TO_EXPANDED.set_description */
extern void T66f14(TC* ac, T0* C, T0* a1);
/* EXTERNAL_FAILURE.set_description */
extern void T65f14(TC* ac, T0* C, T0* a1);
/* CREATE_ON_DEFERRED.set_description */
extern void T64f14(TC* ac, T0* C, T0* a1);
/* RESUMPTION_FAILURE.set_description */
extern void T63f14(TC* ac, T0* C, T0* a1);
/* RESCUE_FAILURE.set_description */
extern void T62f14(TC* ac, T0* C, T0* a1);
/* EIFFEL_RUNTIME_PANIC.set_description */
extern void T53f16(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_description */
extern void T49f16(TC* ac, T0* C, T0* a1);
/* LOOP_INVARIANT_VIOLATION.set_description */
extern void T61f14(TC* ac, T0* C, T0* a1);
/* VARIANT_VIOLATION.set_description */
extern void T60f14(TC* ac, T0* C, T0* a1);
/* BAD_INSPECT_VALUE.set_description */
extern void T59f14(TC* ac, T0* C, T0* a1);
/* ROUTINE_FAILURE.set_description */
extern void T43f18(TC* ac, T0* C, T0* a1);
/* CHECK_VIOLATION.set_description */
extern void T58f14(TC* ac, T0* C, T0* a1);
/* INVARIANT_VIOLATION.set_description */
extern void T48f16(TC* ac, T0* C, T0* a1);
/* FLOATING_POINT_FAILURE.set_description */
extern void T57f14(TC* ac, T0* C, T0* a1);
/* POSTCONDITION_VIOLATION.set_description */
extern void T56f14(TC* ac, T0* C, T0* a1);
/* PRECONDITION_VIOLATION.set_description */
extern void T55f14(TC* ac, T0* C, T0* a1);
/* VOID_TARGET.set_description */
extern void T41f14(TC* ac, T0* C, T0* a1);
/* COM_FAILURE.set_exception_information */
extern void T52f20(TC* ac, T0* C, T0* a1);
/* COM_FAILURE.ccom_hresult_to_string */
extern T0* T52f10(TC* ac, T0* C, T6 a1);
/* INTEGER_32.to_hex_string */
extern T0* T6f20(TC* ac, T6 volatile* C);
/* STRING_8.put */
extern void T17f44(TC* ac, T0* C, T2 a1, T6 a2);
/* INTEGER_32.to_hex_character */
extern T2 T6f22(TC* ac, T6 volatile* C);
/* CHARACTER_8.plus */
extern T2 T2f18(TC* ac, T2 volatile* C, T6 a1);
/* CHARACTER_8.minus */
extern T2 T2f17(TC* ac, T2 volatile* C, T6 a1);
/* STRING_8.make_filled */
extern T0* T17c43(TC* ac, T2 a1, T6 a2);
/* STRING_8.fill_character */
extern void T17f45(TC* ac, T0* C, T2 a1);
/* COM_FAILURE.set_hresult_code */
extern void T52f19(TC* ac, T0* C, T6 a1);
/* OPERATING_SYSTEM_FAILURE.set_error_code */
extern void T51f14(TC* ac, T0* C, T6 a1);
/* IO_FAILURE.set_error_code */
extern void T50f16(TC* ac, T0* C, T6 a1);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_signal_code */
extern void T49f14(TC* ac, T0* C, T6 a1);
/* INVARIANT_VIOLATION.set_is_entry */
extern void T48f14(TC* ac, T0* C, T1 a1);
/* ROUTINE_FAILURE.set_class_name */
extern void T43f15(TC* ac, T0* C, T0* a1);
/* ROUTINE_FAILURE.set_routine_name */
extern void T43f14(TC* ac, T0* C, T0* a1);
/* NO_MORE_MEMORY.set_throwing_exception */
extern void T47f15(TC* ac, T0* C, T0* a1);
/* SERIALIZATION_FAILURE.set_throwing_exception */
extern void T71f12(TC* ac, T0* C, T0* a1);
/* OLD_VIOLATION.set_throwing_exception */
extern void T45f12(TC* ac, T0* C, T0* a1);
/* COM_FAILURE.set_throwing_exception */
extern void T52f18(TC* ac, T0* C, T0* a1);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_throwing_exception */
extern void T70f12(TC* ac, T0* C, T0* a1);
/* MISMATCH_FAILURE.set_throwing_exception */
extern void T68f12(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_FAILURE.set_throwing_exception */
extern void T51f13(TC* ac, T0* C, T0* a1);
/* IO_FAILURE.set_throwing_exception */
extern void T50f15(TC* ac, T0* C, T0* a1);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_throwing_exception */
extern void T67f12(TC* ac, T0* C, T0* a1);
/* VOID_ASSIGNED_TO_EXPANDED.set_throwing_exception */
extern void T66f12(TC* ac, T0* C, T0* a1);
/* EXTERNAL_FAILURE.set_throwing_exception */
extern void T65f12(TC* ac, T0* C, T0* a1);
/* CREATE_ON_DEFERRED.set_throwing_exception */
extern void T64f12(TC* ac, T0* C, T0* a1);
/* RESUMPTION_FAILURE.set_throwing_exception */
extern void T63f12(TC* ac, T0* C, T0* a1);
/* RESCUE_FAILURE.set_throwing_exception */
extern void T62f12(TC* ac, T0* C, T0* a1);
/* EIFFEL_RUNTIME_PANIC.set_throwing_exception */
extern void T53f14(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_throwing_exception */
extern void T49f13(TC* ac, T0* C, T0* a1);
/* LOOP_INVARIANT_VIOLATION.set_throwing_exception */
extern void T61f12(TC* ac, T0* C, T0* a1);
/* VARIANT_VIOLATION.set_throwing_exception */
extern void T60f12(TC* ac, T0* C, T0* a1);
/* BAD_INSPECT_VALUE.set_throwing_exception */
extern void T59f12(TC* ac, T0* C, T0* a1);
/* ROUTINE_FAILURE.set_throwing_exception */
extern void T43f16(TC* ac, T0* C, T0* a1);
/* CHECK_VIOLATION.set_throwing_exception */
extern void T58f12(TC* ac, T0* C, T0* a1);
/* INVARIANT_VIOLATION.set_throwing_exception */
extern void T48f13(TC* ac, T0* C, T0* a1);
/* FLOATING_POINT_FAILURE.set_throwing_exception */
extern void T57f12(TC* ac, T0* C, T0* a1);
/* POSTCONDITION_VIOLATION.set_throwing_exception */
extern void T56f12(TC* ac, T0* C, T0* a1);
/* PRECONDITION_VIOLATION.set_throwing_exception */
extern void T55f12(TC* ac, T0* C, T0* a1);
/* VOID_TARGET.set_throwing_exception */
extern void T41f12(TC* ac, T0* C, T0* a1);
/* ISE_EXCEPTION_MANAGER.exception_from_code */
extern T0* T21s12(TC* ac, T6 a1);
/* SERIALIZATION_FAILURE.default_create */
extern T0* T71c11(TC* ac);
/* OLD_VIOLATION.default_create */
extern T0* T45c11(TC* ac);
/* COM_FAILURE.default_create */
extern T0* T52c17(TC* ac);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.default_create */
extern T0* T70c11(TC* ac);
/* MISMATCH_FAILURE.default_create */
extern T0* T68c11(TC* ac);
/* OPERATING_SYSTEM_FAILURE.default_create */
extern T0* T51c12(TC* ac);
/* IO_FAILURE.set_code */
extern void T50f14(TC* ac, T0* C, T6 a1);
/* IO_FAILURE.default_create */
extern T0* T50c13(TC* ac);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.default_create */
extern T0* T67c11(TC* ac);
/* VOID_ASSIGNED_TO_EXPANDED.default_create */
extern T0* T66c11(TC* ac);
/* EXTERNAL_FAILURE.default_create */
extern T0* T65c11(TC* ac);
/* CREATE_ON_DEFERRED.default_create */
extern T0* T64c11(TC* ac);
/* RESUMPTION_FAILURE.default_create */
extern T0* T63c11(TC* ac);
/* RESCUE_FAILURE.default_create */
extern T0* T62c11(TC* ac);
/* EIFFEL_RUNTIME_PANIC.set_code */
extern void T53f13(TC* ac, T0* C, T6 a1);
/* EIFFEL_RUNTIME_PANIC.code */
extern T6 T53f9(TC* ac, T0* C);
/* EIFFEL_RUNTIME_PANIC.default_create */
extern T0* T53c12(TC* ac);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.default_create */
extern T0* T49c12(TC* ac);
/* LOOP_INVARIANT_VIOLATION.default_create */
extern T0* T61c11(TC* ac);
/* VARIANT_VIOLATION.default_create */
extern T0* T60c11(TC* ac);
/* BAD_INSPECT_VALUE.default_create */
extern T0* T59c11(TC* ac);
/* ROUTINE_FAILURE.default_create */
extern T0* T43c13(TC* ac);
/* CHECK_VIOLATION.default_create */
extern T0* T58c11(TC* ac);
/* INVARIANT_VIOLATION.default_create */
extern T0* T48c12(TC* ac);
/* FLOATING_POINT_FAILURE.default_create */
extern T0* T57c11(TC* ac);
/* POSTCONDITION_VIOLATION.default_create */
extern T0* T56c11(TC* ac);
/* PRECONDITION_VIOLATION.default_create */
extern T0* T55c11(TC* ac);
/* NO_MORE_MEMORY.set_code */
extern void T47f14(TC* ac, T0* C, T6 a1);
/* NO_MORE_MEMORY.code */
extern T6 T47f9(TC* ac, T0* C);
/* ISE_EXCEPTION_MANAGER.no_memory_exception_object_cell */
extern T0* T21s7(TC* ac);
/* CELL [NO_MORE_MEMORY].put */
extern T0* T30c2(TC* ac, T0* a1);
/* NO_MORE_MEMORY.default_create */
extern T0* T47c12(TC* ac);
/* VOID_TARGET.default_create */
extern T0* T41c11(TC* ac);
/* ISE_EXCEPTION_MANAGER.exception_data */
extern T0* T21s11(TC* ac);
/* CELL [detachable TUPLE [INTEGER_32, INTEGER_32, INTEGER_32, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, INTEGER_32, BOOLEAN]].put */
extern void T29f2(TC* ac, T0* C, T0* a1);
/* CELL [detachable TUPLE [INTEGER_32, INTEGER_32, INTEGER_32, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, INTEGER_32, BOOLEAN]].put */
extern T0* T29c2(TC* ac, T0* a1);
/* ISE_EXCEPTION_MANAGER.exception_data_cell */
extern T0* T21s6(TC* ac);
/* ISE_EXCEPTION_MANAGER.once_raise */
extern void T21s15(TC* ac, T0* a1);
/* SERIALIZATION_FAILURE.code */
extern T6 T71f9(TC* ac, T0* C);
/* OLD_VIOLATION.code */
extern T6 T45f9(TC* ac, T0* C);
/* COM_FAILURE.code */
extern T6 T52f9(TC* ac, T0* C);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.code */
extern T6 T70f9(TC* ac, T0* C);
/* MISMATCH_FAILURE.code */
extern T6 T68f9(TC* ac, T0* C);
/* OPERATING_SYSTEM_FAILURE.code */
extern T6 T51f9(TC* ac, T0* C);
/* IO_FAILURE.code */
extern T6 T50f9(TC* ac, T0* C);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.code */
extern T6 T67f9(TC* ac, T0* C);
/* VOID_ASSIGNED_TO_EXPANDED.code */
extern T6 T66f9(TC* ac, T0* C);
/* EXTERNAL_FAILURE.code */
extern T6 T65f9(TC* ac, T0* C);
/* CREATE_ON_DEFERRED.code */
extern T6 T64f9(TC* ac, T0* C);
/* RESUMPTION_FAILURE.code */
extern T6 T63f9(TC* ac, T0* C);
/* RESCUE_FAILURE.code */
extern T6 T62f9(TC* ac, T0* C);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.code */
extern T6 T49f9(TC* ac, T0* C);
/* LOOP_INVARIANT_VIOLATION.code */
extern T6 T61f9(TC* ac, T0* C);
/* VARIANT_VIOLATION.code */
extern T6 T60f9(TC* ac, T0* C);
/* BAD_INSPECT_VALUE.code */
extern T6 T59f9(TC* ac, T0* C);
/* ROUTINE_FAILURE.code */
extern T6 T43f9(TC* ac, T0* C);
/* CHECK_VIOLATION.code */
extern T6 T58f9(TC* ac, T0* C);
/* INVARIANT_VIOLATION.code */
extern T6 T48f9(TC* ac, T0* C);
/* FLOATING_POINT_FAILURE.code */
extern T6 T57f9(TC* ac, T0* C);
/* POSTCONDITION_VIOLATION.code */
extern T6 T56f9(TC* ac, T0* C);
/* PRECONDITION_VIOLATION.code */
extern T6 T55f9(TC* ac, T0* C);
/* VOID_TARGET.code */
extern T6 T41f9(TC* ac, T0* C);
/* CONVERSION_FAILURE.c_description */
extern T0* T135f1(TC* ac, T0* C);
/* NO_MORE_MEMORY.c_description */
extern T0* T47f1(TC* ac, T0* C);
/* SERIALIZATION_FAILURE.c_description */
extern T0* T71f1(TC* ac, T0* C);
/* OLD_VIOLATION.c_description */
extern T0* T45f1(TC* ac, T0* C);
/* COM_FAILURE.c_description */
extern T0* T52f1(TC* ac, T0* C);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.c_description */
extern T0* T70f1(TC* ac, T0* C);
/* DEVELOPER_EXCEPTION.c_description */
extern T0* T69f1(TC* ac, T0* C);
/* MISMATCH_FAILURE.c_description */
extern T0* T68f1(TC* ac, T0* C);
/* OPERATING_SYSTEM_FAILURE.c_description */
extern T0* T51f1(TC* ac, T0* C);
/* IO_FAILURE.c_description */
extern T0* T50f1(TC* ac, T0* C);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.c_description */
extern T0* T67f1(TC* ac, T0* C);
/* VOID_ASSIGNED_TO_EXPANDED.c_description */
extern T0* T66f1(TC* ac, T0* C);
/* EXTERNAL_FAILURE.c_description */
extern T0* T65f1(TC* ac, T0* C);
/* CREATE_ON_DEFERRED.c_description */
extern T0* T64f1(TC* ac, T0* C);
/* RESUMPTION_FAILURE.c_description */
extern T0* T63f1(TC* ac, T0* C);
/* RESCUE_FAILURE.c_description */
extern T0* T62f1(TC* ac, T0* C);
/* EIFFEL_RUNTIME_PANIC.c_description */
extern T0* T53f1(TC* ac, T0* C);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.c_description */
extern T0* T49f1(TC* ac, T0* C);
/* LOOP_INVARIANT_VIOLATION.c_description */
extern T0* T61f1(TC* ac, T0* C);
/* VARIANT_VIOLATION.c_description */
extern T0* T60f1(TC* ac, T0* C);
/* BAD_INSPECT_VALUE.c_description */
extern T0* T59f1(TC* ac, T0* C);
/* ROUTINE_FAILURE.c_description */
extern T0* T43f1(TC* ac, T0* C);
/* CHECK_VIOLATION.c_description */
extern T0* T58f1(TC* ac, T0* C);
/* INVARIANT_VIOLATION.c_description */
extern T0* T48f1(TC* ac, T0* C);
/* FLOATING_POINT_FAILURE.c_description */
extern T0* T57f1(TC* ac, T0* C);
/* POSTCONDITION_VIOLATION.c_description */
extern T0* T56f1(TC* ac, T0* C);
/* PRECONDITION_VIOLATION.c_description */
extern T0* T55f1(TC* ac, T0* C);
/* VOID_TARGET.c_description */
extern T0* T41f1(TC* ac, T0* C);
/* NO_MORE_MEMORY.is_ignored */
extern T1 T47f8(TC* ac, T0* C);
/* NO_MORE_MEMORY.exception_manager */
extern T0* T47s11(TC* ac);
/* SERIALIZATION_FAILURE.is_ignored */
extern T1 T71f8(TC* ac, T0* C);
/* SERIALIZATION_FAILURE.exception_manager */
extern T0* T71s6(TC* ac);
/* OLD_VIOLATION.is_ignored */
extern T1 T45f8(TC* ac, T0* C);
/* OLD_VIOLATION.exception_manager */
extern T0* T45s6(TC* ac);
/* COM_FAILURE.is_ignored */
extern T1 T52f16(TC* ac, T0* C);
/* COM_FAILURE.exception_manager */
extern T0* T52s14(TC* ac);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.is_ignored */
extern T1 T70f8(TC* ac, T0* C);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.exception_manager */
extern T0* T70s6(TC* ac);
/* MISMATCH_FAILURE.is_ignored */
extern T1 T68f8(TC* ac, T0* C);
/* MISMATCH_FAILURE.exception_manager */
extern T0* T68s6(TC* ac);
/* OPERATING_SYSTEM_FAILURE.is_ignored */
extern T1 T51f8(TC* ac, T0* C);
/* OPERATING_SYSTEM_FAILURE.exception_manager */
extern T0* T51s11(TC* ac);
/* IO_FAILURE.is_ignored */
extern T1 T50f8(TC* ac, T0* C);
/* IO_FAILURE.exception_manager */
extern T0* T50s11(TC* ac);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.is_ignored */
extern T1 T67f8(TC* ac, T0* C);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.exception_manager */
extern T0* T67s6(TC* ac);
/* VOID_ASSIGNED_TO_EXPANDED.is_ignored */
extern T1 T66f8(TC* ac, T0* C);
/* VOID_ASSIGNED_TO_EXPANDED.exception_manager */
extern T0* T66s6(TC* ac);
/* EXTERNAL_FAILURE.is_ignored */
extern T1 T65f8(TC* ac, T0* C);
/* EXTERNAL_FAILURE.exception_manager */
extern T0* T65s6(TC* ac);
/* CREATE_ON_DEFERRED.is_ignored */
extern T1 T64f8(TC* ac, T0* C);
/* CREATE_ON_DEFERRED.exception_manager */
extern T0* T64s6(TC* ac);
/* RESUMPTION_FAILURE.is_ignored */
extern T1 T63f8(TC* ac, T0* C);
/* RESUMPTION_FAILURE.exception_manager */
extern T0* T63s6(TC* ac);
/* RESCUE_FAILURE.is_ignored */
extern T1 T62f8(TC* ac, T0* C);
/* RESCUE_FAILURE.exception_manager */
extern T0* T62s6(TC* ac);
/* EIFFEL_RUNTIME_PANIC.is_ignored */
extern T1 T53f8(TC* ac, T0* C);
/* EIFFEL_RUNTIME_PANIC.exception_manager */
extern T0* T53s11(TC* ac);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.is_ignored */
extern T1 T49f8(TC* ac, T0* C);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.exception_manager */
extern T0* T49s11(TC* ac);
/* LOOP_INVARIANT_VIOLATION.is_ignored */
extern T1 T61f8(TC* ac, T0* C);
/* LOOP_INVARIANT_VIOLATION.exception_manager */
extern T0* T61s6(TC* ac);
/* VARIANT_VIOLATION.is_ignored */
extern T1 T60f8(TC* ac, T0* C);
/* VARIANT_VIOLATION.exception_manager */
extern T0* T60s6(TC* ac);
/* BAD_INSPECT_VALUE.is_ignored */
extern T1 T59f8(TC* ac, T0* C);
/* BAD_INSPECT_VALUE.exception_manager */
extern T0* T59s6(TC* ac);
/* ROUTINE_FAILURE.is_ignored */
extern T1 T43f8(TC* ac, T0* C);
/* ROUTINE_FAILURE.exception_manager */
extern T0* T43s11(TC* ac);
/* CHECK_VIOLATION.is_ignored */
extern T1 T58f8(TC* ac, T0* C);
/* CHECK_VIOLATION.exception_manager */
extern T0* T58s6(TC* ac);
/* INVARIANT_VIOLATION.is_ignored */
extern T1 T48f8(TC* ac, T0* C);
/* INVARIANT_VIOLATION.exception_manager */
extern T0* T48s11(TC* ac);
/* FLOATING_POINT_FAILURE.is_ignored */
extern T1 T57f8(TC* ac, T0* C);
/* FLOATING_POINT_FAILURE.exception_manager */
extern T0* T57s6(TC* ac);
/* POSTCONDITION_VIOLATION.is_ignored */
extern T1 T56f8(TC* ac, T0* C);
/* POSTCONDITION_VIOLATION.exception_manager */
extern T0* T56s6(TC* ac);
/* PRECONDITION_VIOLATION.is_ignored */
extern T1 T55f8(TC* ac, T0* C);
/* PRECONDITION_VIOLATION.exception_manager */
extern T0* T55s6(TC* ac);
/* VOID_TARGET.is_ignored */
extern T1 T41f8(TC* ac, T0* C);
/* VOID_TARGET.exception_manager */
extern T0* T41s6(TC* ac);
/* ISE_EXCEPTION_MANAGER.last_exception */
extern T0* T21s1(TC* ac);
/* ISE_EXCEPTION_MANAGER.init_exception_manager */
extern void T21s14(TC* ac);
/* CELL [NO_MORE_MEMORY].do_nothing */
extern void T30s3(TC* ac);
/* CELL [detachable EXCEPTION].do_nothing */
extern void T27s3(TC* ac);
/* CELL [detachable TUPLE [INTEGER_32, INTEGER_32, INTEGER_32, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, STRING_8, INTEGER_32, BOOLEAN]].do_nothing */
extern void T29s3(TC* ac);
/* ISE_EXCEPTION_MANAGER.unraisable_exceptions */
extern T0* T21s5(TC* ac);
/* HASH_TABLE [INTEGER_32, INTEGER_32].force */
extern void T28f37(TC* ac, T0* C, T6 a1, T6 a2);
/* HASH_TABLE [INTEGER_32, INTEGER_32].position */
extern T6 T28f22(TC* ac, T0* C);
/* SPECIAL [INTEGER_32].force */
extern void T73f7(TC* ac, T0* C, T6 a1, T6 a2);
/* HASH_TABLE [INTEGER_32, INTEGER_32].deleted_position */
extern T6 T28f21(TC* ac, T0* C, T6 a1);
/* HASH_TABLE [INTEGER_32, INTEGER_32].add_space */
extern void T28f39(TC* ac, T0* C);
/* HASH_TABLE [INTEGER_32, INTEGER_32].accommodate */
extern void T28f40(TC* ac, T0* C, T6 a1);
/* HASH_TABLE [INTEGER_32, INTEGER_32].set_indexes_map */
extern void T28f44(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [INTEGER_32, INTEGER_32].set_deleted_marks */
extern void T28f43(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [INTEGER_32, INTEGER_32].set_keys */
extern void T28f42(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [INTEGER_32, INTEGER_32].set_content */
extern void T28f41(TC* ac, T0* C, T0* a1);
/* HASH_TABLE [INTEGER_32, INTEGER_32].put */
extern void T28f45(TC* ac, T0* C, T6 a1, T6 a2);
/* HASH_TABLE [INTEGER_32, INTEGER_32].set_conflict */
extern void T28f47(TC* ac, T0* C);
/* HASH_TABLE [INTEGER_32, INTEGER_32].found */
extern T1 T28f31(TC* ac, T0* C);
/* HASH_TABLE [INTEGER_32, INTEGER_32].occupied */
extern T1 T28f29(TC* ac, T0* C, T6 a1);
/* HASH_TABLE [INTEGER_32, INTEGER_32].empty_duplicate */
extern T0* T28f28(TC* ac, T0* C, T6 a1);
/* HASH_TABLE [INTEGER_32, INTEGER_32].compare_objects */
extern void T28f46(TC* ac, T0* C);
/* HASH_TABLE [INTEGER_32, INTEGER_32].soon_full */
extern T1 T28f20(TC* ac, T0* C);
/* HASH_TABLE [INTEGER_32, INTEGER_32].not_found */
extern T1 T28f19(TC* ac, T0* C);
/* HASH_TABLE [INTEGER_32, INTEGER_32].internal_search */
extern void T28f38(TC* ac, T0* C, T6 a1);
/* ISE_EXCEPTION_MANAGER.unignorable_exceptions */
extern T0* T21s4(TC* ac);
/* HASH_TABLE [INTEGER_32, INTEGER_32].do_nothing */
extern void T28s36(TC* ac);
/* MANAGED_POINTER.dispose */
extern void T85f11(TC* ac, T0* C);
/* Call to EXCEPTION.original */
extern T0* T22x4669448(TC* ac, T0* C);
/* Call to EXCEPTION.code */
extern T6 T22x4669447(TC* ac, T0* C);
/* Call to EXCEPTION.c_description */
extern T0* T22x4669460(TC* ac, T0* C);
/* Call to EXCEPTION.is_ignored */
extern T1 T22x4669456(TC* ac, T0* C);
/* Call to TYPE [detachable EXCEPTION].type_id */
extern T6 T82x3883012(TC* ac, T0* C);
/* Call to EXCEPTION.set_type_name */
extern void T22x4669464T0(TC* ac, T0* C, T0* a1);
/* Call to EXCEPTION.set_recipient_name */
extern void T22x4669467T0(TC* ac, T0* C, T0* a1);
/* Call to EXCEPTION.set_description */
extern void T22x4669469T0(TC* ac, T0* C, T0* a1);
/* Call to EXCEPTION.set_exception_trace */
extern void T22x4669463T0(TC* ac, T0* C, T0* a1);
/* Call to EXCEPTION.set_throwing_exception */
extern void T22x4669468T0(TC* ac, T0* C, T0* a1);
extern T0* GE_ma150(TC* ac, T6 c, T6 n, ...);
extern T0* GE_ma149(TC* ac, T6 c, T6 n, ...);
extern T0* GE_mt32(TC* ac, T6 a1, T6 a2, T6 a3, T0* a4, T0* a5, T0* a6, T0* a7, T0* a8, T0* a9, T6 a10, T1 a11);
extern T0* ge6ov98306;
extern T0* ge6ov98308;
extern T0* ge6ov98307;
extern T0* ge6ov98311;
extern T0* ge6ov98309;
extern T0* ge6ov98312;
extern T0* ge6ov98310;
extern T0* ge6ov98305;
extern T0* ge202ov3309577;
extern void GE_init_const1(void);
extern void GE_init_const(void);

#ifdef __cplusplus
}
#endif


/*
	description:

		"Part of ISE Eiffel runtime. Needed to compile the EiffelCOM library."

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2010-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef EIF_CECIL_H
#define EIF_CECIL_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*EIF_PROCEDURE)(EIF_REFERENCE, ...);
#define EIF_PROC EIF_PROCEDURE
typedef EIF_INTEGER_32 (*EIF_INTEGER_32_FUNCTION)(EIF_REFERENCE, ...); /* Returns an Eiffel Integer 32 bits */
#define EIF_INTEGER_FUNCTION EIF_INTEGER_32_FUNCTION
typedef EIF_REFERENCE (*EIF_REFERENCE_FUNCTION)(EIF_REFERENCE, ...); /* Returns an Eiffel Reference */
typedef EIF_POINTER (*EIF_POINTER_FUNCTION)(EIF_REFERENCE, ...); /* Returns an Eiffel Pointer */
typedef EIF_BOOLEAN (*EIF_BOOLEAN_FUNCTION)(EIF_REFERENCE, ...); /* Returns an Eiffel Boolean */
typedef EIF_CHARACTER_8 (*EIF_CHARACTER_8_FUNCTION)(EIF_REFERENCE, ...); /* Returns char */
#define EIF_CHARACTER_FUNCTION EIF_CHARACTER_8_FUNCTION
typedef EIF_REAL_64 (*EIF_REAL_64_FUNCTION)(EIF_REFERENCE, ...); /* Returns an Eiffel Double */
#define EIF_DOUBLE_FUNCTION EIF_REAL_64_FUNCTION
typedef EIF_REAL_32 (*EIF_REAL_32_FUNCTION)(EIF_REFERENCE, ...); /* Returns an Eiffel Real */
#define EIF_REAL_FUNCTION EIF_REAL_32_FUNCTION

extern EIF_PROCEDURE eif_procedure(char* rout, EIF_TYPE_ID cid);
#define eif_proc eif_procedure /* Use `eif_procedure' instead */
extern EIF_INTEGER_FUNCTION eif_integer_function(char* rout, EIF_TYPE_ID cid);
extern EIF_REFERENCE_FUNCTION eif_reference_function(char* rout, EIF_TYPE_ID cid);
extern EIF_POINTER_FUNCTION eif_pointer_function(char* rout, EIF_TYPE_ID cid);
extern EIF_BOOLEAN_FUNCTION eif_boolean_function(char* rout, EIF_TYPE_ID cid);
extern EIF_REAL_64_FUNCTION eif_real_64_function(char* rout, EIF_TYPE_ID cid);
#define eif_double_function(rout,cid) eif_real_64_function((rout),(cid))
extern EIF_REAL_32_FUNCTION eif_real_32_function(char* rout, EIF_TYPE_ID cid);
#define eif_real_function(rout,cid) eif_real_32_function((rout),(cid))
extern EIF_CHARACTER_8_FUNCTION eif_character_8_function(char* rout, EIF_TYPE_ID cid);
#define eif_character_function(rout,cid) eif_character_8_function((rout),(cid))
extern EIF_OBJECT eif_create(EIF_TYPE_ID cid);
extern EIF_TYPE_ID eif_type_id(char* type_string);
extern EIF_INTEGER eifaddr_offset(EIF_REFERENCE object, char *name, int * const ret);
#define eif_string(s) RTMS(s)
#define makestr(s,c) RTMS_EX((s),(c))
#define eifaddr(object,name,ret) ((void*) ((char*) object + eifaddr_offset (object, name, ret)))
#define eif_field(object,name,type) *(type*)(eifaddr(object,name, NULL)) /* Obsolete. Use "eif_attribute" instead. */
#define eif_attribute(object,name,type,ret) *(type*)(eifaddr(object,name,ret)) /* Returns the attribute of an object. Return status in "ret".*/

/* Miscellaneous useful functions. */

/* Make an Eiffel array from a C array:
 * `eif_array' is the direct reference to the Eiffel array.
 * `c_array' is the C array.
 * `nelts' the number of elements to copy in the eiffel array, it has to
 * be equal to `eif_array.count'.
 * type is an Eiffel type.
 */
#define eif_make_from_c(eif_array, c_array, nelts, type) \
	{ \
		EIF_REFERENCE area = eif_field(eif_array, "area", EIF_REFERENCE); \
		memcpy((type *)area, c_array, nelts * sizeof(type));\
	}

#define eif_type eiftype /* Dynamic type ID */
extern EIF_TYPE_ID eiftype(EIF_OBJECT object); /* Give dynamic type of EIF_OBJECT. Obsolete, use "eif_type_by_object". */
extern EIF_TYPE_ID eif_type_by_reference(EIF_REFERENCE object);
extern EIF_TYPE_INDEX eif_gen_param_id(EIF_TYPE_INDEX dftype, uint32_t pos);

#ifdef __cplusplus
}
#endif

#endif
/*
	description:

		"Part of ISE Eiffel runtime. Needed to compile the EiffelCOM library."

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2010-2017, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef EIF_PLUG_H
#define EIF_PLUG_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern int nstcall;	/* Nested call global variable: signals a nested call and
					 * trigger an invariant check in generated C routines  */

#ifdef __cplusplus
}
#endif

#endif
/*
	description:

		"C functions used to implement class CONSOLE"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2006-2017, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef EIF_CONSOLE_H
#define EIF_CONSOLE_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern EIF_POINTER console_def(EIF_INTEGER file);
extern EIF_BOOLEAN console_eof(FILE* fp);
extern EIF_CHARACTER_8 console_separator(FILE* f);
extern void console_ps(FILE* f, char* str, EIF_INTEGER len);
extern void console_pr(FILE* f, EIF_REAL_32 number);
extern void console_pc(FILE* f, EIF_CHARACTER_8 c);
extern void console_pd(FILE* f, EIF_REAL_64 val);
extern void console_pi(FILE* f, EIF_INTEGER number);
extern void console_tnwl(FILE* f);
extern EIF_CHARACTER_8 console_readchar(FILE* f);
extern EIF_REAL_32 console_readreal(FILE* f);
extern EIF_INTEGER console_readint(FILE* f);
extern EIF_REAL_64 console_readdouble(FILE* f);
extern EIF_INTEGER console_readword(FILE* f, char* s, EIF_INTEGER bound, EIF_INTEGER start);
extern EIF_INTEGER console_readline(FILE* f, char* s, EIF_INTEGER bound, EIF_INTEGER start);
extern void console_next_line(FILE* f);
extern EIF_INTEGER console_readstream(FILE* f, char* s, EIF_INTEGER bound);
extern void console_file_close (FILE* f);

#ifdef __cplusplus
}
#endif

#endif
/*
	description:

		"Part of ISE Eiffel runtime. Needed to compile the C code of the EiffelNet library."

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef EIF_CONFIG_H
#define EIF_CONFIG_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif

#if defined(GE_WINDOWS)

/* ABORTSIG:
 *	This symbol holds the signal number (symbol) used by the abort() call. To
 *	actually define the signal symbol, <signal.h> should be included.
 */
#define ABORTSIG SIGABRT		/* NC */

/* MEM_ALIGNBYTES:
 *	This symbol contains the number of bytes required to align a
 *	double. Usual values are 2, 4 and 8.
 */
#define MEM_ALIGNBYTES 8	/* NC */

/* BYTEORDER:
 *	This symbol hold the hexadecimal constant defined in byteorder,
 *	i.e. 0x1234 or 0x4321, etc...
 */
#define BYTEORDER 0x1234	/* large digits for MSB */

/* CAT2:
 *	This macro catenates 2 tokens together.
 */
#if 42 == 1
#define CAT2(a,b)a/* NC */b
#define CAT3(a,b,c)a/* NC */b/* NC */c
#elif 42 == 42
#define CAT2(a,b)a ## b
#define CAT3(a,b,c)a ## b ## c
#endif

#ifndef CAT2
#include "Warning: How does this C preprocessor catenate tokens?"
#endif

/* VAL_NOFILE:
 *	This symbol contains the number of file descriptors available to the
 *	process, as determined at configuration time. Unless a static constant
 *	is needed, you should rely on getdtablesize() to obtain that number.
 */
#define VAL_NOFILE 60	/* Number of file descriptors */

/* USE_BSDJMP:
 *	This symbol, if defined, indicates that the BSD _setjmp and _longjmp
 *	routines are available to do non-local gotos wihtout saving or restoring
 *	the signal mask flag.
 */
/*#define  USE_BSDJMP		 */ /* NC */

/* HAS_CHOWN:
 *	This symbol, if defined, indicates that the chown routine is
 *	available.
 */
/*#define  HAS_CHOWN		 */ /* NC */

/* HAS_DUP2:
 *	This symbol, if defined, indicates that the dup2 routine is
 *	available to duplicate file descriptors.
 */
#define HAS_DUP2	/* NC */

/* EOFPIPE:
 *	This symbol, if defined, indicates that EOF condition will be detected
 *	by the reader of the pipe when it is closed by the writing process.
 *	That is, a select() call on that file descriptor will not block when
 *	only an EOF remains (typical behaviour for BSD systems).
 */
/*#define  EOFPIPE		 */ /* NC */

/* HAS_FCNTL:
 *	This symbol, if defined, indicates to the C program that
 *	the fcntl() function exists.
 */
#define HAS_FCNTL		/* NC */

/* HAS_FTIME:
 *	This symbol, if defined, indicates that the ftime() routine exists.
 *	It is basically a sub-second accuracy clock, but is less accurate
 *	than gettimeofday(2) anyway. The type "Timeval" should be used to
 *	refer to "struct timeb".
 */
#define HAS_FTIME		/* NC */
#ifdef HAS_FTIME
#define Timeval struct timeb		/* Structure used by ftime() */
#endif

/* HAS_GETTIMEOFDAY:
 *	This symbol, if defined, indicates that the gettimeofday() system
 *	call is available for a sub-second accuracy clock. Usually, the file
 *	<sys/resource.h> needs to be included (see I_SYS_RESOURCE).
 *	The type "Timeval" should be used to refer to "struct timeval".
 */
/*#define  HAS_GETTIMEOFDAY	 */ /* NC */
#ifdef HAS_GETTIMEOFDAY
#define Timeval struct timeval	/* Structure used by gettimeofday() */
#endif

/* HAS_GETGROUPS:
 *	This symbol, if defined, indicates that the getgroups() routine is
 *	available to get the list of process groups.  If unavailable, multiple
 *	groups are probably not supported.
 */
/*#define  HAS_GETGROUPS		 */ /* NC */

/* Groups_t:
 *	This symbol holds the type used for the second argument to
 *	getgroups().  Usually, this is the same of gidtype, but
 *	sometimes it isn't.  It can be int, ushort, uid_t, etc...
 *	It may be necessary to include <sys/types.h> to get any
 *	typedef'ed information.  This is only required if you have
 *	getgroups().
 */
#ifdef HAS_GETGROUPS
#define Groups_t 	/* Type for 2nd arg to getgroups() */
#endif

/* PAGESIZE_VALUE:
 *	This symbol holds the size in bytes of a system page (obtained via
 *	the getpagesize() system call at configuration time or asked to the
 *	user if the system call is not available).
 */
#define PAGESIZE_VALUE 4096	/* System page size, in bytes */

/* SIGNALS_KEPT:
 *	This symbol is defined if signal handlers needn't be reinstated after
 *	receipt of a signal.
 */
/*#define  SIGNALS_KEPT	 */ /* NC */

/* HAS_LINK:
 *	This symbol, if defined, indicates that the link routine is
 *	available to create hard links.
 */
/*#define  HAS_LINK	 */ /* NC */

/* HAS_LSTAT:
 *	This symbol, if defined, indicates that the lstat routine is
 *	available to do file stats on symbolic links.
 */
/*#define  HAS_LSTAT		 */ /* NC */

/* HAS_MKDIR:
 *	This symbol, if defined, indicates that the mkdir routine is available
 *	to create directories.  Otherwise you should fork off a new process to
 *	exec /bin/mkdir.
 */
#define HAS_MKDIR		/* NC */

/* PIDCHECK:
 *	This symbol, if defined, means that the kill(pid, 0) will
 *	check for an active pid (i.e. the kernel will run all the
 *	necessary pid checks, but no signal is actually sent).
 */
/*#define  PIDCHECK		 */ /* NC */

/* HAS_READDIR:
 *	This symbol, if defined, indicates that the readdir routine is
 *	available to read directory entries. You may have to include
 *	<dirent.h>. See I_DIRENT.
 */
#define HAS_READDIR		/* NC */

/* HAS_REWINDDIR:
 *	This symbol, if defined, indicates that the rewinddir routine is
 *	available. You may have to include <dirent.h>. See I_DIRENT.
 */
/*#define  HAS_REWINDDIR		 */ /* NC */

/* HAS_RENAME:
 *	This symbol, if defined, indicates that the rename routine is available
 *	to rename files.  Otherwise you should do the unlink(), link(), unlink()
 *	trick.
 */
#define HAS_RENAME	/* NC */

/* HAS_RMDIR:
 *	This symbol, if defined, indicates that the rmdir routine is
 *	available to remove directories. Otherwise you should fork off a
 *	new process to exec /bin/rmdir.
 */
#define HAS_RMDIR		/* NC */

/* HAS_GETRUSAGE:
 *	This symbol, if defined, indicates that the getrusage() routine is
 *	available to get process statistics with a sub-second accuracy.
 *	Inclusion of <sys/resource.h> and <sys/time.h> may be necessary.
 */
/*#define  HAS_GETRUSAGE		 */ /* NC */

/* HAS_SBRK:
 *	This symbol, if defined, indicates that the sbrk system call is
 *	available to add/relase core. Always true on Unix.
 */
/*#define  HAS_SBRK	 */ /* NC */

/* HAS_SIGACTION:
 *	This symbol, if defined, indicates that the sigaction() routine is
 *	available as a better alternative to the signal call.
 */
/*#define  HAS_SIGACTION		 */ /* NC */

/* HAS_SIGALTSTACK:
 *	This symbol, if defined, indicates that the sigaltstack() routine is
 *	available to set an alternative call stack. Otherwise it means that
 *  a stack overflow will not be correctly handled.
 */
/*#define  HAS_SIGALTSTACK		 */ /* NC */

/* HAS_SYS_SIGLIST:
 *	This symbol, if defined, indicates that the sys_siglist array is
 *	available to translate signal numbers to strings.
 */
/*#define  HAS_SYS_SIGLIST		 */ /* NC */

/* HAS_SIGSETMASK:
 *	This symbol, if defined, indicates that the sigsetmask() routine is
 *	available to set current signal mask. Otherwise, you should probably
 *	emulate this by using signal(), but fear race conditions...
 */
/*#define  HAS_SIGSETMASK		 */ /* NC */

/* HAS_SIGVEC:
 *	This symbol, if defined, indicates that BSD reliable signals are
 *	supported.
 */
/*#define  HAS_SIGVEC	 */ /* NC */

/* HAS_SIGVECTOR:
 *	This symbol, if defined, indicates that the sigvec() routine is called
 *	sigvector() instead, and that sigspace() is provided instead of
 *	sigstack().  This is probably only true for HP-UX.
 */
/*#define  HAS_SIGVECTOR	 */ /* NC */

/* HAS_STRERROR:
 *	This symbol, if defined, indicates that the strerror routine is
 *	available to translate error numbers to strings. See the writeup
 *	of Strerror() in this file before you try to define your own.
 */
#define HAS_STRERROR		/* NC */

/* HAS_SYS_ERRLIST:
 *	This symbol, if defined, indicates that the sys_errlist array is
 *	available to translate error numbers to strings. The extern int
 *	sys_nerr gives the size of that table.
 */
#define HAS_SYS_ERRLIST	/* NC */

/* HAS_SYS_ERRNOLIST:
 *	This symbol, if defined, indicates that the sys_errnolist array is
 *	available to translate an errno code into its symbolic name (e.g.
 * ENOENT). The extern int sys_nerrno gives the size of that table.
 */
/*#define  HAS_SYS_ERRNOLIST	 */ /* NC */

/* Strerror:
 *	This preprocessor symbol is defined as a macro if strerror() is
 *	not available to translate error numbers to strings but sys_errlist[]
 *	array is there.
 */
#define Strerror(e) strerror(e)

/* HAS_TIME:
 *	This symbol, if defined, indicates that the time() routine exists.
 */
#define HAS_TIME		/* NC */

/* Time_t:
 *	This symbol holds the type returned by time(). It can be long,
 *	or time_t on BSD sites (in which case <sys/types.h> should be
 *	included).
 */
#define Time_t time_t		/* Time type */

/* HAS_TIMES:
 *	This symbol, if defined, indicates that the times() routine exists.
 *	Note that this became obsolete on some systems (SUNOS), which now
 * use getrusage(). It may be necessary to include <sys/times.h>.
 */
/*#define  HAS_TIMES		 */ /* NC */

/* HAS_USLEEP:
 *	This symbol, if defined, indicates that the usleep routine is
 *	available to let the process sleep on a sub-second accuracy.
 */
/*#define  HAS_USLEEP		 */ /* NC */

/* HAS_NANOSLEEP:
 *	This symbol, if defined, indicates that the nanosleep routine is
 *	available to let the process sleep on a sub-second accuracy.
 */
/*#define  HAS_NANOSLEEP		 */ /* NC */

/* Signal_t:
 *	This symbol's value is either "void" or "int", corresponding to the
 *	appropriate return type of a signal handler.  Thus, you can declare
 *	a signal handler using "Signal_t (*handler)()", and define the
 *	handler using "Signal_t handler(sig)".
 */
#define Signal_t void	/* Signal handler's return type */

/* I_DIRENT:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <dirent.h>. Using this symbol also triggers the definition
 *	of the Direntry_t define which ends up being 'struct dirent' or
 *	'struct direct' depending on the availability of <dirent.h>.
 */
/*#define  I_DIRENT		 */ /* NC */

/* DIRNAMLEN:
 *	This symbol, if defined, indicates to the C program that the length
 *	of directory entry names is provided by a d_namlen field.  Otherwise
 *	you need to do strlen() on the d_name field.
 */
/*#define  DIRNAMLEN	 */ /* NC */

/* I_FCNTL:
 *	This manifest constant tells the C program to include <fcntl.h>.
 */
#define I_FCNTL	/* NC */

/* I_GRP:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <grp.h>.
 */
/*#define  I_GRP		 */ /* NC */

/* I_LIMITS:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <limits.h> to get definition of symbols like WORD_BIT or
 *	LONG_MAX, i.e. machine dependant limitations.
 */
#define I_LIMITS		/* NC */

/* I_NETINET_IN:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <netinet/in.h>. Otherwise, you may try <sys/in.h>.
 */
/*#define  I_NETINET_IN	 */ /* NC */

/* I_SYS_IN:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/in.h> instead of <netinet/in.h>.
 */
/*#define  I_SYS_IN		 */ /* NC */

/* I_PWD:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <pwd.h>.
 */
/*#define  I_PWD		 */ /* NC */

/* I_SYS_DIR:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/dir.h>.
 */
/*#define  I_SYS_DIR		 */ /* NC */

/* I_SYS_FILE:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/file.h> to get definition of R_OK and friends.
 */
/*#define  I_SYS_FILE		 */ /* NC */

/* I_SYS_NDIR:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/ndir.h>.
 */
/*#define  I_SYS_NDIR	 */ /* NC */

/* I_SYS_RESOURCE:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/resource.h>.
 */
/*#define  I_SYS_RESOURCE		 */ /* NC */

/* I_SYS_SOCKET:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/socket.h> before performing socket calls.
 */
/*#define  I_SYS_SOCKET		 */ /* NC */

/* I_SYS_TIMEB:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/timeb.h>, in order to define struct timeb (some systems
 *	define this in <sys/time.h>). This is useful when using ftime().
 *	You should include <sys/time.h> if I_SYS_TIMEB is not defined,
 *	nor is I_SYS_TIME.
 */
#define I_SYS_TIMEB		/* NC */

/* I_SYS_TIMES:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/times.h>.
 */
/*#define 	I_SYS_TIMES		 */ /* NC */

/* I_SYS_UN:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/un.h> to get UNIX domain socket definitions.
 */
/*#define  I_SYS_UN		 */ /* NC */

/* I_TIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <time.h>.
 */
#define I_TIME		/* NC */

/* I_SYS_TIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/time.h>.
 */
/*#define  I_SYS_TIME		 */ /* NC */

/* I_SYS_TIME_KERNEL:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/time.h> with KERNEL defined.
 */
/*#define  I_SYS_TIME_KERNEL		 */ /* NC */

/* I_UTIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <utime.h>.
 */
/*#define  I_UTIME		 */ /* NC */

/* I_SYSUTIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/utime.h>.
 */
#define I_SYSUTIME		/* NC */

/* I_STDARG:
 *	This symbol, if defined, indicates that <stdarg.h> exists and should
 *	be included.
 */
#define I_STDARG		/* NC */

/* I_VARARGS:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <varargs.h>.
 */
#define I_VARARGS	/* NC */

/* INTSIZE:
 *	This symbol contains the size of an int, so that the C preprocessor
 *	can make decisions based on it.
 */
#define INTSIZE 4		/* NC */

/* Malloc_t:
 *	This symbol is the type of pointer returned by malloc and realloc.
 */
#define Malloc_t void *			/* NC */

/* Pid_t:
 *	This symbol holds the type used to declare process ids in the kernel.
 *	It can be int, uint, pid_t, etc... It may be necessary to include
 *	<sys/types.h> to get any typedef'ed information.
 */
#define Pid_t pid_t		/* PID type */

/* CAN_PROTOTYPE:
 *	If defined, this macro indicates that the C compiler can handle
 *	function prototypes.
 */
#define	CAN_PROTOTYPE	/* NC */

/* _:
 *	This macro is used to declare function parameters for folks who want
 *	to make declarations with prototypes using a different style than
 *	the above macros.  Use double parentheses.  For example:
 *
 *		int main _((int argc, char *argv[]));
 */
#ifdef CAN_PROTOTYPE
#define	_(args) args
#else
#define	_(args) ()
#endif

/* HAS_SMART_SBRK:
 *	This symbol is defined when the sbrk() system call may be used with
 *	a negative argument to lower the break value, therefore releasing
 *	core to the system. If not, you'd probably be better off using the
 *	mmap() system call.
 */
/*#define  HAS_SMART_SBRK  */ /* NC */

/* Select_fd_set_t:
 *	This symbol holds the type used for the 2nd, 3rd, and 4th
 *	arguments to select.  Usually, this is 'fd_set *', if HAS_FD_SET
 *	is defined, and 'int *' otherwise.  This is only useful if you
 *	have select(), of course.
 */
#define Select_fd_set_t 	fd_set *	/* NC */

/* CAN_KEEPALIVE:
 *	This symbol if defined indicates to the C program that the SO_KEEPALIVE
 *	option of setsockopt() will work as advertised in the manual.
 */
/*#define  CAN_KEEPALIVE		 */ /* NC */

/* Uid_t:
 *	This symbol holds the type used to declare user ids in the kernel.
 *	It can be int, ushort, uid_t, etc... It may be necessary to include
 *	<sys/types.h> to get any typedef'ed information.
 */
#define Uid_t uid_t		/* UID type */

/* VOIDFLAGS:
 *	This symbol indicates how much support of the void type is given by this
 *	compiler.  What various bits mean:
 *
 *	    1 = supports declaration of void
 *	    2 = supports arrays of pointers to functions returning void
 *	    4 = supports comparisons between pointers to void functions and
 *		    addresses of void functions
 *	    8 = suports declaration of generic void pointers
 *
 *	The package designer should define VOIDUSED to indicate the requirements
 *	of the package.  This can be done either by #defining VOIDUSED before
 *	including eif_config.h, or by defining defvoidused in Myinit.U.  If the
 *	latter approach is taken, only those flags will be tested.  If the
 *	level of void support necessary is not present, defines void to int.
 */
#ifndef VOIDUSED
#define VOIDUSED 15
#endif
#define VOIDFLAGS 15
#if (VOIDFLAGS & VOIDUSED) != VOIDUSED
#define void int		/* is void to be avoided? */
#define M_VOID			/* Xenix strikes again */
#endif

/* USE_ADD_LOG:
 *	This symbol is defined if the run time logging is enabled, mainly for
 *	debugging purposes (although the logging level may be set to a low level
 *	to leave only critical error messages). This will never be defined by
 *	default.
 */
/*#define  USE_ADD_LOG		 */ /* Allow logging */
#define LOGGING_LEVEL	9	/* Logging level */

/* HAS_SMART_MMAP:
 *	This symbol, if defined, indicates to the C program that it can
 *	use mmap and munmap for shared memory.
 */
/*#define  HAS_SMART_MMAP	 */ /* NC */

/* HAS_GETPWUID:
 *	This symbol, if defined, indicates that the getpwuid system call is
 *	available
 */
/*#define  HAS_GETPWUID	 */ /* NC */

/* HAS_GETGRGID:
 *	This symbol, if defined, indicates that the getgrgid system call is
 *	available
 */
/*#define  HAS_GETGRGID	 */ /* NC */

/* HAS_GETEUID:
 *	This symbol, if defined, indicates that the geteuid system call is
 *	available
 */
/*#define  HAS_GETEUID	 */ /* NC */

/* HAS_UNLINK:
 *	This symbol, if defined, indicates that the unlink routine is
 *	available.
 */
#define HAS_UNLINK	/* NC */

/* HAS_UTIME:
 *	This symbol, if defined, indicates that the utime routine is
 *	available.
 */
#define HAS_UTIME	/* NC */

/* I_FD_SET_SYS_SELECT:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/select.h> in order to get definition of struct fd_set.
 */
/*#define  I_FD_SET_SYS_SELECT	 */ /* NC */

/* I_TMVAL_SYS_SELECT:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/select.h> in order to get definition of struct timeval.
 *.I_SYS_SELECT is not set correctly in the dist3.0 p22
 * This unit overrides the default one. It checks the content of
 * the include file <sys/select.h> to find the definition of timeval
 */
/*#define  I_TMVAL_SYS_SELECT	 */ /* NC */

/* MAY_PANIC:
 *	This symbol is defined if the run-time is to be compiled with extra
 *	consistency checks. Those checks make sure some "impossible" conditions
 *	never occur, and they raise a panic if they do. Typical checks include
 *	free-list consistency check, stack overflow or underflow, etc...
 */
/*#define  MAY_PANIC	 */ /* Extra run-time consistency checks */

/* USE_BSD_SIGNALS:
 * On some Unix, we need to define _BSD_SIGNALS (e.g IRIX*)
 */

/*#define  USE_BSD_SIGNALS	 */ /* NC */

/* USE_TLS:
 *	This symbol, if defined, indicates that thread-local storage specifier
 *	can be used to access thread-local variables.
 */
/*#define  USE_TLS	 */ /* NC */

/* INTEGER_64 display format:
 * 	This symbol is used in printf and others to display 64 bits signed
 *	integers.
 */

#define EIF_INTEGER_64_DISPLAY "I64d"
#define EIF_NATURAL_64_DISPLAY "I64u"
/* GOBO #define EIF_POINTER_DISPLAY "llX" */

/* Does current platform support conversion from uin64 to floating point? */
#define	HAS_BUILTIN_CONVERSION_FROM_UINT64_TO_FLOATING_POINT	/* NC */

/* INTEGER_64 constant definition: */
#ifndef RTI64C
#define RTI64C(x)	CAT2(x,i64)
#endif
#ifndef RTU64C
#define RTU64C(x)	CAT2(x,ui64)
#endif

/* Define EIF_OS Constants */

#define EIF_OS_WINNT 	1
#define EIF_OS_LINUX 	2
#define EIF_OS_SUNOS	3
#define EIF_OS_DARWIN 	4
#define EIF_OS_ALPHA 	5
#define EIF_OS_FREEBSD 	6
#define EIF_OS_HPUX 	7
#define EIF_OS_IRIX 	8
#define EIF_OS_OPENBSD 	9
#define EIF_OS_UNICOS 	10
#define EIF_OS_VXWORKS	11
#define EIF_OS_VMS  	12
#define EIF_OS_HAIKU	13
#define EIF_OS_IPHONE	14

/* Define EIF_OS value */
#define EIF_OS EIF_OS_WINNT

/* Define EIF_ARCH Constants */

#define EIF_ARCH_X86 		1
#define EIF_ARCH_X86_64 	2
#define EIF_ARCH_SPARC 		3
#define EIF_ARCH_SPARC_64 	4
#define EIF_ARCH_PPC		5
#define EIF_ARCH_PPC_64		6
#define EIF_ARCH_C90		7
#define EIF_ARCH_T3D		8
#define EIF_ARCH_HPPA		9
#define EIF_ARCH_MIPS		10
#define EIF_ARCH_MIPS_64	11
#define EIF_ARCH_ARM6		12
#define EIF_ARCH_VAX		13
#define EIF_ARCH_ALPHA		14
#define EIF_ARCH_IA64		15

/* Define EIF_ARCH value */
#define EIF_ARCH EIF_ARCH_X86_64

/* Is 64 bits platform? */
#define	EIF_64_BITS		/* NC */

#elif defined(GE_MACOS)

/* ABORTSIG:
 *	This symbol holds the signal number (symbol) used by the abort() call. To
 *	actually define the signal symbol, <signal.h> should be included.
 */
#define ABORTSIG SIGABRT		/* NC */

/* MEM_ALIGNBYTES:
 *	This symbol contains the number of bytes required to align a
 *	double. Usual values are 2, 4 and 8.
 */
#define MEM_ALIGNBYTES 8	/* NC */

/* BYTEORDER:
 *	This symbol hold the hexadecimal constant defined in byteorder,
 *	i.e. 0x1234 or 0x4321, etc...
 */
#define BYTEORDER 0x1234	/* large digits for MSB */

/* CAT2:
 *	This macro catenates 2 tokens together.
 */
#if 42 == 1
#define CAT2(a,b)a/* NC */b
#define CAT3(a,b,c)a/* NC */b/* NC */c
#elif 42 == 42
#define CAT2(a,b)a ## b
#define CAT3(a,b,c)a ## b ## c
#endif

#ifndef CAT2
#include "Warning: How does this C preprocessor catenate tokens?"
#endif

/* VAL_NOFILE:
 *	This symbol contains the number of file descriptors available to the
 *	process, as determined at configuration time. Unless a static constant
 *	is needed, you should rely on getdtablesize() to obtain that number.
 */
#define VAL_NOFILE 1024	/* Number of file descriptors */

/* USE_BSDJMP:
 *	This symbol, if defined, indicates that the BSD _setjmp and _longjmp
 *	routines are available to do non-local gotos wihtout saving or restoring
 *	the signal mask flag.
 */
#define USE_BSDJMP		/* NC */

/* HAS_CHOWN:
 *	This symbol, if defined, indicates that the chown routine is
 *	available.
 */
#define HAS_CHOWN		/* NC */

/* HAS_DUP2:
 *	This symbol, if defined, indicates that the dup2 routine is
 *	available to duplicate file descriptors.
 */
#define HAS_DUP2	/* NC */

/* EOFPIPE:
 *	This symbol, if defined, indicates that EOF condition will be detected
 *	by the reader of the pipe when it is closed by the writing process.
 *	That is, a select() call on that file descriptor will not block when
 *	only an EOF remains (typical behaviour for BSD systems).
 */
#define EOFPIPE		/* NC */

/* HAS_FCNTL:
 *	This symbol, if defined, indicates to the C program that
 *	the fcntl() function exists.
 */
#define HAS_FCNTL		/* NC */

/* HAS_FTIME:
 *	This symbol, if defined, indicates that the ftime() routine exists.
 *	It is basically a sub-second accuracy clock, but is less accurate
 *	than gettimeofday(2) anyway. The type "Timeval" should be used to
 *	refer to "struct timeb".
 */
/*#define  HAS_FTIME		 */ /* NC */
#ifdef HAS_FTIME
#define Timeval struct timeb		/* Structure used by ftime() */
#endif

/* HAS_GETTIMEOFDAY:
 *	This symbol, if defined, indicates that the gettimeofday() system
 *	call is available for a sub-second accuracy clock. Usually, the file
 *	<sys/resource.h> needs to be included (see I_SYS_RESOURCE).
 *	The type "Timeval" should be used to refer to "struct timeval".
 */
#define HAS_GETTIMEOFDAY	/* NC */
#ifdef HAS_GETTIMEOFDAY
#define Timeval struct timeval	/* Structure used by gettimeofday() */
#endif

/* HAS_GETGROUPS:
 *	This symbol, if defined, indicates that the getgroups() routine is
 *	available to get the list of process groups.  If unavailable, multiple
 *	groups are probably not supported.
 */
#define HAS_GETGROUPS		/* NC */

/* Groups_t:
 *	This symbol holds the type used for the second argument to
 *	getgroups().  Usually, this is the same of gidtype, but
 *	sometimes it isn't.  It can be int, ushort, uid_t, etc...
 *	It may be necessary to include <sys/types.h> to get any
 *	typedef'ed information.  This is only required if you have
 *	getgroups().
 */
#ifdef HAS_GETGROUPS
#define Groups_t gid_t	/* Type for 2nd arg to getgroups() */
#endif

/* PAGESIZE_VALUE:
 *	This symbol holds the size in bytes of a system page (obtained via
 *	the getpagesize() system call at configuration time or asked to the
 *	user if the system call is not available).
 */
#define PAGESIZE_VALUE 4096	/* System page size, in bytes */

/* SIGNALS_KEPT:
 *	This symbol is defined if signal handlers needn't be reinstated after
 *	receipt of a signal.
 */
#define SIGNALS_KEPT	/* NC */

/* HAS_LINK:
 *	This symbol, if defined, indicates that the link routine is
 *	available to create hard links.
 */
#define HAS_LINK	/* NC */

/* HAS_LSTAT:
 *	This symbol, if defined, indicates that the lstat routine is
 *	available to do file stats on symbolic links.
 */
#define HAS_LSTAT		/* NC */

/* HAS_MKDIR:
 *	This symbol, if defined, indicates that the mkdir routine is available
 *	to create directories.  Otherwise you should fork off a new process to
 *	exec /bin/mkdir.
 */
#define HAS_MKDIR		/* NC */

/* PIDCHECK:
 *	This symbol, if defined, means that the kill(pid, 0) will
 *	check for an active pid (i.e. the kernel will run all the
 *	necessary pid checks, but no signal is actually sent).
 */
#define PIDCHECK		/* NC */

/* HAS_READDIR:
 *	This symbol, if defined, indicates that the readdir routine is
 *	available to read directory entries. You may have to include
 *	<dirent.h>. See I_DIRENT.
 */
#define HAS_READDIR		/* NC */

/* HAS_REWINDDIR:
 *	This symbol, if defined, indicates that the rewinddir routine is
 *	available. You may have to include <dirent.h>. See I_DIRENT.
 */
#define HAS_REWINDDIR		/* NC */

/* HAS_RENAME:
 *	This symbol, if defined, indicates that the rename routine is available
 *	to rename files.  Otherwise you should do the unlink(), link(), unlink()
 *	trick.
 */
#define HAS_RENAME	/* NC */

/* HAS_RMDIR:
 *	This symbol, if defined, indicates that the rmdir routine is
 *	available to remove directories. Otherwise you should fork off a
 *	new process to exec /bin/rmdir.
 */
#define HAS_RMDIR		/* NC */

/* HAS_GETRUSAGE:
 *	This symbol, if defined, indicates that the getrusage() routine is
 *	available to get process statistics with a sub-second accuracy.
 *	Inclusion of <sys/resource.h> and <sys/time.h> may be necessary.
 */
#define HAS_GETRUSAGE		/* NC */

/* HAS_SBRK:
 *	This symbol, if defined, indicates that the sbrk system call is
 *	available to add/relase core. Always true on Unix.
 */
#define HAS_SBRK	/* NC */

/* HAS_SIGACTION:
 *	This symbol, if defined, indicates that the sigaction() routine is
 *	available as a better alternative to the signal call.
 */
#define HAS_SIGACTION		/* NC */

/* HAS_SIGALTSTACK:
 *	This symbol, if defined, indicates that the sigaltstack() routine is
 *	available to set an alternative call stack. Otherwise it means that
 *  a stack overflow will not be correctly handled.
 */
#define HAS_SIGALTSTACK		/* NC */

/* HAS_SYS_SIGLIST:
 *	This symbol, if defined, indicates that the sys_siglist array is
 *	available to translate signal numbers to strings.
 */
#define HAS_SYS_SIGLIST		/* NC */

/* HAS_SIGSETMASK:
 *	This symbol, if defined, indicates that the sigsetmask() routine is
 *	available to set current signal mask. Otherwise, you should probably
 *	emulate this by using signal(), but fear race conditions...
 */
#define HAS_SIGSETMASK		/* NC */

/* HAS_SIGVEC:
 *	This symbol, if defined, indicates that BSD reliable signals are
 *	supported.
 */
#define HAS_SIGVEC	/* NC */

/* HAS_SIGVECTOR:
 *	This symbol, if defined, indicates that the sigvec() routine is called
 *	sigvector() instead, and that sigspace() is provided instead of
 *	sigstack().  This is probably only true for HP-UX.
 */
/*#define  HAS_SIGVECTOR	 */ /* NC */

/* HAS_STRERROR:
 *	This symbol, if defined, indicates that the strerror routine is
 *	available to translate error numbers to strings. See the writeup
 *	of Strerror() in this file before you try to define your own.
 */
#define HAS_STRERROR		/* NC */

/* HAS_SYS_ERRLIST:
 *	This symbol, if defined, indicates that the sys_errlist array is
 *	available to translate error numbers to strings. The extern int
 *	sys_nerr gives the size of that table.
 */
#define HAS_SYS_ERRLIST	/* NC */

/* HAS_SYS_ERRNOLIST:
 *	This symbol, if defined, indicates that the sys_errnolist array is
 *	available to translate an errno code into its symbolic name (e.g.
 * ENOENT). The extern int sys_nerrno gives the size of that table.
 */
/*#define  HAS_SYS_ERRNOLIST	 */ /* NC */

/* Strerror:
 *	This preprocessor symbol is defined as a macro if strerror() is
 *	not available to translate error numbers to strings but sys_errlist[]
 *	array is there.
 */
#define Strerror(e) strerror(e)

/* HAS_TIME:
 *	This symbol, if defined, indicates that the time() routine exists.
 */
#define HAS_TIME		/* NC */

/* Time_t:
 *	This symbol holds the type returned by time(). It can be long,
 *	or time_t on BSD sites (in which case <sys/types.h> should be
 *	included).
 */
#define Time_t time_t		/* Time type */

/* HAS_TIMES:
 *	This symbol, if defined, indicates that the times() routine exists.
 *	Note that this became obsolete on some systems (SUNOS), which now
 * use getrusage(). It may be necessary to include <sys/times.h>.
 */
#define HAS_TIMES		/* NC */

/* HAS_USLEEP:
 *	This symbol, if defined, indicates that the usleep routine is
 *	available to let the process sleep on a sub-second accuracy.
 */
#define HAS_USLEEP		/* NC */

/* HAS_NANOSLEEP:
 *	This symbol, if defined, indicates that the nanosleep routine is
 *	available to let the process sleep on a sub-second accuracy.
 */
#define HAS_NANOSLEEP		/* NC */

/* Signal_t:
 *	This symbol's value is either "void" or "int", corresponding to the
 *	appropriate return type of a signal handler.  Thus, you can declare
 *	a signal handler using "Signal_t (*handler)()", and define the
 *	handler using "Signal_t handler(sig)".
 */
#define Signal_t void	/* Signal handler's return type */

/* I_DIRENT:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <dirent.h>. Using this symbol also triggers the definition
 *	of the Direntry_t define which ends up being 'struct dirent' or
 *	'struct direct' depending on the availability of <dirent.h>.
 */
#define I_DIRENT		/* NC */

/* DIRNAMLEN:
 *	This symbol, if defined, indicates to the C program that the length
 *	of directory entry names is provided by a d_namlen field.  Otherwise
 *	you need to do strlen() on the d_name field.
 */
#define DIRNAMLEN	/* NC */

/* I_FCNTL:
 *	This manifest constant tells the C program to include <fcntl.h>.
 */
/*#define  I_FCNTL	 */ /* NC */

/* I_GRP:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <grp.h>.
 */
#define I_GRP		/* NC */

/* I_LIMITS:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <limits.h> to get definition of symbols like WORD_BIT or
 *	LONG_MAX, i.e. machine dependant limitations.
 */
#define I_LIMITS		/* NC */

/* I_NETINET_IN:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <netinet/in.h>. Otherwise, you may try <sys/in.h>.
 */
#define I_NETINET_IN	/* NC */

/* I_SYS_IN:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/in.h> instead of <netinet/in.h>.
 */
/*#define  I_SYS_IN		 */ /* NC */

/* I_PWD:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <pwd.h>.
 */
#define I_PWD		/* NC */

/* I_SYS_DIR:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/dir.h>.
 */
#define I_SYS_DIR		/* NC */

/* I_SYS_FILE:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/file.h> to get definition of R_OK and friends.
 */
#define I_SYS_FILE		/* NC */

/* I_SYS_NDIR:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/ndir.h>.
 */
/*#define  I_SYS_NDIR	 */ /* NC */

/* I_SYS_RESOURCE:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/resource.h>.
 */
#define I_SYS_RESOURCE		/* NC */

/* I_SYS_SOCKET:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/socket.h> before performing socket calls.
 */
#define I_SYS_SOCKET		/* NC */

/* I_SYS_TIMEB:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/timeb.h>, in order to define struct timeb (some systems
 *	define this in <sys/time.h>). This is useful when using ftime().
 *	You should include <sys/time.h> if I_SYS_TIMEB is not defined,
 *	nor is I_SYS_TIME.
 */
#define I_SYS_TIMEB		/* NC */

/* I_SYS_TIMES:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/times.h>.
 */
#define	I_SYS_TIMES		/* NC */

/* I_SYS_UN:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/un.h> to get UNIX domain socket definitions.
 */
#define I_SYS_UN		/* NC */

/* I_TIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <time.h>.
 */
/*#define  I_TIME		 */ /* NC */

/* I_SYS_TIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/time.h>.
 */
#define I_SYS_TIME		/* NC */

/* I_SYS_TIME_KERNEL:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/time.h> with KERNEL defined.
 */
/*#define  I_SYS_TIME_KERNEL		 */ /* NC */

/* I_UTIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <utime.h>.
 */
#define I_UTIME		/* NC */

/* I_SYSUTIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/utime.h>.
 */
/*#define  I_SYSUTIME		 */ /* NC */

/* I_STDARG:
 *	This symbol, if defined, indicates that <stdarg.h> exists and should
 *	be included.
 */
#define I_STDARG		/* NC */

/* I_VARARGS:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <varargs.h>.
 */
/*#define  I_VARARGS	 */ /* NC */

/* INTSIZE:
 *	This symbol contains the size of an int, so that the C preprocessor
 *	can make decisions based on it.
 */
#define INTSIZE 4		/* NC */

/* Malloc_t:
 *	This symbol is the type of pointer returned by malloc and realloc.
 */
#define Malloc_t void *			/* NC */

/* Pid_t:
 *	This symbol holds the type used to declare process ids in the kernel.
 *	It can be int, uint, pid_t, etc... It may be necessary to include
 *	<sys/types.h> to get any typedef'ed information.
 */
#define Pid_t pid_t		/* PID type */

/* CAN_PROTOTYPE:
 *	If defined, this macro indicates that the C compiler can handle
 *	function prototypes.
 */
#define	CAN_PROTOTYPE	/* NC */

/* _:
 *	This macro is used to declare function parameters for folks who want
 *	to make declarations with prototypes using a different style than
 *	the above macros.  Use double parentheses.  For example:
 *
 *		int main _((int argc, char *argv[]));
 */
#ifdef CAN_PROTOTYPE
#define	_(args) args
#else
#define	_(args) ()
#endif

/* HAS_SMART_SBRK:
 *	This symbol is defined when the sbrk() system call may be used with
 *	a negative argument to lower the break value, therefore releasing
 *	core to the system. If not, you'd probably be better off using the
 *	mmap() system call.
 */
/*#define  HAS_SMART_SBRK  */ /* NC */

/* Select_fd_set_t:
 *	This symbol holds the type used for the 2nd, 3rd, and 4th
 *	arguments to select.  Usually, this is 'fd_set *', if HAS_FD_SET
 *	is defined, and 'int *' otherwise.  This is only useful if you
 *	have select(), of course.
 */
#define Select_fd_set_t 	fd_set *	/* NC */

/* CAN_KEEPALIVE:
 *	This symbol if defined indicates to the C program that the SO_KEEPALIVE
 *	option of setsockopt() will work as advertised in the manual.
 */
/*#define  CAN_KEEPALIVE		 */ /* NC */

/* Uid_t:
 *	This symbol holds the type used to declare user ids in the kernel.
 *	It can be int, ushort, uid_t, etc... It may be necessary to include
 *	<sys/types.h> to get any typedef'ed information.
 */
#define Uid_t uid_t		/* UID type */

/* VOIDFLAGS:
 *	This symbol indicates how much support of the void type is given by this
 *	compiler.  What various bits mean:
 *
 *	    1 = supports declaration of void
 *	    2 = supports arrays of pointers to functions returning void
 *	    4 = supports comparisons between pointers to void functions and
 *		    addresses of void functions
 *	    8 = suports declaration of generic void pointers
 *
 *	The package designer should define VOIDUSED to indicate the requirements
 *	of the package.  This can be done either by #defining VOIDUSED before
 *	including eif_config.h, or by defining defvoidused in Myinit.U.  If the
 *	latter approach is taken, only those flags will be tested.  If the
 *	level of void support necessary is not present, defines void to int.
 */
#ifndef VOIDUSED
#define VOIDUSED 15
#endif
#define VOIDFLAGS 15
#if (VOIDFLAGS & VOIDUSED) != VOIDUSED
#define void int		/* is void to be avoided? */
#define M_VOID			/* Xenix strikes again */
#endif

/* USE_ADD_LOG:
 *	This symbol is defined if the run time logging is enabled, mainly for
 *	debugging purposes (although the logging level may be set to a low level
 *	to leave only critical error messages). This will never be defined by
 *	default.
 */
/*#define  USE_ADD_LOG		 */ /* Allow logging */
#define LOGGING_LEVEL	9	/* Logging level */

/* HAS_SMART_MMAP:
 *	This symbol, if defined, indicates to the C program that it can
 *	use mmap and munmap for shared memory.
 */
/*#define  HAS_SMART_MMAP	 */ /* NC */

/* HAS_GETPWUID:
 *	This symbol, if defined, indicates that the getpwuid system call is
 *	available
 */
#define HAS_GETPWUID	/* NC */

/* HAS_GETGRGID:
 *	This symbol, if defined, indicates that the getgrgid system call is
 *	available
 */
#define HAS_GETGRGID	/* NC */

/* HAS_GETEUID:
 *	This symbol, if defined, indicates that the geteuid system call is
 *	available
 */
#define HAS_GETEUID	/* NC */

/* HAS_UNLINK:
 *	This symbol, if defined, indicates that the unlink routine is
 *	available.
 */
#define HAS_UNLINK	/* NC */

/* HAS_UTIME:
 *	This symbol, if defined, indicates that the utime routine is
 *	available.
 */
#define HAS_UTIME	/* NC */

/* I_FD_SET_SYS_SELECT:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/select.h> in order to get definition of struct fd_set.
 */
/*#define  I_FD_SET_SYS_SELECT	 */ /* NC */

/* I_TMVAL_SYS_SELECT:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/select.h> in order to get definition of struct timeval.
 *.I_SYS_SELECT is not set correctly in the dist3.0 p22
 * This unit overrides the default one. It checks the content of
 * the include file <sys/select.h> to find the definition of timeval
 */
/*#define  I_TMVAL_SYS_SELECT	 */ /* NC */

/* MAY_PANIC:
 *	This symbol is defined if the run-time is to be compiled with extra
 *	consistency checks. Those checks make sure some "impossible" conditions
 *	never occur, and they raise a panic if they do. Typical checks include
 *	free-list consistency check, stack overflow or underflow, etc...
 */
/*#define  MAY_PANIC	 */ /* Extra run-time consistency checks */

/* USE_BSD_SIGNALS:
 * On some Unix, we need to define _BSD_SIGNALS (e.g IRIX*)
 */

/*#define  USE_BSD_SIGNALS	 */ /* NC */

/* USE_TLS:
 *	This symbol, if defined, indicates that thread-local storage specifier
 *	can be used to access thread-local variables.
 */
/*#define  USE_TLS	 */ /* NC */

/* INTEGER_64 display format:
 * 	This symbol is used in printf and others to display 64 bits signed
 *	integers.
 */

#define EIF_INTEGER_64_DISPLAY "lld"
#define EIF_NATURAL_64_DISPLAY "llu"
/* GOBO #define EIF_POINTER_DISPLAY "lX" */

/* Does current platform support conversion from uin64 to floating point? */
#define	HAS_BUILTIN_CONVERSION_FROM_UINT64_TO_FLOATING_POINT	/* NC */

/* INTEGER_64 constant definition: */
#ifndef RTI64C
#define RTI64C(x)	CAT2(x,LL)
#endif
#ifndef RTU64C
#define RTU64C(x)	CAT2(x,ULL)
#endif

/* Define EIF_OS Constants */

#define EIF_OS_WINNT 	1
#define EIF_OS_LINUX 	2
#define EIF_OS_SUNOS	3
#define EIF_OS_DARWIN 	4
#define EIF_OS_ALPHA 	5
#define EIF_OS_FREEBSD 	6
#define EIF_OS_HPUX 	7
#define EIF_OS_IRIX 	8
#define EIF_OS_OPENBSD 	9
#define EIF_OS_UNICOS 	10
#define EIF_OS_VXWORKS	11
#define EIF_OS_VMS  	12
#define EIF_OS_HAIKU	13
#define EIF_OS_IPHONE	14

/* Define EIF_OS value */
#define EIF_OS EIF_OS_DARWIN

/* Define EIF_ARCH Constants */

#define EIF_ARCH_X86 		1
#define EIF_ARCH_X86_64 	2
#define EIF_ARCH_SPARC 		3
#define EIF_ARCH_SPARC_64 	4
#define EIF_ARCH_PPC		5
#define EIF_ARCH_PPC_64		6
#define EIF_ARCH_C90		7
#define EIF_ARCH_T3D		8
#define EIF_ARCH_HPPA		9
#define EIF_ARCH_MIPS		10
#define EIF_ARCH_MIPS_64	11
#define EIF_ARCH_ARM6		12
#define EIF_ARCH_VAX		13
#define EIF_ARCH_ALPHA		14
#define EIF_ARCH_IA64		15

/* Define EIF_ARCH value */
#define EIF_ARCH EIF_ARCH_X86_64

/* Is 64 bits platform? */
#define	EIF_64_BITS		/* NC */

#else

/* ABORTSIG:
 *	This symbol holds the signal number (symbol) used by the abort() call. To
 *	actually define the signal symbol, <signal.h> should be included.
 */
#define ABORTSIG SIGABRT		/* NC */

/* MEM_ALIGNBYTES:
 *	This symbol contains the number of bytes required to align a
 *	double. Usual values are 2, 4 and 8.
 */
#define MEM_ALIGNBYTES 8	/* NC */

/* BYTEORDER:
 *	This symbol hold the hexadecimal constant defined in byteorder,
 *	i.e. 0x1234 or 0x4321, etc...
 */
#define BYTEORDER 0x1234	/* large digits for MSB */

/* CAT2:
 *	This macro catenates 2 tokens together.
 */
#if 42 == 1
#define CAT2(a,b)a/* NC */b
#define CAT3(a,b,c)a/* NC */b/* NC */c
#elif 42 == 42
#define CAT2(a,b)a ## b
#define CAT3(a,b,c)a ## b ## c
#endif

#ifndef CAT2
#include "Warning: How does this C preprocessor catenate tokens?"
#endif

/* VAL_NOFILE:
 *	This symbol contains the number of file descriptors available to the
 *	process, as determined at configuration time. Unless a static constant
 *	is needed, you should rely on getdtablesize() to obtain that number.
 */
#define VAL_NOFILE 1024	/* Number of file descriptors */

/* USE_BSDJMP:
 *	This symbol, if defined, indicates that the BSD _setjmp and _longjmp
 *	routines are available to do non-local gotos wihtout saving or restoring
 *	the signal mask flag.
 */
#define USE_BSDJMP		/* NC */

/* HAS_CHOWN:
 *	This symbol, if defined, indicates that the chown routine is
 *	available.
 */
#define HAS_CHOWN		/* NC */

/* HAS_DUP2:
 *	This symbol, if defined, indicates that the dup2 routine is
 *	available to duplicate file descriptors.
 */
#define HAS_DUP2	/* NC */

/* EOFPIPE:
 *	This symbol, if defined, indicates that EOF condition will be detected
 *	by the reader of the pipe when it is closed by the writing process.
 *	That is, a select() call on that file descriptor will not block when
 *	only an EOF remains (typical behaviour for BSD systems).
 */
#define EOFPIPE		/* NC */

/* HAS_FCNTL:
 *	This symbol, if defined, indicates to the C program that
 *	the fcntl() function exists.
 */
#define HAS_FCNTL		/* NC */

/* HAS_FTIME:
 *	This symbol, if defined, indicates that the ftime() routine exists.
 *	It is basically a sub-second accuracy clock, but is less accurate
 *	than gettimeofday(2) anyway. The type "Timeval" should be used to
 *	refer to "struct timeb".
 */
/*#define  HAS_FTIME		 */ /* NC */
#ifdef HAS_FTIME
#define Timeval struct timeb		/* Structure used by ftime() */
#endif

/* HAS_GETTIMEOFDAY:
 *	This symbol, if defined, indicates that the gettimeofday() system
 *	call is available for a sub-second accuracy clock. Usually, the file
 *	<sys/resource.h> needs to be included (see I_SYS_RESOURCE).
 *	The type "Timeval" should be used to refer to "struct timeval".
 */
#define HAS_GETTIMEOFDAY	/* NC */
#ifdef HAS_GETTIMEOFDAY
#define Timeval struct timeval	/* Structure used by gettimeofday() */
#endif

/* HAS_GETGROUPS:
 *	This symbol, if defined, indicates that the getgroups() routine is
 *	available to get the list of process groups.  If unavailable, multiple
 *	groups are probably not supported.
 */
#define HAS_GETGROUPS		/* NC */

/* Groups_t:
 *	This symbol holds the type used for the second argument to
 *	getgroups().  Usually, this is the same of gidtype, but
 *	sometimes it isn't.  It can be int, ushort, uid_t, etc...
 *	It may be necessary to include <sys/types.h> to get any
 *	typedef'ed information.  This is only required if you have
 *	getgroups().
 */
#ifdef HAS_GETGROUPS
#define Groups_t gid_t	/* Type for 2nd arg to getgroups() */
#endif

/* PAGESIZE_VALUE:
 *	This symbol holds the size in bytes of a system page (obtained via
 *	the getpagesize() system call at configuration time or asked to the
 *	user if the system call is not available).
 */
#define PAGESIZE_VALUE 4096	/* System page size, in bytes */

/* SIGNALS_KEPT:
 *	This symbol is defined if signal handlers needn't be reinstated after
 *	receipt of a signal.
 */
#define SIGNALS_KEPT	/* NC */

/* HAS_LINK:
 *	This symbol, if defined, indicates that the link routine is
 *	available to create hard links.
 */
#define HAS_LINK	/* NC */

/* HAS_LSTAT:
 *	This symbol, if defined, indicates that the lstat routine is
 *	available to do file stats on symbolic links.
 */
#define HAS_LSTAT		/* NC */

/* HAS_MKDIR:
 *	This symbol, if defined, indicates that the mkdir routine is available
 *	to create directories.  Otherwise you should fork off a new process to
 *	exec /bin/mkdir.
 */
#define HAS_MKDIR		/* NC */

/* PIDCHECK:
 *	This symbol, if defined, means that the kill(pid, 0) will
 *	check for an active pid (i.e. the kernel will run all the
 *	necessary pid checks, but no signal is actually sent).
 */
#define PIDCHECK		/* NC */

/* HAS_READDIR:
 *	This symbol, if defined, indicates that the readdir routine is
 *	available to read directory entries. You may have to include
 *	<dirent.h>. See I_DIRENT.
 */
#define HAS_READDIR		/* NC */

/* HAS_REWINDDIR:
 *	This symbol, if defined, indicates that the rewinddir routine is
 *	available. You may have to include <dirent.h>. See I_DIRENT.
 */
#define HAS_REWINDDIR		/* NC */

/* HAS_RENAME:
 *	This symbol, if defined, indicates that the rename routine is available
 *	to rename files.  Otherwise you should do the unlink(), link(), unlink()
 *	trick.
 */
#define HAS_RENAME	/* NC */

/* HAS_RMDIR:
 *	This symbol, if defined, indicates that the rmdir routine is
 *	available to remove directories. Otherwise you should fork off a
 *	new process to exec /bin/rmdir.
 */
#define HAS_RMDIR		/* NC */

/* HAS_GETRUSAGE:
 *	This symbol, if defined, indicates that the getrusage() routine is
 *	available to get process statistics with a sub-second accuracy.
 *	Inclusion of <sys/resource.h> and <sys/time.h> may be necessary.
 */
#define HAS_GETRUSAGE		/* NC */

/* HAS_SBRK:
 *	This symbol, if defined, indicates that the sbrk system call is
 *	available to add/relase core. Always true on Unix.
 */
#define HAS_SBRK	/* NC */

/* HAS_SIGACTION:
 *	This symbol, if defined, indicates that the sigaction() routine is
 *	available as a better alternative to the signal call.
 */
#define HAS_SIGACTION		/* NC */

/* HAS_SIGALTSTACK:
 *	This symbol, if defined, indicates that the sigaltstack() routine is
 *	available to set an alternative call stack. Otherwise it means that
 *  a stack overflow will not be correctly handled.
 */
#define HAS_SIGALTSTACK		/* NC */

/* HAS_SYS_SIGLIST:
 *	This symbol, if defined, indicates that the sys_siglist array is
 *	available to translate signal numbers to strings.
 */
#define HAS_SYS_SIGLIST		/* NC */

/* HAS_SIGSETMASK:
 *	This symbol, if defined, indicates that the sigsetmask() routine is
 *	available to set current signal mask. Otherwise, you should probably
 *	emulate this by using signal(), but fear race conditions...
 */
#define HAS_SIGSETMASK		/* NC */

/* HAS_SIGVEC:
 *	This symbol, if defined, indicates that BSD reliable signals are
 *	supported.
 */
#define HAS_SIGVEC	/* NC */

/* HAS_SIGVECTOR:
 *	This symbol, if defined, indicates that the sigvec() routine is called
 *	sigvector() instead, and that sigspace() is provided instead of
 *	sigstack().  This is probably only true for HP-UX.
 */
/*#define  HAS_SIGVECTOR	 */ /* NC */

/* HAS_STRERROR:
 *	This symbol, if defined, indicates that the strerror routine is
 *	available to translate error numbers to strings. See the writeup
 *	of Strerror() in this file before you try to define your own.
 */
#define HAS_STRERROR		/* NC */

/* HAS_SYS_ERRLIST:
 *	This symbol, if defined, indicates that the sys_errlist array is
 *	available to translate error numbers to strings. The extern int
 *	sys_nerr gives the size of that table.
 */
#define HAS_SYS_ERRLIST	/* NC */

/* HAS_SYS_ERRNOLIST:
 *	This symbol, if defined, indicates that the sys_errnolist array is
 *	available to translate an errno code into its symbolic name (e.g.
 * ENOENT). The extern int sys_nerrno gives the size of that table.
 */
/*#define  HAS_SYS_ERRNOLIST	 */ /* NC */

/* Strerror:
 *	This preprocessor symbol is defined as a macro if strerror() is
 *	not available to translate error numbers to strings but sys_errlist[]
 *	array is there.
 */
#define Strerror(e) strerror(e)

/* HAS_TIME:
 *	This symbol, if defined, indicates that the time() routine exists.
 */
#define HAS_TIME		/* NC */

/* Time_t:
 *	This symbol holds the type returned by time(). It can be long,
 *	or time_t on BSD sites (in which case <sys/types.h> should be
 *	included).
 */
#define Time_t time_t		/* Time type */

/* HAS_TIMES:
 *	This symbol, if defined, indicates that the times() routine exists.
 *	Note that this became obsolete on some systems (SUNOS), which now
 * use getrusage(). It may be necessary to include <sys/times.h>.
 */
#define HAS_TIMES		/* NC */

/* HAS_USLEEP:
 *	This symbol, if defined, indicates that the usleep routine is
 *	available to let the process sleep on a sub-second accuracy.
 */
#define HAS_USLEEP		/* NC */

/* HAS_NANOSLEEP:
 *	This symbol, if defined, indicates that the nanosleep routine is
 *	available to let the process sleep on a sub-second accuracy.
 */
#define HAS_NANOSLEEP		/* NC */

/* Signal_t:
 *	This symbol's value is either "void" or "int", corresponding to the
 *	appropriate return type of a signal handler.  Thus, you can declare
 *	a signal handler using "Signal_t (*handler)()", and define the
 *	handler using "Signal_t handler(sig)".
 */
#define Signal_t void	/* Signal handler's return type */

/* I_DIRENT:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <dirent.h>. Using this symbol also triggers the definition
 *	of the Direntry_t define which ends up being 'struct dirent' or
 *	'struct direct' depending on the availability of <dirent.h>.
 */
#define I_DIRENT		/* NC */

/* DIRNAMLEN:
 *	This symbol, if defined, indicates to the C program that the length
 *	of directory entry names is provided by a d_namlen field.  Otherwise
 *	you need to do strlen() on the d_name field.
 */
/*#define  DIRNAMLEN	 */ /* NC */

/* I_FCNTL:
 *	This manifest constant tells the C program to include <fcntl.h>.
 */
/*#define  I_FCNTL	 */ /* NC */

/* I_GRP:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <grp.h>.
 */
#define I_GRP		/* NC */

/* I_LIMITS:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <limits.h> to get definition of symbols like WORD_BIT or
 *	LONG_MAX, i.e. machine dependant limitations.
 */
#define I_LIMITS		/* NC */

/* I_NETINET_IN:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <netinet/in.h>. Otherwise, you may try <sys/in.h>.
 */
#define I_NETINET_IN	/* NC */

/* I_SYS_IN:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/in.h> instead of <netinet/in.h>.
 */
/*#define  I_SYS_IN		 */ /* NC */

/* I_PWD:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <pwd.h>.
 */
#define I_PWD		/* NC */

/* I_SYS_DIR:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/dir.h>.
 */
#define I_SYS_DIR		/* NC */

/* I_SYS_FILE:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/file.h> to get definition of R_OK and friends.
 */
#define I_SYS_FILE		/* NC */

/* I_SYS_NDIR:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/ndir.h>.
 */
/*#define  I_SYS_NDIR	 */ /* NC */

/* I_SYS_RESOURCE:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/resource.h>.
 */
#define I_SYS_RESOURCE		/* NC */

/* I_SYS_SOCKET:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/socket.h> before performing socket calls.
 */
#define I_SYS_SOCKET		/* NC */

/* I_SYS_TIMEB:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/timeb.h>, in order to define struct timeb (some systems
 *	define this in <sys/time.h>). This is useful when using ftime().
 *	You should include <sys/time.h> if I_SYS_TIMEB is not defined,
 *	nor is I_SYS_TIME.
 */
#define I_SYS_TIMEB		/* NC */

/* I_SYS_TIMES:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/times.h>.
 */
#define	I_SYS_TIMES		/* NC */

/* I_SYS_UN:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/un.h> to get UNIX domain socket definitions.
 */
#define I_SYS_UN		/* NC */

/* I_TIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <time.h>.
 */
#define I_TIME		/* NC */

/* I_SYS_TIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/time.h>.
 */
#define I_SYS_TIME		/* NC */

/* I_SYS_TIME_KERNEL:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/time.h> with KERNEL defined.
 */
/*#define  I_SYS_TIME_KERNEL		 */ /* NC */

/* I_UTIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <utime.h>.
 */
#define I_UTIME		/* NC */

/* I_SYSUTIME:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/utime.h>.
 */
/*#define  I_SYSUTIME		 */ /* NC */

/* I_STDARG:
 *	This symbol, if defined, indicates that <stdarg.h> exists and should
 *	be included.
 */
#define I_STDARG		/* NC */

/* I_VARARGS:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <varargs.h>.
 */
/*#define  I_VARARGS	 */ /* NC */

/* INTSIZE:
 *	This symbol contains the size of an int, so that the C preprocessor
 *	can make decisions based on it.
 */
#define INTSIZE 4		/* NC */

/* Malloc_t:
 *	This symbol is the type of pointer returned by malloc and realloc.
 */
#define Malloc_t void *			/* NC */

/* Pid_t:
 *	This symbol holds the type used to declare process ids in the kernel.
 *	It can be int, uint, pid_t, etc... It may be necessary to include
 *	<sys/types.h> to get any typedef'ed information.
 */
#define Pid_t pid_t		/* PID type */

/* CAN_PROTOTYPE:
 *	If defined, this macro indicates that the C compiler can handle
 *	function prototypes.
 */
#define	CAN_PROTOTYPE	/* NC */

/* _:
 *	This macro is used to declare function parameters for folks who want
 *	to make declarations with prototypes using a different style than
 *	the above macros.  Use double parentheses.  For example:
 *
 *		int main _((int argc, char *argv[]));
 */
#ifdef CAN_PROTOTYPE
#define	_(args) args
#else
#define	_(args) ()
#endif

/* HAS_SMART_SBRK:
 *	This symbol is defined when the sbrk() system call may be used with
 *	a negative argument to lower the break value, therefore releasing
 *	core to the system. If not, you'd probably be better off using the
 *	mmap() system call.
 */
/*#define  HAS_SMART_SBRK  */ /* NC */

/* Select_fd_set_t:
 *	This symbol holds the type used for the 2nd, 3rd, and 4th
 *	arguments to select.  Usually, this is 'fd_set *', if HAS_FD_SET
 *	is defined, and 'int *' otherwise.  This is only useful if you
 *	have select(), of course.
 */
#define Select_fd_set_t 	fd_set *	/* NC */

/* CAN_KEEPALIVE:
 *	This symbol if defined indicates to the C program that the SO_KEEPALIVE
 *	option of setsockopt() will work as advertised in the manual.
 */
/*#define  CAN_KEEPALIVE		 */ /* NC */

/* Uid_t:
 *	This symbol holds the type used to declare user ids in the kernel.
 *	It can be int, ushort, uid_t, etc... It may be necessary to include
 *	<sys/types.h> to get any typedef'ed information.
 */
#define Uid_t uid_t		/* UID type */

/* VOIDFLAGS:
 *	This symbol indicates how much support of the void type is given by this
 *	compiler.  What various bits mean:
 *
 *	    1 = supports declaration of void
 *	    2 = supports arrays of pointers to functions returning void
 *	    4 = supports comparisons between pointers to void functions and
 *		    addresses of void functions
 *	    8 = suports declaration of generic void pointers
 *
 *	The package designer should define VOIDUSED to indicate the requirements
 *	of the package.  This can be done either by #defining VOIDUSED before
 *	including eif_config.h, or by defining defvoidused in Myinit.U.  If the
 *	latter approach is taken, only those flags will be tested.  If the
 *	level of void support necessary is not present, defines void to int.
 */
#ifndef VOIDUSED
#define VOIDUSED 15
#endif
#define VOIDFLAGS 15
#if (VOIDFLAGS & VOIDUSED) != VOIDUSED
#define void int		/* is void to be avoided? */
#define M_VOID			/* Xenix strikes again */
#endif

/* USE_ADD_LOG:
 *	This symbol is defined if the run time logging is enabled, mainly for
 *	debugging purposes (although the logging level may be set to a low level
 *	to leave only critical error messages). This will never be defined by
 *	default.
 */
/*#define  USE_ADD_LOG		 */ /* Allow logging */
#define LOGGING_LEVEL	9	/* Logging level */

/* HAS_SMART_MMAP:
 *	This symbol, if defined, indicates to the C program that it can
 *	use mmap and munmap for shared memory.
 */
/*#define  HAS_SMART_MMAP	 */ /* NC */

/* HAS_GETPWUID:
 *	This symbol, if defined, indicates that the getpwuid system call is
 *	available
 */
#define HAS_GETPWUID	/* NC */

/* HAS_GETGRGID:
 *	This symbol, if defined, indicates that the getgrgid system call is
 *	available
 */
#define HAS_GETGRGID	/* NC */

/* HAS_GETEUID:
 *	This symbol, if defined, indicates that the geteuid system call is
 *	available
 */
#define HAS_GETEUID	/* NC */

/* HAS_UNLINK:
 *	This symbol, if defined, indicates that the unlink routine is
 *	available.
 */
#define HAS_UNLINK	/* NC */

/* HAS_UTIME:
 *	This symbol, if defined, indicates that the utime routine is
 *	available.
 */
#define HAS_UTIME	/* NC */

/* I_FD_SET_SYS_SELECT:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/select.h> in order to get definition of struct fd_set.
 */
/*#define  I_FD_SET_SYS_SELECT	 */ /* NC */

/* I_TMVAL_SYS_SELECT:
 *	This symbol, if defined, indicates to the C program that it should
 *	include <sys/select.h> in order to get definition of struct timeval.
 *.I_SYS_SELECT is not set correctly in the dist3.0 p22
 * This unit overrides the default one. It checks the content of
 * the include file <sys/select.h> to find the definition of timeval
 */
/*#define  I_TMVAL_SYS_SELECT	 */ /* NC */

/* MAY_PANIC:
 *	This symbol is defined if the run-time is to be compiled with extra
 *	consistency checks. Those checks make sure some "impossible" conditions
 *	never occur, and they raise a panic if they do. Typical checks include
 *	free-list consistency check, stack overflow or underflow, etc...
 */
/*#define  MAY_PANIC	 */ /* Extra run-time consistency checks */

/* USE_BSD_SIGNALS:
 * On some Unix, we need to define _BSD_SIGNALS (e.g IRIX*)
 */

/*#define  USE_BSD_SIGNALS	 */ /* NC */

/* USE_TLS:
 *	This symbol, if defined, indicates that thread-local storage specifier
 *	can be used to access thread-local variables.
 */
/*#define  USE_TLS	 */ /* NC */

/* INTEGER_64 display format:
 * 	This symbol is used in printf and others to display 64 bits signed
 *	integers.
 */

#define EIF_INTEGER_64_DISPLAY "lld"
#define EIF_NATURAL_64_DISPLAY "llu"
/* GOBO #define EIF_POINTER_DISPLAY "lX" */

/* Does current platform support conversion from uin64 to floating point? */
#define	HAS_BUILTIN_CONVERSION_FROM_UINT64_TO_FLOATING_POINT	/* NC */

/* INTEGER_64 constant definition: */
#ifndef RTI64C
#define RTI64C(x)	CAT2(x,LL)
#endif
#ifndef RTU64C
#define RTU64C(x)	CAT2(x,ULL)
#endif

/* Define EIF_OS Constants */

#define EIF_OS_WINNT 	1
#define EIF_OS_LINUX 	2
#define EIF_OS_SUNOS	3
#define EIF_OS_DARWIN 	4
#define EIF_OS_ALPHA 	5
#define EIF_OS_FREEBSD 	6
#define EIF_OS_HPUX 	7
#define EIF_OS_IRIX 	8
#define EIF_OS_OPENBSD 	9
#define EIF_OS_UNICOS 	10
#define EIF_OS_VXWORKS	11
#define EIF_OS_VMS  	12
#define EIF_OS_HAIKU	13
#define EIF_OS_IPHONE	14

/* Define EIF_OS value */
#define EIF_OS EIF_OS_LINUX

/* Define EIF_ARCH Constants */

#define EIF_ARCH_X86 		1
#define EIF_ARCH_X86_64 	2
#define EIF_ARCH_SPARC 		3
#define EIF_ARCH_SPARC_64 	4
#define EIF_ARCH_PPC		5
#define EIF_ARCH_PPC_64		6
#define EIF_ARCH_C90		7
#define EIF_ARCH_T3D		8
#define EIF_ARCH_HPPA		9
#define EIF_ARCH_MIPS		10
#define EIF_ARCH_MIPS_64	11
#define EIF_ARCH_ARM6		12
#define EIF_ARCH_VAX		13
#define EIF_ARCH_ALPHA		14
#define EIF_ARCH_IA64		15

/* Define EIF_ARCH value */
#define EIF_ARCH EIF_ARCH_X86_64

/* Is 64 bits platform? */
#define	EIF_64_BITS		/* NC */

#endif

#endif
/*
	description:

		"C functions used to implement class FILE"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2006-2026, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef EIF_FILE_H
#define EIF_FILE_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif
#ifndef EIF_CONFIG_H
#include "eif_config.h"
#endif

#include <time.h>
#include <sys/stat.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Let's define the stat structure for our platforms. */
/* The definition is the same for both ANSI and Unicode versions on Windows. */
#ifdef EIF_WINDOWS
#	ifdef __LCC__
#		define rt_stat_buf	struct stat
#	elif defined EIF_64_BITS
#		define rt_stat_buf	struct _stat64
#	else
#		define rt_stat_buf	struct _stat64i32
#	endif
#else
#	define rt_stat_buf		struct stat
#endif

/*
 * Create directory `dirname'.
 */
extern void eif_file_mkdir(EIF_FILENAME dirname);

/*
 * Rename file `from' into `to'.
 */
extern void eif_file_rename(EIF_FILENAME from, EIF_FILENAME  to);

/*
 * Link file `from' into `to'.
 */
extern void eif_file_link(EIF_FILENAME from, EIF_FILENAME to);

/*
 * Delete file or directory `name'.
 */
extern void eif_file_unlink(EIF_FILENAME name);

/*
 * Open file `name' with the corresponding type `how'.
 */
extern EIF_POINTER eif_file_open(EIF_FILENAME name, int how);

/*
 * Open file `fd' with the corresponding type `how'.
 */
extern EIF_POINTER eif_file_dopen(int fd, int how);

/*
 * Reopen file `name' with the corresponding type `how' and substitute that
 * to the old stream described by `old'. This is useful to redirect 'stdout'
 * to another place, for instance.
 */
extern EIF_POINTER eif_file_reopen(EIF_FILENAME name, int how, FILE *old);

/*
 * Close the file.
 */
extern void eif_file_close(FILE *fp);

/*
 * Flush data held in stdio buffer.
 */
extern void eif_file_flush(FILE *fp);

/*
 * Return the associated file descriptor.
 */
extern EIF_INTEGER eif_file_fd(FILE *f);

/*
 * Get a character from `f'.
 */
extern EIF_CHARACTER_8 eif_file_gc(FILE *f);

/*
 * Get a string from `f' and fill it into `s' (at most `bound' characters),
 * with `start' being the amount of bytes already stored within s. This
 * means we really have to read (bound - start) characters.
 */
extern EIF_INTEGER eif_file_gs(FILE *f, char *s, EIF_INTEGER bound, EIF_INTEGER start);

/*
 * Read min (bound, remaining bytes in file) characters into `s' and
 * return the number of characters read.
 */
extern EIF_INTEGER eif_file_gss(FILE *f, char *s, EIF_INTEGER bound);

/*
 * Get a word from `f' and fill it into `s' (at most `bound' characters),
 * with `start' being the amount of bytes already stored within s. This
 * means we really have to read (bound - start) characters. Any leading
 * spaces are skipped.
 */
extern EIF_INTEGER eif_file_gw(FILE *f, char *s, EIF_INTEGER bound, EIF_INTEGER start);

/*
 * Look ahead one character. If EOF, return 0.
 */
extern EIF_CHARACTER_8 eif_file_lh(FILE *f);

/*
 * Size of file `fp'.
 */
extern EIF_INTEGER eif_file_size(FILE *fp);

/*
 * Read upto next input line.
 */
extern void eif_file_tnil(FILE *f);

/*
 * Current position within file.
 */
extern EIF_INTEGER eif_file_tell(FILE *f);

/*
 * Touch file `name' by setting both access and modification time to the
 * current time stamp. This external function exists only because there
 * is no way within UNIX_FILE to get the current time stamp. Otherwise,
 * we could simply call file_utime.
 */
extern void eif_file_touch(EIF_FILENAME name);

/*
 * Modify the modification and/or the access time stored in the file's
 * inode. The 'how' parameter tells which attributes should be set.
 */
extern void eif_file_utime(EIF_FILENAME name, time_t stamp, int how);

/*
 * This is an encapsulation of the stat() system call. The routine either
 * succeeds and returns or fails and raises the appropriate exception.
 */
extern int eif_file_stat(EIF_FILENAME path, rt_stat_buf *buf, int follow);

/*
 * Change permissions of file `name', using an interface like chmod(1).
 * The flag is true if permissions are to be added, 0 to remove them.
 */
extern void eif_file_perm(EIF_FILENAME name, char *who, char *what, int flag);

/*
 * Change permission mode on file `path'.
 */
extern void eif_file_chmod(EIF_FILENAME path, int mode);

/*
 * Change the owner of the file to `uid'.
 */
extern void eif_file_chown(EIF_FILENAME name, int uid);

/*
 * Change the group of the file to `gid'.
 */
extern void eif_file_chgrp(EIF_FILENAME name, int gid);

/*
 * Put new_line onto `f'.
 */
extern void eif_file_tnwl(FILE *f);

/*
 * Append a copy of `other' to `f'.
 */
extern void eif_file_append(FILE *f, FILE *other, EIF_INTEGER l);

/*
 * Write string `str' on `f'.
 */
extern void eif_file_ps(FILE *f, char *str, EIF_INTEGER len);

/*
 * Write character `c' on `f'.
 */
extern void eif_file_pc(FILE *f, char c);

/*
 * Go to absolute position `pos' counted from start.
 */
extern void eif_file_go(FILE *f, EIF_INTEGER pos);

/*
 * Go to absolute position `pos' counted from end.
 */
extern void eif_file_recede(FILE *f, EIF_INTEGER pos);

/*
 * Go to absolute position `pos' counted from current position.
 */
extern void eif_file_move(FILE *f, EIF_INTEGER pos);

/*
 * End of file.
 */
extern EIF_BOOLEAN eif_file_feof(FILE *fp);

/*
 * Test whether file exists or not. If `name' represents a symbolic link,
 * it will check that pointed file does exist.
 */
extern EIF_BOOLEAN eif_file_exists(EIF_FILENAME name);

/*
 * Test whether file exists or not without following the symbolic link
 * if `name' represents one.
 */
extern EIF_BOOLEAN eif_file_path_exists(EIF_FILENAME name);

/*
 * Check whether access permission `op' are possible on file `name' using
 * real UID and real GID. This is probably only useful to setuid or setgid
 * programs.
 */
extern EIF_BOOLEAN eif_file_access(EIF_FILENAME name, EIF_INTEGER op);

/*
 * Check whether the file `path' may be created: we need write permissions
 * in the parent directory and there must not be any file bearing that name
 * with no write permissions...
 */
extern EIF_BOOLEAN eif_file_creatable(EIF_FILENAME path, EIF_INTEGER nbytes);

/*
 * Get an integer from `f'.
 */
extern EIF_INTEGER eif_file_gi(FILE *f);

/*
 * Get a real from `f'.
 */
extern EIF_REAL_32 eif_file_gr(FILE *f);

/*
 * Get a double from `f'.
 */
extern EIF_REAL_64 eif_file_gd(FILE *f);

/*
 * Write `number' on `f'.
 */
extern void eif_file_pi(FILE *f, EIF_INTEGER number);

/*
 * Write `number' on `f'.
 */
extern void eif_file_pr(FILE *f, EIF_REAL_32 number);

/*
 * Write double `val' onto `f'.
 */
extern void eif_file_pd(FILE *f, EIF_REAL_64 val);

#ifdef HAS_GETGROUPS
/*
 * Does the list of groups the user belongs to include `gid'?
 */
extern EIF_BOOLEAN eif_group_in_list(int gid);
#endif

/*
 * Size of the stat structure. This is used by the Eiffel side to create
 * the area (special object) which will play the role of a stat buffer
 * structure.
 */
extern EIF_INTEGER stat_size(void);

/*
 * Check file permissions using effective UID and effective GID. The
 * current permission mode is held in the st_mode field of the stat()
 * buffer structure `buf'.
 */
extern EIF_BOOLEAN eif_file_eaccess(rt_stat_buf *buf, int op);

/*
 * Perform the field dereferencing from the appropriate stat structure,
 * which Eiffel cannot do directly.
 */
extern EIF_INTEGER eif_file_info(rt_stat_buf *buf, int op);

/*
 * Return the Eiffel string filled in with the name associated with `uid'
 * if found in /etc/passwd. Otherwise, return fill it in with the numeric
 * value.
 */
extern EIF_REFERENCE eif_file_owner(int uid);

/*
 * Return the Eiffel string filled in with the name associated with `gid'
 * if found in /etc/group. Otherwise, return fill it in with the numeric
 * value.
 */
extern EIF_REFERENCE eif_file_group(int gid);

/*
 * Get an integer from `f'.
 */
extern EIF_INTEGER eif_file_gib(FILE* f);

/*
 * Get a real from `f'.
 */
extern EIF_REAL_32 eif_file_grb(FILE* f);

/*
 * Get a double from `f'.
 */
extern EIF_REAL_64 eif_file_gdb(FILE* f);

/*
 * Open file `name' with the corresponding type `how'.
 */
extern EIF_POINTER eif_file_binary_open(EIF_FILENAME name, int how);

/*
 * Open file `fd' with the corresponding type `how'.
 */
extern EIF_POINTER eif_file_binary_dopen(int fd, int how);

/*
 * Reopen file `name' with the corresponding type `how' and substitute that
 * to the old stream described by `old'. This is useful to redirect 'stdout'
 * to another place, for instance.
 */
extern EIF_POINTER eif_file_binary_reopen(EIF_FILENAME name, int how, FILE* old);

/*
 * Write `number' on `f'.
 */
extern void eif_file_pib(FILE* f, EIF_INTEGER number);

/*
 * Write `number' on `f'.
 */
extern void eif_file_prb(FILE* f, EIF_REAL_32 number);

/*
 * Write double `val' onto `f'.
 */
extern void eif_file_pdb(FILE* f, EIF_REAL_64 val);

/*
 * Modification time of a file.
 * Seconds since epoch (01 January 1970) in UTC or 0 if time cannot be retrieved.
 */
extern EIF_INTEGER eif_file_date(EIF_FILENAME  name);

/*
 * Access time of a file.
 * Seconds since epoch (01 January 1970) in UTC or 0 if time cannot be retrieved.
 */
extern EIF_INTEGER eif_file_access_date(EIF_FILENAME name);

/*
 * Generate a temporary file with a name based on a template and
 * return a file descriptor to the file.
 * The template is overwritten with the name of the new file.
 * Return a non-zero file descriptor for the temporary file upon success, -1 otherwise.
 * `template'is the template to use for creating the temporary file.
 * It must match the rules for mk[s]temp (i.e. end in "XXXXXX").
 * On exit, it is updated with the new name.
 * `is_text_mode', if non-zero, then the temporary file is created
 * in text mode, otherwise in binary mode.<param>
 * Note: Code was inspired from https://github.com/mirror/mingw-w64/blob/master/mingw-w64-crt/misc/mkstemp.c
 */
extern EIF_INTEGER eif_file_mkstemp(EIF_FILENAME a_template, EIF_BOOLEAN is_text_mode);

#ifdef __cplusplus
}
#endif

#endif
/*
	description:

		"C functions used to implement class EXCEPTIONS"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2006-2018, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef EIF_EXCEPT_H
#define EIF_EXCEPT_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif
#ifndef GE_EXCEPTION_H
#include "ge_exception.h"
#endif

#include <errno.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Predefined exception codes.
 */
#define EN_VOID		GE_EX_VOID			/* Feature applied to void reference */
#define EN_MEM		GE_EX_MEM			/* No more memory */
#define EN_PRE		GE_EX_PRE			/* Pre-condition violated */
#define EN_POST		GE_EX_POST			/* Post-condition violated */
#define EN_FLOAT	GE_EX_FLOAT			/* Floating point exception (signal SIGFPE) */
#define EN_CINV		GE_EX_CINV			/* Class invariant violated */
#define EN_CHECK	GE_EX_CHECK			/* Assertion violated */
#define EN_FAIL		GE_EX_FAIL			/* Routine failure */
#define EN_WHEN		GE_EX_WHEN			/* Unmatched inspect value */
#define EN_VAR		GE_EX_VAR			/* Non-decreasing loop variant */
#define EN_LINV		GE_EX_LINV			/* Loop invariant violated */
#define EN_SIG		GE_EX_SIG			/* Operating system signal */
#define EN_BYE		GE_EX_BYE			/* Eiffel run-time panic */
#define EN_RESC		GE_EX_RESC			/* Exception in rescue clause */
#define EN_OMEM		GE_EX_OMEM			/* Out of memory (cannot be ignored) */
#define EN_RES		GE_EX_RES			/* Resumption failed (retry did not succeed) */
#define EN_CDEF		GE_EX_CDEF			/* Create on deferred */
#define EN_EXT		GE_EX_EXT			/* External event */
#define EN_VEXP		GE_EX_VEXP			/* Void assigned to expanded */
#define EN_HDLR		GE_EX_HDLR			/* Exception in signal handler */
#define EN_IO		GE_EX_IO			/* I/O error */
#define EN_SYS		GE_EX_SYS			/* Operating system error */
#define EN_RETR		GE_EX_RETR			/* Retrieval error */
#define EN_PROG		GE_EX_PROG			/* Developer exception */
#define EN_FATAL	GE_EX_FATAL			/* Eiffel run-time fatal error */
#define EN_DOL		GE_EX_DOL			/* $ applied to melted feature */
#define EN_ISE_IO	GE_EX_ISE_IO		/* I/O error raised by the ISE Eiffel runtime */
#define EN_COM		GE_EX_COM			/* COM error raised by EiffelCOM runtime */
#define EN_RT_CHECK	GE_EX_RT_CHECK		/* Runtime check error such as out-of-bound array access */
#define EN_OLD		GE_EX_OLD			/* Old violation */
#define EN_SEL		GE_EX_SEL			/* Serialization failure */
#define EN_DIRTY	GE_EX_DIRTY			/* SCOOP processor dirty exception. */
#define EN_NEX		GE_EX_NEX			/* Number of internal exceptions */

/*
 * Raise an Eiffel exception.
 */
extern void eraise(const char* name, long code);

/*
 * Raise an Eiffel exception of the given code with no associated tag.
 */
extern void xraise(int code);

/*
 * Raise an "Operating system error" exception.
 */
extern void esys(void);

/*
 * As a special case, an I/O error is raised when a system call which is I/O bound fails.
 */
extern void eise_io(const char* tag);

/*
 * Raise a "No more memory" exception.
 */
extern void enomem(void);

/*
 * Raise EiffelCOM exception.
 */
extern void com_eraise(const char* tag, long num);

/*
 * Terminate execution with exit status `code',
 * without triggering an exception.
 */
extern void esdie(int code);

/*
 * Exception tag associated with `code'.
 * This is a duplication from Eiffel classes, but still used for trace printing and in EiffelCom.
 */
extern EIF_REFERENCE eename(long except);

/*
 * Is exception `ex' defined?
 * Used in EiffelCOM.
 */
extern char eedefined(long ex);

/*
 * Enable/diable printing of the exception trace.
 * Per thead information.
 */
extern void eetrace(char b);

/*
 * Is current execution during rescue?
 */
extern EIF_BOOLEAN eif_is_in_rescue(void);

#ifdef EIF_WINDOWS
/*
 * Set default exception handler.
 */
extern void set_windows_exception_filter(void);
#endif

/*
 * Used in EiffelCOM.
 */
#define echval GE_current_context()->exception_code
#define echtg GE_current_context()->exception_tag

#ifdef __cplusplus
}
#endif

#endif
/*
	description:

		"C functions used to implement class REAL"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2006-2019, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_REAL_H
#define GE_REAL_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif

#include <math.h>

#ifndef GE_power
#define GE_power(x,y) pow((x),(y))
#endif
#define GE_ceiling(x) ceil(x)
#define GE_floor(x) floor(x)

extern EIF_NATURAL_32 GE_real_32_to_bits (EIF_REAL_32 v);
extern EIF_NATURAL_64 GE_real_64_to_bits (EIF_REAL_64 v);
extern EIF_REAL_32 GE_real_32_from_bits (EIF_NATURAL_32 v);
extern EIF_REAL_64 GE_real_64_from_bits (EIF_NATURAL_64 v);

#define GE_real_32_is_nan(v) ((v) != (v) ? EIF_TRUE : ((GE_real_32_to_bits(v) & ~GE_nat32(0x80000000)) > GE_nat32(0x7FF00000)))
#define GE_real_64_is_nan(v) ((v) != (v) ? EIF_TRUE : ((GE_real_64_to_bits(v) & ~GE_nat64(0x8000000000000000)) > GE_nat64(0x7FF0000000000000)))
#define GE_real_32_is_negative_infinity(v) (GE_real_32_to_bits(v) == GE_nat32(0xFF800000))
#define GE_real_64_is_negative_infinity(v) (GE_real_64_to_bits(v) == GE_nat64(0xFFF0000000000000))
#define GE_real_32_is_positive_infinity(v) (GE_real_32_to_bits(v) == GE_nat32(0x7F800000))
#define GE_real_64_is_positive_infinity(v) (GE_real_64_to_bits(v) == GE_nat64(0x7FF0000000000000))
#define GE_real_32_nan GE_real_32_from_bits(GE_nat32(0x7FC00000))
#define GE_real_64_nan GE_real_64_from_bits(GE_nat64(0x7FF8000000000000))
#define GE_real_32_negative_infinity GE_real_32_from_bits(GE_nat32(0xFF800000))
#define GE_real_64_negative_infinity GE_real_64_from_bits(GE_nat64(0xFFF0000000000000))
#define GE_real_32_positive_infinity GE_real_32_from_bits(GE_nat32(0x7F800000))
#define GE_real_64_positive_infinity GE_real_64_from_bits(GE_nat64(0x7FF0000000000000))
#define GE_real_32_is_equal(v1,v2) ((v1) == (v1) ? (v1) == (v2) : (v2) != (v2))
#define GE_real_64_is_equal(v1,v2) ((v1) == (v1) ? (v1) == (v2) : (v2) != (v2))
#define GE_real_32_is_less(v1,v2) ((v1) == (v1) ? (v1) < (v2) : (v2) == (v2))
#define GE_real_64_is_less(v1,v2) ((v1) == (v1) ? (v1) < (v2) : (v2) == (v2))
#define GE_real_32_ieee_is_equal(v1,v2) (v1) == (v2)
#define GE_real_64_ieee_is_equal(v1,v2) (v1) == (v2)
#define GE_real_32_ieee_is_greater(v1,v2) isgreater(v1,v2)
#define GE_real_64_ieee_is_greater(v1,v2) isgreater(v1,v2)
#define GE_real_32_ieee_is_greater_equal(v1,v2) isgreaterequal(v1,v2)
#define GE_real_64_ieee_is_greater_equal(v1,v2) isgreaterequal(v1,v2)
#define GE_real_32_ieee_is_less(v1,v2) isless(v1,v2)
#define GE_real_64_ieee_is_less(v1,v2) isless(v1,v2)
#define GE_real_32_ieee_is_less_equal(v1,v2) islessequal(v1,v2)
#define GE_real_64_ieee_is_less_equal(v1,v2) islessequal(v1,v2)
#define GE_real_32_ieee_maximum_number(v1,v2) fmaxf(v1,v2)
#define GE_real_64_ieee_maximum_number(v1,v2) fmax(v1,v2)
#define GE_real_32_ieee_minimum_number(v1,v2) fminf(v1,v2)
#define GE_real_64_ieee_minimum_number(v1,v2) fmin(v1,v2)

#endif
/*
	description:

		"C functions used to implement Thread support"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2007-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef EIF_THREADS_H
#define EIF_THREADS_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef EIF_CECIL_H
#include "eif_cecil.h"
#endif
#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif
#ifdef GE_USE_THREADS
#ifndef GE_THREAD_H
#include "ge_thread.h"
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GE_USE_THREADS

/*
 * Empty stubs for EiffelThread library so that it may be compiled against a non-multithreaded run-time.
 */

/* THREAD_ENVIRONMENT */
#define eif_thr_thread_id() NULL

/* THREAD_CONTROL */
#define eif_thr_yield()
#define eif_thr_join_all()

/* THREAD */
#define eif_thr_create_with_attr(current_obj, init_func, set_terminated_func, attr)
#define eif_thr_wait(obj,get_terminated)
#define eif_thr_wait_with_timeout(obj,get_terminated,tms) EIF_TRUE
#define eif_thr_last_thread() NULL
#define eif_thr_exit()

/* THREAD_ATTRIBUTES */
#define eif_thr_default_priority() 0
#define eif_thr_min_priority() 0
#define eif_thr_max_priority() 0

/* MUTEX */
#define eif_thr_mutex_create() NULL
#define eif_thr_mutex_lock(a_mutex_pointer)
#define eif_thr_mutex_trylock(a_mutex_pointer) EIF_TRUE
#define eif_thr_mutex_unlock(a_mutex_pointer)
#define eif_thr_mutex_destroy(a_mutex_pointer)

/* CONDITION_VARIABLE */
#define eif_thr_cond_create() NULL
#define eif_thr_cond_broadcast(a_cond_ptr)
#define eif_thr_cond_signal(a_cond_ptr)
#define eif_thr_cond_wait(a_cond_ptr,a_mutex_ptr)
#define eif_thr_cond_wait_with_timeout(a_cond_ptr,a_mutex_ptr,a_timeout) 1
#define eif_thr_cond_destroy(a_cond_ptr)

/* SEMAPHORE */
#define eif_thr_sem_create(a_count) NULL
#define eif_thr_sem_wait(a_sem_pointer)
#define eif_thr_sem_post(a_sem_pointer)
#define eif_thr_sem_trywait(a_sem_pointer) EIF_TRUE
#define eif_thr_sem_destroy(a_sem_pointer)

/* READ_WRITE_LOCK */
#define eif_thr_rwl_create() NULL
#define eif_thr_rwl_rdlock(a_read_write_lock_pointer)
#define eif_thr_rwl_unlock(a_read_write_lock_pointer)
#define eif_thr_rwl_wrlock(a_read_write_lock_pointer)
#define eif_thr_rwl_destroy(a_read_write_lock_pointer)

#else

/* THREAD_ENVIRONMENT */
#define eif_thr_thread_id() GE_thread_id()

/* THREAD_CONTROL */
#define eif_thr_yield() GE_thread_yield()
#define eif_thr_join_all() GE_thread_join_all()

/* THREAD */
#define eif_thr_create_with_attr(current_obj,init_func,set_terminated_func,attr) GE_thread_create_with_attr(eif_access(current_obj),(void (*)(EIF_REFERENCE,EIF_INTEGER))(init_func),(void (*)(EIF_REFERENCE,EIF_BOOLEAN))(set_terminated_func),(EIF_THR_ATTR_TYPE*)(attr),0)
#define eif_thr_wait(obj,get_terminated) GE_thread_wait(eif_access(obj),(EIF_BOOLEAN (*)(EIF_REFERENCE))(get_terminated))
#define eif_thr_wait_with_timeout(obj,get_terminated,tms) GE_thread_wait_with_timeout(eif_access(obj),(EIF_BOOLEAN (*)(EIF_REFERENCE))(get_terminated),(tms))
#define eif_thr_last_thread() GE_last_thread_created()
#define eif_thr_exit() GE_thread_exit()

/* THREAD_ATTRIBUTES */
#define eif_thr_default_priority() GE_thread_default_priority()
#define eif_thr_min_priority() GE_thread_min_priority()
#define eif_thr_max_priority() GE_thread_max_priority()

/* MUTEX */
#define eif_thr_mutex_create() GE_mutex_create()
#define eif_thr_mutex_lock(a_mutex_pointer) GE_mutex_lock(a_mutex_pointer)
#define eif_thr_mutex_trylock(a_mutex_pointer) GE_mutex_try_lock(a_mutex_pointer)
#define eif_thr_mutex_unlock(a_mutex_pointer) GE_mutex_unlock(a_mutex_pointer)
#define eif_thr_mutex_destroy(a_mutex_pointer) GE_mutex_destroy(a_mutex_pointer)

/* CONDITION_VARIABLE */
#define eif_thr_cond_create() GE_condition_variable_create()
#define eif_thr_cond_broadcast(a_cond_ptr) GE_condition_variable_broadcast(a_cond_ptr)
#define eif_thr_cond_signal(a_cond_ptr) GE_condition_variable_signal(a_cond_ptr)
#define eif_thr_cond_wait(a_cond_ptr,a_mutex_ptr) GE_condition_variable_wait((a_cond_ptr),(a_mutex_ptr))
#define eif_thr_cond_wait_with_timeout(a_cond_ptr,a_mutex_ptr,a_timeout) GE_condition_variable_wait_with_timeout((a_cond_ptr),(a_mutex_ptr),(a_timeout))
#define eif_thr_cond_destroy(a_cond_ptr) GE_condition_variable_destroy(a_cond_ptr)

/* SEMAPHORE */
#define eif_thr_sem_create(a_count) GE_semaphore_create(a_count)
#define eif_thr_sem_wait(a_sem_pointer) GE_semaphore_wait(a_sem_pointer)
#define eif_thr_sem_post(a_sem_pointer) GE_semaphore_post(a_sem_pointer)
#define eif_thr_sem_trywait(a_sem_pointer) GE_semaphore_try_wait(a_sem_pointer)
#define eif_thr_sem_destroy(a_sem_pointer) GE_semaphore_destroy(a_sem_pointer)

/* READ_WRITE_LOCK */
#define eif_thr_rwl_create() GE_read_write_lock_create()
#define eif_thr_rwl_rdlock(a_read_write_lock_pointer) GE_read_write_lock_read_lock(a_read_write_lock_pointer)
#define eif_thr_rwl_unlock(a_read_write_lock_pointer) GE_read_write_lock_unlock(a_read_write_lock_pointer)
#define eif_thr_rwl_wrlock(a_read_write_lock_pointer) GE_read_write_lock_write_lock(a_read_write_lock_pointer)
#define eif_thr_rwl_destroy(a_read_write_lock_pointer) GE_read_write_lock_destroy(a_read_write_lock_pointer)

/* WEL */
#ifdef EIF_WINDOWS
#define eif_thr_create_wel_per_thread_data(a_size) GE_thread_create_wel_per_thread_data(a_size)
#endif

/* To compile the C code of EiffelNet. */
extern int socket_fides;

#endif

#ifdef __cplusplus
}
#endif

#endif
/*
	description:

		"Part of ISE Eiffel runtime. Needed to compile ISE's compiler."

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2019, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef EIF_SIZE_H
#define EIF_SIZE_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <limits.h>

/* Basic sizes */
#define EIF_ALIGN	8	/* Alignment restrictions */
#define R64SIZ	8	/* Size of double */
#define I64SIZ	8	/* Size of integer 64 bits */
#define R32SIZ	4	/* Size of float */
#define REFSIZ	sizeof(char*)	/* Size of char* */
#define LNGSIZ	4	/* Size of long */
#define I16SIZ	2	/* Size of integer 16 bits */
#define CHRSIZ	1	/* Size of char */
#define PTRSIZ	sizeof(void*)	/* Size of a function pointer */

/* Macros used to access fields in the object */
#define REFACS(n) ((n)*REFSIZ)
#define CHRACS(n) ((n)*CHRSIZ)
#define I16ACS(n) ((n)*I16SIZ)
#define LNGACS(n) ((n)*LNGSIZ)
#define R32ACS(n) ((n)*R32SIZ)
#define I64ACS(n) ((n)*I64SIZ)
#define R64ACS(n) ((n)*R64SIZ)
#define PTRACS(n) ((n)*PTRSIZ)

#ifdef __cplusplus
}
#endif

#endif
/*
	description:

		"Part of ISE Eiffel runtime. Needed to compile the EiffelCOM library."

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2010-2019, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef EIF_GLOBALS_H
#define EIF_GLOBALS_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EXCEPTION_H
#include "ge_exception.h"
#endif
#ifndef EIF_THREADS_H
#include "eif_threads.h"
#endif
#ifndef EIF_SIZE_H
#include "eif_size.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef GE_USE_THREADS
#define EIF_GET_CONTEXT \
	GE_thread_context* eif_globals = GE_current_context()->thread;
#else
#define EIF_GET_CONTEXT
#endif

#define GTCX EIF_GET_CONTEXT

#ifdef __cplusplus
}
#endif

#endif
/*
	description:

		"C declarations for the ISE Eiffel runtime."

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2006-2024, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef EIF_EIFFEL_H
#define EIF_EIFFEL_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif
#ifndef GE_STRING_H
#include "ge_string.h"
#endif
#ifndef GE_GC_H
#include "ge_gc.h"
#endif
#ifndef EIF_GLOBALS_H
#include "eif_globals.h"
#endif
#ifndef EIF_EXCEPT_H
#include "eif_except.h"
#endif

#endif
/*
	description:

		"C functions used to implement class COM_FAILURE"

	system: "Gobo Eiffel Compiler"
	copyright: "Copyright (c) 2016-2018, Eric Bezault and others"
	license: "MIT License"
*/

#ifndef GE_COM_FAILURE_H
#define GE_COM_FAILURE_H
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef GE_EIFFEL_H
#include "ge_eiffel.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern EIF_INTEGER GE_ccom_hresult(EIF_POINTER an_exception_code);

extern EIF_INTEGER GE_ccom_hresult_code(EIF_INTEGER an_hresult);

extern EIF_INTEGER GE_ccom_hresult_facility(EIF_INTEGER an_hresult);

/*
 * Get text from error `a_code'. It is up to the caller to free
 * the returned buffer using `GE_ccom_local_free'.
 */
extern EIF_POINTER GE_ccom_error_text(EIF_INTEGER a_code);

/*
 * Number of characters in `ptr'.
 */
extern EIF_INTEGER_32 GE_ccom_strlen(EIF_POINTER ptr);

/*
 * Number of bytes occupied by a TCHAR.
 */
extern EIF_INTEGER_32 GE_ccom_character_size(void);

/*
 * Free `a_ptr' using LocalFree.
 */
extern void GE_ccom_local_free(EIF_POINTER a_ptr);

#ifdef __cplusplus
}
#endif

#endif
#include <string.h>
#include <stdlib.h>
#include <iconv.h>
#include "string.h"
#include "eif_langinfo.h"
#include <locale.h>
