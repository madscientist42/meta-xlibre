require xorg-driver-video.inc

SUMMARY = "XLibre server -- Intel integrated graphics chipset(s) driver"

DESCRIPTION = "intel is an Xorg driver for Intel integrated graphics \
chipsets. The driver supports depths 8, 15, 16 and 24. On some chipsets, \
the driver supports hardware accelerated 3D via the Direct Rendering \
Infrastructure (DRI)."

LIC_FILES_CHKSUM = "file://COPYING;md5=8730ad58d11c7bbad9a7066d69f7808e"

SRCREV = "52c1ab55f04449ad969bed9f1f4d210dd90b2bbd"

DEPENDS += "virtual/libx11 drm libpciaccess pixman cairo libpng libxcb libxcomposite libxdamage libxrender libxrandr libxext libxfixes"

PACKAGECONFIG ??= "sna xvmc uxa udev ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'dri2 dri3', '', d)}"

PACKAGECONFIG[dri2] = "--enable-dri2,--disable-dri2"
PACKAGECONFIG[dri3] = "--enable-dri3,--disable-dri3"
PACKAGECONFIG[sna] = "--enable-sna,--disable-sna"
PACKAGECONFIG[uxa] = "--enable-uxa,--disable-uxa"
PACKAGECONFIG[udev] = "--enable-udev,--disable-udev,udev"
PACKAGECONFIG[xvmc] = "--enable-xvmc,--disable-xvmc,libxvmc xcb-util"
PACKAGECONFIG[tools] = "--enable-tools,--disable-tools,libxinerama libxcursor libxtst libxscrnsaver libxshmfence"

# --enable-kms-only option is required by ROOTLESS_X
EXTRA_OECONF += '${@oe.utils.conditional( "ROOTLESS_X", "1", " --enable-kms-only", "", d )}'

COMPATIBLE_HOST = '(i.86|x86_64).*-linux'

FILES:${PN} += "${datadir}/polkit-1"
