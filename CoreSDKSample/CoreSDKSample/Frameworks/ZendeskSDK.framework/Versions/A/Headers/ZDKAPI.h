//
//  ZDKAPI.h
//  ZendeskSDK
//
//  Created by Zendesk on 22/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZDKDeviceInfo.h"
#import "ZDKAccount.h"
#import "ZDKDispatcher.h"
#import "ZDKDispatcherDelegate.h"
#import "ZDKRequestContainer.h"
#import "ZDKRequest.h"
#import "ZDKRequestComment.h"
#import "ZDKUserContainer.h"


/**
 * ZDKAPI is the primary access point for API requests.
 */
@interface ZDKAPI : ZDKDispatcher <ZDKDispatcherDelegate> {

    ZDKAccount *account;
    ZDKUserContainer *users;
    ZDKRequestContainer *requests;
}


/**
 * The ZDAccount with details for your account and end user.
 */
@property (strong, readonly) ZDKAccount *account;


/**
 * The User cache with user details.
 */
@property (strong, readonly) ZDKUserContainer *users;


/**
 * The user requests.
 */
@property (strong, readonly) ZDKRequestContainer *requests;


/**
 * Get the API instance (singleton).
 * @return the API instance
 */
+ (instancetype) instance;


#pragma mark API requests


/**
 * Get the list of requests for the logged in user.
 */
- (ZDKRequestContainer*) requests;


/**
 * Create a new request.
 * @param description complete request description
 * @param subject the request subject
 * @param tags all tags to be set on the new request (triggers or automations may update these tags depending on account setup)
 * @param success block to be called on successful submission of the request
 * @param error block to be called if there is an error submitting the request
 */
- (void) createRequest:(NSString*)description
               subject:(NSString*)subject
                  tags:(NSArray*)tags
             onSuccess:(ZDKAPISuccess)success
               onError:(ZDKAPIError)error;


+ (NSString*) userAgent;

@end

