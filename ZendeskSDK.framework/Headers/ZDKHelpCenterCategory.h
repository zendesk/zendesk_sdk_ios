/*
 *
 *  ZDKHelpCenterCategory.h
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

@interface ZDKHelpCenterCategory : NSObject

/**
 *  Category id.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *sid;

/**
 *  Category Name.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *name;

/**
 *  Category Description.
 *
 *  @since 0.9.3.1
 */
@property (strong, nonatomic) NSString *categoryDescription;

/**
 *  Position in Category list.
 *
 *  @since 0.9.3.1
 */
@property (assign, nonatomic) NSInteger position;

/**
 *  Whether the category is outdated or not.
 *
 *  @since 1.4.0.1
 */
@property (assign, nonatomic) BOOL outdated;

/**
 *  Current Locale.
 *
 *  @since 1.4.0.1
 */
@property (strong, nonatomic) NSString *locale;

/**
 *  Source locale of this category
 *
 *  @since 1.4.0.1
 */
@property (strong, nonatomic) NSString *sourceLocale;

/**
 *  API url of the Category in the help center
 *
 *  @since 1.4.0.1
 */
@property (strong, nonatomic) NSString *url;

/**
 *  url of the Category in the help center
 *
 *  @since 1.4.0.1
 */
@property (strong, nonatomic) NSString *html_url;

/**
 *  Time at which the category was last updated at.
 *
 *  @since 1.4.0.1
 */
@property (strong, nonatomic) NSString *updatedAt;

/**
 *  Time at whieh the category was created at
 *
 *  @since 1.4.0.1
 */
@property (strong, nonatomic) NSString *createdAt;

/**
 * Parses a single Help Center json category object.
 *
 * @return A new ZDKHelpCenterCategory.
 */
+ (ZDKHelpCenterCategory *) parseCategory:(NSDictionary *)categoryJson;


/**
 * Parses a collection of Help Center json category objects
 *
 * @return An array of ZDKHelpCenterCatefory objects.
 */
+ (NSArray *) parseCategories:(NSDictionary *)json;


@end
