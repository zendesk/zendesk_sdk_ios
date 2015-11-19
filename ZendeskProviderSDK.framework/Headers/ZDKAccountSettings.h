/*
 *
 *  ZDKAccountSettings.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 19/01/2015.
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
#import "ZDKCoding.h"

@class ZDKAttachmentSettings;

/**
 * This class models the Account settings. These settings describe how your Zendesk instance is
 + configured so they are really higher level sdk settings.
 * 
 * @see ZDKAppSettings
 */
@interface ZDKAccountSettings : ZDKCoding

/**
 *  Gets the attachment settings for the Zendesk instance.
 */
@property (nonatomic, readonly) ZDKAttachmentSettings *attachmentSettings;


/**
 *  Initializes a new instance of ZDKAccountSettings with the contents of the dictionary provided.
 *
 *  @param dictionary A dictionary of the Zendesk instance account settings.
 *
 *  @return An initialzed ZDKAccountSettings object. 
 */
- (instancetype) initWithDictionary:(NSDictionary *) dictionary;

@end
