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
#include "UniversalSocket.h"

#ifndef UniversalSocket_def
#define UniversalSocket_def

//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


extern ssize_t Universal_send (int fd, const void *buf, size_t n, int flags){
    return send(fd,buf,n,flags);
}

#if !defined(_DEFAULT_INET_PTON_AND_INET_NTOP_)

extern const char *Universal_inet_ntop(int af, const void *src, char *dst, Universal_socket_len size){
    if (af == AF_INET) {
        unsigned char *p = (unsigned char *)src;
        snprintf(dst, size, "%u.%u.%u.%u", p[0], p[1], p[2], p[3]);
        return dst;
    } else if (af == AF_INET6) {
        unsigned char *p = (unsigned char *)src;
        int i;
        int offset = 0;

        for (i = 0; i < 8; i++) {
            if (offset < size) {
                offset += snprintf(dst + offset, size - offset, "%x", (p[i * 2] << 8) | p[i * 2 + 1]);
            }
            if (i < 7 && offset < size) {
                dst[offset++] = ':';
            }
        }
        return dst;
    }

    return NULL;
}

extern int Universal_inet_pton(int af, const char *src, void *dst){
    if (af == AF_INET) {
        unsigned char *p = (unsigned char *)dst;
        int values[4];
        if (sscanf(src, "%d.%d.%d.%d", &values[0], &values[1], &values[2], &values[3]) != 4) {
            return 0;
        }
        
        for (int i = 0; i < 4; i++) {
            if (values[i] < 0 || values[i] > 255) {
                return 0;
            }
            p[i] = (unsigned char)values[i];
        }

        return 1;
    } 
    else if (af == AF_INET6) {
        unsigned char *p = (unsigned char *)dst;
        int values[8];
        int count = 0;
        const char *ptr = src;
        int i;
        
        while (*ptr) {
            if (sscanf(ptr, "%x", &values[count]) != 1) {
                return 0;
            }
            count++;
            while (*ptr && isxdigit(*ptr)) {
                ptr++;
            }
            if (*ptr == ':') {
                ptr++;
            }
            if (count > 8) {
                return 0;
            }
        }

        if (count != 8) {
            return 0;
        }

        for (i = 0; i < 8; i++) {
            p[i * 2] = (unsigned char)(values[i] >> 8);
            p[i * 2 + 1] = (unsigned char)(values[i] & 0xFF);
        }

        return 1;
    }

    return 0;
}

#else

extern const char *Universal_inet_ntop(int af, const void *src, char *dst, Universal_socket_len size){
    return inet_ntop(af, src, dst, size);
}

extern int Universal_inet_pton(int af, const char *src, void *dst){
    return inet_pton(af, src, dst);
}

#endif

extern uint32_t Universal_ntohl(uint32_t netlong){
    return ntohl(netlong);
}

uint16_t Universal_htons(uint16_t value) {
    return htons(value);
}

uint16_t Universal_ntohs(uint16_t value) {
    return ntohs(value);
}

extern in_addr_t Universal_inet_addr(const char *ip) {
  return inet_addr(ip);
}



//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end

extern int Universal_bind (int fd, Universal_sockaddr_in  *addrin , Universal_socket_len len){
    return bind(fd,(const struct sockaddr *)addrin,len);
}
extern int Universal_accept (int fd, Universal_sockaddr_in *addrin, Universal_socket_len *adrr_len){
    return accept(fd,( struct sockaddr *)addrin, adrr_len);
}
extern int Universal_listen (int fd, int n){
   return  listen(fd,n);
}

extern int Universal_connect(int sockfd, const Universal_sockaddr *addr, socklen_t addrlen){
    return connect(sockfd, addr, addrlen);
}


//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end





const char* Universal_gai_strerror(int e_code){
    return gai_strerror(e_code);
}


//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end

int Universal_socket (int domain, int type, int protocol){
    return socket(domain,type,protocol);
}

int Universal_ZeroMemory(void *ptr, size_t num){

    if (ptr == NULL || num <= 0) {
        return -1;
    }

    memset(ptr, 0, (unsigned long long)num);
    return 0;
}

int Universal_setsockopt(
    Universal_socket_int sockfd,
    int level,
    int optname,
    const void *optval,
    Universal_socket_len optlen
){
    return setsockopt(sockfd, level, optname, (const char *)optval, optlen);
}

int Universal_getsockopt(
    Universal_socket_int sockfd,
    int level,
    int optname,
    void *optval,
    Universal_socket_len *optlen
){
    return getsockopt(sockfd, level, optname, (char *)optval, optlen);
}

