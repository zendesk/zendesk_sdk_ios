/*
 *
 *  ZDKUserProvider.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 7/13/15.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZDKUser.h"
#import "ZDKCustomField.h"

@interface ZDKUserProvider : NSObject

/**
 *  Callback for user tags request
 *
 *  @param userTags The updated user tags
 *  @param error    An error object. Nil if no error occured.
 *
 *  @since 1.4.0.1
 */
typedef void (^ZDKUserTagsCallback)(NSArray *userTags, NSError *error);
/**
 *  Callback for get userfields request
 *
 *  @param userfields All the user fields as an array of ZDKUserField objects, currently available in this instance of zendesk
 *  @param error      An error object. Nil if no error occured.
 */
typedef void (^ZDKUserFieldsCallback)(NSArray *userfields, NSError *error);

/**
 *  Callback for set userfields request.
 *
 *  @param userfields The updated userfields as a dictionary with the name of the user field being the key and the corresponding value being the user field value set to the current user.
 *  @param error      An error object. Nil if no error occured.
 */
typedef void (^ZDKSetUserFieldsCallback)(NSDictionary *userfields, NSError *error);

/**
 *  Callback for get user request.
 *
 *  @param user  A user object which only contains the user's tags and fields at this time.
 *  @param error An error object. Nil if no error occured.
 */
typedef void (^ZDKUserCallback)(ZDKUser *user, NSError *error);

/**
 *  Gets a user object of the current user with only the user fields and tags properties populated.
 *
 *  @param callback Callback will return a user object or an error. Can be nil.
 *
 *  @since 1.4.0.1
 */
- (void) getUser:(ZDKUserCallback)callback;

/**
 *  Add tags to the current user.
 *
 *  @param tags     The tags to add.
 *  @param callback Callback will return an array of the tags set to the current user or an error. Can be nil.
 *
 *  @since 1.4.0.1
 */
- (void) addTags:(NSArray*)tags callback:(ZDKUserTagsCallback)callback;

/**
 *  Delete tags from the current user.
 *
 *  @param tags     The tags to delete.
 *  @param callback Callback will return an array of the tags set to the current user or an error. Can be nil.
 *
 *  @since 1.4.0.1
 */
- (void) deleteTags:(NSArray*)tags callback:(ZDKUserTagsCallback)callback;

/**
 *  Set one or more user field values on the current user. To see the fields available for setting use the get User method and inspect the user fields dictionary.
 *  Values can be cleared by setting them to @p [NSNull null] @p.
 *
 *  @param userFields The user field to set.  It expects a dictionary(not a ZDKUserField). The key of this dictionary being the name of the user field and the corresponding value being the user field value to be set for the current user.
 *  @param callback  Callback will return a dictionary of userfields values on the current user.
 *
 *  @since 1.4.0.1
 */
- (void) setUserFields:(NSDictionary*)userFields callback:(ZDKSetUserFieldsCallback)callback;

/**
 *  Gets all user fields available for an account instance.
 *
 *  @param callback The callback will return an array of of ZDKUserField objects or an error. Can be nil.
 *
 *  @since 1.4.0.1
 */
- (void) getUserFields:(ZDKUserFieldsCallback)callback;
@end
