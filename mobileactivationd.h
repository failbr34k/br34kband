#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>
#import <Security/Security.h>



struct anonymous_type_2 {
    void * field_1;
    char * field_2;
    char * field_3;
    long long field_4;
    unsigned int field_5;
    int field_6;
    int field_7;
    int field_8;
    int field_9;
};

struct NACContextOpaque_ {
};

struct anonymous_type_3 {
    void * field_1;
    char * field_2;
    char * field_3;
    long long field_4;
    unsigned int field_5;
    int field_6;
    int field_7;
    int field_8;
    int field_9;
};




struct PSCSessionInternal_ {
};







/*****************************************************************/


/*****************************************************************/

@protocol MobileActivationProtocol<NSObject>
- (void)getActivationStateWithCompletionBlock:(id)v1;
- (void)copyRTCResetCountWithCompletionBlock:(id)v1;
- (void)copyMonotonicClockWithCompletionBlock:(id)v1;
- (void)createTunnel1ActivationInfo:(id)v1 options:(id)v2 withCompletionBlock:(id)v3;
- (void)createTunnel1SessionInfoWithCompletionBlock:(id)v1;
- (void)createActivationInfoWithCompletionBlock:(id)v1;
- (void)handleActivationInfo:(id)v1 withCompletionBlock:(id)v2;
- (void)copyUCRTWithCompletionBlock:(id)v1;
- (void)copyPCRTTokenWithCompletionBlock:(id)v1;
- (void)isDeviceBrickedWithCompletionBlock:(id)v1;
- (void)deactivateDeviceWithCompletionBlock:(id)v1;
- (void)requestDeviceReactivationWithCompletionBlock:(id)v1;
- (void)getActivationBuildWithCompletionBlock:(id)v1;
- (void)copyActivationRecordWithCompletionBlock:(id)v1;
- (void)unbrickDeviceWithCompletionBlock:(id)v1;
- (void)recertifyDeviceWithCompletionBlock:(id)v1;
- (void)handleActivationInfoWithSession:(id)v1 activationSignature:(id)v2 completionBlock:(id)v3;
- (void)issueClientCertificateLegacy:(id)v1 WithCompletionBlock:(id)v2;
- (void)issueClientCertificateWithReferenceKey:(id)v1 options:(id)v2 completion:(id)v3;
- (void)isInFieldCollectedWithCompletionBlock:(id)v1;
- (void)updateBasebandTicket:(SecKeyRef)v1 baaCertData:(SecCertificateRef)v2 baaIntermediateCert:(SecCertificateRef)v3 options:(id)v4 withCompletionBlock:(id)v5;
//- (void)updateBasebandTicket:(SecKeyRef)v1 baaCertData:(SecCertificateRef)v2 options:(id)v3 withCompletionBlock:(id)v4;
- (void)getDCRTStateWithCompletionBlock:(id)v1;
- (void)copyDCRTWithCompletionBlock:(id)v1;
- (void)issueDCRT:(id)v1 withCompletionBlock:(id)v2;
@end


/*****************************************************************/



/*****************************************************************/

@interface NSDictionary (MobileActivation)
- (id)objectForCaseInsensitiveKey:(id)v1;
@end


/*****************************************************************/

@interface NSDateFormatter (MobileActivation)
- (id)dateFromServerString:(id)v1 withError:(id *)v2;
@end


/*****************************************************************/

@interface NSData (MobileActivation)
- (id)hexString;
@end


/*****************************************************************/

@interface MALog : NSObject {
    struct anonymous_type_2 * _logHandle;
    NSObject<OS_dispatch_queue> * _queue;
}
@property (nonatomic) struct anonymous_type_3 * logHandle;
@property (retain,nonatomic) NSObject<OS_dispatch_queue> * queue;
+ (id)getSharedInstance;
- (id)init;
- (void)deleteExpiredLogFiles;
- (void)logMessage:(id)v1 toSyslog:(bool)v2;
@end


/*****************************************************************/

@interface DataArk : NSObject {
    NSMutableDictionary * _store;
    NSMutableDictionary * _set_notifications;
    NSMutableDictionary * _change_notifications;
    NSMutableDictionary * _remove_notifications;
    NSString * _path;
}
@property (retain) NSMutableDictionary * store;
@property (retain) NSMutableDictionary * set_notifications;
@property (retain) NSMutableDictionary * change_notifications;
@property (retain) NSMutableDictionary * remove_notifications;
@property (retain) NSString * path;
- (id)initWithPath:(id)v1;
- (id)init;
- (void)postNotification:(id)v1;
@end


