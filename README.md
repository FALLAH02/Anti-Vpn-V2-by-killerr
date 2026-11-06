MoroccoAntiVPN 

Morocco Only Protection for SA-MP & open.mp 
A lightweight Pawn include for Moroccan IP verification. 

![Pawn](https://img.shields.io/badge/Language-Pawn-blue) ![Platform](https://img.shields.io/badge/Platform-SA--MP%20%7C%20open.mp-green) ![Version](https://img.shields.io/badge/Version-1.0.0-purple) ![License](https://img.shields.io/badge/License-MIT-orange) 

Overview 

MoroccoAntiVPN is a lightweight Pawn include designed to restrict server access to Moroccan IP addresses.

It uses GeoIP verification to identify the player's country and automatically blocks connections from outside Morocco.

Features Morocco-only IP access (MA). Automatic country verification. Automatic player kick. HTTP-based GeoIP lookup. Localhost exemption. Easy integration. Standalone .inc include. Installation 

1. Download

Download MoroccoAntiVPN.inc and place it inside:

pawno/include/ 

2. Include

Add this to your gamemode:

#include <MoroccoAntiVPN> Usage 

Initialize

public OnGameModeInit() { MAV_Init(); return 1; } 

Player Connect

public OnPlayerConnect(playerid) { MAV_CheckPlayer(playerid); return 1; } 

Player Disconnect

public OnPlayerDisconnect(playerid, reason) { MAV_ResetPlayer(playerid); return 1; } 

Add these calls to your existing callbacks rather than creating duplicate callbacks.

Configuration 

Default country:

#define MAV_ALLOWED_COUNTRY "MA" 

Kick delay:

#define MAV_KICK_DELAY 1500 Requirements SA-MP 0.3.7 or open.mp. Pawn compiler. Internet connection. ip-api.com GeoIP service. Important 

This release verifies country location only. VPN, Proxy and Hosting detection are not implemented yet.

GeoIP verification does not guarantee that an IP is not using a VPN.

Credits 

Developed for SA-MP and open.mp communities.

MoroccoAntiVPN Development Team

License 

This project is licensed under the MIT License.

