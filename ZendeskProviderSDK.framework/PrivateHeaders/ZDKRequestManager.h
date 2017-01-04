/*
 *
 *  ZDKRequestManager.h
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
#import "ZDKReachability.h"
#import "ZDKRequestSessionFactory.h"


/**
 *  Main class that handles executing http requests
 */
NS_ASSUME_NONNULL_BEGIN
@interface ZDKRequestManager : NSObject

/**
 *  The current internal request session
 */
@property (nonatomic, strong, readonly) ZDKRequestSession *currentRequestSession;

/**
 *  Creates a new ZDKRequestManager
 *
 *  @param reachability   rechability instance to specify if internet is reachable
 *  @param sessionFactory session factory helps in creating different types of sessions
 */
- (instancetype)initWithReachability:(ZDKReachability*)reachability
                      sessionFactory:(ZDKRequestSessionFactory*)sessionFactory NS_DESIGNATED_INITIALIZER;

/**
 *  Executes the HTTP request
 *
 *  @param request           the request to execute
 *  @param isAuthRequired    Is authentication required or not
 *  @param completionHandler handler to call when execution ends
 */
- (void)executeRequest:(NSURLRequest*)request isAuthRequired:(BOOL)isAuthRequired completionHandler:(nonnull ZDKAPIRequestBlock)completionHandler;

- (instancetype)init NS_UNAVAILABLE;

@end
NS_ASSUME_NONNULL_END
