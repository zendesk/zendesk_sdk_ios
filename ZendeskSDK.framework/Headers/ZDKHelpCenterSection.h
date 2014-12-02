/*
 *
 *  ZDKHelpCenterSection.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 25/09/2014.  
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


@interface ZDKHelpCenterSection : NSObject

@property (strong, nonatomic) NSString *sid;
@property (strong, nonatomic) NSString *category_id;
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *sectionDescription;
@property (assign, nonatomic) NSInteger position;
@property (assign, nonatomic) BOOL outdated;


/**
 * Parses a single Help Center json section object.
 *
 * @return A new ZDKHelpCenterSection.
 */
+ (ZDKHelpCenterSection *) parseSection:(NSDictionary *)sectionJson;


/**
 * Parses a collection of Help Center json section objects
 *
 */
+ (NSArray *) parseSections:(NSDictionary *)json;


@end
