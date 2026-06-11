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

/* STRING_8 */
typedef volatile struct S17 T17;

/* ISE_EXCEPTION_MANAGER */
typedef volatile struct S21 T21;

/* SENSOR_UMIDADE */
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

/* VOID_TARGET */
typedef volatile struct S33 T33;

/* TYPE [VOID_TARGET] */
#define T34 EIF_TYPE_OBJ

/* ROUTINE_FAILURE */
typedef volatile struct S35 T35;

/* TYPE [ROUTINE_FAILURE] */
#define T36 EIF_TYPE_OBJ

/* OLD_VIOLATION */
typedef volatile struct S37 T37;

/* TYPE [OLD_VIOLATION] */
#define T38 EIF_TYPE_OBJ

/* NO_MORE_MEMORY */
typedef volatile struct S39 T39;

/* INVARIANT_VIOLATION */
typedef volatile struct S40 T40;

/* OPERATING_SYSTEM_SIGNAL_FAILURE */
typedef volatile struct S41 T41;

/* IO_FAILURE */
typedef volatile struct S42 T42;

/* OPERATING_SYSTEM_FAILURE */
typedef volatile struct S43 T43;

/* COM_FAILURE */
typedef volatile struct S44 T44;

/* EIFFEL_RUNTIME_PANIC */
typedef volatile struct S45 T45;

/* PRECONDITION_VIOLATION */
typedef volatile struct S48 T48;

/* POSTCONDITION_VIOLATION */
typedef volatile struct S49 T49;

/* FLOATING_POINT_FAILURE */
typedef volatile struct S50 T50;

/* CHECK_VIOLATION */
typedef volatile struct S51 T51;

/* BAD_INSPECT_VALUE */
typedef volatile struct S52 T52;

/* VARIANT_VIOLATION */
typedef volatile struct S53 T53;

/* LOOP_INVARIANT_VIOLATION */
typedef volatile struct S54 T54;

/* RESCUE_FAILURE */
typedef volatile struct S55 T55;

/* RESUMPTION_FAILURE */
typedef volatile struct S56 T56;

/* CREATE_ON_DEFERRED */
typedef volatile struct S57 T57;

/* EXTERNAL_FAILURE */
typedef volatile struct S58 T58;

/* VOID_ASSIGNED_TO_EXPANDED */
typedef volatile struct S59 T59;

/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE */
typedef volatile struct S60 T60;

/* MISMATCH_FAILURE */
typedef volatile struct S61 T61;

/* DEVELOPER_EXCEPTION */
typedef volatile struct S62 T62;

/* ADDRESS_APPLIED_TO_MELTED_FEATURE */
typedef volatile struct S63 T63;

/* SERIALIZATION_FAILURE */
typedef volatile struct S64 T64;

/* PRIMES */
typedef volatile struct S65 T65;

/* SPECIAL [INTEGER_32] */
typedef volatile struct S66 T66;

/* SPECIAL [BOOLEAN] */
typedef volatile struct S67 T67;

/* TYPE [detachable VOID_TARGET] */
#define T69 EIF_TYPE_OBJ

/* UTF_CONVERTER */
typedef volatile struct S71 T71;
extern T0* GE_boxed71(TC* ac, T71 a1);
extern T0* GE_boxed_pointer71(TC* ac, T71* a1);
typedef volatile struct Sb71 Tb71;

/* CELL [INTEGER_32] */
typedef volatile struct S72 T72;

/* MANAGED_POINTER */
typedef volatile struct S73 T73;

/* TYPE [detachable ROUTINE_FAILURE] */
#define T74 EIF_TYPE_OBJ

/* TYPE [detachable OLD_VIOLATION] */
#define T75 EIF_TYPE_OBJ

/* TYPE [detachable NO_MORE_MEMORY] */
#define T76 EIF_TYPE_OBJ

/* TYPE [detachable INVARIANT_VIOLATION] */
#define T77 EIF_TYPE_OBJ

/* TYPE [detachable OPERATING_SYSTEM_SIGNAL_FAILURE] */
#define T78 EIF_TYPE_OBJ

/* TYPE [detachable IO_FAILURE] */
#define T79 EIF_TYPE_OBJ

/* TYPE [detachable OPERATING_SYSTEM_FAILURE] */
#define T80 EIF_TYPE_OBJ

/* TYPE [detachable COM_FAILURE] */
#define T81 EIF_TYPE_OBJ

/* TYPE [detachable EIFFEL_RUNTIME_PANIC] */
#define T82 EIF_TYPE_OBJ

/* TYPE [detachable PRECONDITION_VIOLATION] */
#define T83 EIF_TYPE_OBJ

/* TYPE [detachable POSTCONDITION_VIOLATION] */
#define T84 EIF_TYPE_OBJ

/* TYPE [detachable FLOATING_POINT_FAILURE] */
#define T85 EIF_TYPE_OBJ

/* TYPE [detachable CHECK_VIOLATION] */
#define T86 EIF_TYPE_OBJ

/* TYPE [detachable BAD_INSPECT_VALUE] */
#define T87 EIF_TYPE_OBJ

/* TYPE [detachable VARIANT_VIOLATION] */
#define T88 EIF_TYPE_OBJ

/* TYPE [detachable LOOP_INVARIANT_VIOLATION] */
#define T89 EIF_TYPE_OBJ

/* TYPE [detachable RESCUE_FAILURE] */
#define T90 EIF_TYPE_OBJ

/* TYPE [detachable RESUMPTION_FAILURE] */
#define T91 EIF_TYPE_OBJ

/* TYPE [detachable CREATE_ON_DEFERRED] */
#define T92 EIF_TYPE_OBJ

/* TYPE [detachable EXTERNAL_FAILURE] */
#define T93 EIF_TYPE_OBJ

/* TYPE [detachable VOID_ASSIGNED_TO_EXPANDED] */
#define T94 EIF_TYPE_OBJ

/* TYPE [detachable EXCEPTION_IN_SIGNAL_HANDLER_FAILURE] */
#define T95 EIF_TYPE_OBJ

/* TYPE [detachable MISMATCH_FAILURE] */
#define T96 EIF_TYPE_OBJ

/* TYPE [detachable DEVELOPER_EXCEPTION] */
#define T97 EIF_TYPE_OBJ

/* TYPE [detachable ADDRESS_APPLIED_TO_MELTED_FEATURE] */
#define T98 EIF_TYPE_OBJ

/* TYPE [detachable SERIALIZATION_FAILURE] */
#define T99 EIF_TYPE_OBJ

/* EXCEPTIONS */
typedef volatile struct S101 T101;

/* TYPED_POINTER [NATURAL_8] */
typedef volatile struct S102 T102;
extern T0* GE_boxed102(TC* ac, T102 a1);
extern T0* GE_boxed_pointer102(TC* ac, T102* a1);
typedef volatile struct Sb102 Tb102;

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
struct S71 {
	char volatile dummy;
};

/* Struct for boxed version of type UTF_CONVERTER */
struct Sb71 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T71* volatile p1; /* pointer */
	T71 z1; /* item */
};

/* Struct for type TYPED_POINTER [NATURAL_8] */
struct S102 {
	T14 volatile a1; /* to_pointer */
};

/* Struct for boxed version of type TYPED_POINTER [NATURAL_8] */
struct Sb102 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T102* volatile p1; /* pointer */
	T102 z1; /* item */
};

/* Struct for type SPECIAL [CHARACTER_8] */
struct S15 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T6 volatile a2; /* count */
	T2 volatile z2[]; /* item */
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

/* Struct for type ISE_EXCEPTION_MANAGER */
struct S21 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
};

/* Struct for type SENSOR_UMIDADE */
struct S26 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T12 volatile a1; /* valor */
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

