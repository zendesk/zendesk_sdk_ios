/* 
 *  ZDKCustomField.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 08/11/2014.
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

@interface ZDKCustomField : NSObject

@property (nonatomic, readonly) NSNumber *fieldId;
@property (nonatomic, readonly) NSString *value;

/**
 *  init the object
 *
 *  @param aFieldId id of the custom field
 *  @param aValue   value for custom field
 *
 *  @return instance of custom field
 */
- (instancetype) initWithFieldId:(NSNumber *) aFieldId andValue:(NSString *) aValue;

/**
 *  Dictionary Representation of ZDKCustomField
 *
 *  @return NSDictionary of custom field
 */
- (NSDictionary *) dictionaryValue;

@end
