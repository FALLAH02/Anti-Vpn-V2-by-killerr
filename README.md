MoroccoAntiVPN 

Advanced IP Country Verification for SA-MP & open.mp 

Protect your server. Allow Morocco. Block foreign IPs.

About 

MoroccoAntiVPN is a lightweight and easy-to-use Pawn include designed for SA-MP and open.mp servers.

The system verifies player IP addresses and allows connections only from Morocco (MA).

Features Feature Description Morocco Only Allows Moroccan IP addresses GeoIP Check Automatic country verification Auto Kick Blocks foreign IP addresses HTTP System Online IP verification Easy Integration Simple .inc installation Localhost Localhost exemption Installation 

Step 01 — Download

Download the latest MoroccoAntiVPN.inc file.

Step 02 — Install

Move the file into:

pawno/include/MoroccoAntiVPN.inc 

Step 03 — Include

Add this line to your gamemode:

#include <MoroccoAntiVPN> Configuration 

Default country configuration:

#define MAV_ALLOWED_COUNTRY "MA" #define MAV_KICK_DELAY 1500 Implementation Initialize public OnGameModeInit() { MAV_Init(); return 1; } Player Connection public OnPlayerConnect(playerid) { MAV_CheckPlayer(playerid); return 1; } Player Disconnection public OnPlayerDisconnect(playerid, reason) { MAV_ResetPlayer(playerid); return 1; } 

Note: Integrate these calls into your existing callbacks. Do not create duplicate callbacks.

Requirements SA-MP 0.3.7 or open.mp Pawn Compiler Internet connection ip-api.com GeoIP service Limitations 

This version performs country verification only.

VPN, Proxy and Hosting detection are not included yet.

Credits 

MoroccoAntiVPN Development

Made for the SA-MP & open.mp community.

License 

Distributed under the MIT License.

MoroccoAntiVPN — Protect Your Server.

