/*
 * Copyright (C) 2011 Samsung Electronics.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __MODEM_UTILS_H__
#define __MODEM_UTILS_H__

#include <linux/rbtree.h>
#include "modem_prj.h"

#define IS_CONNECTED(iod, ld) ((iod)->link_types & LINKTYPE((ld)->link_type))

#define MAX_MIF_BUFF_SIZE 0x80000 /* 512kb */
#define MAX_MIF_SEPA_SIZE 32
#define MIF_SEPARATOR "IPC_LOGGER(VER1.1)"
#define MIF_SEPARATOR_DPRAM "DPRAM_LOGGER(VER1.1)"
#define MAX_IPC_SKB_SIZE 4096
#define MAX_LOG_SIZE 64

#define MIF_TAG	"mif"

#define MAX_LOG_CNT (MAX_MIF_BUFF_SIZE / MAX_LOG_SIZE)
#define MIF_ID_SIZE sizeof(enum mif_log_id)

#define MAX_IPC_LOG_SIZE \
	(MAX_LOG_SIZE - sizeof(enum mif_log_id) \
	 - sizeof(unsigned long long) - sizeof(size_t))
#define MAX_IRQ_LOG_SIZE \
	(MAX_LOG_SIZE - sizeof(enum mif_log_id) \
	 - sizeof(unsigned long long) - sizeof(struct mif_irq_map))
#define MAX_COM_LOG_SIZE \
	(MAX_LOG_SIZE - sizeof(enum mif_log_id) \
	 - sizeof(unsigned long long))
#define MAX_TIM_LOG_SIZE \
	(MAX_LOG_SIZE - sizeof(enum mif_log_id) \
	 - sizeof(unsigned long long) - sizeof(struct timespec))

enum mif_log_id {
	MIF_IPC_RL2AP = 1,
	MIF_IPC_AP2CP,
	MIF_IPC_CP2AP,
	MIF_IPC_AP2RL,
	MIF_IRQ,
	MIF_COM,
	MIF_TIME
};

struct mif_irq_map {
	u16 magic;
	u16 access;

	u16 fmt_tx_in;
	u16 fmt_tx_out;
	u16 fmt_rx_in;
	u16 fmt_rx_out;

	u16 raw_tx_in;
	u16 raw_tx_out;
	u16 raw_rx_in;
	u16 raw_rx_out;

	u16 cp2ap;
};

struct mif_ipc_block {
	enum mif_log_id id;
	unsigned long long time;
	size_t len;
	char buff[MAX_IPC_LOG_SIZE];
};

struct mif_irq_block {
	enum mif_log_id id;
	unsigned long long time;
	struct mif_irq_map map;
	char buff[MAX_IRQ_LOG_SIZE];
};

struct mif_common_block {
	enum mif_log_id id;
	unsigned long long time;
	char buff[MAX_COM_LOG_SIZE];
};

struct mif_time_block {
	enum mif_log_id id;
	unsigned long long time;
	struct timespec epoch;
	char buff[MAX_TIM_LOG_SIZE];
};

struct __packed utc_time {
	u32 year:18,
	    mon:4,
	    day:5,
	    hour:5;
	u32 min:6,
	    sec:6,
	    us:20;
};

/* {Hour, Minute, Second, U(micro)-second} format */
#define HMSU_FMT	"[%02d:%02d:%02d.%06d]"

