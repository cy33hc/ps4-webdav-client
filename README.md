# PS4 WebDAV Client

Simple WebDAV client for the PS4. Allows you to transfer files between the PS4 and a local WebDAV server or Cloud Storage that supports WebDAV.

Tested with following:
 - **(Recommeded)** [Dufs](https://github.com/sigoden/dufs) - For hosting your own WebDAV server. (Recommended since this allow anonymous access which is required for Remote Package Install)
 - [SFTPgo](https://github.com/drakkan/sftpgo) - For local hosted WebDAV server. Can also be used as a webdav frontend for Cloud Storage like AWS S3, Azure Blob or Google Storage.
 - box.com (Note: delete folder does not work. This is an issue with box.com and not the app)
 - mega.nz (via the megacmd tool)
 - 4shared.com
 - drivehq.com

## Remote Package Installer Feature
Remote Package Installation only works if the WebDAV server allow anonymous access. It's a limitation of the PS4 Installer not able to access protected links.

![Preview](/screenshot.jpg)

## Installation
Copy the **ps4_webdav_client.pkg** in to a FAT32 format usb drive then install from package installer

## Controls
```
Triangle - Menu (after a file(s)/folder(s) is selected)
Cross - Select Button/TextBox
Circle - Un-Select the file list to navigate to other widgets
Square - Mark file(s)/folder(s) for Delete/Rename/Upload/Download
R1 - Navigate to the Remote list of files
L1 - Navigate to the Local list of files
TouchPad Button - Exit Application
```

**HELP - Need new translations for the added strings. Please help update the languages files. Use the [English.ini](https://github.com/cy33hc/ps4-webdav-client/blob/master/data/assets/langs/English.ini) for reference**

**No need for "Remote Package Installer" homebrew and "Remote Package Sender" from PC.**

Example: If you share the folder C:\MyShare for SMB, then also make sure the C:\MyShare is the root folder for the HTTP Server.

**HTTP Servers known to work with RPI.**

[Leefull's exploit host](https://github.com/Leeful/leeful.github.io/blob/master/Exploit%20Host%20Server%20v1.2.exe) Place the "Exploit Host Server v1.2.exe" into the SMB share folder and execute.

Microsoft IIS

[npx serve](https://www.npmjs.com/package/serve)

## Multi Language Support
The appplication support following languages

The following languages are auto detected.
```
Dutch
English
French
German
Italiano
Japanese
Korean
Polish
Portuguese_BR
Russian
Spanish
Simplified Chinese
Traditional Chinese
```

The following aren't standard languages supported by the PS4, therefore requires a config file update.
```
Catalan
Croatian
Euskera
Galego
Greek
Hungarian
Indonesian
Ryukyuan
Thai
```
User must modify the file **/data/ps4-webdav-client/config.ini** located in the ps4 hard drive and update the **language** setting to with the **exact** values from the list above.

**HELP:** There are no language translations for the following languages, therefore not support yet. Please help expand the list by submitting translation for the following languages. If you would like to help, please download this [Template](https://github.com/cy33hc/ps4-webdav-client/blob/master/data/assets/langs/English.ini), make your changes and submit an issue with the file attached.
```
Finnish
Swedish
Danish
Norwegian
Turkish
Arabic
Czech
Romanian
Vietnamese
```
or any other language that you have a traslation for.

## Building
Before build the app, you need to build the dependencies first.
Clone the following Git repos and build them in order

Download the PS4SDK Toolchain
```
1. Download the pacbrew-pacman from following location and install.
   https://github.com/PacBrew/pacbrew-pacman/releases
2. Run following cmds
   pacbrew-pacman -Sy
   pacbrew-pacman -S ps4-openorbis ps4-openorbis-portlibs
   chmod guo+x /opt/pacbrew/ps4/openorbis/ps4vars.sh
```

Build and install openssl
openssl - https://github.com/cy33hc/ps4-openssl/blob/OpenSSL_1_1_1-ps4/README_PS4.md

Build libcurl
```
1. download libcurl https://curl.haxx.se/download/curl-7.80.0.tar.xz and extract to a folder
2. source /opt/pacbrew/ps4/openorbis/ps4vars.sh
3. autoreconf -fi
4. CFLAGS="${CFLAGS} -DSOL_IP=0" LIBS="${LIBS} -lSceNet" \
  ./configure --prefix="${OPENORBIS}/usr" --host=x86_64 \
    --disable-shared --enable-static \
    --with-openssl --disable-manual
5. sed -i 's|#include <osreldate.h>|//#include <osreldate.h>|g' include/curl/curl.h
6. make -C lib install
```

Build libjbc
libjbc - https://github.com/cy33hc/ps4-libjbc/blob/master/README_PS4.md

Finally build the app
```
   source /opt/pacbrew/ps4/openorbis/ps4vars.sh
   mkdir build; cd build
   openorbis-cmake ..
   make
```

## Credits
The color theme was borrowed from NX-Shell on the switch.
