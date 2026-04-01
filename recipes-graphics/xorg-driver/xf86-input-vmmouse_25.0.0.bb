require xorg-driver-input.inc

SUMMARY = "X.Org X server -- VMWare mouse input driver"
DESCRIPTION = "The vmmouse driver enables support for the special VMMouse \
protocol that is provided by VMware virtual machines to give absolute \
pointer positioning. The vmmouse driver is capable of falling back to the \
standard 'mouse' driver if a VMware virtual machine is not detected."

XORG_DRIVER_COMPRESSOR = ".tar.xz"

SRCREV = "3f10b044e45bfabec5b384a56ef2890fe0e7c97b"

RDEPENDS:${PN} += "xf86-input-mouse"

LIC_FILES_CHKSUM = "file://COPYING;md5=622841c068a9d7625fbfe7acffb1a8fc"

COMPATIBLE_HOST = '(i.86|x86_64).*-linux'

do_install:append () {
	# We don't care about hal
	rm -rf ${D}${datadir}/hal/
	rm -rf ${D}${libdir}/hal/
}

EXTRA_OECONF = "--with-udev-rules-dir=${nonarch_base_libdir}/udev/rules.d"

FILES:${PN} += "${datadir}/X11/xorg.conf.d"
