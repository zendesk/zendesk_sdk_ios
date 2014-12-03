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
 * API success block.
 */
typedef void (^ZDKAPISuccess) (id);


/**
 * API error block
 */
typedef void (^ZDKAPIError) (NSError*);


/**
 * ZDKAPI Error codes.
 */
typedef NS_ENUM(NSInteger, ZDKAPIErrorCode) {

    /** No internet connection available according to Reachability. */
    ZDKAPIErrorUnreachable,

    /** Connection could not be established. */
    ZDKAPIErrorConnection,

    /** Authentication failed. */
    ZDKAPIErrorAuth,

    /** Request failed. */
    ZDKAPIErrorRequest,

    /** No valid subdomain has been set. */
    ZDKAPIErrorSubdomain,

    /** No sdk client id. */
    ZDKAPIErrorClientId,

    /** No token or user email. */
    ZDKAPIErrorUserId,

    /** Invalid delegate config for request. */
    ZDKAPIErrorDelegateConfig,
};


/**
 *  Convenience method for executing a block on the request queue.
 *
 *  @param queue The queue that will execute the block.
 *  @param block Block the block to be executed.
 */
static inline void zdk_on_queue(dispatch_queue_t queue, dispatch_block_t block)
{
    dispatch_async(queue, block);
}


/**
 * Convenience method for executing a block on the UI queue
 * @param block the block to be executed
 */
static inline void zdk_on_main_thread(dispatch_block_t block)
{
    dispatch_async(dispatch_get_main_queue(), block);
}


/**
 * ZDKAPI Login state
 */
typedef NS_ENUM(NSInteger, ZDKAPILoginState) {

    /**
     * The SDK has not yet authenticated during this session.
     */
    ZDKAPILoginStateNotLoggedIn,

    /**
     * The SDK is in the process of loggin in.
     */
    ZDKAPILoginStateLoggingIn,

    /**
     * The SDK has an oauth token that was valid the last time it was used.
     */
    ZDKAPILoginStateLoggedIn
};


#pragma mark - Dispatcher



/**
 * The core communications controller.
 */
@interface ZDKDispatcher : NSObject


@property (nonatomic, weak) id<ZDKDispatcherDelegate> delegate;


/**
 * Enable or disable debug logging output.
 *
 * @param enabled YES for debug logging.
 */
+ (void) setDebugLogging:(BOOL)enabled;


/**
 * Verifies the configuration, logs in if necessary and then executes the request on the request queue.
 * This method handles putting the requets process into the request queue and then ensuring that the final
 * responses are sent on the main thread.
 *
 * If the error block is invoked with a 'ZDKAPIErrorUnreachable' error then this is an immediate response on the same thread.
 *
 * @param requestBlock block which builds the NSMutableURLRequest
 * @param successBlock block which will be invoked on the main thread if the request is successful
 * @param errorBlock block which will be invoked on the main thread if the request fails
 * @param requiresAuth boolen indicating if the request requires authentication
 */
- (void) executeRequest:(NSMutableURLRequest* (^)(void))requestBlock
              onSuccess:(ZDKAPISuccess)successBlock
                onError:(ZDKAPIError)errorBlock
           requiresAuth:(BOOL)requiresAuth;


@end
