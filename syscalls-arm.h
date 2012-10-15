/*
 * derived from linux/arch/arm/kernel/calls.S
 */

#include "trinity.h"
#include "sanitise.h"
#include "syscall.h"
#include "syscalls/syscalls.h"

#define NR_ARM_SYSCALLS 379

struct syscalltable syscalls_arm[NR_ARM_SYSCALLS + 1] = {

/* 0 */		{ .entry = &syscall_restart_syscall },
		{ .entry = &syscall_exit },
		{ .entry = &syscall_fork },
		{ .entry = &syscall_read },
		{ .entry = &syscall_write },
/* 5 */		{ .entry = &syscall_open },
		{ .entry = &syscall_close },
		{ .entry = &syscall_ni_syscall },		/* was sys_waitpid */
		{ .entry = &syscall_creat },
		{ .entry = &syscall_link },
/* 10 */	{ .entry = &syscall_unlink },
		{ .entry = &syscall_execve },
		{ .entry = &syscall_chdir },
		{ .entry = &syscall_time },	/* used by libc4 */
		{ .entry = &syscall_mknod },
/* 15 */	{ .entry = &syscall_chmod },
		{ .entry = &syscall_lchown16 },
		{ .entry = &syscall_ni_syscall },		/* was sys_break */
		{ .entry = &syscall_ni_syscall },		/* was sys_stat */
		{ .entry = &syscall_lseek },
/* 20 */	{ .entry = &syscall_getpid },
		{ .entry = &syscall_mount },
		{ .entry = &syscall_oldumount },	/* used by libc4 */
		{ .entry = &syscall_setuid16 },
		{ .entry = &syscall_getuid16 },
/* 25 */	{ .entry = &syscall_stime },
		{ .entry = &syscall_ptrace },
		{ .entry = &syscall_alarm },	/* used by libc4 */
		{ .entry = &syscall_ni_syscall },		/* was sys_fstat */
		{ .entry = &syscall_pause },
/* 30 */	{ .entry = &syscall_utime },	/* used by libc4 */
		{ .entry = &syscall_ni_syscall },		/* was sys_stty */
		{ .entry = &syscall_ni_syscall },		/* was sys_getty */
		{ .entry = &syscall_access },
		{ .entry = &syscall_nice },
/* 35 */	{ .entry = &syscall_ni_syscall },		/* was sys_ftime */
		{ .entry = &syscall_sync },
		{ .entry = &syscall_kill },
		{ .entry = &syscall_rename },
		{ .entry = &syscall_mkdir },
/* 40 */	{ .entry = &syscall_rmdir },
		{ .entry = &syscall_dup },
		{ .entry = &syscall_pipe },
		{ .entry = &syscall_times },
		{ .entry = &syscall_ni_syscall },		/* was sys_prof */
/* 45 */	{ .entry = &syscall_brk },
		{ .entry = &syscall_setgid16 },
		{ .entry = &syscall_getgid16 },
		{ .entry = &syscall_ni_syscall },		/* was sys_signal */
		{ .entry = &syscall_geteuid16 },
/* 50 */	{ .entry = &syscall_getegid16 },
		{ .entry = &syscall_acct },
		{ .entry = &syscall_umount },
		{ .entry = &syscall_ni_syscall },		/* was sys_lock */
		{ .entry = &syscall_ioctl },
/* 55 */	{ .entry = &syscall_fcntl },
		{ .entry = &syscall_ni_syscall },		/* was sys_mpx */
		{ .entry = &syscall_setpgid },
		{ .entry = &syscall_ni_syscall },		/* was sys_ulimit */
		{ .entry = &syscall_ni_syscall },		/* was sys_olduname */
/* 60 */	{ .entry = &syscall_umask },
		{ .entry = &syscall_chroot },
		{ .entry = &syscall_ustat },
		{ .entry = &syscall_dup2 },
		{ .entry = &syscall_getppid },
/* 65 */	{ .entry = &syscall_getpgrp },
		{ .entry = &syscall_setsid },
		{ .entry = &syscall_sigaction },
		{ .entry = &syscall_ni_syscall },		/* was sys_sgetmask */
		{ .entry = &syscall_ni_syscall },		/* was sys_ssetmask */
/* 70 */	{ .entry = &syscall_setreuid16 },
		{ .entry = &syscall_setregid16 },
		{ .entry = &syscall_sigsuspend },
		{ .entry = &syscall_sigpending },
		{ .entry = &syscall_sethostname },
/* 75 */	{ .entry = &syscall_setrlimit },
		{ .entry = &syscall_ni_syscall }, /*{ .entry = &syscall_old_getrlimit },*/ /* used by libc4 */
		{ .entry = &syscall_getrusage },
		{ .entry = &syscall_gettimeofday },
		{ .entry = &syscall_settimeofday },
/* 80 */	{ .entry = &syscall_getgroups16 },
		{ .entry = &syscall_setgroups16 },
		{ .entry = &syscall_ni_syscall }, /*{ .entry = &syscall_old_select },*/	/* used by libc4 */
		{ .entry = &syscall_symlink },
		{ .entry = &syscall_ni_syscall },		/* was sys_lstat */
/* 85 */	{ .entry = &syscall_readlink },
		{ .entry = &syscall_uselib },
		{ .entry = &syscall_swapon },
		{ .entry = &syscall_reboot },
		{ .entry = &syscall_ni_syscall }, /*{ .entry = &syscall_old_readdir },*/	/* used by libc4 */
/* 90 */	{ .entry = &syscall_ni_syscall }, /*{ .entry = &syscall_old_mmap },*/	/* used by libc4 */
		{ .entry = &syscall_munmap },
		{ .entry = &syscall_truncate },
		{ .entry = &syscall_ftruncate },
		{ .entry = &syscall_fchmod },
/* 95 */	{ .entry = &syscall_fchown16 },
		{ .entry = &syscall_getpriority },
		{ .entry = &syscall_setpriority },
		{ .entry = &syscall_ni_syscall },		/* was sys_profil */
		{ .entry = &syscall_statfs },
/* 100 */	{ .entry = &syscall_fstatfs },
		{ .entry = &syscall_ni_syscall },		/* sys_ioperm */
		{ .entry = &syscall_socketcall },
		{ .entry = &syscall_syslog },
		{ .entry = &syscall_setitimer },
/* 105 */	{ .entry = &syscall_getitimer },
		{ .entry = &syscall_newstat },
		{ .entry = &syscall_newlstat },
		{ .entry = &syscall_newfstat },
		{ .entry = &syscall_ni_syscall },		/* was sys_uname */
/* 110 */	{ .entry = &syscall_ni_syscall },		/* was sys_iopl */
		{ .entry = &syscall_vhangup },
		{ .entry = &syscall_ni_syscall },
		{ .entry = &syscall_ni_syscall }, /*{ .entry = &syscall_syscall },*/	/* call a syscall */
		{ .entry = &syscall_wait4 },
/* 115 */	{ .entry = &syscall_swapoff },
		{ .entry = &syscall_sysinfo },
		{ .entry = &syscall_ipc },
		{ .entry = &syscall_fsync },
		{ .entry = &syscall_sigreturn },
/* 120 */	{ .entry = &syscall_clone },
		{ .entry = &syscall_setdomainname },
		{ .entry = &syscall_newuname },
		{ .entry = &syscall_ni_syscall },		/* modify_ldt */
		{ .entry = &syscall_adjtimex },
/* 125 */	{ .entry = &syscall_mprotect },
		{ .entry = &syscall_sigprocmask },
		{ .entry = &syscall_ni_syscall },		/* was sys_create_module */
		{ .entry = &syscall_init_module },
		{ .entry = &syscall_delete_module },
/* 130 */	{ .entry = &syscall_ni_syscall },		/* was sys_get_kernel_syms */
		{ .entry = &syscall_quotactl },
		{ .entry = &syscall_getpgid },
		{ .entry = &syscall_fchdir },
		{ .entry = &syscall_bdflush },
/* 135 */	{ .entry = &syscall_sysfs },
		{ .entry = &syscall_personality },
		{ .entry = &syscall_ni_syscall },		/* reserved for afs_syscall */
		{ .entry = &syscall_setfsuid16 },
		{ .entry = &syscall_setfsgid16 },
/* 140 */	{ .entry = &syscall_llseek },
		{ .entry = &syscall_getdents },
		{ .entry = &syscall_select },
		{ .entry = &syscall_flock },
		{ .entry = &syscall_msync },
/* 145 */	{ .entry = &syscall_readv },
		{ .entry = &syscall_writev },
		{ .entry = &syscall_getsid },
		{ .entry = &syscall_fdatasync },
		{ .entry = &syscall_sysctl },
/* 150 */	{ .entry = &syscall_mlock },
		{ .entry = &syscall_munlock },
		{ .entry = &syscall_mlockall },
		{ .entry = &syscall_munlockall },
		{ .entry = &syscall_sched_setparam },
/* 155 */	{ .entry = &syscall_sched_getparam },
		{ .entry = &syscall_sched_setscheduler },
		{ .entry = &syscall_sched_getscheduler },
		{ .entry = &syscall_sched_yield },
		{ .entry = &syscall_sched_get_priority_max },
/* 160 */	{ .entry = &syscall_sched_get_priority_min },
		{ .entry = &syscall_sched_rr_get_interval },
		{ .entry = &syscall_nanosleep },
		{ .entry = &syscall_mremap },
		{ .entry = &syscall_setresuid16 },
/* 165 */	{ .entry = &syscall_getresuid16 },
		{ .entry = &syscall_ni_syscall },		/* vm86 */
		{ .entry = &syscall_ni_syscall },		/* was sys_query_module */
		{ .entry = &syscall_poll },
		{ .entry = &syscall_ni_syscall },		/* was nfsservctl */
/* 170 */	{ .entry = &syscall_setresgid16 },
		{ .entry = &syscall_getresgid16 },
		{ .entry = &syscall_prctl },
		{ .entry = &syscall_rt_sigreturn },
		{ .entry = &syscall_rt_sigaction },
/* 175 */	{ .entry = &syscall_rt_sigprocmask },
		{ .entry = &syscall_rt_sigpending },
		{ .entry = &syscall_rt_sigtimedwait },
		{ .entry = &syscall_rt_sigqueueinfo },
		{ .entry = &syscall_rt_sigsuspend },
/* 180 */	{ .entry = &syscall_pread64 },
		{ .entry = &syscall_pwrite64 },
		{ .entry = &syscall_chown16 },
		{ .entry = &syscall_getcwd },
		{ .entry = &syscall_capget },
/* 185 */	{ .entry = &syscall_capset },
		{ .entry = &syscall_sigaltstack },
		{ .entry = &syscall_sendfile },
		{ .entry = &syscall_ni_syscall },		/* getpmsg */
		{ .entry = &syscall_ni_syscall },		/* putpmsg */
/* 190 */	{ .entry = &syscall_vfork },
		{ .entry = &syscall_getrlimit },
		{ .entry = &syscall_mmap2 },
		{ .entry = &syscall_truncate64 },
		{ .entry = &syscall_ftruncate64 },
/* 195 */	{ .entry = &syscall_stat64 },
		{ .entry = &syscall_lstat64 },
		{ .entry = &syscall_fstat64 },
		{ .entry = &syscall_lchown },
		{ .entry = &syscall_getuid },
/* 200 */	{ .entry = &syscall_getgid },
		{ .entry = &syscall_geteuid },
		{ .entry = &syscall_getegid },
		{ .entry = &syscall_setreuid },
		{ .entry = &syscall_setregid },
/* 205 */	{ .entry = &syscall_getgroups },
		{ .entry = &syscall_setgroups },
		{ .entry = &syscall_fchown },
		{ .entry = &syscall_setresuid },
		{ .entry = &syscall_getresuid },
/* 210 */	{ .entry = &syscall_setresgid },
		{ .entry = &syscall_getresgid },
		{ .entry = &syscall_chown },
		{ .entry = &syscall_setuid },
		{ .entry = &syscall_setgid },
/* 215 */	{ .entry = &syscall_setfsuid },
		{ .entry = &syscall_setfsgid },
		{ .entry = &syscall_getdents64 },
		{ .entry = &syscall_pivot_root },
		{ .entry = &syscall_mincore },
/* 220 */	{ .entry = &syscall_madvise },
		{ .entry = &syscall_fcntl }, /* fcntl64 */
		{ .entry = &syscall_ni_syscall }, /* TUX */
		{ .entry = &syscall_ni_syscall },
		{ .entry = &syscall_gettid },
/* 225 */	{ .entry = &syscall_readahead },
		{ .entry = &syscall_setxattr },
		{ .entry = &syscall_lsetxattr },
		{ .entry = &syscall_fsetxattr },
		{ .entry = &syscall_getxattr },
/* 230 */	{ .entry = &syscall_lgetxattr },
		{ .entry = &syscall_fgetxattr },
		{ .entry = &syscall_listxattr },
		{ .entry = &syscall_llistxattr },
		{ .entry = &syscall_flistxattr },
/* 235 */	{ .entry = &syscall_removexattr },
		{ .entry = &syscall_lremovexattr },
		{ .entry = &syscall_fremovexattr },
		{ .entry = &syscall_tkill },
		{ .entry = &syscall_sendfile64 },
/* 240 */	{ .entry = &syscall_futex },
		{ .entry = &syscall_sched_setaffinity },
		{ .entry = &syscall_sched_getaffinity },
		{ .entry = &syscall_io_setup },
		{ .entry = &syscall_io_destroy },
/* 245 */	{ .entry = &syscall_io_getevents },
		{ .entry = &syscall_io_submit },
		{ .entry = &syscall_io_cancel },
		{ .entry = &syscall_exit_group },
		{ .entry = &syscall_lookup_dcookie },
/* 250 */	{ .entry = &syscall_epoll_create },
		{ .entry = &syscall_epoll_ctl },
		{ .entry = &syscall_epoll_wait },
		{ .entry = &syscall_remap_file_pages },
		{ .entry = &syscall_ni_syscall },	/* sys_set_thread_area */
/* 255 */	{ .entry = &syscall_ni_syscall },	/* sys_get_thread_area */
		{ .entry = &syscall_set_tid_address },
		{ .entry = &syscall_timer_create },
		{ .entry = &syscall_timer_settime },
		{ .entry = &syscall_timer_gettime },
/* 260 */	{ .entry = &syscall_timer_getoverrun },
		{ .entry = &syscall_timer_delete },
		{ .entry = &syscall_clock_settime },
		{ .entry = &syscall_clock_gettime },
		{ .entry = &syscall_clock_getres },
/* 265 */	{ .entry = &syscall_clock_nanosleep },
		{ .entry = &syscall_statfs64 },
		{ .entry = &syscall_fstatfs64 },
		{ .entry = &syscall_tgkill },
		{ .entry = &syscall_utimes },
/* 270 */	{ .entry = &syscall_arm_fadvise64_64 },
		{ .entry = &syscall_pciconfig_iobase },
		{ .entry = &syscall_pciconfig_read },
		{ .entry = &syscall_pciconfig_write },
		{ .entry = &syscall_mq_open },
/* 275 */	{ .entry = &syscall_mq_unlink },
		{ .entry = &syscall_mq_timedsend },
		{ .entry = &syscall_mq_timedreceive },
		{ .entry = &syscall_mq_notify },
		{ .entry = &syscall_mq_getsetattr },
/* 280 */	{ .entry = &syscall_waitid },
		{ .entry = &syscall_socket },
		{ .entry = &syscall_bind },
		{ .entry = &syscall_connect },
		{ .entry = &syscall_listen },
/* 285 */	{ .entry = &syscall_accept },
		{ .entry = &syscall_getsockname },
		{ .entry = &syscall_getpeername },
		{ .entry = &syscall_socketpair },
		{ .entry = &syscall_send },
/* 290 */	{ .entry = &syscall_sendto },
		{ .entry = &syscall_recv },
		{ .entry = &syscall_recvfrom },
		{ .entry = &syscall_shutdown },
		{ .entry = &syscall_setsockopt },
/* 295 */	{ .entry = &syscall_getsockopt },
		{ .entry = &syscall_sendmsg },
		{ .entry = &syscall_recvmsg },
		{ .entry = &syscall_semop },
		{ .entry = &syscall_semget },
/* 300 */	{ .entry = &syscall_semctl },
		{ .entry = &syscall_msgsnd },
		{ .entry = &syscall_msgrcv },
		{ .entry = &syscall_msgget },
		{ .entry = &syscall_msgctl },
/* 305 */	{ .entry = &syscall_shmat },
		{ .entry = &syscall_shmdt },
		{ .entry = &syscall_shmget },
		{ .entry = &syscall_shmctl },
		{ .entry = &syscall_add_key },
/* 310 */	{ .entry = &syscall_request_key },
		{ .entry = &syscall_keyctl },
		{ .entry = &syscall_semtimedop },
/* vserver */	{ .entry = &syscall_ni_syscall },
		{ .entry = &syscall_ioprio_set },
/* 315 */	{ .entry = &syscall_ioprio_get },
		{ .entry = &syscall_inotify_init },
		{ .entry = &syscall_inotify_add_watch },
		{ .entry = &syscall_inotify_rm_watch },
		{ .entry = &syscall_mbind },
/* 320 */	{ .entry = &syscall_get_mempolicy },
		{ .entry = &syscall_set_mempolicy },
		{ .entry = &syscall_openat },
		{ .entry = &syscall_mkdirat },
		{ .entry = &syscall_mknodat },
/* 325 */	{ .entry = &syscall_fchownat },
		{ .entry = &syscall_futimesat },
		{ .entry = &syscall_fstatat64  },
		{ .entry = &syscall_unlinkat },
		{ .entry = &syscall_renameat },
/* 330 */	{ .entry = &syscall_linkat },
		{ .entry = &syscall_symlinkat },
		{ .entry = &syscall_readlinkat },
		{ .entry = &syscall_fchmodat },
		{ .entry = &syscall_faccessat },
/* 335 */	{ .entry = &syscall_pselect6 },
		{ .entry = &syscall_ppoll },
		{ .entry = &syscall_unshare },
		{ .entry = &syscall_set_robust_list },
		{ .entry = &syscall_get_robust_list },
/* 340 */	{ .entry = &syscall_splice },
		{ .entry = &syscall_sync_file_range2 },
		{ .entry = &syscall_tee },
		{ .entry = &syscall_vmsplice },
		{ .entry = &syscall_move_pages },
/* 345 */	{ .entry = &syscall_getcpu },
		{ .entry = &syscall_epoll_pwait },
		{ .entry = &syscall_kexec_load },
		{ .entry = &syscall_utimensat },
		{ .entry = &syscall_signalfd },
/* 350 */	{ .entry = &syscall_timerfd_create },
		{ .entry = &syscall_eventfd },
		{ .entry = &syscall_fallocate },
		{ .entry = &syscall_timerfd_settime },
		{ .entry = &syscall_timerfd_gettime },
/* 355 */	{ .entry = &syscall_signalfd4 },
		{ .entry = &syscall_eventfd2 },
		{ .entry = &syscall_epoll_create1 },
		{ .entry = &syscall_dup3 },
		{ .entry = &syscall_pipe2 },
/* 360 */	{ .entry = &syscall_inotify_init1 },
		{ .entry = &syscall_preadv },
		{ .entry = &syscall_pwritev },
		{ .entry = &syscall_rt_tgsigqueueinfo },
		{ .entry = &syscall_perf_event_open },
/* 365 */	{ .entry = &syscall_recvmmsg },
		{ .entry = &syscall_accept4 },
		{ .entry = &syscall_fanotify_init },
		{ .entry = &syscall_fanotify_mark },
		{ .entry = &syscall_prlimit64 },
/* 370 */	{ .entry = &syscall_name_to_handle_at },
		{ .entry = &syscall_open_by_handle_at },
		{ .entry = &syscall_clock_adjtime },
		{ .entry = &syscall_syncfs },
		{ .entry = &syscall_sendmmsg },
/* 375 */	{ .entry = &syscall_setns },
		{ .entry = &syscall_process_vm_readv },
		{ .entry = &syscall_process_vm_writev },
		{ .entry = &syscall_ni_syscall },	/* reserved for sys_kcmp */
		{ .entry = NULL }
};
