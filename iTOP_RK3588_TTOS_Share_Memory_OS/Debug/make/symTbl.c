
struct symtab_s
{
  const char *sym_name;          /* A pointer to the symbol name string */ 
  const void *sym_value;         /* The value associated with the string */
};
extern int atomic_add ();
extern int atomic_and ();
extern int atomic_cmpxchg ();
extern int atomic_dec ();
extern int atomic_inc ();
extern int atomic_or ();
extern int atomic_read ();
extern int atomic_set ();
extern int atomic_sub ();
extern int atomic_xor ();
extern int debugEventDisableRecord ();
extern int debugEventEnableRecord ();
extern int debugEventInit ();
extern int debugEventRecord ();
extern int debugEventShow ();
extern int delayMS ();
extern int delayUS ();
extern int getCurrentSystemCount ();
extern int getCurrentSystemFreq ();
extern int getCurrentSystemSubTime ();
extern int getCurrentSystemTime ();
extern int memAlignClear ();
extern int memAlignCpy ();
extern int wordBitSetCountGet ();
extern int wordMSBGet ();
extern int wordMSBGetAndClear ();
extern int __vring_new_virtqueue ();
extern int get_avail_buf_of_virtqueue ();
extern int sm_virtqueue_add ();
extern int sm_virtqueue_get_buf_ctx ();
extern int sm_vring_create_virtqueue ();
extern int vnet_alloc_queues ();
extern int vnet_find_vqs ();
extern int vnet_init_vqs ();
extern int vnet_setup_vq ();
extern int vnet_vp_find_vqs ();
extern int vring_alloc_queue ();
extern int vring_free_queue ();
extern int atomic32Add ();
extern int atomic32And ();
extern int atomic32Cas ();
extern int atomic32Clear ();
extern int atomic32Dec ();
extern int atomic32Get ();
extern int atomic32Inc ();
extern int atomic32Nand ();
extern int atomic32Or ();
extern int atomic32Set ();
extern int atomic32Sub ();
extern int atomic32Xor ();
extern int vmCpuIDGet ();
extern int vmGlobalIntEnMaskClear ();
extern int vmGlobalIntEnMaskGet ();
extern int vmGlobalIntEnMaskGetAndClear ();
extern int vmGlobalIntEnMaskSet ();
extern int zeroNumOfLongGet ();
extern int zeroNumOfWordGet ();
extern int cacheIsEnable ();
extern int fppRegisterInitValue;
extern int fpscrInit ();
extern int intNumSet ();
extern int showExcInfo ();
extern int wordLSBGet ();
extern int fppRestoreContext ();
extern int fppSaveContext ();
extern int spinLockAsm ();
extern int spinUnlockAsm ();
extern int spinLockRaw ();
extern int spinUnlockRaw ();
extern int spinLockAsm ();
extern int spinUnlockAsm ();
extern int dl_lock;
extern int dladdr ();
extern int dlclose ();
extern int dlerror ();
extern int dlopen ();
extern int dlsym ();
extern int libdl_info;
extern int addr_to_name ();
extern int app_find_sym_in_dl ();
extern int dl_unwind_find_exidx ();
extern int find_containing_library ();
extern int find_containing_symbol ();
extern int find_library ();
extern int ide_load_all_library ();
extern int ide_load_single_library ();
extern int lookup ();
extern int lookup_in_library ();
extern int read_library ();
extern int unload_library ();
extern int rtld_db_dlactivity ();
extern int _ctype_;
extern int isalnum ();
extern int isalpha ();
extern int isascii ();
extern int iscntrl ();
extern int isdigit ();
extern int islower ();
extern int isgraph ();
extern int isprint ();
extern int ispunct ();
extern int isspace ();
extern int isupper ();
extern int isxdigit ();
extern int toascii ();
extern int tolower ();
extern int toupper ();
extern int calloc ();
extern int heap_mem_init ();
extern int _Init_Heap;
extern int AdjustSize ();
extern int ClearBlockHeadMap ();
extern int Convert2ValidHeadIndex ();
extern int fnRTL_LibcHeapAppInit ();
extern int free ();
extern int InsertBlockToList ();
extern int malloc ();
extern int mallocInfoHookPtr;
extern int mem_stt_show ();
extern int memalign ();
extern int MoveBlockFromList ();
extern int pgfree ();
extern int pgmalloc ();
extern int SetBlockHeadMap ();
extern int sysHeapInitialize ();
extern int accumFreeBlks;
extern int accumFreeSize;
extern int accumMallocBlks;
extern int accumMallocSize;
extern int freeFailures;
extern int HeapFreeBlocks;
extern int HeapFreeSize;
extern int HeapInuseSize;
extern int HeapTotalSize;
extern int mallocFailures;
extern int mallocInfo ();
extern int mallocInfo_isr ();
extern int mallocInfoHook ();
extern int maxMallocBlkSize;
extern int mem_findmax ();
extern int mem_getinfo ();
extern int mem_show ();
extern int _Mpart_Heap_Control;
extern int check_mpart_id_valid ();
extern int mpart_addmem ();
extern int mpart_alloc ();
extern int mpart_create ();
extern int mpart_delete ();
extern int mpart_free ();
extern int mpart_memalign ();
extern int mpart_module_init ();
extern int mpart_realloc ();
extern int mpartInfoHookPtr;
extern int mpart_findmaxfree ();
extern int mpart_getinfo ();
extern int mpartInfoHook ();
extern int realloc ();
extern int __locale;
extern int __locale_mb_cur_max ();
extern int localeconv ();
extern int setlocale ();
extern int _getopt_internal ();
extern int _getopt_internal_r ();
extern int getopt ();
extern int optarg;
extern int opterr;
extern int optind;
extern int optopt;
extern int _getopt_long_only_r ();
extern int _getopt_long_r ();
extern int getopt_long ();
extern int getopt_long_only ();
extern int dq_addafter ();
extern int dq_addbefore ();
extern int dq_addfirst ();
extern int dq_addlast ();
extern int dq_cat ();
extern int dq_count ();
extern int dq_rem ();
extern int dq_remfirst ();
extern int dq_remlast ();
extern int sq_addafter ();
extern int sq_addfirst ();
extern int sq_addlast ();
extern int sq_cat ();
extern int sq_count ();
extern int sq_rem ();
extern int sq_remafter ();
extern int sq_remfirst ();
extern int sq_remlast ();
extern int clearerr ();
extern int fclose ();
extern int fdopen ();
extern int feof ();
extern int ferror ();
extern int fflush ();
extern int fgetc ();
extern int fgetpos ();
extern int fgets ();
extern int fgetwc ();
extern int fileno ();
extern int __sfmoreglue ();
extern int __sfp ();
extern int __sinit ();
extern int __sflags ();
extern int fopen ();
extern int fprintf ();
extern int fputc ();
extern int fputs ();
extern int fputws ();
extern int fread ();
extern int freopen ();
extern int fscanf ();
extern int fseek ();
extern int fsetpos ();
extern int ftell ();
extern int __sfvwrite ();
extern int _fwalk ();
extern int fwide ();
extern int fwrite ();
extern int getc ();
extern int getchar ();
extern int gets ();
extern int getw ();
extern int global_std_get ();
extern int global_std_set ();
extern int __smakebuf ();
extern int perror ();
extern int fdprintf ();
extern int printf ();
extern int printf_mutex_lock;
extern int vfdprintf ();
extern int vprintf ();
extern int putc ();
extern int putchar ();
extern int puts ();
extern int putw ();
extern int __srefill ();
extern int remove ();
extern int rename ();
extern int rewind ();
extern int __srget ();
extern int scanf ();
extern int setbuf ();
extern int setvbuf ();
extern int __sclose ();
extern int __sread ();
extern int __sseek ();
extern int __swrite ();
extern int _iores_ptr;
extern int createPrintMutex ();
extern int fnRTL_GetIORes ();
extern int fnRTL_LibcIOInit ();
extern int iores_data;
extern int IOResSemObtain ();
extern int IOResSemRelease ();
extern int iosem_id;
extern int libcIOInitFlag;
extern int ungetc ();
extern int vfprintf ();
extern int __swbuf ();
extern int __swsetup ();
extern int abort ();
extern int abs ();
extern int __assert ();
extern int __assert_func ();
extern int atexit ();
extern int atof ();
extern int atoi ();
extern int atol ();
extern int bsearch ();
extern int __cxa_atexit ();
extern int div ();
extern int environ;
extern int initial_env;
extern int _Exit ();
extern int exit ();
extern int findenv ();
extern int fformat ();
extern int fscan ();
extern int labs ();
extern int ldiv ();
extern int disablePrint ();
extern int enablePrint ();
extern int getPrintFlag ();
extern int printk ();
extern int rand ();
extern int srand ();
extern int strdup ();
extern int strtold ();
extern int strtoll ();
extern int skipspace ();
extern int strtoull ();
extern int fioformatnstr ();
extern int fioformatstr ();
extern int fioscans ();
extern int signofnum;
extern int snprintf ();
extern int sprintf ();
extern int sscanf ();
extern int vsnprintf ();
extern int vsprintf ();
extern int getenv ();
extern int putenv ();
extern int qsort ();
extern int setenv ();
extern int strtod ();
extern int strtof ();
extern int strtol ();
extern int strtoul ();
extern int bcmp ();
extern int bcopy ();
extern int bcopyBytes ();
extern int bcopyLongs ();
extern int bcopyWords ();
extern int bfill ();
extern int bfillBytes ();
extern int binvert ();
extern int bswap ();
extern int bzero ();
extern int index ();
extern int memchr ();
extern int memcmp ();
extern int memcpy ();
extern int memmove ();
extern int memset ();
extern int rindex ();
extern int strcat ();
extern int strchr ();
extern int strcmp ();
extern int strcoll ();
extern int strcpy ();
extern int strcspn ();
extern int errno_tlb;
extern int strerror ();
extern int unknow_errno_info;
extern int strlen ();
extern int strncat ();
extern int strncmp ();
extern int strncpy ();
extern int strpbrk ();
extern int strrchr ();
extern int strspn ();
extern int strstr ();
extern int strtok ();
extern int strxfrm ();
extern int swab ();
extern int uswab ();
extern int __createsem ();
extern int __deletesem ();
extern int __obtainsem ();
extern int __releasesem ();
extern int symtab_findbyname ();
extern int symtab_findbyvalue ();
extern int symtab_sortbyname ();
extern int cat ();
extern int chdir ();
extern int close ();
extern int closedir ();
extern int creat ();
extern int fcntl ();
extern int fstat ();
extern int fsync ();
extern int ftruncate ();
extern int getcwd ();
extern int ioctl ();
extern int isatty ();
extern int __lseek ();
extern int lseek ();
extern int mkdir ();
extern int mknod ();
extern int rtos_filesystem_make_dev_t ();
extern int open ();
extern int opendir ();
extern int read ();
extern int readdir ();
extern int rewinddir ();
extern int rmdir ();
extern int sockets_adapter_close ();
extern int sockets_adapter_fcntl ();
extern int sockets_adapter_get_max_fd_with_socket ();
extern int sockets_adapter_ioctl ();
extern int sockets_adapter_is_socket_fd ();
extern int sockets_adapter_read ();
extern int sockets_adapter_set_ops ();
extern int sockets_adapter_write ();
extern int stat ();
extern int truncate ();
extern int unlink ();
extern int utime ();
extern int write ();
extern int asctime ();
extern int clock ();
extern int clock_timespec_to_ticks ();
extern int clock_timespec_to_ticks_by_clockid ();
extern int ctime ();
extern int difftime ();
extern int gettimeofday ();
extern int gettime ();
extern int gmtime ();
extern int gmtime_r ();
extern int localtime ();
extern int localtime_r ();
extern int mktime ();
extern int mktime_utc ();
extern int validate_structure ();
extern int getdstinfo ();
extern int getzoneinfo ();
extern int strftime ();
extern int clockGettime ();
extern int clockSettime ();
extern int time ();
extern int btowc ();
extern int fnmatch ();
extern int getwc ();
extern int isblank ();
extern int iswalnum ();
extern int iswalpha ();
extern int iswblank ();
extern int iswcntrl ();
extern int iswctype ();
extern int iswdigit ();
extern int iswgraph ();
extern int iswlower ();
extern int iswprint ();
extern int iswpunct ();
extern int iswspace ();
extern int iswupper ();
extern int iswxdigit ();
extern int mblen ();
extern int mbrtowc ();
extern int mbstowcs ();
extern int mbtowc ();
extern int putwc ();
extern int towlower ();
extern int towupper ();
extern int ungetwc ();
extern int wcrtomb ();
extern int wcscmp ();
extern int wcscoll ();
extern int wcsftime ();
extern int wcslcpy ();
extern int wcslen ();
extern int wcstombs ();
extern int wcsxfrm ();
extern int wctob ();
extern int wctomb ();
extern int wctype ();
extern int wmemchr ();
extern int wmemcmp ();
extern int wmemcpy ();
extern int wmemmove ();
extern int wmemset ();
extern int acos ();
extern int asin ();
extern int atan ();
extern int atan2 ();
extern int ceil ();
extern int cos ();
extern int cosh ();
extern int exp ();
extern int fabs ();
extern int floor ();
extern int fmod ();
extern int frexp ();
extern int ldexp ();
extern int log ();
extern int log10 ();
extern int copysign ();
extern int drem ();
extern int exp__E ();
extern int expm1 ();
extern int finite ();
extern int fpTypeGet ();
extern int log__L ();
extern int logb ();
extern int scaleb ();
extern int modf ();
extern int pow ();
extern int pow_p ();
extern int sin ();
extern int sinh ();
extern int sqrt ();
extern int tan ();
extern int tanh ();
extern int ttos_shell_prf ();
extern int shell_factory ();
extern int shell_get_pwddir ();
extern int shell_get_workdir ();
extern int shell_signal_handle ();
extern int shell_task_prio;
extern int shell_thread_id;
extern int sys_launch_time;
extern int TICKS_PER_SECENDS;
extern int ttos_shell_fprintf ();
extern int ttos_shell_init ();
extern int ttos_shell_process ();
extern int ttos_shell_process_init ();
extern int ttos_shell_start ();
extern int ttos_shell_thread ();
extern int echo_status;
extern int shell_cmd_clear;
extern int shell_cmd_help;
extern int shell_fprintf_buffer_flush ();
extern int shell_fprintf_fmt ();
extern int shell_help_cmd_print ();
extern int shellGetMementoCount ();
extern int shellHistoryAdd ();
extern int shellHistoryDelete ();
extern int shellHistoryGet ();
extern int shellHistoryInite ();
extern int shellMementoAdd ();
extern int shellMementoDelete ();
extern int shellMementoInite ();
extern int shellMementoIterator ();
extern int shellMementoUninite ();
extern int findMountPoint ();
extern int getFirstMntPoint ();
extern int getLastMntPoint ();
extern int initialFlag;
extern int isMountPointEmpty ();
extern int isMountPointExist ();
extern int mountPoint;
extern int registerMntPoint ();
extern int registerMountPointIterator ();
extern int showAllRegisterMountPoint ();
extern int unRegisterMntPoint ();
extern int shell_cmd_line_erase ();
extern int shell_cursor_in_empty_line ();
extern int shell_data_insert ();
extern int shell_vt100_color_set ();
extern int shell_vt100_colors_restore ();
extern int ttos_shell_char_backspace ();
extern int ttos_shell_char_delete ();
extern int ttos_shell_char_insert ();
extern int ttos_shell_completion_insert ();
extern int ttos_shell_cond_next_line ();
extern int ttos_shell_cursor_end_move ();
extern int ttos_shell_cursor_home_move ();
extern int ttos_shell_cursor_horiz_move ();
extern int ttos_shell_cursor_move ();
extern int ttos_shell_cursor_position_synchronize ();
extern int ttos_shell_cursor_vert_move ();
extern int ttos_shell_cursor_word_move ();
extern int ttos_shell_delete_cmd ();
extern int ttos_shell_delete_from_cursor ();
extern int ttos_shell_internal_fprintf ();
extern int ttos_shell_internal_vfprintf ();
extern int ttos_shell_left_arrow ();
extern int ttos_shell_print_cmd ();
extern int ttos_shell_print_prompt_and_cmd ();
extern int ttos_shell_print_stream ();
extern int ttos_shell_right_arrow ();
extern int ttos_shell_word_remove ();
extern int ttos_shell_write ();
extern int shell_column_span_with_buffer_offsets_get ();
extern int shell_row_span_with_buffer_offsets_get ();
extern int ttos_shell_cmd_get ();
extern int ttos_shell_cmd_trim ();
extern int ttos_shell_make_argv ();
extern int ttos_shell_multiline_data_calc ();
extern int ttos_shell_root_cmd_count ();
extern int ttos_shell_root_cmd_find ();
extern int ttos_shell_root_cmd_get ();
extern int shell_get_current_task ();
extern int cmd_init ();
extern int find_fileposinpath ();
extern int is_hex ();
extern int is_ip ();
extern int nfssys_name_pro ();
extern int shell_cmd_app;
extern int shell_cmd_appconfig;
extern int shell_cmd_arp;
extern int shell_cmd_cat;
extern int shell_cmd_cd;
extern int shell_cmd_cp;
extern int shell_cmd_cpuuse;
extern int shell_cmd_cyclictest;
extern int shell_cmd_d;
extern int shell_cmd_date;
extern int shell_cmd_deadlock;
extern int shell_cmd_devls;
extern int shell_cmd_errno;
extern int shell_cmd_ethercat;
extern int shell_cmd_fdinfo;
extern int shell_cmd_heap;
extern int shell_cmd_history;
extern int shell_cmd_ifconfig;
extern int shell_cmd_ls;
extern int shell_cmd_m;
extern int shell_cmd_mkdir;
extern int shell_cmd_mkfs;
extern int shell_cmd_msg;
extern int shell_cmd_mv;
extern int shell_cmd_netstats;
extern int shell_cmd_ping;
extern int shell_cmd_pwd;
extern int shell_cmd_quit;
extern int shell_cmd_redirect;
extern int shell_cmd_rm;
extern int shell_cmd_rmdir;
extern int shell_cmd_route;
extern int shell_cmd_sem;
extern int shell_cmd_shminfo;
extern int shell_cmd_stackuse;
extern int shell_cmd_sysheap;
extern int shell_cmd_sysinfo;
extern int shell_cmd_task;
extern int shell_cmd_tc;
extern int shell_cmd_td;
extern int shell_cmd_tick;
extern int shell_cmd_timer;
extern int shell_cmd_top;
extern int shell_cmd_touch;
extern int shell_cmd_tp;
extern int shell_cmd_tr;
extern int shell_cmd_trace;
extern int shell_cmd_ts;
extern int shell_cmd_tts;
extern int shell_cmd_version;
extern int shell_cmd_vm;
extern int shell_cmd_who;
extern int string_all_digit_dec ();
extern int string_all_digit_hex ();
extern int task_state_to_char ();
extern int shell_main_app ();
extern int shell_main_appconfig ();
extern int arp_display ();
extern int shell_main_arp ();
extern int shell_cat_file ();
extern int shell_main_cat ();
extern int shell_main_cd ();
extern int copy_dir ();
extern int copy_file ();
extern int shell_main_cp ();
extern int shell_main_cpuuse ();
extern int err_msg ();
extern int err_msg_n ();
extern int event_disable ();
extern int get_tracers ();
extern int parse_time_string ();
extern int policy_to_string ();
extern int setevent ();
extern int shell_main_cyclictest ();
extern int string_to_policy ();
extern int timerthread ();
extern int traceopt ();
extern int tracing ();
extern int shell_main_d ();
extern int shell_main_date ();
extern int shell_main_devls ();
extern int shell_main_errno ();
extern int shell_main_ethercat ();
extern int shell_main_fdinfo ();
extern int data_hook ();
extern int shell_lock_taskshow ();
extern int shell_main_deadlock ();
extern int shell_main_heap ();
extern int shell_main_history ();
extern int shell_main_ifconfig ();
extern int shell_main_lkup ();
extern int to_symbol_type ();
extern int mode_to_string ();
extern int shell_main_ls ();
extern int shell_main_m ();
extern int shell_main_mkdir ();
extern int shell_main_mkfs ();
extern int monitorElementShow ();
extern int shell_main_monitor ();
extern int shell_main_msg ();
extern int shell_main_mv ();
extern int shell_main_netstats ();
extern int shell_main_p ();
extern int ping_send ();
extern int shell_main_ping ();
extern int shell_main_pwd ();
extern int shell_main_quit ();
extern int shell_main_reboot ();
extern int shell_main_redirect ();
extern int shell_main_rm ();
extern int recursion_rmdir ();
extern int shell_main_rmdir ();
extern int shell_main_route ();
extern int shell_main_sem ();
extern int shell_main_shminfo ();
extern int shell_main_stackuse ();
extern int shell_main_sysheap ();
extern int shell_main_sysinfo ();
extern int showMntPointInfo ();
extern int shell_main_task ();
extern int shell_main_tc ();
extern int shell_main_td ();
extern int shell_main_tick ();
extern int shell_main_timer ();
extern int timer_stat_to_string ();
extern int shell_main_top ();
extern int shellTopGetCPUInfo ();
extern int shell_main_touch ();
extern int shell_main_tp ();
extern int shell_main_tr ();
extern int shell_main_trace ();
extern int shell_main_ts ();
extern int shell_main_tts ();
extern int shell_main_version ();
extern int shell_main_vm ();
extern int vmstatus_to_string ();
extern int shell_main_who ();
extern int shell_getopt ();
extern int shell_getopt_long ();
extern int shell_getopt_tmp ();
extern int dot_path_pro ();
extern int dotdot_path_pro ();
extern int find_father_dir ();
extern int get_pwd_dir ();
extern int illegal_path_check ();
extern int pwd_path_pro ();
extern int recursion_dotdot_pro ();
extern int update_shell_prompt ();
extern int update_work_dir ();
extern int addMonitorElement ();
extern int creatSystemMonitor ();
extern int defaultMonitorSignalHandler ();
extern int defaultMonitorTaskHandler ();
extern int exceptionInformationProcess ();
extern int exceptionMonitorSignalHandler ();
extern int get_monitor_priority ();
extern int get_monitor_stack_size ();
extern int info;
extern int monitorElementIterator ();
extern int monitorFind ();
extern int monitorHead;
extern int monitorTrigger ();
extern int set_monitor_priority ();
extern int set_monitor_stack_size ();
extern int sysInfoInit ();
extern int sysInfoInitTask ();
extern int systemPowerOnInfoTask ();
extern int hashCode ();
extern int SYM_SymbolAdd ();
extern int SYM_SymbolDelete ();
extern int SYM_SymbolEach ();
extern int SYM_SymbolFind ();
extern int SYM_SymbolShow ();
extern int SYM_SymbolValueGet ();
extern int SYM_SystemSymbolTableAdd ();
extern int symFind ();
extern int symInit ();
extern int symTableAdd ();
extern int lukp_test_double;
extern int lukp_test_float;
extern int lukp_test_value0;
extern int lukp_test_value1;
extern int lukp_test_value2;
extern int lukp_test_value3;
extern int lukp_test_value4;
extern int standTbl;
extern int standTblSize;
extern int symAaddTest ();
extern int symTest ();
extern int userETbl;
extern int userETblSize;
extern int userTbl;
extern int userTblSize;
extern int connect_fd;
extern int diconnect_telnet ();
extern int enable_shell_telnet ();
extern int get_shell_priority ();
extern int get_shell_ptr ();
extern int get_shell_stack_size ();
extern int oldstd;
extern int rpc_task;
extern int runtime_factory ();
extern int set_shell_priority ();
extern int set_shell_stack_size ();
extern int sh_telnet;
extern int shell_backend_telnet_get_ptr ();
extern int shell_ctx_factory ();
extern int shell_fprintf_factory ();
extern int shell_init_flag;
extern int shell_interface_factory ();
extern int shell_telnet_server_init ();
extern int shell_telnet_server_task ();
extern int shell_telnet_set_client_disable_echo ();
extern int shell_telnet_task ();
extern int shell_uart_server_init ();
extern int telnet_server_fd;
extern int telnet_shell_destroy ();
extern int telnet_shell_factory ();
extern int terminal_factory ();
extern int VMK_AccessVM ();
extern int VMK_AckException ();
extern int VMK_ControlVM ();
extern int VMK_CreateShm ();
extern int VMK_DisablePIC ();
extern int VMK_EnablePIC ();
extern int VMK_EveWriteData ();
extern int VMK_CpuIDGet ();
extern int VMK_GetEnableCpuSet ();
extern int VMK_GetExceptionVM ();
extern int VMK_GetKernelInfo ();
extern int VMK_GetMainFrameTicks ();
extern int VMK_GetSysClkRate ();
extern int VMK_GetSystemTicks ();
extern int VMK_GetTTSID ();
extern int VMK_GetTTSInfo ();
extern int VMK_GetTTSName ();
extern int VMK_GetVMID ();
extern int VMK_GetVMInfo ();
extern int VMK_GetVMMemBlockSize ();
extern int VMK_GetVMName ();
extern int VMK_GetVMPhysicalAddress ();
extern int VMK_GetVMStatus ();
extern int VMK_GetVMTSSInfo ();
extern int VMK_GetVMWindowTicks ();
extern int VMK_HaltVM ();
extern int VMK_InitializeVint ();
extern int VMK_MapPage ();
extern int VMK_MapShm ();
extern int VMK_PrintChar ();
extern int VMK_ResetVM ();
extern int VMK_ResumeVM ();
extern int VMK_SendIPI ();
extern int VMK_SendServiceInt ();
extern int VMK_SetSysClkRate ();
extern int VMK_SetVMPageAttribute ();
extern int VMK_StartTTS ();
extern int VMK_StartVM ();
extern int VMK_StopTTS ();
extern int VMK_StopVM ();
extern int VMK_SuspendVM ();
extern int VMK_TerminateInt ();
extern int VMK_TriggerVint ();
extern int VMK_UnMapShm ();
extern int cpuIDGet ();
extern int hCpuIDGet ();
extern int vbspInit ();
extern int VMK_GetCPUTime ();
extern int vbspDisableExInt ();
extern int vbspDisableGlobalInt ();
extern int vbspDisableSerInt ();
extern int vbspDisableTickInt ();
extern int vbspDispatchVint ();
extern int vbspTriggerVint ();
extern int vbspDisableVint ();
extern int vbspEnableVint ();
extern int vbspEnableExInt ();
extern int restoreGlobalIntCount;
extern int vbspEnableGlobalInt ();
extern int vbspRestoreGlobalInt ();
extern int vbspEnableSerInt ();
extern int vbspEnableTickInt ();
extern int vbspGetGlobalInt ();
extern int vbspGetGlobalIntAdress ();
extern int vbspInitializeVint ();
extern int vbspInitializeVintHandler ();
extern int vbspInitializeVintWithHandler ();
extern int vbspInstallVintHandler ();
extern int vbspUnInstallVintHandler ();
extern int g_vbspExceptionHandlerTable;
extern int g_vbspExIntHandlerTable;
extern int g_vbspServIntHandlerTable;
extern int g_vbspTickHandler;
extern int g_vbspVIntEnMask;
extern int vbspVintHandler ();
extern int cfgGetCurrentVmConfig ();
extern int pciDirectFindCan ();
extern int pciDirectFindDevice ();
extern int pciDirectFindNic ();
extern int pciDirectFindNicInfo ();
extern int pciDirectFindSpi ();
extern int VMK_AllocVector ();
extern int VMK_ChangeCurrentVmCpuStatus ();
extern int VMK_FloatCtrol ();
extern int VMK_GetConfigTableAddr ();
extern int VMK_GetCPUFreq ();
extern int VMK_GetWorkSpaceSize ();
extern int VMK_MapExint ();
extern int VMK_MapExintToVint ();
extern int VMK_Reboot ();
extern int VMK_RteDebugSet ();
extern int VMK_StartStageInit ();
extern int VMK_VmPrintBuf ();
extern int TTOS_GetEventInfo ();
extern int TTOS_ReceiveEvent ();
extern int TTOS_SendEvent ();
extern int TTOS_NotifyHM ();
extern int TTOS_CPULoadDistribution ();
extern int TTOS_CPURecordLog ();
extern int TTOS_CPURecordLogTask ();
extern int TTOS_CPUStatisticsDisable ();
extern int TTOS_CPUStatisticsEnable ();
extern int TTOS_CPUStatisticsInit ();
extern int TTOS_CPUStatisticsTest ();
extern int TTOS_CPUUsageStatistics ();
extern int TTOS_CPUUsageStatisticsTask ();
extern int TTOS_GetCPURecordLogPeriod ();
extern int TTOS_GetCPUSamplingPeriod ();
extern int TTOS_GetCPUUsage ();
extern int TTOS_SetCPURecordLogPeriod ();
extern int TTOS_SetCPUSamplingPeriod ();
extern int TTOS_SetRecordLogTaskPrior ();
extern int TTOS_SetUsageStatisticsTaskPrior ();
extern int TTOS_StartOS ();
extern int ttosAPEntry ();
extern int ttosIdleTaskEntry ();
extern int ttosIdleTCB;
extern int ttosInitialized;
extern int ttosManager;
extern int TTOS_CreateMsgq ();
extern int ttosInitMsgq ();
extern int TTOS_DeleteMsgq ();
extern int ttosDeleteMessage ();
extern int TTOS_GetMsgqClassInfo ();
extern int TTOS_GetMsgqCount ();
extern int TTOS_GetMsgqID ();
extern int TTOS_GetMsgqInfo ();
extern int TTOS_GetMsgqName ();
extern int TTOS_GetMsgqPendingCount ();
extern int ttosCommitMessage ();
extern int ttosInsertMsg ();
extern int ttosSetMessageNotify ();
extern int TTOS_ReceiveMsgq ();
extern int TTOS_SendMsgq ();
extern int alarm ();
extern int alarm_init ();
extern int backTrace ();
extern int backTraceGetDepth ();
extern int backTraceSetDepth ();
extern int clock_getcpuclockid ();
extern int clock_getres ();
extern int clock_gettime ();
extern int clock_settime ();
extern int sys_clk_rate_get ();
extern int sys_clk_rate_set ();
extern int tick_get ();
extern int tick_set ();
extern int exception_handler_set ();
extern int int_disable_pic ();
extern int int_enable_pic ();
extern int int_install_handler ();
extern int int_lock ();
extern int int_uninstall_handler ();
extern int int_unlock ();
extern int shared_int_install ();
extern int shared_int_uninstall ();
extern int mq_close ();
extern int mq_create ();
extern int mq_delete ();
extern int mq_getattr ();
extern int mq_getinfo ();
extern int mq_init ();
extern int mq_notify ();
extern int mq_open ();
extern int mq_receive ();
extern int mq_send ();
extern int mq_setattr ();
extern int mq_show ();
extern int mq_timedreceive ();
extern int mq_timedsend ();
extern int mq_unlink ();
extern int convertCoreReturnCodeToErrno ();
extern int getShowErrnoMoreInfoFlag ();
extern int setShowErrnoMoreInfoFlag ();
extern int corePrioritytoPthread ();
extern int currentPthreadTryToDeferredCancel ();
extern int posix_memalign ();
extern int pthread_cancel ();
extern int pthread_cancelforce ();
extern int pthread_cleanup_pop ();
extern int pthread_cleanup_push ();
extern int pthread_create ();
extern int pthread_default_attr_get ();
extern int pthread_delay ();
extern int pthread_detach ();
extern int pthread_exit ();
extern int pthread_getaffinity_np ();
extern int pthread_getattr_np ();
extern int pthread_getcpuclockid ();
extern int pthread_getschedparam ();
extern int pthread_join ();
extern int pthread_lock ();
extern int pthread_resume ();
extern int pthread_self ();
extern int pthread_setaffinity_np ();
extern int pthread_setcancelstate ();
extern int pthread_setcanceltype ();
extern int pthread_setschedparam ();
extern int pthread_setschedprio ();
extern int pthread_sigmask ();
extern int pthread_spin_destroy ();
extern int pthread_spin_init ();
extern int pthread_spin_lock ();
extern int pthread_spin_trylock ();
extern int pthread_spin_unlock ();
extern int pthread_suspend ();
extern int pthread_testcancel ();
extern int pthread_unlock ();
extern int pthreadIsCancelableForAsync ();
extern int pthreadIsCancelableForDeferred ();
extern int pthreadJoinCanceHook ();
extern int pthreadPriorityIsValid ();
extern int pthreadPriorityToCore ();
extern int pthreadRunCancelHandler ();
extern int pthreadTryToCancel ();
extern int pthread_attr_destroy ();
extern int pthread_attr_getbreakallowed ();
extern int pthread_attr_getdetachstate ();
extern int pthread_attr_getfpallowed ();
extern int pthread_attr_getguardsize ();
extern int pthread_attr_getinheritsched ();
extern int pthread_attr_getname ();
extern int pthread_attr_getschedparam ();
extern int pthread_attr_getschedpolicy ();
extern int pthread_attr_getschedprio ();
extern int pthread_attr_getscope ();
extern int pthread_attr_getstack ();
extern int pthread_attr_getstackaddr ();
extern int pthread_attr_getstackfilled ();
extern int pthread_attr_getstacksize ();
extern int pthread_attr_init ();
extern int pthread_attr_setbreakallowed ();
extern int pthread_attr_setdetachstate ();
extern int pthread_attr_setfpallowed ();
extern int pthread_attr_setguardsize ();
extern int pthread_attr_setinheritsched ();
extern int pthread_attr_setname ();
extern int pthread_attr_setschedparam ();
extern int pthread_attr_setschedpolicy ();
extern int pthread_attr_setschedprio ();
extern int pthread_attr_setscope ();
extern int pthread_attr_setstack ();
extern int pthread_attr_setstackaddr ();
extern int pthread_attr_setstackfilled ();
extern int pthread_attr_setstacksize ();
extern int pthread_barrier_destroy ();
extern int pthread_barrier_init ();
extern int pthread_barrier_wait ();
extern int pthread_barrierattr_destroy ();
extern int pthread_barrierattr_getpshared ();
extern int pthread_barrierattr_init ();
extern int pthread_barrierattr_setpshared ();
extern int pthread_cond_broadcast ();
extern int pthread_cond_destroy ();
extern int pthread_cond_getinfo ();
extern int pthread_cond_init ();
extern int pthread_cond_module_init ();
extern int pthread_cond_show ();
extern int pthread_cond_signal ();
extern int pthread_cond_timedwait ();
extern int pthread_cond_wait ();
extern int pthread_condattr_destroy ();
extern int pthread_condattr_getclock ();
extern int pthread_condattr_getpshared ();
extern int pthread_condattr_init ();
extern int pthread_condattr_setclock ();
extern int pthread_condattr_setpshared ();
extern int display_optional_info_title ();
extern int display_stack_info_title ();
extern int display_task_base_info_title ();
extern int getpid ();
extern int getuid ();
extern int pathconf ();
extern int pthread_base_info_display ();
extern int pthread_equal ();
extern int pthread_get_policy ();
extern int pthread_getid ();
extern int pthread_getinfo ();
extern int pthread_getname ();
extern int pthread_getregs ();
extern int pthread_getschedprio ();
extern int pthread_info_display ();
extern int pthread_is_ready ();
extern int pthread_is_suspend ();
extern int pthread_optional_info_display ();
extern int pthread_show ();
extern int pthread_showstack ();
extern int pthread_showstackframe ();
extern int pthread_stack_info_display ();
extern int pthread_state ();
extern int pthread_verifyid ();
extern int pthreadDeleteTable;
extern int pthreadSwitchTable;
extern int traceFunction ();
extern int pthread_close_hook_add ();
extern int pthread_close_hook_delete ();
extern int pthread_create_hook_add ();
extern int pthread_create_hook_delete ();
extern int pthread_switch_hook_add ();
extern int pthread_switch_hook_delete ();
extern int pthreadCreateHook ();
extern int pthreadDeleteHook ();
extern int pthreadHookInit ();
extern int pthreadSwitchHook ();
extern int pthread_get_control_block ();
extern int pthread_getspecific ();
extern int pthread_key_create ();
extern int pthread_key_delete ();
extern int pthread_key_init ();
extern int pthread_key_mem_free ();
extern int pthread_key_mem_malloc ();
extern int pthread_setspecific ();
extern int pthreadKeyHook ();
extern int pthread_mutex_destroy ();
extern int pthread_mutex_getinfo ();
extern int pthread_mutex_getprioceiling ();
extern int pthread_mutex_init ();
extern int pthread_mutex_lock ();
extern int pthread_mutex_module_init ();
extern int pthread_mutex_show ();
extern int pthread_mutex_timedlock ();
extern int pthread_mutex_trylock ();
extern int pthread_mutex_unlock ();
extern int pthread_mutexattr_destroy ();
extern int pthread_mutexattr_getcancelsafe ();
extern int pthread_mutexattr_getprioceiling ();
extern int pthread_mutexattr_getprotocol ();
extern int pthread_mutexattr_getpshared ();
extern int pthread_mutexattr_gettype ();
extern int pthread_mutexattr_getwaitqtype ();
extern int pthread_mutexattr_init ();
extern int pthread_mutexattr_setcancelsafe ();
extern int pthread_mutexattr_setprioceiling ();
extern int pthread_mutexattr_setprotocol ();
extern int pthread_mutexattr_setpshared ();
extern int pthread_mutexattr_settype ();
extern int pthread_mutexattr_setwaitqtype ();
extern int pthread_once ();
extern int pthread_rwlock_destroy ();
extern int pthread_rwlock_getinfo ();
extern int pthread_rwlock_init ();
extern int pthread_rwlock_module_init ();
extern int pthread_rwlock_rdlock ();
extern int pthread_rwlock_timedrdlock ();
extern int pthread_rwlock_timedwrlock ();
extern int pthread_rwlock_tryrdlock ();
extern int pthread_rwlock_trywrlock ();
extern int pthread_rwlock_unlock ();
extern int pthread_rwlock_wrlock ();
extern int pthread_rwlockattr_destroy ();
extern int pthread_rwlockattr_getpshared ();
extern int pthread_rwlockattr_init ();
extern int pthread_rwlockattr_setpshared ();
extern int pthread_addvar ();
extern int pthread_delvar ();
extern int pthread_getvar ();
extern int pthread_setvar ();
extern int pthreadDeleteVarHook ();
extern int pthreadSwitchVarHook ();
extern int pthreadVarInit ();
extern int sched_get_priority_max ();
extern int sched_get_priority_min ();
extern int sched_getparam ();
extern int sched_getscheduler ();
extern int sched_gettimeslice ();
extern int sched_rr_get_interval ();
extern int sched_setparam ();
extern int sched_setscheduler ();
extern int sched_settimeslice ();
extern int sched_yield ();
extern int sem_close ();
extern int sem_destroy ();
extern int sem_flush ();
extern int sem_getinfo ();
extern int sem_getvalue ();
extern int sem_init ();
extern int sem_module_init ();
extern int sem_open ();
extern int sem_post ();
extern int sem_show ();
extern int sem_timedwait ();
extern int sem_trywait ();
extern int sem_unlink ();
extern int sem_wait ();
extern int kill ();
extern int pthread_kill ();
extern int raise ();
extern int sigaction ();
extern int sigaddset ();
extern int sigdelset ();
extern int sigemptyset ();
extern int sigfillset ();
extern int sighold ();
extern int sigignore ();
extern int sigismember ();
extern int signal ();
extern int signalsWaitQueue;
extern int sigpause ();
extern int sigpending ();
extern int sigprocmask ();
extern int sigqueue ();
extern int sigrelse ();
extern int sigsuspend ();
extern int sigtimedwait ();
extern int sigwait ();
extern int sigwaitinfo ();
extern int ttosDispatchSignal ();
extern int ttosInitTaskSignal ();
extern int ttosSignalInit ();
extern int ttosSigSuspendWait ();
extern int calcdiffNs ();
extern int clock_nanosleep ();
extern int clock_nanosleep_tasks_init ();
extern int modify_clock_nanosleep_task_ticks ();
extern int nanosleep ();
extern int nanosleep_task_hash_table;
extern int sleep ();
extern int usleep ();
extern int sysconf ();
extern int addSigevThreadSigCounts ();
extern int clockTimespecToTicks ();
extern int helpActiveTimer ();
extern int threadTimerID;
extern int ticks2Timespec ();
extern int timer_create ();
extern int timer_delete ();
extern int timer_getinfo ();
extern int timer_getoverrun ();
extern int timer_gettime ();
extern int timer_init ();
extern int timer_settime ();
extern int update_posix_timer ();
extern int wdg_cancel ();
extern int wdg_create ();
extern int wdg_delete ();
extern int wdg_getinfo ();
extern int wdg_init ();
extern int wdg_show ();
extern int wdg_start ();
extern int TTOS_CreateSema ();
extern int ttosInitSema ();
extern int ttosSemaIsMutex ();
extern int TTOS_DeleteSema ();
extern int TTOS_FlushSema ();
extern int TTOS_GetSemaCount ();
extern int TTOS_GetSemaExtendPointer ();
extern int TTOS_GetSemaID ();
extern int TTOS_GetSemaInfo ();
extern int TTOS_GetSemaIdList ();
extern int TTOS_GetSemaName ();
extern int TTOS_ObtainSema ();
extern int TTOS_ReleaseSema ();
extern int TTOS_SetSemaExtendPointer ();
extern int app_main ();
extern int AutoStartAPP ();
extern int CheckFilePath ();
extern int ShellStartAPP ();
extern int ShellStopAPP ();
extern int testAPPDynamicLoad ();
extern int testAPPDynamicLoadInit ();
extern int testShareLibDynamicLoadInit ();
extern int travel_app_from_dir ();
extern int TTOS_ActiveTask ();
extern int ttosClearTaskReady ();
extern int ttosClearTaskWaiting ();
extern int TTOS_CreateTask ();
extern int ttosInitTask ();
extern int ttosSetPWaitAndExpireTick ();
extern int taskDeleteSelfHandler ();
extern int TTOS_DeleteTask ();
extern int ttosDeleteHandlerTaskID;
extern int ttosDeleteTaskStackProtect ();
extern int ttosFreeStackRoutine;
extern int ttosSetFreeStackRoutine ();
extern int ttosTaskExit ();
extern int ttosDequeueFifo ();
extern int ttosDequeuePriority ();
extern int ttosDequeueTaskFromTaskq ();
extern int ttosDequeueTaskq ();
extern int ttosGetFirstPriorityTask ();
extern int TTOS_DisablePreempt ();
extern int TTOS_EnablePreempt ();
extern int ttosEnqueueFifo ();
extern int ttosEnqueuePriority ();
extern int ttosEnqueuePriorityFront ();
extern int ttosEnqueueTaskq ();
extern int ttosEnqueueTaskqPriorityFront ();
extern int ttosExactWaitedPeriodTask ();
extern int ttosExactWaitedTask ();
extern int ttosExtractTaskq ();
extern int TTOS_GetTaskContext ();
extern int TTOS_GetTaskCount ();
extern int TTOS_GetIdleTaskExecutedTicks ();
extern int TTOS_GetIdleTaskExecutedTicksWithCpuID ();
extern int TTOS_GetTaskExecutedTicks ();
extern int TTOS_SetTaskExecutedTicks ();
extern int TTOS_GetTaskID ();
extern int TTOS_GetTaskIdList ();
extern int TTOS_GetTaskInfo ();
extern int ttosGetTaskInfo ();
extern int TTOS_GetTaskName ();
extern int TTOS_GetTaskOriginPriority ();
extern int TTOS_GetTaskPriority ();
extern int TTOS_GetTaskStackInfo ();
extern int ttosTaskStackFilledFlag;
extern int TTOS_GetTaskState ();
extern int TTOS_GetTaskStdFd ();
extern int ttosInsertWaitedPeriodTask ();
extern int ttosInsertWaitedTask ();
extern int ttosPeriodExpireNotify ();
extern int expireWaitedQueueTmp;
extern int periodWaitedQueueTmp;
extern int ttosPeriodExpireQueueModify ();
extern int ttosPeriodQueueMerge ();
extern int ttosPeriodWaitQueueModify ();
extern int ttosPeriodWaitNotify ();
extern int TTOS_ReplenishTask ();
extern int TTOS_ResetTask ();
extern int TTOS_ResumeTask ();
extern int ttosDisableScheduleLevel;
extern int ttosGetCandidateTask ();
extern int ttosGlobalPriorityBitMap;
extern int ttosIsNeedRescheduleWithCpuId ();
extern int ttosPriorityBitMap;
extern int ttosSchedule ();
extern int ttosScheduleInIntDisAndKernelLock ();
extern int ttosScheduleInKernelLock ();
extern int TTOS_SetDelayTime ();
extern int ttosSetTaskReady ();
extern int TTOS_SetTaskStackProtect ();
extern int TTOS_SetTaskStdFd ();
extern int TTOS_Modify_SleepTask ();
extern int TTOS_NanoSleepTask ();
extern int TTOS_SleepTask ();
extern int TTOS_StopTask ();
extern int ttosInitTaskParam ();
extern int ttosStopTask ();
extern int TTOS_SuspendTask ();
extern int ttosSuspendTask ();
extern int posix_spawn ();
extern int ttosFlushTaskq ();
extern int ttosInitializeTaskq ();
extern int ttosTaskqIsEmpty ();
extern int _errno ();
extern int isRTaskNeedReSchedule ();
extern int occupy_tbl_get ();
extern int pthreadTickSlice;
extern int taskChangePriority ();
extern int TTOS_GetTaskAffinity ();
extern int TTOS_IsAllRunningAndCandidateTaskIdleTask ();
extern int TTOS_SetTaskAffinity ();
extern int ttosDisableTaskDispatch ();
extern int ttosDisableTaskDispatchWithLock ();
extern int ttosEnableTaskDispatch ();
extern int ttosEnableTaskDispatchWithLock ();
extern int ttosGetCurrentCpuRunningTask ();
extern int ttosGetIdleTask ();
extern int ttosGetIdleTaskWithCpuID ();
extern int ttosGetRunningTaskName ();
extern int ttosGetUnReserveCpuLowestRTask ();
extern int ttosGTaskRQueuePut ();
extern int ttosGTaskRQueueRemove ();
extern int ttosRotateRunningTask ();
extern int ttosSetTaskState ();
extern int ttosShowInfo ();
extern int ttosTaskStateChanged ();
extern int wait_tbl_get ();
extern int ttosTickNotify ();
extern int TTOS_WaitPeriod ();
extern int tbspInit ();
extern int TTOS_SetPageDisableCache ();
extern int TTOS_SetPageEnableCache ();
extern int cpuFreqGet ();
extern int cpuTimeGet ();
extern int jiffies;
extern int pexpireCurrentTicks;
extern int pexpireTicks;
extern int pwaitCurentTicks;
extern int pwaitTicks;
extern int tbspClockNotify ();
extern int tbspGetPExpireTick ();
extern int tbspGetPWaitTick ();
extern int tbspInitVTimer ();
extern int tbspSetPExpireTick ();
extern int tbspSetPWaitTick ();
extern int tickCount;
extern int tickIsrIpiReschedulecpus;
extern int TTOS_GetCurrentSystemCount ();
extern int TTOS_GetCurrentSystemFreq ();
extern int TTOS_GetCurrentSystemSubTime ();
extern int TTOS_GetCurrentSystemTime ();
extern int TTOS_GetOneCpuRunningTicks ();
extern int TTOS_GetRunningTicks ();
extern int TTOS_GetSysClkRate ();
extern int TTOS_GetSystemTicks ();
extern int TTOS_SetSysClkRate ();
extern int TTOS_SetSystemTicks ();
extern int ttosGetSystemTicks ();
extern int ttosTickCount;
extern int apStart ();
extern int fpscrAsmInit ();
extern int idleTaskEntryLoad ();
extern int tbspGetMSB ();
extern int tbspLoadStack ();
extern int tbspRestoreTaskContext ();
extern int tbspSaveTaskContext ();
extern int intCpuLock ();
extern int intCpuUnlock ();
extern int tbspClearGlobalInt ();
extern int tbspSetGlobalInt ();
extern int tbspApInitVint ();
extern int tbspInitVint ();
extern int tbspTickVIntNestLevel;
extern int tbspVIntNestLevel;
extern int tbspVintStackBottom;
extern int tbspVintStackStart;
extern int tbspVintStackTop;
extern int ttosDecTickIntNestLevel ();
extern int ttosGetIntNestLevel ();
extern int ttosGetIntStackBottom ();
extern int ttosGetIntStackStart ();
extern int ttosGetIntStackTop ();
extern int ttosGetTickIntNestLevel ();
extern int ttosIncTickIntNestLevel ();
extern int ttosMSRAdress;
extern int ttosSetIntStackBottom ();
extern int ttosSetIntStackStart ();
extern int ttosSetIntStackTop ();
extern int ttosSetMSRAdress ();
extern int tbspVintHandler ();
extern int cpu_down ();
extern int cpu_reserve ();
extern int cpu_unreserve ();
extern int cpu_up ();
extern int cpuEnabledNumGet ();
extern int cpuEnabledSetGet ();
extern int cpuNumGet ();
extern int cpuReservedSetGet ();
extern int ipiEmit ();
extern int ipiRescheduleEmit ();
extern int slaveCoreStackTop;
extern int smpInit ();
extern int ttosConfigCpuNum;
extern int ttosEnabledCpuSet;
extern int ttosReservedCpuSet;
extern int TTOS_MapAllocIOPage ();
extern int TTOS_MapIOPage ();
extern int TTOS_MapRamReadPage ();
extern int ttosMemProbeByteRead ();
extern int ttosMemProbeByteWrite ();
extern int ttosMemProbeErrorRtn ();
extern int ttosMemProbeLongRead ();
extern int ttosMemProbeLongWrite ();
extern int ttosMemProbeOnlyRead ();
extern int ttosMemProbeOnlyReadByte ();
extern int ttosMemProbeOnlyReadErrorRtn ();
extern int ttosMemProbeOnlyReadHalfWord ();
extern int ttosMemProbeOnlyReadWord ();
extern int ttosMemProbeOnlyWrite ();
extern int ttosMemProbeOnlyWriteByte ();
extern int ttosMemProbeOnlyWriteErrorRtn ();
extern int ttosMemProbeOnlyWriteHalfWord ();
extern int ttosMemProbeOnlyWriteWord ();
extern int ttosMemProbeSup ();
extern int ttosMemProbeWordRead ();
extern int ttosMemProbeWordWrite ();
extern int ttosMemProbeInit ();
extern int ttosMemReadCheck ();
extern int ttosMemRWCheck ();
extern int ttosMemTest ();
extern int ttosMemWriteCheck ();
extern int ttosVerifyObjectCore ();
extern int ttosVerifyObjectCoreError ();
extern int ttosVerifyObjectCoreMagicRead ();
extern int ttosVerifyObjectCoreTypeRead ();
extern int ttosObjArchLibInit ();
extern int osExcBaseHook;
extern int TTOS_AllocVector ();
extern int TTOS_DisablePIC ();
extern int TTOS_EnablePIC ();
extern int TTOS_ExceptionHandlerSet ();
extern int TTOS_InstallIntHandler ();
extern int TTOS_InstallSharedVintHandler ();
extern int TTOS_InstallVintHandler ();
extern int TTOS_MapExintToVint ();
extern int TTOS_SetIsrStackProtect ();
extern int TTOS_UnInstallSharedVintHandler ();
extern int TTOS_UninstallVintHandler ();
extern int ttosDispatchVint ();
extern int ttosExceptionDefaultHandler ();
extern int ttosExIntDefaultHandler ();
extern int ttosInstallVintHandlerWithParam ();
extern int ttosIsISR ();
extern int ttosIsTickISR ();
extern int ttosServIntDefaultHandler ();
extern int ttosTickIntDefaultHandler ();
extern int ttosUnInstallVintHandlerWithParam ();
extern int ttosVintDefaultHandlerInit ();
extern int TTOS_ActiveTimer ();
extern int TTOS_UpdateTimer ();
extern int TTOS_CreateTimer ();
extern int ttosInitTimer ();
extern int TTOS_DeleteTimer ();
extern int ttosExactWaitedTimer ();
extern int TTOS_GetTimerCount ();
extern int TTOS_GetTimerID ();
extern int TTOS_GetTimerIdList ();
extern int getTimerMaxNum ();
extern int TTOS_GetTimerInfo ();
extern int TTOS_GetTimerName ();
extern int TTOS_GetTimerState ();
extern int ttosInsertWaitedTimer ();
extern int TTOS_InstallTimer ();
extern int TTOS_SetTimerTicks ();
extern int TTOS_StopTimer ();
extern int ttosTimerNotify ();
extern int spin_lock ();
extern int spin_lock_disable_monitor ();
extern int spin_lock_enable_monitor ();
extern int spin_lock_init ();
extern int spin_lock_irq ();
extern int spin_lock_raw ();
extern int spin_trylock ();
extern int spin_trylock_irq ();
extern int spin_trylock_raw ();
extern int spin_unlock ();
extern int spin_unlock_irq ();
extern int spin_unlock_raw ();
extern int ttosIsKernelLockOwner ();
extern int ttosKernelLockInit ();
extern int ttosKernelLockVar;
extern int ttosCompareName ();
extern int ttosCompareVerison ();
extern int ttosCopyName ();
extern int ttosCopyVersion ();
extern int TTOS_GetKernelInfo ();
extern int TTOS_GetWaitLeastTicks ();
extern int ttosAllocateHeap ();
extern int ttosFreeHeap ();
extern int ttosInitHeap ();
extern int TTOS_ResetOs ();
extern int ttosConvertVMKReturnCode ();
extern int ttosCreateRingBuffer ();
extern int ttosGetRingBuffer ();
extern int ttosGetRingBufferEx ();
extern int ttosInitRingBuffer ();
extern int ttosPutRingBuffer ();
extern int ttosPutRingBufferEx ();
extern int ttosRingBufferDataBytes ();
extern int ttosRingBufferFreeBytes ();
extern int ttosRingBufferIsEmpty ();
extern int ttosRingBufferIsFull ();
extern int ttosAllocateObject ();
extern int ttosCopyString ();
extern int ttosGetIdByName ();
extern int ttosGetIdList ();
extern int ttosGetObjectById ();
extern int ttosGetObjectFromInactiveResource ();
extern int ttosInitObjectCore ();
extern int ttosInvalidObjectCore ();
extern int ttosObjectTypeIsOk ();
extern int ttosReturnObjectToInactiveResource ();
extern int ttosChangeName ();
extern int ttosVerifyName ();
extern int TTOS_IsDisableKernelHeap ();
extern int ttosFreeWorkspace ();
extern int ttosGetAvailableWorkspaceSize ();
extern int ttosGetTotalWorkspaceSize ();
extern int ttosInitWorkspace ();
extern int ttosIsDisableWorkspace ();
extern int ttosMallocWorkspace ();
extern int ttosMallocWorkspaceFatalError ();
extern int ttosMallocWorkspaceRaw ();
extern int TTOS_CreateShm ();
extern int TTOS_ReadShm ();
extern int TTOS_WriteShm ();
extern int ttosInitShm ();
extern int ttosShmErrno;
extern int ttosGetShmRingBuffer ();
extern int ttosPutShmRingBuffer ();
extern int ttosGetAvailableShmSize ();
extern int ttosInitShmWorkspace ();
extern int ttosMallocShmWorkspace ();
extern int allocate_shared_memory ();
extern int open_shared_memory ();
extern int shm_atomic32_cas ();
extern int shm_atomic32_get ();
extern int shm_atomic32_set ();
extern int shm_configure_system ();
extern int shm_init ();
extern int shm_initialize_system ();
extern int shm_start_addr;
extern int shm_system;
extern int shm_system_is_init ();
extern int shm_mem_region_alloc ();
extern int shm_mem_region_init ();
extern int shm_object_alloc ();
extern int shm_object_enqueue ();
extern int shm_object_find ();
extern int shm_object_free ();
extern int shm_object_pool_init ();
extern int shm_show ();
extern int shm_gettimeofday ();
extern int shm_mem_region_get ();
extern int shm_set_page_cache ();
extern int shm_timer_is_expired ();
extern int shm_timer_start ();
extern int shm_usleep ();
extern int fnFSC_Bread ();
extern int fnFSC_Brelse ();
extern int fnFSC_Cache_Init ();
extern int fnFSC_Clear_Device_cache ();
extern int fnFSC_Getblk ();
extern int fnFSC_Init_cache ();
extern int fnFSC_Mark_Buffer_Dirty ();
extern int fnFSC_Mark_Buffer_Uptodate ();
extern int fnFSC_Mark_File_Buffer_Dirty ();
extern int fnFSC_Refill_Freelist ();
extern int fnFSC_Sync_Buffer ();
extern int fnFSC_Sync_Buffers ();
extern int fnFSC_Sync_File ();
extern int fnFSC_Unlock_Buffer ();
extern int fnFSC_Wait_On_Buffer ();
extern int fnFSC_End_Buffer_Io_Hook ();
extern int fnFSC_Ll_Rw_Block ();
extern int fnFSC_PhysicDev_Operation ();
extern int fnDFS_checkdir ();
extern int fnDFS_close ();
extern int fnDFS_devinfo ();
extern int fnDFS_filelist ();
extern int fnDFS_fstat ();
extern int fnDFS_ftruncate ();
extern int fnDFS_getfd ();
extern int fnDFS_getFullPathByFd ();
extern int fnDFS_GetSysFirstLogDevChar ();
extern int fnDFS_ioctl ();
extern int fnDFS_lseek ();
extern int fnDFS_mkdir ();
extern int fnDFS_open ();
extern int fnDFS_read ();
extern int fnDFS_remove ();
extern int fnDFS_rename ();
extern int fnDFS_rmdir ();
extern int fnDFS_setfd ();
extern int fnDFS_stat ();
extern int fnDFS_utime ();
extern int fnDFS_write ();
extern int fnDFSAdm_FreeFNode ();
extern int fnDFSAdm_GetFNode ();
extern int fnDFSAdm_GetFreeFNode ();
extern int fnDFSAdm_GetLockLink ();
extern int fnDFSAdm_Init ();
extern int fnDFSAdm_LockFNode ();
extern int fnDFSAdm_UnlockFNode ();
extern int fnDFS_CreateSemaphore ();
extern int fnDFS_DeleteSemaphore ();
extern int fnDFS_FillFnodeDirInfo ();
extern int fnDFS_GetFullPath ();
extern int fnDFS_Init ();
extern int fnDFS_MkFS ();
extern int fnDFS_ObtainSemaphore ();
extern int fnDFS_PhysicDevOpen ();
extern int fnDFS_PhysicDevRead ();
extern int fnDFS_PhysicDevWrite ();
extern int fnDFS_ReleaseSemaphore ();
extern int fnFAT_Bind ();
extern int fnFAT_Unbind ();
extern int uwaDFSSemID;
extern int fnDFS_AddLDCB ();
extern int fnDFS_AddPDCB ();
extern int fnDFS_AllocatePDCB ();
extern int fnDFS_DelLDCB ();
extern int fnDFS_FreePDCB ();
extern int fnDFS_GetDevLetterWithPDCBAndIndex ();
extern int fnDFS_GetLDCB ();
extern int fnDFS_GetLDCBNumber ();
extern int fnDFS_GetLDCBWithChar ();
extern int fnDFS_GetNewDevChar ();
extern int fnDFS_GetPDev ();
extern int fnDFS_InitDev ();
extern int fnDFS_freeDmaMemPage ();
extern int fnDFS_mallocDmaMemPage ();
extern int fnDFS_Err2Errno ();
extern int waDFSErrorTable;
extern int fnDFS_DestroyFatBuf ();
extern int fnDFS_InitFatBuf ();
extern int ACoreOs_DFS_format ();
extern int ACoreOs_DFS_init ();
extern int tpFAT_SyncDir;
extern int tpFAT_SyncFat;
extern int ACoreOs_DFS_get_dev_letter_by_partion_index ();
extern int ACoreOs_DFS_mount ();
extern int ACoreOs_DFS_umount ();
extern int devSysstartchar;
extern int DFS_GetDevSymbol ();
extern int DFS_InitDrvBitmap ();
extern int fnDFS_TodToSeconds ();
extern int uwaDFS_TOD_Days_to_date;
extern int fnFAT16_AddOldName_ForRoot ();
extern int fnFAT16_AddToDirEntry_ForRoot ();
extern int fnFAT16_CloseDir ();
extern int fnFAT16_FindDelEntry_ForRoot ();
extern int fnFAT16_FindEntryInDirectory ();
extern int fnFAT16_GetFileNum_ForRoot ();
extern int fnFAT16_InitDPB ();
extern int fnFAT16_InsertEntry_ForRoot ();
extern int fnFAT16_LinkFatEntry ();
extern int fnFAT16_NextCluster ();
extern int fnFAT16_OpenDir ();
extern int fnFAT16_WriteDir_ForRoot ();
extern int fnFAT16_WriteDirEntry_ForRoot ();
extern int fnFAT_DirCheck ();
extern int fnFAT_FileClose ();
extern int fnFAT_FileCreate ();
extern int fnFAT_FileDelete ();
extern int fnFAT_FileOpen ();
extern int fnFAT_FileRead ();
extern int fnFAT_FileWrite ();
extern int fnFAT_GetDevInfo ();
extern int fnFAT_GetFileList ();
extern int fnFAT_MakeDir ();
extern int fnFAT_RemoveDir ();
extern int FAT32_Is_LongName ();
extern int fnFAT32_CloseDir ();
extern int fnFAT32_FindEntryInDirectory ();
extern int fnFAT32_InitDPB ();
extern int fnFAT32_LinkFatEntry ();
extern int fnFAT32_NextCluster ();
extern int fnFAT32_OpenDir ();
extern int fnFAT_MakeFS ();
extern int fnFAT_BytesToUHWord ();
extern int fnFAT_BytesToWord ();
extern int fnFAT_CheckDPB ();
extern int fnFAT_DestroyDev ();
extern int fnFAT_DevInit ();
extern int FAT_toUpperCase ();
extern int fnFAT_AddOldName_NotForRoot ();
extern int fnFAT_AddToDirEntry_NotForRoot ();
extern int fnFAT_CleanUpDirEntry ();
extern int fnFAT_Cluster2Sector ();
extern int fnFAT_ConvertToFATName ();
extern int fnFAT_DeleteFromDirEntry ();
extern int fnFAT_DeleteOldEntry ();
extern int fnFAT_ExtractFileName ();
extern int fnFAT_FileRename ();
extern int fnFAT_FillLongName2info ();
extern int fnFAT_FillShortName2info ();
extern int fnFAT_FindChar ();
extern int fnFAT_FindDeletedEntry ();
extern int fnFAT_FindDirtyEntry ();
extern int fnFAT_FindEntry_ForShortName ();
extern int fnFAT_FindEntryByIndex ();
extern int fnFAT_FindFreeCluster ();
extern int fnFAT_FindUnusedEntry ();
extern int fnFAT_GetDate ();
extern int fnFAT_GetDirEntry ();
extern int fnFAT_GetFileNum_NotForRoot ();
extern int fnFAT_GetLongName ();
extern int fnFAT_GetNextEntry ();
extern int fnFAT_GetPreviousEntry ();
extern int fnFAT_GetShortName ();
extern int fnFAT_GetTime ();
extern int fnFAT_InsertEntries_NotForRoot ();
extern int fnFAT_IsInUsed ();
extern int fnFAT_NeedLFNEntry ();
extern int fnFAT_ObtainLdcbSem ();
extern int fnFAT_PutDirEntry ();
extern int fnFAT_ReadBlock ();
extern int fnFAT_ReleaseLdcbSem ();
extern int fnFAT_SetCluster ();
extern int fnFAT_SetFileSize ();
extern int fnFAT_UpdataDirAndData ();
extern int fnFAT_WipeOutFatEntry ();
extern int fnFAT_WriteBlock ();
extern int fnFAT_WriteDir_NotForRoot ();
extern int fnFAT_WriteDirEntry ();
extern int fnFAT_ConvertStrToUnicode ();
extern int fnFAT_ConvertUnicodeToStr ();
extern int fnMBC_Destroy ();
extern int fnMBC_Flush_Dirty_Buffers ();
extern int fnMBC_Init ();
extern int fnMBC_Operation ();
extern int fnMBC_Sync_Dirty_Buffer ();
extern int MBC_Flush_Dirty_Buffer ();
extern int MBC_Get_Free_Item ();
extern int MBC_GetBlk ();
extern int MBC_Map_Buffer ();
extern int MBC_PhysicDev_Operation ();
extern int MBC_Recycle_Bh ();
extern int MBC_Search_Item_In_Lru_List ();
extern int format ();
extern int mount ();
extern int sys_fs_type;
extern int umount ();
extern int dm_chain_get_node ();
extern int dm_chain_initialize ();
extern int dm_add_dev ();
extern int dm_delete_dev ();
extern int _dm_dev_find ();
extern int dm_find_dev ();
extern int _dm_dev_name_get ();
extern int dev_display ();
extern int dm_dev_iterator ();
extern int dm_dev_show ();
extern int dm_find_root ();
extern int dm_print_dev ();
extern int find_mount_dir ();
extern int type_to_typename ();
extern int dm_install_drv ();
extern int dm_uninstall_drv ();
extern int dm_fat_path_check ();
extern int dm_fd_value ();
extern int dm_initialization ();
extern int dmInitFlag;
extern int dmManager;
extern int _dm_lock ();
extern int _dm_lock_creat ();
extern int _dm_lock_delete ();
extern int _dm_unlock ();
extern int dm_mknod ();
extern int dm_rtos_filesystem_make_dev_t ();
extern int _dm_dev_info ();
extern int _dm_fd_free ();
extern int _dm_fd_info ();
extern int _dm_fd_value_set ();
extern int _dm_free_fd_get ();
extern int _dm_object_name_is_valid ();
extern int _dm_path_get ();
extern int _dm_path_set ();
extern int _string_copy_memory ();
extern int _string_get_objname_length ();
extern int _string_set_memory ();
extern int _dm_io_creat_open ();
extern int _syscall_close ();
extern int _syscall_creat ();
extern int _string_compare_objname ();
extern int _syscall_ioctl ();
extern int _syscall_maxfd ();
extern int _syscall_open ();
extern int _syscall_read ();
extern int _syscall_write ();
extern int register_device ();
extern int register_driver ();
extern int unregister_device ();
extern int unregister_driver ();
extern int smipc_accept ();
extern int smipc_bind ();
extern int smipc_close ();
extern int smipc_connect ();
extern int smipc_getactivenodes ();
extern int smipc_getbusbyname ();
extern int smipc_getbusmaxnodes ();
extern int smipc_getnamebybus ();
extern int smipc_getnodebybus ();
extern int smipc_getpeername ();
extern int smipc_getsockname ();
extern int smipc_getsockopt ();
extern int smipc_getstats ();
extern int smipc_listen ();
extern int smipc_recv ();
extern int smipc_recvfrom ();
extern int smipc_rx_callback ();
extern int smipc_send ();
extern int smipc_sendto ();
extern int smipc_setsockopt ();
extern int smipc_shutdown ();
extern int smipc_socket ();
extern int smipc_zalloc ();
extern int smipc_zfree ();
extern int smipc_zrecv ();
extern int smipc_zrecvfrom ();
extern int smipc_zsend ();
extern int smipc_zsendto ();
extern int smipc_bus_default;
extern int smipc_bus_get ();
extern int smipc_bus_init ();
extern int smipc_get_buses ();
extern int smipc_max_buses;
extern int smipc_stats_get ();
extern int smipc_sys_signature;
extern int smipcBuses;
extern int smipcLocalBusInfo;
extern int smipcSystem;
extern int smipc_display_bus ();
extern int smipc_display_node ();
extern int smipc_display_port ();
extern int smipc_display_stats ();
extern int smipc_display_system ();
extern int smipc_basic_event_alloc ();
extern int smipc_basic_event_send ();
extern int smipc_event_alloc ();
extern int smipc_event_free ();
extern int smipc_event_pool_init ();
extern int smipc_api_process_rx_events ();
extern int smipc_event_send ();
extern int get_smipc_priority ();
extern int get_smipc_stack_size ();
extern int set_smipc_priority ();
extern int set_smipc_stack_size ();
extern int smipc_config;
extern int smipc_cpu_id;
extern int smipc_init ();
extern int smipc_initialized;
extern int smipc_node_id;
extern int smipcInit ();
extern int smipcStartAddr;
extern int smipc_mem_region_alloc ();
extern int smipc_mem_region_init ();
extern int smipc_node_down ();
extern int smipc_node_get ();
extern int smipc_node_get_valid ();
extern int smipc_node_heartbeat_task ();
extern int smipc_node_init ();
extern int smipc_node_is_up ();
extern int smipc_node_peer_audit ();
extern int smipc_node_pool_audit ();
extern int smipc_node_send_internal_event ();
extern int smipc_node_up ();
extern int smipc_reset_state;
extern int smipc_packet_alloc ();
extern int smipc_packet_free ();
extern int smipc_packet_free_all ();
extern int smipc_packet_pool_init ();
extern int smipc_txbuf_is_avail ();
extern int smipc_dummy_port;
extern int smipc_port_alloc ();
extern int smipc_port_buffer_is_avail ();
extern int smipc_port_bufs_alloc ();
extern int smipc_port_free ();
extern int smipc_port_get ();
extern int smipc_port_init ();
extern int smipc_port_packet_get ();
extern int smipc_port_packet_put ();
extern int smipc_port_packets_free ();
extern int smipc_sock_init ();
extern int smipc_socket_alloc ();
extern int smipc_socket_free ();
extern int smipc_socket_init ();
extern int smipc_socket_packet_queue ();
extern int smipc_socket_wait ();
extern int smipcAllSockets;
extern int smipcMaxSockets;
extern int smipcUserHandles;
extern int smipc_adapt_get_cpu_id ();
extern int smipc_adapt_get_node_id ();
extern int smipc_adapt_notify_node ();
extern int netconn_accept ();
extern int netconn_bind ();
extern int netconn_close ();
extern int netconn_connect ();
extern int netconn_delete ();
extern int netconn_disconnect ();
extern int netconn_getaddr ();
extern int netconn_gethostbyname ();
extern int netconn_join_leave_group ();
extern int netconn_listen_with_backlog ();
extern int netconn_new_with_proto_and_callback ();
extern int netconn_recv ();
extern int netconn_recv_tcp_pbuf ();
extern int netconn_send ();
extern int netconn_sendto ();
extern int netconn_shutdown ();
extern int netconn_write_partly ();
extern int lwip_netconn_do_accepted ();
extern int lwip_netconn_do_bind ();
extern int lwip_netconn_do_close ();
extern int lwip_netconn_do_connect ();
extern int lwip_netconn_do_delconn ();
extern int lwip_netconn_do_disconnect ();
extern int lwip_netconn_do_getaddr ();
extern int lwip_netconn_do_gethostbyname ();
extern int lwip_netconn_do_join_leave_group ();
extern int lwip_netconn_do_listen ();
extern int lwip_netconn_do_newconn ();
extern int lwip_netconn_do_recv ();
extern int lwip_netconn_do_send ();
extern int lwip_netconn_do_write ();
extern int netconn_aborted;
extern int netconn_alloc ();
extern int netconn_free ();
extern int err_to_errno ();
extern int lwip_strerr ();
extern int netbuf_alloc ();
extern int netbuf_chain ();
extern int netbuf_data ();
extern int netbuf_delete ();
extern int netbuf_first ();
extern int netbuf_free ();
extern int netbuf_new ();
extern int netbuf_next ();
extern int netbuf_ref ();
extern int h_errno;
extern int lwip_freeaddrinfo ();
extern int lwip_getaddrinfo ();
extern int lwip_gethostbyname ();
extern int lwip_gethostbyname_r ();
extern int available_sockets;
extern int get_user_config_socket_offset ();
extern int lwip_accept ();
extern int lwip_bind ();
extern int lwip_close ();
extern int lwip_connect ();
extern int lwip_fcntl ();
extern int lwip_getpeername ();
extern int lwip_getsockname ();
extern int lwip_getsockopt ();
extern int lwip_ioctl ();
extern int lwip_listen ();
extern int lwip_read ();
extern int lwip_recv ();
extern int lwip_recvfrom ();
extern int lwip_select ();
extern int lwip_send ();
extern int lwip_sendmsg ();
extern int lwip_sendto ();
extern int lwip_setsockopt ();
extern int lwip_shutdown ();
extern int lwip_socket ();
extern int lwip_socket_thread_cleanup ();
extern int lwip_socket_thread_init ();
extern int lwip_write ();
extern int lwip_writev ();
extern int set_user_config_socket_offset ();
extern int socket_ipv4_multicast_memberships;
extern int get_lwip_priority ();
extern int get_lwip_stack_size ();
extern int mem_free_callback ();
extern int pbuf_free_callback ();
extern int set_lwip_priority ();
extern int set_lwip_stack_size ();
extern int tcpip_api_call ();
extern int tcpip_callback_with_block ();
extern int tcpip_callbackmsg_delete ();
extern int tcpip_callbackmsg_new ();
extern int tcpip_init ();
extern int tcpip_inpkt ();
extern int tcpip_input ();
extern int tcpip_send_msg_wait_sem ();
extern int tcpip_thread_attr_set ();
extern int tcpip_trycallback ();
extern int ping_send ();
extern int arch_protect_mutex;
extern int raw_sem_wait ();
extern int sys_arch_mbox_fetch ();
extern int sys_arch_mbox_fetch_ex ();
extern int sys_arch_mbox_tryfetch ();
extern int sys_arch_sem_wait ();
extern int sys_hook_unknown_eth_protocol ();
extern int sys_init ();
extern int sys_mbox_free ();
extern int sys_mbox_new ();
extern int sys_mbox_new_ex ();
extern int sys_mbox_post ();
extern int sys_mbox_set_invalid ();
extern int sys_mbox_trypost ();
extern int sys_mbox_valid ();
extern int sys_mutex_free ();
extern int sys_mutex_lock ();
extern int sys_mutex_new ();
extern int sys_mutex_unlock ();
extern int sys_now ();
extern int sys_sem_free ();
extern int sys_sem_new ();
extern int sys_sem_set_invalid ();
extern int sys_sem_signal ();
extern int sys_sem_valid ();
extern int sys_thread_new ();
extern int gethostbyaddr ();
extern int change_string_addr_to_int_addr ();
extern int get_broadcast_address ();
extern int get_netif_name_from_minor ();
extern int get_nic_param ();
extern int if_show ();
extern int ifconfig ();
extern int mbuf_show ();
extern int routes_show ();
extern int set_nic_param ();
extern int tcp_show ();
extern int udp_show ();
extern int recvmsg ();
extern int lwip_itoa ();
extern int lwip_stricmp ();
extern int lwip_strnicmp ();
extern int lwip_strnstr ();
extern int dns_gethostbyname ();
extern int dns_gethostbyname_addrtype ();
extern int dns_getserver ();
extern int dns_init ();
extern int dns_mquery_v4group;
extern int dns_setserver ();
extern int dns_tmr ();
extern int inet_chksum ();
extern int inet_chksum_pbuf ();
extern int inet_chksum_pseudo ();
extern int inet_chksum_pseudo_partial ();
extern int ip_chksum_pseudo ();
extern int ip_chksum_pseudo_partial ();
extern int lwip_standard_chksum ();
extern int ip_data;
extern int lwip_init ();
extern int mem_calloc ();
extern int mem_free ();
extern int mem_init ();
extern int mem_malloc ();
extern int mem_trim ();
extern int memp_ARP_QUEUE;
extern int memp_FRAG_PBUF;
extern int memp_free ();
extern int memp_free_pool ();
extern int memp_IGMP_GROUP;
extern int memp_init ();
extern int memp_init_pool ();
extern int memp_malloc ();
extern int memp_malloc_pool ();
extern int memp_NETBUF;
extern int memp_NETCONN;
extern int memp_NETDB;
extern int memp_PBUF;
extern int memp_PBUF_POOL;
extern int memp_pools;
extern int memp_RAW_PCB;
extern int memp_REASSDATA;
extern int memp_SYS_TIMEOUT;
extern int memp_TCP_PCB;
extern int memp_TCP_PCB_LISTEN;
extern int memp_TCP_SEG;
extern int memp_TCPIP_MSG_API;
extern int memp_TCPIP_MSG_INPKT;
extern int memp_UDP_PCB;
extern int if_indextoname ();
extern int if_nametoindex ();
extern int netif_add ();
extern int netif_add_static_route_item ();
extern int netif_alloc_client_data_id ();
extern int netif_default;
extern int netif_find ();
extern int netif_init ();
extern int netif_input ();
extern int netif_list;
extern int netif_loop_output ();
extern int netif_poll ();
extern int netif_remove ();
extern int netif_set_addr ();
extern int netif_set_default ();
extern int netif_set_down ();
extern int netif_set_gw ();
extern int netif_set_ipaddr ();
extern int netif_set_link_callback ();
extern int netif_set_link_down ();
extern int netif_set_link_up ();
extern int netif_set_netmask ();
extern int netif_set_status_callback ();
extern int netif_set_up ();
extern int pbuf_alloc ();
extern int pbuf_alloced_custom ();
extern int pbuf_cat ();
extern int pbuf_chain ();
extern int pbuf_clen ();
extern int pbuf_coalesce ();
extern int pbuf_copy ();
extern int pbuf_copy_partial ();
extern int pbuf_dechain ();
extern int pbuf_free ();
extern int pbuf_free_ooseq_pending;
extern int pbuf_get_at ();
extern int pbuf_header ();
extern int pbuf_header_force ();
extern int pbuf_memcmp ();
extern int pbuf_memfind ();
extern int pbuf_put_at ();
extern int pbuf_realloc ();
extern int pbuf_ref ();
extern int pbuf_skip ();
extern int pbuf_strstr ();
extern int pbuf_take ();
extern int pbuf_take_at ();
extern int pbuf_try_get_at ();
extern int raw_bind ();
extern int raw_connect ();
extern int raw_input ();
extern int raw_netif_ip_addr_changed ();
extern int raw_new ();
extern int raw_new_ip_type ();
extern int raw_recv ();
extern int raw_remove ();
extern int raw_send ();
extern int raw_sendto ();
extern int brief_of_netif ();
extern int etharp_stats_display ();
extern int find_netif ();
extern int icmp_stats_display ();
extern int ip_stats_display ();
extern int link_stats_display ();
extern int lwip_stats;
extern int memp_stats_display ();
extern int netif_show ();
extern int netifShowHook ();
extern int print_ip ();
extern int set_default_netif ();
extern int set_netif ();
extern int socket_stats_display ();
extern int stats_display ();
extern int stats_display_igmp ();
extern int stats_display_mem ();
extern int stats_display_memp ();
extern int stats_display_proto ();
extern int stats_init ();
extern int switchNicType ();
extern int tcp_stats_display ();
extern int udp_stats_display ();
extern int sys_msleep ();
extern int tcp_abandon ();
extern int tcp_abort ();
extern int tcp_accept ();
extern int tcp_active_pcbs;
extern int tcp_active_pcbs_changed;
extern int tcp_alloc ();
extern int tcp_arg ();
extern int tcp_backlog_accepted ();
extern int tcp_backlog_delayed ();
extern int tcp_bind ();
extern int tcp_bound_pcbs;
extern int tcp_close ();
extern int tcp_connect ();
extern int tcp_debug_state_str ();
extern int tcp_eff_send_mss_impl ();
extern int tcp_err ();
extern int tcp_fasttmr ();
extern int tcp_init ();
extern int tcp_listen_pcbs;
extern int tcp_listen_with_backlog ();
extern int tcp_listen_with_backlog_and_err ();
extern int tcp_netif_ip_addr_changed ();
extern int tcp_new ();
extern int tcp_new_ip_type ();
extern int tcp_next_iss ();
extern int tcp_pcb_lists;
extern int tcp_pcb_purge ();
extern int tcp_pcb_remove ();
extern int tcp_poll ();
extern int tcp_process_refused_data ();
extern int tcp_recv ();
extern int tcp_recv_null ();
extern int tcp_recved ();
extern int tcp_seg_copy ();
extern int tcp_seg_free ();
extern int tcp_segs_free ();
extern int tcp_sent ();
extern int tcp_setprio ();
extern int tcp_shutdown ();
extern int tcp_slowtmr ();
extern int tcp_ticks;
extern int tcp_tmr ();
extern int tcp_tw_pcbs;
extern int tcp_txnow ();
extern int tcp_update_rcv_ann_wnd ();
extern int tcp_input ();
extern int tcp_input_pcb;
extern int tcp_trigger_input_pcb_close ();
extern int tcp_enqueue_flags ();
extern int tcp_keepalive ();
extern int tcp_output ();
extern int tcp_rexmit ();
extern int tcp_rexmit_fast ();
extern int tcp_rexmit_rto ();
extern int tcp_rst ();
extern int tcp_send_empty_ack ();
extern int tcp_send_fin ();
extern int tcp_write ();
extern int tcp_zero_window_probe ();
extern int lwip_cyclic_timers;
extern int sys_restart_timeouts ();
extern int sys_timeout ();
extern int sys_timeouts_init ();
extern int sys_timeouts_mbox_fetch ();
extern int sys_untimeout ();
extern int tcp_timer_needed ();
extern int udp_bind ();
extern int udp_connect ();
extern int udp_disconnect ();
extern int udp_init ();
extern int udp_input ();
extern int udp_netif_ip_addr_changed ();
extern int udp_new ();
extern int udp_new_ip_type ();
extern int udp_pcbs;
extern int udp_recv ();
extern int udp_remove ();
extern int udp_send ();
extern int udp_sendto ();
extern int udp_sendto_if ();
extern int udp_sendto_if_src ();
extern int dhcp_arp_reply ();
extern int dhcp_cleanup ();
extern int dhcp_coarse_tmr ();
extern int dhcp_fine_tmr ();
extern int dhcp_inform ();
extern int dhcp_network_changed ();
extern int dhcp_release ();
extern int dhcp_renew ();
extern int dhcp_rx_options_given;
extern int dhcp_rx_options_val;
extern int dhcp_set_struct ();
extern int dhcp_start ();
extern int dhcp_stop ();
extern int dhcp_supplied_address ();
extern int etharp_cleanup_netif ();
extern int etharp_find_addr ();
extern int etharp_get_entry ();
extern int etharp_input ();
extern int etharp_output ();
extern int etharp_query ();
extern int etharp_request ();
extern int etharp_tmr ();
extern int show_allocedarp_nums ();
extern int icmp_dest_unreach ();
extern int icmp_input ();
extern int icmp_time_exceeded ();
extern int igmp_init ();
extern int igmp_input ();
extern int igmp_joingroup ();
extern int igmp_joingroup_netif ();
extern int igmp_leavegroup ();
extern int igmp_leavegroup_netif ();
extern int igmp_lookfor_group ();
extern int igmp_report_groups ();
extern int igmp_start ();
extern int igmp_stop ();
extern int igmp_tmr ();
extern int ip4_input ();
extern int ip4_output ();
extern int ip4_output_hinted ();
extern int ip4_output_if ();
extern int ip4_output_if_opt ();
extern int ip4_output_if_opt_src ();
extern int ip4_output_if_src ();
extern int ip4_route ();
extern int ip4_route_src ();
extern int ip4_set_default_multicast_netif ();
extern int lwip_hook_ip4_route_src ();
extern int ip_addr_any;
extern int ip_addr_broadcast;
extern int ip4_addr_isbroadcast_u32 ();
extern int ip4_addr_netmask_valid ();
extern int ip4addr_aton ();
extern int ip4addr_ntoa ();
extern int ip4addr_ntoa_r ();
extern int ipaddr_addr ();
extern int ip_reass_tmr ();
extern int ip4_frag ();
extern int ip4_reass ();
extern int ethbroadcast;
extern int ethernet_input ();
extern int ethernet_output ();
extern int ethzero;
extern int ip4_static_route ();
extern int slipif_init ();
extern int slipif_loop_thread_attr_set ();
extern int slipif_poll ();
extern int getCurrentVmNicStructAddr ();
extern int getCurrentVmUSBStructAddr ();
extern int NicGetInfoByName ();
extern int TTOS_GetAllHardDiskInfo ();
extern int TTOS_GetFreeMemorySize ();
extern int TTOS_GetFunctionInfo ();
extern int TTOS_GetLogicalAddressByName ();
extern int TTOS_GetNicNameList ();
extern int TTOS_GetNicStatusInfo ();
extern int TTOS_GetNicTotalNum ();
extern int TTOS_GetOSInfo ();
extern int TTOS_GetStaticRouteTableInfo ();
extern int TTOS_GetSystemLoggerModel ();
extern int TTOS_GetTotalMemorySize ();
extern int TTOS_GetUSBTotalNum ();
extern int TTOS_GetVMInternalInfo ();
extern int TTOS_ReStartVM ();
extern int TTOS_ReStartVMByImage ();
extern int TTOS_SetFunctionInfo ();
extern int TTOS_SetOSInfo ();
extern int USBGetInfoByName ();
extern int get_dev_agent_priority ();
extern int get_dev_agent_stack_size ();
extern int set_dev_agent_priority ();
extern int set_dev_agent_stack_size ();
extern int TTOS_InitDevInfoAgent ();
extern int getDevID ();
extern int vmCpuId;
extern int vmDiskSz;
extern int VMM_ControlVM ();
extern int VMM_GetCpuIDs ();
extern int VMM_GetCPUMainFrameTicks ();
extern int VMM_GetDeviceMemorySize ();
extern int VMM_GetDeviceName ();
extern int VMM_GetDeviceNicTotalNum ();
extern int VMM_GetNicMacRange ();
extern int VMM_GetVMBasicInfo ();
extern int VMM_GetVMInfo ();
extern int VMM_GetVMNicDefaultConfig ();
extern int VMM_GetVMNicTotalNum ();
extern int VMM_GetVMTotalNum ();
extern int VMM_GetVscInfo ();
extern int vmMemSz;
struct symtab_s rtpSymtab [2391] =
    {
        { "atomic_add", (char*) atomic_add  },
        { "atomic_and", (char*) atomic_and  },
        { "atomic_cmpxchg", (char*) atomic_cmpxchg  },
        { "atomic_dec", (char*) atomic_dec  },
        { "atomic_inc", (char*) atomic_inc  },
        { "atomic_or", (char*) atomic_or  },
        { "atomic_read", (char*) atomic_read  },
        { "atomic_set", (char*) atomic_set  },
        { "atomic_sub", (char*) atomic_sub  },
        { "atomic_xor", (char*) atomic_xor  },
        { "debugEventDisableRecord", (char*) debugEventDisableRecord  },
        { "debugEventEnableRecord", (char*) debugEventEnableRecord  },
        { "debugEventInit", (char*) debugEventInit  },
        { "debugEventRecord", (char*) debugEventRecord  },
        { "debugEventShow", (char*) debugEventShow  },
        { "delayMS", (char*) delayMS  },
        { "delayUS", (char*) delayUS  },
        { "getCurrentSystemCount", (char*) getCurrentSystemCount  },
        { "getCurrentSystemFreq", (char*) getCurrentSystemFreq  },
        { "getCurrentSystemSubTime", (char*) getCurrentSystemSubTime  },
        { "getCurrentSystemTime", (char*) getCurrentSystemTime  },
        { "memAlignClear", (char*) memAlignClear  },
        { "memAlignCpy", (char*) memAlignCpy  },
        { "wordBitSetCountGet", (char*) wordBitSetCountGet  },
        { "wordMSBGet", (char*) wordMSBGet  },
        { "wordMSBGetAndClear", (char*) wordMSBGetAndClear  },
        { "__vring_new_virtqueue", (char*) __vring_new_virtqueue  },
        { "get_avail_buf_of_virtqueue", (char*) get_avail_buf_of_virtqueue  },
        { "sm_virtqueue_add", (char*) sm_virtqueue_add  },
        { "sm_virtqueue_get_buf_ctx", (char*) sm_virtqueue_get_buf_ctx  },
        { "sm_vring_create_virtqueue", (char*) sm_vring_create_virtqueue  },
        { "vnet_alloc_queues", (char*) vnet_alloc_queues  },
        { "vnet_find_vqs", (char*) vnet_find_vqs  },
        { "vnet_init_vqs", (char*) vnet_init_vqs  },
        { "vnet_setup_vq", (char*) vnet_setup_vq  },
        { "vnet_vp_find_vqs", (char*) vnet_vp_find_vqs  },
        { "vring_alloc_queue", (char*) vring_alloc_queue  },
        { "vring_free_queue", (char*) vring_free_queue  },
        { "atomic32Add", (char*) atomic32Add  },
        { "atomic32And", (char*) atomic32And  },
        { "atomic32Cas", (char*) atomic32Cas  },
        { "atomic32Clear", (char*) atomic32Clear  },
        { "atomic32Dec", (char*) atomic32Dec  },
        { "atomic32Get", (char*) atomic32Get  },
        { "atomic32Inc", (char*) atomic32Inc  },
        { "atomic32Nand", (char*) atomic32Nand  },
        { "atomic32Or", (char*) atomic32Or  },
        { "atomic32Set", (char*) atomic32Set  },
        { "atomic32Sub", (char*) atomic32Sub  },
        { "atomic32Xor", (char*) atomic32Xor  },
        { "vmCpuIDGet", (char*) vmCpuIDGet  },
        { "vmGlobalIntEnMaskClear", (char*) vmGlobalIntEnMaskClear  },
        { "vmGlobalIntEnMaskGet", (char*) vmGlobalIntEnMaskGet  },
        { "vmGlobalIntEnMaskGetAndClear", (char*) vmGlobalIntEnMaskGetAndClear  },
        { "vmGlobalIntEnMaskSet", (char*) vmGlobalIntEnMaskSet  },
        { "zeroNumOfLongGet", (char*) zeroNumOfLongGet  },
        { "zeroNumOfWordGet", (char*) zeroNumOfWordGet  },
        { "cacheIsEnable", (char*) cacheIsEnable  },
        { "fppRegisterInitValue", (char*) &fppRegisterInitValue  },
        { "fpscrInit", (char*) fpscrInit  },
        { "intNumSet", (char*) intNumSet  },
        { "showExcInfo", (char*) showExcInfo  },
        { "wordLSBGet", (char*) wordLSBGet  },
        { "fppRestoreContext", (char*) fppRestoreContext  },
        { "fppSaveContext", (char*) fppSaveContext  },
        { "spinLockAsm", (char*) spinLockAsm  },
        { "spinUnlockAsm", (char*) spinUnlockAsm  },
        { "spinLockRaw", (char*) spinLockRaw  },
        { "spinUnlockRaw", (char*) spinUnlockRaw  },
        { "spinLockAsm", (char*) spinLockAsm  },
        { "spinUnlockAsm", (char*) spinUnlockAsm  },
        { "dl_lock", (char*) &dl_lock  },
        { "dladdr", (char*) dladdr  },
        { "dlclose", (char*) dlclose  },
        { "dlerror", (char*) dlerror  },
        { "dlopen", (char*) dlopen  },
        { "dlsym", (char*) dlsym  },
        { "libdl_info", (char*) &libdl_info  },
        { "addr_to_name", (char*) addr_to_name  },
        { "app_find_sym_in_dl", (char*) app_find_sym_in_dl  },
        { "dl_unwind_find_exidx", (char*) dl_unwind_find_exidx  },
        { "find_containing_library", (char*) find_containing_library  },
        { "find_containing_symbol", (char*) find_containing_symbol  },
        { "find_library", (char*) find_library  },
        { "ide_load_all_library", (char*) ide_load_all_library  },
        { "ide_load_single_library", (char*) ide_load_single_library  },
        { "lookup", (char*) lookup  },
        { "lookup_in_library", (char*) lookup_in_library  },
        { "read_library", (char*) read_library  },
        { "unload_library", (char*) unload_library  },
        { "rtld_db_dlactivity", (char*) rtld_db_dlactivity  },
        { "_ctype_", (char*) &_ctype_  },
        { "isalnum", (char*) isalnum  },
        { "isalpha", (char*) isalpha  },
        { "isascii", (char*) isascii  },
        { "iscntrl", (char*) iscntrl  },
        { "isdigit", (char*) isdigit  },
        { "islower", (char*) islower  },
        { "isgraph", (char*) isgraph  },
        { "isprint", (char*) isprint  },
        { "ispunct", (char*) ispunct  },
        { "isspace", (char*) isspace  },
        { "isupper", (char*) isupper  },
        { "isxdigit", (char*) isxdigit  },
        { "toascii", (char*) toascii  },
        { "tolower", (char*) tolower  },
        { "toupper", (char*) toupper  },
        { "calloc", (char*) calloc  },
        { "heap_mem_init", (char*) heap_mem_init  },
        { "_Init_Heap", (char*) &_Init_Heap  },
        { "AdjustSize", (char*) AdjustSize  },
        { "ClearBlockHeadMap", (char*) ClearBlockHeadMap  },
        { "Convert2ValidHeadIndex", (char*) Convert2ValidHeadIndex  },
        { "fnRTL_LibcHeapAppInit", (char*) fnRTL_LibcHeapAppInit  },
        { "free", (char*) free  },
        { "InsertBlockToList", (char*) InsertBlockToList  },
        { "malloc", (char*) malloc  },
        { "mallocInfoHookPtr", (char*) &mallocInfoHookPtr  },
        { "mem_stt_show", (char*) mem_stt_show  },
        { "memalign", (char*) memalign  },
        { "MoveBlockFromList", (char*) MoveBlockFromList  },
        { "pgfree", (char*) pgfree  },
        { "pgmalloc", (char*) pgmalloc  },
        { "SetBlockHeadMap", (char*) SetBlockHeadMap  },
        { "sysHeapInitialize", (char*) sysHeapInitialize  },
        { "accumFreeBlks", (char*) &accumFreeBlks  },
        { "accumFreeSize", (char*) &accumFreeSize  },
        { "accumMallocBlks", (char*) &accumMallocBlks  },
        { "accumMallocSize", (char*) &accumMallocSize  },
        { "freeFailures", (char*) &freeFailures  },
        { "HeapFreeBlocks", (char*) &HeapFreeBlocks  },
        { "HeapFreeSize", (char*) &HeapFreeSize  },
        { "HeapInuseSize", (char*) &HeapInuseSize  },
        { "HeapTotalSize", (char*) &HeapTotalSize  },
        { "mallocFailures", (char*) &mallocFailures  },
        { "mallocInfo", (char*) mallocInfo  },
        { "mallocInfo_isr", (char*) mallocInfo_isr  },
        { "mallocInfoHook", (char*) mallocInfoHook  },
        { "maxMallocBlkSize", (char*) &maxMallocBlkSize  },
        { "mem_findmax", (char*) mem_findmax  },
        { "mem_getinfo", (char*) mem_getinfo  },
        { "mem_show", (char*) mem_show  },
        { "_Mpart_Heap_Control", (char*) &_Mpart_Heap_Control  },
        { "check_mpart_id_valid", (char*) check_mpart_id_valid  },
        { "mpart_addmem", (char*) mpart_addmem  },
        { "mpart_alloc", (char*) mpart_alloc  },
        { "mpart_create", (char*) mpart_create  },
        { "mpart_delete", (char*) mpart_delete  },
        { "mpart_free", (char*) mpart_free  },
        { "mpart_memalign", (char*) mpart_memalign  },
        { "mpart_module_init", (char*) mpart_module_init  },
        { "mpart_realloc", (char*) mpart_realloc  },
        { "mpartInfoHookPtr", (char*) &mpartInfoHookPtr  },
        { "mpart_findmaxfree", (char*) mpart_findmaxfree  },
        { "mpart_getinfo", (char*) mpart_getinfo  },
        { "mpartInfoHook", (char*) mpartInfoHook  },
        { "realloc", (char*) realloc  },
        { "__locale", (char*) &__locale  },
        { "__locale_mb_cur_max", (char*) __locale_mb_cur_max  },
        { "localeconv", (char*) localeconv  },
        { "setlocale", (char*) setlocale  },
        { "_getopt_internal", (char*) _getopt_internal  },
        { "_getopt_internal_r", (char*) _getopt_internal_r  },
        { "getopt", (char*) getopt  },
        { "optarg", (char*) &optarg  },
        { "opterr", (char*) &opterr  },
        { "optind", (char*) &optind  },
        { "optopt", (char*) &optopt  },
        { "_getopt_long_only_r", (char*) _getopt_long_only_r  },
        { "_getopt_long_r", (char*) _getopt_long_r  },
        { "getopt_long", (char*) getopt_long  },
        { "getopt_long_only", (char*) getopt_long_only  },
        { "dq_addafter", (char*) dq_addafter  },
        { "dq_addbefore", (char*) dq_addbefore  },
        { "dq_addfirst", (char*) dq_addfirst  },
        { "dq_addlast", (char*) dq_addlast  },
        { "dq_cat", (char*) dq_cat  },
        { "dq_count", (char*) dq_count  },
        { "dq_rem", (char*) dq_rem  },
        { "dq_remfirst", (char*) dq_remfirst  },
        { "dq_remlast", (char*) dq_remlast  },
        { "sq_addafter", (char*) sq_addafter  },
        { "sq_addfirst", (char*) sq_addfirst  },
        { "sq_addlast", (char*) sq_addlast  },
        { "sq_cat", (char*) sq_cat  },
        { "sq_count", (char*) sq_count  },
        { "sq_rem", (char*) sq_rem  },
        { "sq_remafter", (char*) sq_remafter  },
        { "sq_remfirst", (char*) sq_remfirst  },
        { "sq_remlast", (char*) sq_remlast  },
        { "clearerr", (char*) clearerr  },
        { "fclose", (char*) fclose  },
        { "fdopen", (char*) fdopen  },
        { "feof", (char*) feof  },
        { "ferror", (char*) ferror  },
        { "fflush", (char*) fflush  },
        { "fgetc", (char*) fgetc  },
        { "fgetpos", (char*) fgetpos  },
        { "fgets", (char*) fgets  },
        { "fgetwc", (char*) fgetwc  },
        { "fileno", (char*) fileno  },
        { "__sfmoreglue", (char*) __sfmoreglue  },
        { "__sfp", (char*) __sfp  },
        { "__sinit", (char*) __sinit  },
        { "__sflags", (char*) __sflags  },
        { "fopen", (char*) fopen  },
        { "fprintf", (char*) fprintf  },
        { "fputc", (char*) fputc  },
        { "fputs", (char*) fputs  },
        { "fputws", (char*) fputws  },
        { "fread", (char*) fread  },
        { "freopen", (char*) freopen  },
        { "fscanf", (char*) fscanf  },
        { "fseek", (char*) fseek  },
        { "fsetpos", (char*) fsetpos  },
        { "ftell", (char*) ftell  },
        { "__sfvwrite", (char*) __sfvwrite  },
        { "_fwalk", (char*) _fwalk  },
        { "fwide", (char*) fwide  },
        { "fwrite", (char*) fwrite  },
        { "getc", (char*) getc  },
        { "getchar", (char*) getchar  },
        { "gets", (char*) gets  },
        { "getw", (char*) getw  },
        { "global_std_get", (char*) global_std_get  },
        { "global_std_set", (char*) global_std_set  },
        { "__smakebuf", (char*) __smakebuf  },
        { "perror", (char*) perror  },
        { "fdprintf", (char*) fdprintf  },
        { "printf", (char*) printf  },
        { "printf_mutex_lock", (char*) &printf_mutex_lock  },
        { "vfdprintf", (char*) vfdprintf  },
        { "vprintf", (char*) vprintf  },
        { "putc", (char*) putc  },
        { "putchar", (char*) putchar  },
        { "puts", (char*) puts  },
        { "putw", (char*) putw  },
        { "__srefill", (char*) __srefill  },
        { "remove", (char*) remove  },
        { "rename", (char*) rename  },
        { "rewind", (char*) rewind  },
        { "__srget", (char*) __srget  },
        { "scanf", (char*) scanf  },
        { "setbuf", (char*) setbuf  },
        { "setvbuf", (char*) setvbuf  },
        { "__sclose", (char*) __sclose  },
        { "__sread", (char*) __sread  },
        { "__sseek", (char*) __sseek  },
        { "__swrite", (char*) __swrite  },
        { "_iores_ptr", (char*) &_iores_ptr  },
        { "createPrintMutex", (char*) createPrintMutex  },
        { "fnRTL_GetIORes", (char*) fnRTL_GetIORes  },
        { "fnRTL_LibcIOInit", (char*) fnRTL_LibcIOInit  },
        { "iores_data", (char*) &iores_data  },
        { "IOResSemObtain", (char*) IOResSemObtain  },
        { "IOResSemRelease", (char*) IOResSemRelease  },
        { "iosem_id", (char*) &iosem_id  },
        { "libcIOInitFlag", (char*) &libcIOInitFlag  },
        { "ungetc", (char*) ungetc  },
        { "vfprintf", (char*) vfprintf  },
        { "__swbuf", (char*) __swbuf  },
        { "__swsetup", (char*) __swsetup  },
        { "abort", (char*) abort  },
        { "abs", (char*) abs  },
        { "__assert", (char*) __assert  },
        { "__assert_func", (char*) __assert_func  },
        { "atexit", (char*) atexit  },
        { "atof", (char*) atof  },
        { "atoi", (char*) atoi  },
        { "atol", (char*) atol  },
        { "bsearch", (char*) bsearch  },
        { "__cxa_atexit", (char*) __cxa_atexit  },
        { "div", (char*) div  },
        { "environ", (char*) &environ  },
        { "initial_env", (char*) &initial_env  },
        { "_Exit", (char*) _Exit  },
        { "exit", (char*) exit  },
        { "findenv", (char*) findenv  },
        { "fformat", (char*) fformat  },
        { "fscan", (char*) fscan  },
        { "labs", (char*) labs  },
        { "ldiv", (char*) ldiv  },
        { "disablePrint", (char*) disablePrint  },
        { "enablePrint", (char*) enablePrint  },
        { "getPrintFlag", (char*) getPrintFlag  },
        { "printk", (char*) printk  },
        { "rand", (char*) rand  },
        { "srand", (char*) srand  },
        { "strdup", (char*) strdup  },
        { "strtold", (char*) strtold  },
        { "strtoll", (char*) strtoll  },
        { "skipspace", (char*) skipspace  },
        { "strtoull", (char*) strtoull  },
        { "fioformatnstr", (char*) fioformatnstr  },
        { "fioformatstr", (char*) fioformatstr  },
        { "fioscans", (char*) fioscans  },
        { "signofnum", (char*) &signofnum  },
        { "snprintf", (char*) snprintf  },
        { "sprintf", (char*) sprintf  },
        { "sscanf", (char*) sscanf  },
        { "vsnprintf", (char*) vsnprintf  },
        { "vsprintf", (char*) vsprintf  },
        { "getenv", (char*) getenv  },
        { "putenv", (char*) putenv  },
        { "qsort", (char*) qsort  },
        { "setenv", (char*) setenv  },
        { "strtod", (char*) strtod  },
        { "strtof", (char*) strtof  },
        { "strtol", (char*) strtol  },
        { "strtoul", (char*) strtoul  },
        { "bcmp", (char*) bcmp  },
        { "bcopy", (char*) bcopy  },
        { "bcopyBytes", (char*) bcopyBytes  },
        { "bcopyLongs", (char*) bcopyLongs  },
        { "bcopyWords", (char*) bcopyWords  },
        { "bfill", (char*) bfill  },
        { "bfillBytes", (char*) bfillBytes  },
        { "binvert", (char*) binvert  },
        { "bswap", (char*) bswap  },
        { "bzero", (char*) bzero  },
        { "index", (char*) index  },
        { "memchr", (char*) memchr  },
        { "memcmp", (char*) memcmp  },
        { "memcpy", (char*) memcpy  },
        { "memmove", (char*) memmove  },
        { "memset", (char*) memset  },
        { "rindex", (char*) rindex  },
        { "strcat", (char*) strcat  },
        { "strchr", (char*) strchr  },
        { "strcmp", (char*) strcmp  },
        { "strcoll", (char*) strcoll  },
        { "strcpy", (char*) strcpy  },
        { "strcspn", (char*) strcspn  },
        { "errno_tlb", (char*) &errno_tlb  },
        { "strerror", (char*) strerror  },
        { "unknow_errno_info", (char*) &unknow_errno_info  },
        { "strlen", (char*) strlen  },
        { "strncat", (char*) strncat  },
        { "strncmp", (char*) strncmp  },
        { "strncpy", (char*) strncpy  },
        { "strpbrk", (char*) strpbrk  },
        { "strrchr", (char*) strrchr  },
        { "strspn", (char*) strspn  },
        { "strstr", (char*) strstr  },
        { "strtok", (char*) strtok  },
        { "strxfrm", (char*) strxfrm  },
        { "swab", (char*) swab  },
        { "uswab", (char*) uswab  },
        { "__createsem", (char*) __createsem  },
        { "__deletesem", (char*) __deletesem  },
        { "__obtainsem", (char*) __obtainsem  },
        { "__releasesem", (char*) __releasesem  },
        { "symtab_findbyname", (char*) symtab_findbyname  },
        { "symtab_findbyvalue", (char*) symtab_findbyvalue  },
        { "symtab_sortbyname", (char*) symtab_sortbyname  },
        { "cat", (char*) cat  },
        { "chdir", (char*) chdir  },
        { "close", (char*) close  },
        { "closedir", (char*) closedir  },
        { "creat", (char*) creat  },
        { "fcntl", (char*) fcntl  },
        { "fstat", (char*) fstat  },
        { "fsync", (char*) fsync  },
        { "ftruncate", (char*) ftruncate  },
        { "getcwd", (char*) getcwd  },
        { "ioctl", (char*) ioctl  },
        { "isatty", (char*) isatty  },
        { "__lseek", (char*) __lseek  },
        { "lseek", (char*) lseek  },
        { "mkdir", (char*) mkdir  },
        { "mknod", (char*) mknod  },
        { "rtos_filesystem_make_dev_t", (char*) rtos_filesystem_make_dev_t  },
        { "open", (char*) open  },
        { "opendir", (char*) opendir  },
        { "read", (char*) read  },
        { "readdir", (char*) readdir  },
        { "rewinddir", (char*) rewinddir  },
        { "rmdir", (char*) rmdir  },
        { "sockets_adapter_close", (char*) sockets_adapter_close  },
        { "sockets_adapter_fcntl", (char*) sockets_adapter_fcntl  },
        { "sockets_adapter_get_max_fd_with_socket", (char*) sockets_adapter_get_max_fd_with_socket  },
        { "sockets_adapter_ioctl", (char*) sockets_adapter_ioctl  },
        { "sockets_adapter_is_socket_fd", (char*) sockets_adapter_is_socket_fd  },
        { "sockets_adapter_read", (char*) sockets_adapter_read  },
        { "sockets_adapter_set_ops", (char*) sockets_adapter_set_ops  },
        { "sockets_adapter_write", (char*) sockets_adapter_write  },
        { "stat", (char*) stat  },
        { "truncate", (char*) truncate  },
        { "unlink", (char*) unlink  },
        { "utime", (char*) utime  },
        { "write", (char*) write  },
        { "asctime", (char*) asctime  },
        { "clock", (char*) clock  },
        { "clock_timespec_to_ticks", (char*) clock_timespec_to_ticks  },
        { "clock_timespec_to_ticks_by_clockid", (char*) clock_timespec_to_ticks_by_clockid  },
        { "ctime", (char*) ctime  },
        { "difftime", (char*) difftime  },
        { "gettimeofday", (char*) gettimeofday  },
        { "gettime", (char*) gettime  },
        { "gmtime", (char*) gmtime  },
        { "gmtime_r", (char*) gmtime_r  },
        { "localtime", (char*) localtime  },
        { "localtime_r", (char*) localtime_r  },
        { "mktime", (char*) mktime  },
        { "mktime_utc", (char*) mktime_utc  },
        { "validate_structure", (char*) validate_structure  },
        { "getdstinfo", (char*) getdstinfo  },
        { "getzoneinfo", (char*) getzoneinfo  },
        { "strftime", (char*) strftime  },
        { "clockGettime", (char*) clockGettime  },
        { "clockSettime", (char*) clockSettime  },
        { "time", (char*) time  },
        { "btowc", (char*) btowc  },
        { "fnmatch", (char*) fnmatch  },
        { "getwc", (char*) getwc  },
        { "isblank", (char*) isblank  },
        { "iswalnum", (char*) iswalnum  },
        { "iswalpha", (char*) iswalpha  },
        { "iswblank", (char*) iswblank  },
        { "iswcntrl", (char*) iswcntrl  },
        { "iswctype", (char*) iswctype  },
        { "iswdigit", (char*) iswdigit  },
        { "iswgraph", (char*) iswgraph  },
        { "iswlower", (char*) iswlower  },
        { "iswprint", (char*) iswprint  },
        { "iswpunct", (char*) iswpunct  },
        { "iswspace", (char*) iswspace  },
        { "iswupper", (char*) iswupper  },
        { "iswxdigit", (char*) iswxdigit  },
        { "mblen", (char*) mblen  },
        { "mbrtowc", (char*) mbrtowc  },
        { "mbstowcs", (char*) mbstowcs  },
        { "mbtowc", (char*) mbtowc  },
        { "putwc", (char*) putwc  },
        { "towlower", (char*) towlower  },
        { "towupper", (char*) towupper  },
        { "ungetwc", (char*) ungetwc  },
        { "wcrtomb", (char*) wcrtomb  },
        { "wcscmp", (char*) wcscmp  },
        { "wcscoll", (char*) wcscoll  },
        { "wcsftime", (char*) wcsftime  },
        { "wcslcpy", (char*) wcslcpy  },
        { "wcslen", (char*) wcslen  },
        { "wcstombs", (char*) wcstombs  },
        { "wcsxfrm", (char*) wcsxfrm  },
        { "wctob", (char*) wctob  },
        { "wctomb", (char*) wctomb  },
        { "wctype", (char*) wctype  },
        { "wmemchr", (char*) wmemchr  },
        { "wmemcmp", (char*) wmemcmp  },
        { "wmemcpy", (char*) wmemcpy  },
        { "wmemmove", (char*) wmemmove  },
        { "wmemset", (char*) wmemset  },
        { "acos", (char*) acos  },
        { "asin", (char*) asin  },
        { "atan", (char*) atan  },
        { "atan2", (char*) atan2  },
        { "ceil", (char*) ceil  },
        { "cos", (char*) cos  },
        { "cosh", (char*) cosh  },
        { "exp", (char*) exp  },
        { "fabs", (char*) fabs  },
        { "floor", (char*) floor  },
        { "fmod", (char*) fmod  },
        { "frexp", (char*) frexp  },
        { "ldexp", (char*) ldexp  },
        { "log", (char*) log  },
        { "log10", (char*) log10  },
        { "copysign", (char*) copysign  },
        { "drem", (char*) drem  },
        { "exp__E", (char*) exp__E  },
        { "expm1", (char*) expm1  },
        { "finite", (char*) finite  },
        { "fpTypeGet", (char*) fpTypeGet  },
        { "log__L", (char*) log__L  },
        { "logb", (char*) logb  },
        { "scaleb", (char*) scaleb  },
        { "modf", (char*) modf  },
        { "pow", (char*) pow  },
        { "pow_p", (char*) pow_p  },
        { "sin", (char*) sin  },
        { "sinh", (char*) sinh  },
        { "sqrt", (char*) sqrt  },
        { "tan", (char*) tan  },
        { "tanh", (char*) tanh  },
        { "ttos_shell_prf", (char*) ttos_shell_prf  },
        { "shell_factory", (char*) shell_factory  },
        { "shell_get_pwddir", (char*) shell_get_pwddir  },
        { "shell_get_workdir", (char*) shell_get_workdir  },
        { "shell_signal_handle", (char*) shell_signal_handle  },
        { "shell_task_prio", (char*) &shell_task_prio  },
        { "shell_thread_id", (char*) &shell_thread_id  },
        { "sys_launch_time", (char*) &sys_launch_time  },
        { "TICKS_PER_SECENDS", (char*) &TICKS_PER_SECENDS  },
        { "ttos_shell_fprintf", (char*) ttos_shell_fprintf  },
        { "ttos_shell_init", (char*) ttos_shell_init  },
        { "ttos_shell_process", (char*) ttos_shell_process  },
        { "ttos_shell_process_init", (char*) ttos_shell_process_init  },
        { "ttos_shell_start", (char*) ttos_shell_start  },
        { "ttos_shell_thread", (char*) ttos_shell_thread  },
        { "echo_status", (char*) &echo_status  },
        { "shell_cmd_clear", (char*) &shell_cmd_clear  },
        { "shell_cmd_help", (char*) &shell_cmd_help  },
        { "shell_fprintf_buffer_flush", (char*) shell_fprintf_buffer_flush  },
        { "shell_fprintf_fmt", (char*) shell_fprintf_fmt  },
        { "shell_help_cmd_print", (char*) shell_help_cmd_print  },
        { "shellGetMementoCount", (char*) shellGetMementoCount  },
        { "shellHistoryAdd", (char*) shellHistoryAdd  },
        { "shellHistoryDelete", (char*) shellHistoryDelete  },
        { "shellHistoryGet", (char*) shellHistoryGet  },
        { "shellHistoryInite", (char*) shellHistoryInite  },
        { "shellMementoAdd", (char*) shellMementoAdd  },
        { "shellMementoDelete", (char*) shellMementoDelete  },
        { "shellMementoInite", (char*) shellMementoInite  },
        { "shellMementoIterator", (char*) shellMementoIterator  },
        { "shellMementoUninite", (char*) shellMementoUninite  },
        { "findMountPoint", (char*) findMountPoint  },
        { "getFirstMntPoint", (char*) getFirstMntPoint  },
        { "getLastMntPoint", (char*) getLastMntPoint  },
        { "initialFlag", (char*) &initialFlag  },
        { "isMountPointEmpty", (char*) isMountPointEmpty  },
        { "isMountPointExist", (char*) isMountPointExist  },
        { "mountPoint", (char*) &mountPoint  },
        { "registerMntPoint", (char*) registerMntPoint  },
        { "registerMountPointIterator", (char*) registerMountPointIterator  },
        { "showAllRegisterMountPoint", (char*) showAllRegisterMountPoint  },
        { "unRegisterMntPoint", (char*) unRegisterMntPoint  },
        { "shell_cmd_line_erase", (char*) shell_cmd_line_erase  },
        { "shell_cursor_in_empty_line", (char*) shell_cursor_in_empty_line  },
        { "shell_data_insert", (char*) shell_data_insert  },
        { "shell_vt100_color_set", (char*) shell_vt100_color_set  },
        { "shell_vt100_colors_restore", (char*) shell_vt100_colors_restore  },
        { "ttos_shell_char_backspace", (char*) ttos_shell_char_backspace  },
        { "ttos_shell_char_delete", (char*) ttos_shell_char_delete  },
        { "ttos_shell_char_insert", (char*) ttos_shell_char_insert  },
        { "ttos_shell_completion_insert", (char*) ttos_shell_completion_insert  },
        { "ttos_shell_cond_next_line", (char*) ttos_shell_cond_next_line  },
        { "ttos_shell_cursor_end_move", (char*) ttos_shell_cursor_end_move  },
        { "ttos_shell_cursor_home_move", (char*) ttos_shell_cursor_home_move  },
        { "ttos_shell_cursor_horiz_move", (char*) ttos_shell_cursor_horiz_move  },
        { "ttos_shell_cursor_move", (char*) ttos_shell_cursor_move  },
        { "ttos_shell_cursor_position_synchronize", (char*) ttos_shell_cursor_position_synchronize  },
        { "ttos_shell_cursor_vert_move", (char*) ttos_shell_cursor_vert_move  },
        { "ttos_shell_cursor_word_move", (char*) ttos_shell_cursor_word_move  },
        { "ttos_shell_delete_cmd", (char*) ttos_shell_delete_cmd  },
        { "ttos_shell_delete_from_cursor", (char*) ttos_shell_delete_from_cursor  },
        { "ttos_shell_internal_fprintf", (char*) ttos_shell_internal_fprintf  },
        { "ttos_shell_internal_vfprintf", (char*) ttos_shell_internal_vfprintf  },
        { "ttos_shell_left_arrow", (char*) ttos_shell_left_arrow  },
        { "ttos_shell_print_cmd", (char*) ttos_shell_print_cmd  },
        { "ttos_shell_print_prompt_and_cmd", (char*) ttos_shell_print_prompt_and_cmd  },
        { "ttos_shell_print_stream", (char*) ttos_shell_print_stream  },
        { "ttos_shell_right_arrow", (char*) ttos_shell_right_arrow  },
        { "ttos_shell_word_remove", (char*) ttos_shell_word_remove  },
        { "ttos_shell_write", (char*) ttos_shell_write  },
        { "shell_column_span_with_buffer_offsets_get", (char*) shell_column_span_with_buffer_offsets_get  },
        { "shell_row_span_with_buffer_offsets_get", (char*) shell_row_span_with_buffer_offsets_get  },
        { "ttos_shell_cmd_get", (char*) ttos_shell_cmd_get  },
        { "ttos_shell_cmd_trim", (char*) ttos_shell_cmd_trim  },
        { "ttos_shell_make_argv", (char*) ttos_shell_make_argv  },
        { "ttos_shell_multiline_data_calc", (char*) ttos_shell_multiline_data_calc  },
        { "ttos_shell_root_cmd_count", (char*) ttos_shell_root_cmd_count  },
        { "ttos_shell_root_cmd_find", (char*) ttos_shell_root_cmd_find  },
        { "ttos_shell_root_cmd_get", (char*) ttos_shell_root_cmd_get  },
        { "shell_get_current_task", (char*) shell_get_current_task  },
        { "cmd_init", (char*) cmd_init  },
        { "find_fileposinpath", (char*) find_fileposinpath  },
        { "is_hex", (char*) is_hex  },
        { "is_ip", (char*) is_ip  },
        { "nfssys_name_pro", (char*) nfssys_name_pro  },
        { "shell_cmd_app", (char*) &shell_cmd_app  },
        { "shell_cmd_appconfig", (char*) &shell_cmd_appconfig  },
        { "shell_cmd_arp", (char*) &shell_cmd_arp  },
        { "shell_cmd_cat", (char*) &shell_cmd_cat  },
        { "shell_cmd_cd", (char*) &shell_cmd_cd  },
        { "shell_cmd_cp", (char*) &shell_cmd_cp  },
        { "shell_cmd_cpuuse", (char*) &shell_cmd_cpuuse  },
        { "shell_cmd_cyclictest", (char*) &shell_cmd_cyclictest  },
        { "shell_cmd_d", (char*) &shell_cmd_d  },
        { "shell_cmd_date", (char*) &shell_cmd_date  },
        { "shell_cmd_deadlock", (char*) &shell_cmd_deadlock  },
        { "shell_cmd_devls", (char*) &shell_cmd_devls  },
        { "shell_cmd_errno", (char*) &shell_cmd_errno  },
        { "shell_cmd_ethercat", (char*) &shell_cmd_ethercat  },
        { "shell_cmd_fdinfo", (char*) &shell_cmd_fdinfo  },
        { "shell_cmd_heap", (char*) &shell_cmd_heap  },
        { "shell_cmd_history", (char*) &shell_cmd_history  },
        { "shell_cmd_ifconfig", (char*) &shell_cmd_ifconfig  },
        { "shell_cmd_ls", (char*) &shell_cmd_ls  },
        { "shell_cmd_m", (char*) &shell_cmd_m  },
        { "shell_cmd_mkdir", (char*) &shell_cmd_mkdir  },
        { "shell_cmd_mkfs", (char*) &shell_cmd_mkfs  },
        { "shell_cmd_msg", (char*) &shell_cmd_msg  },
        { "shell_cmd_mv", (char*) &shell_cmd_mv  },
        { "shell_cmd_netstats", (char*) &shell_cmd_netstats  },
        { "shell_cmd_ping", (char*) &shell_cmd_ping  },
        { "shell_cmd_pwd", (char*) &shell_cmd_pwd  },
        { "shell_cmd_quit", (char*) &shell_cmd_quit  },
        { "shell_cmd_redirect", (char*) &shell_cmd_redirect  },
        { "shell_cmd_rm", (char*) &shell_cmd_rm  },
        { "shell_cmd_rmdir", (char*) &shell_cmd_rmdir  },
        { "shell_cmd_route", (char*) &shell_cmd_route  },
        { "shell_cmd_sem", (char*) &shell_cmd_sem  },
        { "shell_cmd_shminfo", (char*) &shell_cmd_shminfo  },
        { "shell_cmd_stackuse", (char*) &shell_cmd_stackuse  },
        { "shell_cmd_sysheap", (char*) &shell_cmd_sysheap  },
        { "shell_cmd_sysinfo", (char*) &shell_cmd_sysinfo  },
        { "shell_cmd_task", (char*) &shell_cmd_task  },
        { "shell_cmd_tc", (char*) &shell_cmd_tc  },
        { "shell_cmd_td", (char*) &shell_cmd_td  },
        { "shell_cmd_tick", (char*) &shell_cmd_tick  },
        { "shell_cmd_timer", (char*) &shell_cmd_timer  },
        { "shell_cmd_top", (char*) &shell_cmd_top  },
        { "shell_cmd_touch", (char*) &shell_cmd_touch  },
        { "shell_cmd_tp", (char*) &shell_cmd_tp  },
        { "shell_cmd_tr", (char*) &shell_cmd_tr  },
        { "shell_cmd_trace", (char*) &shell_cmd_trace  },
        { "shell_cmd_ts", (char*) &shell_cmd_ts  },
        { "shell_cmd_tts", (char*) &shell_cmd_tts  },
        { "shell_cmd_version", (char*) &shell_cmd_version  },
        { "shell_cmd_vm", (char*) &shell_cmd_vm  },
        { "shell_cmd_who", (char*) &shell_cmd_who  },
        { "string_all_digit_dec", (char*) string_all_digit_dec  },
        { "string_all_digit_hex", (char*) string_all_digit_hex  },
        { "task_state_to_char", (char*) task_state_to_char  },
        { "shell_main_app", (char*) shell_main_app  },
        { "shell_main_appconfig", (char*) shell_main_appconfig  },
        { "arp_display", (char*) arp_display  },
        { "shell_main_arp", (char*) shell_main_arp  },
        { "shell_cat_file", (char*) shell_cat_file  },
        { "shell_main_cat", (char*) shell_main_cat  },
        { "shell_main_cd", (char*) shell_main_cd  },
        { "copy_dir", (char*) copy_dir  },
        { "copy_file", (char*) copy_file  },
        { "shell_main_cp", (char*) shell_main_cp  },
        { "shell_main_cpuuse", (char*) shell_main_cpuuse  },
        { "err_msg", (char*) err_msg  },
        { "err_msg_n", (char*) err_msg_n  },
        { "event_disable", (char*) event_disable  },
        { "get_tracers", (char*) get_tracers  },
        { "parse_time_string", (char*) parse_time_string  },
        { "policy_to_string", (char*) policy_to_string  },
        { "setevent", (char*) setevent  },
        { "shell_main_cyclictest", (char*) shell_main_cyclictest  },
        { "string_to_policy", (char*) string_to_policy  },
        { "timerthread", (char*) timerthread  },
        { "traceopt", (char*) traceopt  },
        { "tracing", (char*) tracing  },
        { "shell_main_d", (char*) shell_main_d  },
        { "shell_main_date", (char*) shell_main_date  },
        { "shell_main_devls", (char*) shell_main_devls  },
        { "shell_main_errno", (char*) shell_main_errno  },
        { "shell_main_ethercat", (char*) shell_main_ethercat  },
        { "shell_main_fdinfo", (char*) shell_main_fdinfo  },
        { "data_hook", (char*) data_hook  },
        { "shell_lock_taskshow", (char*) shell_lock_taskshow  },
        { "shell_main_deadlock", (char*) shell_main_deadlock  },
        { "shell_main_heap", (char*) shell_main_heap  },
        { "shell_main_history", (char*) shell_main_history  },
        { "shell_main_ifconfig", (char*) shell_main_ifconfig  },
        { "shell_main_lkup", (char*) shell_main_lkup  },
        { "to_symbol_type", (char*) to_symbol_type  },
        { "mode_to_string", (char*) mode_to_string  },
        { "shell_main_ls", (char*) shell_main_ls  },
        { "shell_main_m", (char*) shell_main_m  },
        { "shell_main_mkdir", (char*) shell_main_mkdir  },
        { "shell_main_mkfs", (char*) shell_main_mkfs  },
        { "monitorElementShow", (char*) monitorElementShow  },
        { "shell_main_monitor", (char*) shell_main_monitor  },
        { "shell_main_msg", (char*) shell_main_msg  },
        { "shell_main_mv", (char*) shell_main_mv  },
        { "shell_main_netstats", (char*) shell_main_netstats  },
        { "shell_main_p", (char*) shell_main_p  },
        { "ping_send", (char*) ping_send  },
        { "shell_main_ping", (char*) shell_main_ping  },
        { "shell_main_pwd", (char*) shell_main_pwd  },
        { "shell_main_quit", (char*) shell_main_quit  },
        { "shell_main_reboot", (char*) shell_main_reboot  },
        { "shell_main_redirect", (char*) shell_main_redirect  },
        { "shell_main_rm", (char*) shell_main_rm  },
        { "recursion_rmdir", (char*) recursion_rmdir  },
        { "shell_main_rmdir", (char*) shell_main_rmdir  },
        { "shell_main_route", (char*) shell_main_route  },
        { "shell_main_sem", (char*) shell_main_sem  },
        { "shell_main_shminfo", (char*) shell_main_shminfo  },
        { "shell_main_stackuse", (char*) shell_main_stackuse  },
        { "shell_main_sysheap", (char*) shell_main_sysheap  },
        { "shell_main_sysinfo", (char*) shell_main_sysinfo  },
        { "showMntPointInfo", (char*) showMntPointInfo  },
        { "shell_main_task", (char*) shell_main_task  },
        { "shell_main_tc", (char*) shell_main_tc  },
        { "shell_main_td", (char*) shell_main_td  },
        { "shell_main_tick", (char*) shell_main_tick  },
        { "shell_main_timer", (char*) shell_main_timer  },
        { "timer_stat_to_string", (char*) timer_stat_to_string  },
        { "shell_main_top", (char*) shell_main_top  },
        { "shellTopGetCPUInfo", (char*) shellTopGetCPUInfo  },
        { "shell_main_touch", (char*) shell_main_touch  },
        { "shell_main_tp", (char*) shell_main_tp  },
        { "shell_main_tr", (char*) shell_main_tr  },
        { "shell_main_trace", (char*) shell_main_trace  },
        { "shell_main_ts", (char*) shell_main_ts  },
        { "shell_main_tts", (char*) shell_main_tts  },
        { "shell_main_version", (char*) shell_main_version  },
        { "shell_main_vm", (char*) shell_main_vm  },
        { "vmstatus_to_string", (char*) vmstatus_to_string  },
        { "shell_main_who", (char*) shell_main_who  },
        { "shell_getopt", (char*) shell_getopt  },
        { "shell_getopt_long", (char*) shell_getopt_long  },
        { "shell_getopt_tmp", (char*) shell_getopt_tmp  },
        { "dot_path_pro", (char*) dot_path_pro  },
        { "dotdot_path_pro", (char*) dotdot_path_pro  },
        { "find_father_dir", (char*) find_father_dir  },
        { "get_pwd_dir", (char*) get_pwd_dir  },
        { "illegal_path_check", (char*) illegal_path_check  },
        { "pwd_path_pro", (char*) pwd_path_pro  },
        { "recursion_dotdot_pro", (char*) recursion_dotdot_pro  },
        { "update_shell_prompt", (char*) update_shell_prompt  },
        { "update_work_dir", (char*) update_work_dir  },
        { "addMonitorElement", (char*) addMonitorElement  },
        { "creatSystemMonitor", (char*) creatSystemMonitor  },
        { "defaultMonitorSignalHandler", (char*) defaultMonitorSignalHandler  },
        { "defaultMonitorTaskHandler", (char*) defaultMonitorTaskHandler  },
        { "exceptionInformationProcess", (char*) exceptionInformationProcess  },
        { "exceptionMonitorSignalHandler", (char*) exceptionMonitorSignalHandler  },
        { "get_monitor_priority", (char*) get_monitor_priority  },
        { "get_monitor_stack_size", (char*) get_monitor_stack_size  },
        { "info", (char*) &info  },
        { "monitorElementIterator", (char*) monitorElementIterator  },
        { "monitorFind", (char*) monitorFind  },
        { "monitorHead", (char*) &monitorHead  },
        { "monitorTrigger", (char*) monitorTrigger  },
        { "set_monitor_priority", (char*) set_monitor_priority  },
        { "set_monitor_stack_size", (char*) set_monitor_stack_size  },
        { "sysInfoInit", (char*) sysInfoInit  },
        { "sysInfoInitTask", (char*) sysInfoInitTask  },
        { "systemPowerOnInfoTask", (char*) systemPowerOnInfoTask  },
        { "hashCode", (char*) hashCode  },
        { "SYM_SymbolAdd", (char*) SYM_SymbolAdd  },
        { "SYM_SymbolDelete", (char*) SYM_SymbolDelete  },
        { "SYM_SymbolEach", (char*) SYM_SymbolEach  },
        { "SYM_SymbolFind", (char*) SYM_SymbolFind  },
        { "SYM_SymbolShow", (char*) SYM_SymbolShow  },
        { "SYM_SymbolValueGet", (char*) SYM_SymbolValueGet  },
        { "SYM_SystemSymbolTableAdd", (char*) SYM_SystemSymbolTableAdd  },
        { "symFind", (char*) symFind  },
        { "symInit", (char*) symInit  },
        { "symTableAdd", (char*) symTableAdd  },
        { "lukp_test_double", (char*) &lukp_test_double  },
        { "lukp_test_float", (char*) &lukp_test_float  },
        { "lukp_test_value0", (char*) &lukp_test_value0  },
        { "lukp_test_value1", (char*) &lukp_test_value1  },
        { "lukp_test_value2", (char*) &lukp_test_value2  },
        { "lukp_test_value3", (char*) &lukp_test_value3  },
        { "lukp_test_value4", (char*) &lukp_test_value4  },
        { "standTbl", (char*) &standTbl  },
        { "standTblSize", (char*) &standTblSize  },
        { "symAaddTest", (char*) symAaddTest  },
        { "symTest", (char*) symTest  },
        { "userETbl", (char*) &userETbl  },
        { "userETblSize", (char*) &userETblSize  },
        { "userTbl", (char*) &userTbl  },
        { "userTblSize", (char*) &userTblSize  },
        { "connect_fd", (char*) &connect_fd  },
        { "diconnect_telnet", (char*) diconnect_telnet  },
        { "enable_shell_telnet", (char*) enable_shell_telnet  },
        { "get_shell_priority", (char*) get_shell_priority  },
        { "get_shell_ptr", (char*) get_shell_ptr  },
        { "get_shell_stack_size", (char*) get_shell_stack_size  },
        { "oldstd", (char*) &oldstd  },
        { "rpc_task", (char*) &rpc_task  },
        { "runtime_factory", (char*) runtime_factory  },
        { "set_shell_priority", (char*) set_shell_priority  },
        { "set_shell_stack_size", (char*) set_shell_stack_size  },
        { "sh_telnet", (char*) &sh_telnet  },
        { "shell_backend_telnet_get_ptr", (char*) shell_backend_telnet_get_ptr  },
        { "shell_ctx_factory", (char*) shell_ctx_factory  },
        { "shell_fprintf_factory", (char*) shell_fprintf_factory  },
        { "shell_init_flag", (char*) &shell_init_flag  },
        { "shell_interface_factory", (char*) shell_interface_factory  },
        { "shell_telnet_server_init", (char*) shell_telnet_server_init  },
        { "shell_telnet_server_task", (char*) shell_telnet_server_task  },
        { "shell_telnet_set_client_disable_echo", (char*) shell_telnet_set_client_disable_echo  },
        { "shell_telnet_task", (char*) shell_telnet_task  },
        { "shell_uart_server_init", (char*) shell_uart_server_init  },
        { "telnet_server_fd", (char*) &telnet_server_fd  },
        { "telnet_shell_destroy", (char*) telnet_shell_destroy  },
        { "telnet_shell_factory", (char*) telnet_shell_factory  },
        { "terminal_factory", (char*) terminal_factory  },
        { "VMK_AccessVM", (char*) VMK_AccessVM  },
        { "VMK_AckException", (char*) VMK_AckException  },
        { "VMK_ControlVM", (char*) VMK_ControlVM  },
        { "VMK_CreateShm", (char*) VMK_CreateShm  },
        { "VMK_DisablePIC", (char*) VMK_DisablePIC  },
        { "VMK_EnablePIC", (char*) VMK_EnablePIC  },
        { "VMK_EveWriteData", (char*) VMK_EveWriteData  },
        { "VMK_CpuIDGet", (char*) VMK_CpuIDGet  },
        { "VMK_GetEnableCpuSet", (char*) VMK_GetEnableCpuSet  },
        { "VMK_GetExceptionVM", (char*) VMK_GetExceptionVM  },
        { "VMK_GetKernelInfo", (char*) VMK_GetKernelInfo  },
        { "VMK_GetMainFrameTicks", (char*) VMK_GetMainFrameTicks  },
        { "VMK_GetSysClkRate", (char*) VMK_GetSysClkRate  },
        { "VMK_GetSystemTicks", (char*) VMK_GetSystemTicks  },
        { "VMK_GetTTSID", (char*) VMK_GetTTSID  },
        { "VMK_GetTTSInfo", (char*) VMK_GetTTSInfo  },
        { "VMK_GetTTSName", (char*) VMK_GetTTSName  },
        { "VMK_GetVMID", (char*) VMK_GetVMID  },
        { "VMK_GetVMInfo", (char*) VMK_GetVMInfo  },
        { "VMK_GetVMMemBlockSize", (char*) VMK_GetVMMemBlockSize  },
        { "VMK_GetVMName", (char*) VMK_GetVMName  },
        { "VMK_GetVMPhysicalAddress", (char*) VMK_GetVMPhysicalAddress  },
        { "VMK_GetVMStatus", (char*) VMK_GetVMStatus  },
        { "VMK_GetVMTSSInfo", (char*) VMK_GetVMTSSInfo  },
        { "VMK_GetVMWindowTicks", (char*) VMK_GetVMWindowTicks  },
        { "VMK_HaltVM", (char*) VMK_HaltVM  },
        { "VMK_InitializeVint", (char*) VMK_InitializeVint  },
        { "VMK_MapPage", (char*) VMK_MapPage  },
        { "VMK_MapShm", (char*) VMK_MapShm  },
        { "VMK_PrintChar", (char*) VMK_PrintChar  },
        { "VMK_ResetVM", (char*) VMK_ResetVM  },
        { "VMK_ResumeVM", (char*) VMK_ResumeVM  },
        { "VMK_SendIPI", (char*) VMK_SendIPI  },
        { "VMK_SendServiceInt", (char*) VMK_SendServiceInt  },
        { "VMK_SetSysClkRate", (char*) VMK_SetSysClkRate  },
        { "VMK_SetVMPageAttribute", (char*) VMK_SetVMPageAttribute  },
        { "VMK_StartTTS", (char*) VMK_StartTTS  },
        { "VMK_StartVM", (char*) VMK_StartVM  },
        { "VMK_StopTTS", (char*) VMK_StopTTS  },
        { "VMK_StopVM", (char*) VMK_StopVM  },
        { "VMK_SuspendVM", (char*) VMK_SuspendVM  },
        { "VMK_TerminateInt", (char*) VMK_TerminateInt  },
        { "VMK_TriggerVint", (char*) VMK_TriggerVint  },
        { "VMK_UnMapShm", (char*) VMK_UnMapShm  },
        { "cpuIDGet", (char*) cpuIDGet  },
        { "hCpuIDGet", (char*) hCpuIDGet  },
        { "vbspInit", (char*) vbspInit  },
        { "VMK_GetCPUTime", (char*) VMK_GetCPUTime  },
        { "vbspDisableExInt", (char*) vbspDisableExInt  },
        { "vbspDisableGlobalInt", (char*) vbspDisableGlobalInt  },
        { "vbspDisableSerInt", (char*) vbspDisableSerInt  },
        { "vbspDisableTickInt", (char*) vbspDisableTickInt  },
        { "vbspDispatchVint", (char*) vbspDispatchVint  },
        { "vbspTriggerVint", (char*) vbspTriggerVint  },
        { "vbspDisableVint", (char*) vbspDisableVint  },
        { "vbspEnableVint", (char*) vbspEnableVint  },
        { "vbspEnableExInt", (char*) vbspEnableExInt  },
        { "restoreGlobalIntCount", (char*) &restoreGlobalIntCount  },
        { "vbspEnableGlobalInt", (char*) vbspEnableGlobalInt  },
        { "vbspRestoreGlobalInt", (char*) vbspRestoreGlobalInt  },
        { "vbspEnableSerInt", (char*) vbspEnableSerInt  },
        { "vbspEnableTickInt", (char*) vbspEnableTickInt  },
        { "vbspGetGlobalInt", (char*) vbspGetGlobalInt  },
        { "vbspGetGlobalIntAdress", (char*) vbspGetGlobalIntAdress  },
        { "vbspInitializeVint", (char*) vbspInitializeVint  },
        { "vbspInitializeVintHandler", (char*) vbspInitializeVintHandler  },
        { "vbspInitializeVintWithHandler", (char*) vbspInitializeVintWithHandler  },
        { "vbspInstallVintHandler", (char*) vbspInstallVintHandler  },
        { "vbspUnInstallVintHandler", (char*) vbspUnInstallVintHandler  },
        { "g_vbspExceptionHandlerTable", (char*) &g_vbspExceptionHandlerTable  },
        { "g_vbspExIntHandlerTable", (char*) &g_vbspExIntHandlerTable  },
        { "g_vbspServIntHandlerTable", (char*) &g_vbspServIntHandlerTable  },
        { "g_vbspTickHandler", (char*) &g_vbspTickHandler  },
        { "g_vbspVIntEnMask", (char*) &g_vbspVIntEnMask  },
        { "vbspVintHandler", (char*) vbspVintHandler  },
        { "cfgGetCurrentVmConfig", (char*) cfgGetCurrentVmConfig  },
        { "pciDirectFindCan", (char*) pciDirectFindCan  },
        { "pciDirectFindDevice", (char*) pciDirectFindDevice  },
        { "pciDirectFindNic", (char*) pciDirectFindNic  },
        { "pciDirectFindNicInfo", (char*) pciDirectFindNicInfo  },
        { "pciDirectFindSpi", (char*) pciDirectFindSpi  },
        { "VMK_AllocVector", (char*) VMK_AllocVector  },
        { "VMK_ChangeCurrentVmCpuStatus", (char*) VMK_ChangeCurrentVmCpuStatus  },
        { "VMK_FloatCtrol", (char*) VMK_FloatCtrol  },
        { "VMK_GetConfigTableAddr", (char*) VMK_GetConfigTableAddr  },
        { "VMK_GetCPUFreq", (char*) VMK_GetCPUFreq  },
        { "VMK_GetWorkSpaceSize", (char*) VMK_GetWorkSpaceSize  },
        { "VMK_MapExint", (char*) VMK_MapExint  },
        { "VMK_MapExintToVint", (char*) VMK_MapExintToVint  },
        { "VMK_Reboot", (char*) VMK_Reboot  },
        { "VMK_RteDebugSet", (char*) VMK_RteDebugSet  },
        { "VMK_StartStageInit", (char*) VMK_StartStageInit  },
        { "VMK_VmPrintBuf", (char*) VMK_VmPrintBuf  },
        { "TTOS_GetEventInfo", (char*) TTOS_GetEventInfo  },
        { "TTOS_ReceiveEvent", (char*) TTOS_ReceiveEvent  },
        { "TTOS_SendEvent", (char*) TTOS_SendEvent  },
        { "TTOS_NotifyHM", (char*) TTOS_NotifyHM  },
        { "TTOS_CPULoadDistribution", (char*) TTOS_CPULoadDistribution  },
        { "TTOS_CPURecordLog", (char*) TTOS_CPURecordLog  },
        { "TTOS_CPURecordLogTask", (char*) TTOS_CPURecordLogTask  },
        { "TTOS_CPUStatisticsDisable", (char*) TTOS_CPUStatisticsDisable  },
        { "TTOS_CPUStatisticsEnable", (char*) TTOS_CPUStatisticsEnable  },
        { "TTOS_CPUStatisticsInit", (char*) TTOS_CPUStatisticsInit  },
        { "TTOS_CPUStatisticsTest", (char*) TTOS_CPUStatisticsTest  },
        { "TTOS_CPUUsageStatistics", (char*) TTOS_CPUUsageStatistics  },
        { "TTOS_CPUUsageStatisticsTask", (char*) TTOS_CPUUsageStatisticsTask  },
        { "TTOS_GetCPURecordLogPeriod", (char*) TTOS_GetCPURecordLogPeriod  },
        { "TTOS_GetCPUSamplingPeriod", (char*) TTOS_GetCPUSamplingPeriod  },
        { "TTOS_GetCPUUsage", (char*) TTOS_GetCPUUsage  },
        { "TTOS_SetCPURecordLogPeriod", (char*) TTOS_SetCPURecordLogPeriod  },
        { "TTOS_SetCPUSamplingPeriod", (char*) TTOS_SetCPUSamplingPeriod  },
        { "TTOS_SetRecordLogTaskPrior", (char*) TTOS_SetRecordLogTaskPrior  },
        { "TTOS_SetUsageStatisticsTaskPrior", (char*) TTOS_SetUsageStatisticsTaskPrior  },
        { "TTOS_StartOS", (char*) TTOS_StartOS  },
        { "ttosAPEntry", (char*) ttosAPEntry  },
        { "ttosIdleTaskEntry", (char*) ttosIdleTaskEntry  },
        { "ttosIdleTCB", (char*) &ttosIdleTCB  },
        { "ttosInitialized", (char*) &ttosInitialized  },
        { "ttosManager", (char*) &ttosManager  },
        { "TTOS_CreateMsgq", (char*) TTOS_CreateMsgq  },
        { "ttosInitMsgq", (char*) ttosInitMsgq  },
        { "TTOS_DeleteMsgq", (char*) TTOS_DeleteMsgq  },
        { "ttosDeleteMessage", (char*) ttosDeleteMessage  },
        { "TTOS_GetMsgqClassInfo", (char*) TTOS_GetMsgqClassInfo  },
        { "TTOS_GetMsgqCount", (char*) TTOS_GetMsgqCount  },
        { "TTOS_GetMsgqID", (char*) TTOS_GetMsgqID  },
        { "TTOS_GetMsgqInfo", (char*) TTOS_GetMsgqInfo  },
        { "TTOS_GetMsgqName", (char*) TTOS_GetMsgqName  },
        { "TTOS_GetMsgqPendingCount", (char*) TTOS_GetMsgqPendingCount  },
        { "ttosCommitMessage", (char*) ttosCommitMessage  },
        { "ttosInsertMsg", (char*) ttosInsertMsg  },
        { "ttosSetMessageNotify", (char*) ttosSetMessageNotify  },
        { "TTOS_ReceiveMsgq", (char*) TTOS_ReceiveMsgq  },
        { "TTOS_SendMsgq", (char*) TTOS_SendMsgq  },
        { "alarm", (char*) alarm  },
        { "alarm_init", (char*) alarm_init  },
        { "backTrace", (char*) backTrace  },
        { "backTraceGetDepth", (char*) backTraceGetDepth  },
        { "backTraceSetDepth", (char*) backTraceSetDepth  },
        { "clock_getcpuclockid", (char*) clock_getcpuclockid  },
        { "clock_getres", (char*) clock_getres  },
        { "clock_gettime", (char*) clock_gettime  },
        { "clock_settime", (char*) clock_settime  },
        { "sys_clk_rate_get", (char*) sys_clk_rate_get  },
        { "sys_clk_rate_set", (char*) sys_clk_rate_set  },
        { "tick_get", (char*) tick_get  },
        { "tick_set", (char*) tick_set  },
        { "exception_handler_set", (char*) exception_handler_set  },
        { "int_disable_pic", (char*) int_disable_pic  },
        { "int_enable_pic", (char*) int_enable_pic  },
        { "int_install_handler", (char*) int_install_handler  },
        { "int_lock", (char*) int_lock  },
        { "int_uninstall_handler", (char*) int_uninstall_handler  },
        { "int_unlock", (char*) int_unlock  },
        { "shared_int_install", (char*) shared_int_install  },
        { "shared_int_uninstall", (char*) shared_int_uninstall  },
        { "mq_close", (char*) mq_close  },
        { "mq_create", (char*) mq_create  },
        { "mq_delete", (char*) mq_delete  },
        { "mq_getattr", (char*) mq_getattr  },
        { "mq_getinfo", (char*) mq_getinfo  },
        { "mq_init", (char*) mq_init  },
        { "mq_notify", (char*) mq_notify  },
        { "mq_open", (char*) mq_open  },
        { "mq_receive", (char*) mq_receive  },
        { "mq_send", (char*) mq_send  },
        { "mq_setattr", (char*) mq_setattr  },
        { "mq_show", (char*) mq_show  },
        { "mq_timedreceive", (char*) mq_timedreceive  },
        { "mq_timedsend", (char*) mq_timedsend  },
        { "mq_unlink", (char*) mq_unlink  },
        { "convertCoreReturnCodeToErrno", (char*) convertCoreReturnCodeToErrno  },
        { "getShowErrnoMoreInfoFlag", (char*) getShowErrnoMoreInfoFlag  },
        { "setShowErrnoMoreInfoFlag", (char*) setShowErrnoMoreInfoFlag  },
        { "corePrioritytoPthread", (char*) corePrioritytoPthread  },
        { "currentPthreadTryToDeferredCancel", (char*) currentPthreadTryToDeferredCancel  },
        { "posix_memalign", (char*) posix_memalign  },
        { "pthread_cancel", (char*) pthread_cancel  },
        { "pthread_cancelforce", (char*) pthread_cancelforce  },
        { "pthread_cleanup_pop", (char*) pthread_cleanup_pop  },
        { "pthread_cleanup_push", (char*) pthread_cleanup_push  },
        { "pthread_create", (char*) pthread_create  },
        { "pthread_default_attr_get", (char*) pthread_default_attr_get  },
        { "pthread_delay", (char*) pthread_delay  },
        { "pthread_detach", (char*) pthread_detach  },
        { "pthread_exit", (char*) pthread_exit  },
        { "pthread_getaffinity_np", (char*) pthread_getaffinity_np  },
        { "pthread_getattr_np", (char*) pthread_getattr_np  },
        { "pthread_getcpuclockid", (char*) pthread_getcpuclockid  },
        { "pthread_getschedparam", (char*) pthread_getschedparam  },
        { "pthread_join", (char*) pthread_join  },
        { "pthread_lock", (char*) pthread_lock  },
        { "pthread_resume", (char*) pthread_resume  },
        { "pthread_self", (char*) pthread_self  },
        { "pthread_setaffinity_np", (char*) pthread_setaffinity_np  },
        { "pthread_setcancelstate", (char*) pthread_setcancelstate  },
        { "pthread_setcanceltype", (char*) pthread_setcanceltype  },
        { "pthread_setschedparam", (char*) pthread_setschedparam  },
        { "pthread_setschedprio", (char*) pthread_setschedprio  },
        { "pthread_sigmask", (char*) pthread_sigmask  },
        { "pthread_spin_destroy", (char*) pthread_spin_destroy  },
        { "pthread_spin_init", (char*) pthread_spin_init  },
        { "pthread_spin_lock", (char*) pthread_spin_lock  },
        { "pthread_spin_trylock", (char*) pthread_spin_trylock  },
        { "pthread_spin_unlock", (char*) pthread_spin_unlock  },
        { "pthread_suspend", (char*) pthread_suspend  },
        { "pthread_testcancel", (char*) pthread_testcancel  },
        { "pthread_unlock", (char*) pthread_unlock  },
        { "pthreadIsCancelableForAsync", (char*) pthreadIsCancelableForAsync  },
        { "pthreadIsCancelableForDeferred", (char*) pthreadIsCancelableForDeferred  },
        { "pthreadJoinCanceHook", (char*) pthreadJoinCanceHook  },
        { "pthreadPriorityIsValid", (char*) pthreadPriorityIsValid  },
        { "pthreadPriorityToCore", (char*) pthreadPriorityToCore  },
        { "pthreadRunCancelHandler", (char*) pthreadRunCancelHandler  },
        { "pthreadTryToCancel", (char*) pthreadTryToCancel  },
        { "pthread_attr_destroy", (char*) pthread_attr_destroy  },
        { "pthread_attr_getbreakallowed", (char*) pthread_attr_getbreakallowed  },
        { "pthread_attr_getdetachstate", (char*) pthread_attr_getdetachstate  },
        { "pthread_attr_getfpallowed", (char*) pthread_attr_getfpallowed  },
        { "pthread_attr_getguardsize", (char*) pthread_attr_getguardsize  },
        { "pthread_attr_getinheritsched", (char*) pthread_attr_getinheritsched  },
        { "pthread_attr_getname", (char*) pthread_attr_getname  },
        { "pthread_attr_getschedparam", (char*) pthread_attr_getschedparam  },
        { "pthread_attr_getschedpolicy", (char*) pthread_attr_getschedpolicy  },
        { "pthread_attr_getschedprio", (char*) pthread_attr_getschedprio  },
        { "pthread_attr_getscope", (char*) pthread_attr_getscope  },
        { "pthread_attr_getstack", (char*) pthread_attr_getstack  },
        { "pthread_attr_getstackaddr", (char*) pthread_attr_getstackaddr  },
        { "pthread_attr_getstackfilled", (char*) pthread_attr_getstackfilled  },
        { "pthread_attr_getstacksize", (char*) pthread_attr_getstacksize  },
        { "pthread_attr_init", (char*) pthread_attr_init  },
        { "pthread_attr_setbreakallowed", (char*) pthread_attr_setbreakallowed  },
        { "pthread_attr_setdetachstate", (char*) pthread_attr_setdetachstate  },
        { "pthread_attr_setfpallowed", (char*) pthread_attr_setfpallowed  },
        { "pthread_attr_setguardsize", (char*) pthread_attr_setguardsize  },
        { "pthread_attr_setinheritsched", (char*) pthread_attr_setinheritsched  },
        { "pthread_attr_setname", (char*) pthread_attr_setname  },
        { "pthread_attr_setschedparam", (char*) pthread_attr_setschedparam  },
        { "pthread_attr_setschedpolicy", (char*) pthread_attr_setschedpolicy  },
        { "pthread_attr_setschedprio", (char*) pthread_attr_setschedprio  },
        { "pthread_attr_setscope", (char*) pthread_attr_setscope  },
        { "pthread_attr_setstack", (char*) pthread_attr_setstack  },
        { "pthread_attr_setstackaddr", (char*) pthread_attr_setstackaddr  },
        { "pthread_attr_setstackfilled", (char*) pthread_attr_setstackfilled  },
        { "pthread_attr_setstacksize", (char*) pthread_attr_setstacksize  },
        { "pthread_barrier_destroy", (char*) pthread_barrier_destroy  },
        { "pthread_barrier_init", (char*) pthread_barrier_init  },
        { "pthread_barrier_wait", (char*) pthread_barrier_wait  },
        { "pthread_barrierattr_destroy", (char*) pthread_barrierattr_destroy  },
        { "pthread_barrierattr_getpshared", (char*) pthread_barrierattr_getpshared  },
        { "pthread_barrierattr_init", (char*) pthread_barrierattr_init  },
        { "pthread_barrierattr_setpshared", (char*) pthread_barrierattr_setpshared  },
        { "pthread_cond_broadcast", (char*) pthread_cond_broadcast  },
        { "pthread_cond_destroy", (char*) pthread_cond_destroy  },
        { "pthread_cond_getinfo", (char*) pthread_cond_getinfo  },
        { "pthread_cond_init", (char*) pthread_cond_init  },
        { "pthread_cond_module_init", (char*) pthread_cond_module_init  },
        { "pthread_cond_show", (char*) pthread_cond_show  },
        { "pthread_cond_signal", (char*) pthread_cond_signal  },
        { "pthread_cond_timedwait", (char*) pthread_cond_timedwait  },
        { "pthread_cond_wait", (char*) pthread_cond_wait  },
        { "pthread_condattr_destroy", (char*) pthread_condattr_destroy  },
        { "pthread_condattr_getclock", (char*) pthread_condattr_getclock  },
        { "pthread_condattr_getpshared", (char*) pthread_condattr_getpshared  },
        { "pthread_condattr_init", (char*) pthread_condattr_init  },
        { "pthread_condattr_setclock", (char*) pthread_condattr_setclock  },
        { "pthread_condattr_setpshared", (char*) pthread_condattr_setpshared  },
        { "display_optional_info_title", (char*) display_optional_info_title  },
        { "display_stack_info_title", (char*) display_stack_info_title  },
        { "display_task_base_info_title", (char*) display_task_base_info_title  },
        { "getpid", (char*) getpid  },
        { "getuid", (char*) getuid  },
        { "pathconf", (char*) pathconf  },
        { "pthread_base_info_display", (char*) pthread_base_info_display  },
        { "pthread_equal", (char*) pthread_equal  },
        { "pthread_get_policy", (char*) pthread_get_policy  },
        { "pthread_getid", (char*) pthread_getid  },
        { "pthread_getinfo", (char*) pthread_getinfo  },
        { "pthread_getname", (char*) pthread_getname  },
        { "pthread_getregs", (char*) pthread_getregs  },
        { "pthread_getschedprio", (char*) pthread_getschedprio  },
        { "pthread_info_display", (char*) pthread_info_display  },
        { "pthread_is_ready", (char*) pthread_is_ready  },
        { "pthread_is_suspend", (char*) pthread_is_suspend  },
        { "pthread_optional_info_display", (char*) pthread_optional_info_display  },
        { "pthread_show", (char*) pthread_show  },
        { "pthread_showstack", (char*) pthread_showstack  },
        { "pthread_showstackframe", (char*) pthread_showstackframe  },
        { "pthread_stack_info_display", (char*) pthread_stack_info_display  },
        { "pthread_state", (char*) pthread_state  },
        { "pthread_verifyid", (char*) pthread_verifyid  },
        { "pthreadDeleteTable", (char*) &pthreadDeleteTable  },
        { "pthreadSwitchTable", (char*) &pthreadSwitchTable  },
        { "traceFunction", (char*) traceFunction  },
        { "pthread_close_hook_add", (char*) pthread_close_hook_add  },
        { "pthread_close_hook_delete", (char*) pthread_close_hook_delete  },
        { "pthread_create_hook_add", (char*) pthread_create_hook_add  },
        { "pthread_create_hook_delete", (char*) pthread_create_hook_delete  },
        { "pthread_switch_hook_add", (char*) pthread_switch_hook_add  },
        { "pthread_switch_hook_delete", (char*) pthread_switch_hook_delete  },
        { "pthreadCreateHook", (char*) pthreadCreateHook  },
        { "pthreadDeleteHook", (char*) pthreadDeleteHook  },
        { "pthreadHookInit", (char*) pthreadHookInit  },
        { "pthreadSwitchHook", (char*) pthreadSwitchHook  },
        { "pthread_get_control_block", (char*) pthread_get_control_block  },
        { "pthread_getspecific", (char*) pthread_getspecific  },
        { "pthread_key_create", (char*) pthread_key_create  },
        { "pthread_key_delete", (char*) pthread_key_delete  },
        { "pthread_key_init", (char*) pthread_key_init  },
        { "pthread_key_mem_free", (char*) pthread_key_mem_free  },
        { "pthread_key_mem_malloc", (char*) pthread_key_mem_malloc  },
        { "pthread_setspecific", (char*) pthread_setspecific  },
        { "pthreadKeyHook", (char*) pthreadKeyHook  },
        { "pthread_mutex_destroy", (char*) pthread_mutex_destroy  },
        { "pthread_mutex_getinfo", (char*) pthread_mutex_getinfo  },
        { "pthread_mutex_getprioceiling", (char*) pthread_mutex_getprioceiling  },
        { "pthread_mutex_init", (char*) pthread_mutex_init  },
        { "pthread_mutex_lock", (char*) pthread_mutex_lock  },
        { "pthread_mutex_module_init", (char*) pthread_mutex_module_init  },
        { "pthread_mutex_show", (char*) pthread_mutex_show  },
        { "pthread_mutex_timedlock", (char*) pthread_mutex_timedlock  },
        { "pthread_mutex_trylock", (char*) pthread_mutex_trylock  },
        { "pthread_mutex_unlock", (char*) pthread_mutex_unlock  },
        { "pthread_mutexattr_destroy", (char*) pthread_mutexattr_destroy  },
        { "pthread_mutexattr_getcancelsafe", (char*) pthread_mutexattr_getcancelsafe  },
        { "pthread_mutexattr_getprioceiling", (char*) pthread_mutexattr_getprioceiling  },
        { "pthread_mutexattr_getprotocol", (char*) pthread_mutexattr_getprotocol  },
        { "pthread_mutexattr_getpshared", (char*) pthread_mutexattr_getpshared  },
        { "pthread_mutexattr_gettype", (char*) pthread_mutexattr_gettype  },
        { "pthread_mutexattr_getwaitqtype", (char*) pthread_mutexattr_getwaitqtype  },
        { "pthread_mutexattr_init", (char*) pthread_mutexattr_init  },
        { "pthread_mutexattr_setcancelsafe", (char*) pthread_mutexattr_setcancelsafe  },
        { "pthread_mutexattr_setprioceiling", (char*) pthread_mutexattr_setprioceiling  },
        { "pthread_mutexattr_setprotocol", (char*) pthread_mutexattr_setprotocol  },
        { "pthread_mutexattr_setpshared", (char*) pthread_mutexattr_setpshared  },
        { "pthread_mutexattr_settype", (char*) pthread_mutexattr_settype  },
        { "pthread_mutexattr_setwaitqtype", (char*) pthread_mutexattr_setwaitqtype  },
        { "pthread_once", (char*) pthread_once  },
        { "pthread_rwlock_destroy", (char*) pthread_rwlock_destroy  },
        { "pthread_rwlock_getinfo", (char*) pthread_rwlock_getinfo  },
        { "pthread_rwlock_init", (char*) pthread_rwlock_init  },
        { "pthread_rwlock_module_init", (char*) pthread_rwlock_module_init  },
        { "pthread_rwlock_rdlock", (char*) pthread_rwlock_rdlock  },
        { "pthread_rwlock_timedrdlock", (char*) pthread_rwlock_timedrdlock  },
        { "pthread_rwlock_timedwrlock", (char*) pthread_rwlock_timedwrlock  },
        { "pthread_rwlock_tryrdlock", (char*) pthread_rwlock_tryrdlock  },
        { "pthread_rwlock_trywrlock", (char*) pthread_rwlock_trywrlock  },
        { "pthread_rwlock_unlock", (char*) pthread_rwlock_unlock  },
        { "pthread_rwlock_wrlock", (char*) pthread_rwlock_wrlock  },
        { "pthread_rwlockattr_destroy", (char*) pthread_rwlockattr_destroy  },
        { "pthread_rwlockattr_getpshared", (char*) pthread_rwlockattr_getpshared  },
        { "pthread_rwlockattr_init", (char*) pthread_rwlockattr_init  },
        { "pthread_rwlockattr_setpshared", (char*) pthread_rwlockattr_setpshared  },
        { "pthread_addvar", (char*) pthread_addvar  },
        { "pthread_delvar", (char*) pthread_delvar  },
        { "pthread_getvar", (char*) pthread_getvar  },
        { "pthread_setvar", (char*) pthread_setvar  },
        { "pthreadDeleteVarHook", (char*) pthreadDeleteVarHook  },
        { "pthreadSwitchVarHook", (char*) pthreadSwitchVarHook  },
        { "pthreadVarInit", (char*) pthreadVarInit  },
        { "sched_get_priority_max", (char*) sched_get_priority_max  },
        { "sched_get_priority_min", (char*) sched_get_priority_min  },
        { "sched_getparam", (char*) sched_getparam  },
        { "sched_getscheduler", (char*) sched_getscheduler  },
        { "sched_gettimeslice", (char*) sched_gettimeslice  },
        { "sched_rr_get_interval", (char*) sched_rr_get_interval  },
        { "sched_setparam", (char*) sched_setparam  },
        { "sched_setscheduler", (char*) sched_setscheduler  },
        { "sched_settimeslice", (char*) sched_settimeslice  },
        { "sched_yield", (char*) sched_yield  },
        { "sem_close", (char*) sem_close  },
        { "sem_destroy", (char*) sem_destroy  },
        { "sem_flush", (char*) sem_flush  },
        { "sem_getinfo", (char*) sem_getinfo  },
        { "sem_getvalue", (char*) sem_getvalue  },
        { "sem_init", (char*) sem_init  },
        { "sem_module_init", (char*) sem_module_init  },
        { "sem_open", (char*) sem_open  },
        { "sem_post", (char*) sem_post  },
        { "sem_show", (char*) sem_show  },
        { "sem_timedwait", (char*) sem_timedwait  },
        { "sem_trywait", (char*) sem_trywait  },
        { "sem_unlink", (char*) sem_unlink  },
        { "sem_wait", (char*) sem_wait  },
        { "kill", (char*) kill  },
        { "pthread_kill", (char*) pthread_kill  },
        { "raise", (char*) raise  },
        { "sigaction", (char*) sigaction  },
        { "sigaddset", (char*) sigaddset  },
        { "sigdelset", (char*) sigdelset  },
        { "sigemptyset", (char*) sigemptyset  },
        { "sigfillset", (char*) sigfillset  },
        { "sighold", (char*) sighold  },
        { "sigignore", (char*) sigignore  },
        { "sigismember", (char*) sigismember  },
        { "signal", (char*) signal  },
        { "signalsWaitQueue", (char*) &signalsWaitQueue  },
        { "sigpause", (char*) sigpause  },
        { "sigpending", (char*) sigpending  },
        { "sigprocmask", (char*) sigprocmask  },
        { "sigqueue", (char*) sigqueue  },
        { "sigrelse", (char*) sigrelse  },
        { "sigsuspend", (char*) sigsuspend  },
        { "sigtimedwait", (char*) sigtimedwait  },
        { "sigwait", (char*) sigwait  },
        { "sigwaitinfo", (char*) sigwaitinfo  },
        { "ttosDispatchSignal", (char*) ttosDispatchSignal  },
        { "ttosInitTaskSignal", (char*) ttosInitTaskSignal  },
        { "ttosSignalInit", (char*) ttosSignalInit  },
        { "ttosSigSuspendWait", (char*) ttosSigSuspendWait  },
        { "calcdiffNs", (char*) calcdiffNs  },
        { "clock_nanosleep", (char*) clock_nanosleep  },
        { "clock_nanosleep_tasks_init", (char*) clock_nanosleep_tasks_init  },
        { "modify_clock_nanosleep_task_ticks", (char*) modify_clock_nanosleep_task_ticks  },
        { "nanosleep", (char*) nanosleep  },
        { "nanosleep_task_hash_table", (char*) &nanosleep_task_hash_table  },
        { "sleep", (char*) sleep  },
        { "usleep", (char*) usleep  },
        { "sysconf", (char*) sysconf  },
        { "addSigevThreadSigCounts", (char*) addSigevThreadSigCounts  },
        { "clockTimespecToTicks", (char*) clockTimespecToTicks  },
        { "helpActiveTimer", (char*) helpActiveTimer  },
        { "threadTimerID", (char*) &threadTimerID  },
        { "ticks2Timespec", (char*) ticks2Timespec  },
        { "timer_create", (char*) timer_create  },
        { "timer_delete", (char*) timer_delete  },
        { "timer_getinfo", (char*) timer_getinfo  },
        { "timer_getoverrun", (char*) timer_getoverrun  },
        { "timer_gettime", (char*) timer_gettime  },
        { "timer_init", (char*) timer_init  },
        { "timer_settime", (char*) timer_settime  },
        { "update_posix_timer", (char*) update_posix_timer  },
        { "wdg_cancel", (char*) wdg_cancel  },
        { "wdg_create", (char*) wdg_create  },
        { "wdg_delete", (char*) wdg_delete  },
        { "wdg_getinfo", (char*) wdg_getinfo  },
        { "wdg_init", (char*) wdg_init  },
        { "wdg_show", (char*) wdg_show  },
        { "wdg_start", (char*) wdg_start  },
        { "TTOS_CreateSema", (char*) TTOS_CreateSema  },
        { "ttosInitSema", (char*) ttosInitSema  },
        { "ttosSemaIsMutex", (char*) ttosSemaIsMutex  },
        { "TTOS_DeleteSema", (char*) TTOS_DeleteSema  },
        { "TTOS_FlushSema", (char*) TTOS_FlushSema  },
        { "TTOS_GetSemaCount", (char*) TTOS_GetSemaCount  },
        { "TTOS_GetSemaExtendPointer", (char*) TTOS_GetSemaExtendPointer  },
        { "TTOS_GetSemaID", (char*) TTOS_GetSemaID  },
        { "TTOS_GetSemaInfo", (char*) TTOS_GetSemaInfo  },
        { "TTOS_GetSemaIdList", (char*) TTOS_GetSemaIdList  },
        { "TTOS_GetSemaName", (char*) TTOS_GetSemaName  },
        { "TTOS_ObtainSema", (char*) TTOS_ObtainSema  },
        { "TTOS_ReleaseSema", (char*) TTOS_ReleaseSema  },
        { "TTOS_SetSemaExtendPointer", (char*) TTOS_SetSemaExtendPointer  },
        { "app_main", (char*) app_main  },
        { "AutoStartAPP", (char*) AutoStartAPP  },
        { "CheckFilePath", (char*) CheckFilePath  },
        { "ShellStartAPP", (char*) ShellStartAPP  },
        { "ShellStopAPP", (char*) ShellStopAPP  },
        { "testAPPDynamicLoad", (char*) testAPPDynamicLoad  },
        { "testAPPDynamicLoadInit", (char*) testAPPDynamicLoadInit  },
        { "testShareLibDynamicLoadInit", (char*) testShareLibDynamicLoadInit  },
        { "travel_app_from_dir", (char*) travel_app_from_dir  },
        { "TTOS_ActiveTask", (char*) TTOS_ActiveTask  },
        { "ttosClearTaskReady", (char*) ttosClearTaskReady  },
        { "ttosClearTaskWaiting", (char*) ttosClearTaskWaiting  },
        { "TTOS_CreateTask", (char*) TTOS_CreateTask  },
        { "ttosInitTask", (char*) ttosInitTask  },
        { "ttosSetPWaitAndExpireTick", (char*) ttosSetPWaitAndExpireTick  },
        { "taskDeleteSelfHandler", (char*) taskDeleteSelfHandler  },
        { "TTOS_DeleteTask", (char*) TTOS_DeleteTask  },
        { "ttosDeleteHandlerTaskID", (char*) &ttosDeleteHandlerTaskID  },
        { "ttosDeleteTaskStackProtect", (char*) ttosDeleteTaskStackProtect  },
        { "ttosFreeStackRoutine", (char*) &ttosFreeStackRoutine  },
        { "ttosSetFreeStackRoutine", (char*) ttosSetFreeStackRoutine  },
        { "ttosTaskExit", (char*) ttosTaskExit  },
        { "ttosDequeueFifo", (char*) ttosDequeueFifo  },
        { "ttosDequeuePriority", (char*) ttosDequeuePriority  },
        { "ttosDequeueTaskFromTaskq", (char*) ttosDequeueTaskFromTaskq  },
        { "ttosDequeueTaskq", (char*) ttosDequeueTaskq  },
        { "ttosGetFirstPriorityTask", (char*) ttosGetFirstPriorityTask  },
        { "TTOS_DisablePreempt", (char*) TTOS_DisablePreempt  },
        { "TTOS_EnablePreempt", (char*) TTOS_EnablePreempt  },
        { "ttosEnqueueFifo", (char*) ttosEnqueueFifo  },
        { "ttosEnqueuePriority", (char*) ttosEnqueuePriority  },
        { "ttosEnqueuePriorityFront", (char*) ttosEnqueuePriorityFront  },
        { "ttosEnqueueTaskq", (char*) ttosEnqueueTaskq  },
        { "ttosEnqueueTaskqPriorityFront", (char*) ttosEnqueueTaskqPriorityFront  },
        { "ttosExactWaitedPeriodTask", (char*) ttosExactWaitedPeriodTask  },
        { "ttosExactWaitedTask", (char*) ttosExactWaitedTask  },
        { "ttosExtractTaskq", (char*) ttosExtractTaskq  },
        { "TTOS_GetTaskContext", (char*) TTOS_GetTaskContext  },
        { "TTOS_GetTaskCount", (char*) TTOS_GetTaskCount  },
        { "TTOS_GetIdleTaskExecutedTicks", (char*) TTOS_GetIdleTaskExecutedTicks  },
        { "TTOS_GetIdleTaskExecutedTicksWithCpuID", (char*) TTOS_GetIdleTaskExecutedTicksWithCpuID  },
        { "TTOS_GetTaskExecutedTicks", (char*) TTOS_GetTaskExecutedTicks  },
        { "TTOS_SetTaskExecutedTicks", (char*) TTOS_SetTaskExecutedTicks  },
        { "TTOS_GetTaskID", (char*) TTOS_GetTaskID  },
        { "TTOS_GetTaskIdList", (char*) TTOS_GetTaskIdList  },
        { "TTOS_GetTaskInfo", (char*) TTOS_GetTaskInfo  },
        { "ttosGetTaskInfo", (char*) ttosGetTaskInfo  },
        { "TTOS_GetTaskName", (char*) TTOS_GetTaskName  },
        { "TTOS_GetTaskOriginPriority", (char*) TTOS_GetTaskOriginPriority  },
        { "TTOS_GetTaskPriority", (char*) TTOS_GetTaskPriority  },
        { "TTOS_GetTaskStackInfo", (char*) TTOS_GetTaskStackInfo  },
        { "ttosTaskStackFilledFlag", (char*) &ttosTaskStackFilledFlag  },
        { "TTOS_GetTaskState", (char*) TTOS_GetTaskState  },
        { "TTOS_GetTaskStdFd", (char*) TTOS_GetTaskStdFd  },
        { "ttosInsertWaitedPeriodTask", (char*) ttosInsertWaitedPeriodTask  },
        { "ttosInsertWaitedTask", (char*) ttosInsertWaitedTask  },
        { "ttosPeriodExpireNotify", (char*) ttosPeriodExpireNotify  },
        { "expireWaitedQueueTmp", (char*) &expireWaitedQueueTmp  },
        { "periodWaitedQueueTmp", (char*) &periodWaitedQueueTmp  },
        { "ttosPeriodExpireQueueModify", (char*) ttosPeriodExpireQueueModify  },
        { "ttosPeriodQueueMerge", (char*) ttosPeriodQueueMerge  },
        { "ttosPeriodWaitQueueModify", (char*) ttosPeriodWaitQueueModify  },
        { "ttosPeriodWaitNotify", (char*) ttosPeriodWaitNotify  },
        { "TTOS_ReplenishTask", (char*) TTOS_ReplenishTask  },
        { "TTOS_ResetTask", (char*) TTOS_ResetTask  },
        { "TTOS_ResumeTask", (char*) TTOS_ResumeTask  },
        { "ttosDisableScheduleLevel", (char*) &ttosDisableScheduleLevel  },
        { "ttosGetCandidateTask", (char*) ttosGetCandidateTask  },
        { "ttosGlobalPriorityBitMap", (char*) &ttosGlobalPriorityBitMap  },
        { "ttosIsNeedRescheduleWithCpuId", (char*) ttosIsNeedRescheduleWithCpuId  },
        { "ttosPriorityBitMap", (char*) &ttosPriorityBitMap  },
        { "ttosSchedule", (char*) ttosSchedule  },
        { "ttosScheduleInIntDisAndKernelLock", (char*) ttosScheduleInIntDisAndKernelLock  },
        { "ttosScheduleInKernelLock", (char*) ttosScheduleInKernelLock  },
        { "TTOS_SetDelayTime", (char*) TTOS_SetDelayTime  },
        { "ttosSetTaskReady", (char*) ttosSetTaskReady  },
        { "TTOS_SetTaskStackProtect", (char*) TTOS_SetTaskStackProtect  },
        { "TTOS_SetTaskStdFd", (char*) TTOS_SetTaskStdFd  },
        { "TTOS_Modify_SleepTask", (char*) TTOS_Modify_SleepTask  },
        { "TTOS_NanoSleepTask", (char*) TTOS_NanoSleepTask  },
        { "TTOS_SleepTask", (char*) TTOS_SleepTask  },
        { "TTOS_StopTask", (char*) TTOS_StopTask  },
        { "ttosInitTaskParam", (char*) ttosInitTaskParam  },
        { "ttosStopTask", (char*) ttosStopTask  },
        { "TTOS_SuspendTask", (char*) TTOS_SuspendTask  },
        { "ttosSuspendTask", (char*) ttosSuspendTask  },
        { "posix_spawn", (char*) posix_spawn  },
        { "ttosFlushTaskq", (char*) ttosFlushTaskq  },
        { "ttosInitializeTaskq", (char*) ttosInitializeTaskq  },
        { "ttosTaskqIsEmpty", (char*) ttosTaskqIsEmpty  },
        { "_errno", (char*) _errno  },
        { "isRTaskNeedReSchedule", (char*) isRTaskNeedReSchedule  },
        { "occupy_tbl_get", (char*) occupy_tbl_get  },
        { "pthreadTickSlice", (char*) &pthreadTickSlice  },
        { "taskChangePriority", (char*) taskChangePriority  },
        { "TTOS_GetTaskAffinity", (char*) TTOS_GetTaskAffinity  },
        { "TTOS_IsAllRunningAndCandidateTaskIdleTask", (char*) TTOS_IsAllRunningAndCandidateTaskIdleTask  },
        { "TTOS_SetTaskAffinity", (char*) TTOS_SetTaskAffinity  },
        { "ttosDisableTaskDispatch", (char*) ttosDisableTaskDispatch  },
        { "ttosDisableTaskDispatchWithLock", (char*) ttosDisableTaskDispatchWithLock  },
        { "ttosEnableTaskDispatch", (char*) ttosEnableTaskDispatch  },
        { "ttosEnableTaskDispatchWithLock", (char*) ttosEnableTaskDispatchWithLock  },
        { "ttosGetCurrentCpuRunningTask", (char*) ttosGetCurrentCpuRunningTask  },
        { "ttosGetIdleTask", (char*) ttosGetIdleTask  },
        { "ttosGetIdleTaskWithCpuID", (char*) ttosGetIdleTaskWithCpuID  },
        { "ttosGetRunningTaskName", (char*) ttosGetRunningTaskName  },
        { "ttosGetUnReserveCpuLowestRTask", (char*) ttosGetUnReserveCpuLowestRTask  },
        { "ttosGTaskRQueuePut", (char*) ttosGTaskRQueuePut  },
        { "ttosGTaskRQueueRemove", (char*) ttosGTaskRQueueRemove  },
        { "ttosRotateRunningTask", (char*) ttosRotateRunningTask  },
        { "ttosSetTaskState", (char*) ttosSetTaskState  },
        { "ttosShowInfo", (char*) ttosShowInfo  },
        { "ttosTaskStateChanged", (char*) ttosTaskStateChanged  },
        { "wait_tbl_get", (char*) wait_tbl_get  },
        { "ttosTickNotify", (char*) ttosTickNotify  },
        { "TTOS_WaitPeriod", (char*) TTOS_WaitPeriod  },
        { "tbspInit", (char*) tbspInit  },
        { "TTOS_SetPageDisableCache", (char*) TTOS_SetPageDisableCache  },
        { "TTOS_SetPageEnableCache", (char*) TTOS_SetPageEnableCache  },
        { "cpuFreqGet", (char*) cpuFreqGet  },
        { "cpuTimeGet", (char*) cpuTimeGet  },
        { "jiffies", (char*) &jiffies  },
        { "pexpireCurrentTicks", (char*) &pexpireCurrentTicks  },
        { "pexpireTicks", (char*) &pexpireTicks  },
        { "pwaitCurentTicks", (char*) &pwaitCurentTicks  },
        { "pwaitTicks", (char*) &pwaitTicks  },
        { "tbspClockNotify", (char*) tbspClockNotify  },
        { "tbspGetPExpireTick", (char*) tbspGetPExpireTick  },
        { "tbspGetPWaitTick", (char*) tbspGetPWaitTick  },
        { "tbspInitVTimer", (char*) tbspInitVTimer  },
        { "tbspSetPExpireTick", (char*) tbspSetPExpireTick  },
        { "tbspSetPWaitTick", (char*) tbspSetPWaitTick  },
        { "tickCount", (char*) &tickCount  },
        { "tickIsrIpiReschedulecpus", (char*) &tickIsrIpiReschedulecpus  },
        { "TTOS_GetCurrentSystemCount", (char*) TTOS_GetCurrentSystemCount  },
        { "TTOS_GetCurrentSystemFreq", (char*) TTOS_GetCurrentSystemFreq  },
        { "TTOS_GetCurrentSystemSubTime", (char*) TTOS_GetCurrentSystemSubTime  },
        { "TTOS_GetCurrentSystemTime", (char*) TTOS_GetCurrentSystemTime  },
        { "TTOS_GetOneCpuRunningTicks", (char*) TTOS_GetOneCpuRunningTicks  },
        { "TTOS_GetRunningTicks", (char*) TTOS_GetRunningTicks  },
        { "TTOS_GetSysClkRate", (char*) TTOS_GetSysClkRate  },
        { "TTOS_GetSystemTicks", (char*) TTOS_GetSystemTicks  },
        { "TTOS_SetSysClkRate", (char*) TTOS_SetSysClkRate  },
        { "TTOS_SetSystemTicks", (char*) TTOS_SetSystemTicks  },
        { "ttosGetSystemTicks", (char*) ttosGetSystemTicks  },
        { "ttosTickCount", (char*) &ttosTickCount  },
        { "apStart", (char*) apStart  },
        { "fpscrAsmInit", (char*) fpscrAsmInit  },
        { "idleTaskEntryLoad", (char*) idleTaskEntryLoad  },
        { "tbspGetMSB", (char*) tbspGetMSB  },
        { "tbspLoadStack", (char*) tbspLoadStack  },
        { "tbspRestoreTaskContext", (char*) tbspRestoreTaskContext  },
        { "tbspSaveTaskContext", (char*) tbspSaveTaskContext  },
        { "intCpuLock", (char*) intCpuLock  },
        { "intCpuUnlock", (char*) intCpuUnlock  },
        { "tbspClearGlobalInt", (char*) tbspClearGlobalInt  },
        { "tbspSetGlobalInt", (char*) tbspSetGlobalInt  },
        { "tbspApInitVint", (char*) tbspApInitVint  },
        { "tbspInitVint", (char*) tbspInitVint  },
        { "tbspTickVIntNestLevel", (char*) &tbspTickVIntNestLevel  },
        { "tbspVIntNestLevel", (char*) &tbspVIntNestLevel  },
        { "tbspVintStackBottom", (char*) &tbspVintStackBottom  },
        { "tbspVintStackStart", (char*) &tbspVintStackStart  },
        { "tbspVintStackTop", (char*) &tbspVintStackTop  },
        { "ttosDecTickIntNestLevel", (char*) ttosDecTickIntNestLevel  },
        { "ttosGetIntNestLevel", (char*) ttosGetIntNestLevel  },
        { "ttosGetIntStackBottom", (char*) ttosGetIntStackBottom  },
        { "ttosGetIntStackStart", (char*) ttosGetIntStackStart  },
        { "ttosGetIntStackTop", (char*) ttosGetIntStackTop  },
        { "ttosGetTickIntNestLevel", (char*) ttosGetTickIntNestLevel  },
        { "ttosIncTickIntNestLevel", (char*) ttosIncTickIntNestLevel  },
        { "ttosMSRAdress", (char*) &ttosMSRAdress  },
        { "ttosSetIntStackBottom", (char*) ttosSetIntStackBottom  },
        { "ttosSetIntStackStart", (char*) ttosSetIntStackStart  },
        { "ttosSetIntStackTop", (char*) ttosSetIntStackTop  },
        { "ttosSetMSRAdress", (char*) ttosSetMSRAdress  },
        { "tbspVintHandler", (char*) tbspVintHandler  },
        { "cpu_down", (char*) cpu_down  },
        { "cpu_reserve", (char*) cpu_reserve  },
        { "cpu_unreserve", (char*) cpu_unreserve  },
        { "cpu_up", (char*) cpu_up  },
        { "cpuEnabledNumGet", (char*) cpuEnabledNumGet  },
        { "cpuEnabledSetGet", (char*) cpuEnabledSetGet  },
        { "cpuNumGet", (char*) cpuNumGet  },
        { "cpuReservedSetGet", (char*) cpuReservedSetGet  },
        { "ipiEmit", (char*) ipiEmit  },
        { "ipiRescheduleEmit", (char*) ipiRescheduleEmit  },
        { "slaveCoreStackTop", (char*) &slaveCoreStackTop  },
        { "smpInit", (char*) smpInit  },
        { "ttosConfigCpuNum", (char*) &ttosConfigCpuNum  },
        { "ttosEnabledCpuSet", (char*) &ttosEnabledCpuSet  },
        { "ttosReservedCpuSet", (char*) &ttosReservedCpuSet  },
        { "TTOS_MapAllocIOPage", (char*) TTOS_MapAllocIOPage  },
        { "TTOS_MapIOPage", (char*) TTOS_MapIOPage  },
        { "TTOS_MapRamReadPage", (char*) TTOS_MapRamReadPage  },
        { "ttosMemProbeByteRead", (char*) ttosMemProbeByteRead  },
        { "ttosMemProbeByteWrite", (char*) ttosMemProbeByteWrite  },
        { "ttosMemProbeErrorRtn", (char*) ttosMemProbeErrorRtn  },
        { "ttosMemProbeLongRead", (char*) ttosMemProbeLongRead  },
        { "ttosMemProbeLongWrite", (char*) ttosMemProbeLongWrite  },
        { "ttosMemProbeOnlyRead", (char*) ttosMemProbeOnlyRead  },
        { "ttosMemProbeOnlyReadByte", (char*) ttosMemProbeOnlyReadByte  },
        { "ttosMemProbeOnlyReadErrorRtn", (char*) ttosMemProbeOnlyReadErrorRtn  },
        { "ttosMemProbeOnlyReadHalfWord", (char*) ttosMemProbeOnlyReadHalfWord  },
        { "ttosMemProbeOnlyReadWord", (char*) ttosMemProbeOnlyReadWord  },
        { "ttosMemProbeOnlyWrite", (char*) ttosMemProbeOnlyWrite  },
        { "ttosMemProbeOnlyWriteByte", (char*) ttosMemProbeOnlyWriteByte  },
        { "ttosMemProbeOnlyWriteErrorRtn", (char*) ttosMemProbeOnlyWriteErrorRtn  },
        { "ttosMemProbeOnlyWriteHalfWord", (char*) ttosMemProbeOnlyWriteHalfWord  },
        { "ttosMemProbeOnlyWriteWord", (char*) ttosMemProbeOnlyWriteWord  },
        { "ttosMemProbeSup", (char*) ttosMemProbeSup  },
        { "ttosMemProbeWordRead", (char*) ttosMemProbeWordRead  },
        { "ttosMemProbeWordWrite", (char*) ttosMemProbeWordWrite  },
        { "ttosMemProbeInit", (char*) ttosMemProbeInit  },
        { "ttosMemReadCheck", (char*) ttosMemReadCheck  },
        { "ttosMemRWCheck", (char*) ttosMemRWCheck  },
        { "ttosMemTest", (char*) ttosMemTest  },
        { "ttosMemWriteCheck", (char*) ttosMemWriteCheck  },
        { "ttosVerifyObjectCore", (char*) ttosVerifyObjectCore  },
        { "ttosVerifyObjectCoreError", (char*) ttosVerifyObjectCoreError  },
        { "ttosVerifyObjectCoreMagicRead", (char*) ttosVerifyObjectCoreMagicRead  },
        { "ttosVerifyObjectCoreTypeRead", (char*) ttosVerifyObjectCoreTypeRead  },
        { "ttosObjArchLibInit", (char*) ttosObjArchLibInit  },
        { "osExcBaseHook", (char*) &osExcBaseHook  },
        { "TTOS_AllocVector", (char*) TTOS_AllocVector  },
        { "TTOS_DisablePIC", (char*) TTOS_DisablePIC  },
        { "TTOS_EnablePIC", (char*) TTOS_EnablePIC  },
        { "TTOS_ExceptionHandlerSet", (char*) TTOS_ExceptionHandlerSet  },
        { "TTOS_InstallIntHandler", (char*) TTOS_InstallIntHandler  },
        { "TTOS_InstallSharedVintHandler", (char*) TTOS_InstallSharedVintHandler  },
        { "TTOS_InstallVintHandler", (char*) TTOS_InstallVintHandler  },
        { "TTOS_MapExintToVint", (char*) TTOS_MapExintToVint  },
        { "TTOS_SetIsrStackProtect", (char*) TTOS_SetIsrStackProtect  },
        { "TTOS_UnInstallSharedVintHandler", (char*) TTOS_UnInstallSharedVintHandler  },
        { "TTOS_UninstallVintHandler", (char*) TTOS_UninstallVintHandler  },
        { "ttosDispatchVint", (char*) ttosDispatchVint  },
        { "ttosExceptionDefaultHandler", (char*) ttosExceptionDefaultHandler  },
        { "ttosExIntDefaultHandler", (char*) ttosExIntDefaultHandler  },
        { "ttosInstallVintHandlerWithParam", (char*) ttosInstallVintHandlerWithParam  },
        { "ttosIsISR", (char*) ttosIsISR  },
        { "ttosIsTickISR", (char*) ttosIsTickISR  },
        { "ttosServIntDefaultHandler", (char*) ttosServIntDefaultHandler  },
        { "ttosTickIntDefaultHandler", (char*) ttosTickIntDefaultHandler  },
        { "ttosUnInstallVintHandlerWithParam", (char*) ttosUnInstallVintHandlerWithParam  },
        { "ttosVintDefaultHandlerInit", (char*) ttosVintDefaultHandlerInit  },
        { "TTOS_ActiveTimer", (char*) TTOS_ActiveTimer  },
        { "TTOS_UpdateTimer", (char*) TTOS_UpdateTimer  },
        { "TTOS_CreateTimer", (char*) TTOS_CreateTimer  },
        { "ttosInitTimer", (char*) ttosInitTimer  },
        { "TTOS_DeleteTimer", (char*) TTOS_DeleteTimer  },
        { "ttosExactWaitedTimer", (char*) ttosExactWaitedTimer  },
        { "TTOS_GetTimerCount", (char*) TTOS_GetTimerCount  },
        { "TTOS_GetTimerID", (char*) TTOS_GetTimerID  },
        { "TTOS_GetTimerIdList", (char*) TTOS_GetTimerIdList  },
        { "getTimerMaxNum", (char*) getTimerMaxNum  },
        { "TTOS_GetTimerInfo", (char*) TTOS_GetTimerInfo  },
        { "TTOS_GetTimerName", (char*) TTOS_GetTimerName  },
        { "TTOS_GetTimerState", (char*) TTOS_GetTimerState  },
        { "ttosInsertWaitedTimer", (char*) ttosInsertWaitedTimer  },
        { "TTOS_InstallTimer", (char*) TTOS_InstallTimer  },
        { "TTOS_SetTimerTicks", (char*) TTOS_SetTimerTicks  },
        { "TTOS_StopTimer", (char*) TTOS_StopTimer  },
        { "ttosTimerNotify", (char*) ttosTimerNotify  },
        { "spin_lock", (char*) spin_lock  },
        { "spin_lock_disable_monitor", (char*) spin_lock_disable_monitor  },
        { "spin_lock_enable_monitor", (char*) spin_lock_enable_monitor  },
        { "spin_lock_init", (char*) spin_lock_init  },
        { "spin_lock_irq", (char*) spin_lock_irq  },
        { "spin_lock_raw", (char*) spin_lock_raw  },
        { "spin_trylock", (char*) spin_trylock  },
        { "spin_trylock_irq", (char*) spin_trylock_irq  },
        { "spin_trylock_raw", (char*) spin_trylock_raw  },
        { "spin_unlock", (char*) spin_unlock  },
        { "spin_unlock_irq", (char*) spin_unlock_irq  },
        { "spin_unlock_raw", (char*) spin_unlock_raw  },
        { "ttosIsKernelLockOwner", (char*) ttosIsKernelLockOwner  },
        { "ttosKernelLockInit", (char*) ttosKernelLockInit  },
        { "ttosKernelLockVar", (char*) &ttosKernelLockVar  },
        { "ttosCompareName", (char*) ttosCompareName  },
        { "ttosCompareVerison", (char*) ttosCompareVerison  },
        { "ttosCopyName", (char*) ttosCopyName  },
        { "ttosCopyVersion", (char*) ttosCopyVersion  },
        { "TTOS_GetKernelInfo", (char*) TTOS_GetKernelInfo  },
        { "TTOS_GetWaitLeastTicks", (char*) TTOS_GetWaitLeastTicks  },
        { "ttosAllocateHeap", (char*) ttosAllocateHeap  },
        { "ttosFreeHeap", (char*) ttosFreeHeap  },
        { "ttosInitHeap", (char*) ttosInitHeap  },
        { "TTOS_ResetOs", (char*) TTOS_ResetOs  },
        { "ttosConvertVMKReturnCode", (char*) ttosConvertVMKReturnCode  },
        { "ttosCreateRingBuffer", (char*) ttosCreateRingBuffer  },
        { "ttosGetRingBuffer", (char*) ttosGetRingBuffer  },
        { "ttosGetRingBufferEx", (char*) ttosGetRingBufferEx  },
        { "ttosInitRingBuffer", (char*) ttosInitRingBuffer  },
        { "ttosPutRingBuffer", (char*) ttosPutRingBuffer  },
        { "ttosPutRingBufferEx", (char*) ttosPutRingBufferEx  },
        { "ttosRingBufferDataBytes", (char*) ttosRingBufferDataBytes  },
        { "ttosRingBufferFreeBytes", (char*) ttosRingBufferFreeBytes  },
        { "ttosRingBufferIsEmpty", (char*) ttosRingBufferIsEmpty  },
        { "ttosRingBufferIsFull", (char*) ttosRingBufferIsFull  },
        { "ttosAllocateObject", (char*) ttosAllocateObject  },
        { "ttosCopyString", (char*) ttosCopyString  },
        { "ttosGetIdByName", (char*) ttosGetIdByName  },
        { "ttosGetIdList", (char*) ttosGetIdList  },
        { "ttosGetObjectById", (char*) ttosGetObjectById  },
        { "ttosGetObjectFromInactiveResource", (char*) ttosGetObjectFromInactiveResource  },
        { "ttosInitObjectCore", (char*) ttosInitObjectCore  },
        { "ttosInvalidObjectCore", (char*) ttosInvalidObjectCore  },
        { "ttosObjectTypeIsOk", (char*) ttosObjectTypeIsOk  },
        { "ttosReturnObjectToInactiveResource", (char*) ttosReturnObjectToInactiveResource  },
        { "ttosChangeName", (char*) ttosChangeName  },
        { "ttosVerifyName", (char*) ttosVerifyName  },
        { "TTOS_IsDisableKernelHeap", (char*) TTOS_IsDisableKernelHeap  },
        { "ttosFreeWorkspace", (char*) ttosFreeWorkspace  },
        { "ttosGetAvailableWorkspaceSize", (char*) ttosGetAvailableWorkspaceSize  },
        { "ttosGetTotalWorkspaceSize", (char*) ttosGetTotalWorkspaceSize  },
        { "ttosInitWorkspace", (char*) ttosInitWorkspace  },
        { "ttosIsDisableWorkspace", (char*) ttosIsDisableWorkspace  },
        { "ttosMallocWorkspace", (char*) ttosMallocWorkspace  },
        { "ttosMallocWorkspaceFatalError", (char*) ttosMallocWorkspaceFatalError  },
        { "ttosMallocWorkspaceRaw", (char*) ttosMallocWorkspaceRaw  },
        { "TTOS_CreateShm", (char*) TTOS_CreateShm  },
        { "TTOS_ReadShm", (char*) TTOS_ReadShm  },
        { "TTOS_WriteShm", (char*) TTOS_WriteShm  },
        { "ttosInitShm", (char*) ttosInitShm  },
        { "ttosShmErrno", (char*) &ttosShmErrno  },
        { "ttosGetShmRingBuffer", (char*) ttosGetShmRingBuffer  },
        { "ttosPutShmRingBuffer", (char*) ttosPutShmRingBuffer  },
        { "ttosGetAvailableShmSize", (char*) ttosGetAvailableShmSize  },
        { "ttosInitShmWorkspace", (char*) ttosInitShmWorkspace  },
        { "ttosMallocShmWorkspace", (char*) ttosMallocShmWorkspace  },
        { "allocate_shared_memory", (char*) allocate_shared_memory  },
        { "open_shared_memory", (char*) open_shared_memory  },
        { "shm_atomic32_cas", (char*) shm_atomic32_cas  },
        { "shm_atomic32_get", (char*) shm_atomic32_get  },
        { "shm_atomic32_set", (char*) shm_atomic32_set  },
        { "shm_configure_system", (char*) shm_configure_system  },
        { "shm_init", (char*) shm_init  },
        { "shm_initialize_system", (char*) shm_initialize_system  },
        { "shm_start_addr", (char*) &shm_start_addr  },
        { "shm_system", (char*) &shm_system  },
        { "shm_system_is_init", (char*) shm_system_is_init  },
        { "shm_mem_region_alloc", (char*) shm_mem_region_alloc  },
        { "shm_mem_region_init", (char*) shm_mem_region_init  },
        { "shm_object_alloc", (char*) shm_object_alloc  },
        { "shm_object_enqueue", (char*) shm_object_enqueue  },
        { "shm_object_find", (char*) shm_object_find  },
        { "shm_object_free", (char*) shm_object_free  },
        { "shm_object_pool_init", (char*) shm_object_pool_init  },
        { "shm_show", (char*) shm_show  },
        { "shm_gettimeofday", (char*) shm_gettimeofday  },
        { "shm_mem_region_get", (char*) shm_mem_region_get  },
        { "shm_set_page_cache", (char*) shm_set_page_cache  },
        { "shm_timer_is_expired", (char*) shm_timer_is_expired  },
        { "shm_timer_start", (char*) shm_timer_start  },
        { "shm_usleep", (char*) shm_usleep  },
        { "fnFSC_Bread", (char*) fnFSC_Bread  },
        { "fnFSC_Brelse", (char*) fnFSC_Brelse  },
        { "fnFSC_Cache_Init", (char*) fnFSC_Cache_Init  },
        { "fnFSC_Clear_Device_cache", (char*) fnFSC_Clear_Device_cache  },
        { "fnFSC_Getblk", (char*) fnFSC_Getblk  },
        { "fnFSC_Init_cache", (char*) fnFSC_Init_cache  },
        { "fnFSC_Mark_Buffer_Dirty", (char*) fnFSC_Mark_Buffer_Dirty  },
        { "fnFSC_Mark_Buffer_Uptodate", (char*) fnFSC_Mark_Buffer_Uptodate  },
        { "fnFSC_Mark_File_Buffer_Dirty", (char*) fnFSC_Mark_File_Buffer_Dirty  },
        { "fnFSC_Refill_Freelist", (char*) fnFSC_Refill_Freelist  },
        { "fnFSC_Sync_Buffer", (char*) fnFSC_Sync_Buffer  },
        { "fnFSC_Sync_Buffers", (char*) fnFSC_Sync_Buffers  },
        { "fnFSC_Sync_File", (char*) fnFSC_Sync_File  },
        { "fnFSC_Unlock_Buffer", (char*) fnFSC_Unlock_Buffer  },
        { "fnFSC_Wait_On_Buffer", (char*) fnFSC_Wait_On_Buffer  },
        { "fnFSC_End_Buffer_Io_Hook", (char*) fnFSC_End_Buffer_Io_Hook  },
        { "fnFSC_Ll_Rw_Block", (char*) fnFSC_Ll_Rw_Block  },
        { "fnFSC_PhysicDev_Operation", (char*) fnFSC_PhysicDev_Operation  },
        { "fnDFS_checkdir", (char*) fnDFS_checkdir  },
        { "fnDFS_close", (char*) fnDFS_close  },
        { "fnDFS_devinfo", (char*) fnDFS_devinfo  },
        { "fnDFS_filelist", (char*) fnDFS_filelist  },
        { "fnDFS_fstat", (char*) fnDFS_fstat  },
        { "fnDFS_ftruncate", (char*) fnDFS_ftruncate  },
        { "fnDFS_getfd", (char*) fnDFS_getfd  },
        { "fnDFS_getFullPathByFd", (char*) fnDFS_getFullPathByFd  },
        { "fnDFS_GetSysFirstLogDevChar", (char*) fnDFS_GetSysFirstLogDevChar  },
        { "fnDFS_ioctl", (char*) fnDFS_ioctl  },
        { "fnDFS_lseek", (char*) fnDFS_lseek  },
        { "fnDFS_mkdir", (char*) fnDFS_mkdir  },
        { "fnDFS_open", (char*) fnDFS_open  },
        { "fnDFS_read", (char*) fnDFS_read  },
        { "fnDFS_remove", (char*) fnDFS_remove  },
        { "fnDFS_rename", (char*) fnDFS_rename  },
        { "fnDFS_rmdir", (char*) fnDFS_rmdir  },
        { "fnDFS_setfd", (char*) fnDFS_setfd  },
        { "fnDFS_stat", (char*) fnDFS_stat  },
        { "fnDFS_utime", (char*) fnDFS_utime  },
        { "fnDFS_write", (char*) fnDFS_write  },
        { "fnDFSAdm_FreeFNode", (char*) fnDFSAdm_FreeFNode  },
        { "fnDFSAdm_GetFNode", (char*) fnDFSAdm_GetFNode  },
        { "fnDFSAdm_GetFreeFNode", (char*) fnDFSAdm_GetFreeFNode  },
        { "fnDFSAdm_GetLockLink", (char*) fnDFSAdm_GetLockLink  },
        { "fnDFSAdm_Init", (char*) fnDFSAdm_Init  },
        { "fnDFSAdm_LockFNode", (char*) fnDFSAdm_LockFNode  },
        { "fnDFSAdm_UnlockFNode", (char*) fnDFSAdm_UnlockFNode  },
        { "fnDFS_CreateSemaphore", (char*) fnDFS_CreateSemaphore  },
        { "fnDFS_DeleteSemaphore", (char*) fnDFS_DeleteSemaphore  },
        { "fnDFS_FillFnodeDirInfo", (char*) fnDFS_FillFnodeDirInfo  },
        { "fnDFS_GetFullPath", (char*) fnDFS_GetFullPath  },
        { "fnDFS_Init", (char*) fnDFS_Init  },
        { "fnDFS_MkFS", (char*) fnDFS_MkFS  },
        { "fnDFS_ObtainSemaphore", (char*) fnDFS_ObtainSemaphore  },
        { "fnDFS_PhysicDevOpen", (char*) fnDFS_PhysicDevOpen  },
        { "fnDFS_PhysicDevRead", (char*) fnDFS_PhysicDevRead  },
        { "fnDFS_PhysicDevWrite", (char*) fnDFS_PhysicDevWrite  },
        { "fnDFS_ReleaseSemaphore", (char*) fnDFS_ReleaseSemaphore  },
        { "fnFAT_Bind", (char*) fnFAT_Bind  },
        { "fnFAT_Unbind", (char*) fnFAT_Unbind  },
        { "uwaDFSSemID", (char*) &uwaDFSSemID  },
        { "fnDFS_AddLDCB", (char*) fnDFS_AddLDCB  },
        { "fnDFS_AddPDCB", (char*) fnDFS_AddPDCB  },
        { "fnDFS_AllocatePDCB", (char*) fnDFS_AllocatePDCB  },
        { "fnDFS_DelLDCB", (char*) fnDFS_DelLDCB  },
        { "fnDFS_FreePDCB", (char*) fnDFS_FreePDCB  },
        { "fnDFS_GetDevLetterWithPDCBAndIndex", (char*) fnDFS_GetDevLetterWithPDCBAndIndex  },
        { "fnDFS_GetLDCB", (char*) fnDFS_GetLDCB  },
        { "fnDFS_GetLDCBNumber", (char*) fnDFS_GetLDCBNumber  },
        { "fnDFS_GetLDCBWithChar", (char*) fnDFS_GetLDCBWithChar  },
        { "fnDFS_GetNewDevChar", (char*) fnDFS_GetNewDevChar  },
        { "fnDFS_GetPDev", (char*) fnDFS_GetPDev  },
        { "fnDFS_InitDev", (char*) fnDFS_InitDev  },
        { "fnDFS_freeDmaMemPage", (char*) fnDFS_freeDmaMemPage  },
        { "fnDFS_mallocDmaMemPage", (char*) fnDFS_mallocDmaMemPage  },
        { "fnDFS_Err2Errno", (char*) fnDFS_Err2Errno  },
        { "waDFSErrorTable", (char*) &waDFSErrorTable  },
        { "fnDFS_DestroyFatBuf", (char*) fnDFS_DestroyFatBuf  },
        { "fnDFS_InitFatBuf", (char*) fnDFS_InitFatBuf  },
        { "ACoreOs_DFS_format", (char*) ACoreOs_DFS_format  },
        { "ACoreOs_DFS_init", (char*) ACoreOs_DFS_init  },
        { "tpFAT_SyncDir", (char*) &tpFAT_SyncDir  },
        { "tpFAT_SyncFat", (char*) &tpFAT_SyncFat  },
        { "ACoreOs_DFS_get_dev_letter_by_partion_index", (char*) ACoreOs_DFS_get_dev_letter_by_partion_index  },
        { "ACoreOs_DFS_mount", (char*) ACoreOs_DFS_mount  },
        { "ACoreOs_DFS_umount", (char*) ACoreOs_DFS_umount  },
        { "devSysstartchar", (char*) &devSysstartchar  },
        { "DFS_GetDevSymbol", (char*) DFS_GetDevSymbol  },
        { "DFS_InitDrvBitmap", (char*) DFS_InitDrvBitmap  },
        { "fnDFS_TodToSeconds", (char*) fnDFS_TodToSeconds  },
        { "uwaDFS_TOD_Days_to_date", (char*) &uwaDFS_TOD_Days_to_date  },
        { "fnFAT16_AddOldName_ForRoot", (char*) fnFAT16_AddOldName_ForRoot  },
        { "fnFAT16_AddToDirEntry_ForRoot", (char*) fnFAT16_AddToDirEntry_ForRoot  },
        { "fnFAT16_CloseDir", (char*) fnFAT16_CloseDir  },
        { "fnFAT16_FindDelEntry_ForRoot", (char*) fnFAT16_FindDelEntry_ForRoot  },
        { "fnFAT16_FindEntryInDirectory", (char*) fnFAT16_FindEntryInDirectory  },
        { "fnFAT16_GetFileNum_ForRoot", (char*) fnFAT16_GetFileNum_ForRoot  },
        { "fnFAT16_InitDPB", (char*) fnFAT16_InitDPB  },
        { "fnFAT16_InsertEntry_ForRoot", (char*) fnFAT16_InsertEntry_ForRoot  },
        { "fnFAT16_LinkFatEntry", (char*) fnFAT16_LinkFatEntry  },
        { "fnFAT16_NextCluster", (char*) fnFAT16_NextCluster  },
        { "fnFAT16_OpenDir", (char*) fnFAT16_OpenDir  },
        { "fnFAT16_WriteDir_ForRoot", (char*) fnFAT16_WriteDir_ForRoot  },
        { "fnFAT16_WriteDirEntry_ForRoot", (char*) fnFAT16_WriteDirEntry_ForRoot  },
        { "fnFAT_DirCheck", (char*) fnFAT_DirCheck  },
        { "fnFAT_FileClose", (char*) fnFAT_FileClose  },
        { "fnFAT_FileCreate", (char*) fnFAT_FileCreate  },
        { "fnFAT_FileDelete", (char*) fnFAT_FileDelete  },
        { "fnFAT_FileOpen", (char*) fnFAT_FileOpen  },
        { "fnFAT_FileRead", (char*) fnFAT_FileRead  },
        { "fnFAT_FileWrite", (char*) fnFAT_FileWrite  },
        { "fnFAT_GetDevInfo", (char*) fnFAT_GetDevInfo  },
        { "fnFAT_GetFileList", (char*) fnFAT_GetFileList  },
        { "fnFAT_MakeDir", (char*) fnFAT_MakeDir  },
        { "fnFAT_RemoveDir", (char*) fnFAT_RemoveDir  },
        { "FAT32_Is_LongName", (char*) FAT32_Is_LongName  },
        { "fnFAT32_CloseDir", (char*) fnFAT32_CloseDir  },
        { "fnFAT32_FindEntryInDirectory", (char*) fnFAT32_FindEntryInDirectory  },
        { "fnFAT32_InitDPB", (char*) fnFAT32_InitDPB  },
        { "fnFAT32_LinkFatEntry", (char*) fnFAT32_LinkFatEntry  },
        { "fnFAT32_NextCluster", (char*) fnFAT32_NextCluster  },
        { "fnFAT32_OpenDir", (char*) fnFAT32_OpenDir  },
        { "fnFAT_MakeFS", (char*) fnFAT_MakeFS  },
        { "fnFAT_BytesToUHWord", (char*) fnFAT_BytesToUHWord  },
        { "fnFAT_BytesToWord", (char*) fnFAT_BytesToWord  },
        { "fnFAT_CheckDPB", (char*) fnFAT_CheckDPB  },
        { "fnFAT_DestroyDev", (char*) fnFAT_DestroyDev  },
        { "fnFAT_DevInit", (char*) fnFAT_DevInit  },
        { "FAT_toUpperCase", (char*) FAT_toUpperCase  },
        { "fnFAT_AddOldName_NotForRoot", (char*) fnFAT_AddOldName_NotForRoot  },
        { "fnFAT_AddToDirEntry_NotForRoot", (char*) fnFAT_AddToDirEntry_NotForRoot  },
        { "fnFAT_CleanUpDirEntry", (char*) fnFAT_CleanUpDirEntry  },
        { "fnFAT_Cluster2Sector", (char*) fnFAT_Cluster2Sector  },
        { "fnFAT_ConvertToFATName", (char*) fnFAT_ConvertToFATName  },
        { "fnFAT_DeleteFromDirEntry", (char*) fnFAT_DeleteFromDirEntry  },
        { "fnFAT_DeleteOldEntry", (char*) fnFAT_DeleteOldEntry  },
        { "fnFAT_ExtractFileName", (char*) fnFAT_ExtractFileName  },
        { "fnFAT_FileRename", (char*) fnFAT_FileRename  },
        { "fnFAT_FillLongName2info", (char*) fnFAT_FillLongName2info  },
        { "fnFAT_FillShortName2info", (char*) fnFAT_FillShortName2info  },
        { "fnFAT_FindChar", (char*) fnFAT_FindChar  },
        { "fnFAT_FindDeletedEntry", (char*) fnFAT_FindDeletedEntry  },
        { "fnFAT_FindDirtyEntry", (char*) fnFAT_FindDirtyEntry  },
        { "fnFAT_FindEntry_ForShortName", (char*) fnFAT_FindEntry_ForShortName  },
        { "fnFAT_FindEntryByIndex", (char*) fnFAT_FindEntryByIndex  },
        { "fnFAT_FindFreeCluster", (char*) fnFAT_FindFreeCluster  },
        { "fnFAT_FindUnusedEntry", (char*) fnFAT_FindUnusedEntry  },
        { "fnFAT_GetDate", (char*) fnFAT_GetDate  },
        { "fnFAT_GetDirEntry", (char*) fnFAT_GetDirEntry  },
        { "fnFAT_GetFileNum_NotForRoot", (char*) fnFAT_GetFileNum_NotForRoot  },
        { "fnFAT_GetLongName", (char*) fnFAT_GetLongName  },
        { "fnFAT_GetNextEntry", (char*) fnFAT_GetNextEntry  },
        { "fnFAT_GetPreviousEntry", (char*) fnFAT_GetPreviousEntry  },
        { "fnFAT_GetShortName", (char*) fnFAT_GetShortName  },
        { "fnFAT_GetTime", (char*) fnFAT_GetTime  },
        { "fnFAT_InsertEntries_NotForRoot", (char*) fnFAT_InsertEntries_NotForRoot  },
        { "fnFAT_IsInUsed", (char*) fnFAT_IsInUsed  },
        { "fnFAT_NeedLFNEntry", (char*) fnFAT_NeedLFNEntry  },
        { "fnFAT_ObtainLdcbSem", (char*) fnFAT_ObtainLdcbSem  },
        { "fnFAT_PutDirEntry", (char*) fnFAT_PutDirEntry  },
        { "fnFAT_ReadBlock", (char*) fnFAT_ReadBlock  },
        { "fnFAT_ReleaseLdcbSem", (char*) fnFAT_ReleaseLdcbSem  },
        { "fnFAT_SetCluster", (char*) fnFAT_SetCluster  },
        { "fnFAT_SetFileSize", (char*) fnFAT_SetFileSize  },
        { "fnFAT_UpdataDirAndData", (char*) fnFAT_UpdataDirAndData  },
        { "fnFAT_WipeOutFatEntry", (char*) fnFAT_WipeOutFatEntry  },
        { "fnFAT_WriteBlock", (char*) fnFAT_WriteBlock  },
        { "fnFAT_WriteDir_NotForRoot", (char*) fnFAT_WriteDir_NotForRoot  },
        { "fnFAT_WriteDirEntry", (char*) fnFAT_WriteDirEntry  },
        { "fnFAT_ConvertStrToUnicode", (char*) fnFAT_ConvertStrToUnicode  },
        { "fnFAT_ConvertUnicodeToStr", (char*) fnFAT_ConvertUnicodeToStr  },
        { "fnMBC_Destroy", (char*) fnMBC_Destroy  },
        { "fnMBC_Flush_Dirty_Buffers", (char*) fnMBC_Flush_Dirty_Buffers  },
        { "fnMBC_Init", (char*) fnMBC_Init  },
        { "fnMBC_Operation", (char*) fnMBC_Operation  },
        { "fnMBC_Sync_Dirty_Buffer", (char*) fnMBC_Sync_Dirty_Buffer  },
        { "MBC_Flush_Dirty_Buffer", (char*) MBC_Flush_Dirty_Buffer  },
        { "MBC_Get_Free_Item", (char*) MBC_Get_Free_Item  },
        { "MBC_GetBlk", (char*) MBC_GetBlk  },
        { "MBC_Map_Buffer", (char*) MBC_Map_Buffer  },
        { "MBC_PhysicDev_Operation", (char*) MBC_PhysicDev_Operation  },
        { "MBC_Recycle_Bh", (char*) MBC_Recycle_Bh  },
        { "MBC_Search_Item_In_Lru_List", (char*) MBC_Search_Item_In_Lru_List  },
        { "format", (char*) format  },
        { "mount", (char*) mount  },
        { "sys_fs_type", (char*) &sys_fs_type  },
        { "umount", (char*) umount  },
        { "dm_chain_get_node", (char*) dm_chain_get_node  },
        { "dm_chain_initialize", (char*) dm_chain_initialize  },
        { "dm_add_dev", (char*) dm_add_dev  },
        { "dm_delete_dev", (char*) dm_delete_dev  },
        { "_dm_dev_find", (char*) _dm_dev_find  },
        { "dm_find_dev", (char*) dm_find_dev  },
        { "_dm_dev_name_get", (char*) _dm_dev_name_get  },
        { "dev_display", (char*) dev_display  },
        { "dm_dev_iterator", (char*) dm_dev_iterator  },
        { "dm_dev_show", (char*) dm_dev_show  },
        { "dm_find_root", (char*) dm_find_root  },
        { "dm_print_dev", (char*) dm_print_dev  },
        { "find_mount_dir", (char*) find_mount_dir  },
        { "type_to_typename", (char*) type_to_typename  },
        { "dm_install_drv", (char*) dm_install_drv  },
        { "dm_uninstall_drv", (char*) dm_uninstall_drv  },
        { "dm_fat_path_check", (char*) dm_fat_path_check  },
        { "dm_fd_value", (char*) dm_fd_value  },
        { "dm_initialization", (char*) dm_initialization  },
        { "dmInitFlag", (char*) &dmInitFlag  },
        { "dmManager", (char*) &dmManager  },
        { "_dm_lock", (char*) _dm_lock  },
        { "_dm_lock_creat", (char*) _dm_lock_creat  },
        { "_dm_lock_delete", (char*) _dm_lock_delete  },
        { "_dm_unlock", (char*) _dm_unlock  },
        { "dm_mknod", (char*) dm_mknod  },
        { "dm_rtos_filesystem_make_dev_t", (char*) dm_rtos_filesystem_make_dev_t  },
        { "_dm_dev_info", (char*) _dm_dev_info  },
        { "_dm_fd_free", (char*) _dm_fd_free  },
        { "_dm_fd_info", (char*) _dm_fd_info  },
        { "_dm_fd_value_set", (char*) _dm_fd_value_set  },
        { "_dm_free_fd_get", (char*) _dm_free_fd_get  },
        { "_dm_object_name_is_valid", (char*) _dm_object_name_is_valid  },
        { "_dm_path_get", (char*) _dm_path_get  },
        { "_dm_path_set", (char*) _dm_path_set  },
        { "_string_copy_memory", (char*) _string_copy_memory  },
        { "_string_get_objname_length", (char*) _string_get_objname_length  },
        { "_string_set_memory", (char*) _string_set_memory  },
        { "_dm_io_creat_open", (char*) _dm_io_creat_open  },
        { "_syscall_close", (char*) _syscall_close  },
        { "_syscall_creat", (char*) _syscall_creat  },
        { "_string_compare_objname", (char*) _string_compare_objname  },
        { "_syscall_ioctl", (char*) _syscall_ioctl  },
        { "_syscall_maxfd", (char*) _syscall_maxfd  },
        { "_syscall_open", (char*) _syscall_open  },
        { "_syscall_read", (char*) _syscall_read  },
        { "_syscall_write", (char*) _syscall_write  },
        { "register_device", (char*) register_device  },
        { "register_driver", (char*) register_driver  },
        { "unregister_device", (char*) unregister_device  },
        { "unregister_driver", (char*) unregister_driver  },
        { "smipc_accept", (char*) smipc_accept  },
        { "smipc_bind", (char*) smipc_bind  },
        { "smipc_close", (char*) smipc_close  },
        { "smipc_connect", (char*) smipc_connect  },
        { "smipc_getactivenodes", (char*) smipc_getactivenodes  },
        { "smipc_getbusbyname", (char*) smipc_getbusbyname  },
        { "smipc_getbusmaxnodes", (char*) smipc_getbusmaxnodes  },
        { "smipc_getnamebybus", (char*) smipc_getnamebybus  },
        { "smipc_getnodebybus", (char*) smipc_getnodebybus  },
        { "smipc_getpeername", (char*) smipc_getpeername  },
        { "smipc_getsockname", (char*) smipc_getsockname  },
        { "smipc_getsockopt", (char*) smipc_getsockopt  },
        { "smipc_getstats", (char*) smipc_getstats  },
        { "smipc_listen", (char*) smipc_listen  },
        { "smipc_recv", (char*) smipc_recv  },
        { "smipc_recvfrom", (char*) smipc_recvfrom  },
        { "smipc_rx_callback", (char*) smipc_rx_callback  },
        { "smipc_send", (char*) smipc_send  },
        { "smipc_sendto", (char*) smipc_sendto  },
        { "smipc_setsockopt", (char*) smipc_setsockopt  },
        { "smipc_shutdown", (char*) smipc_shutdown  },
        { "smipc_socket", (char*) smipc_socket  },
        { "smipc_zalloc", (char*) smipc_zalloc  },
        { "smipc_zfree", (char*) smipc_zfree  },
        { "smipc_zrecv", (char*) smipc_zrecv  },
        { "smipc_zrecvfrom", (char*) smipc_zrecvfrom  },
        { "smipc_zsend", (char*) smipc_zsend  },
        { "smipc_zsendto", (char*) smipc_zsendto  },
        { "smipc_bus_default", (char*) &smipc_bus_default  },
        { "smipc_bus_get", (char*) smipc_bus_get  },
        { "smipc_bus_init", (char*) smipc_bus_init  },
        { "smipc_get_buses", (char*) smipc_get_buses  },
        { "smipc_max_buses", (char*) &smipc_max_buses  },
        { "smipc_stats_get", (char*) smipc_stats_get  },
        { "smipc_sys_signature", (char*) &smipc_sys_signature  },
        { "smipcBuses", (char*) &smipcBuses  },
        { "smipcLocalBusInfo", (char*) &smipcLocalBusInfo  },
        { "smipcSystem", (char*) &smipcSystem  },
        { "smipc_display_bus", (char*) smipc_display_bus  },
        { "smipc_display_node", (char*) smipc_display_node  },
        { "smipc_display_port", (char*) smipc_display_port  },
        { "smipc_display_stats", (char*) smipc_display_stats  },
        { "smipc_display_system", (char*) smipc_display_system  },
        { "smipc_basic_event_alloc", (char*) smipc_basic_event_alloc  },
        { "smipc_basic_event_send", (char*) smipc_basic_event_send  },
        { "smipc_event_alloc", (char*) smipc_event_alloc  },
        { "smipc_event_free", (char*) smipc_event_free  },
        { "smipc_event_pool_init", (char*) smipc_event_pool_init  },
        { "smipc_api_process_rx_events", (char*) smipc_api_process_rx_events  },
        { "smipc_event_send", (char*) smipc_event_send  },
        { "get_smipc_priority", (char*) get_smipc_priority  },
        { "get_smipc_stack_size", (char*) get_smipc_stack_size  },
        { "set_smipc_priority", (char*) set_smipc_priority  },
        { "set_smipc_stack_size", (char*) set_smipc_stack_size  },
        { "smipc_config", (char*) &smipc_config  },
        { "smipc_cpu_id", (char*) &smipc_cpu_id  },
        { "smipc_init", (char*) smipc_init  },
        { "smipc_initialized", (char*) &smipc_initialized  },
        { "smipc_node_id", (char*) &smipc_node_id  },
        { "smipcInit", (char*) smipcInit  },
        { "smipcStartAddr", (char*) &smipcStartAddr  },
        { "smipc_mem_region_alloc", (char*) smipc_mem_region_alloc  },
        { "smipc_mem_region_init", (char*) smipc_mem_region_init  },
        { "smipc_node_down", (char*) smipc_node_down  },
        { "smipc_node_get", (char*) smipc_node_get  },
        { "smipc_node_get_valid", (char*) smipc_node_get_valid  },
        { "smipc_node_heartbeat_task", (char*) smipc_node_heartbeat_task  },
        { "smipc_node_init", (char*) smipc_node_init  },
        { "smipc_node_is_up", (char*) smipc_node_is_up  },
        { "smipc_node_peer_audit", (char*) smipc_node_peer_audit  },
        { "smipc_node_pool_audit", (char*) smipc_node_pool_audit  },
        { "smipc_node_send_internal_event", (char*) smipc_node_send_internal_event  },
        { "smipc_node_up", (char*) smipc_node_up  },
        { "smipc_reset_state", (char*) &smipc_reset_state  },
        { "smipc_packet_alloc", (char*) smipc_packet_alloc  },
        { "smipc_packet_free", (char*) smipc_packet_free  },
        { "smipc_packet_free_all", (char*) smipc_packet_free_all  },
        { "smipc_packet_pool_init", (char*) smipc_packet_pool_init  },
        { "smipc_txbuf_is_avail", (char*) smipc_txbuf_is_avail  },
        { "smipc_dummy_port", (char*) &smipc_dummy_port  },
        { "smipc_port_alloc", (char*) smipc_port_alloc  },
        { "smipc_port_buffer_is_avail", (char*) smipc_port_buffer_is_avail  },
        { "smipc_port_bufs_alloc", (char*) smipc_port_bufs_alloc  },
        { "smipc_port_free", (char*) smipc_port_free  },
        { "smipc_port_get", (char*) smipc_port_get  },
        { "smipc_port_init", (char*) smipc_port_init  },
        { "smipc_port_packet_get", (char*) smipc_port_packet_get  },
        { "smipc_port_packet_put", (char*) smipc_port_packet_put  },
        { "smipc_port_packets_free", (char*) smipc_port_packets_free  },
        { "smipc_sock_init", (char*) smipc_sock_init  },
        { "smipc_socket_alloc", (char*) smipc_socket_alloc  },
        { "smipc_socket_free", (char*) smipc_socket_free  },
        { "smipc_socket_init", (char*) smipc_socket_init  },
        { "smipc_socket_packet_queue", (char*) smipc_socket_packet_queue  },
        { "smipc_socket_wait", (char*) smipc_socket_wait  },
        { "smipcAllSockets", (char*) &smipcAllSockets  },
        { "smipcMaxSockets", (char*) &smipcMaxSockets  },
        { "smipcUserHandles", (char*) &smipcUserHandles  },
        { "smipc_adapt_get_cpu_id", (char*) smipc_adapt_get_cpu_id  },
        { "smipc_adapt_get_node_id", (char*) smipc_adapt_get_node_id  },
        { "smipc_adapt_notify_node", (char*) smipc_adapt_notify_node  },
        { "netconn_accept", (char*) netconn_accept  },
        { "netconn_bind", (char*) netconn_bind  },
        { "netconn_close", (char*) netconn_close  },
        { "netconn_connect", (char*) netconn_connect  },
        { "netconn_delete", (char*) netconn_delete  },
        { "netconn_disconnect", (char*) netconn_disconnect  },
        { "netconn_getaddr", (char*) netconn_getaddr  },
        { "netconn_gethostbyname", (char*) netconn_gethostbyname  },
        { "netconn_join_leave_group", (char*) netconn_join_leave_group  },
        { "netconn_listen_with_backlog", (char*) netconn_listen_with_backlog  },
        { "netconn_new_with_proto_and_callback", (char*) netconn_new_with_proto_and_callback  },
        { "netconn_recv", (char*) netconn_recv  },
        { "netconn_recv_tcp_pbuf", (char*) netconn_recv_tcp_pbuf  },
        { "netconn_send", (char*) netconn_send  },
        { "netconn_sendto", (char*) netconn_sendto  },
        { "netconn_shutdown", (char*) netconn_shutdown  },
        { "netconn_write_partly", (char*) netconn_write_partly  },
        { "lwip_netconn_do_accepted", (char*) lwip_netconn_do_accepted  },
        { "lwip_netconn_do_bind", (char*) lwip_netconn_do_bind  },
        { "lwip_netconn_do_close", (char*) lwip_netconn_do_close  },
        { "lwip_netconn_do_connect", (char*) lwip_netconn_do_connect  },
        { "lwip_netconn_do_delconn", (char*) lwip_netconn_do_delconn  },
        { "lwip_netconn_do_disconnect", (char*) lwip_netconn_do_disconnect  },
        { "lwip_netconn_do_getaddr", (char*) lwip_netconn_do_getaddr  },
        { "lwip_netconn_do_gethostbyname", (char*) lwip_netconn_do_gethostbyname  },
        { "lwip_netconn_do_join_leave_group", (char*) lwip_netconn_do_join_leave_group  },
        { "lwip_netconn_do_listen", (char*) lwip_netconn_do_listen  },
        { "lwip_netconn_do_newconn", (char*) lwip_netconn_do_newconn  },
        { "lwip_netconn_do_recv", (char*) lwip_netconn_do_recv  },
        { "lwip_netconn_do_send", (char*) lwip_netconn_do_send  },
        { "lwip_netconn_do_write", (char*) lwip_netconn_do_write  },
        { "netconn_aborted", (char*) &netconn_aborted  },
        { "netconn_alloc", (char*) netconn_alloc  },
        { "netconn_free", (char*) netconn_free  },
        { "err_to_errno", (char*) err_to_errno  },
        { "lwip_strerr", (char*) lwip_strerr  },
        { "netbuf_alloc", (char*) netbuf_alloc  },
        { "netbuf_chain", (char*) netbuf_chain  },
        { "netbuf_data", (char*) netbuf_data  },
        { "netbuf_delete", (char*) netbuf_delete  },
        { "netbuf_first", (char*) netbuf_first  },
        { "netbuf_free", (char*) netbuf_free  },
        { "netbuf_new", (char*) netbuf_new  },
        { "netbuf_next", (char*) netbuf_next  },
        { "netbuf_ref", (char*) netbuf_ref  },
        { "h_errno", (char*) &h_errno  },
        { "lwip_freeaddrinfo", (char*) lwip_freeaddrinfo  },
        { "lwip_getaddrinfo", (char*) lwip_getaddrinfo  },
        { "lwip_gethostbyname", (char*) lwip_gethostbyname  },
        { "lwip_gethostbyname_r", (char*) lwip_gethostbyname_r  },
        { "available_sockets", (char*) &available_sockets  },
        { "get_user_config_socket_offset", (char*) get_user_config_socket_offset  },
        { "lwip_accept", (char*) lwip_accept  },
        { "lwip_bind", (char*) lwip_bind  },
        { "lwip_close", (char*) lwip_close  },
        { "lwip_connect", (char*) lwip_connect  },
        { "lwip_fcntl", (char*) lwip_fcntl  },
        { "lwip_getpeername", (char*) lwip_getpeername  },
        { "lwip_getsockname", (char*) lwip_getsockname  },
        { "lwip_getsockopt", (char*) lwip_getsockopt  },
        { "lwip_ioctl", (char*) lwip_ioctl  },
        { "lwip_listen", (char*) lwip_listen  },
        { "lwip_read", (char*) lwip_read  },
        { "lwip_recv", (char*) lwip_recv  },
        { "lwip_recvfrom", (char*) lwip_recvfrom  },
        { "lwip_select", (char*) lwip_select  },
        { "lwip_send", (char*) lwip_send  },
        { "lwip_sendmsg", (char*) lwip_sendmsg  },
        { "lwip_sendto", (char*) lwip_sendto  },
        { "lwip_setsockopt", (char*) lwip_setsockopt  },
        { "lwip_shutdown", (char*) lwip_shutdown  },
        { "lwip_socket", (char*) lwip_socket  },
        { "lwip_socket_thread_cleanup", (char*) lwip_socket_thread_cleanup  },
        { "lwip_socket_thread_init", (char*) lwip_socket_thread_init  },
        { "lwip_write", (char*) lwip_write  },
        { "lwip_writev", (char*) lwip_writev  },
        { "set_user_config_socket_offset", (char*) set_user_config_socket_offset  },
        { "socket_ipv4_multicast_memberships", (char*) &socket_ipv4_multicast_memberships  },
        { "get_lwip_priority", (char*) get_lwip_priority  },
        { "get_lwip_stack_size", (char*) get_lwip_stack_size  },
        { "mem_free_callback", (char*) mem_free_callback  },
        { "pbuf_free_callback", (char*) pbuf_free_callback  },
        { "set_lwip_priority", (char*) set_lwip_priority  },
        { "set_lwip_stack_size", (char*) set_lwip_stack_size  },
        { "tcpip_api_call", (char*) tcpip_api_call  },
        { "tcpip_callback_with_block", (char*) tcpip_callback_with_block  },
        { "tcpip_callbackmsg_delete", (char*) tcpip_callbackmsg_delete  },
        { "tcpip_callbackmsg_new", (char*) tcpip_callbackmsg_new  },
        { "tcpip_init", (char*) tcpip_init  },
        { "tcpip_inpkt", (char*) tcpip_inpkt  },
        { "tcpip_input", (char*) tcpip_input  },
        { "tcpip_send_msg_wait_sem", (char*) tcpip_send_msg_wait_sem  },
        { "tcpip_thread_attr_set", (char*) tcpip_thread_attr_set  },
        { "tcpip_trycallback", (char*) tcpip_trycallback  },
        { "ping_send", (char*) ping_send  },
        { "arch_protect_mutex", (char*) &arch_protect_mutex  },
        { "raw_sem_wait", (char*) raw_sem_wait  },
        { "sys_arch_mbox_fetch", (char*) sys_arch_mbox_fetch  },
        { "sys_arch_mbox_fetch_ex", (char*) sys_arch_mbox_fetch_ex  },
        { "sys_arch_mbox_tryfetch", (char*) sys_arch_mbox_tryfetch  },
        { "sys_arch_sem_wait", (char*) sys_arch_sem_wait  },
        { "sys_hook_unknown_eth_protocol", (char*) sys_hook_unknown_eth_protocol  },
        { "sys_init", (char*) sys_init  },
        { "sys_mbox_free", (char*) sys_mbox_free  },
        { "sys_mbox_new", (char*) sys_mbox_new  },
        { "sys_mbox_new_ex", (char*) sys_mbox_new_ex  },
        { "sys_mbox_post", (char*) sys_mbox_post  },
        { "sys_mbox_set_invalid", (char*) sys_mbox_set_invalid  },
        { "sys_mbox_trypost", (char*) sys_mbox_trypost  },
        { "sys_mbox_valid", (char*) sys_mbox_valid  },
        { "sys_mutex_free", (char*) sys_mutex_free  },
        { "sys_mutex_lock", (char*) sys_mutex_lock  },
        { "sys_mutex_new", (char*) sys_mutex_new  },
        { "sys_mutex_unlock", (char*) sys_mutex_unlock  },
        { "sys_now", (char*) sys_now  },
        { "sys_sem_free", (char*) sys_sem_free  },
        { "sys_sem_new", (char*) sys_sem_new  },
        { "sys_sem_set_invalid", (char*) sys_sem_set_invalid  },
        { "sys_sem_signal", (char*) sys_sem_signal  },
        { "sys_sem_valid", (char*) sys_sem_valid  },
        { "sys_thread_new", (char*) sys_thread_new  },
        { "gethostbyaddr", (char*) gethostbyaddr  },
        { "change_string_addr_to_int_addr", (char*) change_string_addr_to_int_addr  },
        { "get_broadcast_address", (char*) get_broadcast_address  },
        { "get_netif_name_from_minor", (char*) get_netif_name_from_minor  },
        { "get_nic_param", (char*) get_nic_param  },
        { "if_show", (char*) if_show  },
        { "ifconfig", (char*) ifconfig  },
        { "mbuf_show", (char*) mbuf_show  },
        { "routes_show", (char*) routes_show  },
        { "set_nic_param", (char*) set_nic_param  },
        { "tcp_show", (char*) tcp_show  },
        { "udp_show", (char*) udp_show  },
        { "recvmsg", (char*) recvmsg  },
        { "lwip_itoa", (char*) lwip_itoa  },
        { "lwip_stricmp", (char*) lwip_stricmp  },
        { "lwip_strnicmp", (char*) lwip_strnicmp  },
        { "lwip_strnstr", (char*) lwip_strnstr  },
        { "dns_gethostbyname", (char*) dns_gethostbyname  },
        { "dns_gethostbyname_addrtype", (char*) dns_gethostbyname_addrtype  },
        { "dns_getserver", (char*) dns_getserver  },
        { "dns_init", (char*) dns_init  },
        { "dns_mquery_v4group", (char*) &dns_mquery_v4group  },
        { "dns_setserver", (char*) dns_setserver  },
        { "dns_tmr", (char*) dns_tmr  },
        { "inet_chksum", (char*) inet_chksum  },
        { "inet_chksum_pbuf", (char*) inet_chksum_pbuf  },
        { "inet_chksum_pseudo", (char*) inet_chksum_pseudo  },
        { "inet_chksum_pseudo_partial", (char*) inet_chksum_pseudo_partial  },
        { "ip_chksum_pseudo", (char*) ip_chksum_pseudo  },
        { "ip_chksum_pseudo_partial", (char*) ip_chksum_pseudo_partial  },
        { "lwip_standard_chksum", (char*) lwip_standard_chksum  },
        { "ip_data", (char*) &ip_data  },
        { "lwip_init", (char*) lwip_init  },
        { "mem_calloc", (char*) mem_calloc  },
        { "mem_free", (char*) mem_free  },
        { "mem_init", (char*) mem_init  },
        { "mem_malloc", (char*) mem_malloc  },
        { "mem_trim", (char*) mem_trim  },
        { "memp_ARP_QUEUE", (char*) &memp_ARP_QUEUE  },
        { "memp_FRAG_PBUF", (char*) &memp_FRAG_PBUF  },
        { "memp_free", (char*) memp_free  },
        { "memp_free_pool", (char*) memp_free_pool  },
        { "memp_IGMP_GROUP", (char*) &memp_IGMP_GROUP  },
        { "memp_init", (char*) memp_init  },
        { "memp_init_pool", (char*) memp_init_pool  },
        { "memp_malloc", (char*) memp_malloc  },
        { "memp_malloc_pool", (char*) memp_malloc_pool  },
        { "memp_NETBUF", (char*) &memp_NETBUF  },
        { "memp_NETCONN", (char*) &memp_NETCONN  },
        { "memp_NETDB", (char*) &memp_NETDB  },
        { "memp_PBUF", (char*) &memp_PBUF  },
        { "memp_PBUF_POOL", (char*) &memp_PBUF_POOL  },
        { "memp_pools", (char*) &memp_pools  },
        { "memp_RAW_PCB", (char*) &memp_RAW_PCB  },
        { "memp_REASSDATA", (char*) &memp_REASSDATA  },
        { "memp_SYS_TIMEOUT", (char*) &memp_SYS_TIMEOUT  },
        { "memp_TCP_PCB", (char*) &memp_TCP_PCB  },
        { "memp_TCP_PCB_LISTEN", (char*) &memp_TCP_PCB_LISTEN  },
        { "memp_TCP_SEG", (char*) &memp_TCP_SEG  },
        { "memp_TCPIP_MSG_API", (char*) &memp_TCPIP_MSG_API  },
        { "memp_TCPIP_MSG_INPKT", (char*) &memp_TCPIP_MSG_INPKT  },
        { "memp_UDP_PCB", (char*) &memp_UDP_PCB  },
        { "if_indextoname", (char*) if_indextoname  },
        { "if_nametoindex", (char*) if_nametoindex  },
        { "netif_add", (char*) netif_add  },
        { "netif_add_static_route_item", (char*) netif_add_static_route_item  },
        { "netif_alloc_client_data_id", (char*) netif_alloc_client_data_id  },
        { "netif_default", (char*) &netif_default  },
        { "netif_find", (char*) netif_find  },
        { "netif_init", (char*) netif_init  },
        { "netif_input", (char*) netif_input  },
        { "netif_list", (char*) &netif_list  },
        { "netif_loop_output", (char*) netif_loop_output  },
        { "netif_poll", (char*) netif_poll  },
        { "netif_remove", (char*) netif_remove  },
        { "netif_set_addr", (char*) netif_set_addr  },
        { "netif_set_default", (char*) netif_set_default  },
        { "netif_set_down", (char*) netif_set_down  },
        { "netif_set_gw", (char*) netif_set_gw  },
        { "netif_set_ipaddr", (char*) netif_set_ipaddr  },
        { "netif_set_link_callback", (char*) netif_set_link_callback  },
        { "netif_set_link_down", (char*) netif_set_link_down  },
        { "netif_set_link_up", (char*) netif_set_link_up  },
        { "netif_set_netmask", (char*) netif_set_netmask  },
        { "netif_set_status_callback", (char*) netif_set_status_callback  },
        { "netif_set_up", (char*) netif_set_up  },
        { "pbuf_alloc", (char*) pbuf_alloc  },
        { "pbuf_alloced_custom", (char*) pbuf_alloced_custom  },
        { "pbuf_cat", (char*) pbuf_cat  },
        { "pbuf_chain", (char*) pbuf_chain  },
        { "pbuf_clen", (char*) pbuf_clen  },
        { "pbuf_coalesce", (char*) pbuf_coalesce  },
        { "pbuf_copy", (char*) pbuf_copy  },
        { "pbuf_copy_partial", (char*) pbuf_copy_partial  },
        { "pbuf_dechain", (char*) pbuf_dechain  },
        { "pbuf_free", (char*) pbuf_free  },
        { "pbuf_free_ooseq_pending", (char*) &pbuf_free_ooseq_pending  },
        { "pbuf_get_at", (char*) pbuf_get_at  },
        { "pbuf_header", (char*) pbuf_header  },
        { "pbuf_header_force", (char*) pbuf_header_force  },
        { "pbuf_memcmp", (char*) pbuf_memcmp  },
        { "pbuf_memfind", (char*) pbuf_memfind  },
        { "pbuf_put_at", (char*) pbuf_put_at  },
        { "pbuf_realloc", (char*) pbuf_realloc  },
        { "pbuf_ref", (char*) pbuf_ref  },
        { "pbuf_skip", (char*) pbuf_skip  },
        { "pbuf_strstr", (char*) pbuf_strstr  },
        { "pbuf_take", (char*) pbuf_take  },
        { "pbuf_take_at", (char*) pbuf_take_at  },
        { "pbuf_try_get_at", (char*) pbuf_try_get_at  },
        { "raw_bind", (char*) raw_bind  },
        { "raw_connect", (char*) raw_connect  },
        { "raw_input", (char*) raw_input  },
        { "raw_netif_ip_addr_changed", (char*) raw_netif_ip_addr_changed  },
        { "raw_new", (char*) raw_new  },
        { "raw_new_ip_type", (char*) raw_new_ip_type  },
        { "raw_recv", (char*) raw_recv  },
        { "raw_remove", (char*) raw_remove  },
        { "raw_send", (char*) raw_send  },
        { "raw_sendto", (char*) raw_sendto  },
        { "brief_of_netif", (char*) brief_of_netif  },
        { "etharp_stats_display", (char*) etharp_stats_display  },
        { "find_netif", (char*) find_netif  },
        { "icmp_stats_display", (char*) icmp_stats_display  },
        { "ip_stats_display", (char*) ip_stats_display  },
        { "link_stats_display", (char*) link_stats_display  },
        { "lwip_stats", (char*) &lwip_stats  },
        { "memp_stats_display", (char*) memp_stats_display  },
        { "netif_show", (char*) netif_show  },
        { "netifShowHook", (char*) netifShowHook  },
        { "print_ip", (char*) print_ip  },
        { "set_default_netif", (char*) set_default_netif  },
        { "set_netif", (char*) set_netif  },
        { "socket_stats_display", (char*) socket_stats_display  },
        { "stats_display", (char*) stats_display  },
        { "stats_display_igmp", (char*) stats_display_igmp  },
        { "stats_display_mem", (char*) stats_display_mem  },
        { "stats_display_memp", (char*) stats_display_memp  },
        { "stats_display_proto", (char*) stats_display_proto  },
        { "stats_init", (char*) stats_init  },
        { "switchNicType", (char*) switchNicType  },
        { "tcp_stats_display", (char*) tcp_stats_display  },
        { "udp_stats_display", (char*) udp_stats_display  },
        { "sys_msleep", (char*) sys_msleep  },
        { "tcp_abandon", (char*) tcp_abandon  },
        { "tcp_abort", (char*) tcp_abort  },
        { "tcp_accept", (char*) tcp_accept  },
        { "tcp_active_pcbs", (char*) &tcp_active_pcbs  },
        { "tcp_active_pcbs_changed", (char*) &tcp_active_pcbs_changed  },
        { "tcp_alloc", (char*) tcp_alloc  },
        { "tcp_arg", (char*) tcp_arg  },
        { "tcp_backlog_accepted", (char*) tcp_backlog_accepted  },
        { "tcp_backlog_delayed", (char*) tcp_backlog_delayed  },
        { "tcp_bind", (char*) tcp_bind  },
        { "tcp_bound_pcbs", (char*) &tcp_bound_pcbs  },
        { "tcp_close", (char*) tcp_close  },
        { "tcp_connect", (char*) tcp_connect  },
        { "tcp_debug_state_str", (char*) tcp_debug_state_str  },
        { "tcp_eff_send_mss_impl", (char*) tcp_eff_send_mss_impl  },
        { "tcp_err", (char*) tcp_err  },
        { "tcp_fasttmr", (char*) tcp_fasttmr  },
        { "tcp_init", (char*) tcp_init  },
        { "tcp_listen_pcbs", (char*) &tcp_listen_pcbs  },
        { "tcp_listen_with_backlog", (char*) tcp_listen_with_backlog  },
        { "tcp_listen_with_backlog_and_err", (char*) tcp_listen_with_backlog_and_err  },
        { "tcp_netif_ip_addr_changed", (char*) tcp_netif_ip_addr_changed  },
        { "tcp_new", (char*) tcp_new  },
        { "tcp_new_ip_type", (char*) tcp_new_ip_type  },
        { "tcp_next_iss", (char*) tcp_next_iss  },
        { "tcp_pcb_lists", (char*) &tcp_pcb_lists  },
        { "tcp_pcb_purge", (char*) tcp_pcb_purge  },
        { "tcp_pcb_remove", (char*) tcp_pcb_remove  },
        { "tcp_poll", (char*) tcp_poll  },
        { "tcp_process_refused_data", (char*) tcp_process_refused_data  },
        { "tcp_recv", (char*) tcp_recv  },
        { "tcp_recv_null", (char*) tcp_recv_null  },
        { "tcp_recved", (char*) tcp_recved  },
        { "tcp_seg_copy", (char*) tcp_seg_copy  },
        { "tcp_seg_free", (char*) tcp_seg_free  },
        { "tcp_segs_free", (char*) tcp_segs_free  },
        { "tcp_sent", (char*) tcp_sent  },
        { "tcp_setprio", (char*) tcp_setprio  },
        { "tcp_shutdown", (char*) tcp_shutdown  },
        { "tcp_slowtmr", (char*) tcp_slowtmr  },
        { "tcp_ticks", (char*) &tcp_ticks  },
        { "tcp_tmr", (char*) tcp_tmr  },
        { "tcp_tw_pcbs", (char*) &tcp_tw_pcbs  },
        { "tcp_txnow", (char*) tcp_txnow  },
        { "tcp_update_rcv_ann_wnd", (char*) tcp_update_rcv_ann_wnd  },
        { "tcp_input", (char*) tcp_input  },
        { "tcp_input_pcb", (char*) &tcp_input_pcb  },
        { "tcp_trigger_input_pcb_close", (char*) tcp_trigger_input_pcb_close  },
        { "tcp_enqueue_flags", (char*) tcp_enqueue_flags  },
        { "tcp_keepalive", (char*) tcp_keepalive  },
        { "tcp_output", (char*) tcp_output  },
        { "tcp_rexmit", (char*) tcp_rexmit  },
        { "tcp_rexmit_fast", (char*) tcp_rexmit_fast  },
        { "tcp_rexmit_rto", (char*) tcp_rexmit_rto  },
        { "tcp_rst", (char*) tcp_rst  },
        { "tcp_send_empty_ack", (char*) tcp_send_empty_ack  },
        { "tcp_send_fin", (char*) tcp_send_fin  },
        { "tcp_write", (char*) tcp_write  },
        { "tcp_zero_window_probe", (char*) tcp_zero_window_probe  },
        { "lwip_cyclic_timers", (char*) &lwip_cyclic_timers  },
        { "sys_restart_timeouts", (char*) sys_restart_timeouts  },
        { "sys_timeout", (char*) sys_timeout  },
        { "sys_timeouts_init", (char*) sys_timeouts_init  },
        { "sys_timeouts_mbox_fetch", (char*) sys_timeouts_mbox_fetch  },
        { "sys_untimeout", (char*) sys_untimeout  },
        { "tcp_timer_needed", (char*) tcp_timer_needed  },
        { "udp_bind", (char*) udp_bind  },
        { "udp_connect", (char*) udp_connect  },
        { "udp_disconnect", (char*) udp_disconnect  },
        { "udp_init", (char*) udp_init  },
        { "udp_input", (char*) udp_input  },
        { "udp_netif_ip_addr_changed", (char*) udp_netif_ip_addr_changed  },
        { "udp_new", (char*) udp_new  },
        { "udp_new_ip_type", (char*) udp_new_ip_type  },
        { "udp_pcbs", (char*) &udp_pcbs  },
        { "udp_recv", (char*) udp_recv  },
        { "udp_remove", (char*) udp_remove  },
        { "udp_send", (char*) udp_send  },
        { "udp_sendto", (char*) udp_sendto  },
        { "udp_sendto_if", (char*) udp_sendto_if  },
        { "udp_sendto_if_src", (char*) udp_sendto_if_src  },
        { "dhcp_arp_reply", (char*) dhcp_arp_reply  },
        { "dhcp_cleanup", (char*) dhcp_cleanup  },
        { "dhcp_coarse_tmr", (char*) dhcp_coarse_tmr  },
        { "dhcp_fine_tmr", (char*) dhcp_fine_tmr  },
        { "dhcp_inform", (char*) dhcp_inform  },
        { "dhcp_network_changed", (char*) dhcp_network_changed  },
        { "dhcp_release", (char*) dhcp_release  },
        { "dhcp_renew", (char*) dhcp_renew  },
        { "dhcp_rx_options_given", (char*) &dhcp_rx_options_given  },
        { "dhcp_rx_options_val", (char*) &dhcp_rx_options_val  },
        { "dhcp_set_struct", (char*) dhcp_set_struct  },
        { "dhcp_start", (char*) dhcp_start  },
        { "dhcp_stop", (char*) dhcp_stop  },
        { "dhcp_supplied_address", (char*) dhcp_supplied_address  },
        { "etharp_cleanup_netif", (char*) etharp_cleanup_netif  },
        { "etharp_find_addr", (char*) etharp_find_addr  },
        { "etharp_get_entry", (char*) etharp_get_entry  },
        { "etharp_input", (char*) etharp_input  },
        { "etharp_output", (char*) etharp_output  },
        { "etharp_query", (char*) etharp_query  },
        { "etharp_request", (char*) etharp_request  },
        { "etharp_tmr", (char*) etharp_tmr  },
        { "show_allocedarp_nums", (char*) show_allocedarp_nums  },
        { "icmp_dest_unreach", (char*) icmp_dest_unreach  },
        { "icmp_input", (char*) icmp_input  },
        { "icmp_time_exceeded", (char*) icmp_time_exceeded  },
        { "igmp_init", (char*) igmp_init  },
        { "igmp_input", (char*) igmp_input  },
        { "igmp_joingroup", (char*) igmp_joingroup  },
        { "igmp_joingroup_netif", (char*) igmp_joingroup_netif  },
        { "igmp_leavegroup", (char*) igmp_leavegroup  },
        { "igmp_leavegroup_netif", (char*) igmp_leavegroup_netif  },
        { "igmp_lookfor_group", (char*) igmp_lookfor_group  },
        { "igmp_report_groups", (char*) igmp_report_groups  },
        { "igmp_start", (char*) igmp_start  },
        { "igmp_stop", (char*) igmp_stop  },
        { "igmp_tmr", (char*) igmp_tmr  },
        { "ip4_input", (char*) ip4_input  },
        { "ip4_output", (char*) ip4_output  },
        { "ip4_output_hinted", (char*) ip4_output_hinted  },
        { "ip4_output_if", (char*) ip4_output_if  },
        { "ip4_output_if_opt", (char*) ip4_output_if_opt  },
        { "ip4_output_if_opt_src", (char*) ip4_output_if_opt_src  },
        { "ip4_output_if_src", (char*) ip4_output_if_src  },
        { "ip4_route", (char*) ip4_route  },
        { "ip4_route_src", (char*) ip4_route_src  },
        { "ip4_set_default_multicast_netif", (char*) ip4_set_default_multicast_netif  },
        { "lwip_hook_ip4_route_src", (char*) lwip_hook_ip4_route_src  },
        { "ip_addr_any", (char*) &ip_addr_any  },
        { "ip_addr_broadcast", (char*) &ip_addr_broadcast  },
        { "ip4_addr_isbroadcast_u32", (char*) ip4_addr_isbroadcast_u32  },
        { "ip4_addr_netmask_valid", (char*) ip4_addr_netmask_valid  },
        { "ip4addr_aton", (char*) ip4addr_aton  },
        { "ip4addr_ntoa", (char*) ip4addr_ntoa  },
        { "ip4addr_ntoa_r", (char*) ip4addr_ntoa_r  },
        { "ipaddr_addr", (char*) ipaddr_addr  },
        { "ip_reass_tmr", (char*) ip_reass_tmr  },
        { "ip4_frag", (char*) ip4_frag  },
        { "ip4_reass", (char*) ip4_reass  },
        { "ethbroadcast", (char*) &ethbroadcast  },
        { "ethernet_input", (char*) ethernet_input  },
        { "ethernet_output", (char*) ethernet_output  },
        { "ethzero", (char*) &ethzero  },
        { "ip4_static_route", (char*) ip4_static_route  },
        { "slipif_init", (char*) slipif_init  },
        { "slipif_loop_thread_attr_set", (char*) slipif_loop_thread_attr_set  },
        { "slipif_poll", (char*) slipif_poll  },
        { "getCurrentVmNicStructAddr", (char*) getCurrentVmNicStructAddr  },
        { "getCurrentVmUSBStructAddr", (char*) getCurrentVmUSBStructAddr  },
        { "NicGetInfoByName", (char*) NicGetInfoByName  },
        { "TTOS_GetAllHardDiskInfo", (char*) TTOS_GetAllHardDiskInfo  },
        { "TTOS_GetFreeMemorySize", (char*) TTOS_GetFreeMemorySize  },
        { "TTOS_GetFunctionInfo", (char*) TTOS_GetFunctionInfo  },
        { "TTOS_GetLogicalAddressByName", (char*) TTOS_GetLogicalAddressByName  },
        { "TTOS_GetNicNameList", (char*) TTOS_GetNicNameList  },
        { "TTOS_GetNicStatusInfo", (char*) TTOS_GetNicStatusInfo  },
        { "TTOS_GetNicTotalNum", (char*) TTOS_GetNicTotalNum  },
        { "TTOS_GetOSInfo", (char*) TTOS_GetOSInfo  },
        { "TTOS_GetStaticRouteTableInfo", (char*) TTOS_GetStaticRouteTableInfo  },
        { "TTOS_GetSystemLoggerModel", (char*) TTOS_GetSystemLoggerModel  },
        { "TTOS_GetTotalMemorySize", (char*) TTOS_GetTotalMemorySize  },
        { "TTOS_GetUSBTotalNum", (char*) TTOS_GetUSBTotalNum  },
        { "TTOS_GetVMInternalInfo", (char*) TTOS_GetVMInternalInfo  },
        { "TTOS_ReStartVM", (char*) TTOS_ReStartVM  },
        { "TTOS_ReStartVMByImage", (char*) TTOS_ReStartVMByImage  },
        { "TTOS_SetFunctionInfo", (char*) TTOS_SetFunctionInfo  },
        { "TTOS_SetOSInfo", (char*) TTOS_SetOSInfo  },
        { "USBGetInfoByName", (char*) USBGetInfoByName  },
        { "get_dev_agent_priority", (char*) get_dev_agent_priority  },
        { "get_dev_agent_stack_size", (char*) get_dev_agent_stack_size  },
        { "set_dev_agent_priority", (char*) set_dev_agent_priority  },
        { "set_dev_agent_stack_size", (char*) set_dev_agent_stack_size  },
        { "TTOS_InitDevInfoAgent", (char*) TTOS_InitDevInfoAgent  },
        { "getDevID", (char*) getDevID  },
        { "vmCpuId", (char*) &vmCpuId  },
        { "vmDiskSz", (char*) &vmDiskSz  },
        { "VMM_ControlVM", (char*) VMM_ControlVM  },
        { "VMM_GetCpuIDs", (char*) VMM_GetCpuIDs  },
        { "VMM_GetCPUMainFrameTicks", (char*) VMM_GetCPUMainFrameTicks  },
        { "VMM_GetDeviceMemorySize", (char*) VMM_GetDeviceMemorySize  },
        { "VMM_GetDeviceName", (char*) VMM_GetDeviceName  },
        { "VMM_GetDeviceNicTotalNum", (char*) VMM_GetDeviceNicTotalNum  },
        { "VMM_GetNicMacRange", (char*) VMM_GetNicMacRange  },
        { "VMM_GetVMBasicInfo", (char*) VMM_GetVMBasicInfo  },
        { "VMM_GetVMInfo", (char*) VMM_GetVMInfo  },
        { "VMM_GetVMNicDefaultConfig", (char*) VMM_GetVMNicDefaultConfig  },
        { "VMM_GetVMNicTotalNum", (char*) VMM_GetVMNicTotalNum  },
        { "VMM_GetVMTotalNum", (char*) VMM_GetVMTotalNum  },
        { "VMM_GetVscInfo", (char*) VMM_GetVscInfo  },
        { "vmMemSz", (char*) &vmMemSz  },
    };


int rtpSymNum = 2391;
