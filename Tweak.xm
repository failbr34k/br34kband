#import <Foundation/Foundation.h>
#import <Security/Security.h>
#import <CoreFoundation/CoreFoundation.h>
#import "mobileactivationd.h"
#import "substrate.h"


%hook MALog
- (void)logMessage:(id)v1 toSyslog:(bool)v2 { %log; %orig(v1,YES); }
%end


%hook DeviceType

- (NSString * )product_type { %log; NSString *  r = @"iPad2,1"; NSLog(@"product_type = %@", r); return r; }
- (NSString * )device_class { %log; NSString *  r = @"iPad"; NSLog(@"device_class = %@", r); return r; }
- (NSString * )hardware_model { %log; NSString *  r = %orig; NSLog(@"hardware_model = %@", r); return r; }

- (bool )device_supports_dcrt_oob { %log; bool  r = YES; NSLog(@" = %d", r); return r; }
- (bool )is_ipod { %log; bool  r = %orig; NSLog(@" = %d", r); return r; }
- (bool )is_ipad { %log; bool  r = YES; NSLog(@" = %d", r); return r; }
- (bool )has_telephony { %log; bool  r = NO; NSLog(@"has_telephony = %d", r); return r; }

%end