Universal_hostent *Universal_gethostbyname(const char *hostname){
    return gethostbyname(hostname);
}



//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


#if defined(__linux__)

extern const char* Universal_inet_ntoa(Universal_in_addr addr) {
  static char buffer[INET_ADDRSTRLEN];
  return inet_ntop(UNI_AF_INET, &addr, buffer, INET_ADDRSTRLEN);
}

extern ssize_t Universal_recv (int fd, void *buf, size_t n, int flags){
    return recv(fd, buf, n,flags);
}

#endif




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


#if defined(__linux__)


extern char *Universal_GetLastError(){
  return strerror(errno);
}



#endif







//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end

#if defined(__linux__)

extern int Universal_start_all (){
    return 0;
}

extern int Universal_end (){
    return 0;
}

extern int Universal_close (int fd){
    return close(fd);
}

//#if defined(_GET_ADDR_INFO_DEFAULT_)
int Universal_getaddrinfo(const char *node, const char *service, const Universal_addrinfo *hints, Universal_addrinfo **res){
    return getaddrinfo(node, service, hints, res);
}


void Universal_freeaddrinfo(Universal_addrinfo *addrinfo_ptr){
    freeaddrinfo(addrinfo_ptr);
}
//#endif





#endif




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


#if defined(_WIN32)

extern const char* Universal_inet_ntoa(Universal_in_addr addr) {
  return inet_ntoa(addr);
}

ssize_t private_Universal_recv_all(int fd, void *buf, size_t n){
  int max = 0;
  int received;

  while (max < n) {
    received = recv(fd, buf + max, n - max, 0);
  
    if (received <= 0) { 
      return received;
    }

    max += received;
  }

  return max;
}

extern ssize_t Universal_recv (int fd, void *buf, size_t n, int flags){

  if(flags == UNI_MSG_WAITALL){
    return private_Universal_recv_all(fd, buf, n);
  }

  return recv(fd, buf, n, flags);
}

#endif




//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end


#if defined(_WIN32)


extern char *Universal_GetLastError(){
  
  static char errorBuffer[256];

  DWORD dwError = WSAGetLastError();
  if (dwError == 0) {
      return "Nenhum erro";
  }

  FormatMessage(
      FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
      NULL,
      dwError,
      0,
      errorBuffer,
      sizeof(errorBuffer),
      NULL
  );

  return errorBuffer;
}



#endif





//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain

//silver_chain_scope_end



#if defined(_WIN32)

extern int Universal_start_all (){
    WSADATA wsa;
    int error = WSAStartup(MAKEWORD(2, 2), &wsa);
    return error;
}

extern int Universal_end (){
    WSACleanup();
}

extern int Universal_close (int fd){
    return closesocket(fd);
}

//#if defined(_GET_ADDR_INFO_DEFAULT_)
int Universal_getaddrinfo(const char *node, const char *service, const Universal_addrinfo *hints, Universal_addrinfo **res){


    Universal_hostent *he;

    he = Universal_gethostbyname(node);

    if(he == NULL){
        return 1;
    }

    *res = (Universal_addrinfo *)malloc(sizeof(Universal_addrinfo));
    if (*res == NULL) {
        return 1;
    }

    (*res)->ai_flags = 0;
    (*res)->ai_family = UNI_AF_INET;
    (*res)->ai_socktype = UNI_SOCK_STREAM;
    (*res)->ai_protocol = UNI_IPPROTO_TCP;
    (*res)->ai_addrlen = sizeof(Universal_sockaddr_in);


    Universal_sockaddr_in *sa_in = (Universal_sockaddr_in *)malloc(sizeof(Universal_sockaddr_in));
    if (sa_in == NULL) {
        free(*res);
        return 1;
    }

    Universal_in_addr **addr_list;
    sa_in->sin_family = UNI_AF_INET;
    addr_list = (Universal_in_addr **)he->h_addr_list;
    sa_in->sin_addr = *addr_list[0];

    (*res)->ai_addr = (Universal_sockaddr *)sa_in;
    (*res)->ai_canonname = strdup(he->h_name);
    (*res)->ai_next = NULL;

    return 0;
}


void Universal_freeaddrinfo(Universal_addrinfo *addrinfo_ptr){

    free(addrinfo_ptr->ai_addr);
    free(addrinfo_ptr->ai_canonname);
    free(addrinfo_ptr);
}
//#endif

#endif

#endif
