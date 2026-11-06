
#if defined _MOROCCO_ANTIVPN_INCLUDED
    #endinput
#endif
#define _MOROCCO_ANTIVPN_INCLUDED

#include <a_samp>
#include <a_http>

#define MAV_ALLOWED_COUNTRY "MA"
#define MAV_KICK_DELAY 1500

new bool:MAV_CheckingIP[MAX_PLAYERS];

forward MAV_OnIPCheck(playerid, response_code, data[]);
forward MAV_KickPlayer(playerid);

stock MAV_Init()
{
    print("[MAV] Morocco Anti VPN initialized.");
    return 1;
}

stock MAV_CheckPlayer(playerid)
{
    if (!IsPlayerConnected(playerid))
        return 0;

    new ip[16], url[256];

    GetPlayerIp(playerid, ip, sizeof(ip));

    if (!strcmp(ip, "127.0.0.1"))
        return 1;

    MAV_CheckingIP[playerid] = true;

    format(url, sizeof(url),
        "http://ip-api.com/json/%s?fields=status,countryCode",
        ip
    );

    HTTP(playerid, HTTP_GET, url, "", "MAV_OnIPCheck");
    return 1;
}

public MAV_OnIPCheck(playerid, response_code, data[])
{
    if (!IsPlayerConnected(playerid))
        return 1;

    if (!MAV_CheckingIP[playerid])
        return 1;

    MAV_CheckingIP[playerid] = false;

    if (response_code != 200 ||
        strfind(data, "\"status\":\"success\"", true) == -1)
    {
        SetTimerEx("MAV_KickPlayer", MAV_KICK_DELAY, false, "i", playerid);
        return 1;
    }

    if (strfind(data, "\"countryCode\":\"MA\"", true) == -1)
    {
        SendClientMessage(playerid, 0xFF0000FF,
            "[ANTI VPN] Only Moroccan IPs are allowed.");

        SetTimerEx("MAV_KickPlayer", MAV_KICK_DELAY, false, "i", playerid);
        return 1;
    }

    SendClientMessage(playerid, 0x00FF00FF,
        "[ANTI VPN] Moroccan IP verified.");

    return 1;
}

public MAV_KickPlayer(playerid)
{
    if (IsPlayerConnected(playerid))
        Kick(playerid);

    return 1;
}

stock MAV_ResetPlayer(playerid)
{
    MAV_CheckingIP[playerid] = false;
    return 1;
}