/*****************************************************************/

@interface MACollectionInterface : NSObject {
    bool _collectionLibraryLoaded;
    SecKeyRef _signingKey;
    DataArk * _dark;
}
@property (readonly) SecKeyRef signingKey;
@property (nonatomic) bool collectionLibraryLoaded;
@property (readonly,nonatomic) DataArk * dark;
+ (id)copyIngestURL;
- (id)initWithContext:(id)v1;
- (id)collectSigningAttestation:(id *)v1;
- (id)collectSIK:(id *)v1;
- (id)collectPCRT:(id *)v1;
- (id)signingKeyPublicKeyWithError:(id *)v1;
- (id)signatureForData:(id)v1 error:(id *)v2;
- (id)copyIngestHeaders:(id)v1 withError:(id *)v2;
- (id)copyIngestData:(id *)v1;
- (bool)processSUInfo:(id)v1 withError:(id *)v2;
@end


/*****************************************************************/

@interface GestaltHlpr : NSObject
+ (id)getSharedInstance;
- (id)copyAnswer:(CFStringRef)v1;
- (bool)getBoolAnswer:(CFStringRef)v1;
- (void)addAGestaltKey:(CFStringRef)v1 toDictionary:(id)v2 required:(bool)v3 errors:(id)v4;
- (id)copyDeviceIDInfo:(id *)v1;
- (id)copyDeviceInfo:(id *)v1;
- (id)copyRegulatoryImagesInfo:(id *)v1;
- (void)updateRecertInfo:(id)v1 errors:(id *)v2;
@end


/*****************************************************************/

@interface DeviceType : NSObject {
    bool _device_supports_dcrt_oob;
    bool _is_prodfused_demoted;
    bool _is_devfused_undemoted;
    bool _is_dev_board;
    bool _is_fpga;
    bool _is_ipod;
    bool _is_ipad;
    bool _is_audio_accessory;
    bool _has_telephony;
    bool _should_hactivate;
    bool _is_internal_build;
    bool _has_internal_diagnostics;
    NSString * _product_type;
    NSString * _device_class;
    NSString * _hardware_model;
}
@property (readonly,copy,nonatomic) NSString * product_type;
@property (readonly,copy,nonatomic) NSString * device_class;
@property (readonly,copy,nonatomic) NSString * hardware_model;
@property (readonly,nonatomic) bool device_supports_dcrt_oob;
@property (readonly,nonatomic) bool is_prodfused_demoted;
@property (readonly,nonatomic) bool is_devfused_undemoted;
@property (readonly,nonatomic) bool is_dev_board;
@property (readonly,nonatomic) bool is_fpga;
@property (readonly,nonatomic) bool is_ipod;
@property (readonly,nonatomic) bool is_ipad;
@property (readonly,nonatomic) bool is_audio_accessory;
@property (readonly,nonatomic) bool has_telephony;
@property (readonly,nonatomic) bool should_hactivate;
@property (readonly,nonatomic) bool is_internal_build;
@property (readonly,nonatomic) bool has_internal_diagnostics;
+ (id)sharedInstance;
- (id)init;
- (id)copyDeviceTreeProperty:(id)v1 key:(id)v2;
- (id)copyBootSessionUUID;
- (id)copyBootArgs;
- (id)copyDeviceTreeInt:(id)v1 key:(id)v2 defaultValue:(int)v3;
- (bool)runningInRAMDisk;
@end


/*****************************************************************/

@interface MANetworkServiceClientVersion : NSObject<NSURLSessionDataDelegate> {
    bool _allowInvalidCert;
    NSError * _lastNetworkError;
}
@property bool allowInvalidCert;
@property (retain) NSError * lastNetworkError;
@property (readonly) Class superclass;
@property (readonly,copy) NSString * description;
@property (readonly,copy) NSString * debugDescription;
- (void)URLSession:(id)v1 didReceiveChallenge:(id)v2 completionHandler:(id)v3;
@end


/*****************************************************************/

@interface MobileRecertifyEngine : NSObject {
    DataArk * _dark;
    NSObject<OS_dispatch_queue> * _queue;
}
@property (retain,nonatomic) DataArk * dark;
@property (retain,nonatomic) NSObject<OS_dispatch_queue> * queue;
- (id)initWithQueue:(id)v1 dark:(id)v2;
- (id)createRecertInfoWithDataArk:(id)v1 alcoholBlob:(struct NACContextOpaque_ *)v2 options:(id)v3 error:(id *)v4;
- (void)recertifyDevice:(id)v1;
@end


