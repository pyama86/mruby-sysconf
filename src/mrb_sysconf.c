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

static const struct conf {
  const char *nm;
  long no;
} sysconflist[] = {
#ifdef _SC_ARG_MAX
    {"_SC_ARG_MAX", 0},
#endif
#ifdef _SC_CHILD_MAX
    {"_SC_CHILD_MAX", 1},
#endif
#ifdef _SC_CLK_TCK
    {"_SC_CLK_TCK", 2},
#endif
#ifdef _SC_NGROUPS_MAX
    {"_SC_NGROUPS_MAX", 3},
#endif
#ifdef _SC_OPEN_MAX
    {"_SC_OPEN_MAX", 4},
#endif
#ifdef _SC_STREAM_MAX
    {"_SC_STREAM_MAX", 5},
#endif
#ifdef _SC_TZNAME_MAX
    {"_SC_TZNAME_MAX", 6},
#endif
#ifdef _SC_JOB_CONTROL
    {"_SC_JOB_CONTROL", 7},
#endif
#ifdef _SC_SAVED_IDS
    {"_SC_SAVED_IDS", 8},
#endif
#ifdef _SC_REALTIME_SIGNALS
    {"_SC_REALTIME_SIGNALS", 9},
#endif
#ifdef _SC_PRIORITY_SCHEDULING
    {"_SC_PRIORITY_SCHEDULING", 10},
#endif
#ifdef _SC_TIMERS
    {"_SC_TIMERS", 11},
#endif
#ifdef _SC_ASYNCHRONOUS_IO
    {"_SC_ASYNCHRONOUS_IO", 12},
#endif
#ifdef _SC_PRIORITIZED_IO
    {"_SC_PRIORITIZED_IO", 13},
#endif
#ifdef _SC_SYNCHRONIZED_IO
    {"_SC_SYNCHRONIZED_IO", 14},
#endif
#ifdef _SC_FSYNC
    {"_SC_FSYNC", 15},
#endif
#ifdef _SC_MAPPED_FILES
    {"_SC_MAPPED_FILES", 16},
#endif
#ifdef _SC_MEMLOCK
    {"_SC_MEMLOCK", 17},
#endif
#ifdef _SC_MEMLOCK_RANGE
    {"_SC_MEMLOCK_RANGE", 18},
#endif
#ifdef _SC_MEMORY_PROTECTION
    {"_SC_MEMORY_PROTECTION", 19},
#endif
#ifdef _SC_MESSAGE_PASSING
    {"_SC_MESSAGE_PASSING", 20},
#endif
#ifdef _SC_SEMAPHORES
    {"_SC_SEMAPHORES", 21},
#endif
#ifdef _SC_SHARED_MEMORY_OBJECTS
    {"_SC_SHARED_MEMORY_OBJECTS", 22},
#endif
#ifdef _SC_AIO_LISTIO_MAX
    {"_SC_AIO_LISTIO_MAX", 23},
#endif
#ifdef _SC_AIO_MAX
    {"_SC_AIO_MAX", 24},
#endif
#ifdef _SC_AIO_PRIO_DELTA_MAX
    {"_SC_AIO_PRIO_DELTA_MAX", 25},
#endif
#ifdef _SC_DELAYTIMER_MAX
    {"_SC_DELAYTIMER_MAX", 26},
#endif
#ifdef _SC_MQ_OPEN_MAX
    {"_SC_MQ_OPEN_MAX", 27},
#endif
#ifdef _SC_MQ_PRIO_MAX
    {"_SC_MQ_PRIO_MAX", 28},
#endif
#ifdef _SC_VERSION
    {"_SC_VERSION", 29},
#endif
#ifdef _SC_PAGESIZE
    {"_SC_PAGESIZE", 30},
#endif
#ifdef _SC_RTSIG_MAX
    {"_SC_RTSIG_MAX", 31},
#endif
#ifdef _SC_SEM_NSEMS_MAX
    {"_SC_SEM_NSEMS_MAX", 32},
#endif
#ifdef _SC_SEM_VALUE_MAX
    {"_SC_SEM_VALUE_MAX", 33},
#endif
#ifdef _SC_SIGQUEUE_MAX
    {"_SC_SIGQUEUE_MAX", 34},
#endif
#ifdef _SC_TIMER_MAX
    {"_SC_TIMER_MAX", 35},
#endif
#ifdef _SC_BC_BASE_MAX
    {"_SC_BC_BASE_MAX", 36},
#endif
#ifdef _SC_BC_DIM_MAX
    {"_SC_BC_DIM_MAX", 37},
#endif
#ifdef _SC_BC_SCALE_MAX
    {"_SC_BC_SCALE_MAX", 38},
#endif
#ifdef _SC_BC_STRING_MAX
    {"_SC_BC_STRING_MAX", 39},
#endif
#ifdef _SC_COLL_WEIGHTS_MAX
    {"_SC_COLL_WEIGHTS_MAX", 40},
#endif
#ifdef _SC_EQUIV_CLASS_MAX
    {"_SC_EQUIV_CLASS_MAX", 41},
#endif
#ifdef _SC_EXPR_NEST_MAX
    {"_SC_EXPR_NEST_MAX", 42},
#endif
#ifdef _SC_LINE_MAX
    {"_SC_LINE_MAX", 43},
#endif
#ifdef _SC_RE_DUP_MAX
    {"_SC_RE_DUP_MAX", 44},
#endif
#ifdef _SC_CHARCLASS_NAME_MAX
    {"_SC_CHARCLASS_NAME_MAX", 45},
#endif
#ifdef _SC_2_VERSION
    {"_SC_2_VERSION", 46},
#endif
#ifdef _SC_2_C_BIND
    {"_SC_2_C_BIND", 47},
#endif
#ifdef _SC_2_C_DEV
    {"_SC_2_C_DEV", 48},
#endif
#ifdef _SC_2_FORT_DEV
    {"_SC_2_FORT_DEV", 49},
#endif
#ifdef _SC_2_FORT_RUN
    {"_SC_2_FORT_RUN", 50},
#endif
#ifdef _SC_2_SW_DEV
    {"_SC_2_SW_DEV", 51},
#endif
#ifdef _SC_2_LOCALEDEF
    {"_SC_2_LOCALEDEF", 52},
#endif
#ifdef _SC_PII
    {"_SC_PII", 53},
#endif
#ifdef _SC_PII_XTI
    {"_SC_PII_XTI", 54},
#endif
#ifdef _SC_PII_SOCKET
    {"_SC_PII_SOCKET", 55},
#endif
#ifdef _SC_PII_INTERNET
    {"_SC_PII_INTERNET", 56},
#endif
#ifdef _SC_PII_OSI
    {"_SC_PII_OSI", 57},
#endif
#ifdef _SC_POLL
    {"_SC_POLL", 58},
#endif
#ifdef _SC_SELECT
    {"_SC_SELECT", 59},
#endif
#ifdef _SC_UIO_MAXIOV
    {"_SC_UIO_MAXIOV", 60},
#endif
#ifdef _SC_IOV_MAX
    {"_SC_IOV_MAX", 60},
#endif
#ifdef _SC_PII_INTERNET_STREAM
    {"_SC_PII_INTERNET_STREAM", 62},
#endif
#ifdef _SC_PII_INTERNET_DGRAM
    {"_SC_PII_INTERNET_DGRAM", 63},
#endif
#ifdef _SC_PII_OSI_COTS
    {"_SC_PII_OSI_COTS", 64},
#endif
#ifdef _SC_PII_OSI_CLTS
    {"_SC_PII_OSI_CLTS", 65},
#endif
#ifdef _SC_PII_OSI_M
    {"_SC_PII_OSI_M", 66},
#endif
#ifdef _SC_T_IOV_MAX
    {"_SC_T_IOV_MAX", 67},
#endif
#ifdef _SC_THREADS
    {"_SC_THREADS", 68},
#endif
#ifdef _SC_THREAD_SAFE_FUNCTIONS
    {"_SC_THREAD_SAFE_FUNCTIONS", 69},
#endif
#ifdef _SC_GETGR_R_SIZE_MAX
    {"_SC_GETGR_R_SIZE_MAX", 70},
#endif
#ifdef _SC_GETPW_R_SIZE_MAX
    {"_SC_GETPW_R_SIZE_MAX", 71},
#endif
#ifdef _SC_LOGIN_NAME_MAX
    {"_SC_LOGIN_NAME_MAX", 72},
#endif
#ifdef _SC_TTY_NAME_MAX
    {"_SC_TTY_NAME_MAX", 73},
#endif
#ifdef _SC_THREAD_DESTRUCTOR_ITERATIONS
    {"_SC_THREAD_DESTRUCTOR_ITERATIONS", 74},
#endif
#ifdef _SC_THREAD_KEYS_MAX
    {"_SC_THREAD_KEYS_MAX", 75},
#endif
#ifdef _SC_THREAD_STACK_MIN
    {"_SC_THREAD_STACK_MIN", 76},
#endif
#ifdef _SC_THREAD_THREADS_MAX
    {"_SC_THREAD_THREADS_MAX", 77},
#endif
#ifdef _SC_THREAD_ATTR_STACKADDR
    {"_SC_THREAD_ATTR_STACKADDR", 78},
#endif
#ifdef _SC_THREAD_ATTR_STACKSIZE
    {"_SC_THREAD_ATTR_STACKSIZE", 79},
#endif
#ifdef _SC_THREAD_PRIORITY_SCHEDULING
    {"_SC_THREAD_PRIORITY_SCHEDULING", 80},
#endif
#ifdef _SC_THREAD_PRIO_INHERIT
    {"_SC_THREAD_PRIO_INHERIT", 81},
#endif
#ifdef _SC_THREAD_PRIO_PROTECT
    {"_SC_THREAD_PRIO_PROTECT", 82},
#endif
#ifdef _SC_THREAD_PROCESS_SHARED
    {"_SC_THREAD_PROCESS_SHARED", 83},
#endif
#ifdef _SC_NPROCESSORS_CONF
    {"_SC_NPROCESSORS_CONF", 84},
#endif
#ifdef _SC_NPROCESSORS_ONLN
    {"_SC_NPROCESSORS_ONLN", 85},
#endif
#ifdef _SC_PHYS_PAGES
    {"_SC_PHYS_PAGES", 86},
#endif
#ifdef _SC_AVPHYS_PAGES
    {"_SC_AVPHYS_PAGES", 87},
#endif
#ifdef _SC_ATEXIT_MAX
    {"_SC_ATEXIT_MAX", 88},
#endif
#ifdef _SC_PASS_MAX
    {"_SC_PASS_MAX", 89},
#endif
#ifdef _SC_XOPEN_VERSION
    {"_SC_XOPEN_VERSION", 90},
#endif
#ifdef _SC_XOPEN_XCU_VERSION
    {"_SC_XOPEN_XCU_VERSION", 91},
#endif
#ifdef _SC_XOPEN_UNIX
    {"_SC_XOPEN_UNIX", 92},
#endif
#ifdef _SC_XOPEN_CRYPT
    {"_SC_XOPEN_CRYPT", 93},
#endif
#ifdef _SC_XOPEN_ENH_I18N
    {"_SC_XOPEN_ENH_I18N", 94},
#endif
#ifdef _SC_XOPEN_SHM
    {"_SC_XOPEN_SHM", 95},
#endif
#ifdef _SC_2_CHAR_TERM
    {"_SC_2_CHAR_TERM", 96},
#endif
#ifdef _SC_2_C_VERSION
    {"_SC_2_C_VERSION", 97},
#endif
#ifdef _SC_2_UPE
    {"_SC_2_UPE", 98},
#endif
#ifdef _SC_XOPEN_XPG2
    {"_SC_XOPEN_XPG2", 99},
#endif
#ifdef _SC_XOPEN_XPG3
    {"_SC_XOPEN_XPG3", 100},
#endif
#ifdef _SC_XOPEN_XPG4
    {"_SC_XOPEN_XPG4", 101},
#endif
#ifdef _SC_CHAR_BIT
    {"_SC_CHAR_BIT", 102},
#endif
#ifdef _SC_CHAR_MAX
    {"_SC_CHAR_MAX", 103},
#endif
#ifdef _SC_CHAR_MIN
    {"_SC_CHAR_MIN", 104},
#endif
#ifdef _SC_INT_MAX
    {"_SC_INT_MAX", 105},
#endif
#ifdef _SC_INT_MIN
    {"_SC_INT_MIN", 106},
#endif
#ifdef _SC_LONG_BIT
    {"_SC_LONG_BIT", 107},
#endif
#ifdef _SC_WORD_BIT
    {"_SC_WORD_BIT", 108},
#endif
#ifdef _SC_MB_LEN_MAX
    {"_SC_MB_LEN_MAX", 109},
#endif
#ifdef _SC_NZERO
    {"_SC_NZERO", 110},
#endif
#ifdef _SC_SSIZE_MAX
    {"_SC_SSIZE_MAX", 111},
#endif
#ifdef _SC_SCHAR_MAX
    {"_SC_SCHAR_MAX", 112},
#endif
#ifdef _SC_SCHAR_MIN
    {"_SC_SCHAR_MIN", 113},
#endif
#ifdef _SC_SHRT_MAX
    {"_SC_SHRT_MAX", 114},
#endif
#ifdef _SC_SHRT_MIN
    {"_SC_SHRT_MIN", 115},
#endif
#ifdef _SC_UCHAR_MAX
    {"_SC_UCHAR_MAX", 116},
#endif
#ifdef _SC_UINT_MAX
    {"_SC_UINT_MAX", 117},
#endif
#ifdef _SC_ULONG_MAX
    {"_SC_ULONG_MAX", 118},
#endif
#ifdef _SC_USHRT_MAX
    {"_SC_USHRT_MAX", 119},
#endif
#ifdef _SC_NL_ARGMAX
    {"_SC_NL_ARGMAX", 120},
#endif
#ifdef _SC_NL_LANGMAX
    {"_SC_NL_LANGMAX", 121},
#endif
#ifdef _SC_NL_MSGMAX
    {"_SC_NL_MSGMAX", 122},
#endif
#ifdef _SC_NL_NMAX
    {"_SC_NL_NMAX", 123},
#endif
#ifdef _SC_NL_SETMAX
    {"_SC_NL_SETMAX", 124},
#endif
#ifdef _SC_NL_TEXTMAX
    {"_SC_NL_TEXTMAX", 125},
#endif
#ifdef _SC_XBS5_ILP32_OFF32
    {"_SC_XBS5_ILP32_OFF32", 126},
#endif
#ifdef _SC_XBS5_ILP32_OFFBIG
    {"_SC_XBS5_ILP32_OFFBIG", 127},
#endif
#ifdef _SC_XBS5_LP64_OFF64
    {"_SC_XBS5_LP64_OFF64", 128},
#endif
#ifdef _SC_XBS5_LPBIG_OFFBIG
    {"_SC_XBS5_LPBIG_OFFBIG", 129},
#endif
#ifdef _SC_XOPEN_LEGACY
    {"_SC_XOPEN_LEGACY", 130},
#endif
#ifdef _SC_XOPEN_REALTIME
    {"_SC_XOPEN_REALTIME", 131},
#endif
#ifdef _SC_XOPEN_REALTIME_THREADS
    {"_SC_XOPEN_REALTIME_THREADS", 132},
#endif
#ifdef _SC_ADVISORY_INFO
    {"_SC_ADVISORY_INFO", 133},
#endif
#ifdef _SC_BARRIERS
    {"_SC_BARRIERS", 134},
#endif
#ifdef _SC_BASE
    {"_SC_BASE", 135},
#endif
#ifdef _SC_C_LANG_SUPPORT
    {"_SC_C_LANG_SUPPORT", 136},
#endif
#ifdef _SC_C_LANG_SUPPORT_R
    {"_SC_C_LANG_SUPPORT_R", 137},
#endif
#ifdef _SC_CLOCK_SELECTION
    {"_SC_CLOCK_SELECTION", 138},
#endif
#ifdef _SC_CPUTIME
    {"_SC_CPUTIME", 139},
#endif
#ifdef _SC_THREAD_CPUTIME
    {"_SC_THREAD_CPUTIME", 140},
#endif
#ifdef _SC_DEVICE_IO
    {"_SC_DEVICE_IO", 141},
#endif
#ifdef _SC_DEVICE_SPECIFIC
    {"_SC_DEVICE_SPECIFIC", 142},
#endif
#ifdef _SC_DEVICE_SPECIFIC_R
    {"_SC_DEVICE_SPECIFIC_R", 143},
#endif
#ifdef _SC_FD_MGMT
    {"_SC_FD_MGMT", 144},
#endif
#ifdef _SC_FIFO
    {"_SC_FIFO", 145},
#endif
#ifdef _SC_PIPE
    {"_SC_PIPE", 146},
#endif
#ifdef _SC_FILE_ATTRIBUTES
    {"_SC_FILE_ATTRIBUTES", 147},
#endif
#ifdef _SC_FILE_LOCKING
    {"_SC_FILE_LOCKING", 148},
#endif
#ifdef _SC_FILE_SYSTEM
    {"_SC_FILE_SYSTEM", 149},
#endif
#ifdef _SC_MONOTONIC_CLOCK
    {"_SC_MONOTONIC_CLOCK", 150},
#endif
#ifdef _SC_MULTI_PROCESS
    {"_SC_MULTI_PROCESS", 151},
#endif
#ifdef _SC_SINGLE_PROCESS
    {"_SC_SINGLE_PROCESS", 152},
#endif
#ifdef _SC_NETWORKING
    {"_SC_NETWORKING", 153},
#endif
#ifdef _SC_READER_WRITER_LOCKS
    {"_SC_READER_WRITER_LOCKS", 154},
#endif
#ifdef _SC_SPIN_LOCKS
    {"_SC_SPIN_LOCKS", 155},
#endif
#ifdef _SC_REGEXP
    {"_SC_REGEXP", 156},
#endif
#ifdef _SC_REGEX_VERSION
    {"_SC_REGEX_VERSION", 157},
#endif
#ifdef _SC_SHELL
    {"_SC_SHELL", 158},
#endif
#ifdef _SC_SIGNALS
    {"_SC_SIGNALS", 159},
#endif
#ifdef _SC_SPAWN
    {"_SC_SPAWN", 160},
#endif
#ifdef _SC_SPORADIC_SERVER
    {"_SC_SPORADIC_SERVER", 161},
#endif
#ifdef _SC_THREAD_SPORADIC_SERVER
    {"_SC_THREAD_SPORADIC_SERVER", 162},
#endif
#ifdef _SC_SYSTEM_DATABASE
    {"_SC_SYSTEM_DATABASE", 163},
#endif
#ifdef _SC_SYSTEM_DATABASE_R
    {"_SC_SYSTEM_DATABASE_R", 164},
#endif
#ifdef _SC_TIMEOUTS
    {"_SC_TIMEOUTS", 165},
#endif
#ifdef _SC_TYPED_MEMORY_OBJECTS
    {"_SC_TYPED_MEMORY_OBJECTS", 166},
#endif
#ifdef _SC_USER_GROUPS
    {"_SC_USER_GROUPS", 167},
#endif
#ifdef _SC_USER_GROUPS_R
    {"_SC_USER_GROUPS_R", 168},
#endif
#ifdef _SC_2_PBS
    {"_SC_2_PBS", 169},
#endif
#ifdef _SC_2_PBS_ACCOUNTING
    {"_SC_2_PBS_ACCOUNTING", 170},
#endif
#ifdef _SC_2_PBS_LOCATE
    {"_SC_2_PBS_LOCATE", 171},
#endif
#ifdef _SC_2_PBS_MESSAGE
    {"_SC_2_PBS_MESSAGE", 172},
#endif
#ifdef _SC_2_PBS_TRACK
    {"_SC_2_PBS_TRACK", 173},
#endif
#ifdef _SC_SYMLOOP_MAX
    {"_SC_SYMLOOP_MAX", 174},
#endif
#ifdef _SC_STREAMS
    {"_SC_STREAMS", 175},
#endif
#ifdef _SC_2_PBS_CHECKPOINT
    {"_SC_2_PBS_CHECKPOINT", 176},
#endif
#ifdef _SC_V6_ILP32_OFF32
    {"_SC_V6_ILP32_OFF32", 177},
#endif
#ifdef _SC_V6_ILP32_OFFBIG
    {"_SC_V6_ILP32_OFFBIG", 178},
#endif
#ifdef _SC_V6_LP64_OFF64
    {"_SC_V6_LP64_OFF64", 179},
#endif
#ifdef _SC_V6_LPBIG_OFFBIG
    {"_SC_V6_LPBIG_OFFBIG", 180},
#endif
#ifdef _SC_HOST_NAME_MAX
    {"_SC_HOST_NAME_MAX", 181},
#endif
#ifdef _SC_TRACE
    {"_SC_TRACE", 182},
#endif
#ifdef _SC_TRACE_EVENT_FILTER
    {"_SC_TRACE_EVENT_FILTER", 183},
#endif
#ifdef _SC_TRACE_INHERIT
    {"_SC_TRACE_INHERIT", 184},
#endif
#ifdef _SC_TRACE_LOG
    {"_SC_TRACE_LOG", 185},
#endif
#ifdef _SC_LEVEL1_ICACHE_SIZE
    {"_SC_LEVEL1_ICACHE_SIZE", 186},
#endif
#ifdef _SC_LEVEL1_ICACHE_ASSOC
    {"_SC_LEVEL1_ICACHE_ASSOC", 187},
#endif
#ifdef _SC_LEVEL1_ICACHE_LINESIZE
    {"_SC_LEVEL1_ICACHE_LINESIZE", 188},
#endif
#ifdef _SC_LEVEL1_DCACHE_SIZE
    {"_SC_LEVEL1_DCACHE_SIZE", 189},
#endif
#ifdef _SC_LEVEL1_DCACHE_ASSOC
    {"_SC_LEVEL1_DCACHE_ASSOC", 190},
#endif
#ifdef _SC_LEVEL1_DCACHE_LINESIZE
    {"_SC_LEVEL1_DCACHE_LINESIZE", 191},
#endif
#ifdef _SC_LEVEL2_CACHE_SIZE
    {"_SC_LEVEL2_CACHE_SIZE", 192},
#endif
#ifdef _SC_LEVEL2_CACHE_ASSOC
    {"_SC_LEVEL2_CACHE_ASSOC", 193},
#endif
#ifdef _SC_LEVEL2_CACHE_LINESIZE
    {"_SC_LEVEL2_CACHE_LINESIZE", 194},
#endif
#ifdef _SC_LEVEL3_CACHE_SIZE
    {"_SC_LEVEL3_CACHE_SIZE", 195},
#endif
#ifdef _SC_LEVEL3_CACHE_ASSOC
    {"_SC_LEVEL3_CACHE_ASSOC", 196},
#endif
#ifdef _SC_LEVEL3_CACHE_LINESIZE
    {"_SC_LEVEL3_CACHE_LINESIZE", 197},
#endif
#ifdef _SC_LEVEL4_CACHE_SIZE
    {"_SC_LEVEL4_CACHE_SIZE", 198},
#endif
#ifdef _SC_LEVEL4_CACHE_ASSOC
    {"_SC_LEVEL4_CACHE_ASSOC", 199},
#endif
#ifdef _SC_LEVEL4_CACHE_LINESIZE
    {"_SC_LEVEL4_CACHE_LINESIZE", 200},
#endif
#ifdef _SC_IPV6
    {"_SC_IPV6", _SC_LEVEL1_ICACHE_SIZE + 50},
#endif
#ifdef _SC_RAW_SOCKETS
    {"_SC_RAW_SOCKETS", 202},
#endif
#ifdef _SC_V7_ILP32_OFF32
    {"_SC_V7_ILP32_OFF32", 203},
#endif
#ifdef _SC_V7_ILP32_OFFBIG
    {"_SC_V7_ILP32_OFFBIG", 204},
#endif
#ifdef _SC_V7_LP64_OFF64
    {"_SC_V7_LP64_OFF64", 205},
#endif
#ifdef _SC_V7_LPBIG_OFFBIG
    {"_SC_V7_LPBIG_OFFBIG", 206},
#endif
#ifdef _SC_SS_REPL_MAX
    {"_SC_SS_REPL_MAX", 207},
#endif
#ifdef _SC_TRACE_EVENT_NAME_MAX
    {"_SC_TRACE_EVENT_NAME_MAX", 208},
#endif
#ifdef _SC_TRACE_NAME_MAX
    {"_SC_TRACE_NAME_MAX", 209},
#endif
#ifdef _SC_TRACE_SYS_MAX
    {"_SC_TRACE_SYS_MAX", 210},
#endif
#ifdef _SC_TRACE_USER_EVENT_MAX
    {"_SC_TRACE_USER_EVENT_MAX", 211},
#endif
#ifdef _SC_XOPEN_STREAMS
    {"_SC_XOPEN_STREAMS", 212},
#endif
#ifdef _SC_THREAD_ROBUST_PRIO_INHERIT
    {"_SC_THREAD_ROBUST_PRIO_INHERIT", 213},
#endif
#ifdef _SC_THREAD_ROBUST_PRIO_PROTECT
    {"_SC_THREAD_ROBUST_PRIO_PROTECT", 214},
#endif
};
static int confnm2confno(const char *nm)
{
  const struct conf *confs;
  int size = sizeof(sysconflist) / sizeof(*confs) - 1;
  int cnt = 0;

  for (confs = sysconflist; confs->nm; confs++) {
    if (strcmp(confs->nm, nm) == 0)
      return confs->no;
    cnt++;
    if (size == cnt)
      break;
  }
  return -1;
}
static mrb_value mrb_sysconf_get(mrb_state *mrb, mrb_value self)
{
  mrb_value name;
  long value;

  mrb_get_args(mrb, "S", &name);
  value = sysconf(confnm2confno(RSTRING_PTR(name)));

  if (value == -1)
    mrb_raise(mrb, E_ARGUMENT_ERROR, NULL);

  return mrb_fixnum_value(value);
}

void mrb_mruby_sysconf_gem_init(mrb_state *mrb)
{
  struct RClass *sysconf;
  sysconf = mrb_define_class(mrb, "Sysconf", mrb->object_class);
  mrb_define_class_method(mrb, sysconf, "get", mrb_sysconf_get, MRB_ARGS_REQ(1));
  DONE;
}

void mrb_mruby_sysconf_gem_final(mrb_state *mrb)
{
}
