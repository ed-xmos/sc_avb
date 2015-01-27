#include "avb_ethernet.h"
#include <timer.h>

#if (NUM_ETHERNET_PORTS == 1)

void avb_ethernet_server(avb_ethernet_ports_t &ports,
                         chanend c_mac_rx[], int num_rx,
                         chanend c_mac_tx[], int num_tx)
{
  char mac_address[6];
  otp_board_info_get_mac(ports.otp_ports, 0, mac_address);
  mii_init_full(ports.mii);         //Sets up MII ports - do before applying reset
  eth_phy_reset(ports.eth_rst);
  //delay_milliseconds(100);
  smi_init(ports.smi);              //Does MDIO/MDC setup
  eth_phy_config(1, ports.smi);     //Sets register values via SMI

  ethernet_server_full(ports.mii, ports.smi,
                       mac_address,
                       c_mac_rx, num_rx,
                       c_mac_tx, num_tx);

}

#endif
