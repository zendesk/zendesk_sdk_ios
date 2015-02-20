/*
 *
 *  ZDKSettingsProvider.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 10/11/2014.  
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
@class ZDKAppSettings, ZDKSettings;

/**
 *  Block used to pass response from API call
 *
 *  @param settings ZDKAppSettings returned based on applicationId set in ZDKConfig.init, can be nill on error
 *  @param error    NSError passed when an error has occured, can be nil on success
 */
typedef void (^ZDKSettingsCallback)(ZDKSettings *settings, NSError *error);

@interface ZDKSettingsProvider : NSObject

/**
 *  Get SDK Settings from Zendesk instance
 *
 *  @param callback block callback invoked on success and error states
 */
- (void) getSdkSettingsWithCallback:(ZDKSettingsCallback) callback;

/**
 *  Get SDK Settings from Zendesk instance using the specified locale.
 *
 *  @param locale   IETF language code. Config returned from server will contain this string if the local is supported, will
 *                  be the default locale otherwise
 *  @param callback block callback invoked on success and error states
 */
- (void) getSdkSettingsWithLocale:(NSString *)locale andCallback:(ZDKSettingsCallback) callback;

@end
