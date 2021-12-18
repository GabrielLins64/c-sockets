#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Chapter 1 example. For every network adapter, prints its name, 
 * address type (IPv4 ou IPv6) and its address.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int unix_list(int argc, char const *argv[]);
