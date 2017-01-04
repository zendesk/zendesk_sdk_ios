/*
 *
 *  ZDKLoginRequest.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on  14/12/2015
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZendeskSDKConstants.h"


@protocol ZDKIdentity;
@class ZDKRequestExecutor, ZDKAccount, ZDKAuthenticationSpace;

/**
 class that performs the login request and manages the storage of the auth token
 */
NS_ASSUME_NONNULL_BEGIN
@interface ZDKLoginRequest : NSObject

/**
 *  create a new login request
 *
 *  @param requestExecutor      executor to use for the request
 *  @param authenticationSpace  authentication space to use with requests
 *
 */
- (instancetype)initWithRequestExecutor:(ZDKRequestExecutor*)requestExecutor
                    authenticationSpace:(ZDKAuthenticationSpace*)authenticationSpace NS_DESIGNATED_INITIALIZER;

/**
 *  perform the login request
 *
 *  @param completionHandler handler to call when request ends
 */
- (void)loginWithcompletionHandler:(void (^)(NSError *))completionHandler;

- (instancetype)init NS_UNAVAILABLE;

@end
NS_ASSUME_NONNULL_END
