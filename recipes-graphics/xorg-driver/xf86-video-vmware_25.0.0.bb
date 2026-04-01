require xorg-driver-video.inc

SUMMARY = "Xlibre X11 server -- VMware SVGA display driver"

DESCRIPTION = "vmware is an Xorg driver for VMware virtual video cards."

LIC_FILES_CHKSUM = "file://COPYING;md5=5fcd7d437a959a15fbee8707747c6b53"

DEPENDS += "virtual/libx11 xorgproto libpciaccess"
XORG_DRIVER_COMPRESSOR = ".tar.xz"

SRCREV = "3580a57072304cecdf256733acfba1dc11cd366d"

COMPATIBLE_HOST = '(i.86.*-linux|x86_64.*-linux)'
