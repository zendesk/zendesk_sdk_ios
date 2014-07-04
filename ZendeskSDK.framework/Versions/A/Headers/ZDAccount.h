//
//  ZDAccount.h
//  ZDAPI
//
//  Created by Zendesk on 06/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>


/**
 * The ZDAccount is a wrapper around the account and
 * user details required to interact with your helpdesk.
 */
@interface ZDAccount : NSObject


/**
 * The subdomain of your Zendesk account
 * e.g. if your usual helpdesk URL is 'http://xyz.zendesk.com' then you would set this as 'xyz.zendesk.com'
 */
@property (strong) NSString *subdomain;


/**
 * End users email address, this should be set at runtime before any other methods are invoked.
 */
@property (strong) NSString *email;


/**
 * The token the SDK will use to authenticate against your specified service.
 */
@property (strong) NSString *userToken;


/**
 * The SDK client id.
 */
@property (strong) NSString *clientId;


/**
 * The current Zendesk oauth token.
 */
@property (strong) NSString *oauthToken;


@end