/*****************************************************************/

@interface MobileActivationDaemon : NSObject<MobileActivationProtocol> {
    NSString * _hostActivationNonce;
    NSString * _deviceActivationNonce;
    struct PSCSessionInternal_ * _session;
    NSData * _sessionHelloMessage;
    DataArk * _dark;
    NSObject<OS_dispatch_queue> * _sessionQueue;
    NSObject<OS_dispatch_queue> * _xpcQueue;
    NSObject<OS_dispatch_queue> * _creationQueue;
    NSString * _recertNonce;
}
@property (retain,nonatomic) DataArk * dark;
@property (readonly,nonatomic) struct PSCSessionInternal_ * session;
@property (readonly,nonatomic) NSData * sessionHelloMessage;
@property (readonly,nonatomic) NSObject<OS_dispatch_queue> * sessionQueue;
@property (readonly,nonatomic) NSObject<OS_dispatch_queue> * xpcQueue;
@property (readonly,nonatomic) NSObject<OS_dispatch_queue> * creationQueue;
@property (retain,nonatomic) NSString * activationNonce;
@property (retain,nonatomic) NSString * recertNonce;
@property (readonly,nonatomic) bool isHostConnection;
@property (readonly) Class superclass;
@property (readonly,copy) NSString * description;
@property (readonly,copy) NSString * debugDescription;
- (id)initWithContext:(id)v1 Queue:(id)v2;
- (void)generateSession;
- (id)callingProcessName;
- (bool)isEntitled:(id)v1;
- (id)valueForEntitlement:(id)v1;
- (bool)listener:(id)v1 shouldAcceptNewConnection:(id)v2;
- (void)_issueDCRT:(id)v1 options:(id)v2 withCompletionBlock:(id)v3;
- (void)_issueClientCertificateWithReferenceKey:(id)v1 rkData:(id)v2 options:(id)v3 completion:(id)v4;
- (bool)handleSessionResponse:(id)v1 withError:(id *)v2;
- (bool)validateActivationDataSignature:(id)v1 activationSignature:(id)v2 withError:(id *)v3;
- (void)getActivationStateWithCompletionBlock:(id)v1;
- (void)copyRTCResetCountWithCompletionBlock:(id)v1;
- (void)copyMonotonicClockWithCompletionBlock:(id)v1;
- (void)deactivateDeviceWithCompletionBlock:(id)v1;
- (void)createTunnel1ActivationInfo:(id)v1 options:(id)v2 withCompletionBlock:(id)v3;
- (void)createTunnel1SessionInfoWithCompletionBlock:(id)v1;
- (void)createActivationInfoWithCompletionBlock:(id)v1;
- (void)handleActivationInfo:(id)v1 withCompletionBlock:(id)v2;
- (void)copyUCRTWithCompletionBlock:(id)v1;
- (void)copyPCRTTokenWithCompletionBlock:(id)v1;
- (void)isDeviceBrickedWithCompletionBlock:(id)v1;
- (void)getActivationBuildWithCompletionBlock:(id)v1;
- (void)requestDeviceReactivationWithCompletionBlock:(id)v1;
- (void)copyActivationRecordWithCompletionBlock:(id)v1;
- (void)unbrickDeviceWithCompletionBlock:(id)v1;
- (void)recertifyDeviceWithCompletionBlock:(id)v1;
- (void)handleActivationInfoWithSession:(id)v1 activationSignature:(id)v2 completionBlock:(id)v3;
- (void)issueClientCertificateLegacy:(id)v1 WithCompletionBlock:(id)v2;
- (void)issueClientCertificateWithReferenceKey:(id)v1 options:(id)v2 completion:(id)v3;
- (void)isInFieldCollectedWithCompletionBlock:(id)v1;
- (void)updateBasebandTicket:(id)v1 baaCertData:(id)v2 baaIntermediateCert:(id)v3 options:(id)v4 withCompletionBlock:(id)v5;
- (void)copyDCRTWithCompletionBlock:(id)v1;
- (void)getDCRTStateWithCompletionBlock:(id)v1;
- (void)issueDCRT:(id)v1 withCompletionBlock:(id)v2;
@end
