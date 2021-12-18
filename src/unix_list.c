#include "unix_list.h"

int unix_list(int argc, char const *argv[])
{
  /** Stores the addresses */
  struct ifaddrs *addresses;

  /** Allocates memory and fills in a linked list of addresses. Returns 0 if success or -1 on failure. */
  if (getifaddrs(&addresses) == -1)
  {
    printf("getifaddrs call failed\n");
    return -1;
  }

  struct ifaddrs *address = addresses;

  /** For each address, we identify the address family. We are interested in AF_INET (IPv4 addresses) and AF_INET6 (IPv6 addresses). The getifaddrs() function can return other types, so we skip those. */
  while (address)
  {
    int family = address->ifa_addr->sa_family;
    if (family == AF_INET || family == AF_INET6)
    {
      /** For each address, we then continue to print its adapter name and its address type, IPv4 or IPv6. */
      printf("%s\t", address->ifa_name);
      printf("%s\t", family == AF_INET ? "IPv4" : "IPv6");

      /** Buffer to store the textual address. */
      char ap[100];
      const int family_size = family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
      getnameinfo(address->ifa_addr, family_size, ap, sizeof(ap), 0, 0, NI_NUMERICHOST);
      printf("\t%s\n", ap);
    }

    address = address->ifa_next;
  }

  /** Free the memory allocated by getifaddrs() */
  freeifaddrs(addresses);
  
  return 0;
}
