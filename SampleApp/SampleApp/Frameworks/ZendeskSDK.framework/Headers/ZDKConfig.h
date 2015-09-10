/*
 *
 *  ZDKConfig.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 29/10/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZDKIdentity.h"
#import "ZDKPushRegistrationProvider.h"
#import "ZDKDispatcher.h"
#import "ZendeskSDKConstants.h"


@class ZDKAppSettings, ZDKAccount, ZDKSdkStorage;

/**
 *  SDK configuration file found and SDK initialized successfully.
 *
 *  @since 1.3.0.1
 */
typedef void (^ZDKInitializeSuccess)(void);


/*
 * ZDKConfig is responsible for initialization of
 * the SDK and manages the backend configuration.
 *
 *  @since 0.9.3.1
 */
@interface ZDKConfig : NSObject


/**
 *  The ZDKAccount for the configuration.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, readonly) ZDKAccount *account;


/**
 *  The user identity for SDK.
 *
 *  @since 1.2.0.1
 */
@property (nonatomic, setter=setUserIdentity:, getter=userIdentity) id<ZDKIdentity>userIdentity;


/**
 *  An array for custom fields.
 *
 *  @see <a href="https://developer.zendesk.com/embeddables/docs/ios/providers#using-custom-fields-and-custom-forms">Custom fields and forms documentation</a>
 *
 *  @since 1.0.0.1
 */
@property (nonatomic, strong) NSArray *customTicketFields;


/**
 *  Form id for ticket creation.
 *
 *  The ticket form id will be ignored if your Zendesk doesn't support it.  Currently
 *  Enterprise and higher plans support this.
 *
 *  @see <a href="https://developer.zendesk.com/embeddables/docs/ios/providers#using-custom-fields-and-custom-forms">Custom fields and forms documentation</a>
 *
 *  @since 1.0.0.1
 */
@property (nonatomic, strong) NSNumber *ticketFormId;


/**
 *  Returns YES if authentication type is Anonymous and NO if it authentication is JWT.
 *
 *  @since 1.1.0.1
 */
@property (readonly) BOOL isAnonymousAuth __deprecated_msg("Deprecated as of 1.3.4.1. Use `[ZDKConfig instance].authenticationType` instead.");


/**
 *  The authentication type associated with the current Zendesk SDK user.
 *
 *  @since 1.3.4.1
 */
@property (nonatomic, assign, readonly) ZDKAuthenticationType authenticationType;



/**
 *  Override the default locale specified via the SDK admin.
 *  A request is made to check the language is supported. If it is not supported, or the request fails, the default
 *  language remians in place. Should be an IETF language tag.
 *
 *  @since 1.1.0.1
 */
@property (nonatomic, copy) NSString *userLocale;


/**
 *  Enable COPPA for SDK.
 *
 *  @since 1.1.0.1
 */
@property (nonatomic, assign) BOOL coppaEnabled;


/**
 *  Get the API instance (singleton).
 *
 *  @since 0.9.3.1
 *
 *  @return the API instance
 */
+ (instancetype) instance;



/**
 *  Initialize the SDK with callbacks.
 *
 *  @param applicationId The application id of your SDK app, as found in the web interface.
 *  @param zendeskUrl    The full URL of your Zendesk instance, https://{subdomain}.zendesk.com
 *  @param oAuthClientId The oAuthClientId required as part of the authentication process
 *  @param successBlock  Callback executed on successful initialization of the SDK. Can be nil.
 *  @param errorBlock    Callback executed if initialization fails. Can be nil.
 */
- (void) initializeWithAppId:(NSString *)applicationId
                  zendeskUrl:(NSString *)zendeskUrl
                    ClientId:(NSString *)oAuthClientId
                   onSuccess:(ZDKInitializeSuccess)successBlock
                     onError:(ZDKAPIError)errorBlock;


/**
 *  Initialize the SDK.
 *
 *  @since 1.0.0.1
 *
 *  @param applicationId The application id of your SDK app, as found in the web interface.
 *  @param zendeskUrl    The full URL of your Zendesk instance, https://{subdomain}.zendesk.com
 *  @param oAuthClientId The oAuthClientId required as part of the authentication process
 */
- (void) initializeWithAppId:(NSString *)applicationId
                  zendeskUrl:(NSString *)zendeskUrl
                 andClientId:(NSString *)oAuthClientId;

/**
 *  Reload the config from the server, reload will be started if a reload
 *  is not already in progress and the reload interval has passed. This method
 *  will automatically be invoked when the application enters the foreground to
 *  check for updates if due.
 *
 *  @since 0.9.3.1
 */
- (void) reload;


/**
 *  The reload time interval is the maximum frequency with which a reload will be triggered.
 *
 *  @since 0.9.3.1
 */
- (NSTimeInterval) reloadInterval;


/**
 *  Set reload time interval. One hour is the minimum possible value for a reload interval.
 *
 *  @since 0.9.3.1
 *
 *  @param interval the reload interval. An interval of less than one hour will result in
 *  a minimum reload interval, eg. [ZendeskSDK setReloadInterval:0] results in a reload
 *  interval of one hour.
 */
- (void) setReloadInterval:(NSTimeInterval)interval;

/**
 *  Set userIdentity for the user
 *
 *  @param aUserIdentity instance of NSObject that implements the protcol ZDKIdentity
 */
- (void) setUserIdentity:(id<ZDKIdentity>) aUserIdentity;


/**
 *  Register the device for push notifications.
 *  Deprecated as 1.4.0.1, please use enablePushWithDeviceID or enablePushWithUAChannelID.
 *
 *  @since 1.2.0.1
 *
 *  @param identifier The device identifier
 *  @param callback    Callback that will provide a newly created device ZDKPushRegistrationResponse.
 */
- (void) enablePush:(NSString *)identifier callback:(ZDKPushRegistrationCallback)callback __deprecated_msg("As of version 1.4.0.1, please use enablePushWithDeviceID or enablePushWithUAChannelID");


/**
 *  Register the device for push notifications with APNS ID.
 *
 *  @param identifier The APNS device identifier.
 *  @param callback   Callback that will provide a newly created device ZDKPushRegistrationResponse.
 *
 *  @since 1.4.0.1
 */
- (void) enablePushWithDeviceID:(NSString *)identifier callback:(ZDKPushRegistrationCallback)callback;


/**
 *  Register the device for push notifications with Urban Airship channel ID.
 *
 *  @param identifier The Urban Airship channel ID
 *  @param callback   Callback that will provide a newly created device ZDKPushRegistrationResponse.
 *
 *  @since 1.4.0.1
 */
- (void) enablePushWithUAChannelID:(NSString *)identifier callback:(ZDKPushRegistrationCallback)callback;


/**
 *  Unregister the device for push notifications.
 *
 *  @since 1.2.0.1
 *
 *  @param identifier The device identifier
 *  @param callback    Callback that provides the HTTP status code for the deletion request.
 */
- (void) disablePush:(NSString *)identifier callback:(ZDKPushDeletionCallback)callback;


@end
