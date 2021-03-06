/*
 // Copyright (c) 2016 Intel Corporation
 //
 // Licensed under the Apache License, Version 2.0 (the "License");
 // you may not use this file except in compliance with the License.
 // You may obtain a copy of the License at
 //
 //      http://www.apache.org/licenses/LICENSE-2.0
 //
 // Unless required by applicable law or agreed to in writing, software
 // distributed under the License is distributed on an "AS IS" BASIS,
 // WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 // See the License for the specific language governing permissions and
 // limitations under the License.
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <contiki-conf.h>

/* Time resolution */
#include <stdint.h>
typedef uint64_t oc_clock_time_t;
#define OC_CLOCK_CONF_TICKS_PER_SECOND CLOCK_CONF_SECOND

#define OC_BYTES_POOL_SIZE (900)
#define OC_INTS_POOL_SIZE (4)
#define OC_DOUBLES_POOL_SIZE (4)

/* Server-side parameters */
/* Maximum number of server resources */
#define MAX_APP_RESOURCES (1)

/* Common paramters */
/* Maximum size of request/response PDUs */
#define OC_MAX_PDU_BUFFER_SIZE (512)

/* Maximum number of concurrent requests */
#define MAX_NUM_CONCURRENT_REQUESTS (2)

/* Estimated number of nodes in payload tree structure */
#define EST_NUM_REP_OBJECTS (60)

/* Number of devices on the OCF platform */
#define MAX_NUM_DEVICES (1)

/* Platform payload size */
#define MAX_PLATFORM_PAYLOAD_SIZE (256)

/* Device payload size */
#define MAX_DEVICE_PAYLOAD_SIZE (256)

/* Security layer */
/* Maximum number of authorized clients */
#define MAX_NUM_SUBJECTS (1)

/* Maximum number of concurrent DTLS sessions */
#define MAX_DTLS_PEERS (1)

/* Max inactivity timeout before tearing down DTLS connection */
#define DTLS_INACTIVITY_TIMEOUT (10)

#endif /* CONFIG_H */
