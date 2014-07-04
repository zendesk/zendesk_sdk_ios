//
//  ZDAPI.h
//  ZDAPI
//
//  Created by Zendesk on 22/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZDDeviceInfo.h"
#import "ZDAccount.h"
#import "ZDDispatcher.h"
#import "ZDDispatcherDelegate.h"
#import "ZDRequests.h"
#import "ZDRequest.h"
#import "ZDRequestComment.h"
#import "ZDUsers.h"


/**
 * ZDAPI is the primary access point for API requests.
 */
@interface ZDAPI : ZDDispatcher <ZDDispatcherDelegate> {

    ZDAccount *account;
    ZDUsers *users;
    ZDRequests *requests;
}


/**
 * The ZDAccount with details for your account and end user.
 */
@property (strong, readonly) ZDAccount *account;


/**
 * The User cache with user details.
 */
@property (strong, readonly) ZDUsers *users;


/**
 * The user requests.
 */
@property (strong, readonly) ZDRequests *requests;


/**
 * Get the API instance (singleton).
 * @retutn the API instance
 */
+ (instancetype) instance;


#pragma mark API requests


/**
 * Get the list of requests for the logged in user.
 */
- (ZDRequests*) requests;


/**
 * Create a new request.
 * @param the complete request description
 * @param subject the request subject
 * @param tags all tags to be set on the new request (triggers or automations may update these tags depending on account setup)
 * @param success block to be called on successful submission of the request
 * @param error block to be called if there is an error submitting the request
 */
- (void) createRequest:(NSString*)description
               subject:(NSString*)subject
                  tags:(NSArray*)tags
             onSuccess:(ZDAPISuccess)success
               onError:(ZDAPIError)error;


@end

