#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <ns3/command-line.h>
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/olsr-helper.h"
#include "ns3/ipv4-static-routing-helper.h"
#include "ns3/ipv4-list-routing-helper.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("SimplePointToPointOlsrExample");

int
main (int argc, char *argv[])
{
// Users may find it convenient to turn on explicit debugging
// for selected modules; the below lines suggest how to do this
#if 0
LogComponentEnable ("SimpleGlobalRoutingExample", LOG_LEVEL_INFO);
#endif

// Set up some default values for the simulation. Use the

Config::SetDefault ("ns3::OnOffApplication::PacketSize", UintegerValue (210));
Config::SetDefault ("ns3::OnOffApplication::DataRate", StringValue ("448kb/s"));

//DefaultValue::Bind ("DropTailQueue::m_maxPackets", 30);

// Allow the user to override any of the defaults and the above
// DefaultValue::Bind ()s at run-time, via command-line arguments
//CommandLinecmd; cmd.Parse (argc, argv);

// Here, we will explicitly create four nodes. In more sophisticated
// topologies, we could configure a node factory. 
NS_LOG_INFO ("Create nodes."); 
NodeContainer c;
c.Create (5);
NodeContainer n02 = NodeContainer (c.Get (0), c.Get (2)); NodeContainer n12 = NodeContainer (c.Get (1), c.Get (2)); NodeContainer n32 = NodeContainer (c.Get (3), c.Get (2)); NodeContainer n34 = NodeContainer (c.Get (3), c.Get (4));

// Enable OLSR
NS_LOG_INFO ("Enabling OLSR Routing.");
OlsrHelper olsr;

Ipv4StaticRoutingHelper staticRouting;

Ipv4ListRoutingHelper list; 
list.Add (staticRouting, 0);
list.Add (olsr, 10);
/*
std::list<int>::iterator it = list.begin();
list.insert(it, olsr);

std::__cxx11::list.Add (staticRouting, 0);
std::__cxx11::list.Add (olsr, 10);
*/
InternetStackHelper internet;
internet.SetRoutingHelper (list); // has effect on the next Install () 
internet.Install (c);

// We create the channels first without any IP addressing information
NS_LOG_INFO ("Create channels.");
PointToPointHelper p2p;
p2p.SetDeviceAttribute ("DataRate", StringValue ("5Mbps")); p2p.SetChannelAttribute ("Delay", StringValue ("2ms")); NetDeviceContainer nd02 = p2p.Install (n02); NetDeviceContainer nd12 = p2p.Install (n12); p2p.SetDeviceAttribute ("DataRate", StringValue ("1500kbps")); p2p.SetChannelAttribute ("Delay", StringValue ("10ms")); NetDeviceContainer nd32 = p2p.Install (n32); NetDeviceContainer nd34 = p2p.Install (n34);

// Later, we add IP addresses. 
NS_LOG_INFO ("Assign IP Addresses."); 
Ipv4AddressHelper ipv4;
ipv4.SetBase ("10.1.1.0", "255.255.255.0");
Ipv4InterfaceContainer i02 = ipv4.Assign (nd02);

ipv4.SetBase ("10.1.2.0", "255.255.255.0");
Ipv4InterfaceContainer i12 = ipv4.Assign (nd12);

ipv4.SetBase ("10.1.3.0", "255.255.255.0");
Ipv4InterfaceContainer i32 = ipv4.Assign (nd32);

ipv4.SetBase ("10.1.4.0", "255.255.255.0");
Ipv4InterfaceContainer i34 = ipv4.Assign (nd34);

// Create the OnOff application to send UDP datagrams of size
// 210 bytes at a rate of 448 Kb/s from n0 to n4 
NS_LOG_INFO ("Create Applications."); 
uint16_t port = 9; // Discard port (RFC 863)

OnOffHelper onoff ("ns3::UdpSocketFactory", InetSocketAddress (i34.GetAddress (1), port)); onoff.SetConstantRate (DataRate ("448kb/s"));
/*
ApplicationContainer apps = onoff.Install (c.Get (0)); 
apps.Start (Seconds (1.0));
apps.Stop (Seconds (10.0));
*/
// Create a packet sink to receive these packets 
//PacketSinkHelpersink sink("ns3::UdpSocketFactory", InetSocketAddress (Ipv4Address::GetAny (), port));
PacketSinkHelper sink("ns3::UdpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port));

/*
apps = sink.Install (c.Get (3)); 
apps.Start (Seconds (1.0));
*/
ApplicationContainer apps = sink.Install(c.Get(3));
apps.Start(Seconds(1.0));

apps.Stop (Seconds (10.0));



// Create a similar flow from n3 to n1, starting at time 1.1 seconds 
//onoff.SetAttribute = ("Remote",AddressValue (InetSocketAddress (i12.GetAddress (0), port))); 

onoff.SetAttribute("Remote", AddressValue(InetSocketAddress(i12.GetAddress(0), port)));
apps = onoff.Install (c.Get (3));
apps.Start (Seconds (1.1));
apps.Stop (Seconds (10.0));

// Create a packet sink to receive these packets 
apps = sink.Install (c.Get (1));
apps.Start (Seconds (1.1));
apps.Stop (Seconds (10.0));

AsciiTraceHelper ascii;
p2p.EnableAsciiAll (ascii.CreateFileStream ("simple-point-to-point-olsr.tr")); p2p.EnablePcapAll ("simple-point-to-point-olsr");

Simulator::Stop (Seconds (30));

NS_LOG_INFO ("Run Simulation."); Simulator::Run (); Simulator::Destroy (); NS_LOG_INFO ("Done.");

return 0;
}