/* Struct for type VOID_TARGET */
struct S33 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type ROUTINE_FAILURE */
struct S35 {
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
struct S37 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type NO_MORE_MEMORY */
struct S39 {
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
struct S40 {
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
struct S41 {
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
struct S42 {
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
struct S43 {
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
struct S44 {
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
struct S45 {
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
struct S48 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type POSTCONDITION_VIOLATION */
struct S49 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type FLOATING_POINT_FAILURE */
struct S50 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type CHECK_VIOLATION */
struct S51 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type BAD_INSPECT_VALUE */
struct S52 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type VARIANT_VIOLATION */
struct S53 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type LOOP_INVARIANT_VIOLATION */
struct S54 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type RESCUE_FAILURE */
struct S55 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type RESUMPTION_FAILURE */
struct S56 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type CREATE_ON_DEFERRED */
struct S57 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type EXTERNAL_FAILURE */
struct S58 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type VOID_ASSIGNED_TO_EXPANDED */
struct S59 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type EXCEPTION_IN_SIGNAL_HANDLER_FAILURE */
struct S60 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type MISMATCH_FAILURE */
struct S61 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type DEVELOPER_EXCEPTION */
struct S62 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type ADDRESS_APPLIED_TO_MELTED_FEATURE */
struct S63 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type SERIALIZATION_FAILURE */
struct S64 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T0* volatile a1; /* c_description */
	T0* volatile a2; /* throwing_exception */
	T0* volatile a3; /* internal_trace */
	T0* volatile a4; /* recipient_name */
	T0* volatile a5; /* type_name */
};

/* Struct for type PRIMES */
struct S65 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
};

/* Struct for type SPECIAL [INTEGER_32] */
struct S66 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T6 volatile a2; /* count */
	T6 volatile z2[]; /* item */
};

/* Struct for type SPECIAL [BOOLEAN] */
struct S67 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* capacity */
	T6 volatile a2; /* count */
	T1 volatile z2[]; /* item */
};

/* Struct for type CELL [INTEGER_32] */
struct S72 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T6 volatile a1; /* item */
};

/* Struct for type MANAGED_POINTER */
struct S73 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
	T14 volatile a1; /* item */
	T6 volatile a2; /* count */
	T1 volatile a3; /* is_shared */
};

/* Struct for type EXCEPTIONS */
struct S101 {
	EIF_TYPE_INDEX volatile id;
	uint16_t volatile flags;
};


extern T71 GE_default71;
extern T102 GE_default102;

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
/* New instance of type STRING_8 */
extern T0* GE_new17(TC* ac, T1 initialize);
/* New instance of type ISE_EXCEPTION_MANAGER */
extern T0* GE_new21(TC* ac, T1 initialize);
/* New instance of type SENSOR_UMIDADE */
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
/* New instance of type VOID_TARGET */
extern T0* GE_new33(TC* ac, T1 initialize);
/* New instance of type ROUTINE_FAILURE */
extern T0* GE_new35(TC* ac, T1 initialize);
/* New instance of type OLD_VIOLATION */
extern T0* GE_new37(TC* ac, T1 initialize);
/* New instance of type NO_MORE_MEMORY */
extern T0* GE_new39(TC* ac, T1 initialize);
/* New instance of type INVARIANT_VIOLATION */
extern T0* GE_new40(TC* ac, T1 initialize);
/* New instance of type OPERATING_SYSTEM_SIGNAL_FAILURE */
extern T0* GE_new41(TC* ac, T1 initialize);
/* New instance of type IO_FAILURE */
extern T0* GE_new42(TC* ac, T1 initialize);
/* New instance of type OPERATING_SYSTEM_FAILURE */
extern T0* GE_new43(TC* ac, T1 initialize);
/* New instance of type COM_FAILURE */
extern T0* GE_new44(TC* ac, T1 initialize);
/* New instance of type EIFFEL_RUNTIME_PANIC */
extern T0* GE_new45(TC* ac, T1 initialize);
/* New instance of type PRECONDITION_VIOLATION */
extern T0* GE_new48(TC* ac, T1 initialize);
/* New instance of type POSTCONDITION_VIOLATION */
extern T0* GE_new49(TC* ac, T1 initialize);
/* New instance of type FLOATING_POINT_FAILURE */
extern T0* GE_new50(TC* ac, T1 initialize);
/* New instance of type CHECK_VIOLATION */
extern T0* GE_new51(TC* ac, T1 initialize);
/* New instance of type BAD_INSPECT_VALUE */
extern T0* GE_new52(TC* ac, T1 initialize);
/* New instance of type VARIANT_VIOLATION */
extern T0* GE_new53(TC* ac, T1 initialize);
/* New instance of type LOOP_INVARIANT_VIOLATION */
extern T0* GE_new54(TC* ac, T1 initialize);
/* New instance of type RESCUE_FAILURE */
extern T0* GE_new55(TC* ac, T1 initialize);
/* New instance of type RESUMPTION_FAILURE */
extern T0* GE_new56(TC* ac, T1 initialize);
/* New instance of type CREATE_ON_DEFERRED */
extern T0* GE_new57(TC* ac, T1 initialize);
/* New instance of type EXTERNAL_FAILURE */
extern T0* GE_new58(TC* ac, T1 initialize);
/* New instance of type VOID_ASSIGNED_TO_EXPANDED */
extern T0* GE_new59(TC* ac, T1 initialize);
/* New instance of type EXCEPTION_IN_SIGNAL_HANDLER_FAILURE */
extern T0* GE_new60(TC* ac, T1 initialize);
/* New instance of type MISMATCH_FAILURE */
extern T0* GE_new61(TC* ac, T1 initialize);
/* New instance of type DEVELOPER_EXCEPTION */
extern T0* GE_new62(TC* ac, T1 initialize);
/* New instance of type ADDRESS_APPLIED_TO_MELTED_FEATURE */
extern T0* GE_new63(TC* ac, T1 initialize);
/* New instance of type SERIALIZATION_FAILURE */
extern T0* GE_new64(TC* ac, T1 initialize);
/* New instance of type PRIMES */
extern T0* GE_new65(TC* ac, T1 initialize);
/* New instance of type SPECIAL [INTEGER_32] */
extern T0* GE_new66(TC* ac, T6 a1, T1 initialize);
/* New instance of type SPECIAL [BOOLEAN] */
extern T0* GE_new67(TC* ac, T6 a1, T1 initialize);
/* New instance of type UTF_CONVERTER */
extern T0* GE_new71(TC* ac, T1 initialize);
/* New instance of type CELL [INTEGER_32] */
extern T0* GE_new72(TC* ac, T1 initialize);
/* New instance of type MANAGED_POINTER */
extern T0* GE_new73(TC* ac, T1 initialize);
/* New instance of type EXCEPTIONS */
extern T0* GE_new101(TC* ac, T1 initialize);
/* New instance of type TYPED_POINTER [NATURAL_8] */
extern T0* GE_new102(TC* ac, T1 initialize);
/* SENSOR_UMIDADE.make */
extern T0* T26c2(TC* ac);
/* ISE_EXCEPTION_MANAGER.set_exception_data */
extern void T21s16(TC* ac, T6 a1, T1 a2, T6 a3, T6 a4, T0* a5, T0* a6, T0* a7, T0* a8, T0* a9, T0* a10, T6 a11, T1 a12);
/* NO_MORE_MEMORY.set_type_name */
extern void T39f18(TC* ac, T0* C, T0* a1);
/* SERIALIZATION_FAILURE.set_type_name */
extern void T64f16(TC* ac, T0* C, T0* a1);
/* OLD_VIOLATION.set_type_name */
extern void T37f16(TC* ac, T0* C, T0* a1);
/* COM_FAILURE.set_type_name */
extern void T44f24(TC* ac, T0* C, T0* a1);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_type_name */
extern void T63f16(TC* ac, T0* C, T0* a1);
/* DEVELOPER_EXCEPTION.set_type_name */
extern void T62f16(TC* ac, T0* C, T0* a1);
/* MISMATCH_FAILURE.set_type_name */
extern void T61f16(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_FAILURE.set_type_name */
extern void T43f18(TC* ac, T0* C, T0* a1);
/* IO_FAILURE.set_type_name */
extern void T42f20(TC* ac, T0* C, T0* a1);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_type_name */
extern void T60f16(TC* ac, T0* C, T0* a1);
/* VOID_ASSIGNED_TO_EXPANDED.set_type_name */
extern void T59f16(TC* ac, T0* C, T0* a1);
/* EXTERNAL_FAILURE.set_type_name */
extern void T58f16(TC* ac, T0* C, T0* a1);
/* CREATE_ON_DEFERRED.set_type_name */
extern void T57f16(TC* ac, T0* C, T0* a1);
/* RESUMPTION_FAILURE.set_type_name */
extern void T56f16(TC* ac, T0* C, T0* a1);
/* RESCUE_FAILURE.set_type_name */
extern void T55f16(TC* ac, T0* C, T0* a1);
/* EIFFEL_RUNTIME_PANIC.set_type_name */
extern void T45f18(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_type_name */
extern void T41f18(TC* ac, T0* C, T0* a1);
/* LOOP_INVARIANT_VIOLATION.set_type_name */
extern void T54f16(TC* ac, T0* C, T0* a1);
/* VARIANT_VIOLATION.set_type_name */
extern void T53f16(TC* ac, T0* C, T0* a1);
/* BAD_INSPECT_VALUE.set_type_name */
extern void T52f16(TC* ac, T0* C, T0* a1);
/* ROUTINE_FAILURE.set_type_name */
extern void T35f20(TC* ac, T0* C, T0* a1);
/* CHECK_VIOLATION.set_type_name */
extern void T51f16(TC* ac, T0* C, T0* a1);
/* INVARIANT_VIOLATION.set_type_name */
extern void T40f18(TC* ac, T0* C, T0* a1);
/* FLOATING_POINT_FAILURE.set_type_name */
extern void T50f16(TC* ac, T0* C, T0* a1);
/* POSTCONDITION_VIOLATION.set_type_name */
extern void T49f16(TC* ac, T0* C, T0* a1);
/* PRECONDITION_VIOLATION.set_type_name */
extern void T48f16(TC* ac, T0* C, T0* a1);
/* VOID_TARGET.set_type_name */
extern void T33f16(TC* ac, T0* C, T0* a1);
/* NO_MORE_MEMORY.set_recipient_name */
extern void T39f17(TC* ac, T0* C, T0* a1);
/* SERIALIZATION_FAILURE.set_recipient_name */
extern void T64f15(TC* ac, T0* C, T0* a1);
/* OLD_VIOLATION.set_recipient_name */
extern void T37f15(TC* ac, T0* C, T0* a1);
/* COM_FAILURE.set_recipient_name */
extern void T44f23(TC* ac, T0* C, T0* a1);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_recipient_name */
extern void T63f15(TC* ac, T0* C, T0* a1);
/* DEVELOPER_EXCEPTION.set_recipient_name */
extern void T62f15(TC* ac, T0* C, T0* a1);
/* MISMATCH_FAILURE.set_recipient_name */
extern void T61f15(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_FAILURE.set_recipient_name */
extern void T43f17(TC* ac, T0* C, T0* a1);
/* IO_FAILURE.set_recipient_name */
extern void T42f19(TC* ac, T0* C, T0* a1);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_recipient_name */
extern void T60f15(TC* ac, T0* C, T0* a1);
/* VOID_ASSIGNED_TO_EXPANDED.set_recipient_name */
extern void T59f15(TC* ac, T0* C, T0* a1);
/* EXTERNAL_FAILURE.set_recipient_name */
extern void T58f15(TC* ac, T0* C, T0* a1);
/* CREATE_ON_DEFERRED.set_recipient_name */
extern void T57f15(TC* ac, T0* C, T0* a1);
/* RESUMPTION_FAILURE.set_recipient_name */
extern void T56f15(TC* ac, T0* C, T0* a1);
/* RESCUE_FAILURE.set_recipient_name */
extern void T55f15(TC* ac, T0* C, T0* a1);
/* EIFFEL_RUNTIME_PANIC.set_recipient_name */
extern void T45f17(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_recipient_name */
extern void T41f17(TC* ac, T0* C, T0* a1);
/* LOOP_INVARIANT_VIOLATION.set_recipient_name */
extern void T54f15(TC* ac, T0* C, T0* a1);
/* VARIANT_VIOLATION.set_recipient_name */
extern void T53f15(TC* ac, T0* C, T0* a1);
/* BAD_INSPECT_VALUE.set_recipient_name */
extern void T52f15(TC* ac, T0* C, T0* a1);
/* ROUTINE_FAILURE.set_recipient_name */
extern void T35f19(TC* ac, T0* C, T0* a1);
/* CHECK_VIOLATION.set_recipient_name */
extern void T51f15(TC* ac, T0* C, T0* a1);
/* INVARIANT_VIOLATION.set_recipient_name */
extern void T40f17(TC* ac, T0* C, T0* a1);
/* FLOATING_POINT_FAILURE.set_recipient_name */
extern void T50f15(TC* ac, T0* C, T0* a1);
/* POSTCONDITION_VIOLATION.set_recipient_name */
extern void T49f15(TC* ac, T0* C, T0* a1);
/* PRECONDITION_VIOLATION.set_recipient_name */
extern void T48f15(TC* ac, T0* C, T0* a1);
/* VOID_TARGET.set_recipient_name */
extern void T33f15(TC* ac, T0* C, T0* a1);
/* NO_MORE_MEMORY.set_exception_trace */
extern void T39f13(TC* ac, T0* C, T0* a1);
/* SERIALIZATION_FAILURE.set_exception_trace */
extern void T64f13(TC* ac, T0* C, T0* a1);
/* OLD_VIOLATION.set_exception_trace */
extern void T37f13(TC* ac, T0* C, T0* a1);
/* COM_FAILURE.set_exception_trace */
extern void T44f21(TC* ac, T0* C, T0* a1);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_exception_trace */
extern void T63f13(TC* ac, T0* C, T0* a1);
/* DEVELOPER_EXCEPTION.set_exception_trace */
extern void T62f13(TC* ac, T0* C, T0* a1);
/* MISMATCH_FAILURE.set_exception_trace */
extern void T61f13(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_FAILURE.set_exception_trace */
extern void T43f15(TC* ac, T0* C, T0* a1);
/* IO_FAILURE.set_exception_trace */
extern void T42f17(TC* ac, T0* C, T0* a1);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_exception_trace */
extern void T60f13(TC* ac, T0* C, T0* a1);
/* VOID_ASSIGNED_TO_EXPANDED.set_exception_trace */
extern void T59f13(TC* ac, T0* C, T0* a1);
/* EXTERNAL_FAILURE.set_exception_trace */
extern void T58f13(TC* ac, T0* C, T0* a1);
/* CREATE_ON_DEFERRED.set_exception_trace */
extern void T57f13(TC* ac, T0* C, T0* a1);
/* RESUMPTION_FAILURE.set_exception_trace */
extern void T56f13(TC* ac, T0* C, T0* a1);
/* RESCUE_FAILURE.set_exception_trace */
extern void T55f13(TC* ac, T0* C, T0* a1);
/* EIFFEL_RUNTIME_PANIC.set_exception_trace */
extern void T45f15(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_exception_trace */
extern void T41f15(TC* ac, T0* C, T0* a1);
/* LOOP_INVARIANT_VIOLATION.set_exception_trace */
extern void T54f13(TC* ac, T0* C, T0* a1);
/* VARIANT_VIOLATION.set_exception_trace */
extern void T53f13(TC* ac, T0* C, T0* a1);
/* BAD_INSPECT_VALUE.set_exception_trace */
extern void T52f13(TC* ac, T0* C, T0* a1);
/* ROUTINE_FAILURE.set_exception_trace */
extern void T35f17(TC* ac, T0* C, T0* a1);
/* CHECK_VIOLATION.set_exception_trace */
extern void T51f13(TC* ac, T0* C, T0* a1);
/* INVARIANT_VIOLATION.set_exception_trace */
extern void T40f15(TC* ac, T0* C, T0* a1);
/* FLOATING_POINT_FAILURE.set_exception_trace */
extern void T50f13(TC* ac, T0* C, T0* a1);
/* POSTCONDITION_VIOLATION.set_exception_trace */
extern void T49f13(TC* ac, T0* C, T0* a1);
/* PRECONDITION_VIOLATION.set_exception_trace */
extern void T48f13(TC* ac, T0* C, T0* a1);
/* VOID_TARGET.set_exception_trace */
extern void T33f13(TC* ac, T0* C, T0* a1);
/* ISE_EXCEPTION_MANAGER.set_last_exception */
extern void T21s17(TC* ac, T0* a1);
/* CELL [detachable EXCEPTION].put */
extern void T27f2(TC* ac, T0* C, T0* a1);
/* CELL [detachable EXCEPTION].put */
extern T0* T27c2(TC* ac, T0* a1);
/* ISE_EXCEPTION_MANAGER.last_exception_cell */
extern T0* T21s2(TC* ac);
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
extern void T39f16(TC* ac, T0* C, T0* a1);
/* C_STRING.set_count */
extern void T31f5(TC* ac, T0* C, T6 a1);
/* MANAGED_POINTER.resize */
extern void T73f8(TC* ac, T0* C, T6 a1);
/* POINTER.memory_set */
extern void T14f12(TC* ac, T14 volatile* C, T6 a1, T6 a2);
/* POINTER.c_memset */
extern void T14s16(TC* ac, T14 a1, T6 a2, T6 a3);
/* INTEGER_32.is_greater */
extern T1 T6f14(TC* ac, T6 volatile* C, T6 a1);
/* EXCEPTIONS.raise */
extern void T101s2(TC* ac, T0* a1);
/* DEVELOPER_EXCEPTION.raise */
extern void T62f17(TC* ac, T0* C);
/* ISE_EXCEPTION_MANAGER.raise */
extern void T21s19(TC* ac, T0* a1);
/* DEVELOPER_EXCEPTION.code */
extern T6 T62f9(TC* ac, T0* C);
/* C_STRING.item */
extern T14 T31f3(TC* ac, T0* C);
/* ISE_EXCEPTION_MANAGER.default_pointer */
extern T14 T21s9(TC* ac);
/* DEVELOPER_EXCEPTION.is_ignored */
extern T1 T62f8(TC* ac, T0* C);
/* ISE_EXCEPTION_MANAGER.is_ignored */
extern T1 T21s13(TC* ac, T0* a1);
/* HASH_TABLE [INTEGER_32, INTEGER_32].has */
extern T1 T28f34(TC* ac, T0* C, T6 a1);
/* HASH_TABLE [INTEGER_32, INTEGER_32].same_keys */
extern T1 T28f26(TC* ac, T0* C, T6 a1, T6 a2);
/* INTEGER_32.is_greater_equal */
extern T1 T6f9(TC* ac, T6 volatile* C, T6 a1);
/* HASH_TABLE [INTEGER_32, INTEGER_32].hash_code_of */
extern T6 T28f25(TC* ac, T0* C, T6 a1);
/* INTEGER_32.hash_code */
extern T6 T6f13(TC* ac, T6 volatile* C);
/* TYPE [detachable SERIALIZATION_FAILURE].type_id */
extern T6 T99f1(TC* ac, T0* C);
/* TYPE [detachable ADDRESS_APPLIED_TO_MELTED_FEATURE].type_id */
extern T6 T98f1(TC* ac, T0* C);
/* TYPE [detachable DEVELOPER_EXCEPTION].type_id */
extern T6 T97f1(TC* ac, T0* C);
/* TYPE [detachable MISMATCH_FAILURE].type_id */
extern T6 T96f1(TC* ac, T0* C);
/* TYPE [detachable EXCEPTION_IN_SIGNAL_HANDLER_FAILURE].type_id */
extern T6 T95f1(TC* ac, T0* C);
/* TYPE [detachable VOID_ASSIGNED_TO_EXPANDED].type_id */
extern T6 T94f1(TC* ac, T0* C);
/* TYPE [detachable EXTERNAL_FAILURE].type_id */
extern T6 T93f1(TC* ac, T0* C);
/* TYPE [detachable CREATE_ON_DEFERRED].type_id */
extern T6 T92f1(TC* ac, T0* C);
/* TYPE [detachable RESUMPTION_FAILURE].type_id */
extern T6 T91f1(TC* ac, T0* C);
/* TYPE [detachable RESCUE_FAILURE].type_id */
extern T6 T90f1(TC* ac, T0* C);
/* TYPE [detachable LOOP_INVARIANT_VIOLATION].type_id */
extern T6 T89f1(TC* ac, T0* C);
/* TYPE [detachable VARIANT_VIOLATION].type_id */
extern T6 T88f1(TC* ac, T0* C);
/* TYPE [detachable BAD_INSPECT_VALUE].type_id */
extern T6 T87f1(TC* ac, T0* C);
/* TYPE [detachable CHECK_VIOLATION].type_id */
extern T6 T86f1(TC* ac, T0* C);
/* TYPE [detachable FLOATING_POINT_FAILURE].type_id */
extern T6 T85f1(TC* ac, T0* C);
/* TYPE [detachable POSTCONDITION_VIOLATION].type_id */
extern T6 T84f1(TC* ac, T0* C);
/* TYPE [detachable PRECONDITION_VIOLATION].type_id */
extern T6 T83f1(TC* ac, T0* C);
/* TYPE [detachable EIFFEL_RUNTIME_PANIC].type_id */
extern T6 T82f1(TC* ac, T0* C);
/* TYPE [detachable COM_FAILURE].type_id */
extern T6 T81f1(TC* ac, T0* C);
/* TYPE [detachable OPERATING_SYSTEM_FAILURE].type_id */
extern T6 T80f1(TC* ac, T0* C);
/* TYPE [detachable IO_FAILURE].type_id */
extern T6 T79f1(TC* ac, T0* C);
/* TYPE [detachable OPERATING_SYSTEM_SIGNAL_FAILURE].type_id */
extern T6 T78f1(TC* ac, T0* C);
/* TYPE [detachable INVARIANT_VIOLATION].type_id */
extern T6 T77f1(TC* ac, T0* C);
/* TYPE [detachable NO_MORE_MEMORY].type_id */
extern T6 T76f1(TC* ac, T0* C);
/* TYPE [detachable OLD_VIOLATION].type_id */
extern T6 T75f1(TC* ac, T0* C);
/* TYPE [detachable ROUTINE_FAILURE].type_id */
extern T6 T74f1(TC* ac, T0* C);
/* TYPE [detachable VOID_TARGET].type_id */
extern T6 T69f1(TC* ac, T0* C);
/* ISE_EXCEPTION_MANAGER.ignored_exceptions */
extern T0* T21s3(TC* ac);
/* HASH_TABLE [INTEGER_32, INTEGER_32].make */
extern T0* T28c35(TC* ac, T6 a1);
/* SPECIAL [INTEGER_32].make_filled */
extern T0* T66c5(TC* ac, T6 a1, T6 a2);
/* SPECIAL [INTEGER_32].fill_with */
extern void T66f8(TC* ac, T0* C, T6 a1, T6 a2, T6 a3);
/* SPECIAL [INTEGER_32].extend */
extern void T66f9(TC* ac, T0* C, T6 a1);
/* INTEGER_32.min */
extern T6 T6f12(TC* ac, T6 volatile* C, T6 a1);
/* INTEGER_32.is_less_equal */
extern T1 T6f15(TC* ac, T6 volatile* C, T6 a1);
/* SPECIAL [BOOLEAN].make_filled */
extern T0* T67c4(TC* ac, T1 a1, T6 a2);
/* SPECIAL [BOOLEAN].fill_with */
extern void T67f7(TC* ac, T0* C, T1 a1, T6 a2, T6 a3);
/* SPECIAL [BOOLEAN].extend */
extern void T67f9(TC* ac, T0* C, T1 a1);
/* SPECIAL [BOOLEAN].make_empty */
extern void T67f6(TC* ac, T0* C, T6 a1);
/* SPECIAL [INTEGER_32].make_empty */
extern void T66f4(TC* ac, T0* C, T6 a1);
/* SPECIAL [INTEGER_32].make_empty */
extern T0* T66c4(TC* ac, T6 a1);
/* PRIMES.higher_prime */
extern T6 T65s1(TC* ac, T6 a1);
/* PRIMES.is_prime */
extern T1 T65s3(TC* ac, T6 a1);
/* PRIMES.default_create */
extern T0* T65c5(TC* ac);
/* DEVELOPER_EXCEPTION.exception_manager */
extern T0* T62s6(TC* ac);
/* DEVELOPER_EXCEPTION.default_create */
extern T0* T62c11(TC* ac);
/* EXCEPTIONS.default_create */
extern T0* T101c1(TC* ac);
/* MANAGED_POINTER.default_pointer */
extern T14 T73s4(TC* ac);
/* POINTER.memory_realloc */
extern T14 T14f5(TC* ac, T14 volatile* C, T6 a1);
/* POINTER.c_realloc */
extern T14 T14s8(TC* ac, T14 a1, T6 a2);
/* INTEGER_32.max */
extern T6 T6f4(TC* ac, T6 volatile* C, T6 a1);
/* UTF_CONVERTER.utf_32_string_into_utf_8_0_pointer */
extern void T71s4(TC* ac, T0* a1, T0* a2, T6 a3, T0* a4);
/* MANAGED_POINTER.put_natural_8 */
extern void T73f9(TC* ac, T0* C, T8 a1, T6 a2);
/* POINTER.memory_copy */
extern void T14f13(TC* ac, T14 volatile* C, T14 a1, T6 a2);
/* POINTER.c_memcpy */
extern void T14s17(TC* ac, T14 a1, T14 a2, T6 a3);
/* NATURAL_32.to_natural_8 */
extern T8 T10f4(TC* ac, T10 volatile* C);
/* NATURAL_32.is_less_equal */
extern T1 T10f5(TC* ac, T10 volatile* C, T10 a1);
/* STRING_8.code */
extern T10 T17f5(TC* ac, T0* C, T6 a1);
/* INTEGER_32.to_natural_32 */
extern T10 T6f21(TC* ac, T6 volatile* C);
/* UTF_CONVERTER.utf_8_bytes_count */
extern T6 T71s3(TC* ac, T0* a1, T6 a2, T6 a3);
/* CELL [INTEGER_32].put */
extern void T72f2(TC* ac, T0* C, T6 a1);
/* CELL [INTEGER_32].put */
extern T0* T72c2(TC* ac, T6 a1);
/* C_STRING.make_empty */
extern void T31f4(TC* ac, T0* C, T6 a1);
/* C_STRING.make_empty */
extern T0* T31c4(TC* ac, T6 a1);
/* MANAGED_POINTER.make */
extern T0* T73c7(TC* ac, T6 a1);
/* POINTER.memory_calloc */
extern T14 T14s4(TC* ac, T6 a1, T6 a2);
/* POINTER.c_calloc */
extern T14 T14s7(TC* ac, T6 a1, T6 a2);
/* MANAGED_POINTER.increment_counter */
extern void T73f10(TC* ac, T0* C);
/* SERIALIZATION_FAILURE.set_description */
extern void T64f14(TC* ac, T0* C, T0* a1);
/* OLD_VIOLATION.set_description */
extern void T37f14(TC* ac, T0* C, T0* a1);
/* COM_FAILURE.set_description */
extern void T44f22(TC* ac, T0* C, T0* a1);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_description */
extern void T63f14(TC* ac, T0* C, T0* a1);
/* DEVELOPER_EXCEPTION.set_description */
extern void T62f14(TC* ac, T0* C, T0* a1);
/* MISMATCH_FAILURE.set_description */
extern void T61f14(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_FAILURE.set_description */
extern void T43f16(TC* ac, T0* C, T0* a1);
/* IO_FAILURE.set_description */
extern void T42f18(TC* ac, T0* C, T0* a1);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_description */
extern void T60f14(TC* ac, T0* C, T0* a1);
/* VOID_ASSIGNED_TO_EXPANDED.set_description */
extern void T59f14(TC* ac, T0* C, T0* a1);
/* EXTERNAL_FAILURE.set_description */
extern void T58f14(TC* ac, T0* C, T0* a1);
/* CREATE_ON_DEFERRED.set_description */
extern void T57f14(TC* ac, T0* C, T0* a1);
/* RESUMPTION_FAILURE.set_description */
extern void T56f14(TC* ac, T0* C, T0* a1);
/* RESCUE_FAILURE.set_description */
extern void T55f14(TC* ac, T0* C, T0* a1);
/* EIFFEL_RUNTIME_PANIC.set_description */
extern void T45f16(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_description */
extern void T41f16(TC* ac, T0* C, T0* a1);
/* LOOP_INVARIANT_VIOLATION.set_description */
extern void T54f14(TC* ac, T0* C, T0* a1);
/* VARIANT_VIOLATION.set_description */
extern void T53f14(TC* ac, T0* C, T0* a1);
/* BAD_INSPECT_VALUE.set_description */
extern void T52f14(TC* ac, T0* C, T0* a1);
/* ROUTINE_FAILURE.set_description */
extern void T35f18(TC* ac, T0* C, T0* a1);
/* CHECK_VIOLATION.set_description */
extern void T51f14(TC* ac, T0* C, T0* a1);
/* INVARIANT_VIOLATION.set_description */
extern void T40f16(TC* ac, T0* C, T0* a1);
/* FLOATING_POINT_FAILURE.set_description */
extern void T50f14(TC* ac, T0* C, T0* a1);
/* POSTCONDITION_VIOLATION.set_description */
extern void T49f14(TC* ac, T0* C, T0* a1);
/* PRECONDITION_VIOLATION.set_description */
extern void T48f14(TC* ac, T0* C, T0* a1);
/* VOID_TARGET.set_description */
extern void T33f14(TC* ac, T0* C, T0* a1);
/* ISE_EXCEPTION_MANAGER.in_rescue */
extern T1 T21s8(TC* ac);
/* COM_FAILURE.set_exception_information */
extern void T44f20(TC* ac, T0* C, T0* a1);
/* C_STRING.make */
extern T0* T31c6(TC* ac, T0* a1);
/* C_STRING.set_string */
extern void T31f7(TC* ac, T0* C, T0* a1);
/* C_STRING.set_substring */
extern void T31f8(TC* ac, T0* C, T0* a1, T6 a2, T6 a3);
/* COM_FAILURE.ccom_hresult_to_string */
extern T0* T44f10(TC* ac, T0* C, T6 a1);
/* STRING_8.plus */
extern T0* T17f6(TC* ac, T0* C, T0* a1);
/* STRING_8.append */
extern void T17f15(TC* ac, T0* C, T0* a1);
/* STRING_8.reset_hash_codes */
extern void T17f17(TC* ac, T0* C);
/* SPECIAL [CHARACTER_8].copy_data */
extern void T15f11(TC* ac, T0* C, T0* a1, T6 a2, T6 a3, T6 a4);
/* SPECIAL [CHARACTER_8].force */
extern void T15f13(TC* ac, T0* C, T2 a1, T6 a2);
/* SPECIAL [CHARACTER_8].extend */
extern void T15f10(TC* ac, T0* C, T2 a1);
/* SPECIAL [CHARACTER_8].move_data */
extern void T15f12(TC* ac, T0* C, T6 a1, T6 a2, T6 a3);
/* SPECIAL [CHARACTER_8].overlapping_move */
extern void T15f15(TC* ac, T0* C, T6 a1, T6 a2, T6 a3);
/* SPECIAL [CHARACTER_8].fill_with */
extern void T15f8(TC* ac, T0* C, T2 a1, T6 a2, T6 a3);
/* SPECIAL [CHARACTER_8].non_overlapping_move */
extern void T15f14(TC* ac, T0* C, T6 a1, T6 a2, T6 a3);
/* STRING_8.area_lower */
extern T6 T17f10(TC* ac, T0* C);
/* STRING_8.resize */
extern void T17f18(TC* ac, T0* C, T6 a1);
/* SPECIAL [CHARACTER_8].aliased_resized_area_with_default */
extern T0* T15f4(TC* ac, T0* C, T2 a1, T6 a2);
/* SPECIAL [CHARACTER_8].aliased_resized_area */
extern T0* T15f5(TC* ac, T0* C, T6 a1);
/* STRING_8.additional_space */
extern T6 T17f9(TC* ac, T0* C);
/* STRING_8.capacity */
extern T6 T17f8(TC* ac, T0* C);
/* STRING_8.new_string */
extern T0* T17f7(TC* ac, T0* C, T6 a1);
/* STRING_8.make */
extern void T17f12(TC* ac, T0* C, T6 a1);
/* STRING_8.make */
extern T0* T17c12(TC* ac, T6 a1);
/* SPECIAL [CHARACTER_8].make_filled */
extern T0* T15c6(TC* ac, T2 a1, T6 a2);
/* SPECIAL [CHARACTER_8].make_empty */
extern void T15f7(TC* ac, T0* C, T6 a1);
/* INTEGER_32.to_hex_string */
extern T0* T6f18(TC* ac, T6 volatile* C);
/* STRING_8.put */
extern void T17f14(TC* ac, T0* C, T2 a1, T6 a2);
/* INTEGER_32.to_hex_character */
extern T2 T6f19(TC* ac, T6 volatile* C);
/* CHARACTER_8.plus */
extern T2 T2f5(TC* ac, T2 volatile* C, T6 a1);
/* CHARACTER_8.minus */
extern T2 T2f4(TC* ac, T2 volatile* C, T6 a1);
/* STRING_8.make_filled */
extern T0* T17c13(TC* ac, T2 a1, T6 a2);
/* STRING_8.fill_character */
extern void T17f16(TC* ac, T0* C, T2 a1);
/* COM_FAILURE.set_hresult_code */
extern void T44f19(TC* ac, T0* C, T6 a1);
/* OPERATING_SYSTEM_FAILURE.set_error_code */
extern void T43f14(TC* ac, T0* C, T6 a1);
/* IO_FAILURE.set_error_code */
extern void T42f16(TC* ac, T0* C, T6 a1);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_signal_code */
extern void T41f14(TC* ac, T0* C, T6 a1);
/* INVARIANT_VIOLATION.set_is_entry */
extern void T40f14(TC* ac, T0* C, T1 a1);
/* ROUTINE_FAILURE.set_class_name */
extern void T35f15(TC* ac, T0* C, T0* a1);
/* ROUTINE_FAILURE.set_routine_name */
extern void T35f14(TC* ac, T0* C, T0* a1);
/* NO_MORE_MEMORY.set_throwing_exception */
extern void T39f15(TC* ac, T0* C, T0* a1);
/* SERIALIZATION_FAILURE.set_throwing_exception */
extern void T64f12(TC* ac, T0* C, T0* a1);
/* OLD_VIOLATION.set_throwing_exception */
extern void T37f12(TC* ac, T0* C, T0* a1);
/* COM_FAILURE.set_throwing_exception */
extern void T44f18(TC* ac, T0* C, T0* a1);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.set_throwing_exception */
extern void T63f12(TC* ac, T0* C, T0* a1);
/* DEVELOPER_EXCEPTION.set_throwing_exception */
extern void T62f12(TC* ac, T0* C, T0* a1);
/* MISMATCH_FAILURE.set_throwing_exception */
extern void T61f12(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_FAILURE.set_throwing_exception */
extern void T43f13(TC* ac, T0* C, T0* a1);
/* IO_FAILURE.set_throwing_exception */
extern void T42f15(TC* ac, T0* C, T0* a1);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.set_throwing_exception */
extern void T60f12(TC* ac, T0* C, T0* a1);
/* VOID_ASSIGNED_TO_EXPANDED.set_throwing_exception */
extern void T59f12(TC* ac, T0* C, T0* a1);
/* EXTERNAL_FAILURE.set_throwing_exception */
extern void T58f12(TC* ac, T0* C, T0* a1);
/* CREATE_ON_DEFERRED.set_throwing_exception */
extern void T57f12(TC* ac, T0* C, T0* a1);
/* RESUMPTION_FAILURE.set_throwing_exception */
extern void T56f12(TC* ac, T0* C, T0* a1);
/* RESCUE_FAILURE.set_throwing_exception */
extern void T55f12(TC* ac, T0* C, T0* a1);
/* EIFFEL_RUNTIME_PANIC.set_throwing_exception */
extern void T45f14(TC* ac, T0* C, T0* a1);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.set_throwing_exception */
extern void T41f13(TC* ac, T0* C, T0* a1);
/* LOOP_INVARIANT_VIOLATION.set_throwing_exception */
extern void T54f12(TC* ac, T0* C, T0* a1);
/* VARIANT_VIOLATION.set_throwing_exception */
extern void T53f12(TC* ac, T0* C, T0* a1);
/* BAD_INSPECT_VALUE.set_throwing_exception */
extern void T52f12(TC* ac, T0* C, T0* a1);
/* ROUTINE_FAILURE.set_throwing_exception */
extern void T35f16(TC* ac, T0* C, T0* a1);
/* CHECK_VIOLATION.set_throwing_exception */
extern void T51f12(TC* ac, T0* C, T0* a1);
/* INVARIANT_VIOLATION.set_throwing_exception */
extern void T40f13(TC* ac, T0* C, T0* a1);
/* FLOATING_POINT_FAILURE.set_throwing_exception */
extern void T50f12(TC* ac, T0* C, T0* a1);
/* POSTCONDITION_VIOLATION.set_throwing_exception */
extern void T49f12(TC* ac, T0* C, T0* a1);
/* PRECONDITION_VIOLATION.set_throwing_exception */
extern void T48f12(TC* ac, T0* C, T0* a1);
/* VOID_TARGET.set_throwing_exception */
extern void T33f12(TC* ac, T0* C, T0* a1);
/* ISE_EXCEPTION_MANAGER.exception_from_code */
extern T0* T21s12(TC* ac, T6 a1);
/* SERIALIZATION_FAILURE.default_create */
extern T0* T64c11(TC* ac);
/* OLD_VIOLATION.default_create */
extern T0* T37c11(TC* ac);
/* COM_FAILURE.default_create */
extern T0* T44c17(TC* ac);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.default_create */
extern T0* T63c11(TC* ac);
/* MISMATCH_FAILURE.default_create */
extern T0* T61c11(TC* ac);
/* OPERATING_SYSTEM_FAILURE.default_create */
extern T0* T43c12(TC* ac);
/* IO_FAILURE.set_code */
extern void T42f14(TC* ac, T0* C, T6 a1);
/* IO_FAILURE.default_create */
extern T0* T42c13(TC* ac);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.default_create */
extern T0* T60c11(TC* ac);
/* VOID_ASSIGNED_TO_EXPANDED.default_create */
extern T0* T59c11(TC* ac);
/* EXTERNAL_FAILURE.default_create */
extern T0* T58c11(TC* ac);
/* CREATE_ON_DEFERRED.default_create */
extern T0* T57c11(TC* ac);
/* RESUMPTION_FAILURE.default_create */
extern T0* T56c11(TC* ac);
/* RESCUE_FAILURE.default_create */
extern T0* T55c11(TC* ac);
/* EIFFEL_RUNTIME_PANIC.set_code */
extern void T45f13(TC* ac, T0* C, T6 a1);
/* EIFFEL_RUNTIME_PANIC.code */
extern T6 T45f9(TC* ac, T0* C);
/* EIFFEL_RUNTIME_PANIC.default_create */
extern T0* T45c12(TC* ac);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.default_create */
extern T0* T41c12(TC* ac);
/* LOOP_INVARIANT_VIOLATION.default_create */
extern T0* T54c11(TC* ac);
/* VARIANT_VIOLATION.default_create */
extern T0* T53c11(TC* ac);
/* BAD_INSPECT_VALUE.default_create */
extern T0* T52c11(TC* ac);
/* ROUTINE_FAILURE.default_create */
extern T0* T35c13(TC* ac);
/* CHECK_VIOLATION.default_create */
extern T0* T51c11(TC* ac);
/* INVARIANT_VIOLATION.default_create */
extern T0* T40c12(TC* ac);
/* FLOATING_POINT_FAILURE.default_create */
extern T0* T50c11(TC* ac);
/* POSTCONDITION_VIOLATION.default_create */
extern T0* T49c11(TC* ac);
/* PRECONDITION_VIOLATION.default_create */
extern T0* T48c11(TC* ac);
/* NO_MORE_MEMORY.set_code */
extern void T39f14(TC* ac, T0* C, T6 a1);
/* NO_MORE_MEMORY.code */
extern T6 T39f9(TC* ac, T0* C);
/* ISE_EXCEPTION_MANAGER.no_memory_exception_object_cell */
extern T0* T21s7(TC* ac);
/* CELL [NO_MORE_MEMORY].put */
extern T0* T30c2(TC* ac, T0* a1);
/* NO_MORE_MEMORY.default_create */
extern T0* T39c12(TC* ac);
/* VOID_TARGET.default_create */
extern T0* T33c11(TC* ac);
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
extern T6 T64f9(TC* ac, T0* C);
/* OLD_VIOLATION.code */
extern T6 T37f9(TC* ac, T0* C);
/* COM_FAILURE.code */
extern T6 T44f9(TC* ac, T0* C);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.code */
extern T6 T63f9(TC* ac, T0* C);
/* MISMATCH_FAILURE.code */
extern T6 T61f9(TC* ac, T0* C);
/* OPERATING_SYSTEM_FAILURE.code */
extern T6 T43f9(TC* ac, T0* C);
/* IO_FAILURE.code */
extern T6 T42f9(TC* ac, T0* C);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.code */
extern T6 T60f9(TC* ac, T0* C);
/* VOID_ASSIGNED_TO_EXPANDED.code */
extern T6 T59f9(TC* ac, T0* C);
/* EXTERNAL_FAILURE.code */
extern T6 T58f9(TC* ac, T0* C);
/* CREATE_ON_DEFERRED.code */
extern T6 T57f9(TC* ac, T0* C);
/* RESUMPTION_FAILURE.code */
extern T6 T56f9(TC* ac, T0* C);
/* RESCUE_FAILURE.code */
extern T6 T55f9(TC* ac, T0* C);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.code */
extern T6 T41f9(TC* ac, T0* C);
/* LOOP_INVARIANT_VIOLATION.code */
extern T6 T54f9(TC* ac, T0* C);
/* VARIANT_VIOLATION.code */
extern T6 T53f9(TC* ac, T0* C);
/* BAD_INSPECT_VALUE.code */
extern T6 T52f9(TC* ac, T0* C);
/* ROUTINE_FAILURE.code */
extern T6 T35f9(TC* ac, T0* C);
/* CHECK_VIOLATION.code */
extern T6 T51f9(TC* ac, T0* C);
/* INVARIANT_VIOLATION.code */
extern T6 T40f9(TC* ac, T0* C);
/* FLOATING_POINT_FAILURE.code */
extern T6 T50f9(TC* ac, T0* C);
/* POSTCONDITION_VIOLATION.code */
extern T6 T49f9(TC* ac, T0* C);
/* PRECONDITION_VIOLATION.code */
extern T6 T48f9(TC* ac, T0* C);
/* VOID_TARGET.code */
extern T6 T33f9(TC* ac, T0* C);
/* NO_MORE_MEMORY.c_description */
extern T0* T39f1(TC* ac, T0* C);
/* SERIALIZATION_FAILURE.c_description */
extern T0* T64f1(TC* ac, T0* C);
/* OLD_VIOLATION.c_description */
extern T0* T37f1(TC* ac, T0* C);
/* COM_FAILURE.c_description */
extern T0* T44f1(TC* ac, T0* C);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.c_description */
extern T0* T63f1(TC* ac, T0* C);
/* DEVELOPER_EXCEPTION.c_description */
extern T0* T62f1(TC* ac, T0* C);
/* MISMATCH_FAILURE.c_description */
extern T0* T61f1(TC* ac, T0* C);
/* OPERATING_SYSTEM_FAILURE.c_description */
extern T0* T43f1(TC* ac, T0* C);
/* IO_FAILURE.c_description */
extern T0* T42f1(TC* ac, T0* C);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.c_description */
extern T0* T60f1(TC* ac, T0* C);
/* VOID_ASSIGNED_TO_EXPANDED.c_description */
extern T0* T59f1(TC* ac, T0* C);
/* EXTERNAL_FAILURE.c_description */
extern T0* T58f1(TC* ac, T0* C);
/* CREATE_ON_DEFERRED.c_description */
extern T0* T57f1(TC* ac, T0* C);
/* RESUMPTION_FAILURE.c_description */
extern T0* T56f1(TC* ac, T0* C);
/* RESCUE_FAILURE.c_description */
extern T0* T55f1(TC* ac, T0* C);
/* EIFFEL_RUNTIME_PANIC.c_description */
extern T0* T45f1(TC* ac, T0* C);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.c_description */
extern T0* T41f1(TC* ac, T0* C);
/* LOOP_INVARIANT_VIOLATION.c_description */
extern T0* T54f1(TC* ac, T0* C);
/* VARIANT_VIOLATION.c_description */
extern T0* T53f1(TC* ac, T0* C);
/* BAD_INSPECT_VALUE.c_description */
extern T0* T52f1(TC* ac, T0* C);
/* ROUTINE_FAILURE.c_description */
extern T0* T35f1(TC* ac, T0* C);
/* CHECK_VIOLATION.c_description */
extern T0* T51f1(TC* ac, T0* C);
/* INVARIANT_VIOLATION.c_description */
extern T0* T40f1(TC* ac, T0* C);
/* FLOATING_POINT_FAILURE.c_description */
extern T0* T50f1(TC* ac, T0* C);
/* POSTCONDITION_VIOLATION.c_description */
extern T0* T49f1(TC* ac, T0* C);
/* PRECONDITION_VIOLATION.c_description */
extern T0* T48f1(TC* ac, T0* C);
/* VOID_TARGET.c_description */
extern T0* T33f1(TC* ac, T0* C);
/* NO_MORE_MEMORY.original */
extern T0* T39f10(TC* ac, T0* C);
/* SERIALIZATION_FAILURE.original */
extern T0* T64f10(TC* ac, T0* C);
/* OLD_VIOLATION.original */
extern T0* T37f10(TC* ac, T0* C);
/* COM_FAILURE.original */
extern T0* T44f11(TC* ac, T0* C);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.original */
extern T0* T63f10(TC* ac, T0* C);
/* DEVELOPER_EXCEPTION.original */
extern T0* T62f10(TC* ac, T0* C);
/* MISMATCH_FAILURE.original */
extern T0* T61f10(TC* ac, T0* C);
/* OPERATING_SYSTEM_FAILURE.original */
extern T0* T43f10(TC* ac, T0* C);
/* IO_FAILURE.original */
extern T0* T42f10(TC* ac, T0* C);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.original */
extern T0* T60f10(TC* ac, T0* C);
/* VOID_ASSIGNED_TO_EXPANDED.original */
extern T0* T59f10(TC* ac, T0* C);
/* EXTERNAL_FAILURE.original */
extern T0* T58f10(TC* ac, T0* C);
/* CREATE_ON_DEFERRED.original */
extern T0* T57f10(TC* ac, T0* C);
/* RESUMPTION_FAILURE.original */
extern T0* T56f10(TC* ac, T0* C);
/* RESCUE_FAILURE.original */
extern T0* T55f10(TC* ac, T0* C);
/* EIFFEL_RUNTIME_PANIC.original */
extern T0* T45f10(TC* ac, T0* C);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.original */
extern T0* T41f10(TC* ac, T0* C);
/* LOOP_INVARIANT_VIOLATION.original */
extern T0* T54f10(TC* ac, T0* C);
/* VARIANT_VIOLATION.original */
extern T0* T53f10(TC* ac, T0* C);
/* BAD_INSPECT_VALUE.original */
extern T0* T52f10(TC* ac, T0* C);
/* ROUTINE_FAILURE.original */
extern T0* T35f10(TC* ac, T0* C);
/* CHECK_VIOLATION.original */
extern T0* T51f10(TC* ac, T0* C);
/* INVARIANT_VIOLATION.original */
extern T0* T40f10(TC* ac, T0* C);
/* FLOATING_POINT_FAILURE.original */
extern T0* T50f10(TC* ac, T0* C);
/* POSTCONDITION_VIOLATION.original */
extern T0* T49f10(TC* ac, T0* C);
/* PRECONDITION_VIOLATION.original */
extern T0* T48f10(TC* ac, T0* C);
/* VOID_TARGET.original */
extern T0* T33f10(TC* ac, T0* C);
/* NO_MORE_MEMORY.is_ignored */
extern T1 T39f8(TC* ac, T0* C);
/* NO_MORE_MEMORY.exception_manager */
extern T0* T39s11(TC* ac);
/* SERIALIZATION_FAILURE.is_ignored */
extern T1 T64f8(TC* ac, T0* C);
/* SERIALIZATION_FAILURE.exception_manager */
extern T0* T64s6(TC* ac);
/* OLD_VIOLATION.is_ignored */
extern T1 T37f8(TC* ac, T0* C);
/* OLD_VIOLATION.exception_manager */
extern T0* T37s6(TC* ac);
/* COM_FAILURE.is_ignored */
extern T1 T44f16(TC* ac, T0* C);
/* COM_FAILURE.exception_manager */
extern T0* T44s14(TC* ac);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.is_ignored */
extern T1 T63f8(TC* ac, T0* C);
/* ADDRESS_APPLIED_TO_MELTED_FEATURE.exception_manager */
extern T0* T63s6(TC* ac);
/* MISMATCH_FAILURE.is_ignored */
extern T1 T61f8(TC* ac, T0* C);
/* MISMATCH_FAILURE.exception_manager */
extern T0* T61s6(TC* ac);
/* OPERATING_SYSTEM_FAILURE.is_ignored */
extern T1 T43f8(TC* ac, T0* C);
/* OPERATING_SYSTEM_FAILURE.exception_manager */
extern T0* T43s11(TC* ac);
/* IO_FAILURE.is_ignored */
extern T1 T42f8(TC* ac, T0* C);
/* IO_FAILURE.exception_manager */
extern T0* T42s11(TC* ac);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.is_ignored */
extern T1 T60f8(TC* ac, T0* C);
/* EXCEPTION_IN_SIGNAL_HANDLER_FAILURE.exception_manager */
extern T0* T60s6(TC* ac);
/* VOID_ASSIGNED_TO_EXPANDED.is_ignored */
extern T1 T59f8(TC* ac, T0* C);
/* VOID_ASSIGNED_TO_EXPANDED.exception_manager */
extern T0* T59s6(TC* ac);
/* EXTERNAL_FAILURE.is_ignored */
extern T1 T58f8(TC* ac, T0* C);
/* EXTERNAL_FAILURE.exception_manager */
extern T0* T58s6(TC* ac);
/* CREATE_ON_DEFERRED.is_ignored */
extern T1 T57f8(TC* ac, T0* C);
/* CREATE_ON_DEFERRED.exception_manager */
extern T0* T57s6(TC* ac);
/* RESUMPTION_FAILURE.is_ignored */
extern T1 T56f8(TC* ac, T0* C);
/* RESUMPTION_FAILURE.exception_manager */
extern T0* T56s6(TC* ac);
/* RESCUE_FAILURE.is_ignored */
extern T1 T55f8(TC* ac, T0* C);
/* RESCUE_FAILURE.exception_manager */
extern T0* T55s6(TC* ac);
/* EIFFEL_RUNTIME_PANIC.is_ignored */
extern T1 T45f8(TC* ac, T0* C);
/* EIFFEL_RUNTIME_PANIC.exception_manager */
extern T0* T45s11(TC* ac);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.is_ignored */
extern T1 T41f8(TC* ac, T0* C);
/* OPERATING_SYSTEM_SIGNAL_FAILURE.exception_manager */
extern T0* T41s11(TC* ac);
/* LOOP_INVARIANT_VIOLATION.is_ignored */
extern T1 T54f8(TC* ac, T0* C);
/* LOOP_INVARIANT_VIOLATION.exception_manager */
extern T0* T54s6(TC* ac);
/* VARIANT_VIOLATION.is_ignored */
extern T1 T53f8(TC* ac, T0* C);
/* VARIANT_VIOLATION.exception_manager */
extern T0* T53s6(TC* ac);
/* BAD_INSPECT_VALUE.is_ignored */
extern T1 T52f8(TC* ac, T0* C);
/* BAD_INSPECT_VALUE.exception_manager */
extern T0* T52s6(TC* ac);
/* ROUTINE_FAILURE.is_ignored */
extern T1 T35f8(TC* ac, T0* C);
/* ROUTINE_FAILURE.exception_manager */
extern T0* T35s11(TC* ac);
/* CHECK_VIOLATION.is_ignored */
extern T1 T51f8(TC* ac, T0* C);
/* CHECK_VIOLATION.exception_manager */
extern T0* T51s6(TC* ac);
/* INVARIANT_VIOLATION.is_ignored */
extern T1 T40f8(TC* ac, T0* C);
/* INVARIANT_VIOLATION.exception_manager */
extern T0* T40s11(TC* ac);
/* FLOATING_POINT_FAILURE.is_ignored */
extern T1 T50f8(TC* ac, T0* C);
/* FLOATING_POINT_FAILURE.exception_manager */
extern T0* T50s6(TC* ac);
/* POSTCONDITION_VIOLATION.is_ignored */
extern T1 T49f8(TC* ac, T0* C);
/* POSTCONDITION_VIOLATION.exception_manager */
extern T0* T49s6(TC* ac);
/* PRECONDITION_VIOLATION.is_ignored */
extern T1 T48f8(TC* ac, T0* C);
/* PRECONDITION_VIOLATION.exception_manager */
extern T0* T48s6(TC* ac);
/* VOID_TARGET.is_ignored */
extern T1 T33f8(TC* ac, T0* C);
/* VOID_TARGET.exception_manager */
extern T0* T33s6(TC* ac);
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
extern void T66f7(TC* ac, T0* C, T6 a1, T6 a2);
/* SPECIAL [BOOLEAN].force */
extern void T67f5(TC* ac, T0* C, T1 a1, T6 a2);
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
extern void T73f6(TC* ac, T0* C);
/* POINTER.memory_free */
extern void T14f11(TC* ac, T14 volatile* C);
/* POINTER.default_pointer */
extern T14 T14s9(TC* ac);
/* POINTER.c_free */
extern void T14s14(TC* ac, T14 a1);
/* Call to EXCEPTION.original */
extern T0* T22x4669448(TC* ac, T0* C);
/* Call to EXCEPTION.code */
extern T6 T22x4669447(TC* ac, T0* C);
/* Call to EXCEPTION.c_description */
extern T0* T22x4669460(TC* ac, T0* C);
/* Call to EXCEPTION.is_ignored */
extern T1 T22x4669456(TC* ac, T0* C);
/* Call to TYPE [detachable EXCEPTION].type_id */
extern T6 T70x3883012(TC* ac, T0* C);
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
extern T0* GE_mt32(TC* ac, T6 a1, T6 a2, T6 a3, T0* a4, T0* a5, T0* a6, T0* a7, T0* a8, T0* a9, T6 a10, T1 a11);
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
