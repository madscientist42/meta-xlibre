SUMMARY = "XLibre X Server - Fork of X.Org Server with enhancements"
DESCRIPTION = "XLibre is a maintained fork of the X.Org X server for continued X11 support."
HOMEPAGE = "https://github.com/X11Libre/xserver"
LICENSE = "MIT & BSD-3-Clause"

DEPENDS = "pixman libdrm libxfont2 xkbcomp xkeyboard-config xorgproto libpciaccess libxcvt util-macros font-util libepoxy"
DEPENDS += "${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'mesa', '', d)}"

inherit meson pkgconfig features_check

REQUIRED_DISTRO_FEATURES = "x11"

SRC_URI = "git://github.com/X11Libre/xserver.git;protocol=https;branch=${XLIBRE_BRANCH}"
S = "${WORKDIR}/git"

PACKAGECONFIG ??= "xdmcp xdm-auth-1 glx dri3 ipv6 xcsecurity"
PACKAGECONFIG[xdmcp] = "-Dxdmcp=true, -Dxdmcp=false, libxdmcp"
PACKAGECONFIG[xdm-auth-1] = "-Dxdm-auth-1=true, -Dxdm-auth-1=false"
PACKAGECONFIG[glx] = "-Dglx=true, -Dglx=false"
PACKAGECONFIG[dri3] = "-Ddri3=true, -Ddri3=false"
PACKAGECONFIG[ipv6] = "-Dipv6=true, -Dipv6=false"
PACKAGECONFIG[xcsecurity] = "-Dxcsecurity=true, -Dxcsecurity=false, libgcrypt"
PACKAGECONFIG[libunwind] = "-Dlibunwind=true, -Dlibunwind=false, libunwind"
PACKAGECONFIG[xselinux] = "-Dxselinux=true, -Dxselinux=false, libselinux"
PACKAGECONFIG[xvfb] = "-Dxvfb=true, -Dxvfb=false"
PACKAGECONFIG[xnest] = "-Dxnest=true, -Dxnest=false"
# Add more for XLibre-specific options if needed, e.g., -Dxnamespace=true

# We provide an instance of the X11 server...
PROVIDES = "virtual/xserver virtual/xserver-xf86"

# Explicitly axe XOrg from being involved if we are...
REPLACED = "xserver-xorg"
REPLACES:${PN} = "${REPLACED}"
RCONFLICTS:${PN} = "${REPLACED}"
RREPLACES:${PN} = "${REPLACED}"

# Sub out some of the silliness that Yocto did with the packaging
# for this to make it fit in tighter spaces...
PACKAGES =+ "${REPLACED}-sdl \
             ${REPLACED}-fbdev \
             ${REPLACED}-xvfb \
             ${REPLACED}-utils \
             ${REPLACED}-xephyr \
             ${REPLACED}-xwayland \
             ${REPLACED}-multimedia-modules \
             ${REPLACED}-extension-dri \
             ${REPLACED}-extension-dri2 \
             ${REPLACED}-extension-glx \
             ${REPLACED}-extension-record \
             ${REPLACED}-extension-extmod \
             ${REPLACED}-extension-dbe \
             ${REPLACED}-module-libint10 \
             ${REPLACED}-module-libafb \
             ${REPLACED}-module-libwfb  \
             ${REPLACED}-module-libmfb \
             ${REPLACED}-module-libcfb \
             ${REPLACED}-module-exa \
             ${REPLACED}-module-xaa \
             ${REPLACED}-module-libxf1bpp \
             ${REPLACED}-module-libxf4bpp \
             xf86-video-modesetting"

SUMMARY:xf86-video-modesetting = "X.Org X server -- modesetting display driver"

require xserver-abi.inc

python add_xorg_abi_depends() {
    _add_xorg_abi_depends(d, "videodrv", d.expand("${MLPREFIX}xf86-video-modesetting"))
}

PACKAGEFUNCS =+ "add_xorg_abi_provides add_xorg_abi_depends"

XSERVER_RDEPENDS = "xkeyboard-config rgb xserver-xf86-config xkbcomp xf86-input-libinput"
RDEPENDS:${PN} += "${XSERVER_RDEPENDS}"
RDEPENDS:${REPLACED}-xvfb += "xkeyboard-config"
RDEPENDS:${PN}-module-exa = "${PN} (= ${EXTENDPKGV})"

