/*
 *
 *  ZDKSettings.h
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

@class ZDKAppSettings, ZDKAccountSettings;

@interface ZDKSettings : ZDKCoding

/**
 *  Gets the app settings.
 */
@property (nonatomic, readonly) ZDKAppSettings *appSettings;

/**
 *  Gets the Zendesk account settings.
 */
@property (nonatomic, readonly) ZDKAccountSettings *accountSettings;


/**
 *  Initializes a new instance of ZDKSettings with the contents of the dictionary provided.
 *
 *  @param dictionary A dictionary of the SDK settings.
 *
 *  @return An initialzed ZDKSettings object.
 */
- (id) initWithDictionary: (NSDictionary *) dictionary;


@end
