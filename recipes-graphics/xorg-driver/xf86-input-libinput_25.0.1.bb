require xorg-driver-input.inc

SUMMARY = "Generic input driver for the X.Org server based on libinput"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://COPYING;md5=a22925127bd3c827c384cedd23ed2309"

DEPENDS += "libinput"

SRCREV = "4eb6691efeef4969a05b1d6b77d980943fb9760e"

FILES:${PN} += "${datadir}/X11/xorg.conf.d"
