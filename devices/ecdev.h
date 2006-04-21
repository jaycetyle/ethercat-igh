/******************************************************************************
 *
 *  EtherCAT interface for EtherCAT device drivers.
 *
 *  $Id$
 *
 *  Copyright (C) 2006  Florian Pose, Ingenieurgemeinschaft IgH
 *
 *  This file is part of the IgH EtherCAT Master.
 *
 *  The IgH EtherCAT Master is free software; you can redistribute it
 *  and/or modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; version 2 of the License.
 *
 *  The IgH EtherCAT Master is distributed in the hope that it will be
 *  useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the IgH EtherCAT Master; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/

#ifndef _ETHERCAT_DEVICE_H_
#define _ETHERCAT_DEVICE_H_

#include <linux/netdevice.h>

/*****************************************************************************/

struct ec_device;
typedef struct ec_device ec_device_t;

typedef irqreturn_t (*ec_isr_t)(int, void *, struct pt_regs *);

/*****************************************************************************/
// Registration functions

ec_device_t *ecdev_register(unsigned int master_index,
                            struct net_device *net_dev, ec_isr_t isr,
                            struct module *module);
void ecdev_unregister(unsigned int master_index, ec_device_t *device);

int ecdev_start(unsigned int master_index);
void ecdev_stop(unsigned int master_index);

/*****************************************************************************/
// Device methods

void ecdev_receive(ec_device_t *device, const void *data, size_t size);
void ecdev_link_state(ec_device_t *device, uint8_t newstate);

/*****************************************************************************/

#endif
