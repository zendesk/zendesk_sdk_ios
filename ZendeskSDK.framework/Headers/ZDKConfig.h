//
//  ZDKConfig.h
//  ZendeskSDK
//
//  Created by Zendesk on 29/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZDKAppSettings, ZDKAccount;

/*
 * ZDKConfig is responsible for initialization of
 * the SDK and manages the backend configuration.
 */
@interface ZDKConfig : NSObject

@property (nonatomic, readonly) ZDKAccount *account;


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
 */
- (void) initializeWithAppId:(NSString *)applicationId
               andZendeskUrl:(NSString *)zendeskUrl;

/**
 *  Initialize the SDK.
 *
 *  This initializer is deprecated and is likely to be removed in the next release.
 *
 *  @param applicationId The application id of your SDK app, as found in the web interface.
 *  @param zendeskUrl    The full URL of your Zendesk instance, https://{subdomain}.zendesk.com
 *  @param oAuthClientId Your client ID, can be nil if not using any authentication.
 *  @param userId        An identifier that can be used to identify your user.
 */
- (void) initializeWithAppId:(NSString *)applicationId
                  zendeskUrl:(NSString *)zendeskUrl
               oAuthClientId:(NSString *)oAuthClientId
                   andUserId:(NSString *)userId __attribute__((deprecated));



/**
 * Get the SDK Settings for an instance of Zendesk.
 *
 * @return The SDK Settings for the configured instance of Zendesk.
 */
- (ZDKAppSettings *) getSDKSettings;


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


@end
