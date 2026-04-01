require xorg-driver-video.inc

SUMMARY = "X.Org X server -- cirrus display driver"
DESCRIPTION = "cirrus is an Xorg driver for Cirrus Logic VGA adapters. These \
devices are not so common in the wild anymore, but QEMU can emulate one, so \
the driver is still useful."

LIC_FILES_CHKSUM = "file://COPYING;md5=6ddc7ca860dc5fd014e7f160ea699295"

SRCREV = "6d684a65b8efaf719c5d62483cb8d9f8dee4879a"

DEPENDS += "libpciaccess"

