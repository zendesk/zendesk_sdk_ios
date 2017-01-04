/*
 *
 *  ZDKRequestSessionLoggingIn.h
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

#import "ZDKRequestSession.h"


@class ZDKLoginRequest, ZDKRequestQueue;

/**
 *  Request session that handles the requests executed on a session that is still logging in
 */
NS_ASSUME_NONNULL_BEGIN
@interface ZDKRequestSessionLoggingIn: ZDKRequestSession

@property (atomic, assign, readonly) BOOL isLoggingIn;

/**
 *  create a logging in session
 *
 *  @param requestExecutor the executor to use
 *  @param loginRequest    the login request to use for logging in
 *  @param authenticationSpace  authentication space to use with requests
 *  @param delegate        the session progression delegate
 */
- (instancetype)initWithRequestExecutor:(ZDKRequestExecutor*)requestExecutor
                           loginRequest:(ZDKLoginRequest*)loginRequest
                    authenticationSpace:(ZDKAuthenticationSpace *)authenticationSpace
                        sessionDelegate:(id<ZDKRequestSessionStateDelegate>)delegate;

/**
 *  create a logging in session
 *
 *  @param requestExecutor the executor to use
 *  @param loginRequest    the login request to use for logging in
 *  @param requestQueue    the request queue to store the request dispatched while logging in
 *  @param authenticationSpace  authentication space to use with requests
 *  @param delegate        the session progression delegate
 */
- (instancetype)initWithRequestExecutor:(ZDKRequestExecutor*)requestExecutor
                           loginRequest:(ZDKLoginRequest*)loginRequest
                           requestQueue:(ZDKRequestQueue*)requestQueue
                    authenticationSpace:(ZDKAuthenticationSpace *)authenticationSpace
                        sessionDelegate:(id<ZDKRequestSessionStateDelegate>)delegate NS_DESIGNATED_INITIALIZER;


- (instancetype)initWithRequestExecutor:(ZDKRequestExecutor*)requestExecutor
                    authenticationSpace:(ZDKAuthenticationSpace *)authenticationSpace
                        sessionDelegate:(id<ZDKRequestSessionStateDelegate>)delegate NS_UNAVAILABLE;


@end
NS_ASSUME_NONNULL_END
