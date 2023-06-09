/*
 * Copyright (c) 2013, Court of the University of Glasgow
 * Copyright (c) 2020, University of Oregon
 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:

 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * - Neither the name of the University of Glasgow nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 * - Neither the name of the University of Oregon nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * header file for endpoint ADT used in the Buffer eXchange Protocol
 */

#ifndef _ENDPOINT_H_
#define _ENDPOINT_H_

#include <netinet/in.h>

/*
 * all data in an endpoint is in NETWORK order;
 * this is true by default for a sockaddr_in
 */
typedef struct endpoint {
    struct sockaddr_in addr;
    unsigned long subport;
} BXPEndpoint;

/*
 * complete (fill in) the endpoint with the sockaddr and subport
 */
void endpoint_complete(BXPEndpoint *ep, struct sockaddr_in *addr,
                       unsigned long subport);

/*
 * construct an endpoint from the arguments
 */
BXPEndpoint *endpoint_create(struct sockaddr_in *addr, unsigned long subport);

/*
 * construct an endpoint from the remaining arguments
 */
void endpoint_construct(BXPEndpoint *ep, struct sockaddr_in *addr,
                        unsigned long subport);

/*
 * duplicate endpoint
 */
BXPEndpoint *endpoint_duplicate(BXPEndpoint *ep);

/*
 * determine if two endpoints are equal
 */
int endpoint_equal(BXPEndpoint *ep1, BXPEndpoint *ep2);

/*
 * compute hash value for an endpoint
 *
 * returns value in the range of 0..limit-1
 */
unsigned endpoint_hash(BXPEndpoint *ep, unsigned limit);

/*
 * dump an endpoint
 */
void endpoint_dump(BXPEndpoint *ep, char *leadString);

#endif /* _ENDPOINT_H_ */