#define evt_log(fmt, ...) \
	printk_ratelimited(KERN_ERR LOG_TAG pr_fmt(fmt), ##__VA_ARGS__)

static inline unsigned long ns2us(unsigned long ns)
{
	return (ns > 0) ? (ns / 1000) : 0;
}

static inline unsigned long ns2ms(unsigned long ns)
{
	return (ns > 0) ? (ns / 1000000) : 0;
}

static inline unsigned long us2ms(unsigned long us)
{
	return (us > 0) ? (us / 1000) : 0;
}

static inline unsigned long ms2us(unsigned long ms)
{
	return ms * 1E3L;
}

static inline unsigned long ms2ns(unsigned long ms)
{
	return ms * 1E6L;
}

void ts2utc(struct timespec *ts, struct utc_time *utc);
void get_utc_time(struct utc_time *utc);
void print_utc_time(int level, struct utc_time *utc);
void print_timespec(int level, struct timespec *ts);

/**
@brief		calculate the offset of @e @@target from @e @@base in bytes
*/
static inline unsigned int calc_offset(void *target, void *base)
{
	return (unsigned int)target - (unsigned int)base;
}

int mif_dump_log(struct modem_shared *, struct io_device *);

#define mif_irq_log(msd, map, data, len) \
	_mif_irq_log(MIF_IRQ, msd, map, data, len)
#define mif_com_log(msd, format, ...) \
	_mif_com_log(MIF_COM, msd, pr_fmt(format), ##__VA_ARGS__)
#define mif_time_log(msd, epoch, data, len) \
	_mif_time_log(MIF_TIME, msd, epoch, data, len)

void mif_ipc_log(enum mif_log_id,
	struct modem_shared *, const char *, size_t);
void _mif_irq_log(enum mif_log_id,
	struct modem_shared *, struct mif_irq_map, const char *, size_t);
void _mif_com_log(enum mif_log_id,
	struct modem_shared *, const char *, ...);
void _mif_time_log(enum mif_log_id,
	struct modem_shared *, struct timespec, const char *, size_t);

/**
@brief		find a link device

@param	msd		struct modem_shared *
@param	link_type	the type of a link device

@retval	struct link_device *	if NO error
@retval "NULL"			if ANY error
*/
static inline struct link_device *find_linkdev(struct modem_shared *msd,
		enum modem_link link_type)
{
	struct link_device *ld;
	list_for_each_entry(ld, &msd->link_dev_list, list) {
		if (ld->link_type == link_type)
			return ld;
	}
	return NULL;
}

/**
@brief		count number of 1 bits as fastest way
@param n	number
*/
static inline unsigned int countbits(unsigned int n)
{
	unsigned int i;
	for (i = 0; n != 0; i++)
		n &= (n - 1);
	return i;
}

/**
@brief		check whether or not the counter value @b @@cnt gets to the
		counter boundary mask @b @@mask
@remark		@b @@mask must be a number of (2^n - 1), e.g. 0xF, 0x1F, etc.
*/
static inline bool count_flood(int cnt, int mask)
{
	return (cnt > 0 && (cnt & mask) == 0) ? true : false;
}

/* print IPC/UDL message as hex string with UTC time */
void pr_ipc(int level, const char *tag, const char *data, size_t len);

/**
@brief		print an IPC data @b WITH a @b LINK header

@param ch	the SIPC channel ID
@param layer	the layer in the Samsung IPC
@param dir	the direction of communication (TX or RX)
@param skb	the pointer to a sk_buff instance
@param hd_exist	whether or not there is a link header in a message frame
@param hd_print	whether or not a link header will be logged

@remark		if @e @@hd_exist is false, @e @@hd_print is ignored.
*/
void log_ipc_pkt(u8 ch, enum ipc_layer layer, enum direction dir,
		 struct sk_buff *skb, bool hd_exist, bool hd_print);

/* print buffer as hex string */
int pr_buffer(const char *tag, const char *data, size_t data_len,
							size_t max_len);

/* print a sk_buff as hex string */
#define pr_skb(tag, skb) \
	pr_buffer(tag, (char *)((skb)->data), (size_t)((skb)->len), (size_t)16)

/* print a urb as hex string */
#define pr_urb(tag, urb) \
	pr_buffer(tag, (char *)((urb)->transfer_buffer), \
			(size_t)((urb)->actual_length), (size_t)16)

/* Stop/wake all TX queues in network interfaces */
void mif_netif_stop(struct link_device *ld);
void mif_netif_wake(struct link_device *ld);
void stop_net_ifaces(struct link_device *ld);
void resume_net_ifaces(struct link_device *ld);

/* flow control CMD from CP, it use in serial devices */
int link_rx_flowctl_cmd(struct link_device *ld, const char *data, size_t len);

/* get iod from tree functions */

struct io_device *get_iod_with_format(struct modem_shared *msd,
					enum dev_format format);
struct io_device *get_iod_with_channel(struct modem_shared *msd,
					unsigned int channel);

static inline struct io_device *link_get_iod_with_format(
			struct link_device *ld, enum dev_format format)
{
	struct io_device *iod = get_iod_with_format(ld->msd, format);
	return (iod && IS_CONNECTED(iod, ld)) ? iod : NULL;
}

static inline struct io_device *link_get_iod_with_channel(
			struct link_device *ld, unsigned int channel)
{
	struct io_device *iod = get_iod_with_channel(ld->msd, channel);
	return (iod && IS_CONNECTED(iod, ld)) ? iod : NULL;
}

/* insert iod to tree functions */
struct io_device *insert_iod_with_format(struct modem_shared *msd,
			enum dev_format format, struct io_device *iod);
struct io_device *insert_iod_with_channel(struct modem_shared *msd,
			unsigned int channel, struct io_device *iod);

/* iodev for each */
typedef void (*action_fn)(struct io_device *iod, void *args);
void iodevs_for_each(struct modem_shared *msd, action_fn action, void *args);

/* netif wake/stop queue of iod */
void iodev_netif_wake(struct io_device *iod, void *args);
void iodev_netif_stop(struct io_device *iod, void *args);

/* change tx_link of raw devices */
void rawdevs_set_tx_link(struct modem_shared *msd, enum modem_link link_type);

__be32 ipv4str_to_be32(const char *ipv4str, size_t count);

void mif_add_timer(struct timer_list *timer, unsigned long expire,
		void (*function)(unsigned long), unsigned long data);

/* debug helper functions for sipc4, sipc5 */
void mif_print_data(const u8 *data, int len);

void mif_dump2format16(const u8 *data, int len, char *buff, char *tag);
void mif_dump2format4(const u8 *data, int len, char *buff, char *tag);
void mif_print_dump(const u8 *data, int len, int width);

void print_sipc4_hdlc_fmt_frame(const u8 *psrc);
void print_sipc4_fmt_frame(const u8 *psrc);
void print_sipc5_link_fmt_frame(const u8 *psrc);

/*---------------------------------------------------------------------------

				IPv4 Header Format

	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|Version|  IHL  |Type of Service|          Total Length         |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|         Identification        |C|D|M|     Fragment Offset     |
	|                               |E|F|F|                         |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|  Time to Live |    Protocol   |         Header Checksum       |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|                       Source Address                          |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|                    Destination Address                        |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|                    Options                    |    Padding    |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	IHL - Header Length
	Flags - Consist of 3 bits
		The 1st bit is "Congestion" bit.
		The 2nd bit is "Dont Fragment" bit.
		The 3rd bit is "More Fragments" bit.

---------------------------------------------------------------------------*/
#define IPV4_HDR_SIZE	20

/*-------------------------------------------------------------------------

				TCP Header Format

	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|          Source Port          |       Destination Port        |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|                        Sequence Number                        |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|                    Acknowledgment Number                      |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|  Data |       |C|E|U|A|P|R|S|F|                               |
	| Offset| Rsvd  |W|C|R|C|S|S|Y|I|            Window             |
	|       |       |R|E|G|K|H|T|N|N|                               |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|           Checksum            |         Urgent Pointer        |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|                    Options                    |    Padding    |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|                             data                              |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

-------------------------------------------------------------------------*/
#define TCP_HDR_SIZE	20

/*-------------------------------------------------------------------------

				UDP Header Format

	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|          Source Port          |       Destination Port        |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|            Length             |           Checksum            |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	|                             data                              |
	+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

-------------------------------------------------------------------------*/
#define UDP_HDR_SIZE	8

void print_ip4_packet(const u8 *ip_pkt, bool tx);
bool is_dns_packet(const u8 *ip_pkt);
bool is_syn_packet(const u8 *ip_pkt);

int mif_register_isr(unsigned int irq, irq_handler_t isr, unsigned long flags,
		     const char *name, void *data);
void mif_init_irq(struct modem_irq *irq, unsigned int num, const char *name,
		  unsigned long flags);
int mif_request_irq(struct modem_irq *irq, irq_handler_t isr, void *data);
void mif_enable_irq(struct modem_irq *irq);
void mif_disable_irq(struct modem_irq *irq);

struct file *mif_open_file(const char *path);
void mif_save_file(struct file *fp, const char *buff, size_t size);
void mif_close_file(struct file *fp);

#endif/*__MODEM_UTILS_H__*/

