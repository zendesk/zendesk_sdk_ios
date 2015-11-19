/*
 *
 *  ZDKIdentityStorage.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 25/11/2014.  
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
#import "ZDKIdentity.h"

@interface ZDKIdentityStorage : NSObject

/**
 *  Store and fetch object that implements ZDKIdentity protocol in local storage
 */
@property (nonatomic, strong, getter=storedIdentity, setter=storeIdentity:) id<ZDKIdentity> identity;


/**
 *  Get UUID from local storage or generate if required
 *
 *  @return NSString of UUID that has been generated
 */
- (NSString *) getUUID ;

/**
 *  Store object that implements ZDKIdentity protocol in local storage
 *
 *  @param identity NSObject that implements ZDKIdentity protocol
 */
- (void) storeIdentity:(id <ZDKIdentity>) identity;

/**
 *  Fetch stored Identity from local storage
 *
 *  @return instance that implements ZDKIdentity protocol
 */
- (id <ZDKIdentity>) storedIdentity;

/**
 *  Fetch stored OAuth token from local storage
 *
 *  @return NSString OAuth token
 */
- (NSString *) storedOAuthToken;


/**
 *  Stores an OAuth token to be stored
 *
 *  @param oAuthToken NSString of the OAuth to be stored
 */
- (void) storeOAuthToken:(NSString *)oAuthToken;


/**
 * Deletes ALL storage
 */
- (void) deleteStoredData;


@end