FILES:${PN} = "${bindir} ${libdir}/X11/Options ${libdir}/X11/Cards ${libdir}/X11/getconfig ${libdir}/X11/etc ${libdir}/xorg/modules/xlibre-25/input/*.so ${libdir}/xorg/modules/xlibre-25/*.so /etc/X11 ${libdir}/xorg/protocol.txt ${datadir}/X11/xorg.conf.d"
FILES:${REPLACED}-dev += "${libdir}/xorg/modules/xlibre-25/*.la ${libdir}/xorg/modules/xlibre-25/*/*.la"
FILES:${REPLACED}-doc += "${libdir}/X11/doc ${datadir}/X11/xkb/compiled/README.compiled ${localstatedir}/lib/xkb/README.compiled"
FILES:${REPLACED}-sdl = "${bindir}/Xsdl"
FILES:${REPLACED}-fbdev = "${bindir}/Xfbdev"
FILES:${REPLACED}-xvfb = "${bindir}/Xvfb"
FILES:${REPLACED}-utils = "${bindir}/scanpci ${bindir}/pcitweak ${bindir}/ioport ${bindir}/in[bwl] ${bindir}/out[bwl] ${bindir}/mmap[rw] ${bindir}/gtf ${bindir}/getconfig ${bindir}/getconfig.pl"
FILES:${REPLACED}-xephyr = "${bindir}/Xephyr"
FILES:${REPLACED}-multimedia-modules = "${libdir}/xorg/modules/xlibre-25/multimedia/*drv*"
FILES:${REPLACED}-extension-dri = "${libdir}/xorg/modules/xlibre-25/extensions/libdri.so"
FILES:${REPLACED}-extension-dri2 = "${libdir}/xorg/modules/xlibre-25/extensions/libdri2.so"
FILES:${REPLACED}-extension-glx = "${libdir}/xorg/modules/xlibre-25/extensions/libglx.so"
FILES:${REPLACED}-extension-record = "${libdir}/xorg/modules/xlibre-25/extensions/librecord.so"
FILES:${REPLACED}-extension-extmod = "${libdir}/xorg/modules/xlibre-25/extensions/libextmod.so"
FILES:${REPLACED}-extension-dbe = "${libdir}/xorg/modules/xlibre-25/extensions/libdbe.so"
FILES:${REPLACED}-module-libint10 = "${libdir}/xorg/modules/xlibre-25/libint10.so"
FILES:${REPLACED}-module-libafb = "${libdir}/xorg/modules/xlibre-25/libafb.so"
FILES:${REPLACED}-module-libwfb = "${libdir}/xorg/modules/xlibre-25/libwfb.so"
FILES:${REPLACED}-module-libmfb = "${libdir}/xorg/modules/xlibre-25/libmfb.so"
FILES:${REPLACED}-module-libcfb = "${libdir}/xorg/modules/xlibre-25/libcfb.so"
FILES:${REPLACED}-module-exa = "${libdir}/xorg/modules/xlibre-25/libexa.so"
FILES:${REPLACED}-module-xaa = "${libdir}/xorg/modules/xlibre-25/libxaa.so"
FILES:${REPLACED}-module-libxf1bpp = "${libdir}/xorg/modules/xlibre-25/libxf1bpp.so"
FILES:${REPLACED}-module-libxf4bpp = "${libdir}/xorg/modules/xlibre-25/libxf4bpp.so"
FILES:xf86-video-modesetting = "${libdir}/xorg/modules/xlibre-25/drivers/modesetting_drv.so"

# Temp hacks.  Need to fix this so we have a layer and handle
# call-outs for RPi, etc right- but for a smoke test, this
# will do well enough.
PENGL_PKGCONFIGS:rpi = "dri glx ${@bb.utils.contains('MACHINE_FEATURES', 'vc4graphics', 'dri3 glamor', '', d)}"

# when using userland graphic KHR/khrplatform.h is provided by userland but virtual/libgl is provided by mesa-gl where
# we explicitly delete KHR/khrplatform.h since its already coming from userland package
DEPENDS:append:rpi = " ${@bb.utils.contains('MACHINE_FEATURES', 'vc4graphics', '', 'userland', d)}"
