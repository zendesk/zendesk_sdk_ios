//
//  ZDKAccount.h
//  ZendeskSDK
//
//  Created by Zendesk on 06/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger, ZDKAccountState) {

    /**
     * Account details have not yet been loaded.
     */
    ZDKAccountStateUnloaded,
    
    /**
     * Account state is valid.
     */
    ZDKAccountStateValid,

    /**
     * A defining value has been changed and the account can not be guaranteed to point to the same Zendesk account.
     */
    ZDKAccountStateInvalidated
};


/**
 * The ZDAccount is a wrapper around the account and
 * user details required to interact with your helpdesk.
 */
@interface ZDKAccount : NSObject


/**
 * The full URL of your Zendesk instance, https://{subdomain}.zendesk.com
 */
@property (nonatomic, strong) NSString *zendeskUrl;


/**
 * The application id of your SDK app, as found in the web interface
 */
@property (nonatomic, strong) NSString *applicationId;


/**
 * End users email address, this should be set at runtime before any other methods are invoked.
 */
@property (nonatomic, strong) NSString *email;

/**
 * An identifier that can be used to identify your user.
 */
@property (nonatomic, strong) NSString *userId;

/**
 * The oauth client id that was supplied when you set up oauth in web interface
 */
@property (nonatomic, strong) NSString *oAuthClientId;

/**
 * The current Zendesk oauth token.
 */
@property (nonatomic, strong) NSString *oauthToken;

/**
 * The zendesk user id of the user in the current subdomain.
 */
@property (nonatomic, strong) NSNumber *zendeskUserId;

/**
 * Indicates account state and whether the account state has been invalidated by a credential change.
 */
@property (assign) ZDKAccountState state;


@end

