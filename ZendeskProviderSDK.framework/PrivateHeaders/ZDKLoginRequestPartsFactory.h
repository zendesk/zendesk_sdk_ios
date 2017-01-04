/*
 *
 *  ZDKLoginRequestPartsFactory.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on  14/12/2015
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZendeskProviderSDK.h"


@class ZDKAccount;
/**
 *  class that aids in the creation of the parts of a login request
 */
NS_ASSUME_NONNULL_BEGIN
@interface ZDKLoginRequestPartsFactory : NSObject

/**
 *  returns the URL to use based on the accounts settings
 *  @param account            account to use to get url
 *  @param identity           identity type to get body from
 */
+ (NSURL *_Nullable)loginURLWithAccount:(ZDKAccount*)account identity:(id <ZDKIdentity>)identity;

/**
 *  returns the HTTP body to send
 *  @param identity identity type to get body from
 */
+ (NSDictionary *)loginBodyForIdentity:(id <ZDKIdentity>)identity;

/**
 *  return an error if the stored identity is not valid
 *  @param identity identity type to get body from
 */
+ (NSError *_Nullable)validateIdentityForSettingsAuthenticationType:(id <ZDKIdentity>)identity;

@end
NS_ASSUME_NONNULL_END
