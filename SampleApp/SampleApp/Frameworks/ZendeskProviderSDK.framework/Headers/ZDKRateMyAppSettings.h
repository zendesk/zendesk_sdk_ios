/*
 *
 *  ZDKRateMyAppSettings.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 16/10/2014.  
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
#import "ZDKCoding.h"

@interface ZDKRateMyAppSettings : ZDKCoding


/**
 * enabled determines if Rate My App component should be shown
 */
@property (nonatomic, assign, readonly) BOOL enabled;


/**
 * numberOfVisits is the number of visits/app launches the app will need to be completed before showing the dialog
 */
@property (nonatomic, strong, readonly) NSNumber *visits;


/**
 * duration is the time that is required to expire before showing the dialog
 */
@property (nonatomic, strong, readonly) NSNumber *duration;


/**
 * delay is the length of delay that should pass before the dialog is shown
 */
@property (nonatomic, strong, readonly) NSNumber *delay;


/**
 * tags is a list of tags that should be included as part of the ticket creation
 */
@property (nonatomic, copy, readonly) NSArray *tags;


/**
 * appStoreUrl, is the url provided by the server to be invoked when "Yes, rate my app" is selected
 */
@property (nonatomic, copy, readonly) NSString *appStoreUrl;


/**
 * initWithDictionary, passing the NSDictionary of Rate My App settings received from the server
 */
- (id) initWithDictionary:(NSDictionary *)dictionary ;

@end
