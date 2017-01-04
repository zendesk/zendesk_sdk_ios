/*
 *
 *  ZDKRequestSession.h
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
#import "ZDKRequestExecutor.h"


@class ZDKRequestSession, ZDKRequestSessionLoggingIn, ZDKRequestExecutor,
ZDKRequestSessionLoggedIn, ZDKRequestSessionNotLoggedIn, ZDKAuthenticationSpace;

NS_ASSUME_NONNULL_BEGIN
/**
 *  Session state progression protocol
 */
@protocol ZDKRequestSessionStateDelegate <NSObject>
/**
 *  Method called from a ZDKRequestSession to inform the delegate about a session change
 *
 *  @param session    the current session
 *  @param newSession the newly created session
 *
 *  The implementer of this delegate will have to maintain a reference to the newly created session
 */
- (void)requestSession:(ZDKRequestSession*)session didChangeToSession:(ZDKRequestSession*)newSession;
@end

/**
 *  Helper protocol that aids in creating the different subclasses of ZDKRequestSession
 */
@protocol ZDKRequestSessionCreationDelegate <NSObject>
- (ZDKRequestSessionNotLoggedIn*)requestSessionCreateNotLoggedInSession:(ZDKRequestSession*)session;
- (ZDKRequestSessionLoggingIn*)requestSessionCreateLoggingInSession:(ZDKRequestSession*)session;
- (ZDKRequestSessionLoggedIn*)requestSessionCreateLoggedInSession:(ZDKRequestSession*)session;
@end


/**
 *  A request session represent a state in the state diagram of the a request
 *  The request starts as not logged in, then it changes to logging in and lastly to logged in
 
 */
@interface ZDKRequestSession : NSObject

/**
 *  Request executor used internally for executing
 */
@property (nonatomic, strong) ZDKRequestExecutor *requestExecutor;

/**
 *  Authentication space to use
 */
@property (nonatomic, strong) ZDKAuthenticationSpace *authenticationSpace;

/**
 *  State delegate that will be called when the current state changes to a new one
 */
@property (nonatomic, weak) id<ZDKRequestSessionStateDelegate> delegate;

/**
 *  Creation delegate is used internally to create the new session
 */
@property (nonatomic, weak) id<ZDKRequestSessionCreationDelegate> creationDelegate;


/**
 *  create a logging in session
 *
 *  @param requestExecutor the executor to use
 *  @param authenticationSpace  authentication space to use with requests
 *  @param delegate        the session progression delegate
 *
 *  The loginRequest and the requestQueue will be set to the default ones
 */
- (instancetype)initWithRequestExecutor:(ZDKRequestExecutor*)requestExecutor
                    authenticationSpace:(ZDKAuthenticationSpace *)authenticationSpace
                        sessionDelegate:(id<ZDKRequestSessionStateDelegate>)delegate NS_DESIGNATED_INITIALIZER;

/**
 *  Executes the HTTP request, the request will finally be forwarded to the requestExecutor
 *
 *  @param request           the request to execute
 *  @param isAuthRequired    Is authentication required or not
 *  @param completionHandler handler to call when execution ends
 */
- (void)executeRequest:(NSURLRequest*)request isAuthRequired:(BOOL)isAuthRequired completionHandler:(ZDKAPIRequestBlock)completionHandler;

- (instancetype)init NS_UNAVAILABLE;

@end
NS_ASSUME_NONNULL_END
