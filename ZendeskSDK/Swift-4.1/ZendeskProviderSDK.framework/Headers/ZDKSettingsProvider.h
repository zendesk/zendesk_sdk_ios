/*
 *
 *  ZDKSettingsProvider.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 10/11/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZDKProvider.h"

@class ZDKAppSettings, ZDKSettings;

/**
 *  Block used to pass response from API call
 *
 *  @param settings ZDKAppSettings returned based on applicationId set in ZDKConfig.init, can be nil on error
 *  @param error    NSError passed when an error has occurred, can be nil on success
 */
typedef void (^ZDKSettingsCallback)(ZDKSettings *settings, NSError *error);

@interface ZDKSettingsProvider : ZDKProvider

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
