DESCRIPTION = "picom lightweight X11 compositor"
LICENSE = "MIT & MPL-2.0"
LIC_FILES_CHKSUM = " \
    file://LICENSES/MIT;md5=6a01e8ccc65bea4e8bfa79b09ea1444c \
    file://LICENSES/MPL-2.0;md5=815ca599c9df247a0c7f619bab123dad \
    "

inherit meson pkgconfig

DEPENDENCY_LIST = " \
    libx11 \
    libxcb \
    libconfig \
    libpcre2 \
    libev \
    xcb-util-image \
    xcb-util-renderutil \
    "

DEPENDS = " \
    ${DEPENDENCY_LIST} \
    pixman \
    uthash \
    "

RDEPENDS:${PN} = " \
    ${DEPENDENCY_LIST} \
    "

SRC_URI = " \
    git://github.com/yshui/picom.git;protocol=https;branch=next \
    "

SRCREV = "e5bbe6702375af762fe290db51b050ccf5a53fda"
S = "${WORKDIR}/git"


# Tune the build.  FIXME : Need to turn off a few things and PKGCONFIG them in later.
EXTRA_OEMESON += " \
    -Ddbus=false \
    -Dopengl=false \
    "

FILES:${PN} += " \
    /usr/share \
    "