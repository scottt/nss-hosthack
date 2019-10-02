/* Copyright (c) 2011-2019, Scott Tsai
 * 
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
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
#include <nss.h>
#include <stdint.h>
#include <stddef.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED __attribute__((unused))

enum nss_status
_nss_hosthack_gethostbyname4_r(
		const char *name,
		struct gaih_addrtuple **pat,
		char *buffer, size_t buflen,
		int *errnop, int *h_errnop,
		int32_t *ttlp) __attribute__((visibility("default")));

enum nss_status
_nss_hosthack_gethostbyname3_r(
                const char *name,
                int af,
                struct hostent *host,
                char *buffer, size_t buflen,
                int *errnop, int *h_errnop,
                int32_t *ttlp,
                char **canonp) __attribute__((visibility("default")));

enum nss_status
_nss_hosthack_gethostbyname2_r(
                const char *name,
                int af,
                struct hostent *host,
                char *buffer, size_t buflen,
                int *errnop, int *h_errnop) __attribute__((visibility("default")));

enum nss_status
_nss_hosthack_gethostbyname_r(
                const char *name,
                struct hostent *host,
                char *buffer, size_t buflen,
                int *errnop, int *h_errnop) __attribute__((visibility("default")));

enum nss_status
_nss_hosthack_gethostbyaddr2_r(
                const void* addr, socklen_t len,
                int af,
                struct hostent *host,
                char *buffer, size_t buflen,
                int *errnop, int *h_errnop,
                int32_t *ttlp) __attribute__((visibility("default")));

enum nss_status
_nss_hosthack_gethostbyaddr_r(
                const void* addr, socklen_t len,
                int af,
                struct hostent *host,
                char *buffer, size_t buflen,
                int *errnop, int *h_errnop) __attribute__((visibility("default")));

enum {
	DELAY_SECS = 5,
};

enum nss_status
_nss_hosthack_gethostbyname4_r(
                const char *name,
                struct gaih_addrtuple **pat UNUSED,
                char *buffer UNUSED, size_t buflen UNUSED,
                int *errnop UNUSED, int *h_errnop UNUSED,
                int32_t *ttlp UNUSED)
{
	fprintf(stderr, "%s(\"%s\") called\n", __func__, name);
	sleep(DELAY_SECS);
	return NSS_STATUS_UNAVAIL;

}

enum nss_status _nss_hosthack_gethostbyname3_r(
                const char *name,
                int af UNUSED,
                struct hostent *host UNUSED,
                char *buffer UNUSED, size_t buflen UNUSED,
                int *errnop UNUSED, int *h_errnop UNUSED,
                int32_t *ttlp UNUSED,
                char **canonp UNUSED)
{
	fprintf(stderr, "%s(\"%s\") called\n", __func__, name);
	sleep(DELAY_SECS);
	return NSS_STATUS_UNAVAIL;
}

enum nss_status _nss_hosthack_gethostbyname2_r(
                const char *name,
                int af,
                struct hostent *host,
                char *buffer, size_t buflen,
                int *errnop, int *h_errnop)
{
        return _nss_hosthack_gethostbyname3_r(
                        name,
                        af,
                        host,
                        buffer, buflen,
                        errnop, h_errnop,
                        NULL,
                        NULL);
}

enum nss_status _nss_hosthack_gethostbyname_r(
                const char *name,
                struct hostent *host,
                char *buffer, size_t buflen,
                int *errnop, int *h_errnop)
{
        return _nss_hosthack_gethostbyname3_r(
                        name,
                        AF_UNSPEC,
                        host,
                        buffer, buflen,
                        errnop, h_errnop,
                        NULL,
                        NULL);
}

enum nss_status _nss_hosthack_gethostbyaddr2_r(
                const void* addr UNUSED, socklen_t len UNUSED,
                int af UNUSED,
                struct hostent *host UNUSED,
                char *buffer UNUSED, size_t buflen UNUSED,
                int *errnop UNUSED, int *h_errnop UNUSED,
                int32_t *ttlp UNUSED)
{
	fprintf(stderr, "%s called\n", __func__);
	sleep(5);
	return NSS_STATUS_UNAVAIL;
}

enum nss_status _nss_hosthack_gethostbyaddr_r(
                const void* addr, socklen_t len,
                int af,
                struct hostent *host,
                char *buffer, size_t buflen,
                int *errnop, int *h_errnop)
{
        return _nss_hosthack_gethostbyaddr2_r(
                        addr, len,
                        af,
                        host,
                        buffer, buflen,
                        errnop, h_errnop,
                        NULL);
}
