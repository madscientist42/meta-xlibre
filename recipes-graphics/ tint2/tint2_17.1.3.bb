SUMMARY = "Lightweight panel and taskbar for Openbox"
HOMEPAGE = "https://gitlab.com/nick87720z/tint2"
LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM = "file://COPYING;md5=94d55d512a9ba36caa9b7df079bae19f"

inherit cmake pkgconfig features_check

REQUIRED_DISTRO_FEATURES = "x11"

DEPENDENCY_LIST = " \
    glib-2.0 \
    gtk+3 \
    cairo \
    pango \
    libx11 \
    libxcb \
    xcb-util-image \
    xcb-util-renderutil \
    libxinerama \
    imlib2 \
    librsvg \
    startup-notification \
    "

DEPENDS = "${DEPENDENCY_LIST}"
RDEPENDS:${PR} = "${DEPENDENCY_LIST}"

SRC_URI = " \
    git://gitlab.com/nick87720z/tint2.git;protocol=https;branch=master \
    "

SRCREV = "57e96cee7c98c0f272befd34fd959964052e51c4"
S = "${WORKDIR}/git"

EXTRA_OECMAKE = "-DCMAKE_BUILD_TYPE=Release -DENABLE_WNCK=OFF"

do_install:append() {
    install -d ${D}${sysconfdir}/xdg/tint2
}

FILES:${PN} += "/usr/share"