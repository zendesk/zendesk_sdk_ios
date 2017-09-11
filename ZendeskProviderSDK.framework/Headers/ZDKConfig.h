/*
 *
 *  ZDKConfig.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 29/10/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZDKIdentity.h"
#import "ZDKPushRegistrationProvider.h"
#import "ZDKDispatcher.h"
#import "ZendeskSDKConstants.h"


@class ZDKAppSettings, ZDKAccount, ZDKSdkStorage, ZDKTheme, ZDKCustomField;

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
@property (nonatomic, strong, readonly) ZDKAccount *account;


/**
 *  The userIdentity for the user is an instance of NSObject that implements the protocol ZDKIdentity
 *  @since 1.2.0.1
 */
@property (nonatomic, strong, setter=setUserIdentity:, getter=userIdentity) id<ZDKIdentity> userIdentity;


/**
 *  The reload time interval is the maximum frequency with which a reload will be triggered.
 *
 *  Set reload time interval. One hour is the minimum possible value for a reload interval.
 *  the reload interval. An interval of less than one hour will result in
 *  a minimum reload interval, e.g.. [ZendeskSDK setReloadInterval:0] results in a reload
 *  interval of one hour.
 *
 *  @since 1.6.0.1
 */

@property (nonatomic, assign, setter=setReloadInterval:, getter=reloadInterval) NSTimeInterval reloadInterval;


/**
 *  The authentication type associated with the current Zendesk SDK user.
 *
 *  @since 1.3.4.1
 */
@property (nonatomic, assign, readonly) ZDKAuthenticationType authenticationType;



/**
 *  Override the default locale specified via the SDK admin.
 *  A request is made to check the language is supported. If it is not supported, or the request fails, the default
 *  language remains in place. Should be an IETF language tag.
 *
 *  @since 1.1.0.1
 */
@property (nonatomic, copy) NSString *userLocale;


/**
 * Sets whether we should enable COPPA mode. If the set ZDKAnonymousIdentity doesn't contain a
 * name or email, this method will do nothing. If the set ZDKAnonymousIdentity does contain
 * a name or email, this method will clear user storage (such as requests, article votes, identity
 * information) and set a new, empty ZDKAnonymousIdentity.
 *
 *  @since 1.1.0.1
 */
@property (nonatomic, assign) BOOL coppaEnabled __deprecated_msg("as of 1.11.0.1. Consider using an empty ZDKAnonymousIdentity instead.");

/**
 *  Enable Help Center article up and down voting in Article UI.
 *  Default value is true.
 *
 *  @since 1.10.0.1
 */
@property (nonatomic, assign) BOOL articleVotingEnabled;


/**
 *  Get the API instance (singleton).
 *
 *  @since 0.9.3.1
 *
 *  @return the API instance
 */
+ (instancetype) instance;


/**
 *  Initialize the SDK.
 *
 *  @since 1.6.0.1
 *
 *  @param applicationId The application id of your SDK app, as found in the web interface.
 *  @param zendeskUrl    The full URL of your Zendesk instance, https://{subdomain}.zendesk.com
 *  @param oAuthClientId The oAuthClientId required as part of the authentication process
 */
- (void) initializeWithAppId:(NSString *)applicationId
                  zendeskUrl:(NSString *)zendeskUrl
                    clientId:(NSString *)oAuthClientId;

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


#pragma mark - Deprication


/**
 *  An array for custom fields.
 *
 *  @see <a href="https://developer.zendesk.com/embeddables/docs/ios/providers#using-custom-fields-and-custom-forms">Custom fields and forms documentation</a>
 *
 *  @since 1.0.0.1
 */
@property (nonatomic, copy) NSArray<ZDKCustomField*> *customTicketFields;


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


@end
