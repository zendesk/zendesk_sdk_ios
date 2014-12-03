/*
 *
 *  ZDKUser.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 13/06/2014.  
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

