# 🇲🇦 MoroccoAntiVPN

> A lightweight, fast, and standalone Pawn include to restrict **SA-MP** and **open.mp** server access exclusively to Moroccan IP addresses.

![Platform](https://img.shields.io/badge/Platform-SA--MP%20%7C%20open.mp-blue)
![Language](https://img.shields.io/badge/Language-Pawn-orange)
![License](https://img.shields.io/badge/License-MIT-green)
![GeoIP](https://img.shields.io/badge/GeoIP-ip--api.com-informational)

---

## 📌 Overview

**MoroccoAntiVPN** is designed for server owners who want to enforce strict country-based access control. It automatically verifies incoming player IP addresses via HTTP lookup and allows access **only** to connections originating from **Morocco (`MA`)**, keeping foreign traffic off your server.

---

## ✨ Features

* 🚀 **Strict Country Restriction:** Only permits connections from Morocco.
* ⚡ **Automatic Actions:** Automatically kicks non-Moroccan IP addresses with a customizable delay.
* 🌐 **HTTP GeoIP Verification:** Powered by `ip-api.com` for fast and reliable IP country lookups.
* 💻 **Localhost Exemption:** Automatically bypasses verification for local testing (`127.0.0.1`).
* 📦 **Lightweight & Standalone:** Zero heavy dependencies, clean drop-in integration.
* 🔄 **SA-MP & open.mp Compatible:** Works seamlessly with both server engines.

---

## 📥 Installation

1. **Download:** Get `MoroccoAntiVPN.inc` from this repository.
2. **Place in Includes:** Move the file into your Pawn include folder:
   ```text
   pawno/include/MoroccoAntiVPN.inc
   ```
3. **Include in Gamemode:** Add the following line at the top of your gamemode script:
   ```pawn
   #include <MoroccoAntiVPN>
   ```

---

## ⚙️ Configuration

You can easily override default settings by defining these constants **before** including `MoroccoAntiVPN.inc`:

| Definition | Description | Default Value |
| :--- | :--- | :--- |
| `MAV_ALLOWED_COUNTRY` | Allowed ISO country code | `"MA"` |
| `MAV_KICK_DELAY` | Delay before kicking blocked players (in milliseconds) | `1500` |

---

## 🛠️ Integration

Add the required hooks directly inside your existing gamemode callbacks:

```pawn
public OnGameModeInit()
{
    MAV_Init();
    return 1;
}

public OnPlayerConnect(playerid)
{
    MAV_CheckPlayer(playerid);
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    MAV_ResetPlayer(playerid);
    return 1;
}
```

> ⚠️ **Important:** Insert these functions inside your **existing** callbacks. Do not create duplicate callbacks in your script.

---

## 📋 Requirements

* **Server Engine:** SA-MP 0.3.7 or open.mp
* **Compiler:** Standard Pawn compiler
* **Network:** Active internet connection (required for `ip-api.com` lookup requests)

---

## ⚠️ Limitations

* **Country-Level Filtering Only:** This release restricts access based on the country code (`MA`). Advanced detection for commercial VPNs, proxies, and hosting server ranges is not included in this build.
* **GeoIP Dependence:** Lookup accuracy relies on external GeoIP database entries.

---

## 📄 License & Credits

* **Developer:** Developed for the SA-MP & open.mp community.
* **License:** Distributed under the [MIT License](LICENSE).

---

<p align="center">
  <b>MoroccoAntiVPN</b> — Secure your server. Control your connections. 🇲🇦
</p>