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
 *  Tags associated with the user.
 *
 *  @since 1.4.0.1
 */
@property (nonatomic, strong) NSArray *tags;

/**
 *  User fields for this user as a dictionary with the key being the name of the user field
 *  and the corresponding value being the value of the user field set for this user.
 *
 *  @since 1.4.0.1
 */
@property (nonatomic, strong) NSDictionary *userFields;


/**
 * Initialise with dictionary generated from API json.
 *
 * @param dictionary the user details
 */
- (instancetype) initWithDictionary:(NSDictionary*)dictionary;


@end

