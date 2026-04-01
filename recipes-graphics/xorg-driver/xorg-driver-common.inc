SUMMARY = "X driver (${PN})"
HOMEPAGE = "http://www.x.org"
BUGTRACKER = "https://bugs.freedesktop.org"
SECTION = "x11/drivers"
LICENSE = "MIT"

PE = "2"

DEPENDS = "virtual/xserver xorgproto util-macros"

# Moving this to work with XLibre's GitHub repo structure...
SRC_URI = " \
    git://github.com/X11Libre/${PN}.git;protocol=https;branch=master \
    "
S = "${WORKDIR}/git"
FILES:${PN} += " ${libdir}"

inherit pkgconfig features_check
XORGBUILDCLASS ??= "autotools"
inherit_defer ${XORGBUILDCLASS}

# depends on virtual/xserver
REQUIRED_DISTRO_FEATURES = "x11"

SECURITY_LDFLAGS = "${SECURITY_X_LDFLAGS}"

require recipes-graphics/xlibre-server/xserver-abi.inc
