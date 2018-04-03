/*
 *
 *  ZDKAnonymousIdentity.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 19/11/2014.  
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
#import "ZDKIdentity.h"
#import "ZDKCoding.h"

@interface ZDKAnonymousIdentity : ZDKCoding <ZDKIdentity>

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *email;


@end
