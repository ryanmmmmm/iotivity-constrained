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

#ifndef OCCONNECTIVITY_H
#define OCCONNECTIVITY_H

#include <stdint.h>
#include "config.h"
#include "util/oc_process.h"
#include "port/oc_log.h"

#define COAP_PORT_UNSECURED (5683)
#define ALL_COAP_NODES_V6 "FF02::FD"

typedef struct {
  uint16_t port;
  uint8_t address[16];
  uint8_t scope;
} oc_ipv6_addr_t;

typedef struct {
  uint8_t type;
  uint8_t address[6];
} oc_le_addr_t;

typedef struct {
  enum transport_flags {
    IP = 1 << 0,         // IPv6
    GATT = 1 << 1,       // GATT over BLE
    MULTICAST = 1 << 2,
    SECURED = 1 << 3
  } flags;

  union {
    /// IPv6 address of the peer.
    oc_ipv6_addr_t ipv6_addr;

    /// BLE address of the GATT peer.
    oc_le_addr_t gatt_addr;
  };
} oc_endpoint_t;

#define oc_make_ip_endpoint(__name__, __flags__, __port__, ...)		\
  oc_endpoint_t __name__ = { .flags = __flags__ ,			\
			     .ipv6_addr = {.port = __port__,		\
					   .address = {__VA_ARGS__}}}

typedef struct oc_message_s {
  struct oc_message_s *next;
  
  uint8_t ref_count;
  
  oc_endpoint_t endpoint;

  size_t length;

  uint8_t data[MAX_PAYLOAD_SIZE];
} oc_message_t;

void oc_send_buffer(oc_message_t * message);

#if POLL_NETWORK
void oc_poll_network();
#endif

uint16_t oc_connectivity_get_dtls_port();

int oc_connectivity_init();

void oc_connectivity_shutdown();

void oc_send_multicast_message(oc_message_t *message);

#endif /* OCCONNECTIVITY_H */
