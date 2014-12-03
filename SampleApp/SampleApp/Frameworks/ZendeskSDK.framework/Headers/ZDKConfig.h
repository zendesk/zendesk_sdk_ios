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
@class ZDKAppSettings, ZDKAccount, ZDKSdkStorage;

/*
 * ZDKConfig is responsible for initialization of
 * the SDK and manages the backend configuration.
 */
@interface ZDKConfig : NSObject

@property (nonatomic, readonly) ZDKAccount *account;
@property (nonatomic, strong) NSArray *customTicketFields;
@property (nonatomic, strong) NSNumber *ticketFormId;

/**
 * Get the API instance (singleton).
 * @return the API instance
 */
+ (instancetype) instance;

/**
 *  Initialize the SDK.
 *
 *  This initializer is deprecated and is likely to be removed in the next release.
 *
 *  @param applicationId The application id of your SDK app, as found in the web interface.
 *  @param zendeskUrl    The full URL of your Zendesk instance, https://{subdomain}.zendesk.com
 *  @param oAuthClientId The oAuthClientId required as part of the authentication process
 */
- (void) initializeWithAppId:(NSString *)applicationId
                  zendeskUrl:(NSString *)zendeskUrl
                 andClientId:(NSString *)oAuthClientId;


/**
 * Reload the config from the server, reload will be started if a reload
 * is not already in progress and the reload interval has passed. This method
 * will automatically be invoked when the application enters the foreground to
 * check for updates if due.
 */
- (void) reload;


/**
 * The reload time interval is the maximum frequency with which a reload will be triggered.
 */
- (NSTimeInterval) reloadInterval;


/**
 * Set reload time interval. One hour is the minimum possible value for a reload interval.
 *
 * @param interval the reload interval. An interval of less than one hour will result in
 * a minimum reload interval, eg. [ZendeskSDK setReloadInterval:0] results in a reload
 * interval of one hour.
 */
- (void) setReloadInterval:(NSTimeInterval)interval;

/**
 *  Set userIdentity for the user
 *
 *  @param aUserIdentity instance of NSObject that implements the protcol ZDKIdentity
 */
- (void) setUserIdentity:(NSObject<ZDKIdentity> *) aUserIdentity;

@end
