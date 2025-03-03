/* MIT License

Copyright (c) 2024 Samuel Henrique

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */ 
#ifndef UniversalSocket_dep
#define UniversalSocket_dep



#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>


//#define _GET_ADDR_INFO_DEFAULT_


#if defined(__linux__)
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#endif

#if defined(_WIN32)

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")

#endif

#endif

#ifndef UniversalSocket_mac
#define UniversalSocket_mac

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


#define UNI_AF_INET AF_INET
#define UNI_INADDR_ANY INADDR_ANY
#define UNI_FD_SET FD_SET
#define UNI_FD_CLR FD_CLR
#define UNI_FD_ISSET FD_ISSET
#define UNI_FD_ZERO FD_ZERO
#define UNI_SOCK_STREAM SOCK_STREAM
#define UNI_SOCK_DGRAM SOCK_DGRAM
#define UNI_SOCK_RAW SOCK_RAW
#define UNI_MSG_PEEK MSG_PEEK
#define UNI_MSG_WAITALL MSG_WAITALL
#define UNI_SO_RCVTIMEO SO_RCVTIMEO
#define UNI_SO_SNDTIMEO SO_SNDTIMEO
#define UNI_SO_KEEPALIVE SO_KEEPALIVE
#define UNI_SO_BROADCAST SO_BROADCAST
#define UNI_SO_LINGER SO_LINGER
#define UNI_AF_UNSPEC AF_UNSPEC
#define UNI_IPPROTO_TCP IPPROTO_TCP
#define UNI_IPPROTO_UDP IPPROTO_UDP
#define UNI_MSG_OOB MSG_OOB
#define UNI_AF_INET6 AF_INET6
#define UNI_SHUT_RD SHUT_RD
#define UNI_SHUT_WR SHUT_WR
#define UNI_SHUT_RDWR SHUT_RDWR

#define UNI_SO_REUSEADDR SO_REUSEADDR
#define UNI_SO_RCVBUF SO_RCVBUF
#define UNI_SOL_SOCKET SOL_SOCKET
#define UNI_AF_INET6 AF_INET6

#define UNI_INET6_ADDRSTRLEN INET6_ADDRSTRLEN

#define UNI_EAI_MEMORY EAI_MEMORY

#define UNI_INET_ADDRSTRLEN INET_ADDRSTRLEN




//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


#if defined(__linux__)

#define UNI_INVALID_SOCKET -1
#define UNI_SOCKET_ERROR -1
#define UNI_EAGAIN EAGAIN
#define UNI_EWOULDBLOCK EWOULDBLOCK

#define UNI_ECONNREFUSED ECONNREFUSED
#define UNI_ETIMEDOUT ETIMEDOUT
#define UNI_EINPROGRESS EINPROGRESS
#define UNI_EADDRNOTAVAIL EADDRNOTAVAIL
#define UNI_ENETUNREACH ENETUNREACH

#define UNI_EAI_NONAME EAI_NONAME 
#define UNI_EAI_AGAIN EAI_AGAIN
#define UNI_EAI_FAIL EAI_FAIL
#define UNI_EAI_NODATA EAI_NONAME

#endif


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


#if defined(_WIN32)

#define UNI_INVALID_SOCKET INVALID_SOCKET
#define UNI_SOCKET_ERROR SOCKET_ERROR
#define UNI_EAGAIN WSAEWOULDBLOCK
#define UNI_EWOULDBLOCK WSAEWOULDBLOCK

#define UNI_ECONNREFUSED WSAECONNREFUSED
#define UNI_ETIMEDOUT WSAETIMEDOUT
#define UNI_EINPROGRESS WSAEINPROGRESS
#define UNI_EADDRNOTAVAIL WSAEADDRNOTAVAIL
#define UNI_ENETUNREACH WSAENETUNREACH

#define UNI_EAI_NONAME WSAHOST_NOT_FOUND
#define UNI_EAI_AGAIN WSATRY_AGAIN
#define UNI_EAI_FAIL WSANO_RECOVERY
#define UNI_EAI_NODATA WSANO_DATA

#endif








#endif

#ifndef UniversalSocket_types
#define UniversalSocket_types

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

typedef struct sockaddr Universal_sockaddr;

typedef struct sockaddr_in Universal_sockaddr_in;

typedef struct sockaddr_in6 Universal_sockaddr_in6;

typedef struct sockaddr_storage Universal_sockaddr_storage;

typedef struct addrinfo Universal_addrinfo;

typedef struct in_addr Universal_in_addr;

typedef struct in6_addr Universal_in6_addr;

typedef struct hostent Universal_hostent;





//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

#if defined(__linux__)

typedef int Universal_socket_int;

typedef socklen_t Universal_socket_len;

typedef unsigned int Universal_DWORD;

typedef ssize_t Universal_ssize_t;

#endif


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end



#if defined(_WIN32)

typedef SOCKET Universal_socket_int;

typedef int Universal_socket_len;

typedef DWORD Universal_DWORD;

typedef unsigned long in_addr_t;

typedef long Universal_ssize_t;

#endif

#endif

#ifndef UniversalSocket_dec
#define UniversalSocket_dec

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end



extern const char* Universal_inet_ntoa(Universal_in_addr addr);





//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

extern ssize_t Universal_recv (int fd, void *buf, size_t n, int flags);

extern ssize_t Universal_send (int fd, const void *buf, size_t n, int flags);

extern const char *Universal_inet_ntop(int af, const void *src, char *dst, Universal_socket_len size);

extern int Universal_inet_pton(int af, const char *src, void *dst);

uint32_t Universal_ntohl(uint32_t netlong);

uint16_t Universal_htons(uint16_t value);

uint16_t Universal_ntohs(uint16_t value);

extern in_addr_t Universal_inet_addr(const char *ip);




//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

extern int Universal_bind (int fd,Universal_sockaddr_in  *addrin , Universal_socket_len len);

extern int Universal_accept (int fd, Universal_sockaddr_in *addrin,
		   Universal_socket_len *adrr_len);

extern int Universal_listen (int fd, int n);

extern int Universal_connect(int sockfd, const Universal_sockaddr *addr, socklen_t addrlen);




//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end





int Universal_getaddrinfo(const char *node, const char *service, const Universal_addrinfo *hints, Universal_addrinfo **res);






//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


extern char *Universal_GetLastError();









//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

extern int Universal_start_all ();

extern int Universal_close (int fd);

extern int Universal_end ();

//#if defined(_GET_ADDR_INFO_DEFAULT_)

int Universal_getaddrinfo(const char *node, const char *service, const Universal_addrinfo *hints, Universal_addrinfo **res);

void Universal_freeaddrinfo(Universal_addrinfo *addrinfo_ptr);
//#endif





//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

int Universal_socket (int domain, int type, int protocol);

int Universal_ZeroMemory(void *ptr, size_t num);

int Universal_setsockopt(
    Universal_socket_int sockfd,
    int level,
    int optname,
    const void *optval,
    Universal_socket_len optlen
);

int Universal_getsockopt(
    Universal_socket_int sockfd,
    int level,
    int optname,
    void *optval,
    Universal_socket_len *optlen
);

Universal_hostent *Universal_gethostbyname(const char *hostname);





#endif
