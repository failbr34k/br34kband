# =========================================================================
#     SecDump for iOS 10.x - 14.x (Configure for your theos/SDK config)
#       Created by 80HD, BlueDog, Failbr34k, V4sk3, xrdis, ixhub
#
# 	File Description:
#	Makefile for SecDump iOS Security framework transaction Logger
# =========================================================================

# For iOS 10.x or lower, uncomment this target and comment the others
#TARGET := iPhone:clang:10.2:9.3
#ARCHS = arm64 arm64e armv7 armv7s
#VALID_ARCHS = arm64 arm64e armv7 armv7s
#SDKVERSION = 10.2


#iOS 11.x and 12.x
#TARGET := iphone:clang:12.4:11.0
#SDKVERSION = 12.4


#iOS 13.x and 14.x 
TARGET := iPhone:clang:12.4:10.2
SDKVERSION = 12.4

ARCHS = arm64 arm64e
VALID_ARCHS = arm64 arm64e

INSTALL_TARGET_PROCESSES = CommCenter mobileactivationd lockdownd akd coreauthd mc_mobile_tunnel mdmd teslad setoken



#SYSROOT = $THEOS/sdks/iPhoneOS12.4.sdk
DEBUG=0
GO_EASY_ON_ME = 1
TWEAK_NAME = br34kband

THEOS_DEVICE_IP = 10.0.0.8
THEOS_DEVICE_PORT = 22

UDIDit_LIBRARIES = MobileGestalt
UDIDit_PRIVATEFRAMEWORKS = MobileActivation
UDIDit_FRAMEWORKS = Security
UDIDit_CODESIGN_FLAGS = -Sentitlements.xml
UDIDit_FILES = Tweak.xm
UDIDit_CFLAGS += -fobjc-arc -Wno-deprecated-declarations $(IMPORTS) -DTHEOS -Wno-incompatible-pointer-types -Wno-format -Wno-protocol
#UDIDit_LDFLAGS = -lz -L. -v -force_load ./libcapstone.5.dylib
include ~/theos/makefiles/common.mk
include ~/theos/makefiles/tweak.mk
include ~/theos/makefiles/aggregate.mk
include ~/theos/makefiles/framework.mk
#include ~/theos/makefiles/library.mk
after-install::
	install.exec "killall -9 mobileactivationd CommCenter lockdownd"
