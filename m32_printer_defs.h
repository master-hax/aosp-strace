/* Generated by Makefile from block.c.mpers.i btrfs.c.mpers.i dirent.c.mpers.i evdev_mpers.c.mpers.i fetch_bpf_fprog.c.mpers.i fetch_struct_flock.c.mpers.i fetch_struct_keyctl_kdf_params.c.mpers.i fetch_struct_mmsghdr.c.mpers.i fetch_struct_msghdr.c.mpers.i fetch_struct_stat.c.mpers.i fetch_struct_stat64.c.mpers.i fetch_struct_statfs.c.mpers.i fetch_struct_xfs_quotastat.c.mpers.i hdio.c.mpers.i ipc_msgctl.c.mpers.i ipc_shmctl.c.mpers.i loop.c.mpers.i mtd.c.mpers.i perf_ioctl.c.mpers.i print_aio_sigset.c.mpers.i print_group_req.c.mpers.i print_mq_attr.c.mpers.i print_msgbuf.c.mpers.i print_sg_req_info.c.mpers.i print_sigevent.c.mpers.i print_time.c.mpers.i print_timespec.c.mpers.i print_timeval.c.mpers.i print_timex.c.mpers.i printrusage.c.mpers.i printsiginfo.c.mpers.i rt_sigreturn.c.mpers.i rtc.c.mpers.i sg_io_v3.c.mpers.i sigaltstack.c.mpers.i sock.c.mpers.i sysinfo.c.mpers.i times.c.mpers.i ustat.c.mpers.i utime.c.mpers.i v4l2.c.mpers.i; do not edit. */
.block_ioctl = m32_block_ioctl,
.btrfs_ioctl = m32_btrfs_ioctl,
.evdev_write_ioctl_mpers = m32_evdev_write_ioctl_mpers,
.get_sock_fprog_size = m32_get_sock_fprog_size,
.fetch_bpf_fprog = m32_fetch_bpf_fprog,
.fetch_struct_flock = m32_fetch_struct_flock,
.fetch_struct_flock64 = m32_fetch_struct_flock64,
.fetch_keyctl_kdf_params = m32_fetch_keyctl_kdf_params,
.fetch_struct_mmsghdr = m32_fetch_struct_mmsghdr,
.sizeof_struct_mmsghdr = m32_sizeof_struct_mmsghdr,
.fetch_struct_msghdr = m32_fetch_struct_msghdr,
.fetch_struct_stat = m32_fetch_struct_stat,
.fetch_struct_stat64 = m32_fetch_struct_stat64,
.fetch_struct_statfs = m32_fetch_struct_statfs,
.fetch_struct_statfs64 = m32_fetch_struct_statfs64,
.fetch_struct_quotastat = m32_fetch_struct_quotastat,
.hdio_ioctl = m32_hdio_ioctl,
.loop_ioctl = m32_loop_ioctl,
.mtd_ioctl = m32_mtd_ioctl,
.perf_ioctl = m32_perf_ioctl,
.print_aio_sigset = m32_print_aio_sigset,
.print_group_req = m32_print_group_req,
.printmqattr = m32_printmqattr,
.tprint_msgbuf = m32_tprint_msgbuf,
.decode_sg_req_info = m32_decode_sg_req_info,
.print_sigevent = m32_print_sigevent,
.print_struct_timespec_data_size = m32_print_struct_timespec_data_size,
.print_struct_timespec_array_data_size = m32_print_struct_timespec_array_data_size,
.print_timespec = m32_print_timespec,
.sprint_timespec = m32_sprint_timespec,
.print_timespec_utime_pair = m32_print_timespec_utime_pair,
.print_itimerspec = m32_print_itimerspec,
.print_struct_timeval = m32_print_struct_timeval,
.print_struct_timeval_data_size = m32_print_struct_timeval_data_size,
.print_timeval = m32_print_timeval,
.print_timeval_utimes = m32_print_timeval_utimes,
.sprint_timeval = m32_sprint_timeval,
.print_itimerval = m32_print_itimerval,
.print_timex = m32_print_timex,
.printrusage = m32_printrusage,
.printsiginfo_at = m32_printsiginfo_at,
.print_siginfo_array = m32_print_siginfo_array,
.rtc_ioctl = m32_rtc_ioctl,
.decode_sg_io_v3 = m32_decode_sg_io_v3,
.sock_ioctl = m32_sock_ioctl,
.v4l2_ioctl = m32_v4l2_ioctl,