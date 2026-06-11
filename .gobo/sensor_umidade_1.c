/* C files for Boehm GC. */

#if defined(WIN32) || defined(WINVER) || defined(_WIN32_WINNT) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(_WIN_MSC_VER32)
#	define GE_WINDOWS
#elif defined(macintosh) || defined(Macintosh) || defined(__APPLE__) || defined(__MACH__)
#	define GE_MACOS
#elif defined(__OpenBSD__)
#	define GE_OPENBSD
#endif

/*
 * Workaround for crashes (illegal instruction signal) when calling
 * `memset` in Azure Devops pipelines under Windows.
 */
#if defined(GE_WINDOWS) && defined(__clang__)
#include <string.h>
extern void* GE_memset(void* str, int c, size_t n);
#define memset(x, y, z) GE_memset((x), (y), (z))
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
#	if defined(GE_MACOS)
#		define FORCE_DESC_CATCH_EXCEPTION_RAISE
#	else
#		define GC_PTHREAD_START_STANDALONE
#	endif
#	ifndef _REENTRANT
#		define _REENTRANT
#	endif
#	define HANDLE_FORK
#endif

#if defined(__clang__) || defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW64__)
#	define GC_BUILTIN_ATOMIC
#	if defined(GE_WINDOWS)
#		define NO_WRAP_MARK_SOME
#	endif
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

#include "/home/edson/Documentos/trabalhoEiffel/gobo-26.05.14+6b1e882/tool/gec/backend/c/boehm_gc/extra/gc.c"
#ifdef GC_PTHREAD_START_STANDALONE
#include "/home/edson/Documentos/trabalhoEiffel/gobo-26.05.14+6b1e882/tool/gec/backend/c/boehm_gc/pthread_start.c"
#endif

