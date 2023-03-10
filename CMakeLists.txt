cmake_minimum_required(VERSION 3.0)

project(ps4_webdav_client)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDONT_HAVE_STRUPR")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

include_directories(
  source
  source/webdav
  source/pugixml
)

add_executable(ps4_webdav_client
  source/pugixml/pugixml.cpp
  source/webdav/callback.cpp
  source/webdav/client.cpp
  source/webdav/fsinfo.cpp
  source/webdav/header.cpp
  source/webdav/request.cpp
  source/webdav/urn.cpp
  source/actions.cpp
  source/config.cpp
  source/fs.cpp
  source/gui.cpp
  source/getentropy.c
  source/ime_dialog.cpp
  source/inifile.c
  source/installer.cpp
  source/lang.cpp
  source/main.cpp
  source/orbis_jbc.c
  source/rtc.cpp
  source/windows.cpp
  source/webdavclient.cpp
  source/imgui_draw.cpp
  source/imgui_impl_sdl.cpp
  source/imgui_impl_sdlrenderer.cpp
  source/imgui_tables.cpp
  source/imgui_widgets.cpp
  source/imgui.cpp
)

add_self(ps4_webdav_client)

add_pkg(ps4_webdav_client ${CMAKE_SOURCE_DIR}/data "WDVC00001" "PS4 WebDAV Client" "01.04" 32 0)

target_link_libraries(ps4_webdav_client
  c
  c++
  png
  z
  pthread
  SDL2
  samplerate
  jbc
  crypto
  ssl
  curl
  lexbor
  kernel
  SceShellCoreUtil
  SceSysmodule
  SceSystemService
  ScePigletv2VSH
  ScePrecompiledShaders
  SceRtc
  SceUserService
  ScePad
  SceAudioOut
  SceSysUtil
  SceImeDialog
  SceNet
  SceBgft
  SceAppInstUtil
)
