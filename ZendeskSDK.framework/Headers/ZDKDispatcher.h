/*
 *
 *  ZDKDispatcher.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 08/06/2014.  
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
#import "ZDKDispatcherDelegate.h"
#import "ZDKDispatcherResponse.h"



/**
 *  API success block.
 *
 *  @since 0.9.3.1
 */
typedef void (^ZDKAPISuccess) (id result);


/**
 *  API error block.
 *
 *  @since 0.9.3.1
 */
typedef void (^ZDKAPIError) (NSError *error);


/**
 *  ZDKAPI Error codes.
 *
 *  @since 0.9.3.1
 */
typedef NS_ENUM(NSInteger, ZDKAPIErrorCode) {

    /** 
     *  No internet connection available according to Reachability.
     *
     *  @since 0.9.3.1
     */
    ZDKAPIErrorUnreachable,

    /** 
     *  Connection could not be established.
     *
     *  @since 0.9.3.1
     */
    ZDKAPIErrorConnection,

    /** 
     *  Authentication failed.
     *
     *  @since 0.9.3.1
     */
    ZDKAPIErrorAuth,

    /** 
     *  Request failed.
     *
     *  @since 0.9.3.1
     */
    ZDKAPIErrorRequest,

    /** 
     *  No valid subdomain has been set.
     *
     *  @since 0.9.3.1
     */
    ZDKAPIErrorSubdomain,

    /** 
     *  No sdk client id.
     *
     *  @since 0.9.3.1
     */
    ZDKAPIErrorClientId,

    /** 
     *  No token or user email.
     *
     *  @since 0.9.3.1
     */
    ZDKAPIErrorUserId,

    /** 
     *  Invalid delegate config for request.
     *
     *  @since 0.9.3.1
     */
    ZDKAPIErrorDelegateConfig,
};


/**
 *  Convenience method for executing a block on the request queue.
 *
 *  @since 0.9.3.1
 *
 *  @param queue The queue that will execute the block.
 *  @param block Block the block to be executed.
 */
static inline void zdk_on_queue(dispatch_queue_t queue, dispatch_block_t block)
{
    dispatch_async(queue, block);
}


/**
 *  Convenience method for executing a block on the UI queue
 *
 *  @since 0.9.3.1
 *  @param block the block to be executed
 */
static inline void zdk_on_main_thread(dispatch_block_t block)
{
    dispatch_async(dispatch_get_main_queue(), block);
}


/**
 *  ZDKAPI Login state.
 *
 *  @since 0.9.3.1
 */
typedef NS_ENUM(NSInteger, ZDKAPILoginState) {

    /**
     *  The SDK has not yet authenticated during this session.
     *
     *  @since 0.9.3.1
     */
    ZDKAPILoginStateNotLoggedIn,

    /**
     *  The SDK is in the process of loggin in.
     *
     *  @since 0.9.3.1
     */
    ZDKAPILoginStateLoggingIn,

    /**
     *  The SDK has an oauth token that was valid the last time it was used.
     *
     *  @since 0.9.3.1
     */
    ZDKAPILoginStateLoggedIn
};


#pragma mark - Dispatcher



/**
 *  The core communications controller.
 *
 *  @since 0.9.3.1
 */
@interface ZDKDispatcher : NSObject


@property (nonatomic, weak) id<ZDKDispatcherDelegate> delegate;


/**
 *  Enable or disable debug logging output.
 *
 *  @since 0.9.3.1
 *
 *  @param enabled YES for debug logging.
 */
+ (void) setDebugLogging:(BOOL)enabled __deprecated_msg(" As of version 1.3.0.1");


/**
 *  Verifies the configuration, logs in if necessary and then executes the request on the request queue.
 *  This method handles putting the requets process into the request queue and then ensuring that the final
 *  responses are sent on the main thread.
 *
 *  If the error block is invoked with a 'ZDKAPIErrorUnreachable' error then this is an immediate response on the same thread.
 *
 *  @since 0.9.3.1
 *
 *  @param requestBlock block which builds the NSMutableURLRequest
 *  @param successBlock block which will be invoked on the main thread if the request is successful
 *  @param errorBlock block which will be invoked on the main thread if the request fails
 *  @param requiresAuth boolen indicating if the request requires authentication
 */
- (void) executeRequest:(NSMutableURLRequest* (^)(void))requestBlock
              onSuccess:(ZDKAPISuccess)successBlock
                onError:(ZDKAPIError)errorBlock
           requiresAuth:(BOOL)requiresAuth;


@end
