/**
@file		link_device_mem_config.h
@brief		configurations of memory-type interface
@date		2014/02/05
@author		Hankook Jang (hankook.jang@samsung.com)
*/

/*
 * Copyright (C) 2010 Samsung Electronics.
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

#ifndef __MODEM_LINK_DEVICE_MEM_CONFIG_H__
#define __MODEM_LINK_DEVICE_MEM_CONFIG_H__

#define GROUP_MEM_TYPE
#define GROUP_MEM_TYPE_SHMEM

#define GROUP_MEM_LINK_DEVICE
#define GROUP_MEM_LINK_SNAPSHOT
#define GROUP_MEM_LINK_INTERRUPT
#define GROUP_MEM_LINK_SETUP
#define GROUP_MEM_LINK_METHOD
#define GROUP_MEM_LINK_COMMAND

#define GROUP_MEM_IPC_DEVICE
#define GROUP_MEM_IPC_TX
#define GROUP_MEM_IPC_RX
#define GROUP_MEM_FLOW_CONTROL

#define GROUP_MEM_CP_CRASH

#define GROUP_MEM_LINK_DEBUG

/**
@defgroup group_mem_type		Memory Type
*/

/**
@defgroup group_mem_type_shmem		Shared Memory
@ingroup group_mem_type
*/

/**
@defgroup group_mem_link_device		Memory Link Device
*/

/**
@defgroup group_mem_link_snapshot	Memory Snapshot
@ingroup group_mem_link_device
*/

/**
@defgroup group_mem_link_setup		Link Setup
@ingroup group_mem_link_device
*/

/**
@defgroup group_mem_link_method		Link Method
@ingroup group_mem_link_device
*/

/**
@defgroup group_mem_link_interrupt	Interrupt
@ingroup group_mem_link_device
*/

/**
@defgroup group_mem_link_command	Link Command
@ingroup group_mem_link_device
*/

/**
@defgroup group_mem_ipc_device		Logical IPC Device
@ingroup group_mem_link_device
*/

/**
@defgroup group_mem_ipc_tx		TX
@ingroup group_mem_ipc_device
*/

/**
@defgroup group_mem_ipc_rx		RX
@ingroup group_mem_ipc_device
*/

/**
@defgroup group_mem_flow_control	Flow Control
@ingroup group_mem_ipc_device
*/

/**
@defgroup group_mem_cp_crash		CP Crash Dump
@ingroup group_mem_link_device
*/

/**
@defgroup group_mem_link_debug		Debugging
@ingroup group_mem_link_device
*/

#endif
