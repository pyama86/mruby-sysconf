/*
** mrb_sysconf.c - Sysconf class
**
** Copyright (c) pyama86 2017
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include <string.h>
#include <unistd.h>

#define DONE mrb_gc_arena_restore(mrb, 0);
#define DEF_SYSCONF_CONST(mrb, klass, v)                                                           \
  mrb_define_const((mrb), (klass), #v, mrb_fixnum_value(sysconf(_##v)));

void mrb_mruby_sysconf_gem_init(mrb_state *mrb)
{
  struct RClass *klass;
  klass = mrb_define_class(mrb, "Sysconf", mrb->object_class);
#ifdef _SC_ARG_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_ARG_MAX)
#endif
#ifdef _SC_CHILD_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_CHILD_MAX)
#endif
#ifdef _SC_CLK_TCK
  DEF_SYSCONF_CONST(mrb, klass, SC_CLK_TCK)
#endif
#ifdef _SC_NGROUPS_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_NGROUPS_MAX)
#endif
#ifdef _SC_OPEN_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_OPEN_MAX)
#endif
#ifdef _SC_STREAM_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_STREAM_MAX)
#endif
#ifdef _SC_TZNAME_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_TZNAME_MAX)
#endif
#ifdef _SC_JOB_CONTROL
  DEF_SYSCONF_CONST(mrb, klass, SC_JOB_CONTROL)
#endif
#ifdef _SC_SAVED_IDS
  DEF_SYSCONF_CONST(mrb, klass, SC_SAVED_IDS)
#endif
#ifdef _SC_REALTIME_SIGNALS
  DEF_SYSCONF_CONST(mrb, klass, SC_REALTIME_SIGNALS)
#endif
#ifdef _SC_PRIORITY_SCHEDULING
  DEF_SYSCONF_CONST(mrb, klass, SC_PRIORITY_SCHEDULING)
#endif
#ifdef _SC_TIMERS
  DEF_SYSCONF_CONST(mrb, klass, SC_TIMERS)
#endif
#ifdef _SC_ASYNCHRONOUS_IO
  DEF_SYSCONF_CONST(mrb, klass, SC_ASYNCHRONOUS_IO)
#endif
#ifdef _SC_PRIORITIZED_IO
  DEF_SYSCONF_CONST(mrb, klass, SC_PRIORITIZED_IO)
#endif
#ifdef _SC_SYNCHRONIZED_IO
  DEF_SYSCONF_CONST(mrb, klass, SC_SYNCHRONIZED_IO)
#endif
#ifdef _SC_FSYNC
  DEF_SYSCONF_CONST(mrb, klass, SC_FSYNC)
#endif
#ifdef _SC_MAPPED_FILES
  DEF_SYSCONF_CONST(mrb, klass, SC_MAPPED_FILES)
#endif
#ifdef _SC_MEMLOCK
  DEF_SYSCONF_CONST(mrb, klass, SC_MEMLOCK)
#endif
#ifdef _SC_MEMLOCK_RANGE
  DEF_SYSCONF_CONST(mrb, klass, SC_MEMLOCK_RANGE)
#endif
#ifdef _SC_MEMORY_PROTECTION
  DEF_SYSCONF_CONST(mrb, klass, SC_MEMORY_PROTECTION)
#endif
#ifdef _SC_MESSAGE_PASSING
  DEF_SYSCONF_CONST(mrb, klass, SC_MESSAGE_PASSING)
#endif
#ifdef _SC_SEMAPHORES
  DEF_SYSCONF_CONST(mrb, klass, SC_SEMAPHORES)
#endif
#ifdef _SC_SHARED_MEMORY_OBJECTS
  DEF_SYSCONF_CONST(mrb, klass, SC_SHARED_MEMORY_OBJECTS)
#endif
#ifdef _SC_AIO_LISTIO_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_AIO_LISTIO_MAX)
#endif
#ifdef _SC_AIO_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_AIO_MAX)
#endif
#ifdef _SC_AIO_PRIO_DELTA_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_AIO_PRIO_DELTA_MAX)
#endif
#ifdef _SC_DELAYTIMER_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_DELAYTIMER_MAX)
#endif
#ifdef _SC_MQ_OPEN_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_MQ_OPEN_MAX)
#endif
#ifdef _SC_MQ_PRIO_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_MQ_PRIO_MAX)
#endif
#ifdef _SC_VERSION
  DEF_SYSCONF_CONST(mrb, klass, SC_VERSION)
#endif
#ifdef _SC_PAGESIZE
  DEF_SYSCONF_CONST(mrb, klass, SC_PAGESIZE)
#endif
#ifdef _SC_RTSIG_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_RTSIG_MAX)
#endif
#ifdef _SC_SEM_NSEMS_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_SEM_NSEMS_MAX)
#endif
#ifdef _SC_SEM_VALUE_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_SEM_VALUE_MAX)
#endif
#ifdef _SC_SIGQUEUE_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_SIGQUEUE_MAX)
#endif
#ifdef _SC_TIMER_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_TIMER_MAX)
#endif
#ifdef _SC_BC_BASE_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_BC_BASE_MAX)
#endif
#ifdef _SC_BC_DIM_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_BC_DIM_MAX)
#endif
#ifdef _SC_BC_SCALE_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_BC_SCALE_MAX)
#endif
#ifdef _SC_BC_STRING_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_BC_STRING_MAX)
#endif
#ifdef _SC_COLL_WEIGHTS_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_COLL_WEIGHTS_MAX)
#endif
#ifdef _SC_EQUIV_CLASS_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_EQUIV_CLASS_MAX)
#endif
#ifdef _SC_EXPR_NEST_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_EXPR_NEST_MAX)
#endif
#ifdef _SC_LINE_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_LINE_MAX)
#endif
#ifdef _SC_RE_DUP_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_RE_DUP_MAX)
#endif
#ifdef _SC_CHARCLASS_NAME_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_CHARCLASS_NAME_MAX)
#endif
#ifdef _SC_2_VERSION
  DEF_SYSCONF_CONST(mrb, klass, SC_2_VERSION)
#endif
#ifdef _SC_2_C_BIND
  DEF_SYSCONF_CONST(mrb, klass, SC_2_C_BIND)
#endif
#ifdef _SC_2_C_DEV
  DEF_SYSCONF_CONST(mrb, klass, SC_2_C_DEV)
#endif
#ifdef _SC_2_FORT_DEV
  DEF_SYSCONF_CONST(mrb, klass, SC_2_FORT_DEV)
#endif
#ifdef _SC_2_FORT_RUN
  DEF_SYSCONF_CONST(mrb, klass, SC_2_FORT_RUN)
#endif
#ifdef _SC_2_SW_DEV
  DEF_SYSCONF_CONST(mrb, klass, SC_2_SW_DEV)
#endif
#ifdef _SC_2_LOCALEDEF
  DEF_SYSCONF_CONST(mrb, klass, SC_2_LOCALEDEF)
#endif
#ifdef _SC_PII
  DEF_SYSCONF_CONST(mrb, klass, SC_PII)
#endif
#ifdef _SC_PII_XTI
  DEF_SYSCONF_CONST(mrb, klass, SC_PII_XTI)
#endif
#ifdef _SC_PII_SOCKET
  DEF_SYSCONF_CONST(mrb, klass, SC_PII_SOCKET)
#endif
#ifdef _SC_PII_INTERNET
  DEF_SYSCONF_CONST(mrb, klass, SC_PII_INTERNET)
#endif
#ifdef _SC_PII_OSI
  DEF_SYSCONF_CONST(mrb, klass, SC_PII_OSI)
#endif
#ifdef _SC_POLL
  DEF_SYSCONF_CONST(mrb, klass, SC_POLL)
#endif
#ifdef _SC_SELECT
  DEF_SYSCONF_CONST(mrb, klass, SC_SELECT)
#endif
#ifdef _SC_UIO_MAXIOV
  DEF_SYSCONF_CONST(mrb, klass, SC_UIO_MAXIOV)
#endif
#ifdef _SC_IOV_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_IOV_MAX)
#endif
#ifdef _SC_PII_INTERNET_STREAM
  DEF_SYSCONF_CONST(mrb, klass, SC_PII_INTERNET_STREAM)
#endif
#ifdef _SC_PII_INTERNET_DGRAM
  DEF_SYSCONF_CONST(mrb, klass, SC_PII_INTERNET_DGRAM)
#endif
#ifdef _SC_PII_OSI_COTS
  DEF_SYSCONF_CONST(mrb, klass, SC_PII_OSI_COTS)
#endif
#ifdef _SC_PII_OSI_CLTS
  DEF_SYSCONF_CONST(mrb, klass, SC_PII_OSI_CLTS)
#endif
#ifdef _SC_PII_OSI_M
  DEF_SYSCONF_CONST(mrb, klass, SC_PII_OSI_M)
#endif
#ifdef _SC_T_IOV_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_T_IOV_MAX)
#endif
#ifdef _SC_THREADS
  DEF_SYSCONF_CONST(mrb, klass, SC_THREADS)
#endif
#ifdef _SC_THREAD_SAFE_FUNCTIONS
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_SAFE_FUNCTIONS)
#endif
#ifdef _SC_GETGR_R_SIZE_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_GETGR_R_SIZE_MAX)
#endif
#ifdef _SC_GETPW_R_SIZE_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_GETPW_R_SIZE_MAX)
#endif
#ifdef _SC_LOGIN_NAME_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_LOGIN_NAME_MAX)
#endif
#ifdef _SC_TTY_NAME_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_TTY_NAME_MAX)
#endif
#ifdef _SC_THREAD_DESTRUCTOR_ITERATIONS
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_DESTRUCTOR_ITERATIONS)
#endif
#ifdef _SC_THREAD_KEYS_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_KEYS_MAX)
#endif
#ifdef _SC_THREAD_STACK_MIN
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_STACK_MIN)
#endif
#ifdef _SC_THREAD_THREADS_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_THREADS_MAX)
#endif
#ifdef _SC_THREAD_ATTR_STACKADDR
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_ATTR_STACKADDR)
#endif
#ifdef _SC_THREAD_ATTR_STACKSIZE
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_ATTR_STACKSIZE)
#endif
#ifdef _SC_THREAD_PRIORITY_SCHEDULING
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_PRIORITY_SCHEDULING)
#endif
#ifdef _SC_THREAD_PRIO_INHERIT
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_PRIO_INHERIT)
#endif
#ifdef _SC_THREAD_PRIO_PROTECT
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_PRIO_PROTECT)
#endif
#ifdef _SC_THREAD_PROCESS_SHARED
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_PROCESS_SHARED)
#endif
#ifdef _SC_NPROCESSORS_CONF
  DEF_SYSCONF_CONST(mrb, klass, SC_NPROCESSORS_CONF)
#endif
#ifdef _SC_NPROCESSORS_ONLN
  DEF_SYSCONF_CONST(mrb, klass, SC_NPROCESSORS_ONLN)
#endif
#ifdef _SC_PHYS_PAGES
  DEF_SYSCONF_CONST(mrb, klass, SC_PHYS_PAGES)
#endif
#ifdef _SC_AVPHYS_PAGES
  DEF_SYSCONF_CONST(mrb, klass, SC_AVPHYS_PAGES)
#endif
#ifdef _SC_ATEXIT_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_ATEXIT_MAX)
#endif
#ifdef _SC_PASS_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_PASS_MAX)
#endif
#ifdef _SC_XOPEN_VERSION
  DEF_SYSCONF_CONST(mrb, klass, SC_XOPEN_VERSION)
#endif
#ifdef _SC_XOPEN_XCU_VERSION
  DEF_SYSCONF_CONST(mrb, klass, SC_XOPEN_XCU_VERSION)
#endif
#ifdef _SC_XOPEN_UNIX
  DEF_SYSCONF_CONST(mrb, klass, SC_XOPEN_UNIX)
#endif
#ifdef _SC_XOPEN_CRYPT
  DEF_SYSCONF_CONST(mrb, klass, SC_XOPEN_CRYPT)
#endif
#ifdef _SC_XOPEN_ENH_I18N
  DEF_SYSCONF_CONST(mrb, klass, SC_XOPEN_ENH_I18N)
#endif
#ifdef _SC_XOPEN_SHM
  DEF_SYSCONF_CONST(mrb, klass, SC_XOPEN_SHM)
#endif
#ifdef _SC_2_CHAR_TERM
  DEF_SYSCONF_CONST(mrb, klass, SC_2_CHAR_TERM)
#endif
#ifdef _SC_2_C_VERSION
  DEF_SYSCONF_CONST(mrb, klass, SC_2_C_VERSION)
#endif
#ifdef _SC_2_UPE
  DEF_SYSCONF_CONST(mrb, klass, SC_2_UPE)
#endif
#ifdef _SC_XOPEN_XPG2
  DEF_SYSCONF_CONST(mrb, klass, SC_XOPEN_XPG2)
#endif
#ifdef _SC_XOPEN_XPG3
  DEF_SYSCONF_CONST(mrb, klass, SC_XOPEN_XPG3)
#endif
#ifdef _SC_XOPEN_XPG4
  DEF_SYSCONF_CONST(mrb, klass, SC_XOPEN_XPG4)
#endif
#ifdef _SC_CHAR_BIT
  DEF_SYSCONF_CONST(mrb, klass, SC_CHAR_BIT)
#endif
#ifdef _SC_CHAR_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_CHAR_MAX)
#endif
#ifdef _SC_CHAR_MIN
  DEF_SYSCONF_CONST(mrb, klass, SC_CHAR_MIN)
#endif
#ifdef _SC_INT_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_INT_MAX)
#endif
#ifdef _SC_INT_MIN
  DEF_SYSCONF_CONST(mrb, klass, SC_INT_MIN)
#endif
#ifdef _SC_LONG_BIT
  DEF_SYSCONF_CONST(mrb, klass, SC_LONG_BIT)
#endif
#ifdef _SC_WORD_BIT
  DEF_SYSCONF_CONST(mrb, klass, SC_WORD_BIT)
#endif
#ifdef _SC_MB_LEN_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_MB_LEN_MAX)
#endif
#ifdef _SC_NZERO
  DEF_SYSCONF_CONST(mrb, klass, SC_NZERO)
#endif
#ifdef _SC_SSIZE_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_SSIZE_MAX)
#endif
#ifdef _SC_SCHAR_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_SCHAR_MAX)
#endif
#ifdef _SC_SCHAR_MIN
  DEF_SYSCONF_CONST(mrb, klass, SC_SCHAR_MIN)
#endif
#ifdef _SC_SHRT_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_SHRT_MAX)
#endif
#ifdef _SC_SHRT_MIN
  DEF_SYSCONF_CONST(mrb, klass, SC_SHRT_MIN)
#endif
#ifdef _SC_UCHAR_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_UCHAR_MAX)
#endif
#ifdef _SC_UINT_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_UINT_MAX)
#endif
#ifdef _SC_ULONG_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_ULONG_MAX)
#endif
#ifdef _SC_USHRT_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_USHRT_MAX)
#endif
#ifdef _SC_NL_ARGMAX
  DEF_SYSCONF_CONST(mrb, klass, SC_NL_ARGMAX)
#endif
#ifdef _SC_NL_LANGMAX
  DEF_SYSCONF_CONST(mrb, klass, SC_NL_LANGMAX)
#endif
#ifdef _SC_NL_MSGMAX
  DEF_SYSCONF_CONST(mrb, klass, SC_NL_MSGMAX)
#endif
#ifdef _SC_NL_NMAX
  DEF_SYSCONF_CONST(mrb, klass, SC_NL_NMAX)
#endif
#ifdef _SC_NL_SETMAX
  DEF_SYSCONF_CONST(mrb, klass, SC_NL_SETMAX)
#endif
#ifdef _SC_NL_TEXTMAX
  DEF_SYSCONF_CONST(mrb, klass, SC_NL_TEXTMAX)
#endif
#ifdef _SC_XBS5_ILP32_OFF32
  DEF_SYSCONF_CONST(mrb, klass, SC_XBS5_ILP32_OFF32)
#endif
#ifdef _SC_XBS5_ILP32_OFFBIG
  DEF_SYSCONF_CONST(mrb, klass, SC_XBS5_ILP32_OFFBIG)
#endif
#ifdef _SC_XBS5_LP64_OFF64
  DEF_SYSCONF_CONST(mrb, klass, SC_XBS5_LP64_OFF64)
#endif
#ifdef _SC_XBS5_LPBIG_OFFBIG
  DEF_SYSCONF_CONST(mrb, klass, SC_XBS5_LPBIG_OFFBIG)
#endif
#ifdef _SC_XOPEN_LEGACY
  DEF_SYSCONF_CONST(mrb, klass, SC_XOPEN_LEGACY)
#endif
#ifdef _SC_XOPEN_REALTIME
  DEF_SYSCONF_CONST(mrb, klass, SC_XOPEN_REALTIME)
#endif
#ifdef _SC_XOPEN_REALTIME_THREADS
  DEF_SYSCONF_CONST(mrb, klass, SC_XOPEN_REALTIME_THREADS)
#endif
#ifdef _SC_ADVISORY_INFO
  DEF_SYSCONF_CONST(mrb, klass, SC_ADVISORY_INFO)
#endif
#ifdef _SC_BARRIERS
  DEF_SYSCONF_CONST(mrb, klass, SC_BARRIERS)
#endif
#ifdef _SC_BASE
  DEF_SYSCONF_CONST(mrb, klass, SC_BASE)
#endif
#ifdef _SC_C_LANG_SUPPORT
  DEF_SYSCONF_CONST(mrb, klass, SC_C_LANG_SUPPORT)
#endif
#ifdef _SC_C_LANG_SUPPORT_R
  DEF_SYSCONF_CONST(mrb, klass, SC_C_LANG_SUPPORT_R)
#endif
#ifdef _SC_CLOCK_SELECTION
  DEF_SYSCONF_CONST(mrb, klass, SC_CLOCK_SELECTION)
#endif
#ifdef _SC_CPUTIME
  DEF_SYSCONF_CONST(mrb, klass, SC_CPUTIME)
#endif
#ifdef _SC_THREAD_CPUTIME
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_CPUTIME)
#endif
#ifdef _SC_DEVICE_IO
  DEF_SYSCONF_CONST(mrb, klass, SC_DEVICE_IO)
#endif
#ifdef _SC_DEVICE_SPECIFIC
  DEF_SYSCONF_CONST(mrb, klass, SC_DEVICE_SPECIFIC)
#endif
#ifdef _SC_DEVICE_SPECIFIC_R
  DEF_SYSCONF_CONST(mrb, klass, SC_DEVICE_SPECIFIC_R)
#endif
#ifdef _SC_FD_MGMT
  DEF_SYSCONF_CONST(mrb, klass, SC_FD_MGMT)
#endif
#ifdef _SC_FIFO
  DEF_SYSCONF_CONST(mrb, klass, SC_FIFO)
#endif
#ifdef _SC_PIPE
  DEF_SYSCONF_CONST(mrb, klass, SC_PIPE)
#endif
#ifdef _SC_FILE_ATTRIBUTES
  DEF_SYSCONF_CONST(mrb, klass, SC_FILE_ATTRIBUTES)
#endif
#ifdef _SC_FILE_LOCKING
  DEF_SYSCONF_CONST(mrb, klass, SC_FILE_LOCKING)
#endif
#ifdef _SC_FILE_SYSTEM
  DEF_SYSCONF_CONST(mrb, klass, SC_FILE_SYSTEM)
#endif
#ifdef _SC_MONOTONIC_CLOCK
  DEF_SYSCONF_CONST(mrb, klass, SC_MONOTONIC_CLOCK)
#endif
#ifdef _SC_MULTI_PROCESS
  DEF_SYSCONF_CONST(mrb, klass, SC_MULTI_PROCESS)
#endif
#ifdef _SC_SINGLE_PROCESS
  DEF_SYSCONF_CONST(mrb, klass, SC_SINGLE_PROCESS)
#endif
#ifdef _SC_NETWORKING
  DEF_SYSCONF_CONST(mrb, klass, SC_NETWORKING)
#endif
#ifdef _SC_READER_WRITER_LOCKS
  DEF_SYSCONF_CONST(mrb, klass, SC_READER_WRITER_LOCKS)
#endif
#ifdef _SC_SPIN_LOCKS
  DEF_SYSCONF_CONST(mrb, klass, SC_SPIN_LOCKS)
#endif
#ifdef _SC_REGEXP
  DEF_SYSCONF_CONST(mrb, klass, SC_REGEXP)
#endif
#ifdef _SC_REGEX_VERSION
  DEF_SYSCONF_CONST(mrb, klass, SC_REGEX_VERSION)
#endif
#ifdef _SC_SHELL
  DEF_SYSCONF_CONST(mrb, klass, SC_SHELL)
#endif
#ifdef _SC_SIGNALS
  DEF_SYSCONF_CONST(mrb, klass, SC_SIGNALS)
#endif
#ifdef _SC_SPAWN
  DEF_SYSCONF_CONST(mrb, klass, SC_SPAWN)
#endif
#ifdef _SC_SPORADIC_SERVER
  DEF_SYSCONF_CONST(mrb, klass, SC_SPORADIC_SERVER)
#endif
#ifdef _SC_THREAD_SPORADIC_SERVER
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_SPORADIC_SERVER)
#endif
#ifdef _SC_SYSTEM_DATABASE
  DEF_SYSCONF_CONST(mrb, klass, SC_SYSTEM_DATABASE)
#endif
#ifdef _SC_SYSTEM_DATABASE_R
  DEF_SYSCONF_CONST(mrb, klass, SC_SYSTEM_DATABASE_R)
#endif
#ifdef _SC_TIMEOUTS
  DEF_SYSCONF_CONST(mrb, klass, SC_TIMEOUTS)
#endif
#ifdef _SC_TYPED_MEMORY_OBJECTS
  DEF_SYSCONF_CONST(mrb, klass, SC_TYPED_MEMORY_OBJECTS)
#endif
#ifdef _SC_USER_GROUPS
  DEF_SYSCONF_CONST(mrb, klass, SC_USER_GROUPS)
#endif
#ifdef _SC_USER_GROUPS_R
  DEF_SYSCONF_CONST(mrb, klass, SC_USER_GROUPS_R)
#endif
#ifdef _SC_2_PBS
  DEF_SYSCONF_CONST(mrb, klass, SC_2_PBS)
#endif
#ifdef _SC_2_PBS_ACCOUNTING
  DEF_SYSCONF_CONST(mrb, klass, SC_2_PBS_ACCOUNTING)
#endif
#ifdef _SC_2_PBS_LOCATE
  DEF_SYSCONF_CONST(mrb, klass, SC_2_PBS_LOCATE)
#endif
#ifdef _SC_2_PBS_MESSAGE
  DEF_SYSCONF_CONST(mrb, klass, SC_2_PBS_MESSAGE)
#endif
#ifdef _SC_2_PBS_TRACK
  DEF_SYSCONF_CONST(mrb, klass, SC_2_PBS_TRACK)
#endif
#ifdef _SC_SYMLOOP_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_SYMLOOP_MAX)
#endif
#ifdef _SC_STREAMS
  DEF_SYSCONF_CONST(mrb, klass, SC_STREAMS)
#endif
#ifdef _SC_2_PBS_CHECKPOINT
  DEF_SYSCONF_CONST(mrb, klass, SC_2_PBS_CHECKPOINT)
#endif
#ifdef _SC_V6_ILP32_OFF32
  DEF_SYSCONF_CONST(mrb, klass, SC_V6_ILP32_OFF32)
#endif
#ifdef _SC_V6_ILP32_OFFBIG
  DEF_SYSCONF_CONST(mrb, klass, SC_V6_ILP32_OFFBIG)
#endif
#ifdef _SC_V6_LP64_OFF64
  DEF_SYSCONF_CONST(mrb, klass, SC_V6_LP64_OFF64)
#endif
#ifdef _SC_V6_LPBIG_OFFBIG
  DEF_SYSCONF_CONST(mrb, klass, SC_V6_LPBIG_OFFBIG)
#endif
#ifdef _SC_HOST_NAME_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_HOST_NAME_MAX)
#endif
#ifdef _SC_TRACE
  DEF_SYSCONF_CONST(mrb, klass, SC_TRACE)
#endif
#ifdef _SC_TRACE_EVENT_FILTER
  DEF_SYSCONF_CONST(mrb, klass, SC_TRACE_EVENT_FILTER)
#endif
#ifdef _SC_TRACE_INHERIT
  DEF_SYSCONF_CONST(mrb, klass, SC_TRACE_INHERIT)
#endif
#ifdef _SC_TRACE_LOG
  DEF_SYSCONF_CONST(mrb, klass, SC_TRACE_LOG)
#endif
#ifdef _SC_LEVEL1_ICACHE_SIZE
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL1_ICACHE_SIZE)
#endif
#ifdef _SC_LEVEL1_ICACHE_ASSOC
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL1_ICACHE_ASSOC)
#endif
#ifdef _SC_LEVEL1_ICACHE_LINESIZE
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL1_ICACHE_LINESIZE)
#endif
#ifdef _SC_LEVEL1_DCACHE_SIZE
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL1_DCACHE_SIZE)
#endif
#ifdef _SC_LEVEL1_DCACHE_ASSOC
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL1_DCACHE_ASSOC)
#endif
#ifdef _SC_LEVEL1_DCACHE_LINESIZE
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL1_DCACHE_LINESIZE)
#endif
#ifdef _SC_LEVEL2_CACHE_SIZE
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL2_CACHE_SIZE)
#endif
#ifdef _SC_LEVEL2_CACHE_ASSOC
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL2_CACHE_ASSOC)
#endif
#ifdef _SC_LEVEL2_CACHE_LINESIZE
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL2_CACHE_LINESIZE)
#endif
#ifdef _SC_LEVEL3_CACHE_SIZE
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL3_CACHE_SIZE)
#endif
#ifdef _SC_LEVEL3_CACHE_ASSOC
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL3_CACHE_ASSOC)
#endif
#ifdef _SC_LEVEL3_CACHE_LINESIZE
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL3_CACHE_LINESIZE)
#endif
#ifdef _SC_LEVEL4_CACHE_SIZE
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL4_CACHE_SIZE)
#endif
#ifdef _SC_LEVEL4_CACHE_ASSOC
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL4_CACHE_ASSOC)
#endif
#ifdef _SC_LEVEL4_CACHE_LINESIZE
  DEF_SYSCONF_CONST(mrb, klass, SC_LEVEL4_CACHE_LINESIZE)
#endif
#ifdef _SC_IPV6
  DEF_SYSCONF_CONST(mrb, klass, SC_IPV6)
#endif
#ifdef _SC_RAW_SOCKETS
  DEF_SYSCONF_CONST(mrb, klass, SC_RAW_SOCKETS)
#endif
#ifdef _SC_V7_ILP32_OFF32
  DEF_SYSCONF_CONST(mrb, klass, SC_V7_ILP32_OFF32)
#endif
#ifdef _SC_V7_ILP32_OFFBIG
  DEF_SYSCONF_CONST(mrb, klass, SC_V7_ILP32_OFFBIG)
#endif
#ifdef _SC_V7_LP64_OFF64
  DEF_SYSCONF_CONST(mrb, klass, SC_V7_LP64_OFF64)
#endif
#ifdef _SC_V7_LPBIG_OFFBIG
  DEF_SYSCONF_CONST(mrb, klass, SC_V7_LPBIG_OFFBIG)
#endif
#ifdef _SC_SS_REPL_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_SS_REPL_MAX)
#endif
#ifdef _SC_TRACE_EVENT_NAME_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_TRACE_EVENT_NAME_MAX)
#endif
#ifdef _SC_TRACE_NAME_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_TRACE_NAME_MAX)
#endif
#ifdef _SC_TRACE_SYS_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_TRACE_SYS_MAX)
#endif
#ifdef _SC_TRACE_USER_EVENT_MAX
  DEF_SYSCONF_CONST(mrb, klass, SC_TRACE_USER_EVENT_MAX)
#endif
#ifdef _SC_XOPEN_STREAMS
  DEF_SYSCONF_CONST(mrb, klass, SC_XOPEN_STREAMS)
#endif
#ifdef _SC_THREAD_ROBUST_PRIO_INHERIT
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_ROBUST_PRIO_INHERIT)
#endif
#ifdef _SC_THREAD_ROBUST_PRIO_PROTECT
  DEF_SYSCONF_CONST(mrb, klass, SC_THREAD_ROBUST_PRIO_PROTECT)
#endif
  DONE;
}

void mrb_mruby_sysconf_gem_final(mrb_state *mrb)
{
}
