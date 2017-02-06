/*
 *
 *  ZDKSdkStorage.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 25/11/2014.  
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

@class ZDKRequestStorage, ZDKIdentityStorage, ZDKSettingsStorage, ZDKTicketForm;

@interface ZDKSdkStorage : NSObject

@property (nonatomic, strong, readonly) ZDKRequestStorage *requestStorage;
@property (nonatomic, strong, readonly) ZDKIdentityStorage *identityStorage;


/**
 * Clears user data from storage.
 *
 * This will only clear data that is associated with a user. 
 * ZDKSettingsStorage are an example of something that won't be cleared but ZDKRequestStorage will
 * be cleared because that is from a user.
 *
 */
- (void) clearUserData;

/**
 *  Singleton return instance of object
 *
 *  @return instance of ZDKSdkStorage
 */
+ (instancetype) instance;

@end
