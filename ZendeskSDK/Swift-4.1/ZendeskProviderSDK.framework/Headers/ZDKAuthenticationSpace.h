/*
 *
 *  ZDKAuthenticationSpace.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on  31/12/2015.
 *
 *  Copyright (c) 2016 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZendeskSDKConstants.h"
#import "ZDKIdentity.h"
#import "ZDKAccount.h"


@class ZDKIdentityStorage;

/**
 *  Class that represents the authentication space
 *
 *  @since 1.6.0.1
 */
@interface ZDKAuthenticationSpace : NSObject


/**
 *  zendesk account to use for requests
 *
 *  @since 1.6.0.1
 */
@property (nonatomic, strong, readonly) ZDKAccount *account;

/**
 *  user identity identity
 *
 *  @since 1.6.0.1
 */
@property (nonatomic, strong, readonly) id<ZDKIdentity> userIdentity;

/**
 *  user identity identity storage
 *
 *  @since 1.6.0.1
 */
@property (nonatomic, strong) ZDKIdentityStorage *identityStorage;

/**
 *  get the default space
 *
 *  @since 1.6.0.1
 */
+ (ZDKAuthenticationSpace*)defaultSpace;

/**
 *  creates an authentication space
 *
 *  @since 1.6.0.1
 *
 *  @param account              the account to use for the requests
 *  @param userIdentity         the user identity used
 */
- (instancetype)initWithAccount:(ZDKAccount *)account
                   userIdentity:(id<ZDKIdentity>)userIdentity;


/**
 *  Get UUID from local storage or generate if required
 *
 *  @since 1.6.0.1
 *
 *  @return NSString of UUID that has been generated
 */
- (NSString*)UUID;

@end
