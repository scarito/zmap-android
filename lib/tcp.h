/*
 * Copyright (C) 2008 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#ifndef _NETINET_TCP_H
#define _NETINET_TCP_H

#include <endian.h>		/* Include *before* linux/tcp.h */

__BEGIN_DECLS

enum {
  TCP_ESTABLISHED = 1,
  TCP_SYN_SENT,
  TCP_SYN_RECV,
  TCP_FIN_WAIT1,
  TCP_FIN_WAIT2,
  TCP_TIME_WAIT,
  TCP_CLOSE,
  TCP_CLOSE_WAIT,
  TCP_LAST_ACK,
  TCP_LISTEN,
  TCP_CLOSING
};

typedef	u_int32_t tcp_seq;
/*
 * TCP header.
 * Per RFC 793, September, 1981.
 */
struct tcphdr
  {
    __extension__ union
    {
      struct
      {
	u_int16_t th_sport;		/* source port */
	u_int16_t th_dport;		/* destination port */
	tcp_seq th_seq;		/* sequence number */
	tcp_seq th_ack;		/* acknowledgement number */
# if __BYTE_ORDER == __LITTLE_ENDIAN
	u_int8_t th_x2:4;		/* (unused) */
	u_int8_t th_off:4;		/* data offset */
# endif
# if __BYTE_ORDER == __BIG_ENDIAN
	u_int8_t th_off:4;		/* data offset */
	u_int8_t th_x2:4;		/* (unused) */
# endif
	u_int8_t th_flags;
# define TH_FIN	0x01
# define TH_SYN	0x02
# define TH_RST	0x04
# define TH_PUSH	0x08
# define TH_ACK	0x10
# define TH_URG	0x20
	u_int16_t th_win;		/* window */
	u_int16_t th_sum;		/* checksum */
	u_int16_t th_urp;		/* urgent pointer */
      };
      struct
      {
	u_int16_t source;
	u_int16_t dest;
	u_int32_t seq;
	u_int32_t ack_seq;
# if __BYTE_ORDER == __LITTLE_ENDIAN
	u_int16_t res1:4;
	u_int16_t doff:4;
	u_int16_t fin:1;
	u_int16_t syn:1;
	u_int16_t rst:1;
	u_int16_t psh:1;
	u_int16_t ack:1;
	u_int16_t urg:1;
	u_int16_t res2:2;
# elif __BYTE_ORDER == __BIG_ENDIAN
	u_int16_t doff:4;
	u_int16_t res1:4;
	u_int16_t res2:2;
	u_int16_t urg:1;
	u_int16_t ack:1;
	u_int16_t psh:1;
	u_int16_t rst:1;
	u_int16_t syn:1;
	u_int16_t fin:1;
# else
#  error "Adjust your <bits/endian.h> defines"
# endif
	u_int16_t window;
	u_int16_t check;
	u_int16_t urg_ptr;
      };
    };
};

__END_DECLS

#endif /* _NETINET_TCP_H */
