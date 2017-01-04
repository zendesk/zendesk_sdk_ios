/*
 *
 *  ZDKRequestSessionFactory.h
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
#import "ZDKRequestSession.h"


@class ZDKRequestExecutor, ZDKAuthenticationSpace;
@protocol ZDKRequestSessionStateDelegate, ZDKIdentity;

/**
 *  Factory that aids in the creation of the different types of sessions
 */
NS_ASSUME_NONNULL_BEGIN
@interface ZDKRequestSessionFactory : NSObject <ZDKRequestSessionCreationDelegate>

/**
 *  Authentication space to use
 */
@property (nonatomic, strong) ZDKAuthenticationSpace *authenticationSpace;

/**
 *  create a factory with an account
 *
 *  @param authenticationSpace  authentication space to use with requests
 */
- (instancetype)initWithAuthenticationSpace:(ZDKAuthenticationSpace *)authenticationSpace;

/**
 *  creates a factory with an executor
 *
 *  @param requestExecutor      the executor, this will be passed to any session the factory creates
 *  @param authenticationSpace  authentication space to use with requests
 */
- (instancetype)initWithRequestExecutor:(ZDKRequestExecutor*)requestExecutor
                    authenticationSpace:(ZDKAuthenticationSpace *)authenticationSpace NS_DESIGNATED_INITIALIZER;

/**
 *  creates the initial session based on the values stored in ZDKKAccount
 *
 *  @param delegate session state progression delegate
 *
 *  This method is the only method that the user of the class has to call, after that, the creation of new 
 *  session will be vended by the ZDKRequestSessionCreationDelegate delegate method
 *  Upon creating any session, factory will set itself as the creation delegate of the created session
 */
- (ZDKRequestSession*)createAndSetupInitialSessionWithDelegate:(id<ZDKRequestSessionStateDelegate>)delegate;


- (instancetype)init NS_UNAVAILABLE;

@end
NS_ASSUME_NONNULL_END
