MoroccoAntiVPN 

A Morocco-only IP verification system for SA-MP & open.mp servers.

MoroccoAntiVPN is a lightweight Pawn include designed to restrict server access to Moroccan IP addresses using GeoIP verification.

Features Morocco-only access (MA). Automatic IP country verification. Automatic kick for non-Moroccan IP addresses. HTTP-based GeoIP verification. Localhost exemption. Easy integration into existing gamemodes. Independent Pawn include (.inc). Installation Download MoroccoAntiVPN.inc. Put it inside your server's pawno/include folder. Add the following to your gamemode: #include <MoroccoAntiVPN> Usage 

Initialize the system:

public OnGameModeInit() { MAV_Init(); return 1; } 

Check players:

public OnPlayerConnect(playerid) { MAV_CheckPlayer(playerid); return 1; } 

Reset player data:

public OnPlayerDisconnect(playerid, reason) { MAV_ResetPlayer(playerid); return 1; } Configuration #define MAV_ALLOWED_COUNTRY "MA" #define MAV_KICK_DELAY 1500 Important Notes Requires the SA-MP HTTP API. Uses ip-api.com for GeoIP country verification. Internet access is required. This version checks country only; VPN and Proxy detection are not yet implemented. GeoIP results are not guaranteed to identify the user's physical location. Credits 

MoroccoAntiVPN Development Team

Made for SA-MP & open.mp communities.

License 

MIT License

