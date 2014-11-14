//
//  ZDKUser.h
//  ZendeskSDK
//
//  Created by Zendesk on 13/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>


/**
 * A user in Zendesk.
 */
@interface ZDKUser : NSObject

/**
 * The users id in Zendesk.
 */
@property (nonatomic, strong) NSNumber *userId;

/**
 * The users name.
 */
@property (nonatomic, strong) NSString *name;

/**
 * URL of the users avatar.
 */
@property (nonatomic, strong) NSString *avatarURL;

/**
 * YES if the user is an agent.
 */
@property (nonatomic, assign) BOOL isAgent;


/**
 * Initialise with dictionary generated from API json.
 *
 * @param dictionary the user details
 */
- (instancetype) initWithDictionary:(NSDictionary*)dictionary;


@end

