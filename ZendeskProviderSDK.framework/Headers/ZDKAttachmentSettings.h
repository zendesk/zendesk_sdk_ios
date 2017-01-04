/*
 *
 *  ZDKAttachmentSettings.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 19/01/2015.
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
#import "ZDKCoding.h"

@interface ZDKAttachmentSettings : ZDKCoding


/**
 *  This setting corresponds to the "Customers can attach files" setting in the Zendesk admin interface.
 */
@property (nonatomic, assign, readonly) BOOL enabled;

/**
 *  This setting controls the maximum attachment size that can be uploaded to your Zendesk.
 */
@property (nonatomic, strong, readonly) NSNumber *maxAttachmentSize;


/**
 *  Initializes a new instance of ZDKAccountSettings with the contents of the dictionary provided.
 *
 *  @param dictionary A dictionary of the attachment settings.
 *
 *  @return An initialized ZDKAttachmentSettings object.
 */
- (instancetype) initWithDictionary:(NSDictionary *) dictionary;


@end
