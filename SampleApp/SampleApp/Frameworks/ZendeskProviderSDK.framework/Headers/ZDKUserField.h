/*
 *
 *  ZDKUserField.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 17/08/2015.
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

@interface ZDKUserField : NSObject

/**
 *  User Field ID in zendesk instance.
 */
@property (nonatomic, strong) NSNumber *userFieldId;

/**
 *  Title of User Field.
 */
@property (nonatomic, strong) NSString *title;

/**
 *  The type of the user field e.g. "checkbox", "text" or "date".
 */
@property (nonatomic, strong) NSString *typeOfField;

/**
 *  Description of the user field's purpose.
 */
@property (nonatomic, strong) NSString *fieldDescription;

/**
 *  Options for the custom userfield. An array of ZDKCustomField objects(only for "dropdown" type userfields).
 */
@property (nonatomic, copy) NSArray *customFieldOptions;

/**
 * Initialise with dictionary generated from API json.
 *
 * @param dictionary the user details
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

/**
 *  Parses a json array of user fields into an array of ZDKUserField objects.
 *
 *  @see Developer docs on user fields for more information: https://developer.zendesk.com/rest_api/docs/core/user_fields
 *
 *  @param array The array of API json.
 *
 *  @return An array of ZDKUserField objects.
 */
+ (NSArray*) parseUserFields:(NSArray*)array;

@end
