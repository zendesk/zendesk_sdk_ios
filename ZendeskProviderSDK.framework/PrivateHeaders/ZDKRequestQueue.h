/*
 *
 *  ZDKRequestQueue.h
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


/**
 class responsible for storing a list of requests, and perform them later
 */
NS_ASSUME_NONNULL_BEGIN
@interface ZDKRequestQueue : NSObject

/**
 *  create a request queue
 *
 *  @param requestExecutor executor to perfom the requests on
 */
- (instancetype)initWithRequestExecutor:(ZDKRequestExecutor*)requestExecutor NS_DESIGNATED_INITIALIZER;


/**
 *  adds a request to the internally stored ones
 *
 *  @param request           request to store
 *  @param isAuthRequired    is auth required for this request
 *  @param completionHandler the handler to call when the request is executed
 */
- (void)addRequest:(NSURLRequest *)request
    isAuthRequired:(BOOL)isAuthRequired
 completionHandler:(ZDKAPIRequestBlock)completionHandler;

/**
 *  Execute all the stored requests
 */
- (void)executeRequests;

/**
 *  Informs the passed blocks about an error
 *  @param error Error to inform about
 */
- (void)informAboutError:(NSError*)error;

/**
 *  return the number of request queued
 */
- (NSInteger)pendingRequestsCount;

- (instancetype)init NS_UNAVAILABLE;

@end
NS_ASSUME_NONNULL_END
