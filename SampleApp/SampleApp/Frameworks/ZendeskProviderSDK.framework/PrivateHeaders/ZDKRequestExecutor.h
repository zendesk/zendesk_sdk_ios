/*
 *
 *  ZDKRequestExecutor.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on  14/12/2015
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZendeskSDKConstants.h"


@class ZDKAccount;
/**
 class responsible for performing the request
 */
NS_ASSUME_NONNULL_BEGIN
typedef void (^ZDKAPIRequestBlock)(NSHTTPURLResponse * _Nullable urlResponse, NSData * _Nullable data, NSError * _Nullable error);

@interface ZDKRequestExecutor : NSObject

/**
 *  Init with an account
 *
 *  @param account The account to use for request
 */
- (instancetype)initWithAccount:(ZDKAccount*)account;

/**
 *  Creates a ZDKRequestExecutor
 *
 *  @param operationQueue the queue to dispatch the operation on
 *  @param account The account to use for request
 */
- (instancetype)initWithQueue:(NSOperationQueue*_Nullable)operationQueue account:(ZDKAccount*)account NS_DESIGNATED_INITIALIZER;

/**
 *  Execute the request
 *
 *  @param request           request to execute
 *  @param isAuthRequired    Is authentication required or not
 *  @param completionHandler completion handler called when the request ends
 */
- (void)executeRequest:(NSURLRequest *)request
        isAuthRequired:(BOOL)isAuthRequired
     completionHandler:(ZDKAPIRequestBlock)completionHandler;


- (instancetype)init NS_UNAVAILABLE;

@end
NS_ASSUME_NONNULL_END
