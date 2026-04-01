# Force the RDEPENDS relationship in this packagegroup to call
# for our preferred server- which is differing from the one
# that Yocto has for it all..
XSERVER:remove = " xserver-xorg"
XSERVER += "xlibre-server"