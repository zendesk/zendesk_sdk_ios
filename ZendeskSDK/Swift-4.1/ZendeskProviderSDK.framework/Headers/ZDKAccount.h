/*
 *
 *  ZDKAccount.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 06/06/2014.
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

/**
 *  An account can be in one of these states.
 *
 *  @since 0.9.3.1
 */
typedef NS_ENUM(NSInteger, ZDKAccountState) {
    
    /**
     * Account details have not yet been loaded.
     *
     *  @since 0.9.3.1
     */
    ZDKAccountStateUnloaded,
    
    /**
     * Account state is valid.
     *
     *  @since 0.9.3.1
     */
    ZDKAccountStateValid,
    
    /**
     * A defining value has been changed and the account can not be guaranteed to point to the same Zendesk account.
     *
     *  @since 0.9.3.1
     */
    ZDKAccountStateInvalidated
};


/**
 * The ZDAccount is a wrapper around the account and
 * user details required to interact with your helpdesk.
 *
 *  @since 0.9.3.1
 */
@interface ZDKAccount : NSObject


/**
 * The full URL of your Zendesk instance, https://{subdomain}.zendesk.com
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, copy) NSString *zendeskUrl;


/**
 * The application id of your SDK app, as found in the web interface.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, copy) NSString *applicationId;


/**
 * The oauth client id that was supplied when you set up oauth in web interface.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, copy) NSString *oAuthClientId;


/**
 * The current Zendesk oauth token.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, copy) NSString *oauthToken;

/**
 * Indicates account state and whether the account state has been invalidated by a credential change.
 *
 *  @since 0.9.3.1
 */
@property (assign) ZDKAccountState state;


/**
 *  create an account
 *
 *  @param zendeskUrl    The full URL of your Zendesk instance, https://{subdomain}.zendesk.com
 *  @param applicationId The application id of your SDK app, as found in the web interface.
 *  @param clientId      The oauth client id that was supplied when you set up oauth in web interface.
 */
- (instancetype)initWithUrl:(NSString *)zendeskUrl
              applicationId:(NSString *)applicationId
                   clientId:(NSString *)clientId NS_DESIGNATED_INITIALIZER;


- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

