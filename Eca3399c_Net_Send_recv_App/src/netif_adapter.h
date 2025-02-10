/*
 * netif_Intel_I350AM4_fops.h
 *
 *  Created on: 2018-5-3
 *      Author: Administrator
 */

#ifndef NETIF_ADAPTER_H_
#define NETIF_ADAPTER_H_
#include <open_flag.h>
#include <configTableUtils.h>
#include <devinfo.h>
#include <vmkDR.h>
#include <arch/sys/sys_os.h>

#define MAX_NIC_NUM 64
#define MAX_NIC_NAME 32

#define ETHERNETIF_DEV_NAME_LEN DEVICE_NAME_SIZE

typedef unsigned int (*net_write_copy_data_fun)(void *buf, unsigned int size, void *data);

struct data_buf
{
	T_WORD len;
	T_UBYTE *data;
};

struct raw_socket_send_buf_node
{
	T_UBYTE used;//为0，表示该节点空闲；为1，表示该节点已经被占用
	struct data_buf data;
};

struct netif_adapter_info
{
	sys_mbox_t msgq_recv_id;
	sys_mbox_t msgq_send_id;
	T_BYTE init_flag;
	T_BOOL   open_flag;
	T_UBYTE *node_array;
	T_UWORD send_node_num;
	T_UWORD recv_node_num;
	T_UWORD send_buf_size;
	sys_mutex_t node_mutex_lock;
	T_BOOL (*drv_write) (T_UBYTE minor, void *data);
	ssize_t (*drv_read) (sys_mbox_t *msg_id,T_VOID *buf, size_t len, T_UWORD ticks);	
	void (*drv_get_nic_info) (T_UBYTE minor, T_NIC_Basic_Info *nicInfo);
	T_WORD (*drv_get_mac_addr) (T_UBYTE minor, T_VOID *mac);
	T_WORD (*drv_set_mac_addr) (T_UBYTE minor, T_VOID *mac);
    T_UWORD timeout_val;
};

T_WORD adapter_open(T_WORD pDevHeader,T_BYTE *path, T_UWORD flags, T_WORD mode);
ssize_t adapter_read(T_UWORD fileDescriptor, T_VOID *buf, size_t size);
ssize_t adapter_write(T_UWORD fileDescriptor, T_VOID *buf, size_t size);
ssize_t adapter_close(T_UWORD fileDescriptor);
T_WORD adapter_ioctl(T_WORD fd, T_WORD command, T_WORD arg);
T_VOID init_ethernetif_list(T_VOID);
T_WORD register_raw_socket_dev(T_DM_DAT *drvptr, T_UBYTE *name, T_UWORD devType);

extern T_DM_DAT  raw_socket_drvptr;
extern T_DM_DAT  intel_82574_drvptr;
#endif /* NETIF_INTEL_I350AM4_FOPS_H_ */
