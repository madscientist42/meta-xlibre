require xorg-driver-video.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=a1f0610ebdc6f314a9fa5102a8c5c1b0"

SUMMARY = "XLibre server -- Generic Vesa video driver"

DESCRIPTION = "vesa is an Xorg driver for generic VESA video cards. It \
can drive most VESA-compatible video cards, but only makes use of the \
basic standard VESA core that is common to these cards. The driver \
supports depths 8, 15 16 and 24."

DEPENDS += "virtual/libx11 xorgproto libpciaccess"

COMPATIBLE_HOST = '(i.86|x86_64).*-linux'

# FIXME - For now, we're straightening out some of the 'xserver-xorg' stuff
#         by proper misdirection in packaging in the XLibre recipe.
#         Ultimately, we're going to rip much of that out in the layer
#         and properly BBAPPEND things in place in the layer.  But...to
#         get this up and running as an Alpha...
RRECOMMENDS:${PN} += "xserver-xorg-module-libint10"

SRCREV = "850ec6dc643bf18d9011770b5b6fef7edfb927ce"


