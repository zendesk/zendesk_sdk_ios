//
//  ZDUser.h
//  ZDAPI
//
//  Created by Zendesk on 13/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "ZDModelObject.h"


/**
 * A user in Zendesk.
 */
@interface ZDUser : ZDModelObject

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
 * @param dict the user details
 */
- (void) updateWithDict:(NSDictionary*)dict;


#pragma mark avatar download


/**
 * Download the avatar image for this user.
 * 
 * @param successBlock to be executed upon success, the result object will be the UIImage of the avatar
 * @param errorBlock to be executed upon error
 */
- (void) getAvatar:(ZDAPISuccess)success
           onError:(ZDAPIError)error;


@end

